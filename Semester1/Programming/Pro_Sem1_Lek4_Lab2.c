#include <stdio.h>

int main(void) {
	//a
	printf("\nA:\n");
	for (int i = 1; i < 8; i++) {
		printf("%d", i);
	}

	//b
	printf("\nb:\n");
	for (int i = 3; i < 24; i += 5) {
		printf("%d", i);
	}

	//c
	printf("\nc:\n");
	for (int i = 20; i > -11; i -= 6) {
		printf("%d", i);
	}

	//d
	printf("\nd:\n");
	for (int i = 19; i < 52; i += 8) {
		printf("%d", i);
	}


	return 0;
}