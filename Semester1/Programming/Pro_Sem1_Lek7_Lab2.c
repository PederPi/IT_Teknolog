#include <stdio.h>

int main(void) {
	int firstNumber = 8;
	int secondNumber = 3;
	int* ptr1 = &firstNumber;
	int* ptr2 = &secondNumber;
	if (*ptr1 > *ptr2) {
		printf_s("%d", *ptr1);
	}
	else {
		printf_s("%d", *ptr2);
	}
}