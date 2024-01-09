
def createGraph():
    g = {}

    n = int(input("Enter the number of vertices:"))

    type = int(input("\nEnter the type of graph\n1. Directed\n2. Undirected\n"))

    if type == 1:
        maxNumberOFEdges = n*(n-1)
    else:
        maxNumberOFEdges = (n*(n-1))//2

    for i in range(maxNumberOFEdges):
        print("Enter the edge", i+1, "(-1 -1  to exit)")
        u, v = map(str, input().split(" "))
        if u == '-1' and v == '-1':
            break

        if u not in g:
            g[u] = []
        if v not in g:
            g[v] = []
        
        g[u].append(v)
        if (type == 2):
            g[v].append(u)
    return g

def inputHeuristic(g):
    h={}

    for node in g:
        h[node]=int(input("Enter heuristic value of "+str(node)+":"))
    return h

def hillClimbing(graph,heuristicValues):

    startNode=input("Enter starting node: ")
    sortedList =[startNode]

    visited=set()

    while sortedList :

        current=sortedList [0] # take the first element

        print (current)
        visited.add(current)

        sortedList=[]
        for i in graph [current]: # for all the neighbors of currrent node

            if(i not in visited and i not in sortedList and heuristicValues [i] <heuristicValues [current]):
                sortedList.append(i)

                #sort after each iteration 
                sortedList=sorted (sortedList,key=lambda v: heuristicValues [v])

if __name__ == "__main__":
    graph=createGraph()
    heuristicValues=inputHeuristic(graph)

    hillClimbing(graph,heuristicValues)
