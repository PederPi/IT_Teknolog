userInput = []
for x in range(1, 8):
    userInput.append(int(input("Input day flu cases (Finish with enter): ")))

def analyzeFlu(userInput):
    totalCases = 0
    totalCases = sum(userInput)
    print("Total number of cases: ", totalCases)
    averageCases = 0
    averageCases = totalCases / len(userInput)
    print("Average cases per day: ", averageCases)
    minimumCases = 0
    minimumCases = min(userInput)
    print("Day with least cases: ", minimumCases)
    maximumCases = 0
    maximumCases = max(userInput)
    print("Day with most cases: ", maximumCases)

analyzeFlu(userInput)