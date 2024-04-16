#include <stdio.h>

int main(void){
	int evenCounter = 0;
	int evenSum = 0;
	float averageEven = 0;
	int oddCounter = 0;
	int oddSum = 0;
	float averageOdd = 0;
	int userInput;
	int zeroEntered = 0;

	while (zeroEntered == 0){
		scanf_s("%d", &userInput);
		if (userInput != 0){
			if (userInput % 2 == 0){
				evenCounter++;
				evenSum += userInput;
			}
			else{
				oddCounter++;
				oddSum += userInput;
			}
		}
		else{
			zeroEntered = 1;
		}
	}

	averageEven = evenSum / (float)evenCounter;
	averageOdd = oddSum / (float)oddCounter;
	printf_s("Number of evens: %d\n", evenCounter);
	printf_s("Average of evens: %f\n", averageEven);
	printf_s("Number of odds: %d\n", oddCounter);
	printf_s("Average of odds: %f\n", averageOdd);
}