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