#include <stdio.h>

int main(void) {
	double value1 = 20.4568;
	double value2;
	//a
	double *dPtr;
	//b
	dPtr = &value1;
	//c
	printf_s("%lf\n", *dPtr);
	//d
	dPtr = &value2;
	//e
	printf_s("%lf\n", *dPtr);
	//f
	printf_s("%p\n", value1);
	//g
	printf_s("%p\n", *dPtr);
	//No not the same address because dPtr now points to value2
}

