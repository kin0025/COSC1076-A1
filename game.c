/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alexander Chi-Cheng Kinross-Smith
 * Student Number   : s3603437
 * Course Code      : COSC1076
 * Program Code     : BH094
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include "game.h"

/**
 * The heart of the game itself. You should do ALL initialisation required 
 * for the game in here or call function required for that purpose. For example
 * both players should be initialised from here, you should seed the random 
 * number generator, that kind of thing. 
 *
 * Next, you should set the initial player - the initial player is the player 
 * whose token was set by initialisation to RED. 
 *
 * Next, you will need to manage the game loop in here. In each loop of the 
 * game, you should display the game board, including player scores 
 * display whose turn it is, etc in the format specified in the assignment
 * specification. Finally at the end of each turn you will calculate the score 
 * for each player you will calculate their score and store it and then you 
 * will need to swap the current player and other player 
 * using the swap_player() function. 
 * 
 * A game will end when either player presses enter or ctrl-d on a newline. 
 * 
 * When you detect a request to end the game, you should do a final calculation
 * of the scores for the two players and return the player with the highest
 * score.
 *
 **/
struct player *play_game(struct player *first, struct player *second) {
   game_board board;
   enum cell token;
   struct player *current, *other, *winner;
   BOOLEAN quitting;
   srand(time(NULL));

   /* Initialise players and check if they want to quit */
   if (!init_first_player(first, &token) ||
       !init_second_player(second, first->token)) {
      printf("Quitting Game and returning to menu \n \n");
      return NULL;
   }

   /* Initialise gameboard and scores for players */
   init_game_board(board);

   calculate_player_scores(first, second, board);

   /* Set the current and other player */
   current = first;
   other = second;

   /* Swap the players so that the current player is a red token */
   if (current->token == BLUE) {
      swap_players(&current, &other);
   }

   /* Run the play loop */
   while (!quitting) {
      /* Display the game board */
      display_board(board, current, other);

      /* If a player somehow has no pieces tell them they should concede */
      if (current->score == 0) {
         /* This may be impossible */
         printf("%s You currently have no tokens on the board and it is "
                        "impossible to win. %s\n",
                MENU_COLOUR,
                COLOR_RESET);
      }

      /* If the board is full tell them that if they somehow don't know */
      if (current->score + other->score == 64) {
         printf("There are no blank squares. The game is over. Press enter to "
                        "see who has won!\n");
      }
      /* Make the current player's move, and if they choose to concede then
       * quit */
      if (!make_move(current, board)) {
         printf("Quitting Game and returning to menu \n \n");
         quitting = TRUE;
      }

      /* Swap players and calculate scores at the end of the turn */
      swap_players(&current, &other);


      calculate_player_scores(first, second, board);
   }

   /* Once they choose to quit, recalculate scores again, tell them who won
    * and return the winner */

   calculate_player_scores(first, second, board);

   if (first->score > second->score) {
      winner = first;
   } else if (second->score > first->score) {
      winner = second;
   } else {
      printf("The game was a draw! No one was added to scoreboard.\n");
      winner = NULL;
   }
   if (winner != NULL) {
      printf("%s won! Congratulations\n", winner->name);
   }
   return winner;
}

/**
 * does the work of applying the move requested by the user to the game board.
 * It iterates over all the directions from the coordinate specified to see
 * whether there are any pieces that can be captured. If there are no pieces
 * that can be captured in any direction, it is an invalid move.
 * At this point just a wrapper function to check move, as we were not able
 * to  modify function specifications.
 **/
BOOLEAN
apply_move(game_board board, unsigned y, unsigned x, enum cell player_token) {
   if (check_move(board, x, y, player_token, TRUE) > 0) {
      return TRUE;
   } else {
      return FALSE;
   }
}

