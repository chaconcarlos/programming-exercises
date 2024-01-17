numbers_list = list(range(0, 1000000))

print('The sum of all numbers is ', sum(numbers_list))

odd_numbers_list = list(range(1, 20, 2))

print(odd_numbers_list)

multiples_list = list(range(3, 30, 3))

print(multiples_list)

for number_multiple in multiples_list:
    if number_multiple % 3 == 0:
        print(str(number_multiple) + ' is a multiple of 3')

for value in range(1, 11):
    print('The cube of ' + str(value) + ' is ' + str(value ** 3))

cubes_list = [ value ** 3 for value in range(1, 11) ]
print(cubes_list)