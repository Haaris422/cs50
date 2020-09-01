from cs50 import get_float

while True:
    change = get_float("Enter the change owed: ")
    if (change > 0):
        break
ci = round(change * 100)
coins = 0
AC = {25, 10, 5, 1}
for i in AC:
    coins += ci // i
    ci %= i
    
print(f"Least number of coins to be dispensed: {coins}")    