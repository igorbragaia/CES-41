import itertools
from pprint import pprint


terminais = ["(", ")", "id", "+", "*"]
producoes = ["E", "T", "E'", "T'", "F"]

prods = {
    "E": [["T", "E'"]],
    "T": [["F", "T'"]],
    "E'": [["+", "T", "E'"], ["eps"]],
    "T'": [["*", "F", "T'"], ["eps"]],
    "F": [["(", "E", ")"], ["id"]]
}

prims = {
}

# step1 - inicializacao
simbolos = list(prods.values())
x = list(itertools.chain(*simbolos))
simbolos = list(set(itertools.chain(*x)))

for s in simbolos:
    if s in terminais:
        prims[s] = set([s])
    elif s in prods and ["eps"] in prods[s]:
        prims[s] = set(["eps"])
    else:
        prims[s] = set()

pprint(prims)

# step2 - processo rotativo convergente
k = 0
keepgoing = True
while keepgoing and k < 5:
    k += 1
    keepgoing = False
    for x, val in prods.items():
        for ylist in val:
            i = 0

            new_set = set([el for el in prims[ylist[0]] if el != "eps"])
            if len(new_set) > 0:
                prims[x] = prims[x].union(new_set)
                keepgoing = True

            flag = True
            while i < len(ylist) - 1 and flag:
                flag &= "eps" in prims[ylist[i]]
                if flag:
                    new_set = set([el for el in prims[ylist[i+1]] if el != "eps"])
                    if len(new_set) > 0:
                        prims[x] = prims[x].union(new_set)
                        keepgoing = True
                i += 1

            if i == len(ylist):
                prims[x].add("eps")


        #
        # print(x + "->" + "".join(ylist))
        #
        # for i in range(len(ylist)):
        #     flag = i == 0
        #     if i != 0:
        #         for el in ylist[:i]:
        #             if "eps" in prims[el]:
        #                 flag = True
        #     if flag:
        #         new_set = set([el for el in prims[ylist[i]] if el != "eps"])
        #         prims[x] = prims[x].union(new_set)
        #
        # flag = False
        # for el in ylist:
        #     if "eps" in prims[el]:
        #         flag = True
        # if flag:
        #     prims[x].add("eps")

pprint(prims)