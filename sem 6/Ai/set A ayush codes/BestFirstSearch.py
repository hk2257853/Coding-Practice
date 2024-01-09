from queue import PriorityQueue

# Creating an empty dictionary where we'll store the edges of the graph
graph = {}

# Function to add edges to the graph
def add_edge(graph, u, v, weight):
    if u not in graph:
        graph[u] = []
    if v not in graph:
        graph[v] = []
    graph[u].append((v, weight))
    graph[v].append((u, weight))

# Function to do a best-first traversal of the graph
def best_first_traversal(graph, start, goal):
    visited = set()
    pq = PriorityQueue()
    pq.put((0, start, [start]))
    visited.add(start)

    while not pq.empty():
        (cost, node, path) = pq.get()
        print(node, end=" ")
        if node == goal:
            print("\nPath:", "->".join(path))
            return True
        for neighbor, weight in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                new_path = path + [neighbor]
                pq.put((weight, neighbor, new_path))

    return False

# Taking input from the user
n = int(input("Enter the number of edges in the graph: "))
for i in range(1, n+1):
    start, end, weight = input(f"Enter the edge {i} separated by a space (start end weight): ").split()
    add_edge(graph, start, end, int(weight))

# Doing a best-first traversal starting from node 'a' and ending at node 'f'
start_node = input("Enter the starting node for Best First Search traversal: ")
goal_node = input("Enter the goal node for Best First Search traversal: ")
print("Best First Search Traversal: ", end="")
found_path = best_first_traversal(graph, start_node, goal_node)

if not found_path:
    print("Path not found!")
