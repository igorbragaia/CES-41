import itertools
from pprint import pprint

# INICIALIZANDO VARIAVEIS


terminais = ["(", ")", "id", "+", "*"]
nao_terminais = ["E", "T", "E'", "T'", "F"]
producoes = {
    "E": [["T", "E'"]],
    "T": [["F", "T'"]],
    "E'": [["+", "T", "E'"], ["eps"]],
    "T'": [["*", "F", "T'"], ["eps"]],
    "F": [["(", "E", ")"], ["id"]]
}
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
simbolos = list(producoes.values())
x = list(itertools.chain(*simbolos))
simbolos = list(set(itertools.chain(*x)))

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
                add_to_seguintes(ys[i], [el for el in primeiros[ys[i+1]] if el != "eps"])

# processo rotativo não convergente

keepgoing = True
while keepgoing:
    keepgoing = False
    for x, val in producoes.items():
        for ys in val:
            for i in range(len(ys)):
                if ys[i] in nao_terminais and (i == len(ys) - 1 or "eps" in primeiros[ys[i+1]]):
                    if add_to_seguintes(ys[i], seguintes[x]):
                        keepgoing = True

pprint(seguintes)