/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alexander Chi-Cheng Kinross-Smith
 * Student Number   : s3603437
 * Course Code      : COSC1076
 * Program Code     : BH094
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include "player.h"
#include "game.h"


/**
 * These two functions initialise the player structure at the beginning of the 
 * game. In both cases, you should initialise the whole structure to known safe
 * values and then prompt the user for their name. In the init_first_player() 
 * function you should then select a color at random for this player using the 
 * rand() function. This token should be assigned to the first player's token
 * and also returned via the token pointer. In init_second_player() you should
 * just test the value of token and assign the opposite color to the second
 * player.
 **/
BOOLEAN init_first_player(struct player *first, enum cell *token) {
   /* A random number between 0 and 1 */
   int r = rand() % 2;

   /* Set a default name */
   strcpy(first->name, "Player 1");

   /* Request a real name */
   printf("Please enter a name for player 1: ");

   /* Get name input. If the user elects to quit, return false */
   if (!read_game_input(first->name, NAMELEN)) {
      return FALSE;
   }

   /* Set the users score to initial value */
   first->score = INITIAL_SCORE;

   /* Set the token based on the random number */
   if (r > 0) {
      *token = BLUE;
   } else {
      *token = RED;
   }
   first->token = *token;

   return TRUE;
}

BOOLEAN init_second_player(struct player *second, enum cell token) {

   /* Set a default name */
   strcpy(second->name, "Player 2");
   printf("Please enter a name for player 2: ");

   /* Get name input. If the user elects to quit, return false */
   if (!read_game_input(second->name, NAMELEN)) {
      return FALSE;
   }

   /* Set the score to initial value */
   second->score = INITIAL_SCORE;

   /* Set the token to the opposite of the one passed in */
   if (token == RED) {
      second->token = BLUE;
   } else {
      second->token = RED;
   }

   return TRUE;
}

/**
 * prompts the user for a comma-separate pair of coordinates for a move in the
 * game. Each move, if valid, must capture at least one enemy piece by 
 * surrounding a sequence of one or more enemy pieces with two pieces of our 
 * own: one being the new piece to be placed and the other a piece already 
 * on the board. This function then validates that a valid move has been entered
 * calls the apply_move function to do the actual work of capturing pieces.
 **/
BOOLEAN make_move(struct player *human, game_board board) {
   /* The input we get from the user */
   char input[COORDS_LEN + EXTRACHARS];
   char *token = NULL;
   /* The coordinates entered, number of times user has been prompted for input
    * and a loop incrementer */
   int x[NUM_DIMS] = {0, 0}, runs = 0, z;
   char *ptr = NULL;
   BOOLEAN input_valid = TRUE;

   /* Print the user we are prompting for input */
   if (human->token == BLUE) {
      printf("It is %s %s's %s turn:\n", COLOR_BLUE, human->name, COLOR_RESET);
   } else {
      printf("It is %s %s's %s turn\n", COLOR_RED, human->name, COLOR_RESET);
   }
   printf("Enter a set of values in the format x , y where you want to place"
                  " your piece:\n");

   /* Run until we get a valid input that is a valid move */
   do {
      /* If the input entered previously was valid and it is not their first
       * move, prompt them for another one */
      if (runs > 0 && input_valid == TRUE) {
         printf("Invalid Move. Please try again:\n");
      }

      /* Check for input. If they elect to quit, quit */
      if (!read_game_input(input, COORDS_LEN)) {
         return FALSE;
      }

      /* Tokenize the input and enter it into an array*/
      token = strtok(input, COORD_DELIMS);
      z = 0;
      while (token != NULL) {
         x[z] = (int) strtol(token, &ptr, BASE) - ARRAY_OFFSET;
         z++;
         token = strtok(NULL, COORD_DELIMS);
      }
      /* If there were not 2 tokens received, or the input is out of bounds,
       * set the input_valid variable to false and try again */
      if (z != 2 || x[0] > BOARD_WIDTH - ARRAY_OFFSET ||
          x[1] > BOARD_HEIGHT - ARRAY_OFFSET || x[0] < 0 || x[1] < 0) {
         printf("Invalid co-ordinates provided, please try again.\n");
         /* We have to prevent the second statement from running , so add a
          * first statement that will be false*/
         input_valid = FALSE;
      } else {
         /* Increment the number of times false input has been provided */
         runs++;
         /* if we passed the previous test input is valid, so run the second
          * condition */
         input_valid = TRUE;
      }
      /* Apply move and input valid both have to return true to break the loop*/

   } while (!(input_valid &&
              apply_move(board, x[1], x[0], human->token, TRUE)));
   return TRUE;
}
