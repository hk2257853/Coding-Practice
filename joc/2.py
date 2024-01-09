for i in range(3):
    for j in range(2, i - 1, -1): # (a, b, c) - a is the starting point, b is the ending point, c is the step. -1 step means going backwards.
        print(i, ": ",  j)

for i in range(5, 0, -1): # need to mention -1 to go backwards. otherwise doesn't work. prints 5, 4, 3, 2, 1
    print(i, end=" ")

n = 10
l = []
for i in range(10,n+10):
    l.append(i**i) # wow indentation was the error in the ques
# for i in range (10,0,-1): print(l[i]) # out of range error. range is 0 to 9. so 10 is out of range. so start from 10 and go to 1. so 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
# ok might need to c minute. I do brute force here, try to use logic n do
print("\n")
l = [0]
t = (5,)
def add_items(x,y):
    x+= [1,2] # so this is like append. so l = [0, 1, 2]
    y+= (3,4)
add_items(l, t) # so don't need to pass by reference n all there
print(l, end="")
print(t) # why is this (5,) and not (5, 3, 4) ?? because tuples are immutable. so can't add to them. so it's just (5,)
         # damn
# t[0] = 5 # so this is an error. tuples are immutable. so can't change them. so can't do this. so can't do t[0] = 5
# print(t)         

# Q 7 looks wrong

print(l.count(1)) # so this is like how many times does 1 occur in the list l

# other modes are: r - read only, w - write only, a - append, r+ - read and write, w+ - write and read, a+ - append and read
# r+ vs w+: w+ overwrites, r+ doesn't

l[2:4] # print from index 2 to 3 

word = 'Python'
# word[2] = 'n'
print(word) # string are immutable lol

'''
Which of the following is not a method in string?
 lower()
 upper()
 isalpha()
 insert()

 ans: insert() - this was like aptitude, strings aren't mutable!
'''

s = 'I am amazed'
s.replace('a', 'z') # won't modify the original string, but return a modified that can be stored somewhere
x = s.replace('a', 'z')
print(s, "   ", x)

print(int(16**0.5))

# composite means non primes
# 1 is neither prime nor composite.

# no switch in python lol (hai kya yaha) 