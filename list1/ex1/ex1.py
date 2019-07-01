import ex1_constants as CONST


class Atrib():
    def __init__(self):
        self.cadeia = None
        self.valor = None
        self.atr = None
        self.carac = None


class Atom():
    def __init__(self):
        self.tipo = None
        self.atrib = Atrib()

    def __str__(self):
        return str(self.tipo)


class Compiler():
    def __init__(self):
        self.f = None
        self.atom = None
        self.state = None

    def compile(self, filename):
        self.f = open(filename)
        self.atom = Atom()

        self.__novo_carac()
        while self.atom.atrib.carac:
            self.state = 1
            self.atom.atrib.cadeia = ""
            self.__novo_atomo()
            print(self.atom)

        self.f.close()

    def __novo_atomo(self):
        novo_atomo = False
        while self.atom.atrib.carac:
                novo_atomo = True
                self.analise_lexica(self.atom.atrib.carac)
                if self.state == 3:
                    break

        return novo_atomo

    def __novo_carac(self):
        self.atom.atrib.carac = self.f.read(1)

    def __classifica_cadeia(self):
        if self.atom.atrib.cadeia in ["BEGIN", "BOOLEAN", "DO", "ELSE", "END", "FALSE", "IF", "INTEGER", "PROGRAM",
                                      "READ", "THEN", "TRUE", "VAR", "WHILE", "WRITE"]:
            self.atom.tipo = getattr(CONST, self.atom.atrib.cadeia)
        elif self.atom.atrib.cadeia in ["AND", "OR", "NOT"]:
            self.atom.tipo = getattr(CONST, self.atom.atrib.cadeia)
        else:
            self.atom.tipo = CONST.CADEIA

    def __forma_atomo(self):
        pass

    def __forma_cadeia(self):
        self.atom.atrib.cadeia += self.atom.atrib.carac

    def __forma_numero(self):
        self.atom.atrib.valor = int(self.atom.atrib.cadeia)

    def __classifica(self):
        if self.atom.atrib.carac == '+':
            self.atom.tipo = CONST.MAIS
        if self.atom.atrib.carac == '-':
            self.atom.tipo = CONST.MENOS
        if self.atom.atrib.carac == '/':
            self.atom.tipo = CONST.DIV
        if self.atom.atrib.carac == '~':
            self.atom.tipo = CONST.NOT
        if self.atom.atrib.carac == '=':
            self.atom.tipo = CONST.IGUAL
        if self.atom.atrib.carac == ';':
            self.atom.tipo = CONST.PVIRG
        if self.atom.atrib.carac == '.':
            self.atom.tipo = CONST.PONTO
        if self.atom.atrib.carac == ',':
            self.atom.tipo = CONST.VIRG
        if self.atom.atrib.carac == '(':
            self.atom.tipo = CONST.ABPAR
        if self.atom.atrib.carac == ')':
            self.atom.tipo = CONST.FPAR

    def analise_lexica(self, carac):
        if self.state == 1:
            if carac == '\\':
                self.__novo_carac()
                self.state = 5
            elif carac == '+' or carac == '-' or carac == '/' or carac == '~' or carac == '=' or carac == ';' or \
                    carac == '.' or carac == ',' or carac == '(' or carac == ')':
                self.__classifica()
                self.__novo_carac()
                self.state = 3
            elif carac == '<':
                self.__novo_carac()
                self.state = 6
            elif carac == '>':
                self.__novo_carac()
                self.state = 7
            elif carac == ':':
                self.__novo_carac()
                self.state = 8
            elif carac == '\0':
                self.atom.tipo = CONST.FINAL
                self.state = 3
            elif carac.isalpha():
                self.__forma_cadeia()
                self.__novo_carac()
                self.state = 2
            elif carac.isdigit():
                self.__forma_cadeia()
                self.__novo_carac()
                self.state = 4
            # elif (carac.isspace() or carac.iscntrl()) and carac != 0:
            elif carac == '\n' or carac == ' ':
                self.__novo_carac()
                self.state = 1
            else:
                self.atom.tipo = CONST.INVAL
                self.atom.atrib.carac = carac
                self.__novo_carac()
                self.state = 3
        elif self.state == 2:
            if carac.isalnum():
                self.__forma_cadeia()
                self.__novo_carac()
                self.state = 2
            else:
                self.__classifica_cadeia()
                self.state = 3
        elif self.state == 4:
            if carac.isdigit():
                self.__forma_cadeia()
                self.__novo_carac()
                self.state = 4
            else:
                self.atom = self.__forma_numero()
                self.state = 3
        elif self.state == 6:
            if carac == '=':
                self.atom.tipo = CONST.OPREL
                self.atom.atrib.atr = CONST.MENIG
                self.__novo_carac()
            elif carac == '>':
                self.atom.tipo = CONST.OPREL
                self.atom.atrib.atr = CONST.DIFER
                self.__novo_carac()
            else:
                self.atom.tipo = CONST.OPREL
                self.atom.atrib.atr = CONST.MENOR

            self.state = 3


compilador = Compiler()
compilador.compile("ex1_input.in")
