import itertools
from pprint import pprint

# INICIALIZANDO VARIAVEIS

# exemplo lab

terminais = ["ID", "CTE", "int", "real", "+", "*", "=", ";", ",", "(", ")", "{", "}", "eps"]
nao_terminais = ["Prog", "Decls", "CmdComp", "Declaracao", "LDaux", "Tipo", "ListId", "LIaux", "ListCmd",
                 "Comando", "LCaux", "CmdAtrib", "Expressao", "Termo", "Eaux"]
producoes = {
    "Prog": [["Decls", "CmdComp"]],
    "Decls": [["Declaracao", "LDaux"]],
    "LDaux": [["eps"], ["Decls"]],
    "Declaracao": [["Tipo", "ListId", ";"]],
    "Tipo": [["int"], ["real"]],
    "ListId": [["ID", "LIaux"]],
    "LIaux": [["eps"], [",", "ListId"]],
    "CmdComp": [["{", "ListCmd", "}"]],
    "ListCmd": [["Comando", "LCaux"]],
    "LCaux": [["eps"], ["ListCmd"]],
    "Comando": [["CmdComp"], ["CmdAtrib"]],
    "CmdAtrib": [["ID", "=", "Expressao", ";"]],
    "Expressao": [["Termo", "Eaux"]],
    "Eaux": [["eps"], ["+", "Expressao"]],
    "Termo": [["(", "Expressao", ")"], ["ID"], ["CTE"]]
}
#
# # exemplo slide
# terminais = ["(", ")", "id", "+", "*", "eps"]
# nao_terminais = ["E", "T", "E'", "T'", "F"]
# producoes = {
#     "E": [["T", "E'"]],
#     "T": [["F", "T'"]],
#     "E'": [["+", "T", "E'"], ["eps"]],
#     "T'": [["*", "F", "T'"], ["eps"]],
#     "F": [["(", "E", ")"], ["id"]]
# }

# terminais = ["i", "b", "e", "a", "eps"]
# nao_terminais = ["S", "S'"]
# producoes = {
#     "S": [["i", "b", "S", "S'"], ["a"]],
#     "S'": [["e", "S"], ["eps"]]
# }


# # questao 2 lista 2
# terminais = ["@", "+", "*", "(", ")", "a", ","]
# nao_terminais = ["E", "T", "F", "P", "L"]
# producoes = {
#     "E'": [["E"]],
#     "E": [["E", "+", "T"], ["T"]],
#     "T": [["T", "*", "F"], ["F"]],
#     "F": [["P", "@", "F"], ["P"]],
#     "P": [["(", "E", ")"], ["a"], ["a", "(", "L", ")"]],
#     "L": [["L", ",", "E"], ["E"]]
# }

# # questao 2 lista 2 - exemplo slide
# terminais = ["+", "*", "(", ")", "id"]
# nao_terminais = ["E", "T", "F"]
# producoes = {
#     "E'": [["E"]],
#     "E": [["E", "+", "T"], ["T"]],
#     "T": [["T", "*", "F"], ["F"]],
#     "F": [["(", "E", ")"], ["id"]],
# }

primeiros = {}
seguintes = {}


# PRIMEIROS


def add_to_primeiros(key, arr):
    response = False
    if key not in primeiros:
        primeiros[key] = []
    for el in arr:
        if el not in primeiros[key]:
            primeiros[key].append(el)
            response = True
    return response


def add_to_seguintes(key, arr):
    response = False
    if key not in seguintes:
        seguintes[key] = []
    for el in arr:
        if el not in seguintes[key]:
            seguintes[key].append(el)
            response = True
    return response


# step1 - inicializacao
# simbolos = list(producoes.values())
# x = list(itertools.chain(*simbolos))
# simbolos = list(set().union(set(itertools.chain(*x)), producoes.keys()))

# sanity check
# diff_set =  set(simbolos) - set().union(set(set().union(terminais, nao_terminais)))
# assert(len(diff_set) >= 0)

simbolos = list(set().union(terminais, nao_terminais, ["eps"]))

for s in simbolos:
    if s in terminais:
        add_to_primeiros(s, [s])
    elif s in producoes and ["eps"] in producoes[s]:
        add_to_primeiros(s, ["eps"])
    else:
        add_to_primeiros(s, [])

# step2 - processo rotativo convergente

keepgoing = True
while keepgoing:
    keepgoing = False
    for x, val in producoes.items():
        for ys in val:

            i = 0
            while i < len(ys):
                if add_to_primeiros(x, [y for y in primeiros[ys[i]] if y != "eps"]):
                    keepgoing = True

                if "eps" in primeiros[ys[i]]:
                    i += 1
                else:
                    break
print("Primeiros:\n")
pprint(primeiros)

# SEGUINTES

# inicializacao trivial
simbolo_inicial = list(producoes.items())[0][0]
seguintes[simbolo_inicial] = ["$"]

# inicializao nao trivial
for x, val in producoes.items():
    for ys in val:
        for i in range(len(ys)):
            if i < len(ys) - 1 and ys[i] in nao_terminais:
                add_to_seguintes(ys[i], [el for el in primeiros[ys[i + 1]] if el != "eps"])

# processo rotativo não convergente

keepgoing = True
while keepgoing:
    keepgoing = False
    for x, val in producoes.items():
        for ys in val:
            for i in range(len(ys)):
                if ys[i] in nao_terminais and (i == len(ys) - 1 or "eps" in primeiros[ys[i + 1]]):
                    if add_to_seguintes(ys[i], seguintes[x]):
                        keepgoing = True

print("\nSeguintes:\n")
pprint(seguintes)

tabela_de_prim_seg = {}
# criar tabela
for key, value in producoes.items():
    for item in value:
        tabela_de_prim_seg[key + "->" + "".join(item)] = {
            "primalfa": primeiros[item[0]],
            "primA": primeiros[key],
            "segA": seguintes[key]
        }

with open("tabeladeprimseg.csv", "w") as f:
    f.write("A->alfa#Prim(alfa)#Prim(A)#Seg(A)\n")
    for prod in tabela_de_prim_seg:
        f.write(prod + "#" + " ".join(tabela_de_prim_seg[prod]["primalfa"]) + "#" + " ".join(tabela_de_prim_seg[prod]["primA"]) + "#" + " ".join(tabela_de_prim_seg[prod]["segA"]) + "\n")


tabela_de_prods = {}
for key in tabela_de_prim_seg:
    A = key.split('->')[0]
    if A not in tabela_de_prods:
        tabela_de_prods[A] = {}
    for a in tabela_de_prim_seg[key]["primalfa"]:
        if a not in tabela_de_prods[A]:
            tabela_de_prods[A][a] = set()
        tabela_de_prods[A][a].add(key)
    if "eps" in tabela_de_prim_seg[key]["primalfa"]:
        for b in tabela_de_prim_seg[key]["segA"]:
            if b not in tabela_de_prods[A]:
                tabela_de_prods[A][b] = set()
            tabela_de_prods[A][b].add(key)
        if "$" in tabela_de_prim_seg[key]["segA"]:
            if "$" not in tabela_de_prods[key[0]]:
                tabela_de_prods[A]["$"] = set()
            tabela_de_prods[A]["$"].add(key)


with open("tabeladeproducoes.csv", "w") as f:
    keys = [x for x in terminais if x != "eps"] + ["$"]
    f.write("# " + "# ".join(keys) + "\n")
    for term in tabela_de_prods:
        row = term + "# "
        for key in keys:
            if key in tabela_de_prods[term]:
                row += "|".join(tabela_de_prods[term][key])
            row += "# "

        f.write(row + "\n")

