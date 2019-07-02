import itertools
from pprint import pprint

# INICIALIZANDO VARIAVEIS

# exemplo lab

terminais = ["ID", "CTE", "int", "real", "+", "*", "=", ";", ",", "(", ")", "{", "}"]
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
    "Termo": [["(", "Expressao", ")"], ["ID", "CTE"]]
}

# # exemplo slide
# terminais = ["(", ")", "id", "+", "*"]
# nao_terminais = ["E", "T", "E'", "T'", "F"]
# producoes = {
#     "E": [["T", "E'"]],
#     "T": [["F", "T'"]],
#     "E'": [["+", "T", "E'"], ["eps"]],
#     "T'": [["*", "F", "T'"], ["eps"]],
#     "F": [["(", "E", ")"], ["id"]]
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
print("primeiros:\n")
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

print("\nseguintes:\n")
pprint(seguintes)
