table = {
    "E": {
        "id": ["T", "E'"],
        "+": None,
        "*": None,
        "(": ["T", "E'"],
        ")": None,
        "$": None,
    },
    "E'": {
        "id": None,
        "+": ["+", "T", "E'"],
        "*": None,
        "(": None,
        ")": [],
        "$": [],
    },
    "T": {
        "id": ["F", "T'"],
        "+": None,
        "*": None,
        "(": ["F", "T'"],
        ")": None,
        "$": None,
    },
    "T'": {
        "id": None,
        "+": [],
        "*": ["*", "F", "T'"],
        "(": None,
        ")": [],
        "$": [],
    },
    "F": {
        "id": ["id"],
        "+": None,
        "*": None,
        "(": ["(", "E", ")"],
        ")": None,
        "$": None,
    }
}

# exp = ["id", "+", "id", "*", "id", "$"]
exp = ["id", "*", "(", "(", "id", "+", "id", ")", "*", "(", "id", "*", "(", "id", "+", "id", ")", ")", ")", "$"]
stack = ["$", "E"]
i = 0


def bprint(stack, exp, acao, producao):
    print(" ".join(stack) + "; " + " ".join(exp) + "; " + acao + "; " + producao + ";")


print("Pilha; Entrada; Acao; Producao;")
while len(stack):
    top = stack[-1]
    if top == exp[i]:
        bprint(stack, exp[i:], "Desempilhar e avancar", "")
        stack.pop()
        i += 1
    else:
        if table[top][exp[i]]:
            producao = top + "->" + "".join(table[top][exp[i]])
        else:
            producao = top + "->epsilon"
        bprint(stack, exp[i:], "Expandir", producao)
        stack.pop()
        stack.extend(list(reversed(table[top][exp[i]])))

bprint(stack, exp[i:], "Encerrar com sucesso", "")