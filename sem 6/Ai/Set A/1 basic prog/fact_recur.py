n = int(input())

def fact(n):
    # base
    if(n == 0 or n == 1):
        return 1
    return n * fact(n - 1)

print(fact(n))
