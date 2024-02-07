import string

array_1 = [ 1, 2, 3, 4, 5 ]
array_2 = [ 0, 2, 4, 6, 8 ]
expected = [ 2, 4 ]

def find_intersection(array_1, array_2):
    lookup_table = {}
    intersection = []

    for item in array_1:
        lookup_table[item] = True

    for item in array_2:
        if (item in lookup_table):
            intersection.append(item)

    return intersection

print('TEST 1 - Array Intersection')
print('array_1:', array_1)
print('array_2:', array_2)

intersection = find_intersection(array_1, array_2)

if (intersection == expected):
    print('PASSED!')
else:
    print('FAILED!')
    print('Got: ', intersection)
    print('Expected: ', expected)

test2_input_array = [ 'a', 'b', 'c', 'd', 'c', 'e', 'f' ]
test2_expected = 'c'

print('TEST 2 - Duplicate string lookup')
print('input array:', test2_input_array)

def find_duplicate(input_array):
    lookup_table = {}

    for item in input_array:
        if (item in lookup_table):
            return item
        else:
            lookup_table[item] = True

    return ''

duplicated_value = find_duplicate(test2_input_array)

if (duplicated_value == test2_expected):
    print('PASSED!')
else:
    print('FAILED!')
    print('Got: ', duplicated_value)
    print('Expected: ', test2_expected)

test3_input = 'the quick brown box jumps over a lazy dog'
test3_expected = 'f'

print('TEST 3 - Missing letter')
print('input:', test3_input)

def get_missing_letter(input_string):
    lookup_table = {}
    missing_letter = ''

    for item in input_string:
        lookup_table[item.lower()] = True
    
    for letter in list(string.ascii_lowercase):
        if (letter not in lookup_table):
            missing_letter = letter

    return missing_letter

missing_letter = get_missing_letter(test3_input)

if (missing_letter == test3_expected):
    print('PASSED!')
else:
    print('FAILED!')
    print('Got: ', missing_letter)
    print('Expected: ', test3_expected)

test4_input = 'minimum'
test4_expected = 'n'

print('TEST 4 - Non-duplicated letters')
print('input:', test4_input)

def get_non_duplicated_letter(input_string):
    lookup_table = {}

    for item in input_string:
        if (item in lookup_table):
            lookup_table[item] += 1
        else:
            lookup_table[item] = 1
        
    for letter in lookup_table.keys():
        if (lookup_table[letter] == 1):
            return letter
    
    return ''

unique_letter = get_non_duplicated_letter(test4_input)

if (unique_letter == test4_expected):
    print('PASSED!')
else:
    print('FAILED!')
    print('Got: ', unique_letter)
    print('Expected: ', test4_expected)