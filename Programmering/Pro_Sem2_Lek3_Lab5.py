import random, time

def insertionSort(unsortedList):
    startTime = round(time.time() * 1000)

    for unsortedIndex in range(1, len(unsortedList)):
        for sortedIndex in range(unsortedIndex, 0, -1):
            if unsortedList[sortedIndex] < unsortedList[sortedIndex - 1]:
                temp = unsortedList[sortedIndex - 1]
                unsortedList[sortedIndex - 1] = unsortedList[sortedIndex]
                unsortedList[sortedIndex] = temp            
    sortedList = unsortedList

    endTime = round(time.time() * 1000)
    elapsedTime = endTime - startTime
    return elapsedTime

for x in range (10000, 100000, 10000):
    values = []
    counter = 0
    while counter < x:
        number = random.randint(0, x * 10)
        if number not in values:
            values.append(number)
            counter += 1
    print(x,",",insertionSort(values))
