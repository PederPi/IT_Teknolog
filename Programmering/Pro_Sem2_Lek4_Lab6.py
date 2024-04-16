import math

number_to_word = {  0: 'ZERO', 1: 'ONE', 2: 'TWO', 3: 'THREE', 4: 'FOUR',
                    5: 'FIVE', 6: 'SIX', 7: 'SEVEN', 8: 'EIGHT', 9: 'NINE',
                    10: 'TEN', 11: 'ELEVEN', 12: 'TWELVE', 13: 'THIRTEEN',
                    14: 'FOURTEEN', 15: 'FIFTEEN', 16: 'SIXTEEN', 17: 'SEVENTEEN',
                    18: 'EIGHTEEN', 19: 'NINETEEN', 20: 'TWENTY', 30: 'THIRTY',
                    40: 'FORTY', 50: 'FIFTY', 60: 'SIXTY', 70: 'SEVENTY',
                    80: 'EIGHTY', 90: 'NINETY'}

def takeUserInput():
    userInput = 1001
    while userInput >= 1000:
        userInput = input("Input the cheque amount (must be less than 1000): ")
    return userInput

def translateChequeNumberV1(chequeAmountString):
    chequeAmount = int(chequeAmountString)
    print(type(chequeAmount))
    if chequeAmount < 10:
        for key in number_to_word:
            if key == chequeAmount:
                print(number_to_word[key])
    elif chequeAmount < 100:
        for key in number_to_word:
            if key / 10 == int(chequeAmount / 10):
                print(number_to_word[key]) 
                remainder = chequeAmount - key
                for key in number_to_word:
                    if key == 0:
                        break
                    elif key == remainder:
                        print(number_to_word[key])
    elif chequeAmount < 1000:
        for key in number_to_word:
            if key == int(chequeAmount / 100):
                print(number_to_word[key], 'HUNDRED') 
                for key in number_to_word:
                    if key == int((chequeAmount % 100) / 10) * 10:
                        print(number_to_word[key]) 
                        for key in number_to_word:
                            if chequeAmount % 10 == 0:
                                break
                            elif key == chequeAmount % 10:
                                print(number_to_word[key])

    return 0

def translateChequeNumverV2(chequeAmount):

    return 0

translateChequeNumberV1(takeUserInput())