import networkx as nx
import matplotlib.pyplot as plt

from queue import PriorityQueue

heuristic = {}
graph = {}
visited = []

def addHeuristic(node,value):
    heuristic[node] = value

def addEdge(u, v):
    if u not in graph:
        graph[u] = []
    if v not in graph:
        graph[v] = []
    graph[u].append(v)
    graph[v].append(u)

def hillClimbing(source,target):
    solvable = True
    s=9999
    q= PriorityQueue()
    q.put((heuristic[source],source))
    
    while not q.empty():
        u = q.get()[1]
        while not q.empty():
            q.get()
        if(heuristic[u]<s):
            s=heuristic[u]
            visited.append(u)
            for neighbour in graph[u]:
                if neighbour not in visited:
                    q.put((heuristic[neighbour],neighbour))
        else:
            solvable = False
            break
        if u == target:
            print("Path: ")
            for i in visited:
                print (i, end =" ")
            break
    
    if not solvable:
        print("No Solution Possible ")

addHeuristic("1", 10)
addHeuristic("2", 8)
addHeuristic("3", 5)
addHeuristic("4", 7)
addHeuristic("5", 3)
addHeuristic("6", 6)
addHeuristic("7", 5)
addHeuristic("8", 3)
addHeuristic("9", 1)
addHeuristic("10", 0)

addEdge("1", "2")
addEdge("1", "6")
addEdge("2", "3")
addEdge("2", "4")
addEdge("3", "4")
addEdge("3", "5")
addEdge("4", "5")
addEdge("5", "9")
addEdge("5", "10")
addEdge("6", "7")
addEdge("6", "8")
addEdge("7", "9")
addEdge("8", "9")
addEdge("9", "10")

print()
print("Nodes and Heuristic Values",heuristic)
print("Graph Edges", graph)

src = input("Enter the Start Node ")
target = input("Enter the Target Node ")
hillClimbing(src,target)


G = nx.Graph(graph)
nx.draw(G, with_labels=True)
plt.show()