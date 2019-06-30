import itertools
from pprint import pprint


terminais = ["(", ")", "id", "+", "*"]
producoes = ["E", "T", "E'", "T'", "F"]

hash_producoes = {
    "E": [["T", "E'"]],
    "T": [["F", "T'"]],
    "E'": [["+", "T", "E'"], ["eps"]],
    "T'": [["*", "F", "T'"], ["eps"]],
    "F": [["(", "E", ")"], ["id"]]
}

primeiros = {
}


def add_to_prims(key, arr):
    response = False
    if key not in primeiros:
        primeiros[key] = []
    for el in arr:
        if el not in primeiros[key]:
            primeiros[key].append(el)
            response = True
    return response


# step1 - inicializacao
simbolos = list(hash_producoes.values())
x = list(itertools.chain(*simbolos))
simbolos = list(set(itertools.chain(*x)))

# step1 - inicializacao
for s in simbolos:
    if s in terminais:
        add_to_prims(s, [s])
    elif s in hash_producoes and ["eps"] in hash_producoes[s]:
        add_to_prims(s, ["eps"])
    else:
        add_to_prims(s, [])

pprint(primeiros)


# step2 - processo rotativo convergente
keepgoing = True
while keepgoing:
    keepgoing = False
    for x, val in hash_producoes.items():
        for ys in val:

            i = 0
            while i < len(ys):
                if add_to_prims(x, [y for y in primeiros[ys[i]] if y != "eps"]):
                    keepgoing = True

                if "eps" in primeiros[ys[i]]:
                    i += 1
                else:
                    break

pprint(primeiros)
