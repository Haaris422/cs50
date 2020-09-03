from cs50 import get_string
import re
text = get_string ("Text: ")
words = 0
letters = 0
sentences = 0
if text.isalnum() == True:
    words = 1
for i in range(len(text)):
    if text[i].isalpha() == True:
        letters += 1
    elif (i == 0 and text[i] != ' ') or (i != len(text) - 1 and text[i] == ' ' and text [i+1] != ' '):
        words += 1
    elif text[i] in ['?', '.', '!']:
        sentences += 1
print(f"letter : {letters}, words = {words}, sentences  = {sentences }")
L = (letters/words * 100)
S = (sentences/words *100)
I = round(float(0.0588 * L - 0.296 * S - 15.8))
if I < 1:
    print("Before Grade 1")
elif I >= 16:
    print ("Grade 16 and +")
else:
    print (f"Grade {I}")
    