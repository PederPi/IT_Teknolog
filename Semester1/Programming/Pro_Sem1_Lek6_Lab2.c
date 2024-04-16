#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arraySize;
	int sum = 0;
	float average;
	int lowestElement;
	int largestElement;
	int dublicate = 0;
	printf_s("Input size of array: ");
	scanf_s("%d", &arraySize);
	int* array;
	array = (int*)malloc(arraySize * sizeof(int));
	for (int i = 0; i < arraySize; i++) {
		scanf_s("%d", &array[i]);
	}
	lowestElement = array[0];
	largestElement = array[0];
	for (int i = 0; i < arraySize; i++) {
		sum += array[i];
		if (lowestElement > array[i]) {
			lowestElement = array[i];
		}
		if (largestElement < array[i]) {
			largestElement = array[i];
		}
		for (int y = 0; y < arraySize; y++) {
			if (array[i] == array[y] && i != y) {
				dublicate = 1;
			}
		}
	}
	average = (float)sum / (float)arraySize;
	printf_s("Sum of elements: %d\n", sum);
	printf_s("Average of elements: %.2f\n", average);
	printf_s("Smallest element: %d\n", lowestElement);
	printf_s("Largest element: %d\n", largestElement);
	if (dublicate == 1) {
		printf("There are dublicates.\n");
	}
	else {
		printf("There are no dublicates.\n");
	}
	free(array);
	return 0;
}