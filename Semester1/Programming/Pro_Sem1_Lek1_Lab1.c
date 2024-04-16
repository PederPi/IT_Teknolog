#include <stdio.h>

void main() {

	int userInput;
	printf("Enter your number: \n");
	scanf_s("%d", &userInput);

	if (userInput % 5 == 0)
	{
		printf("The number is divisble by 5.");
	}
	else
	{
		printf("The number is not divisble by 5.");
	}
}