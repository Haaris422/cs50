from sys import argv, exit
import csv

if len(argv) != 3:
    print("Error: There should be exactly 2 CLAs")  # Shows error if incorrecct ammount of CLAs are entered.
    exit(1)
with open(argv[1], 'r') as csvfile:
    db = csv.reader(csvfile)  # Opens & reads the csv file. (db = databases)
    D = [row for row in db]  # Makes a list of every row in the csv. 
with open(argv[2], 'r') as textfile: 
    seq = textfile.read()  # Reads the text file.
counter = []  # Set to store the largest repeating substring.
for i in range(1, len(D[0])):
    counts = 1  # Set as 1 to avoid getting 0*R in line 16.
    R = D[0][i]  # Stores every string. 
    while R*counts in seq:  # Eg = If R*1 != seq, it goes to R*2 untill it satisys the condition.
        counts += 1
    counter.append(str(counts - 1))  # Reduce 1 as counts is initialised at 1.
for j in range(1, len(D)):
    if D[j][1:len(D[0])] == counter:  # FOr only comparing numbers.
        print(D[j][0])  # to print corresponding name.
        exit(0)
print("No Match")        