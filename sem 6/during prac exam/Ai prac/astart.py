from queue import PriorityQueue

graph={
    'S':[['A',1],['B',4]],
    'A':[['D',12],['B',2],['C',5],['S',1]],
    'B':[['C',2],['A',2],['S',4]],
    'C':[['A',5],['D',3],['B',2]],
    'D':[['A',12],['C',3]]    
}

heuristic={
    'S':7,
    'A':6,
    'B':2,
    'C':1,
    'D':0
}

def astar(start, dest, heuristic, graph):
    q = PriorityQueue()
    visited=set()
    q.put((heuristic[start], start, 0)) # it will sort wrt 1st. (h+c, node, cost to reach node)
    visited.add(start)

    while q:
        top = q.get() 
        print(top)
        curhc, curn, costp = top

        if curn == dest:
            break

        for i in graph[curn]:
            # print(i)
            inode = i[0]
            icost = i[1]
            if inode not in visited:
                q.put((heuristic[inode] + costp + icost, inode, costp+icost))
                visited.add(inode)

astar('S', 'D',  heuristic, graph)                

