/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alexander Chi-Cheng Kinross-Smith
 * Student Number   : s3603437
 * Course Code      : COSC1076
 * Program Code     : BH094
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include "reversi.h"

/**
 * the hear of the program. The main() function in particular should 
 * manage the main menu for the program.
 **/
int main(void)
{
    score scrboard[MAX_SCORES];
    struct player human, computer, *winner = NULL;
    /* initialise the scoreboard */
    
    /* in a loop: display the main menu */
    do{
        printf("Welcome to Reversi!\n");
        printf("================ \n");
        printf("Select and option: \n");
        printf("1. Play a game\n");
        printf("2. Display High Scores\n");
        printf("3. Quit the program\n");
        printf("Please enter your choice:");

    }while(&run == 0);
    
    /* get the user's selection from the main menu */

    /* perform the requested task */
            /* play a game and add the winner to the scoreboard */    
        
            /* display scores */
            /* quit the program */
    return EXIT_SUCCESS;
}

