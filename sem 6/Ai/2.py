# dictionary
mydic = {
    "name": "sus",
    "age": 69,
    "country": "UK"
}

mydic["country"] = "pizza"

# list
l = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
l.append(10)
l.insert(2, 96)
l.append(101)
print(l[0:5]) 

# stack in python
stack = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
stack.append(11)
stack.pop()
# some people made stack using deque too

# queue in python
from collections import deque
queue = deque(["hello", "there", "python"])
queue.append("here")           
queue.append("c++")
queue.popleft()
queue.popleft()                 
queue.pop                       
print(queue)

# bst in python
class Node:
    # cons to initialise a node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
    
# why outside the class?
def insert(root, data):
    if root is None:
        return Node(data)
    else:
        if root.data < data:
            root.right = insert(root.right, data)
        else:
            root.left = insert(root.left, data)
    return root

def inorder(root):
    if(root == None):
        return
    inorder(root.left)
    print(root.data)
    inorder(root.right)
    
r = Node(50)
r = insert(r, 30)
r = insert(r, 20)
r = insert(r, 40)
r = insert(r, 70)
r = insert(r, 60)
r = insert(r, 80)

inorder(r)

# graph (undir)
n = int(input("Enter total nodes: "))
graph = []

for i in range(0, n):
    print("vertex", i, " is connected to: ")
    choice = 0
    neigh = []
    while choice != -1:
        choice = int(input())
        if choice >= n or choice < 0:
            print("Enter a valid input")
            continue
        elif choice == -1:
            break
        neigh.append(choice)
    graph.append(neigh)

# print graph:
for i in graph:
    print(i)
    # print(i, ": ", end="")
    # for j in i:
    #     print(j, end="")
    # print("")

