# 153: 1*1*1 + 5*5*5 + 3*3*3 = 153 ams

n = int(input())
temp = n

sum = 0

while(n > 0):
    x = n % 10
    sum = sum + x ** 3
    n = n // 10

print(sum)
if(sum == temp):
    print(temp, "is an Amstrong num")
else:
    print(temp, "is not an Amstrong num")
