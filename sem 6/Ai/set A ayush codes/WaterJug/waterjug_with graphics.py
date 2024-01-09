import turtle
visited=[]
traversal=[]
sol={}

A=int(input("Enter the max capacity of container A :"))
B=int(input("Enter the max capacity of container B :"))

desired=tuple([int(x) for x in input("Enter the desired states(a b) : ").split(" ")])

def test(a,b):
    new=[]

    if (a,0) not in visited:
        new.append((a,0))

    if (0,b) not in visited:
        new.append((0,b))

    if (A,b) not in visited:
        new.append((A,b))

    if (a,B) not in visited:
        new.append((a,B))

    # a into b
    temp1,temp2=a,b
    if (B-b)>=a:
        temp2=a+b
        temp1=0
    else:
        temp1=a-B+b
        temp2=B
    if (temp1,temp2) not in visited:
        new.append((temp1,temp2))

    # b into a
    temp1,temp2=a,b
    if A-a>=b:
        temp1=a+b
        temp2=0
    else:
        temp1=A
        temp2=b-A+a     
    if (temp1,temp2) not in visited:
        new.append((temp1,temp2))

    new=list(set(new))
    return new


def waterjug():
    start1,start2=[0,0] #[int(x) for x in input("Enter the starting state(a b) : ").split(" ")]
    queue=[(start1,start2)]
    templist=[(start1,start2)]
    visited.append((0,0))

    while len(queue)>0:
        a=queue.pop(0)
        traversal.append(a)

        if a==desired:
            break

        templist=test(a[0],a[1])
        templist=[x for x in templist if x not in visited]
        visited.extend(templist)

        for x in templist:
            sol[x]=a

        queue=queue+templist
    
    if desired in traversal:
      path=[(start1,start2)]
      cur=desired
      while cur!=(start1,start2):
          path.insert(1,cur)
          cur=sol[cur]
      print(path)
      graphics(path)
    else:
      print("No Solution Possible!!!")

    
def graphics(path):
    t = turtle.Turtle()
    t.speed(2000)
    turtle.bgcolor("white")

    base=50
    side=10

    i=0
    x=-100
    y=250
    for i in path:
        a=i[0]
        b=i[1]

        #container A
        t.penup()
        t.goto(x,y)
        t.pendown()
        t.color("black")
        t.right(180)
        t.forward(base)
        t.right(90)
        t.forward(A*side+5)
        t.penup()
        t.right(90)
        t.forward(base)
        t.right(90)
        t.pendown()
        t.forward(A*side+5)


        #container B
        t.penup()
        t.goto(x+200,y)
        t.pendown()
        t.color("black")
        t.right(90)
        t.forward(base)
        t.right(90)
        t.forward(B*side+5)
        t.penup()
        t.right(90)
        t.forward(base)
        t.right(90)
        t.pendown()
        t.forward(B*side+5) #now pointing downwards

        t.penup()
        t.goto(-50,y+10)
        t.pendown()
        t.write(i,font=('consolas',12,'normal'))


        # water in A
        t.penup()
        t.left(90)
        t.goto(x,y)
        t.pendown()
        t.color("blue")
        t.begin_fill()
        t.right(180)
        t.forward(base)
        t.right(90)
        t.forward(a*side)
        t.right(90)
        t.forward(base)
        t.right(90)
        t.forward(a*side)
        t.end_fill()

        # water in B
        t.penup()
        t.goto(x+200,y)
        t.left(90)
        t.pendown()
        t.color("blue")
        t.begin_fill()
        t.right(180)
        t.forward(base)
        t.right(90)
        t.forward(b*side)
        # t.penup()
        t.right(90)
        t.forward(base)
        t.right(90)
        # t.pendown()
        t.forward(b*side)
        t.end_fill()
        t.left(90)

        y-=90

    t.hideturtle()
    turtle.done()

waterjug()