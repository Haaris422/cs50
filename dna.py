from sys import argv, exit
import csv

if len(argv) != 3 :
    print("Error: There should be exactly 2 CLAs")
    exit(1)
with open(argv[1], 'r') as csvfile:
    db = csv.reader(csvfile)
    D = [row for row in db]
with open(argv[2], 'r') as textfile:
    seq = textfile.read()
counter = []
for i in range(1, len(D[0])):
    counts = 1
    R = D[0][i]
    while R*counts in seq:
        counts += 1
    counter.append(str(counts - 1))
for j in range(1, len(D)):
    if D[j][1:len(D[0])] == counter:
        print(D[j][0])
        exit(0)
print("No Match")        