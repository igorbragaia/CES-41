from graphviz import Digraph
from queue import Queue
from pprint import pprint
import itertools
# esse codigo eh uma implementacao do algoritmo do slide 5c do prof Mokarzel


def hashlist(list):
    return ", ".join(sorted(list))


class AfndNode:
    def __init__(self, left, right):
        self.left = left
        self.right = right

    def __str__(self):
        return "".join(self.left) + "->" + "".join(self.right)


class AfdNode:
    def __init__(self, closure):
        self.closure = closure

    def __str__(self):
        return self.closure


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

    def get_afd(self):
        tmp = Graph()
        gotos = self.get_gotos()
        for Ii in gotos["gotos"]:
            for Ij in gotos["gotos"][Ii]:
                tmp.add_edge(Ii, Ij, gotos["gotos"][Ii][Ij])

        afd = Graph()
        queue = Queue(maxsize=10000)
        queue.put(gotos["start"])
        hash = {}
        while not queue.empty():
            front = queue.get()
            for neighbor in tmp.graph[front]:
                afd.add_edge(front, neighbor, tmp.graph[front][neighbor])
                if neighbor not in hash:
                    queue.put(neighbor)
                    hash[neighbor] = True

        return afd

    def get_gotos(self):
        closures = self.get_closures()

        simbolos = set(itertools.chain(*[prod.left+prod.right for prod in self.nodes.values()]))
        simbolos = [x for x in simbolos if x != '.']

        gotos = {}
        for key, value in closures.items():
            for simbolo in simbolos:
                J = []
                for prod in value:
                    for neighbor in self.graph[prod]:
                        if self.graph[prod][neighbor] == simbolo:
                            J.extend(closures[neighbor])
                if len(J):
                    if hashlist(value) not in gotos:
                        gotos[hashlist(value)] = {}
                    gotos[hashlist(value)][hashlist(J)] = simbolo
        return {
            "gotos": gotos,
            "start": hashlist(closures["E'->.E"])
        }

    def get_closures(self):
        closures = {}
        for node in self.graph:
            closures[node] = self.__get_closure(node)
        return closures

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

        for from_node in self.graph:
            for to_node in self.graph[from_node]:
                f.edge(from_node, to_node, label=self.graph[from_node][to_node])

        f.view()

prods = [
    AfndNode(["E'"], ["E"]),
    AfndNode(["E"], ["E", "+", "T"]),
    AfndNode(["E"], ["T"]),
    AfndNode(["T"], ["T", "*", "F"]),
    AfndNode(["T"], ["F"]),
    AfndNode(["F"], ["(", "E", ")"]),
    AfndNode(["F"], ["id"]),
]

prods_ext = []
for prod in prods:
    for i in range(len(prod.right)):
        prods_ext.append(AfndNode(prod.left, prod.right[:i] + ["."] + prod.right[i:]))
    prods_ext.append(AfndNode(prod.left, prod.right + ["."]))

afnd = Graph()
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

        afnd.add_edge(prod, new_prod, transicao)

    # segundo tipo de transicao de AFND
    if prod.right[-1] != ".":
        next_prod_right = []
        i = 0
        while i < len(prod.right):
            if prod.right[i] == ".":
                prods_transicoes = [x for x in prods_ext if x.left[0] == prod.right[i+1] and x.right[0] == "." and str(prod) != str(x)]
                for prod_transicao in prods_transicoes:
                    afnd.add_edge(prod, prod_transicao, "eps")
            i += 1

afd = afnd.get_afd()
afd.view()
