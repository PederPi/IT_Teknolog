#include <stdio.h>;

int calcAndOutput() {
	int mortgage = 0;
	int mortgageTerm = 0;
	int interestRate = 0;
	int totalInterestPayable = 0;
	int monthlyPayableInterest = 0;
	char continueInput[1] = "";
	printf_s("Enter mortgage amount in dollars: ");
	scanf_s("%d", &mortgage);
	printf_s("Enter Mortgage term (in years): ");
	scanf_s("%d", &mortgageTerm);
	printf_s("Enter interest rate: ");
	scanf_s("%d", &interestRate);
	totalInterestPayable = mortgage * interestRate * mortgageTerm;
	monthlyPayableInterest = (totalInterestPayable + mortgage) / (mortgageTerm * 12);
	printf_s("The Monthly Payable Interest Is: %d", monthlyPayableInterest);
	printf_s("\nWant to continue inputting data? (y/n): ");
	scanf_s(" %c", &continueInput[0]);
	if (strcmp(continueInput[0], "y") == 0) {
		return 1;
	}
	else if (strcmp(continueInput[0], 'n') != 0) {
		return 0;
	}
	else {
		printf_s("Invalid input, exiting program.");
		return 0;
	}
}



int main(void) {
	int continueInput = 1;
	while(continueInput){
		continueInput = calcAndOutput();
	}
}