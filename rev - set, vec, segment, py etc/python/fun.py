def add(a, b):
    print(a+b)

add(1, 2)
add(1, 8)

def factorial(n):
    if n == 1:
        return 1
    return n * factorial(n-1)