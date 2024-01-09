import itertools

def find_inputs(expression):
    inputs = []
    for char in expression:
        if char not in ['+', '*', '-', '(', ')', ' '] and char not in inputs:
            inputs.append(char)
    return inputs

def evaluate_expression(expression, row):
    input_no = 0
    replaced = []
    for char in expression:
        if char not in ['+', '*', '-', '(', ')', ' '] and char not in replaced:
            expression = expression.replace(char, str(row[input_no]))
            input_no += 1
            replaced.append(char)
    expression = expression.replace('+', '&')
    expression = expression.replace('*', '|')
    expression = expression.replace('-', '~')
    result = eval(expression)
    return result

def compute_results(truth_table, expression):
    outputs = []
    for row in truth_table:
        outputs.append(evaluate_expression(expression, row))
    return outputs

n = int(input('Enter the number of inputs: '))
print('Rules:')
print('1) To enter "AND", use "+"')
print('2) To enter "OR", use "*"')
print('3) To enter "NOT", use "-"')
logical_expression = input('Enter the logical expression: ')

truth_table = list(itertools.product([0, 1], repeat=n))
table_outputs = compute_results(truth_table, logical_expression)

print('') 
print('Truth Table:') 
print('')
for c in find_inputs(logical_expression): 
    print(c,end=' ')
print('Output')

for i in range(len(truth_table)): 
    for val in truth_table[i]:
        print(val,end=' ') 
    print(' ',table_outputs[i])
print('')

if table_outputs.count(1)>=1:
    print('The entered propositional logic expression is Satisfiable') 
else:
    print('The entered propositional logic expression is Not Satisfiable')
