import random

numbers = list(range(0, 100))

random.shuffle(numbers)

ordered_list = []

for item in numbers:
    if (len(ordered_list) == 0):
        ordered_list.append(item)
    else:
        for index in range(0, len(ordered_list) + 1):
            if (index >= len(ordered_list)):
                ordered_list.append(item)
            elif (item < ordered_list[index]):
                ordered_list.insert(index, item)
                break

print(ordered_list)