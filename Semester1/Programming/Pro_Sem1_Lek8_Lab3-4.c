#include <stdio.h>

int main(void) {
	int array[20] = {0};
	int userEnteredPosition;
	int userEnteredNumber;
	int largestElement = array[0];
	while (1) {
		printf_s("\n\nAt what position do you want to enter a number?: ");
		scanf_s("%d", &userEnteredPosition);
		if (userEnteredPosition < 20 && userEnteredPosition >= 0) {
			printf_s("What number you want to enter at this position?: ");
			scanf_s("%d", &userEnteredNumber);
			array[userEnteredPosition] = userEnteredNumber;
			for (int i = 0; i < 20; i++) {
				printf_s("\n%d", array[i]);
				if (largestElement < array[i]) {
					largestElement = array[i];
				}
			}
			printf_s("\nLargest element in array: %d", largestElement);
		}
		else{
			printf_s("Invalid position, must be [0;19], please try again.");
		}
	}
}