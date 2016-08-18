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
   int i, x, y, row, potential_moves = 0;
   enum cell current;
   /*print top info rows*/
   printf("Other Player:\n");
   print_player_info(second);

   printf("Current Player:\n");
   /* Do the same as for the other player */
   print_player_info(first);

   /* Print spaces to account for the index on the left hand side */
    for(i= 0; i<INDEX_WIDTH;i++){
       printf(" ");
    }


   /* Print the top row of numbers with spacing */
   for (i = 1; i <= BOARD_WIDTH; i++) {
      printf(" %d  ", i);
   }
   printf("\n");


   print_divider('=',DISPLAY_WIDTH);

   row = STARTING_ROW;
   /*Print board*/
   /* Iterate through all the y values/rows */
   for (y = 0; y < BOARD_HEIGHT; y++) {
      /* Print the row number and a spacer */
      printf(" %d |", row);

      /* Iterate through all the columns for this row */
      for (x = 0; x < BOARD_WIDTH; x++) {
         /*Print the token based on its value*/
         current = board[x][y];
         if (current == RED) {
            printf("%s 0 %s|", COLOR_RED, COLOR_RESET);
         } else if (current == BLUE) {
            printf("%s 0 %s|", COLOR_BLUE, COLOR_RESET);
         } else if (check_move(board, x, y, first->token, FALSE)) {
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
      print_divider('-',DISPLAY_WIDTH);


      row++;
   }
   /* Print the board end */
   print_divider('=',DISPLAY_WIDTH);

   if (potential_moves == 0) {
      printf("%s NO POSSIBLE MOVES %s", MENU_COLOUR, COLOR_RESET);
   }

}

void print_player_info(struct player *printme) {
   /* Print the other player's name, score and token colour - if they both have
 * the same name they still know who's turn it is*/
   if (printme->token == RED) {
      printf("Name: %-*s  Score: %*d  Token Color %s 0 %s\n", NAMELEN,
             printme->name, SCORELEN, printme->score, COLOR_RED, COLOR_RESET);
   } else {
      printf("Name: %-*s  Score: %*d  Token Color %s 0 %s\n", NAMELEN,
             printme->name, SCORELEN, printme->score, COLOR_BLUE, COLOR_RESET);
   }

   /* Print a border */
   print_divider('=',DISPLAY_WIDTH+NAMELEN);
}

/** Prints character char for length times and a newline at the end **/
void print_divider(char character,int length){
   int i;
   for (i = 0; i <= length; i++) {
      printf("%c",character);
   }
   printf("\n");
}