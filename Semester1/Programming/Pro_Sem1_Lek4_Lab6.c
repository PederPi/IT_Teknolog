#include <stdio.h>

int main(void) {
	int sum = 1;
	for (int i = 1; i < 16; i += 2) {
		sum *= i;
	}
	printf("%d", sum);
}