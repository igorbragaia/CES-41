estado = {
    0: {
        "acao": {
            "id": ["d", 5],
            "+": None,
            "*": None,
            "(": ["d", 4],
            ")": None,
            "$": None,
        },
        "goto": {
            "E": 1,
            "T": 2,
            "F": 3
        }
    },
    1: {
        "acao": {
            "id": None,
            "+": ["d", 6],
            "*": None,
            "(": None,
            ")": None,
            "$": ["act"],
        },
        "goto": {
            "E": None,
            "T": None,
            "F": None
        }
    },
    2: {
        "acao": {
            "id": None,
            "+": ["r", 2],
            "*": ["d", 7],
            "(": None,
            ")": ["r", 2],
            "$": ["r", 2],
        },
        "goto": {
            "E": None,
            "T": None,
            "F": None
        }
    },
    3: {
        "acao": {
            "id": None,
            "+": ["r", 4],
            "*": ["r", 4],
            "(": None,
            ")": ["r", 4],
            "$": ["r", 4],
        },
        "goto": {
            "E": None,
            "T": None,
            "F": None
        }
    },
    4: {
        "acao": {
            "id": ["d", 5],
            "+": None,
            "*": None,
            "(": ["d", 4],
            ")": None,
            "$": None,
        },
        "goto": {
            "E": 8,
            "T": 2,
            "F": 3
        }
    },
    5: {
        "acao": {
            "id": None,
            "+": ["r", 6],
            "*": ["r", 6],
            "(": None,
            ")": ["r", 6],
            "$": ["r", 6],
        },
        "goto": {
            "E": None,
            "T": None,
            "F": None
        }
    },
    6: {
        "acao": {
            "id": ["d", 5],
            "+": None,
            "*": None,
            "(": ["d", 4],
            ")": None,
            "$": None,
        },
        "goto": {
            "E": None,
            "T": 9,
            "F": 3
        }
    },
    7: {
        "acao": {
            "id": ["d", 5],
            "+": None,
            "*": None,
            "(": ["d", 4],
            ")": None,
            "$": None,
        },
        "goto": {
            "E": None,
            "T": None,
            "F": 10
        }
    },
    8: {
        "acao": {
            "id": None,
            "+": ["d", 6],
            "*": None,
            "(": None,
            ")": ["d", 11],
            "$": None,
        },
        "goto": {
            "E": None,
            "T": None,
            "F": None
        }
    },
    9: {
        "acao": {
            "id": None,
            "+": ["r", 1],
            "*": ["d", 7],
            "(": None,
            ")": ["r", 1],
            "$": ["r", 1],
        },
        "goto": {
            "E": None,
            "T": None,
            "F": None
        }
    },
    10: {
        "acao": {
            "id": None,
            "+": ["r", 3],
            "*": ["r", 3],
            "(": None,
            ")": ["r", 3],
            "$": ["r", 3],
        },
        "goto": {
            "E": None,
            "T": None,
            "F": None
        }
    },
    11: {
        "acao": {
            "id": None,
            "+": ["r", 5],
            "*": ["r", 5],
            "(": None,
            ")": ["r", 5],
            "$": ["r", 5],
        },
        "goto": {
            "E": None,
            "T": None,
            "F": None
        }
    },
}

producoes = {
    1: [["E"], ["E", "+", "T"]],
    2: [["E"], ["T"]],
    3: [["T"], ["T", "*", "F"]],
    4: [["T"], ["F"]],
    5: [["F"], ["(", "E", ")"]],
    6: [["F"], ["id"]]
}

sentenca = ["id", "*", "id", "+", "id", "$"]
# sentenca = ["id", "*", "(", "(", "id", "+", "id", ")", "*", "(", "(", "id", "+", "id", ")", "*", "id", ")", ")", "$"]
pilha = [[0, None]]
e_path = [0, "acao", "id"] # caminho do estado atual no mapa de estados

i = 0
while i < len(sentenca):
    ee = estado[e_path[0]][e_path[1]][e_path[2]]

    if ee and ee[0] == "d":
        log_pilha = "$ " + " ".join(["(" + str(x[0]) + ", '" + str(x[1]) + "')" for x in pilha]).replace("(0, 'None')", "0")
        log_entrada = " ".join(sentenca[i:])
        pilha.append([ee[1], sentenca[i]])
        i += 1
        e_path = [ee[1], "acao", sentenca[i]]

        log_acao = ee[0] + " " + str(ee[1])
        log_goto = ""

        print(log_pilha + "; " + log_entrada + "; " + log_acao + "; " + log_goto)

    elif ee and ee[0] == "r":
        log_pilha = "$ " + " ".join(["(" + str(x[0]) + ", '" + str(x[1]) + "')" for x in pilha]).replace("(0, 'None')", "0")
        log_entrada = " ".join(sentenca[i:])
        prod = ["".join(x) for x in producoes[ee[1]]]

        deslocamento = len(producoes[ee[1]][1])
        for _ in range(deslocamento):
            pilha.pop()
        e_path_temp = [pilha[-1][0], "goto", producoes[ee[1]][0][0]]
        novo_e = estado[e_path_temp[0]][e_path_temp[1]][e_path_temp[2]]
        pilha.append([novo_e, producoes[ee[1]][0][0]])
        e_path = [novo_e, "acao", sentenca[i]]

        log_acao = ee[0] + " " + str(ee[1]) + " (" + prod[0] + " -> " + prod[1] + ")"
        log_goto = "Goto (" + str(e_path_temp[0]) + ", " + e_path_temp[2] + ") = " + str(novo_e)
        print(log_pilha + "; " + log_entrada + "; " + log_acao + "; " + log_goto)

    elif ee and ee[0] == 'act':
        log_pilha = "$ " + " ".join(["(" + str(x[0]) + ", '" + str(x[1]) + "')" for x in pilha]).replace("(0, 'None')", "0")
        log_entrada = " ".join(sentenca[i:])
        log_acao = "aceitar"
        log_goto = ""
        print(log_pilha + "; " + log_entrada + "; " + log_acao + "; " + log_goto)

        i += 1

