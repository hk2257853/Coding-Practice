def generate_truth_table(num_inputs, operator):
    inputs = []
    for i in range(num_inputs):
        inputs.append('x{}'.format(i+1))
    print(' '.join(inputs) + '   ' + operator)
    
    num_rows = 2**num_inputs
    for i in range(num_rows):
        row = []
        for j in range(num_inputs):
            row.append(int(bool(i & (1 << (num_inputs - 1 - j)))))
        if operator == '&':
            result = int(all(row))
        elif operator == '|':
            result = int(any(row))
        elif operator == '~':
            result = int(not row[0])
        row_str = ' '.join(str(val) for val in row)
        print(row_str + '    ' + str(result))

num_inputs = 3
operator = '|'
generate_truth_table(num_inputs, operator)
