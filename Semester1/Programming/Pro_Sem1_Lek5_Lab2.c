#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int getUserInputGuess() {
	int guess = 0;
	printf("\nGuess an integer between 0 and 99: ");
	scanf_s("%d", &guess);
	printf("\n");
	return guess;
}

int testGuess(int userGuess, int randomNumber) {
	if (userGuess == randomNumber) {
		return 1;
	}
	else {
		return -1;
	}
}

void userOutput(int correct) {
	if (correct == 1) {
		printf("Congratulations! You guessed correct.\n");
	}
	else {
		printf("Sorry wrong guess, try again.\n");
	}
}

int generateRandomNumber() {
	int randomNumber;
	srand((int)time(0));
	return rand() % 100;
}

void runLoop() {
	int userGuess;
	int randomNumber;
	int correctGuess = -1;
	randomNumber = generateRandomNumber();
	while (correctGuess == -1) {
		userGuess = getUserInputGuess();
		correctGuess = testGuess(userGuess, randomNumber);
		userOutput(correctGuess);
	}
}

int main(void) {
	runLoop();
}