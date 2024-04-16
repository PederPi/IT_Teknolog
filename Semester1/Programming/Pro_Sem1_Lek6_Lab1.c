#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/*a
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += array[i];
	}
	printf_s("Sum of array: %d\n", sum);*/
	/*b
	int sumd1 = 0;
	int sumd2 = 0;
	int dif[10][10];
	int d1[10][10];
	int d2[10][10];
	for (int i = 0; i < 10; i++) {
		for (int y = 0; y < 10; y++) {
			d1[i][y] = 1;
			d2[i][y] = 1;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int y = 0; y < 10; y++) {
			sumd1 += d1[i][y];
			sumd2 += d2[i][y];
			dif[i][y] = d1[i][y] - d2[i][y];
		}
	}
	printf_s("Sum of d1: %d\n", sumd1);
	printf_s("Sum of d2: %d\n", sumd2);*/
	/*c
	int sales[20];
	for (int i = 0; i < 20; i++) {
		int input = 0;
		scanf_s("%d", &input);
		sales[i] = input;
	}
	for (int i = 0; i < 20; i++) {
		for (int y = 0; y < sales[i]; y++) {
			printf_s("x");
		}
		printf_s("\n");
	}*/
	/*d
	int salesd[20];
	for (int i = 0; i < 20; i++) {
		salesd[i] = rand();	
	}
	int largestElement = salesd[0];
	int smallestElement = salesd[0];
	for (int i = 0; i < 20; i++) {
		if (salesd[i] < smallestElement) {
			smallestElement = salesd[i];
		}
		if (salesd[i] > largestElement) {
			largestElement = salesd[i];
		}
	}
	printf("%d\n", smallestElement);
	printf("%d\n", largestElement);*/
}