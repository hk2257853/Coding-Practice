import networkx as nx
import matplotlib.pyplot as plt
graph = {}


def add_edge(graph, u, v):
    if u not in graph:
        graph[u] = []
    if v not in graph:
        graph[v] = []
    graph[u].append(v)
    graph[v].append(u)


def dfs_traversal(graph, start, visited=None):
    if visited is None:
        visited = set() 
    visited.add(start)
    print(start, end=" ")
    for neighbor in graph[start]:#elemnts in list which is dictionary are the neigbours
        if neighbor not in visited:
            dfs_traversal(graph, neighbor, visited)


n = int(input("Enter the number of edges in the graph: "))
for i in range(1, n+1):
    start, end = input(f"Enter the edge {i} separated by a space (start end): ").split()
    add_edge(graph, start, end)


G = nx.Graph(graph)
nx.draw(G, with_labels=True)
plt.show()


start_node = input("Enter the starting node for DFS traversal: ")
print("DFS Traversal: ", end="")
dfs_traversal(graph, start_node)
print()
