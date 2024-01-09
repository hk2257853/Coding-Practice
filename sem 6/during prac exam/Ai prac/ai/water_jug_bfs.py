from collections import deque

def bfs_util(jug1_capacity, jug2_capacity, target, visited, queue, path):
    while queue:
        jug1, jug2, curr_path = queue.popleft()

        if jug1 == target or jug2 == target:
            path.extend(curr_path)
            path.append((jug1, jug2))
            return True

        visited[jug1][jug2] = True

        # Fill jug 1
        if jug1 < jug1_capacity and not visited[jug1_capacity][jug2]:
            new_path = curr_path + [(jug1_capacity, jug2)]
            queue.append((jug1_capacity, jug2, new_path))
            visited[jug1_capacity][jug2] = True

        # Fill jug 2
        if jug2 < jug2_capacity and not visited[jug1][jug2_capacity]:
            new_path = curr_path + [(jug1, jug2_capacity)]
            queue.append((jug1, jug2_capacity, new_path))
            visited[jug1][jug2_capacity] = True

        # Empty jug 1
        if jug1 > 0 and not visited[0][jug2]:
            new_path = curr_path + [(0, jug2)]
            queue.append((0, jug2, new_path))
            visited[0][jug2] = True

        # Empty jug 2
        if jug2 > 0 and not visited[jug1][0]:
            new_path = curr_path + [(jug1, 0)]
            queue.append((jug1, 0, new_path))
            visited[jug1][0] = True

        # Pour jug 1 to jug 2
        if jug1 > 0 and jug2 < jug2_capacity:
            amount = min(jug1, jug2_capacity - jug2)
            if not visited[jug1 - amount][jug2 + amount]:
                new_path = curr_path + [(jug1 - amount, jug2 + amount)]
                queue.append((jug1 - amount, jug2 + amount, new_path))
                visited[jug1 - amount][jug2 + amount] = True

        # Pour jug 2 to jug 1
        if jug2 > 0 and jug1 < jug1_capacity:
            amount = min(jug2, jug1_capacity - jug1)
            if not visited[jug1 + amount][jug2 - amount]:
                new_path = curr_path + [(jug1 + amount, jug2 - amount)]
                queue.append((jug1 + amount, jug2 - amount, new_path))
                visited[jug1 + amount][jug2 - amount] = True

    return False


def water_jug_bfs(jug1_capacity, jug2_capacity, target):
    visited = [[False] * (jug2_capacity + 1) for _ in range(jug1_capacity + 1)]
    queue = deque()
    path = []

    queue.append((0, 0, []))
    visited[0][0] = True

    if bfs_util(jug1_capacity, jug2_capacity, target, visited, queue, path):
        print("Solution exists:")
        for state in path:
            print(state[0], state[1])
    else:
        print("No solution exists")

# -------main-----------------
# Test the water_jug_bfs function
jug1_capacity = int(input("Enter capacity of jug 1: "))
jug2_capacity = int(input("Enter capacity of jug 2: "))
target = int(input("Enter target value to be measured: "))

(water_jug_bfs(jug1_capacity, jug2_capacity, target))
