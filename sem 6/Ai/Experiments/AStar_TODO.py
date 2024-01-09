import networkx as nx
import matplotlib.pyplot as plt

from queue import PriorityQueue

heuristic = {}
graph = {}

def addHeuristic(node, val):
    heuristic[node] = val

def addEdge(u,v,cost):
    if u not in graph:
        graph[u] = []
    if v not in graph:
        graph[v] = [] 
    
    graph[u].append((v,cost))
    graph[v].append((u,cost))

def retCost(a,b): # returns the cost of the edge between nodes a and b.
    for e in graph[a]:
        if e[0] == b:
            return e[1]

def aStar(src,target):
    visited = []
    path = []
    cost,i = 0,0
    q = PriorityQueue()
    q.put((0,src))
    visited.append(src)
    
    while not q.empty():
        u = q.get()[1]
        visited.append(u)
        path.append(u)
        t = retCost(path[i-1],u)
        if(t == None):
            t=0
        cost = cost + t
        i=i+1
        if u == target:
            print("Path ", end=" ")
            for i in path:
                print( i, end = " ")
            print()
            print()
            print("Cost(Addition of Edges Cost) : ",cost)
            break
        for neighbour in graph[u]:
            if neighbour[0] not in visited:
                val = heuristic[neighbour[0]] + neighbour[1] + cost  
                q.put((val,neighbour[0]))

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

addEdge("1", "2", 6)
addEdge("1", "6", 3)
addEdge("2", "3", 3)
addEdge("2", "4", 2)
addEdge("3", "4", 1)
addEdge("3", "5", 5)
addEdge("4", "5", 8)
addEdge("5", "9", 5)
addEdge("5", "10", 5)
addEdge("6", "7", 1)
addEdge("6", "8", 7)
addEdge("7", "9", 3)
addEdge("8", "9", 2)
addEdge("9", "10", 3)

src = input("Enter the Start Node ")
target = input("Enter the Target Node ")
print(graph)
print()
print("HEURISTIC ",heuristic)
print()
aStar(src,target)

G = nx.Graph(graph)
nx.draw(G, with_labels=True)
plt.show()