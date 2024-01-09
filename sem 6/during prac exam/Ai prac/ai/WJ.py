from collections import deque

def nextstates(state,capacities):
    a,b = state
    ca,cb = capacities
    next_moves = []

    next_moves.append((a,cb))
    next_moves.append((ca,b))
    next_moves.append((0,b))
    next_moves.append((a,0))

    amt=min(a,cb-b)
    next_moves.append((a-amt,b+amt))

    amt=min(ca-a,b)
    next_moves.append((a+amt,b-amt))

    return next_moves

def bfs(start,capacities,goal):
    path = []
    q = deque()
    q.append((start,None))

    visited = set()
    visited.add(start)

    while q:
        current_state,parent = q.popleft()

        if current_state == goal:
            while parent is not None:
                path.insert(0,current_state)#.insert not append   currstate not start   singel bracket
                current_state,parent=parent
            path.insert(0,current_state)

            for state in path:
                print(state[0]," , ",state[1])
            return True #return true at the end of while loop

        for nexstate in nextstates(current_state,capacities):
            if nexstate not in visited:
                q.append((nexstate,(current_state,parent)))
                visited.add(nexstate)

    return False

start=tuple(map(int,input("enter 0 0 : ").split()))
capacities=tuple(map(int,input("enter 4 3 : ").split()))
goal=tuple(map(int,input("enter 2 0 : ").split()))

found_sol=bfs(start,capacities,goal)

if found_sol:
    print("found ")
else:
    print("not found ")