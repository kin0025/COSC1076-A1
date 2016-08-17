/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alexander Chi-Cheng Kinross-Smith
 * Student Number   : s3603437
 * Course Code      : COSC1076
 * Program Code     : BH094
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include "gameboard.h"
#include "player.h"
#include "shared.h"
#include "game.h"

/**
 * initialise the game board to be consistent with the screenshot provided
 * in your assignment specification. 
 *
 * All squares should be initialised to be blank other than the four
 * squares in the middle of the board. In that case they are initialised to 
 * appropriate colored tokens
 **/
void init_game_board(game_board board) {
   int i, j, tiles_added;


   /*Set all values to BLANK - iterate through all x coords*/
   for (i = 0; i < BOARD_HEIGHT; i++) {
      /* Iterate through all y coords */
      for (j = 0; j < BOARD_WIDTH; j++) {
         /* Set the current coord to blank */
         board[i][j] = BLANK;
      }
   }

   /* Set the central grid of size CENTRE_SIZE to an alternating RED BLUE
    * layout */
   tiles_added = 0;
   /* Iterate through the central x coords */
   for (i = BOARD_WIDTH / 2; i < BOARD_WIDTH / 2 + CENTRE_SIZE; i++) {
      /* Iterate through all the central y coords */
      for (j = BOARD_HEIGHT / 2; j < BOARD_HEIGHT / 2 + CENTRE_SIZE; j++) {
         /* If the current coord is an even tile added set it to red,
          * otherwise set it to blue */
         if (isEven(tiles_added) == TRUE) {
            board[i - ARRAY_OFFSET][j - ARRAY_OFFSET] = RED;
         } else {
            board[i - ARRAY_OFFSET][j - ARRAY_OFFSET] = BLUE;
         }
         /* Increment number of tiles added every x and y position moved*/
         tiles_added++;
      }
      tiles_added++;
   }
}

/**
 * display the board as specified in the assignment specification. You should 
 * make every effort to create a board consistent with the screenshots in the 
 * assignment specification. 
 **/
void
display_board(game_board board, struct player *first, struct player *second) {
   int i, j, k, row, potential_moves = 0;
   enum cell current;
   /*print top info rows*/
   printf("Other Player:\n");

   /* Print the other player's name, score and token colour - if they both have
    * the same name they still know who's turn it is*/
   if (second->token == RED) {
      printf("Name: %-20s  Score: %2d  Token Color %s 0 %s\n", second->name,
             second->score, COLOR_RED, COLOR_RESET);
   } else {
      printf("Name: %-20s  Score: %2d  Token Color %s 0 %s\n", second->name,
             second->score, COLOR_BLUE, COLOR_RESET);
   }
   /* Print a border */
   for (i = 0; i <= (DISPLAY_WIDTH + NAMELEN); i++) {
      printf("=");
   }
   printf("\n");
   printf("Current Player:\n");
   /* Do the same as for the other player */
   if (first->token == RED) {
      printf("Name: %-20s  Score: %2d  Token Color %s 0 %s\n", first->name,
             first->score, COLOR_RED, COLOR_RESET);
   } else {
      printf("Name: %-20s  Score: %2d  Token Color %s 0 %s\n", first->name,
             first->score, COLOR_BLUE, COLOR_RESET);
   }
   for (i = 0; i <= (DISPLAY_WIDTH + NAMELEN); i++) {
      printf("=");
   }
   printf("\n");

   /* Print spaces to account for the index on the left hand side */
   for (i = 0; i <= INDEX_WIDTH; i++) {
      printf(" ");
   }
   /* Print the top row of numbers with spacing */
   for (i = 1; i <= BOARD_WIDTH; i++) {
      printf(" %d  ", i);
   }
   printf("\n");

   for (i = 0; i <= DISPLAY_WIDTH; i++) {
      printf("=");
   }

   row = STARTING_ROW;
   /*Print board*/
   /* Iterate through all the y values/rows */
   for (i = 0; i < BOARD_HEIGHT; i++) {
      /* Print the row number and a spacer */
      printf("\n %d |", row);

      /* Iterate through all the columns for this row */
      for (j = 0; j < BOARD_WIDTH; j++) {
         /*Print the token based on its value*/
         current = board[j][i];
         if (current == RED) {
            printf("%s 0 %s|", COLOR_RED, COLOR_RESET);
         } else if (current == BLUE) {
            printf("%s 0 %s|", COLOR_BLUE, COLOR_RESET);
         } else if (apply_move(board, i, j, first->token, FALSE)) {
            if (DISPLAY_MARKERS) {
               printf(" x |");
            } else {
               printf("   |");
            }
            potential_moves++;
         } else {
            printf("   |");
         }
      }
      printf("\n");

      /* Print the row divider */
      for (k = 0; k <= DISPLAY_WIDTH; k++) {
         printf("-");
      }

      row++;
   }
   printf("\n");

   /* Print the board end */
   for (i = 0; i <= DISPLAY_WIDTH; i++) {
      printf("=");
   }
   printf("\n");

   if (potential_moves == 0) {
      printf("%s NO POSSIBLE MOVES %s", MENU_COLOUR, COLOR_RESET);
   }

}

