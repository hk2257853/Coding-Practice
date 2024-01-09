def isvalid(state):
    m1,c1,b,m2,c2 = state
    return 0<=m1<=3 and 0<=m2<=3 and 0<=c1<=3 and 0<=c2<=3 and (m1==0 or m1>=c1) and (m2==0 or m2>=c2) 

def nextstates(states):
    m1,c1,b,m2,c2 = states
    next_state=[]
    moves = [(1,0),(2,0),(0,2),(0,1),(1,1)]

    for dm,dc in moves:
        if b==1:
            newstate=(m1-dm,c1-dc,0,m2+dm,c2+dc)
        else:
            newstate=(m1+dm,c1+dc,1,m2-dm,c2-dc)

        if isvalid(newstate):   # this is inside the for loop
            next_state.append(newstate)
    
    return next_state

def dfs(start_state):
    stack=[(start_state,[start_state])] # stack under sq bracket

    while stack:
        current_state,path = stack.pop()

        if current_state == (0,0,0,3,3):
            return path

        for nextstate in nextstates(current_state):
           if nextstate not in path:
               stack.append((nextstate,path+[nextstate]))  #double bracket for append

    return None 



miss=int(input("enter m "))
canni=int(input("enter c "))

state=(miss,canni,1,0,0)
soln=dfs(state)

if soln:
    print("left     right")
    for path in soln:
        m1,c1,b,m2,c2=path #path
        print("(",m1, c1,")","(",m2, c2,")")
else:
    print("no soln ")