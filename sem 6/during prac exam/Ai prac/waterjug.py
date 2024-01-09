from collections import deque

ca = 4
cb = 2

def possibilities(state):
    a, b = state

    possib = []
    possib.append((0, b))
    possib.append((a, 0))
    possib.append((ca, b))
    possib.append((a, cb))

    tr = min(cb-b, a)
    possib.append((a-tr, b+tr))
    tl = min(ca-a, b)
    possib.append((a+tl, b-tl))

    return possib

def bfs(state):
    q = deque()
    q.append(state)
    visited = set()
    visited.add(tuple(state)) # can add only tuple to deque

    while q:
        temp = q.popleft()
        print(temp)

        if temp == (2,2):
            break

        for i in possibilities(temp):
            if i not in visited:
                q.append(i)
                visited.add(i)

bfs((0, 0))

# is this code ok? (the output part especially)