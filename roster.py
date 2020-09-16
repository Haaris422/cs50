from sys import argv, exit
import csv
import cs50

if len(argv) != 2:
    print("Usaage error: only input 1 argument")
    exit(1)
db = cs50.SQL("sqlite:///students.db") 
table = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", (argv[1]))
for row in table:
    first, middle, last, birth = row["first"], row["middle"], row["last"], row["birth"]
    print(f"{first} {middle + ' ' if middle else ''} {last} born {birth}")