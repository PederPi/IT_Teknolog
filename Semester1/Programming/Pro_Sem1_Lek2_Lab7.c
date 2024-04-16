//lab7.c
#include <stdio.h>
#define CONSTANT1 0x33
const CONSTANT2 = 0xCC;
int variable1 = CONSTANT1;
int variable2;
//int variable2 = CONSTANT2;
// This cannot be done with a constant defined with "const"
int main(void)
{
	variable2 = CONSTANT2;
	printf("The first constant is 0x%X\n", CONSTANT1);
	printf("The second constant is 0x%X\n", CONSTANT2);
	//while(1);
	return 0;
}