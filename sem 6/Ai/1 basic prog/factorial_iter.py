# TODO: till what input it works
print("Enter -1 to exit")

n = 1
while(n != -1):
    fact = 1
    n = int(input())
    for i in range (1, n + 1):
        fact = fact * i
    if(n != -1):
        print("The factorial is: ", fact);    
