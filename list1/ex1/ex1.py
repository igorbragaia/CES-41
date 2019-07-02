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
        self.state = 1
        self.atom.atrib.cadeia = ""
        self.__novo_atomo()
        self.ExecProg()

        self.f.close()

    def __novo_atomo(self):
        novo_atomo = False
        while self.atom.atrib.carac:
                novo_atomo = True
                self.analise_lexica(self.atom.atrib.carac)
                if self.state == 3:
                    break

        print(self.atom)
        self.state = 1
        self.atom.atrib.cadeia = ""
        return novo_atomo

    def __novo_carac(self):
        self.atom.atrib.carac = self.f.read(1)

    def __categoriza_cadeia(self):
        cadeia = self.atom.atrib.cadeia
        if cadeia in ["BEGIN", "BOOLEAN", "DO", "ELSE", "END", "FALSE", "IF", "INTEGER", "PROGRAM", "READ", "THEN", "TRUE", "VAR", "WHILE", "WRITE"]:
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

    def esperado(self, atom_tipo):
        print("ESPERADO: ", atom_tipo)

    def nao_esperado(self, atom_tipo):
        print("NAO ESPERADO ", atom_tipo)

    def ExecProg(self):
        estado = 1
        while estado != 8:
            if estado == 1:
                if self.atom.tipo == CONST.PROGRAM:
                    self.__novo_atomo()
                    estado = 2
                else:
                    self.esperado("PROGRAM")
                    estado = 9
            elif estado == 2:
                if self.atom.tipo == CONST.ID:
                    self.__novo_atomo()
                    estado = 3
                else:
                    self.esperado("IDENTIFICADOR")
                    estado = 9
            elif estado == 3:
                if self.atom.tipo == CONST.PVIRG:
                    self.__novo_atomo()
                    estado = 4
                else:
                    self.esperado("PONTO E VIRGULA")
            elif estado == 4:
                self.ExecDecls()
                estado = 5
            elif estado == 5:
                self.ExecCmdComp()
                estado = 6
            elif estado == 6:
                if self.atom.tipo == CONST.PONTO:
                    self.__novo_atomo()
                    estado = 7
                else:
                    self.esperado("PONTO")
                    estado = 10
            elif estado == 7:
                if self.atom.tipo == CONST.FINAL:
                    estado = 8
                else:
                    self.esperado("END OF FILE")
                    # estado = 10
                    estado = 8
            elif estado == 9:
                if self.atom.tipo == CONST.PVIRG:
                    self.__novo_atomo()
                    estado = 4
                elif self.atom.tipo == CONST.FINAL:
                    estado = 8
                else:
                    self.__novo_atomo()
                    estado = 9
            elif estado == 10:
                if self.atom.tipo == CONST.FINAL:
                    estado = 8
                else:
                    self.__novo_atomo()
                    estado = 10

    def ExecDecls(self):
        estado = 11
        while estado != 13:
            if estado == 11:
                if self.atom.tipo == CONST.VAR:
                    self.__novo_atomo()
                    estado = 12
                else:
                    estado = 13
            elif estado == 12:
                self.ExecListDecl()
                estado = 13

    def ExecListDecl(self):
        estado = 14
        while estado != 16:
            if estado == 14:
                self.ExecDeclTipo()
                estado = 15
            elif estado == 15:
                if self.atom.tipo == CONST.ID:
                    estado = 14
                else:
                    estado = 16

    def ExecDeclTipo(self):
        estado = 17
        while estado != 21:
            if estado == 17:
                self.ExecListId()
                estado = 18
            elif estado == 18:
                if self.atom.tipo == CONST.DPONTS:
                    self.__novo_atomo()
                    estado = 19
                else:
                    self.esperado("DOIS PONTOS")
                    estado = 22
            elif estado == 19:
                self.ExecTip()
                estado = 20
            elif estado == 20:
                if self.atom.tipo == CONST.PVIRG:
                    self.__novo_atomo()
                    estado = 21
                else:
                    self.esperado("PONTO E VIRGULA")
            elif estado == 22:
                if self.atom.tipo == CONST.VIRG:
                    self.__novo_atomo()
                    estado = 21
                elif self.atom.tipo == CONST.FINAL:
                    estado = 21
                else:
                    self.__novo_atomo()
                    estado = 22

    def ExecListId(self):
        estado = 23
        while estado != 25:
            if estado == 23:
                if self.atom.tipo == CONST.ID:
                    self.__novo_atomo()
                    estado = 24
                else:
                    self.esperado("ID")
                    estado = 26
            elif estado == 24:
                if self.atom.tipo == CONST.VIRG:
                    self.__novo_atomo()
                    estado = 23
                else:
                    estado = 25
            elif estado == 26:
                if self.atom.tipo == CONST.VIRG:
                    self.__novo_atomo()
                    estado = 23
                elif self.atom.tipo == CONST.ID:
                    estado = 23
                elif self.atom.tipo in [CONST.DPONTS, CONST.FPAR, CONST.FINAL]:
                    estado = 25
                else:
                    self.__novo_atomo()

    def ExecTip(self):
        estado = 27
        while estado != 28:
            if estado == 27:
                if self.atom.tipo in [CONST.INTEGER, CONST.BOOLEAN]:
                    self.__novo_atomo()
                    estado = 28
                else:
                    self.esperado("INTEGER ou BOOLEAN")
                    estado = 29
            elif estado == 29:
                if self.atom.tipo in [CONST.PVIRG, CONST.FINAL]:
                    estado = 28
                else:
                    self.__novo_atomo()

    def ExecCmdComp(self):
        estado = 30
        while estado != 33:
            if estado == 30:
                if self.atom.tipo == CONST.BEGIN:
                    self.__novo_atomo()
                    estado = 31
                else:
                    self.esperado("BEGIN")
                    estado = 34
            elif estado == 31:
                self.ExecListCmd()
                estado = 32
            elif estado == 32:
                if self.atom.tipo == CONST.END:
                    self.__novo_atomo()
                    estado = 33
                else:
                    self.esperado("END")
                    estado = 33
            elif estado == 34:
                if self.atom.tipo == CONST.FINAL:
                    estado = 33
                elif self.atom.tipo == CONST.END:
                    self.__novo_atomo()
                    estado = 33
                elif self.atom.tipo == CONST.PVIRG:
                    self.__novo_atomo()
                    estado = 31
                else:
                    self.__novo_atomo()

    def ExecListCmd(self):
        estado = 35
        while estado != 37:
            if estado == 35:
                self.ExecCmd()
                estado = 36
            elif estado == 36:
                if self.atom.tipo == CONST.PVIRG:
                    self.__novo_atomo()
                    estado = 35
                else:
                    estado = 37

    def ExecCmd(self):
        estado = 38
        while estado != 39:
            if estado == 38:
                if self.atom.tipo == CONST.BEGIN:
                    self.ExecCmdComp()
                    estado = 39
                elif self.atom.tipo == CONST.WHILE:
                    self.__novo_atomo()
                    self.ExecCmdWhile()
                    estado = 39
                elif self.atom.tipo == CONST.IF:
                    self.__novo_atomo()
                    self.ExecCmdIf()
                    estado = 39
                elif self.atom.tipo == CONST.READ:
                    self.__novo_atomo()
                    self.ExecCmdRead()
                    estado = 39
                elif self.atom.tipo == CONST.WRITE:
                    self.__novo_atomo()
                    self.ExecCmdWrite()
                    estado = 39
                else:
                    self.ExecCmdAtrib()
                    estado = 39

    def ExecCmdIf(self):
        estado = 40
        while estado != 45:
            if estado == 40:
                self.ExecExpr()
                estado = 41
            elif estado == 41:
                if self.atom.tipo == CONST.THEN:
                    self.__novo_atomo()
                    estado = 42
                else:
                    self.esperado("THEN")
                    estado = 42
            elif estado == 42:
                self.ExecCmd()
                estado = 43
            elif estado == 43:
                if self.atom.tipo == CONST.ELSE:
                    self.__novo_atomo()
                    estado = 44
                else:
                    estado = 45
            elif estado == 44:
                self.ExecCmd()
                estado = 45

    def ExecCmdWhile(self):
        estado = 46
        while estado != 49:
            if estado == 46:
                self.ExecExpr()
                estado = 47
            elif estado == 47:
                if self.atom.tipo == CONST.DO:
                    self.__novo_atomo()
                    estado = 48
                else:
                    self.esperado("DO")
                    estado = 48
            elif estado == 48:
                self.ExecCmd()
                estado = 49

    def ExecCmdRead(self):
        estado = 50
        while estado != 53:
            if estado == 50:
                if self.atom.tipo == CONST.ABPAR:
                    self.__novo_atomo()
                    estado = 51
                else:
                    self.esperado("ABPAR")
                    estado = 51
            elif estado == 51:
                self.ExecListId()
                estado = 52
            elif estado == 52:
                if self.atom.tipo == CONST.FPAR:
                    self.__novo_atomo()
                    estado = 53
                else:
                    self.esperado("FPAR")
                    estado = 53

    def ExecCmdWrite(self):
        estado = 54
        while estado !=  57:
            if estado == 54:
                if self.atom.tipo == CONST.ABPAR:
                    self.__novo_atomo()
                    estado = 55
                else:
                    self.esperado("ABPAR")
                    estado = 55
            elif estado == 55:
                self.ExecListW()
                estado = 56
            elif estado == 56:
                if self.atom.tipo == CONST.FPAR:
                    self.__novo_atomo()
                    estado = 57
                else:
                    self.esperado("FPAR")
                    estado = 57

    def ExecListW(self):
        estado = 58
        while estado != 60:
            if estado == 58:
                self.ExecElemW()
                estado = 59
            elif estado == 59:
                if self.atom.tipo == CONST.VIRG:
                    self.__novo_atomo()
                    estado = 58
                else:
                    estado = 60

    def ExecElemW(self):
        estado = 61
        while estado != 62:
            if estado == 61:
                if self.atom.tipo == CONST.CADEIA:
                    self.__novo_atomo()
                    estado = 62
                else:
                    self.ExecExpr()
                    estado = 62

    def ExecCmdAtrib(self):
        estado = 63
        while estado != 66:
            if estado == 63:
                if self.atom.tipo == CONST.ID:
                    self.__novo_atomo()
                    estado = 64
                else:
                    self.esperado("ID")
                    estado = 67
            elif estado == 64:
                if self.atom.tipo == CONST.ATRIB:
                    self.__novo_atomo()
                    estado = 65
                else:
                    self.esperado("ATRIB")
                    estado = 67
            elif estado == 65:
                self.ExecExpr()
                estado = 66
            elif estado == 67:
                if self.atom.tipo == CONST.ATRIB:
                    self.__novo_atomo()
                    estado = 65
                elif self.atom.tipo in [CONST.PVIRG, CONST.END, CONST.FINAL]:
                    estado = 66
                else:
                    self.__novo_atomo()

    def ExecExpr(self):
        estado = 68
        while estado != 71:
            if estado == 68:
                self.ExecExprSimpl()
                estado = 69
            elif estado == 69:
                if self.atom.tipo == CONST.OPREL:
                    self.__novo_atomo()
                    estado = 70
                else:
                    estado = 71
            elif estado == 70:
                self.ExecExprSimpl()
                estado = 71

    def ExecExprSimpl(self):
        estado = 72
        while estado != 74:
            if estado == 72:
                self.ExecTerm()
                estado = 73
            elif estado == 73:
                if self.atom.tipo == CONST.OPAD:
                    self.__novo_atomo()
                    estado = 72
                else:
                    estado = 74

    def ExecTerm(self):
        estado = 75
        while estado != 77:
            if estado == 75:
                self.ExecFat()
                estado = 76
            elif estado == 76:
                if self.atom.tipo == CONST.OPMULT:
                    self.__novo_atomo()
                    estado = 75
                else:
                    estado = 77

    def ExecFat(self):
        estado = 78
        while estado != 81:
            if estado == 78:
                if self.atom.tipo == CONST.ABPAR:
                    self.__novo_atomo()
                    estado = 79
                elif self.atom.tipo == CONST.OPNEG:
                    self.__novo_atomo()
                    self.ExecFat()
                    estado = 81
                elif self.atom.tipo in [CONST.ID, CONST.CTE, CONST.TRUE, CONST.FALSE]:
                    self.__novo_atomo()
                    estado = 81
                else:
                    self.nao_esperado(self.atom.tipo)
                    estado = 82
            elif estado == 79:
                self.ExecExpr()
                estado = 80
            elif estado == 80:
                if self.atom.tipo == CONST.FPAR:
                    self.__novo_atomo()
                    estado = 81
                else:
                    self.esperado("FPAR")
            elif estado == 82:
                if self.atom.tipo in [CONST.PVIRG, CONST.END, CONST.DO, CONST.THEN, CONST.ELSE, CONST.VIRG, CONST.FINAL]:
                    estado = 81
                else:
                    self.__novo_atomo()


compilador = Compiler()
compilador.compile("ex1_input.in")
