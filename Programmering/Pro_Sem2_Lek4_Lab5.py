text = ('this is some encrypted text with different words '       
        'this is some more text with a hidden message')

def CFA(text):
    charFrequencyDictionary = {}
    textLowerCase = text.lower()
    textNoSpace = textLowerCase.replace(' ', '')
    alphabeticallySortedText = ''.join(sorted(textNoSpace))
    for character in alphabeticallySortedText:
        if character in charFrequencyDictionary: 
            charFrequencyDictionary[character] += 1  # update existing key-value pair
        else:
            charFrequencyDictionary[character] = 1  # insert new key-value pair
    for item in charFrequencyDictionary:
        print(item, ':', charFrequencyDictionary[item])
    return 0

CFA(text)