from graphviz import Digraph
from queue import Queue
from pprint import pprint
import itertools
# esse codigo eh uma implementacao do algoritmo do slide 5c do prof Mokarzel


class AfndNode:
    def __init__(self, left, right):
        self.left = left
        self.right = right
        self.idx = None

    def __str__(self):
        return "".join(self.left) + "->" + "".join(self.right)


class AfdNode:
    def __init__(self, closure):
        self.closure = sorted(closure)
        self.idx = None

    def __str__(self):
        return ", ".join(self.closure)


class Graph:
    def __init__(self, terminais, naoterminais, seguintes, producoes):
        self.terminais = terminais
        self.naoterminais = naoterminais
        self.seguintes = seguintes
        self.graph = {}
        self.nodes = {}
        self.state = "afnd"
        self.simbolos = None
        self.producoes = producoes

    def add_node(self, node):
        if str(node) not in self.graph:
            self.graph[str(node)] = {}
            self.nodes[str(node)] = node

    def add_edge(self, from_node, to_node, label):
        self.add_node(from_node)
        self.add_node(to_node)
        self.graph[str(from_node)][str(to_node)] = label

    def rename_nodes(self):
        idx = 0
        for key, value in self.nodes.items():
            value.idx = idx
            idx += 1

    def reduce_to_afd(self):
        start = "E'->.E"
        afd = Graph(self.terminais, self.naoterminais, self.seguintes, self.producoes)
        closure = self.__get_closure(start)

        simbolos = set(itertools.chain(*[prod.left + prod.right for prod in self.nodes.values()]))
        self.simbolos = [x for x in simbolos if x != '.']

        queue = Queue(maxsize=1000)
        queue.put(AfdNode(closure))
        hash = {}
        while not queue.empty():
            front = queue.get()
            for simbolo in simbolos:
                tmp = []
                for prod in front.closure:
                    tmp += [neighbor for neighbor in self.graph[prod] if self.graph[prod][neighbor] == simbolo]
                if len(tmp):
                    goto = []
                    tmpclosure = itertools.chain(*[self.__get_closure(x) for x in tmp])
                    for node in tmpclosure:
                        if node not in goto:
                            goto.append(node)
                    afdnode = AfdNode(goto)
                    afd.add_edge(front, afdnode, simbolo)
                    if str(afdnode) not in hash:
                        queue.put(afdnode)
                        hash[str(afdnode)] = True

        self.graph = afd.graph
        self.nodes = afd.nodes
        self.state = "afd"

        self.get_slr_table()

    def __get_closure(self, node):
        closure = [node]
        queue = Queue(maxsize=10000)
        queue.put(node)
        while not queue.empty():
            front = queue.get()
            for neighbor in self.graph[front]:
                if self.graph[front][neighbor] == "eps" and neighbor not in closure:
                    closure.append(neighbor)
                    queue.put(neighbor)
        return closure

    def view(self):
        f = Digraph()
        f.attr(rankdir='LR', size='8,5')
        if self.state == "afd":
            for from_node in self.graph:
                for to_node in self.graph[from_node]:
                    f.edge(str(self.nodes[from_node].idx), str(self.nodes[to_node].idx), label=self.graph[from_node][to_node])
                    f.render('log/questao_lista_afd.gv', view=False)
        else:
            for from_node in self.graph:
                for to_node in self.graph[from_node]:
                    f.edge(from_node, to_node, label=self.graph[from_node][to_node])
            f.render('log/questao_lista_afnd.gv', view=False)

    def get_slr_table(self):
        if self.state == "afd":
            table = {"acao": {}, "goto": {}}

            self.rename_nodes()
            max_idx = len(self.nodes)
            for i in range(max_idx):
                for simbolo in self.terminais + ["$"]:
                    if i not in table["acao"]:
                        table["acao"][i] = {}
                    table["acao"][i][simbolo] = ""
                for simbolo in self.naoterminais:
                    if i not in table["goto"]:
                        table["goto"][i] = {}
                    table["goto"][i][simbolo] = ""

            for node in self.graph:
                for neighbor in self.graph[node]:
                    if self.graph[node][neighbor] in self.terminais + ["$"]:
                        if table["acao"][self.nodes[node].idx][self.graph[node][neighbor]] != "":
                            print("NÃO É SLR!!")
                        table["acao"][self.nodes[node].idx][self.graph[node][neighbor]] = "d " + str(self.nodes[neighbor].idx)

            for node in self.nodes.values():
                alfaponto = [prod for prod in node.closure if prod[-1] == "."]
                if len(alfaponto) > 1:
                    print("FUDEU!")
                elif len(alfaponto) == 1 and alfaponto[0] != "E'->E.":
                    for seguinte in self.seguintes[alfaponto[0][0]]:
                        if table["acao"][node.idx][seguinte]:
                            print("NÃO É SLR!!")
                        table["acao"][node.idx][seguinte] = "r " + str(self.producoes[alfaponto[0][:-1]])
                elif len(alfaponto) == 1 and alfaponto[0] == "E'->E.":
                    if table["acao"][node.idx]["$"] != "":
                        print("NÃO É SLR!!")
                    table["acao"][node.idx]["$"] = "act"

            for node in self.graph:
                for neighbor in self.graph[node]:
                    if self.graph[node][neighbor] in naoterminais:
                        if self.nodes[node].idx not in table["goto"]:
                            table["goto"][self.nodes[node].idx] = {}
                        table["goto"][self.nodes[node].idx][self.graph[node][neighbor]] = str(self.nodes[neighbor].idx)

            header = "; " + "; ".join(terminais) + "; $; " + "; ".join(naoterminais)
            print(header)
            for i in range(len(self.nodes)):
                row = str(i) + "; " + "; ".join(table["acao"][i][terminal] for terminal in terminais) + "; " + table["acao"][i]["$"] + "; " + "; ".join([table["goto"][i][naoterminal] for naoterminal in naoterminais])
                print(row)


