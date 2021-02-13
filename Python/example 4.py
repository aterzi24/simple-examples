first_num   = input("First number: ")
second_num  = input("Second number: ")

try:
    num1 = int(first_num)
    num2 = int(second_num)
    print(num1, "/", num2, "=", num1 / num2)
except ValueError:
    print("Please enter only numbers!")
except ZeroDivisionError:
    print("Cannot divide a numbe by zero!")
