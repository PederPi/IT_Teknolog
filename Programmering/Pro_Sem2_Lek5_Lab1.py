gradeFile = open("grades.txt", "w")
gradeFile.write("")
gradeFile.close()
gradeFile = open("grades.txt", "a")

takeInput = True
while(takeInput):
    userInput = ""
    userInput = input("Enter grade: ")
    userInput = " ".join(userInput.split())
    if userInput == "exit":
        takeInput = False
        gradeFile.close()
    else:
        gradeFile.write(userInput + "\n")
