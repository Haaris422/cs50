import cs50
from sys import argv, exit
import csv

def dividedN(N):
    names = N.split()
    return names if len(names) >= 3 else [names[0], None, names[1]]

if len(argv) != 2:
    print("Usage Error: incorrect number of arguments")
    exit(1)
db = cs50.SQL("sqlite:///students.db")
with open (argv[1], 'r') as csvf:
    D = csv.DictReader(csvf)
    for row in D:
        names = dividedN(row["name"])
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?,?,?,?,?)", names[0], names[1], names[2], row["house"], row["birth"])
     