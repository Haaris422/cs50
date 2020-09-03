from cs50 import get_string

text = get_string("Text: ").strip()  # Asks for the usrers input.
words = 0  # number of words.
letters = 0  # Nnumber of letters.
sentences = 0  # Number of sentences.
for i in range(len(text)):
    words = len(text.split())  # Counts the no. of words in the text.
    if text[i].isalpha() == True:  # Countss the no. of letters in the text.
        letters += 1
    elif text[i] in ['?', '.', '!']:  # Countss the no. of sentences in the text.
        sentences += 1
L = (letters/words * 100)
S = (sentences/words * 100)
I = round(0.0588 * L - 0.296 * S - 15.8)  # Coleman-Liau formula
if I < 1:
    print("Before Grade 1")
elif I >= 16:
    print("Grade 16+")  # I = Index/Grade Level
else:
    print(f"Grade {I}")
    