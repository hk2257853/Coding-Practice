from queue import PriorityQueue


def bestfs(start_node, target):
    visited = []
    pq = PriorityQueue()
    count = -1
    pq.put((0, start_node, 0))

    while pq.empty() == False and count != 10:
        current_node = pq.get()[1]
        count += 1
        display(current_node)
        if current_node not in visited:
            visited.append(current_node)

        if current_node == target:
            print("Goal State reached!!")
            print("Moves=", count)
            return
        child_states = generate_child_states(current_node)
        for child_state in child_states:
            if child_state not in visited:
                distance = manhattan_distance(child_state, target)
                pq.put((distance+count, child_state, current_node))
    print("Goal state not reached.")


def generate_child_states(parent):
    child_states = []
    empty_tile_pos = find_position(parent, 0)
    moves = [(0, -1), (0, 1), (-1, 0), (1, 0)]
    for move in moves:
        new_pos = (empty_tile_pos[0] + move[0], empty_tile_pos[1] + move[1])
        if is_valid_move(new_pos):
            child_state = swap_tiles(parent, empty_tile_pos, new_pos)
            child_states.append(child_state)
    return child_states


def is_valid_move(pos):
    x, y = pos
    return x >= 0 and x < 3 and y >= 0 and y < 3


def swap_tiles(state, pos1, pos2):
    new_state = [row[:] for row in state]  # copy state to new state
    x1, y1 = pos1
    x2, y2 = pos2
    new_state[x1][y1], new_state[x2][y2] = new_state[x2][y2], new_state[x1][y1]
    return new_state


def manhattan_distance(grid1, grid2):
    distance = 0
    for i in range(len(grid1)):
        for j in range(len(grid1[i])):
            value = grid1[i][j]
            if value != 0:
                x, y = find_position(grid2, value)
                distance += abs(i - x) + abs(j - y)
    return distance


def find_position(grid, value):
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == value:
                return i, j


def display(grid):
    c = 0
    for row in grid:
        c += 1
        print(" | ".join(str(cell) for cell in row))
        if c != 3:
            print("----------")
    print()
    print()


# initial = [[1, 2, 3],
#            [4, 0, 6],
#            [7, 5, 8]]

final = [[1, 2, 3],
         [4, 5, 6],
         [7, 8, 0]]


def get_user_input():
    initial = []
    print("Enter the values for the initial state:")
    for i in range(3):
        row = []
        for j in range(3):
            value = int(input(f"Enter value at position ({i+1}, {j+1}): "))
            row.append(value)
        initial.append(row)
    return initial


initial = get_user_input()
bestfs(initial, final)
