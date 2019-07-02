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
            return CONST.tipos[self.tipo] + "; " + str(self.tipo) + ";"
        if self.tipo in operadores_id:
            return CONST.tipos[self.tipo] + "; " + str(self.tipo) + "; " + str(self.atrib.atr)
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

    def __categoriza_cadeia(self):
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

    def __forma_cadeia(self):
        self.atom.atrib.cadeia += self.atom.atrib.carac

    def __classifica(self, atomo):
        if atomo == '\0':
            self.atom.tipo = CONST.FINAL
        elif atomo == '+':
            self.atom.tipo = CONST.OPAD
            self.atom.atrib.atr = CONST.MAIS
        elif atomo == '-':
            self.atom.tipo = CONST.OPAD
            self.atom.atrib.atr = CONST.MENOS
        elif atomo == 'OR':
            self.atom.tipo = CONST.OPAD
            self.atom.atrib.atr = CONST.OR
        elif atomo == '/':
            self.atom.tipo = CONST.OPMULT
            self.atom.atrib.atr = CONST.DIV
        elif atomo == '*':
            self.atom.tipo = CONST.OPMULT
            self.atom.atrib.atr = CONST.VEZES
        elif atomo == 'AND':
            self.atom.tipo = CONST.OPMULT
            self.atom.atrib.atr = CONST.AND
        elif atomo == '~':
            self.atom.tipo = CONST.OPNEG
            self.atom.atrib.atr = CONST.NEG
        elif atomo == 'NOT':
            self.atom.tipo = CONST.OPNEG
            self.atom.atrib.atr = CONST.NOT
        elif atomo == '=':
            self.atom.tipo = CONST.OPREL
            self.atom.atrib.atr = CONST.IGUAL
        elif atomo == '<':
            self.atom.tipo = CONST.OPREL
            self.atom.atrib.atr = CONST.MENOR
        elif atomo == '<=':
            self.atom.tipo = CONST.OPREL
            self.atom.atrib.atr = CONST.MENIG
        elif atomo == '>':
            self.atom.tipo = CONST.OPREL
            self.atom.atrib.atr = CONST.MAIOR
        elif atomo == '>=':
            self.atom.tipo = CONST.OPREL
            self.atom.atrib.atr = CONST.MAIG
        elif atomo == '<>':
            self.atom.tipo = CONST.OPREL
            self.atom.atrib.atr = CONST.DIFER
        elif atomo == ';':
            self.atom.tipo = CONST.PVIRG
        elif atomo == '.':
            self.atom.tipo = CONST.PONTO
        elif atomo == ',':
            self.atom.tipo = CONST.VIRG
        elif atomo == '(':
            self.atom.tipo = CONST.ABPAR
        elif atomo == ')':
            self.atom.tipo = CONST.FPAR
        elif atomo == ':':
            self.atom.tipo = CONST.DPONTS
        elif atomo == ':=':
            self.atom.tipo = CONST.ATRIB
        elif atomo == 'reservada':
            self.atom.tipo = getattr(CONST, self.atom.atrib.cadeia)
        elif atomo == 'cte':
            self.atom.tipo = CONST.CTE
            self.atom.atrib.atr = int(self.atom.atrib.cadeia)
        elif atomo == 'id':
            self.atom.tipo = CONST.ID
            self.atom.atrib.atr = self.atom.atrib.cadeia
        elif atomo == 'cadeia':
            self.atom.tipo = CONST.CADEIA
            self.atom.atrib.atr = self.atom.atrib.cadeia
        else:
            self.atom.tipo = CONST.INVAL

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
                self.__classifica('\0')
                self.state = 3
            elif carac == '‘':
                self.__novo_carac()
                self.state = 5
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
                self.__classifica('')
                self.__novo_carac()
                self.state = 3
        elif self.state == 2:
            if carac.isalnum():
                self.__forma_cadeia()
                self.__novo_carac()
                self.state = 2
            else:
                categoria = self.__categoriza_cadeia()
                self.__classifica(categoria)
                self.state = 3
        elif self.state == 4:
            if carac.isdigit():
                self.__forma_cadeia()
                self.__novo_carac()
                self.state = 4
            else:
                self.__classifica('cte')
                self.state = 3
        elif self.state == 5:
            if carac == '’':
                self.__classifica('cadeia')
                self.__novo_carac()
                self.state = 3
            elif carac == '\0':
                self.__classifica('cadeia')
                self.state = 3
            else:
                self.__forma_cadeia()
                self.__novo_carac()
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
