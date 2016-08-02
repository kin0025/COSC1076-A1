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
 * rand() function. This token should be assigned to the first player's token and
 * also returned via the token pointer. In init_second_player() you should just
 * test the value of token and assign the opposite color to the second player.
 **/
BOOLEAN init_first_player(struct player* first, enum cell * token)
{
}

BOOLEAN init_second_player(struct player * second, enum cell token)
{
}

/**
 * prompts the user for a comma-separate pair of coordinates for a move in the
 * game. Each move, if valid, must capture at least one enemy piece by 
 * surrounding a sequence of one or more enemy pieces with two pieces of our 
 * own: one being the new piece to be placed and the other a piece already 
 * on the board. This function then validates that a valid move has been entered
 * calls the apply_move function to do the actual work of capturing pieces.
 **/
BOOLEAN make_move(struct player * human, game_board board)
{
}
