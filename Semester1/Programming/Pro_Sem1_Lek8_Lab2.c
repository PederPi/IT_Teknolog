#include <stdio.h>

int main(void) {
	int passwordCorrect = 0;
	int password;
	while (passwordCorrect == 0) {
		printf_s("\nInput the password: ");
		scanf_s("%d", &password);
		if (password == 5678) {
			printf_s("Correct password\n");
			passwordCorrect = 1;
		}
		else {
			printf_s("Incorrect password\n");
		}
	}
}