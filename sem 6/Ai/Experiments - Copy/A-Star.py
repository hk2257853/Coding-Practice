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

def retCost(a,b):
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

#nodes = int(input("Enter the number of nodes "))
#for i in range(nodes):
#    node=input("Enter Node ")
#    val=int(input("Enter Heuristic Value "))
#    addHeuristic(node,val)

#edges = int(input("Enter the number of Edges "))
#for i in range(edges):
#    start = input("Enter Start node of Edge ")
#   end = input("Enter Destination node of Edge ")
#    cost = int(input("Enter Cost of the Edge "))
#    addEdge(start,end,cost)

addHeuristic("a", 10)
addHeuristic("b", 8)
addHeuristic("c", 5)
addHeuristic("d", 7)
addHeuristic("e", 3)
addHeuristic("f", 6)
addHeuristic("g", 5)
addHeuristic("h", 3)
addHeuristic("i", 1)
addHeuristic("j", 0)

addEdge("a", "b", 6)
addEdge("a", "f", 3)
addEdge("b", "c", 3)
addEdge("b", "d", 2)
addEdge("c", "d", 1)
addEdge("c", "e", 5)
addEdge("d", "e", 8)
addEdge("e", "i", 5)
addEdge("e", "j", 5)
addEdge("f", "g", 1)
addEdge("f", "h", 7)
addEdge("g", "i", 3)
addEdge("h", "i", 2)
addEdge("i", "j", 3)


src = input("Enter the Start Node ")
target = input("Enter the Target Node ")
print(graph)
print()
print("HEURISTIC ",heuristic)
print()
aStar(src,target)
