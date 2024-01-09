import turtle

# boat capacity: 2
traversal=[]
visited=[]
sol={}
def newstates(x):
  m=x[0]
  c=x[1]
  b=x[2]

  templist=[]

  if b==1: # right
    templist.extend([(m-2,c,0),(m,c-2,0),(m-1,c-1,0),(m-1,c,0),(m,c-1,0)]) # all possibilities (we aren't simulating boat here, just getting the possibilities).
    templist=[x for x in templist if x[0]>=0 and x[1]>=0] # remove unwanted cases
    # ques: in very few cases both I'll put on right (it will be like ending cases...)
  else:
    templist.extend([(m+2,c,1),(m,c+2,1),(m+1,c+1,1),(m+1,c,1),(m,c+1,1)]) 
    templist=[x for x in templist if x[0]<=3 and x[1]<=3]

  templist=[x for x in templist if x not in visited]

  return templist


def isgood(x):
  m=x[0]
  c=x[1]

  if m==3 or m==0 or m==c:
    return 1
  else:
    return 0

def mnc():
  start=(3,3,1)
  desired=(0,0,0)
  
  visited.append(start)
  stack=[start]
  traversal=[]
  
  while len(stack)>0:
    a=stack.pop(0)
    traversal.append(a)

    if a==desired:
      break

    templist=newstates(a)
    templist=[x for x in templist if isgood(x)]

    for x in templist:
      sol[x]=a

    visited.extend(templist)
    stack=templist+stack    # inserting at the begining

  cur=desired
  path=[start]
  while cur!=start:
    path.insert(1,cur)
    cur=sol[cur]
  
  print("Path : ")
  for x in path:
    print(x,end="\n" if x==desired else " -> ")
  graphics(path)

def graphics(path):
  t=turtle.Turtle()
  turtle.speed(300000)
  turtle.bgcolor("green")

  x=-100
  y=250

  t.color("light blue")
  t.penup()
  t.goto(-80,350)
  t.pendown()
  t.begin_fill()
  t.goto(-80,-350)

  t.penup()
  t.goto(80,-350)
  t.pendown()
  t.goto(80,350)
  t.end_fill()

  for i in path:
    t.penup()
    t.color("brown")
    if i[2]==1:
      x1=-100
    else:
      x1=60
    t.goto(x1,y)
    t.pendown()
    t.begin_fill()
    t.goto(x1+40,y)
    t.goto(x1+60,y+20)
    t.goto(x1-10,y+20)
    t.end_fill()
    t.color("black")

    x1,y1=x-150,y
    
    t.penup()
    t.goto(x1-100,y)
    t.pendown()

    t.write(i,font=('consolas',14,'bold'))

    t.penup()
    t.goto(x1,y1)
    t.pendown()

    # text=str(i[0])+"M"+str(i[1])+"C"
    text=i[0]*"\U0001F607"+i[1]*"\U0001F47A"
    t.write(text,font=('consolas',14,'bold'))

    t.penup()
    t.goto(-x1-40,y1)
    t.pendown()

    # text=str(3-i[0])+"M  "+str(3-i[1])+"C"
    text=(3-i[0])*"\U0001F607"+(3-i[1])*"\U0001F47A"
    t.write(text,font=('consolas',14,'bold'))

    y=y-50
  t.hideturtle()
    
  turtle.done()

mnc()