int
check_move(game_board board, unsigned x, unsigned y, enum cell player_token,
           BOOLEAN apply_changes) {

   /* The direction currently been searched */
   enum direction current_dir = 0;
   /* The number of captured pieces total, and number captured in current
    * direction respectively */
   unsigned captured_pieces = 0, captured_dir = 0;

   /* The coordinates been examined during iteration */
   int xa, ya;

   /* An array of the values that get added to coordinates during iteration.
    * Changes based on direction */
   int adder_amount[2];

   /* Whether there are more squares in the current direction */
   BOOLEAN more_squares = TRUE;

   enum cell other_token;

   /* Set the types of tokens we are looking for */
   if (player_token == BLUE) {
      other_token = RED;
   } else {
      other_token = BLUE;
   }

   /* If the current position already has a token on it return false */
   if (board[x][y] != BLANK) {
      return FALSE;
   }

   /* Iterate through all possible directions */
   for (current_dir = 0; current_dir < NUM_DIRS; current_dir++) {

      more_squares = TRUE;
      captured_dir = 0;

      /* Set the values to add to the coords each iteration based on direction*/
      switch (current_dir) {
         case NORTH:
            adder_amount[0] = 0;
            adder_amount[1] = -1;
            break;
         case SOUTH:
            adder_amount[0] = 0;
            adder_amount[1] = 1;
            break;
         case EAST:
            adder_amount[0] = 1;
            adder_amount[1] = 0;
            break;
         case WEST:
            adder_amount[0] = -1;
            adder_amount[1] = 0;
            break;
         case NORTH_WEST:
            adder_amount[0] = -1;
            adder_amount[1] = -1;
            break;
         case NORTH_EAST:
            adder_amount[0] = 1;
            adder_amount[1] = -1;
            break;
         case SOUTH_WEST:
            adder_amount[0] = -1;
            adder_amount[1] = 1;
            break;
         case SOUTH_EAST:
            adder_amount[0] = 1;
            adder_amount[1] = 1;
            break;
         default:
            adder_amount[0] = 0;
            adder_amount[1] = 0;
      }

      /*Set the initial values of the coordinates */
      xa = x;
      ya = y;

      /* Iterate till we get to the first blank cell, or the first cell of same
       * colour, or exceed bounds of board */
      while (more_squares) {
         /* Check if the current iteration will exceed bounds of board and break
          * loop if they do */
         if (x + adder_amount[0] < 0 || y + adder_amount[1] < 0 ||
             x + adder_amount[0] > 7 ||
             y + adder_amount[1] > 7) {
            /*printf("Would have exceeded bounds, skipping operation %d %d\n",
                   xa + adder_amount[0], ya + adder_amount[1]);*/
            break;
         }

         /* Adjust the coordinates based on current_dir */
         xa += adder_amount[0];
         ya += adder_amount[1];

         /* Check if the current square is the other players token. If it is,
          * keep moving.
          * If it is our token then iterate back until we reach our
          * token, replacing every cell with current player's token.
          * If we didn't capture anything (the cell was our immediate neighbour)
          * then don't capture the user selected token
          * If it is blank then the direction is invalid.
          */
         if (board[xa][ya] == other_token) {
            more_squares = TRUE;
         } else if (board[xa][ya] == player_token) {
            more_squares = FALSE;
            /*Move back to the last token that wasn't the current player's*/
            xa -= adder_amount[0];
            ya -= adder_amount[1];
            /* Loop through all the tokens until we reach the original */
            while (xa != x || ya != y) {
               /* Set each token to the player's token if apply changes
                * is true*/
               if (apply_changes) {
                  board[xa][ya] = player_token;
               }
               /* Increment the number of tokens captured this direction,
                * and captured total */
               captured_pieces++;
               captured_dir++;
               /* Move back to the next token */
               xa -= adder_amount[0];
               ya -= adder_amount[1];
            }
            /* If there were tokens captured this time, the move was valid.
             * Set the initial token to the current player's token */
            if (captured_dir > 0 && apply_changes) {
               board[x][y] = player_token;
            }
         } else {
            /* If it wasn't either player's token then it must be blank.
             * Don't iterate any further */
            more_squares = FALSE;
         }
      }/*End While */
   }/* End For */

   /* If we captured pieces it was a valid move and return true.
    * Otherwise return false */
   return captured_pieces;

}

/**
 * simply count up how many locations contain the player_token 
 * specified on the game_board.
 **/
unsigned game_score(game_board board, enum cell player_token) {
   int x, y, total = 0;
   /* Iterate through x and y coordinates */
   for (x = 0; x < BOARD_WIDTH; x++) {
      for (y = 0; y < BOARD_HEIGHT; y++) {
         /* If the cell is set to a player token, then increment the total */
         if (board[y][x] == player_token) {
            total++;
         }
      }
   }
   return total;
}

/**
 * swap the two player pointers passed in so that first points to the player
 * pointer that originally contained the second player and vice versa.
 **/
void swap_players(struct player **first, struct player **second) {
   struct player *temp;
   temp = *first;
   *first = *second;
   *second = temp;
}

void calculate_player_scores(struct player *player1, struct player *player2,
                             game_board board) {
   player1->score = game_score(board, player1->token);
   player2->score = game_score(board, player2->token);
}


/***************** SPECIAL COMPUTER FUNCTIONALITY *************************/



struct player *play_sp(struct player *real_human, struct player *computer) {
   game_board board;
   enum cell token;
   struct player *winner;
   BOOLEAN quitting;
   srand(time(NULL));

