//lab8.c
/*-------------------------------------------------------------------------------
 HEADER FILES
-------------------------------------------------------------------------------*/
#include <stdio.h> // Standard I/O - required for printf() function
/*-------------------------------------------------------------------------------
 FUNCTION PROTOTYPES
-------------------------------------------------------------------------------*/
int main(void);
/*===============================================================================
 FUNCTION: main()
 DESCRIPTION: Prints out various data types with different format settings
 PARAMETERS: none
 RETURNS: nothing
===============================================================================*/
int main(void)
{
	/*---------------------------------------------------------------------------
	 Print out various data types with different format settings
	---------------------------------------------------------------------------*/
	printf("25 as decimal (d): %d\n", 25); //%d = decimal int
	printf("'a' as character (c): %c\n", 'a'); //%c = character
	printf("'a' as decimal (d): %d\n", 'a'); //%d = decimal int
	printf("2.55 as float (f): %f\n", 2.55); //%f = float
	printf("2.55 as decimal (d): %d\n", 2.55); //%d = decimal int
	printf("6.02e23 as exponent (e): %e\n", 6.02e23); //%e = float exp
	printf("6.02e23 as decimal (d): %d\n", 6.02e23); //%d = decimal int
	printf("'Raspberry' as string (s): %s\n", "Raspberry"); //%s = string
	printf("'Raspberry' as decimal (d): %d\n", "Raspberry"); //%d = decimal int
	return 0;
}