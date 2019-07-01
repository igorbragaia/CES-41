import _Const from ex1_constants
global CONST = _Const()

class Atrib():
    def __init__():
        self.cadeia = None
        self.valor = None
        self.atr = None
        self.carac = None
        
class Atom():
    def __init__():
        self.tipo = None
        self.atrib = Atrib()


class Compilador():   
    def compilar(self, filename):
        self.f = open(filename)
        self.atom = Atom()
        self.self.estado_lex_lex = 1

        self.estado_lex = 1
        program = ""
        while True:
            carac = self.__novo_carac()
            if c:          
                carac = self.analise_lexica(carac)
            else:
                break

        self.f.close()

    def __novo_carac(self):
        return self.f.read()

    def __classifica_cadeia(self):
        pass

    def __forma_atomo(self):
        pass

    def __forma_cadeia(self):
        pass

    def __forma_numero(self):
        pass
        
    def analise_lexica(self, carac):
        if self.estado_lex == 1:
            if carac == '\':
                carac = self.__novo_carac()
                self.estado_lex = 5
            elif carac == '+' or case == '-' or case == '/' or case == '~' or carac == '=' or case == ';' or case == '.' or case == '(' or carac == ')':
                self.atom = self.__classifica_cadeia()
                carac = self.__novo_carac()                
                self.estado_lex = 3
            elif carac == '<':
                carac = self.__novo_carac()
                self.estado_lex = 6
            elif carac == '>':
                carac = self.__novo_carac()
                self.estado_lex = 7
            elif carac == ':':
                carac = self.__novo_carac()
                self.estado_lex = 8
            elif carac == '\0':
                self.atom.tipo = CONST.FINAL
                self.estado_lex = 3
            if carac.isalpha():
                self.__forma_cadeia()
                carac = self.__novo_carac()
                self.estado_lex = 2
            elif carac.isdigit():
                self.__forma_cadeia()
                carac = self.__novo_carac()
                self.estado_lex = 4
            elif (carac.isspace() or carac.iscntrl()) and carac != 0:
                carac = self.__novo_carac()
                self.estado_lex = 1
            else:
                self.atom.tipo = CONST.INVAL
                self.atom.atrib.carac = carac
                carac = self.__novo_carac()
                self.estado_lex = 3
        elif self.estado_lex == 2:
            if carac.isalnum():
                self.__forma_cadeia()
                carac = self.__novo_carac()
                self.estado_lex = 2
            else:
                self.atom = self.__classifica_cadeia()
                self.estado_lex = 3
        elif self.estado_lex == 4:
            if carac.isdigit():
                self.__forma_cadeia()
                carac = self.__novo_carac()
                self.estado_lex_lex = 4
            else:
                self.atom = self.__forma_numero()
                self.estado_lex = 3
        elif self.estado_lex == 6:
            if carac == '=':
                self.atom.tipo = CONST.OPREL
                self.atom.atrib.atr = CONST.MENIG
                carac = self.__novo_carac()
            elif carac == '>':
                self.atom.tipo = CONST.OPREL
                self.atom.atrib.atr = CONST.DIFER
                carac = self.__novo_carac()
            else:
                self.atom.tipo = CONST.OPREL
                self.atom.atrib.atr = CONST.MENOR
            self.estado_lex = 3
        
        return carac

filename = "ex1_program.in"

compilador = Compilador()
compilador.compilar(filename)
