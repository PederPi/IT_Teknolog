#include <stdio.h>

int main(void) {
	printf("Please input 7 integers, sepperated by commas: ");
	int int1, int2, int3, int4, int5, int6, int7;
	scanf_s("%d,%d,%d,%d,%d,%d,%d", &int1, &int2, &int3, &int4, &int5, &int6, &int7);
	for (int i = 0; i <= int1; i++) {
		printf("*");
	}
	printf("\n");
	for (int i = 0; i <= int1; i++) {
		printf("*");
	}
	printf("\n");
	for (int i = 0; i <= int2; i++) {
		printf("*");
	}
	printf("\n");
	for (int i = 0; i <= int3; i++) {
		printf("*");
	}
	printf("\n");
	for (int i = 0; i <= int4; i++) {
		printf("*");
	}
	printf("\n");
	for (int i = 0; i <= int5; i++) {
		printf("*");
	}
	printf("\n");
	for (int i = 0; i <= int6; i++) {
		printf("*");
	}
	printf("\n");
	for (int i = 0; i <= int7; i++) {
		printf("*");
	}
}