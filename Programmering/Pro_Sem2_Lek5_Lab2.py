gradesFile = open("grades.txt", "r")
sum = 0
count = 0
average = 0.0
for line in gradesFile:
    print(" ".join(line.split()))
    sum += int(line)
    count += 1
print("Sum of grades:", sum)
print("Count:", count)
average = float(sum) / float(count)
print("Average:", average)

gradesFile.close()