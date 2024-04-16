#include <stdio.h>
int main(void) {
	//a
	printf("\nA:\n");
	int sum = 0;
	for (int count = 1; count <= 99; count += 2) {
		sum += count;
	}
	printf("%d", sum);

	//b
	printf("\nB:\n");
	float numberB = 333.546372;
	printf("%15.1f", numberB);
	printf("%15.2f", numberB);
	printf("%15.3f", numberB);
	printf("%15.4f", numberB);
	printf("%15.5f", numberB);

	//c
	printf("\nC:\n");
	float numberC = 0;
	numberC = pow(2.5, 3);
	printf("%10.2f", numberC);

	//d
	printf("\nD:\n");
	int x = 1;
	while (x < 21) {
		printf("%d", x);
		if (x % 5 == 0) {
			printf("\n");
		}
		else {
			printf("\t");
		}
		x++;
	}

	//e
	printf("\nE:\n");
	for (int x = 1; x < 21; x++) {
		printf("%d", x);
		if (x % 5 == 0) {
			printf("\n");
		}
		else {
			printf("\t");
		}
	}

}