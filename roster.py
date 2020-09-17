from sys import argv, exit
import cs50

if len(argv) != 2:
    print("Usage Error: incorrect number of arguments")
    exit(1)
db = cs50.SQL("sqlite:///students.db")
rows = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", argv[1])
for row in rows:
    first, middle, last, birth = row["first"], row["middle"], row["last"], row["birth"]
    print(f"{first} {middle + ' ' if middle else ''} {last}, born {birth}")
    