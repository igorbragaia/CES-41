from graphviz import Digraph
# esse codigo eh uma implementacao do algoritmo do slide 5c do prof Mokarzel


class Node:
    def __init__(self, left, right):
        self.left = left
        self.right = right

    def __str__(self):
        return "".join(self.left) + "->" + "".join(self.right)


class Graph:
    def __init__(self):
        self.graph = {}
        self.nodes = {}

    def add_node(self, node):
        if str(node) not in self.graph:
            self.graph[str(node)] = {}
            self.nodes[str(node)] = node

    def add_edge(self, from_node, to_node, label):
        self.add_node(from_node)
        self.add_node(to_node)
        self.graph[str(from_node)][str(to_node)] = label

    def view(self):
        f = Digraph()
        f.attr(rankdir='LR', size='8,5')

        for from_node in self.graph:
            for to_node in self.graph[from_node]:
                f.edge(from_node, to_node, label=self.graph[from_node][to_node])

        f.view()


prods = [
    Node(["E'"], ["E"]),
    Node(["E"], ["E", "+", "T"]),
    Node(["E"], ["T"]),
    Node(["T"], ["T", "*", "F"]),
    Node(["T"], ["F"]),
    Node(["F"], ["(", "E", ")"]),
    Node(["F"], ["id"]),
]

prods_ext = []
for prod in prods:
    for i in range(len(prod.right)):
        prods_ext.append(Node(prod.left, prod.right[:i] + ["."] + prod.right[i:]))
    prods_ext.append(Node(prod.left, prod.right + ["."]))

graph = Graph()
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
        new_prod = Node(prod.left, next_prod_right)

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
