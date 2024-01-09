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

#nodes = int(input("Enter the number of Nodes "))
#for i in range(nodes):
#    node=input("Enter Node ")
#    val=int(input("Enter Heuristic Value "))
#    addHeuristic(node,val)

#edges = int(input("Enter the number of Edges "))
#for i in range(edges):
#    start=input("Enter Start node of Edge ")
#    end=input("Enter Destination node of Edge ")
#    addEdge(start,end)

#addHeuristic("s", 21)
#addHeuristic("a", 14)
#addHeuristic("b", 16)
#addHeuristic("c", 8)
#addHeuristic("d", 12)
#addHeuristic("f", 5)
#addHeuristic("g", 6)
#addHeuristic("h", 4)
#addHeuristic("i", 6)
#addHeuristic("j", 0)

#addEdge("s", "a")
#addEdge("s", "b")
#addEdge("s", "c")
#addEdge("s", "d")
#addEdge("a", "f")
#addEdge("a", "g")
#addEdge("c", "f")
#addEdge("c", "g")
#addEdge("d", "g")
#addEdge("d", "h")
#addEdge("b", "g")
#addEdge("b", "h")
#addEdge("f", "i")
#addEdge("g", "i")
#addEdge("g", "j")
#addEdge("h", "j")


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

addEdge("a", "b")
addEdge("a", "f")
addEdge("b", "c")
addEdge("b", "d")
addEdge("c", "d")
addEdge("c", "e")
addEdge("d", "e")
addEdge("e", "i")
addEdge("e", "j")
addEdge("f", "g")
addEdge("f", "h")
addEdge("g", "i")
addEdge("h", "i")
addEdge("i", "j")

print()
print("Nodes and Heuristic Values",heuristic)
print("Graph Edges", graph)

src = input("Enter the Start Node ")
target = input("Enter the Target Node ")
hillClimbing(src,target)
