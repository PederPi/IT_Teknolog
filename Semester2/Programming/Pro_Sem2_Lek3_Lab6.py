
def isPalindrome(testString):
    palindrome = True
    sanitizedTeststring = testString.lower()
    sanitizedTeststring = sanitizedTeststring.replace(" ", "")
    sanitizedTeststring = sanitizedTeststring.replace(".", "")
    sanitizedTeststring = sanitizedTeststring.replace(",", "")
    sanitizedTeststring = sanitizedTeststring.replace(":", "")
    sanitizedTeststring = sanitizedTeststring.replace(";", "")
    for character in range(0, len(sanitizedTeststring)):
        if sanitizedTeststring[character] != sanitizedTeststring[len(sanitizedTeststring) - character - 1]:
            palindrome = False
    return palindrome

print(isPalindrome('an,e'))