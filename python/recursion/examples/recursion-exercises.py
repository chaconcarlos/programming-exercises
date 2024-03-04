def display_numbers(top_value):
    print(top_value)

    if (top_value > 0):
        display_numbers(top_value - 1)

display_numbers(10)

def factorial(value):
    if (value == 1):
        return value
    else:
        return value * factorial(value - 1)

print(factorial(51))

def print_numbers(low, high):
    if (low >= high):
        print(high)
    else:
        print(low)
        print_numbers(low + 2, high)

print_numbers(0, 1000)

def recursive_array_sum(values):
    if (len(values) == 1):
        return values[0]
    return values[0] + sum(values[1:]);

test_input = [ 1, 2, 3, 4, 5 ]
test_expected = sum(test_input)

print('TEST - Recursive array sum')
print('input:', test_input)
print('expected: ', test_expected)

result = recursive_array_sum(test_input)

if (result == test_expected):
    print('PASSED!')
else:
    print('FAILED!')
    print('Got: ', result)
    print('Expected: ', test_expected)

test_input = 'abcde'
test_expected = test_input[::-1]

def recursive_reverse_string(input_string):
    if (len(input_string) == 1):
        return input_string[0]

    return recursive_reverse_string(input_string[1:]) + input_string[0]

print('TEST - Recursive reverse string')
print('input:', test_input)
print('expected: ', test_expected)

result = recursive_reverse_string(test_input)

if (result == test_expected):
    print('PASSED!')
else:
    print('FAILED!')
    print('Got: ', result)
    print('Expected: ', test_expected)

def count_x(input_string):
    count = 1 if input_string[0] == 'x' else 0

    if (len(input_string) == 1):
        return count
    
    return count + count_x(input_string[1:])

test_input = 'axbxcxd'
test_expected = 3

print('TEST - Recursive count x')
print('input:', test_input)
print('expected: ', test_expected)

result = count_x(test_input)

if (result == test_expected):
    print('PASSED!')
else:
    print('FAILED!')
    print('Got: ', result)
    print('Expected: ', test_expected)