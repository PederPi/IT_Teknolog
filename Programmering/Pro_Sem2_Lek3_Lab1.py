#a
#day, high_temperature = ('Monday', 87, 65)         2 variables for 3 values
day, high_temperature, low_temperature = ('Monday', 87, 65)

#b
numbers = [1, 2, 3, 4, 5] 
#numbers[10] calling list "numbers" index 10, which does not exist only index 0-4 exists presently

#c
name = 'amanda' 
#name[0] = 'A' not how you replace letter in a string 
name = name.replace("a", "A", 1)
print(name)

#d
numbers = [1, 2, 3, 4, 5] 
#numbers[3.4] an index must be an integer

#e
student_tuple = ('Amanda', 'Blue', [98, 75, 87]) 
#student_tuple[0] = 'Ariana'            tupples are immutable

#f
#('Monday', 87, 65) + 'Tuesday'         tupples are immutable and items cant be added by concatonation

#g
#'A' += ('B', 'C')                      Not even sure what is trying to be achieved here

#h
x = 7 
#del x                                  Cannot print a deleted variable
print(x) 

#i
numbers = [1, 2, 3, 4, 5] 
#numbers.index(10)                      Cannot find the index of the integer 10 in the list because the list doesnt contain 10

