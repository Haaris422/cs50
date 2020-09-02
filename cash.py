from cs50 import get_float

while True:
    change = get_float("Enter the change owed: ")
    if (change > 0):
        break  # To ensure the user enters a +(ive) float.
LC = round(change * 100)  # eg -> .41 becomes 41. LC = Loose Change.
coins = 0  # Sets the coins needed to be dispensed initially to 0.
AC = {25, 10, 5, 1}  # AC = Available Coins. 
for i in AC:
    coins += LC // i  # eg = 41/25 ; coins = 1 & r = 16.
    LC %= i  # r is set as LC's new value.
    # repeats till r = 0.
print(f"Least number of coins to be dispensed: {coins}")    