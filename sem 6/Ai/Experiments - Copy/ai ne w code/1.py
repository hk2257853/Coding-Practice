from collections import deque

def is_valid_state(state):
    missionaries_left, cannibals_left, boat = state

    # Check if the number of missionaries is valid
    if missionaries_left < 0 or missionaries_left > 3:
        return False

    # Check if the number of cannibals is valid
    if cannibals_left < 0 or cannibals_left > 3:
        return False

    # Check if cannibals outnumber missionaries on either bank
    if missionaries_left > 0 and cannibals_left > missionaries_left:
        return False

    missionaries_right = 3 - missionaries_left
    cannibals_right = 3 - cannibals_left

    # Check if cannibals outnumber missionaries on the right bank
    if missionaries_right > 0 and cannibals_right > missionaries_right:
        return False

    return True

def get_possible_states(state):
    states = []
    missionaries_left, cannibals_left, boat = state

    if boat == 'L':
        # Try moving 2 missionaries
        new_state = (missionaries_left - 2, cannibals_left, 'R')
        if is_valid_state(new_state):
            states.append(new_state)

        # Try moving 2 cannibals
        new_state = (missionaries_left, cannibals_left - 2, 'R')
        if is_valid_state(new_state):
            states.append(new_state)

        # Try moving 1 missionary and 1 cannibal
        new_state = (missionaries_left - 1, cannibals_left - 1, 'R')
        if is_valid_state(new_state):
            states.append(new_state)

        # Try moving 1 missionary
        new_state = (missionaries_left - 1, cannibals_left, 'R')
        if is_valid_state(new_state):
            states.append(new_state)

        # Try moving 1 cannibal
        new_state = (missionaries_left, cannibals_left - 1, 'R')
        if is_valid_state(new_state):
            states.append(new_state)

    else:
        # Try moving 2 missionaries
        new_state = (missionaries_left + 2, cannibals_left, 'L')
        if is_valid_state(new_state):
            states.append(new_state)

        # Try moving 2 cannibals
        new_state = (missionaries_left, cannibals_left + 2, 'L')
        if is_valid_state(new_state):
            states.append(new_state)

        # Try moving 1 missionary and 1 cannibal
        new_state = (missionaries_left + 1, cannibals_left + 1, 'L')
        if is_valid_state(new_state):
            states.append(new_state)

        # Try moving 1 missionary
        new_state = (missionaries_left + 1, cannibals_left, 'L')
        if is_valid_state(new_state):
            states.append(new_state)

        # Try moving 1 cannibal
        new_state = (missionaries_left, cannibals_left + 1, 'L')
        if is_valid_state(new_state):
            states.append(new_state)

    return states

def dfs():
    start_state = (3, 3, 'L')
    goal_state = (0, 0, 'R')

    visited = set()
    stack = deque([(start_state, [])])

    while stack:
        state, path = stack.pop()
        visited.add(state)

        if state == goal_state:
            return path

        possible_states = get_possible_states(state)
        for next_state in possible_states:
            if next_state not in visited:
                stack.append((next_state, path + [next_state]))

    return None

def display_steps(path):
    for i, state in enumerate(path):
        missionaries_left, cannibals_left, boat = state
        missionaries_right = 3 - missionaries_left
        cannibals_right = 3 - cannibals_left

        print(f"Step {i + 1}:")
        print(f"Left Bank: {missionaries_left} missionaries, {cannibals_left} cannibals")
        print(f"Right Bank: {missionaries_right} missionaries, {cannibals_right} cannibals")
        print(f"Boat is on the {boat} bank.")
        print()

# Solve the problem using DFS
solution = dfs()
if solution:
    print("Steps to solve the Missionaries and Cannibals problem:")
    display_steps(solution)
else:
    print("No solution found for the Missionaries and Cannibals problem.")