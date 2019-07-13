from graphviz import Digraph


class Graph:
    def __init__(self):
        self.graph = {}

    def add_node(self, node_name):
        if node_name not in self.graph:
            self.graph[node_name] = {}

    def add_edge(self, from_node, to_node, label):
        self.add_node(from_node)
        self.add_node(to_node)
        self.graph[from_node][to_node] = label

    def view(self):
        f = Digraph()
        f.attr(rankdir='LR', size='8,5')

        for from_node in self.graph:
            for to_node in self.graph[from_node]:
                f.edge(from_node, to_node, label=self.graph[from_node][to_node])

        f.view()


graph = Graph()
graph.add_edge('LR_0', 'LR_2', 'SS(B)')
graph.add_edge('LR_0', 'LR_1', 'SS(S)')
graph.add_edge('LR_1', 'LR_3', 'S($end)')
graph.add_edge('LR_2', 'LR_6', 'SS(b)')
graph.add_edge('LR_2', 'LR_5', 'SS(a)')
graph.add_edge('LR_2', 'LR_4', 'S(A)')
graph.add_edge('LR_5', 'LR_7', 'S(b)')
graph.add_edge('LR_5', 'LR_5', 'S(a)')
graph.add_edge('LR_6', 'LR_6', 'S(b)')
graph.add_edge('LR_6', 'LR_5', 'S(a)')
graph.add_edge('LR_7', 'LR_8', 'S(b)')
graph.add_edge('LR_7', 'LR_5', 'S(a)')
graph.add_edge('LR_8', 'LR_6', 'S(b)')
graph.add_edge('LR_8', 'LR_5', 'S(a)')
graph.view()
