from queue import Queue

# Creating an empty dictionary where we'll store the edges of the graph
graph = {}

# Function to add edges to the graph
def add_edge(graph, u, v): #It checks whether the nodes are already present in the graph and adds them if not. Then, it appends the nodes to each other's list of neighbors.
    if u not in graph:
        graph[u] = []
    if v not in graph:
        graph[v] = []
    graph[u].append(v)
    graph[v].append(u)

# Function to do a breadth-first traversal of the graph
def bfs_traversal(graph, start):
    visited = set() # initializes an empty set to keep track of visited nodes
    q = Queue() #a queue to keep track of the nodes to be processed
    q.put(start) # and adds the start node to both
    visited.add(start) 

    while not q.empty():        #hen, it loops until the queue is empty and keeps dequeuing nodes and adding their unvisited neighbors to the queue. It also marks visited nodes to avoid revisiting them. Finally, it prints the BFS traversal order.
        node = q.get()
        print(node, end=" ")
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                q.put(neighbor)

# Taking input from the user
n = int(input("Enter the number of edges in the graph: "))
for i in range(1, n+1):
    start, end = input(f"Enter the edge {i} separated by a space (start end): ").split()
    add_edge(graph, start, end)

# Doing a breadth-first traversal starting from node 'a'
start_node = input("Enter the starting node for BFS traversal: ")
print("BFS Traversal: ", end="")
bfs_traversal(graph, start_node)
print()
