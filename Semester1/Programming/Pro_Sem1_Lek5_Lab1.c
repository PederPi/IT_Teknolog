#include <stdio.h>
#include <math.h>

double triangleArea(int a, int b);
int isPythagorean(int a, int b, int c);
double findMax(double a, double b, double c, double d);
void analyzeQuadratic(double a, double b, double c);

int isPythagorean(int a, int b, int c) {

	int a2Plusb2 = a * a + b * b;
	int c2 = c * c;
	
	if (a2Plusb2 == c2) {
		printf("\nThe triangle with side lengths: %d, %d and %d, is a rigth angle triangle!\n", a, b, c);
		return 1;
	}
	else {
		printf("\nNot pythagorean :(\n");
		return -1;
	}
}

double triangleArea(int a, int b) {
	double area = ((double)a * (double)b) / 2.0;
	printf("The triangle has an area of: %.2f\n", area);
	return area;
}

double findMax(double a, double b, double c, double d) {
	double floatArray[4] = { a, b, c, d };
	double maxFloat;
	maxFloat = floatArray[0];
	for (int i = 1; i < 4; i++) {
		if (floatArray[i] > maxFloat) {
			maxFloat = floatArray[i];
		}
	}
	printf("\nThe max float out of the following floats: %.2f, %.2f, %.2f and %.2f, is: %.2f\n", floatArray[0], floatArray[1], floatArray[2], floatArray[3], maxFloat);
	return maxFloat;
}

void analyzeQuadratic(double a, double b, double c) {
	double discriminant;
	double root1RealPart;
	double root2RealPart;
	double root1ComplexPart;
	double root2ComplexPart;
	discriminant = (b * b) - (4.0 * a * c);
	if (discriminant > 0.0) {
		root1RealPart = (b * -1.0 + sqrtf(discriminant)) / (2.0 * a);
		root2RealPart = (b * -1.0 - sqrtf(discriminant)) / (2.0 * a);
		printf("\nThe quadratic equation has 2 real roots: x = %.2f and x = %.2f\n", root1RealPart, root2RealPart);
	}
	else if (discriminant < 0.0) {
		root1RealPart = (b * -1.0) / (2.0 * a);
		root1ComplexPart = sqrtf(-1.0 * discriminant) / 2.0 * a;
		root2RealPart = (b * -1.0) / (2.0 * a);
		root1ComplexPart = sqrtf(-1.0 * discriminant) / 2.0 * a;
		printf("\nThe quadratic equation has 2 complex roots: x = %.2f + %.2fi and x = %.2f - %.2fi\n", root1RealPart, root1ComplexPart, root2RealPart, root1ComplexPart);
	}
	else {
		root1RealPart = (b * -1.0 + sqrtf(b * b - 4.0 * a * c)) / (2.0 * a);
		printf("\nThe quadratic equation has a double root: x = %.2f\n", root1RealPart);
	}
}

int main(void) {
	//a:
	int a = 3;
	int b = 4;
	int c = 5;
	isPythagorean(a, b, c);

	//b:
	triangleArea(a, b);

	//c:
	double d1 = 1.0;
	double d2 = 2.0;
	double d3 = 3.0;
	double d4 = 4.0;
	findMax(d1, d2, d3, d4);

	//d:
	double dA = 1.0;
	double dB = 2.0;
	double dC = 1.0;
	analyzeQuadratic(dA, dB, dC);

	return 0;
}