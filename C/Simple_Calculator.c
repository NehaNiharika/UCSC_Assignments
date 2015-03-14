/**
 * This is a simple calculator program which perform addition,
 * subtraction, multiplication and division of float numbers.
 *
 * Author Neha Niharika
 * Version 1.0
 * Date 2015-02-23
 */

/* Header Declaration */
# include <stdio.h>

/* Variable to hold operation value (1 for +, 2 for -) etc */
int operation;

/* Function to show calculator main menu */
int askCalcChoice()
{
    char menuChoice;
    printf("\nWelcome to Neha's Handy Calculator");
    printf("\n");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\n5. Exit");
    printf("\n\n");
    printf("What would you like to do?");
    /* Do While loop  to get input from user till exit */
    do {
        scanf("%c",&menuChoice);
        if (menuChoice==('1')|menuChoice==('a')|menuChoice==('A')){
			operation=1;
			break;
		} else if (menuChoice==('2')|menuChoice==('s')|menuChoice==('S')){
			operation=2;
			break;
		} else if (menuChoice==('3')|menuChoice==('m')|menuChoice==('M')){
			operation=3;
			break;
		} else if (menuChoice==('4')|menuChoice==('d')|menuChoice==('D')){
			operation=4;
			break;
		} else if (menuChoice==('5')|menuChoice==('x')|menuChoice==('X')){
			return 5;
		} else {
            while (getchar() != '\n')
				continue;
			printf("That is not a valid choice, please re-enter : ");
			continue;
        }
    } while (1);
    /* return the number corresonding to operation selected */
    return operation;
}

/* Function to accept floating numbers as input */
void getTwoFloats(float fNums[])
{
    /* Flush any stdin values */
    fflush(stdin);
	printf("Please enter two float numbers separated by a space and press enter: ");
    while (1) {
	while ((scanf("%f %f", &fNums[0], &fNums[1])) != 2)
	{
		while (getchar() != '\n')
			continue;
		printf("\nError reading your numbers. Pleas re-enter: ");
	}
    if (operation == 4 && fNums[1] == 0.0f){
        printf("You can't divide by zero, please re-enter both floats : ");
        fNums[0] = fNums[1] = 0.0f;
        continue;
    }
        break;
    }
}

/* Function to retrun operation as String corresponding to operation value */
void operationInText()
{
    switch(operation){
		case 1 : printf("addition");
            break;
		case 2 : printf("substraction");
            break;
		case 3 : printf("multiplication");
            break;
		case 4 : printf("division");
            break;
    }
}

/* Function to display result of calculation */
void displayResults(float fNums[])
{
    char enter;
    float result=0.0;
    switch (operation){
		case 1: result = fNums[0]+fNums[1]; break;
		case 2: result = fNums[0]-fNums[1]; break;
		case 3: result = fNums[0]*fNums[1]; break;
		case 4: result = fNums[0]/fNums[1]; break;
    }
    printf("\nResult of ");
    operationInText();
    printf(" of %5.2f and %5.2f is : %5.2f",fNums[0],fNums[1],result);
    printf("\n\nPress enter to continue ... \n");
    scanf("%c",&enter);
    while( getchar() != '\n');
    }

/* Function to display program end message */
void displayBye(){
    printf("\nThank you for using Neha's Handy Calculator ! ");
}

/* Starting point of program */
int main()
{
    float myFloats[2]=  {0.0, 0.0};
    /* Check user input if not "Exit" continue program */
    while(askCalcChoice()!=5){
        getTwoFloats(myFloats);
        displayResults(myFloats);
    }
    displayBye();
    return 0;
}
/********** End of Program **********/