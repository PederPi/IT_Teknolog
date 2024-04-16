#include <stdio.h>

int main(void) {
	int sum = 0;
	for (int i = 2; i < 31; i += 2) {
		sum += i;
	}
	printf("%d", sum);
}