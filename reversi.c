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
 * the heart of the program. The main() function in particular should 
 * manage the main menu for the program.
 **/
int main(void) {
   /* Create the scoreboard and players */
   score scrboard[MAX_SCORES];
   struct player human, computer, *winner = NULL;
   int choice, run = TRUE;

   /* initialise the scoreboard */
   init_scoreboard(scrboard);
   /* in a loop: display the main menu until the user elects to quit*/
   do {
      printf("\n\n%sWelcome to Reversi!%s\n", MENU_COLOUR, COLOR_RESET);
      printf("================ \n");
      printf("Select and option: \n");
      printf("1. Play a game\n");
      printf("2. Display High Scores\n");
      printf("3. Quit the program\n");
      if (ENABLE_SP) {
         printf("4. Play Against Computer\n");
      }
      printf("Please enter your choice: ");

      /* get the user's selection from the main menu */
      choice = read_int();

      /* perform the requested task */
      switch (choice) {
         case -1:
            printf("Invalid choice");
            break;
         case 1:
            /* play a game and add the winner to the scoreboard */

            winner = play_game(&human, &computer);
            if (winner != NULL) {
               if(!add_to_scoreboard(scrboard, winner)){
                  printf("Your score was not in the top 10.");
               }
            }
            break;
         case 2:
            /* display scores */
            display_scores(scrboard);
            break;
         case 3:
            /* quit the program */
            run = FALSE;
            break;
         case 4:
            if (ENABLE_SP) {
               /* play against ai */
               winner = play_sp(&human, &computer);
               if (winner != NULL) {
                  add_to_scoreboard(scrboard, winner);
               }
                  break;
            }
         default:
            /* If input is not one of the choices, inform the user and
             * loop back */
            printf("Invalid choice\n\n");
            break;
      }
   } while (run == TRUE);


   return EXIT_SUCCESS;
}

