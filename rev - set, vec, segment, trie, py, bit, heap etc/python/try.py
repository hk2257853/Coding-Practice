import fun
x=[1 , 2, 3, 4]

i = 0
for i in x:
    print(i, end=" ")

i = 0
while i < len(x):
    print(x[i], end=" ")
    i += 1

print("hi")


# x = int(input("Enter a number: "))
# y = int(input("Enter a number: "))
# print(x+y)

x = int(input("Enter a number for fact: "))
print(fun.factorial(x))

fun.add(1, 2)
