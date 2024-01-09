# list of list is also a good way

# going with dict for now

# foll line not req
#vertices = [x for x in input("Enter the vertices:").split(" ")] # x is a declared variable?

edges = [x.split(',') for x in input("Enter the edges").split(" ")] # exaplination of this line: x.split(',') is a list of 2 elements, x is a list of 2 elements, input is a list of 2 elements

graph = {}

# graph = {
#   '5' : ['3','7'],
#   '3' : ['2', '4'],
#   '7' : ['8'],
#   '2' : [],
#   '4' : ['8'],
#   '8' : []
# }
#a,b a,c b,d b,e c,f c,g e,h e,i h,l h,m h,n i,o i,p g,j g,k k,q

for e in edges:
    if e[0] in graph:
        graph[e[0]].append(e[1]) #value is a list
    else:
        if e[1] == "null":
            graph[e[0]] = []
        else:
            graph[e[0]] = [e[1]]
    if e[1] not in graph: # a,d b,d  need to d too
            graph[e[1]] = []

print(graph)

print("dfs")
visited = set()
def dfs(ver):    
    visited.add(ver)
    print(ver, " ", end='')

    for i in graph[ver]:
        if i not in visited:
            dfs(i)

dfs('a')

print("\nbfs")
from collections import deque
visited = set()
queue = deque()
def bfs(ver):
    queue.append(ver)
    visited.add(ver)

    while queue:
        x = queue[0]
        print(x, " ", end='')
        queue.popleft() # infinite loop coz no bracket-() here
        for i in graph[x]:
            if i not in visited:
                queue.append(i)
                visited.add(i)
          
bfs('a')

# TODO: display tree using network x

# a,b b,c c,d d,g e,f f,g g,t k,j i,j i,h e,h k,g