   /* Initialise players and check if they want to quit */
   if (!init_first_player(real_human, &token)) {
      printf("Quitting Game and returning to menu \n \n");
      return NULL;
   }
   printf("This is the computer player. Set their name below\n");
   if (!init_second_player(computer, real_human->token)) {
      printf("Quitting Game and returning to menu \n \n");
      return NULL;
   }

   /* Initialise gameboard and scores for players */
   init_game_board(board);

   calculate_player_scores(real_human, computer, board);

   /* Run the play loop */
   while (!quitting) {
      if (computer->token == RED) {
         display_board(board, computer, real_human);
         quitting = !ai_move(computer, board);
      }

      /* Display the game board */
      display_board(board, real_human, computer);

      /* If a player somehow has no pieces tell them they should concede */
      if (real_human->score == 0) {
         /* This may be impossible */
         printf("%s You currently have no tokens on the board and it is "
                        "impossible to win. %s\n",
                MENU_COLOUR,
                COLOR_RESET);
      }

      /* If the board is full tell them that if they somehow don't know */
      if (real_human->score + computer->score == 64) {
         printf("There are no blank squares. The game is over. Press enter to "
                        "see who has won!\n");
      }

      /* Make the current player's move, and if they choose to concede then
       * quit */
      if (!make_move(real_human, board)) {
         printf("Quitting Game and returning to menu \n \n");
         quitting = TRUE;
      }

      if (!quitting) {
         display_board(board, computer, real_human);
         quitting = !ai_move(computer, board);
      }

      calculate_player_scores(real_human, computer, board);
   }

   /* Once they choose to quit, recalculate scores again, tell them who won
    * and return the winner */
   calculate_player_scores(real_human, computer, board);


   if (real_human->score > computer->score) {
      winner = real_human;
      printf("%s won! Congratulations\n", winner->name);
   } else if (computer->score > real_human->score) {
      winner = computer;
      printf("%s won! Try again\n", winner->name);
   } else {
      printf("The game was a draw! No one was added to scoreboard.\n");
      winner = NULL;
   }
   if (winner != NULL) {
   }
   return winner;
}


/** Runs a move as the ai. Follows no strategy but picking the move that nets
 *  it the most pieces. Returns false if it finds no moves to make.
 */
BOOLEAN ai_move(struct player *computer, game_board board) {
   /* The coordinates entered, number of times user has been prompted for input
    * and a loop incrementer */
   struct cell_ai cells[BOARD_HEIGHT * BOARD_WIDTH], temp;
   int runs, x, y;
   BOOLEAN made_move = TRUE;

   for (x = 0; x < BOARD_HEIGHT * BOARD_WIDTH; x++) {
      cells[x] = temp;
   }

   /* Print the user we are prompting for input */
   if (computer->token == BLUE) {
      printf("It is %s %s's (Computer) %s turn:\n", COLOR_BLUE, computer->name,
             COLOR_RESET);
   } else {
      printf("It is %s %s's (Computer) %s turn\n", COLOR_RED, computer->name,
             COLOR_RESET);
   }
   printf("Enter a set of values in the format x , y where you want to place"
                  " your piece:\n");

   for (x = 0; x < BOARD_WIDTH; x++) {
      for (y = 0; y < BOARD_HEIGHT; y++) {

         printf("Finding valid moves %d %d\n", x, y);
         printf("Position %d\n", calculate_x_y(x, y));
         cells[calculate_x_y(x, y)].value = check_move(board, x, y,
                                                       computer->token, FALSE);
         cells[calculate_x_y(x, y)].x = x;
         cells[calculate_x_y(x, y)].y = y;

         printf("Value %d", cells[calculate_x_y(x, y)].value);

      }
   }

   qsort(cells, BOARD_WIDTH * BOARD_HEIGHT, sizeof(struct cell_ai),
         sort_compare);

   runs = BOARD_HEIGHT * BOARD_WIDTH - ARRAY_OFFSET;


   do {
      made_move = check_move(board, cells[runs].x, cells[runs].y,
                             computer->token, TRUE);
      runs--;
   } while (!made_move && runs >= 0);
   printf("%d,%d", cells[runs].x, cells[runs].y);
   return made_move;
}

int calculate_x_y(int x, int y) {
   return (x * BOARD_WIDTH + y);
}

int sort_compare(const void *a1, const void *a2) {
   const struct cell_ai *element1 = a1;
   const struct cell_ai *element2 = a2;
   if (element1->value < element2->value) {
      return -1;
   } else if (element1->value > element2->value) {
      return 1;
   } else {
      return 0;
   }

}