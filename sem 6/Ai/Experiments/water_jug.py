from collections import deque

def BFS(a, b, target):
    visited = {}
    isSolvable = False
    path = []

    q = deque()

    q.append((0, 0, None))  # (Jug1, Jug2, Parent)

    while len(q) > 0:
        u = q.popleft()
        if (u[0], u[1]) in visited:
            continue
        if u[0] > a or u[1] > b or u[0] < 0 or u[1] < 0:
            continue

        path.append([u[0], u[1]])
        visited[(u[0], u[1])] = 1

        if u[0] == target or u[1] == target:
            isSolvable = True

            pathLength = len(path)
            for i in range(pathLength):
                print("(", path[i][0], ",", path[i][1], ")")
            break

        q.append((u[0], b))  
        q.append((a, u[1]))  

        for fill in range(max(a, b) + 1):
            c = u[0] + fill
            d = u[1] - fill

            if c == a or (d == 0 and d >= 0):
                q.append((c, d, (u[0], u[1])))  

            c = u[0] - fill
            d = u[1] + fill

            if (c == 0 and c >= 0) or d == b:
                q.append((c, d, (u[0], u[1]))) 

        q.append((u[0], 0)) 
        q.append((0, u[1])) 

    if not isSolvable:
        print("No solution")

if __name__ == '__main__':
    Jug1, Jug2, target = int(input("Capacity of JUG1: ")), int(input("Capacity of JUG2: ")), int(
        input("Enter Goal: "))
    print("solution:")
    BFS(Jug1, Jug2, target)
