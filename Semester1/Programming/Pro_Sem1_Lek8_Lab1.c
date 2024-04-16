#include <stdio.h>

int main(void) {
	char array[62] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0' };
	printf_s("-------------------------------------------------\n");
	printf_s("| Character | Ascii Decimal | Ascii Hexadecimal |\n");
	printf_s("-------------------------------------------------\n");
	for (int i = 0; i < 62; i++) {
		printf_s("| %-9c ", array[i]);
		printf_s("| %-13d |", array[i], 20);
		printf_s(" %-17x |\n", array[i], 20);
		printf_s("-------------------------------------------------\n");
	}
}