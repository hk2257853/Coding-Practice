from queue import Queue

def valid_state(state):
    if state[0] < 0 or state[0] > 4 or state[1] < 0 or state[1] > 4 or state[2] < 0 or state[2] > 1 or state[3] < 0 or state[3] > 1:
        return False
    if (state[0] != 0 and state[0] < state[1]) or (state[2] != 0 and state[2] < state[3]):
        return False
    return True

def generate_next_states(state):
    states = []
    if state[2] == 1:
        # boat is on the left bank
        for i in range(1, 4+1):
            for j in range(0, i+1):
                new_state = (state[0]-i, state[1]-j, state[2]-1, state[3]+1)
                if valid_state(new_state):
                    states.append(new_state)
    else:
        # boat is on the right bank
        for i in range(1, 4+1):
            for j in range(0, i+1):
                new_state = (state[0]+i, state[1]+j, state[2]+1, state[3]-1)
                if valid_state(new_state):
                    states.append(new_state)
    return states

def bfs_missionaries_cannibals(start, goal):
    visited = set()
    q = Queue()
    q.put(start)
    visited.add(start)

    while not q.empty():
        node = q.get()
        if node == goal:
            print("Solution found!")
            return True
        for neighbor in generate_next_states(node):
            if neighbor not in visited:
                visited.add(neighbor)
                q.put(neighbor)

    print("Solution not found.")
    return False

# Taking input from the user
start_state = tuple(map(int, input("Enter the initial state of the problem (3 numbers for missionaries, 3 numbers for cannibals, 1 for boat): ").split()))
goal_state = tuple(map(int, input("Enter the goal state of the problem (3 numbers for missionaries, 3 numbers for cannibals, 1 for boat): ").split()))

# Finding the solution using BFS
found_solution = bfs_missionaries_cannibals(start_state, goal_state)

if not found_solution:
    print("Solution not found!")

