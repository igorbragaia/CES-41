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

    def __classifica_cadeia(self):
        cadeia = self.atom.atrib.cadeia
        if cadeia in ["BEGIN", "BOOLEAN", "DO", "ELSE", "END", "FALSE", "IF", "INTEGER", "PROGRAM",
                                      "READ", "THEN", "TRUE", "VAR", "WHILE", "WRITE"]:
            return 'reservada'
        if cadeia == 'AND':
            return 'AND'
        if cadeia == 'OR':
            return 'OR'
        if cadeia == 'NOT':
            return 'NOT'
        return 'id'

    def __forma_atomo(self):
        pass

    def __forma_cadeia(self):
        self.atom.atrib.cadeia += self.atom.atrib.carac

    def __forma_numero(self):
        self.atom.atrib.valor = int(self.atom.atrib.cadeia)

    def __classifica(self, atomo):
        if atomo == '+':
            self.atom.tipo = CONST.OPAD
            self.atom.atrib.atr = CONST.MAIS
        if atomo == '-':
            self.atom.tipo = CONST.OPAD
            self.atom.atrib.atr = CONST.MENOS
        if atomo == 'OR':
            self.atom.tipo = CONST.OPAD
            self.atom.atrib.atr = CONST.OR
        if atomo == '/':
            self.atom.tipo = CONST.OPMULT
            self.atom.atrib.atr = CONST.DIV
        if atomo == '*':
            self.atom.tipo = CONST.OPMULT
            self.atom.atrib.atr = CONST.VEZES
        if atomo == 'AND':
            self.atom.tipo = CONST.OPMULT
            self.atom.atrib.atr = CONST.AND
        if atomo == '~':
            self.atom.tipo = CONST.OPNEG
            self.atom.atrib.atr = CONST.NEG
        if atomo == 'NOT':
            self.atom.tipo = CONST.OPNEG
            self.atom.atrib.atr = CONST.NOT
        if atomo == '=':
            self.atom.tipo = CONST.OPREL
            self.atom.atrib.atr = CONST.IGUAL
        if atomo == '<':
            self.atom.tipo = CONST.OPREL
            self.atom.atrib.atr = CONST.MENOR
        if atomo == '<=':
            self.atom.tipo = CONST.OPREL
            self.atom.atrib.atr = CONST.MENIG
        if atomo == '>':
            self.atom.tipo = CONST.OPREL
            self.atom.atrib.atr = CONST.MAIOR
        if atomo == '>=':
            self.atom.tipo = CONST.OPREL
            self.atom.atrib.atr = CONST.MAIG
        if atomo == '<>':
            self.atom.tipo = CONST.OPREL
            self.atom.atrib.atr = CONST.DIFER
        if atomo == ';':
            self.atom.tipo = CONST.PVIRG
        if atomo == '.':
            self.atom.tipo = CONST.PONTO
        if atomo == ',':
            self.atom.tipo = CONST.VIRG
        if atomo == '(':
            self.atom.tipo = CONST.ABPAR
        if atomo == ')':
            self.atom.tipo = CONST.FPAR
        if atomo == ':':
            self.atom.tipo = CONST.DPONTS
        if atomo == ':=':
            self.atom.tipo = CONST.ATRIB
        if atomo == 'reservada':
            self.atom.tipo = getattr(CONST, self.atom.atrib.cadeia)
        if atomo == 'cte':
            self.atom.tipo = CONST.CTE
            self.atom.atrib.atr = int(self.atom.atrib.cadeia)
        if atomo == 'id':
            self.atom.tipo = CONST.ID
            self.atom.atrib.atr = self.atom.atrib.cadeia

    def analise_lexica(self, carac):
        if self.state == 1:
            if carac == '\\':
                self.__novo_carac()
                self.state = 5
            elif carac == '+' or carac == '-' or carac == '*' or carac == '/' or carac == '~' or carac == '=' or carac == ';' or \
                    carac == '.' or carac == ',' or carac == '(' or carac == ')':
                self.__classifica(carac)
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
                categoria = self.__classifica_cadeia()
                self.__classifica(categoria)
                self.state = 3
        elif self.state == 4:
            if carac.isdigit():
                self.__forma_cadeia()
                self.__novo_carac()
                self.state = 4
            else:
                self.__forma_numero()
                self.__classifica('cte')
                self.state = 3
        elif self.state == 6:
            if carac == '=':
                self.__classifica('<=')
                self.__novo_carac()
            elif carac == '>':
                self.__classifica('<>')
                self.__novo_carac()
            else:
                self.__classifica('<')
            self.state = 3
        elif self.state == 7:
            if carac == '=':
                self.__classifica('>=')
            else:
                self.__classifica('>')
            self.state = 3
        elif self.state == 8:
            if carac == '=':
                self.__forma_cadeia()
                self.__classifica(':=')
                self.__novo_carac()
            else:
                self.__classifica(':')
            self.state = 3
        else:
            print("ESTADO NAO EXISTE")


compilador = Compiler()
compilador.compile("ex1_input.in")
