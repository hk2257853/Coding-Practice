from collections import deque

def bfs(jug1_capacity, jug2_capacity, target):
    open_list = deque([(0, 0, None)])  # Starting state: (0 gallons in jug1, 0 gallons in jug2, parent state)
    closed_list = set()

    while open_list:
        node = open_list.popleft()

        if node[0] == target or node[1] == target:
            return reconstruct_path(node, closed_list)

        closed_list.add(node)

        children = move_gen(node)

        no_loops = remove_seen(children, open_list, closed_list)

        new_nodes = make_pairs(no_loops, node)

        open_list.extend(new_nodes)

    return None

def reconstruct_path(node, closed_list):
    path = []
    while node:
        path.append((node[0], node[1]))
        node = node[2]  # Get the parent node
    return path[::-1]  # Reverse the path to get the correct order

def move_gen(node):
    jug1, jug2, _ = node
    children = []

    # Perform all possible jug operations
    # Fill jug1
    children.append((jug1_capacity, jug2, node))
    # Fill jug2
    children.append((jug1, jug2_capacity, node))
    # Empty jug1
    children.append((0, jug2, node))
    # Empty jug2
    children.append((jug1, 0, node))
    # Pour jug1 into jug2 until jug2 is full or jug1 is empty
    children.append((max(0, jug1 - (jug2_capacity - jug2)), min(jug2_capacity, jug1 + jug2), node))
    # Pour jug2 into jug1 until jug1 is full or jug2 is empty
    children.append((min(jug1_capacity, jug1 + jug2), max(0, jug2 - (jug1_capacity - jug1)), node))

    return children

def remove_seen(children, open_list, closed_list):
    no_loops = []
    for child in children:
        if not occurs_in(child, open_list) and child not in closed_list:
            no_loops.append(child)
    return no_loops

def occurs_in(node, node_list):
    for n in node_list:
        if node[0] == n[0] and node[1] == n[1]:
            return True
    return False

def make_pairs(node_list, parent):
    return [(node[0], node[1], parent) for node in node_list]

def display_steps(steps):
    print("Steps to reach the target:")
    for i, step in enumerate(steps):
        jug1, jug2 = step
        print(f"Step {i+1}: ({jug1} gallons, {jug2} gallons)")
    print()

# Take input of jug capacities and target gallons
jug1_capacity = int(input("Enter the capacity of jug 1 (in gallons): "))
jug2_capacity = int(input("Enter the capacity of jug 2 (in gallons): "))
target = int(input("Enter the target number of gallons: "))

# Solve the problem using BFS
solution = bfs(jug1_capacity, jug2_capacity, target)

if solution:
    print("Target reached!")
    display_steps(solution)
else:
    print("No solution found.")