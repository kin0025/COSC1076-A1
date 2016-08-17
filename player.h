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

BOOLEAN init_first_player(struct player *human, enum cell *token);

BOOLEAN init_second_player(struct player *computer, enum cell token);

BOOLEAN make_move(struct player *player, game_board board);

#endif /* ifndef PLAYER_H */
