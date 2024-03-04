import random

numbers = list(range(0, 100))
#numbers = [ 4, 2, 7, 1, 3 ]

print('Starting list = ', numbers)

#random.shuffle(numbers)

steps = 0
ordered_list = numbers.copy()
ordered_list.sort()

for i in range(0, len(numbers)):
    gap_index = i
    current_value = numbers[i]

    for j in reversed(range(i)):
        steps += 1
        shift_value = numbers[j]

        if (current_value > shift_value or gap_index == 0):
            numbers[gap_index] = current_value
            break
        elif (shift_value > current_value):
            numbers[gap_index] = shift_value
            gap_index -= 1

    numbers[gap_index] = current_value

if (ordered_list == numbers):
    print('THE LIST IS SORTED! Done in ', steps, 'steps')
else:
    print('OH NO! NOT SORTED')
    print(numbers)
