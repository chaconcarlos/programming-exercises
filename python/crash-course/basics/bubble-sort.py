import random

numbers = list(range(0, 100))

random.shuffle(numbers)

unsorted_end_index = len(numbers) - 1
has_changes = True
steps = 0

print(numbers)

while (has_changes):
  has_changes = False
  steps = steps + 1

  for current_index in range(unsorted_end_index):
    pointer_left = numbers[current_index]
    pointer_right = numbers[current_index + 1]

    if (pointer_left > pointer_right):
       numbers[current_index] = pointer_right
       numbers[current_index + 1] = pointer_left
       has_changes = True
  
  unsorted_end_index -= 1

print('Done!!!!!!!!!')
print('Number of steps:', steps)
print(numbers)