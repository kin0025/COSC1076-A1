/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alexander Chi-Cheng Kinross-Smith
 * Student Number   : s3603437
 * Course Code      : COSC1076
 * Program Code     : BH094
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include <time.h>
#include "shared.h"
#include "player.h"
#include "gameboard.h"


#ifndef GAME_H
#define GAME_H

struct cell_ai {
    int value;
    unsigned x;
    unsigned y;
};


/* Core play game loop. Initialises both players passed to it, displays board
 * and calls move code.  Returns the winner of the game, or NULL if the game
 * was a draw.
 */
struct player *play_game(struct player *human, struct player *computer);

/* Applies the move. Receives the game board, and coordinates for the move,
 * and will attempt to apply them for the given token. Returns whether the
 * move was valid. If it returns true a move was applied
 */
BOOLEAN apply_move(game_board board, unsigned y, unsigned x,
                   enum cell player_token);

/*
 * What I wanted apply move to be, but couldn't add parameters/ change
 * function definition.
 */
int check_move(game_board board, unsigned y, unsigned x,
               enum cell player_token, BOOLEAN apply_changes);


/* Calculates the number of tokens player_token on the board and returns them
 * as an unsigned integer. Does not modify the board
 */
unsigned game_score(game_board board, enum cell player_token);

/* Swaps the pointers of the first and second player */
void swap_players(struct player **first, struct player **second);

/* Sets the scores of both players based on the gameboard */
void calculate_player_scores(struct player *player1,struct player *player2,
                             game_board board);

/***************** SPECIAL COMPUTER FUNCTIONALITY *************************/


/* For SinglePlayer Play */
struct player *play_sp(struct player *real_human, struct player *computer);

/* A function that makes a move on the AI's behalf */
BOOLEAN ai_move(struct player *computer, game_board board);


int calculate_x_y(int x, int y);


int sort_compare(const void *a1, const void *a2);


#endif /* ifndef GAME_H */
