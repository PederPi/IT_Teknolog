import random

def makeKey(string):
    alphabetString = 'abcdefghijklmnopqrstuvwxyz'
    randomizedalphabetString = ''.join(random.sample(alphabetString, len(alphabetString)))

    sanitizedString = string.lower()
    sanitizedString = sanitizedString.replace(" ", "")
    sanitizedString = sanitizedString.replace(".", "")
    sanitizedString = sanitizedString.replace(",", "")
    sanitizedString = sanitizedString.replace(":", "")
    sanitizedString = sanitizedString.replace(";", "")

    sanitizedString = sanitizedString + randomizedalphabetString
    keyString = list(dict.fromkeys(sanitizedString))
    return keyString

string = 'The quick brown fox jumps over the lazy dog'
print(f'"{makeKey(string)} is the key you can use to encrypt your message')