from collections import deque

# Define the problem variables
jug_1_size = 4
jug_2_size = 3
goal_amount = 2

# Define the initial state of the problem
initial_state = (0, 0)

# Define the goal state of the problem
goal_state = (goal_amount, 0)

# Define a function to generate the next states
def generate_next_states(current_state):
    next_states = []
    # Fill jug 1
    next_states.append((jug_1_size, current_state[1]))
    # Fill jug 2
    next_states.append((current_state[0], jug_2_size))
    # Empty jug 1
    next_states.append((0, current_state[1]))
    # Empty jug 2
    next_states.append((current_state[0], 0))
    # Pour from jug 1 to jug 2
    amount = min(current_state[0], jug_2_size - current_state[1])
    next_states.append((current_state[0] - amount, current_state[1] + amount))
    # Pour from jug 2 to jug 1
    amount = min(current_state[1], jug_1_size - current_state[0])
    next_states.append((current_state[0] + amount, current_state[1] - amount))
    return next_states

# Define a function to solve the problem
def solve_problem():
    # Create a queue to hold the states to explore
    queue = deque()
    # Add the initial state to the queue
    queue.append(initial_state)
    # Create a set to hold the visited states
    visited = set()
    # Loop until the queue is empty
    while queue:
        # Get the next state to explore
        current_state = queue.popleft()
        # Check if the state is the goal state
        if current_state == goal_state:
            return True
        # Generate the next states
        next_states = generate_next_states(current_state)
        # Loop through the next states
        for next_state in next_states:
            # Check if the next state has not been visited
            if next_state not in visited:
                # Add the next state to the queue
                queue.append(next_state)
                # Add the next state to the visited set
                visited.add(next_state)
    # If the loop completes without finding the goal state, return False
    return False

# Call the solve_problem function and print the result
if solve_problem():
    print("The problem can be solved.")
else:
    print("The problem cannot be solved.")