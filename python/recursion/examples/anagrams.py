import math

def get_anagrams(input): 
    if (len(input) == 1):
        return [ input[0] ]
    
    previous_anagrams = get_anagrams(input[1:])
    result = []

    for anagram in previous_anagrams:
        for i in range(len(anagram) + 1):
            result.append(anagram[:i] + input[0] + anagram[i:])
    
    return result

input = "abcdefghij"
anagrams = get_anagrams(input)
print('got ', len(anagrams), ' anagrams')
print('expected ', math.factorial(len(input)), ' anagrams')
#print(anagrams)

def total_chars(strings):
    if (len(strings) == 0):
        return 0

    return len(strings[0]) + total_chars(strings[1:len(strings)])

print('total_chars: ', total_chars([ "ab", "c", "def", "ghij" ]))

input = list(range(0, 10))

def get_even_numbers(input):
    if len(input) == 0:
        return []

    if input[0] % 2 == 0:
        return [ input[0] ] + get_even_numbers(input[1:])
    else:
        return get_even_numbers(input[1:])

print('get_even_numbers: ', get_even_numbers(input))

def get_triangular(index):
    if (index == 1):
        return 1
    
    return index + get_triangular(index - 1)

print(get_triangular(200))

def get_index_of_x(input, current_index = 0):
    if (input[0] == 'x'):
        return 0

    return get_index_of_x(input[1:]) + 1

print('get_index_of_x: ', get_index_of_x('abcdefghijklmnopqrstuvwxyz'))

def get_shortest_paths_number(rows, columns, current_x = 0, current_y = 0):
    if (current_x == columns - 1 and current_y == rows - 1):
        return 1
    elif (current_x >= columns or current_y >= rows):
        return 0
   
    return get_shortest_paths_number(rows, columns, current_x + 1, current_y) + get_shortest_paths_number(rows, columns, current_x, current_y + 1)

print('get_shortest_paths_number: ', get_shortest_paths_number(3, 2))

def get_shortest_paths_number2(rows, columns):
    if rows == 1 or columns == 1:
        return 1
   
    return get_shortest_paths_number2(rows - 1, columns) + get_shortest_paths_number2(rows, columns - 1)

print('get_shortest_paths_number2: ', get_shortest_paths_number2(3, 2))