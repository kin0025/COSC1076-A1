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
int apply_move(game_board board, unsigned y, unsigned x,
                   enum cell player_token, BOOLEAN apply_changes);

/* Calculates the number of tokens player_token on the board and returns them
 * as an unsigned integer. Does not modify the board
 */
unsigned game_score(game_board board, enum cell player_token);

/* Swaps the pointers of the first and second player */
void swap_players(struct player **first, struct player **second);

#endif /* ifndef GAME_H */