# prods = [
#     AfndNode(["E'"], ["E"]),
#     AfndNode(["E"], ["E", "+", "T"]),
#     AfndNode(["E"], ["T"]),
#     AfndNode(["T"], ["T", "*", "F"]),
#     AfndNode(["T"], ["F"]),
#     AfndNode(["F"], ["(", "E", ")"]),
#     AfndNode(["F"], ["id"]),
# ]
#
# terminais = ["id", "+", "*", "(", ")", "$"]
# naoterminais = ["E", "T", "F"]
#
# seguintes = {
#     "E": ["+", ")", "$"],
#     "T": ["+", "*", ")", "$"],
#     "F": ["+", "*", ")", "$"],
#     "E'": ["$"]
# }

prods = [
    AfndNode(["E'"], ["E"]),
    AfndNode(["E"], ["E", "+", "T"]),
    AfndNode(["E"], ["T"]),
    AfndNode(["T"], ["T", "*", "F"]),
    AfndNode(["T"], ["F"]),
    AfndNode(["F"], ["P", "@", "F"]),
    AfndNode(["F"], ["P"]),
    AfndNode(["P"], ["(", "E", ")"]),
    AfndNode(["P"], ["a"]),
    AfndNode(["P"], ["a", "(", "L", ")"]),
    AfndNode(["L"], ["L", ",", "E"]),
    AfndNode(["L"], ["E"]),
]

terminais = ["@", "+", "*", "(", ")", "a", ","]
naoterminais = ["E", "T", "F", "P", "L"]
seguintes = {
    'E': ['$', '+', ')', ','],
    'F': ['*', '$', '+', ')', ','],
    'L': [')', ','],
    'P': ['@', '*', '$', '+', ')', ','],
    'T': ['*', '$', '+', ')', ',']
}

prods_ext = []
for prod in prods:
    for i in range(len(prod.right)):
        prods_ext.append(AfndNode(prod.left, prod.right[:i] + ["."] + prod.right[i:]))
    prods_ext.append(AfndNode(prod.left, prod.right + ["."]))

graph = Graph(terminais, naoterminais, seguintes, {str(prods[i]): i for i in range(len(prods))})
for prod in prods_ext:
    # primeiro tipo de transicao de AFND
    if prod.right[-1] != ".":
        next_prod_right = []
        i = 0
        transicao = None
        while i < len(prod.right):
            if prod.right[i] != ".":
                next_prod_right.append(prod.right[i])
                i += 1
            else:
                next_prod_right.append(prod.right[i + 1])
                transicao = prod.right[i+1]
                next_prod_right.append(".")
                i += 2
        new_prod = AfndNode(prod.left, next_prod_right)

        graph.add_edge(prod, new_prod, transicao)

    # segundo tipo de transicao de AFND
    if prod.right[-1] != ".":
        next_prod_right = []
        i = 0
        while i < len(prod.right):
            if prod.right[i] == ".":
                prods_transicoes = [x for x in prods_ext if x.left[0] == prod.right[i+1] and x.right[0] == "." and str(prod) != str(x)]
                for prod_transicao in prods_transicoes:
                    graph.add_edge(prod, prod_transicao, "eps")
            i += 1

graph.view()
graph.reduce_to_afd()
graph.view()
