#include <stdio.h>
const int CONSTANT50 = 50;
char charVariable;
short shortVariable;
int intVariable;
long longVariable;
float floatVariable;
double doubleVariable;
int main(void);
int main(void)
{
	/*---------------------------------------------------------------------------
	 Initialize Variables
	---------------------------------------------------------------------------*/
	charVariable = CONSTANT50;
	shortVariable = CONSTANT50;
	intVariable = CONSTANT50;
	longVariable = CONSTANT50;
	floatVariable = CONSTANT50;
	doubleVariable = CONSTANT50;
	/*---------------------------------------------------------------------------
	 Print out storage size of each variable
	---------------------------------------------------------------------------*/
	printf("A character variable requires %d byte\n", sizeof(charVariable));
	printf("A short variable requires %d bytes\n", sizeof(shortVariable));
	printf("An integer variable requires %d bytes\n", sizeof(intVariable));
	printf("A long variable requires %d bytes\n", sizeof(longVariable));
	printf("A floating point variable requires %d bytes\n", sizeof(floatVariable));
	printf("A double variable requires %d bytes\n", sizeof(doubleVariable));
	printf("---\n");
	printf("A character variable requires %d byte\n", sizeof(char));
	printf("A short variable requires %d bytes\n", sizeof(short));
	printf("An integer variable requires %d bytes\n", sizeof(int));
	printf("A long variable requires %d bytes\n", sizeof(long));
	printf("A floating point variable requires %d bytes\n", sizeof(float));
	printf("A double variable requires %d bytes\n", sizeof(double));
	return 0;
}
