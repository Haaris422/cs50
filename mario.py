from cs50 import get_int  # To use get_int.
n = 0
while True:
    n = get_int ("Enter the desired height of your pyramid: ")
    if (n > 0 and n < 9):
        break  # To make sure the user enters valid no.
for i in range(n):
    for h in range(n - i - 1):  # To decrease range for each succesive row.
        print(" ", end="")
    for w in range(i + 1):  # To print an increasing no. of # for each succesive row.
        print("#", end="")
    print()  # New Line