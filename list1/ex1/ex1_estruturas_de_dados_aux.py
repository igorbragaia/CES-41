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

    def print(self):
        print("cadeia, tipo_id, tipo_var, inic, ref\n")
        for simb in self.hash.values():
            print(simb.cadeia + ", " + simb.tipo_id + ", " + simb.tipo_var + ", " + str(simb.inic) + ", " + str(simb.ref) + ", " )