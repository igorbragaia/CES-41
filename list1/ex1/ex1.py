import ex1_constants as CONST

separadores = ["BEGIN", "BOOLEAN", "DO", "ELSE", "END", "FALSE", "IF", "INTEGER", "PROGRAM", "READ", "THEN", "TRUE", "VAR", "WHILE", "WRITE" ]
operadores = ["ID", "CTE", "CADEIA", "OPAD", "OPMULT", "OPNEG", "OPREL" ]
palavras_reservadas = ["PVIRG", "PONTO", "DPONTS", "VIRG", "ABPAR", "FPAR", "ATRIB"]
aux = ["INVAL", "FINAL"]

str_to_const_separadores = {string: getattr(CONST, string) for string in separadores}
str_to_const_operadores = {string: getattr(CONST, string) for string in operadores}
str_to_const_palavras_reservadas = {string: getattr(CONST, string) for string in palavras_reservadas}
str_to_const_aux = {string: getattr(CONST, string) for string in aux}

separadores_id = str_to_const_separadores.values()
operadores_id = str_to_const_operadores.values()
palavras_reservadas_id = str_to_const_palavras_reservadas.values()
aux_id = str_to_const_aux.values()


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
        if self.tipo == CONST.CTE:
            return CONST.tipos[self.tipo] + ", " + str(self.tipo) + ", " + str(self.atrib.valor)
        if self.tipo in separadores_id or self.tipo in palavras_reservadas_id:
            return CONST.tipos[self.tipo] + ", " + str(self.tipo)
        if self.tipo in operadores_id:
            return CONST.tipos[self.tipo] + ", " + str(self.tipo) + ", " + str(self.atrib.atr)
        if self.tipo == getattr(CONST, "INVAL"):
            return "INVAL"
        if self.tipo == getattr(CONST, "FINAL"):
            return "FINAL"
        return "ERRO"


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

    def __classifica_cadeia(self, tipo=None):
        if tipo is not None:
            self.atom.tipo = tipo
            return
        if self.atom.atrib.cadeia in ["BEGIN", "BOOLEAN", "DO", "ELSE", "END", "FALSE", "IF", "INTEGER", "PROGRAM",
                                      "READ", "THEN", "TRUE", "VAR", "WHILE", "WRITE"]:
            self.atom.tipo = getattr(CONST, self.atom.atrib.cadeia)
        elif self.atom.atrib.cadeia == "OR":
            self.atom.tipo = getattr(CONST, "OPAD")
            self.atom.atrib.atr = getattr(CONST, "AND")
        elif self.atom.atrib.cadeia == "AND":
            self.atom.tipo = getattr(CONST, "OPMUL")
            self.atom.atrib.atr = getattr(CONST, "AND")
        elif self.atom.atrib.cadeia == "NOT":
            self.atom.tipo = getattr(CONST, "OPNEG")
            self.atom.atrib.atr = getattr(CONST, "NOT")
        else:
            self.atom.tipo = CONST.ID
            self.atom.atrib.atr = self.atom.atrib.cadeia

    def __forma_atomo(self):
        pass

    def __forma_cadeia(self):
        self.atom.atrib.cadeia += self.atom.atrib.carac

    def __forma_numero(self):
        self.atom.atrib.valor = int(self.atom.atrib.cadeia)

    def __classifica(self):
        if self.atom.atrib.carac == '+':
            self.atom.tipo = CONST.OPAD
            self.atom.atrib.atr = CONST.MAIS
        if self.atom.atrib.carac == '-':
            self.atom.tipo = CONST.OPAD
            self.atom.atrib.atr = CONST.MENOS
        if self.atom.atrib.carac == '/':
            self.atom.tipo = CONST.OPMULT
            self.atom.atrib.atr = CONST.DIV
        if self.atom.atrib.carac == '*':
            self.atom.tipo = CONST.OPMULT
            self.atom.atrib.atr = CONST.VEZES
        if self.atom.atrib.carac == '~':
            self.atom.tipo = CONST.OPNEG
            self.atom.atrib.atr = CONST.NEG
        if self.atom.atrib.carac == '=':
            self.atom.tipo = CONST.OPREL
            self.atom.atrib.atr = CONST.IGUAL
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
        if self.atom.atrib.cadeia == ':':
            self.atom.tipo = CONST.DPONTS
        if self.atom.atrib.cadeia == ':=':
            self.atom.tipo = CONST.ATRIB

    def analise_lexica(self, carac):
        if self.state == 1:
            if carac == '\\':
                self.__novo_carac()
                self.state = 5
            elif carac == '+' or carac == '-' or carac == '*' or carac == '/' or carac == '~' or carac == '=' or carac == ';' or \
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
                self.__forma_cadeia()
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
            elif carac == '\n' or carac == ' ' or carac == '\t' or carac == '\r':
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
                self.__forma_numero()
                self.__classifica_cadeia(tipo=CONST.CTE)
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
        elif self.state == 8:
            if carac == '=':
                self.__forma_cadeia()
                self.__classifica()
                self.__novo_carac()
            else:
                self.__classifica()
            self.state = 3

        else:
            print("ESTADO NAO EXISTE")


compilador = Compiler()
compilador.compile("ex1_input.in")
