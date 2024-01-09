from queue import PriorityQueue

def best_fs(start, goal):
	visited = []
	pq = PriorityQueue() # default: min
	pq.put((0,start))    # (priority,node)

	visited.append(start);
	
	while pq.empty() == False:
		x = pq.get()[1]   #to get the node
		
	    # Displaying the path having lowest cost
		print(x, end=" ")
		

		if x == goal:   #if goal is found
			return

		for y, cost in graph[x]:
			if y not in visited:
				visited.append(y);
				pq.put((cost,y))
	


def addedge(x, y, cost):
	graph[x].append((y, cost))
	graph[y].append((x, cost))





graph = [[] for i in range(15)] #[[], [], [], [], [], [], [], [], [], []]

#(x,y,cost);
addedge(0, 1, 3)
addedge(0, 2, 6)
addedge(0, 3, 5)
addedge(1, 4, 9)
addedge(1, 5, 8)
addedge(2, 6, 12)
addedge(2, 7, 14)
addedge(3, 8, 7)
addedge(8, 9, 5)
addedge(8, 10, 6)
addedge(9, 11, 1)
addedge(9, 12, 10)
addedge(9, 13, 2)



start = 0
goal = 13
best_fs(start, goal)


