import ex1_constants as CONST


class Simbolo():
    def __init__(self, cadeia, tipo_id, tipo_var, inic=False, ref=False):
        self.cadeia = cadeia
        self.tipo_id = tipo_id
        self.tipo_var = tipo_var
        self.inic = inic
        self.ref = ref


class TabelaDeSimbolos():
    def __init__(self):
        self.hash = {}
        self.list_simb = []
        self.log_semantic = []

    def __print(self, text):
        self.log_semantic.append(text)

    def procura_simb(self, cadeia):
        if cadeia in self.hash:
            return self.hash[cadeia]
        else:
            return None

    def insere_simb(self, cadeia, tipo_id, tipo_var=""):
        simbolo = Simbolo(cadeia, tipo_id, tipo_var)
        self.hash[cadeia] = simbolo
        self.list_simb.append(simbolo)

    def anula_list_simb(self):
        self.list_simb = []

    def adic_tipo_var(self, tipo_var):
        for simb in self.list_simb:
            simb.tipo_var = tipo_var

    def tipo_inadequado(self, cadeia):
        self.__print("Tipo inadequado: " + cadeia)

    def nao_declarado(self, cadeia):
        self.__print("Não declarado: " + cadeia)

    def dupla_declaracao(self, cadeia):
        self.__print("Dupla declaração: " + cadeia)

    def incompatibilidade(self, text):
        self.__print(text)

    def log_erros(self):
        for simb in self.hash.values():
            if simb.tipo_id == CONST.IDVAR and (not simb.ref or not simb.inic):
                self.__print("Simbolo nao ref ou inic: " + simb.cadeia)

    def print(self):
        for simb in self.hash.values():
            self.__print(simb.cadeia + ", " + simb.tipo_id + ", " + simb.tipo_var + ", inic=" + str(simb.inic) + ", ref=" + str(simb.ref) )