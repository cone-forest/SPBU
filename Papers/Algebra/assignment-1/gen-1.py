import collections
import copy as cp

class Graph:
    def __init__(self):
        self.graph = collections.defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v] = list()

    def remove_edge(self, u, v):
        if v in self.graph[u]:
            self.graph[u].remove(v)

    def is_cyclic_util(self, v, visited, parent):
        visited[v] = True
        for i in self.graph[v]:
            if not visited[i]:
                if self.is_cyclic_util(i, visited, v):
                    return True
            elif parent != i:
                return True
        return False

    def is_cyclic(self):
        visited = {v: False for v in self.graph}
        for v in self.graph:
            if not visited[v]:
                if self.is_cyclic_util(v, visited, -1):
                    return True
        return False

d = {
        'A': 0,
        'B': 1,
        'C': 2,
        'D': 3,
        'E': 4,
        'F': 5,
        'G': 6,
        'H': 7,
        'I': 8,
        'J': 9,
}

# Создание графа
g = Graph()
g.add_edge(d['C'], d['A'])
g.add_edge(d['C'], d['H'])
g.add_edge(d['A'], d['F'])
g.add_edge(d['A'], d[])
g.add_edge(d[], d[])
g.add_edge(d[], d[])
print(g)
for i in range(len(g.graph)):
  for j in range(len(g.graph)):
    if i == j:
      continue
    else:
      copy = cp.deepcopy(g)
      copy.add_edge(i, j)
      if copy.is_cyclic():
        print(i, j)
