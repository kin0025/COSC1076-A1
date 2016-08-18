/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alexander Chi-Cheng Kinross-Smith
 * Student Number   : s3603437
 * Course Code      : COSC1076
 * Program Code     : BH094
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include "shared.h"
#include "gameboard.h"
#include "utility.h"

#ifndef PLAYER_H
#define PLAYER_H

/* the maximum length of a player name */
#define NAMELEN 20

/* Maximum number of chars for a score (8*8 = 64, so 2) */
#define SCORELEN 2

/* The score each player is initialised with */
#define INITIAL_SCORE 0

/* The delimiter for coordinates */
#define COORD_DELIMS ","

/* what are the attributes of a player? They have a name, a token (either BLUE
 * or RED), and a score
 */
struct player {
    char name[NAMELEN + EXTRACHARS];
    enum cell token;
    unsigned score;
};

/* Initialises the first player, asks for their name and sets their token
 * randomly. Returns FALSE if the player elects to quit.
 */
BOOLEAN init_first_player(struct player *human, enum cell *token);

/* Initialises the second player, asks for their name and sets their token to
 * the opposite of token. Returns FALSE if the player elects to quit.
 */
BOOLEAN init_second_player(struct player *computer, enum cell token);

/* Requests input for the move from the player. Validates the move and loops
 * until a valid move is found. Returns FALSE if the player elects to quit.
 */
BOOLEAN make_move(struct player *player, game_board board);

#endif /* ifndef PLAYER_H */
