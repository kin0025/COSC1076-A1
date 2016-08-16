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
int main(void) {
    score scrboard[MAX_SCORES];
    struct player human, computer, *winner = NULL;
    int choice, run = TRUE;
    /* initialise the scoreboard */

    /* in a loop: display the main menu */
    do {
        printf("\nWelcome to Reversi!\n");
        printf("================ \n");
        printf("Select and option: \n");
        printf("1. Play a game\n");
        printf("2. Display High Scores\n");
        printf("3. Quit the program\n");
        printf("Please enter your choice:");

        /* get the user's selection from the main menu */
        choice = read_int();

        /* perform the requested task */
        switch (choice) {
            case -1:
                printf("Invalid choice");
                break;
                /* play a game and add the winner to the scoreboard */
            case 1:
                winner = play_game(&human, &computer);
                if (winner != NULL) {
                    add_to_scoreboard(scrboard, winner);
                }
                break;
            case 2:
                display_scores(scrboard);
                break;
            case 3:
                run = FALSE;
                break;
            default:
                printf("Invalid choice\n\n");
                break;
        }
    } while (run == TRUE);


    /* display scores */
    /* quit the program */
    return EXIT_SUCCESS;
}

