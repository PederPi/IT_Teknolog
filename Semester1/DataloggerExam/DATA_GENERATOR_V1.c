#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	char* dataTest = "C:\\Users\\jpive\\Documents\\programtest\\dateTest6.txt";
	FILE* dataTestFile = fopen(dataTest, "w");
	int hour = -1;
	int counter = 0;
	int min = 0;
	for (int i = 0; i < 144; i++) {
		srand(i);
		int tempIN = rand() % 300;
		int tempOUT = rand() % 100;
		int humIN = rand() % 800;
		int humOUT = rand() % 400;
		int light = rand() % 1000;
		if (counter % 6 == 0) {
			hour++;
			min = 0;
		}
		fprintf(dataTestFile, "2023-12-10,%d:%d:00,%d,%d,%d,%d,%d,\n", hour, min, tempIN, humIN, tempOUT, humOUT, light);
		min += 10;
		counter++;
	}
}