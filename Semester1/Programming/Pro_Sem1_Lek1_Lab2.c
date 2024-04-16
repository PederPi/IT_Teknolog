
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void main()
{
	char operator;
	double firstDigit, secondDigit;

	printf("Please enter first digit:");
	scanf("%lf", &firstDigit);
	printf("Please enter operation:");
	scanf(" %c", &operator);
	printf("Please enter second digit:");
	scanf("%lf", &secondDigit);


	if (operator == '+')
	{
		printf("The result is: %f", firstDigit + secondDigit);
	}
	else if (operator == '-')
	{
		printf("The result is: %f", firstDigit - secondDigit);
	}
	else if (operator == '*')
	{
		printf("The result is: %f", firstDigit * secondDigit);

	}
	else if (operator == '/')
	{
		printf("The result is: %f", firstDigit / secondDigit);
	}
	else
	{
		printf("Wrong input!!!");
	}
}