// lab9.c
#include <stdio.h> // Standard I/O - required for printf() function
#define CONSTANT1 50
int main(void)
{
	/* VARIABLE DECLARATIONS */
	unsigned char charVariable1 = 50;
	unsigned char charVariable2 = 100;
	float floatVariable1 = 34.5678;
	float floatVariable2 = 156.78956;
	int intVariable1 = 1000;
	int intVariable2 = 10000;
	long longVariable1 = 1000;
	long longVariable2 = 2000;
	/*---------------------------------------------------------------------------
	Standard Mathematical Operators
   ---------------------------------------------------------------------------*/
   /*###########################################################################
   # STEP 1: Add charVariable1 to charVariable2 and store the result in
   # charVariable1. This may be done in two ways. One uses the
   # ordinary addition operator, the other uses a compound assignment
   # operator. Write two lines of code to perform this operation
   # twice - once for each of the two methods.
   # Don't forget to end each statement with a semi-colon!
   ###########################################################################*/
	charVariable1 = charVariable1 + charVariable2;
	charVariable1 += charVariable2;
   /*###########################################################################
   # STEP 2: Increment charVariable1. There are several ways this could be
   # done. Use the one that requires the least amount of typing.
   ###########################################################################*/
	charVariable1++;
	intVariable1 = intVariable2 - intVariable1;
	intVariable2--;
	longVariable2 *= longVariable1;
	floatVariable2 /= floatVariable1;
	/*---------------------------------------------------------------------------
	 Conditional Operator
	---------------------------------------------------------------------------*/
	/*###########################################################################
	# STEP 3: Use the conditional operator to set longVariable1 equal to
	# intVariable1 if charVariable1 is less than charVariable2.
	# Otherwise, set longVariable1 equal to intVariable2
	# NOTE: The comments below are broken up into 3 lines, but the code you
	# need to write can fit on a single line.
	###########################################################################*/
	if (charVariable1 < charVariable2) {
		longVariable1 = intVariable1;
	}
	else {
		longVariable1 = intVariable2;
	}
	/*---------------------------------------------------------------------------
	 Comma Operator
	 The code below increments charVariable1, then increments charVariable2 and
	 assigns the new value of charVariable2 to longVariable2.
	---------------------------------------------------------------------------*/
	longVariable2 = (charVariable1++, charVariable2++);
	/*---------------------------------------------------------------------------
	 Bit Shift Operator
	---------------------------------------------------------------------------*/
	/*###########################################################################
	# STEP 4: Shift longVariable2 one bit to the right. This can be accomplished
	# most easily using the appropriate compound assignment operator.
	###########################################################################*/
	longVariable2 = longVariable2 >> 1;
	//### Your Code Here ### //### Shift longVariable2 one bit to the right
	/*---------------------------------------------------------------------------
	 Bitwise AND Operators
	---------------------------------------------------------------------------*/
	/*###########################################################################
	# STEP 5: Perform the operation (longVariable2 AND 0x30) and store the result
	# back in longVariable2. Once again, the easiest way to do this is
	# to use the appropriate compound assignment operator that will
	# perform an equivalent operation to the one in the comment below.
	# (The operation is a bitwise AND - not a logical AND)
	###########################################################################*/
	longVariable2 &= 0x30;
	/*---------------------------------------------------------------------------
	 Bitwise Inclusive OR Operators (both lines perform the same operation)
	---------------------------------------------------------------------------*/
	//longVariable2 = longVariable2 | 0x0F;
	longVariable2 |= 0x0F;
	/*---------------------------------------------------------------------------
	 Bitwise Exclusive OR Operators (both lines perform the same operation)
	---------------------------------------------------------------------------*/
	//longVariable2 = longVariable2 ^ 0x03;
	longVariable2 ^= 0x03;
	/*---------------------------------------------------------------------------
	 Loop Forever and repeatedly increment longVariable2
	---------------------------------------------------------------------------*/
	while (1)
	{
		longVariable2++;
	}
}