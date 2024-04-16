#include <stdio.h>

int main(void) {
	int sentinel = 0;
	int counter = 0;
	double average = 0.0;
	int store = 0;
	printf("Please input numbers to be averaged, end with 9999:\n");
	while (sentinel == 0) {
		int input;
		scanf_s("%d", &input);
		if (input == 9999) {
			sentinel = 9999;
		}
		else {
			store += input;
			counter++;
		}
	}
	average = (float)store / (float)counter;
	printf("%.2f", average);
}