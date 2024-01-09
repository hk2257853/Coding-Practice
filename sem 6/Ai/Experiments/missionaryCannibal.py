# function to validate states
# check overflow and underflow
# check if missionary > cannibals
def is_valid(state):
    m1, c1, b, m2, c2 = state
    return 0<=m1<=3 and 0<=c1<=3 and 0<=m2<=3 and 0<=c2<=3 and (m1==0 or m1>=c1) and (m2==0 or m2>=c2)

def generate_next_states(state):
    m1, c1, b, m2, c2 = state
    moves = [(1, 0), (2, 0), (0, 1), (0, 2), (1, 1)]
    next_states = []

    for dm, dc in moves:
        if b==1:
            # boat in on left side
            new_state = (m1 - dm, c1 - dc, 0, m2 + dm, c2 + dc)
        else:
            # boat in on right side
            new_state = (m1 + dm, c1 + dc, 1, m2 - dm, c2 - dc)

        if is_valid(new_state):
            next_states.append(new_state)

    return next_states

def dfs(start_state):
    stack = [(start_state, [start_state])]

    while len(stack)!=0:
        current_state, path = stack.pop()
        if current_state == (0, 0, 0, 3, 3):
            return path

        for next_state in generate_next_states(current_state):
            if next_state not in path:
                stack.append((next_state, path+[next_state]))
    return None

missionaries = int(input("Enter The number of Missionaries "))
cannibals = int(input("Enter The number of Cannibals "))

start_state = (missionaries, cannibals, 1, 0, 0)
solution = dfs(start_state)
if solution:
    print("Solution paths - ")
    print ("Left Side   Right side ")
    for state in solution:
        m1, c1, b, m2, c2 = state
        print("( ",m1," ",c1," ) ( ", m2," ",c2," )")
else:
    print("No Solution")