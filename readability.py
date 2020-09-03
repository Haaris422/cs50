from cs50 import get_string

text = get_string ("Text: ").strip()
words = 0
letters = 0
sentences = 0
for i in range(len(text)):
    words = len(text.split())
    if text[i].isalpha() == True:
        letters += 1
    elif text[i] in ['?', '.', '!']:
        sentences += 1
L = (letters/words * 100)
S = (sentences/words *100)
I = round(0.0588 * L - 0.296 * S - 15.8)
if I < 1:
    print("Before Grade 1")
elif I >= 16:
    print ("Grade 16+")
else:
    print (f"Grade {I}")
    