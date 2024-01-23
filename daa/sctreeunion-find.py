class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []
    def add_edge(self, src, dest, weight):
        self.graph.append([src, dest, weight])
    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])
    def union(self, parent, rank, x, y):
        x_root = self.find(parent, x)
        y_root = self.find(parent, y)
        if rank[x_root] < rank[y_root]:
            parent[x_root] = y_root
        elif rank[x_root] > rank[y_root]:
            parent[y_root] = x_root
        else:
            parent[y_root] = x_root
            rank[x_root] += 1
    def kruskal_mst(self):
        result = []
        i, e = 0, 0
        self.graph = sorted(self.graph, key=lambda item: item[2])
        parent = []
        rank = []
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        while e < self.V - 1 and i < len(self.graph):
            src, dest, weight = self.graph[i]
            i += 1
            x = self.find(parent, src)
            y = self.find(parent, dest)
            if x != y:
                e += 1 
                result.append([src, dest, weight])
                self.union(parent, rank, x, y)
        print("Edges in the Minimum Cost Spanning Tree:")
        for src, dest, weight in result:
            print(f"{src} - {dest} Weight: {weight}")
g = Graph(4)
g.add_edge(0, 1, 10)
g.add_edge(0, 2, 6)
g.add_edge(0, 3, 5)
g.add_edge(1, 3, 15)
g.add_edge(2, 3, 4)
g.kruskal_mst()