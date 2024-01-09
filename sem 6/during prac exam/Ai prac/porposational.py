# why eval ain't working?

import itertools

# n=int(input("Enter num of varaibles"))
# exp=input() # & | ~ are allowed

n = 2
exp = "(a+b)*(-b)"

truth_table = list(itertools.product([0, 1], repeat=n)) # rem this

# for row in truth_table:
#     print(row)

print("Calc: ")

for row in truth_table:
    newexp = exp
    ind = 0
    replaced = [] # like a visited array
    for c in newexp:
        if c!='(' and c!=')' and c!='+' and c!='-' and c!='*' and c!= ' ' and c not in replaced:        
            newexp=newexp.replace(c, str(row[ind])) # replaced every occurance of c
            ind = ind + 1
            replaced.append(c)
    newexp=newexp.replace('+', '&')
    newexp=newexp.replace('-', '~')
    newexp=newexp.replace('*', '|')
    print(eval(newexp))


