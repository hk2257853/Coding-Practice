# totally hardcoded code

def isvalid(state):
    m1, c1, b, m2, c2 = state
    return 0<=m1<=3 and 0<=m2<=3 and 0<=c1<=3 and 0<=c2<=3 and (m1 >= c1 or m1 == 0) and (m2 >= c2 or m2 == 0)
# conditions at end: 2, 2 is ok (>=). 0, 2 is also ok (here c > m)
# m can't be -ve, m can't be > 3 (boundaries)

def nextstates(state):
    m1, c1, b, m2, c2 = state
    possiblestates=[]

    moves = [(1, 0), (2, 0), (0, 2), (0, 1), (1, 1)] # at a time 2 people on boat?

    for dm, dc in moves:
        if b == 1: # left side (remove from left and put on right)
            newstate=(m1-dm, c1-dc, 0, m2+dm, c2+dc)
        if b == 0:
            newstate=(m1+dm, c1+dc, 1, m2-dm, c2-dc)

        if isvalid(newstate):
            possiblestates.append(newstate)
        
    return possiblestates

def dfs(start):
    stack = [(start, [start])] # [start] is the path

    while start:
        current_state, path = stack.pop()

        if current_state == (0, 0, 0, 3, 3): # why 3, 3 ?
            return path
        
        for nextstate in nextstates(current_state):
            if nextstate not in path:
                stack.append((nextstate, path+[nextstate]))

m = 3
c = 3

initialstate = (m, c, 1, 0, 0) # ml, cl, current loc (left), mr, cr

soln = dfs(initialstate)

print(soln)

