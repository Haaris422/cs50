from sys import argv, exit
import csv
import cs50

def F_N(full_name):
    names = row["name"].split()
    return names if len(names) >= 3 else [names[0], None, names[1]] 
    
if len(argv) != 2:
    print("Usaage error: only input 1 argument")
    exit(1)

db = cs50.SQL("sqlite:///students.db")

with open(argv[1], 'r') as csvf:
    D = csv.DictReader(csvf, delimiter = ",")
    

    for row in D:
       
        names = F_N(row["name"])
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", names[0], names[1], names[2], row["house"], row["birth"])
        house = row["birth"]
        birth = row["birth"]
        