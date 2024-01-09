import networkx as nx
import matplotlib.pyplot as plt
from queue import Queue

graph = {}

def add_edge(graph, u, v):
    if u not in graph:
        graph[u] = []
    if v not in graph:
        graph[v] = []
    graph[u].append(v)
    graph[v].append(u)

def bfs_traversal(graph, start):
    visited = set() 
    q = Queue() 
    q.put(start) 
    visited.add(start) 

    while not q.empty():        
        node = q.get()
        print(node, end=" ")
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                q.put(neighbor)

n = int(input("Enter the number of edges in the graph: "))
for i in range(1, n+1):
    start, end = input(f"Enter the edge {i} separated by a space (start end): ").split()
    add_edge(graph, start, end)

start_node = input("Enter the starting node for BFS traversal: ")
print("BFS Traversal: ", end="")
bfs_traversal(graph, start_node)
print()

# Displaying the graph
G = nx.Graph(graph)
nx.draw(G, with_labels=True)
plt.show()