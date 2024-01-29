import random

def is_ordered(numbers): 
    for index in range(1, len(numbers)):
        if (numbers[index] < numbers[index - 1]):
            return False
    return True

numbers = list(range(0, 3))
permutations = 0

random.shuffle(numbers)

while (is_ordered(numbers) == False):
    permutations = permutations + 1
    random.shuffle(numbers)
    print(numbers)

print('permutations: ', permutations)