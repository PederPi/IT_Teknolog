#include <stdio.h>
#include <ctype.h>

void main()
{
	int firstGrade, secondGrade, thirdGrade, fourthGrade, roundedAverage, correctInput = 0;
	float sumOfGrades, average;
	char finalGrade;

	while (correctInput == 0)
	{
		printf("Enter the students grades in the format: grade1, grade2, grade3, grade4:");
		scanf_s("%d, %d, %d, %d", &firstGrade, &secondGrade, &thirdGrade, &fourthGrade);

		if (firstGrade % 1 == 0 && secondGrade % 1 == 0 && thirdGrade % 1 == 0 && fourthGrade % 1 == 0)
		{
			if (firstGrade >= 0 && firstGrade <= 100 && secondGrade >= 0 && secondGrade <= 100 && thirdGrade >= 0 && thirdGrade <= 100 && fourthGrade >= 0 && fourthGrade <= 100)
			{
				sumOfGrades = firstGrade + secondGrade + thirdGrade + fourthGrade;
				average = sumOfGrades / 4.0;
				printf("The students average score is: %f\n", average);
				correctInput = 1;
				if (average <= 39)
				{
					printf("The students final grade is: 00");
				}
				else if (average > 39 && average <= 59)
				{
					printf("The students final grade is: 02");
				}
				else if (average > 59 && average <= 69)
				{
					printf("The students final grade is: 4");
				}
				else if (average > 69 && average <= 79)
				{
					printf("The students final grade is: 7");
				}
				else if (average > 79 && average <= 89)
				{
					printf("The students final grade is: 10");
				}
				else if(average > 89 && average <=100)
				{
					printf("The students final grade is: 12");
				}
			}
			else
			{
				printf("Wrong input, try again:\n");
			}
		}
		else
		{
			printf("Wrong input, try again:\n");
		}
	}
}