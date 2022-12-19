/************************madharhaAnkushA1.c**************
Student Name: Ankush Madharha Email Id: amadharh@uoguelph.ca
Due Date: October 7th         Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:

1) I have read and understood the University policy on academic integrity.

2) I have completed the Computing with Integrity Tutorial on Moodle; and

3) I have achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own. I have appropriately acknowledged any and all 
material that I have used, whether directly quoted or paraphrased. Furthermore, 
I certify that this assignment was prepared by me specifically for this course.

********************************************************/

/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall

compiling:

gcc -std=c99 -Wall madharhaAnkushA1.c

Running: ./a.out

OR
gcc -std=c99 -Wall madharhaAnkushA1.c -o assn1

Running the Program: ./assn1

*********************************************************/

#include <stdio.h> // Used for printf and scanf
#include <stdbool.h> // Used for bool datatype
#include <stdlib.h> // Used for rand()
#include <time.h> // Used for time()

int main()
{
    // Declare Variables
    int yearOfBirth, luckyNum, questionReward;
    char lifelineAns, correctAns, finalAns;
    bool lifelineUsed;

    // Input yearOfBirth
    printf("Enter your year of birth (yyyy): ");
    scanf("%d", &yearOfBirth);

    // Validate yearOfBirth
    while (yearOfBirth < 1000 || yearOfBirth > 9999)
    {
        printf("Enter your year of birth (yyyy): ");
        scanf("%d", &yearOfBirth);
    }

    // Calculate luckyNum
    for (int i = 0; i < 4; i++)
    {
        luckyNum += yearOfBirth % 10;
        yearOfBirth /= 10;
    }

    // Output welcome message and luckyNum
    printf("*************************\n");
    printf("Welcome - Let us play millionEh!\n");
    printf("Your lucky number is %d\n", luckyNum);
    printf("*************************\n\n");

    // Runs questions 1 - 7
    for (int questionNum = 1; questionNum <= 7; questionNum++)
    {
        // Calculate reward
        if (questionNum == 1)
        {
            questionReward = 100;
        }
        else if (questionNum % 2 == 0)
        {
            questionReward *= 5;
        }
        else
        {
            questionReward *= 2;
        }
        printf("Question %d: Here is the $%d question:\n\n", questionNum, questionReward);

        switch (questionNum)
        {
        /* Depending on iteration (q1, q2, etc.):
            Output question with options
            Set correct answer
        */
        case 1:
            printf("Which one of the following programming languages is taught in CIS1300 at the University of Guelph?\n\n");
            printf("A. Python\nB. Cobra\nC. C\nD. Java\n");
            correctAns = 'C';
            break;
        case 2:
            printf("Which Canadian chain first opened in Hamilton in 1964?\n\n");
            printf("A. McDonalds\nB. Tim Hortons\nC. Wendys\nD. Mr. Sub\n");
            correctAns = 'B';
            break;
        case 3:
            printf("What is Canada's national sport?\n\n");
            printf("A. Hockey\nB. Lacrosse\nC. Hockey and Lacrosse\nD. Baseball\n");
            correctAns = 'C';
            break;
        case 4:
            printf("Which Canadian city ranks as the most educated in the country?\n\n");
            printf("A. Montreal\nB. Ottawa\nC. Vancouver\nD. Toronto\n");
            correctAns = 'B';
            break;
        case 5:
            printf("What is Canada's highest mountain?\n\n");
            printf("A. Mount Logan, Yukon\nB. Whistler Mountain, BC\nC. Mont Tremblant, Quebec\nD. Tip Top Mountain, Ontario\n");
            correctAns = 'A';
            break;
        case 6:
            printf("What is the easternmost province of Canada?\n\n");
            printf("A. Ontario\nB. Prince Edward Island\nC. Newfoundland\nD. Nova Scotia\n");
            correctAns = 'C';
            break;
        case 7:
            printf("The southernmost point of mainland Canada is called Point Pelee. Which province is it located in?\n\n");
            printf("A. Ontario\nB. Quebec\nC. Newfoundland\nD. Nova Scotia\n");
            correctAns = 'A';
            break;
        }


        // Runs if user did not use lifeline
        if (lifelineUsed == false)
        {
            // Input lifeline answer
            printf("\nWould you like to use a lifeline (50–50)?\n");
            printf("Enter Y or y, N or n: ");
            scanf(" %c", &lifelineAns);

            // Validate lifelineAns
            while (lifelineAns != 'Y' && lifelineAns != 'y' && lifelineAns != 'N' && lifelineAns != 'n')
            {
                printf("Invalid option entered\n\n");
                printf("Enter Y or y, N or n: ");
                scanf(" %c", &lifelineAns);
            }

            // Runs if user uses lifeline
            if (lifelineAns == 'Y' || lifelineAns == 'y')
            {
                // Set lifelineUsed to true,
                lifelineUsed = true;
                printf("\nOK - here are your 2 choices after using the 50-50 lifeline\n\n");

                // Depending on iteration (q1, q2, etc.): Output two remaining options
                switch (questionNum)
                {
                case 1:
                    printf("C. C\nD. Java\n\n");
                    break;
                case 2:
                    printf("A. McDonalds\nB. Tim Hortons\n\n");
                    break;
                case 3:
                    printf("C. Hockey and Lacrosse\nD. Baseball\n\n");
                    break;
                case 4:
                    printf("A. Montreal\nB. Ottawa\n\n");
                    break;
                case 5:
                    printf("A. Mount Logan, Yukon\nB. Whistler Mountain, BC\n\n");
                    break;
                case 6:
                    printf("C. Newfoundland\nD. Nova Scotia\n\n");
                    break;
                case 7:
                    printf("A. Ontario\nB. Quebec\n\n");
                    break;
                }

                // Output reminder
                printf("Reminder - You get only 1 lifeline - and you are using it now\n");
            }
        }

        // Input final answer
        printf("\nEnter your FINAL ANSWER (‘A’, ‘B’, ‘C’ OR ‘D’) here: ");
        scanf(" %c", &finalAns);

        // Validate finalAns
        while (finalAns != 'A' && finalAns != 'B' && finalAns != 'C' && finalAns != 'D')
        {
            printf("Enter your FINAL ANSWER (‘A’, ‘B’, ‘C’ OR ‘D’) here: ");
            scanf(" %c", &finalAns);
        }

        // Runs if final answer was correct
        if (finalAns == correctAns)
        {
            // Generate a random seed
            srand(time(0));

            // Output random congratulations message
            printf("\n");
            switch (rand() % 5)
            {
            case 0:
                printf("Bravo - You just won $%d\n", questionReward);
                break;
            case 1:
                printf("Congrats - You just won $%d\n", questionReward);
                break;
            case 2:
                printf("Well done - You just won $%d\n", questionReward);
                break;
            case 3:
                printf("Very nice - You just won $%d\n", questionReward);
                break;
            case 4:
                printf("Proud of you - You just won $%d\n", questionReward);
                break;
            }

            // Output transition to next question
            if (questionNum < 7)
            {
                printf("Let us play the next question now\n\n");
            }
        }
        // Runs if final answer was incorrect
        else
        {
            // Calculate question reward
            if (questionNum == 1)
            {
                questionReward = 0;
            }
            else if (questionNum % 2 == 0)
            {
                questionReward /= 5;
            }
            else
            {
                questionReward /= 2;
            }

            // Output concluding messages
            printf("\nOops - that was incorrect. You still won $%d. Well done.\n\n", questionReward);
            printf("It was fun playing with you.\n");

            break;
        }
    }
    return 0;
}