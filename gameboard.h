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

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

/* forwards declaration of a struct player. This means that the compiler knows
 * that such a datastructure will be available but it does not what it contains
 * and so we can have pointers to a player but we don't know how big it is or 
 * what it contains.
 */
struct player;
/* all the directions that we can capture pieces in leaving from this direction
 */
enum direction {
    NORTH, SOUTH, EAST, WEST, NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST
};
/* How many directions are there */
#define NUM_DIRS 8
/* Height of the gameboard in number of cells */
#define BOARD_HEIGHT 8
/* Width of the game board in cells */
#define BOARD_WIDTH BOARD_HEIGHT
/* Size of the central staring square */
#define CENTRE_SIZE 2

/** For display purposes **/
/* Number of chars needed to display a column */
#define COLUMN_WIDTH 4
/* Width of the left hand row index in chars */
#define INDEX_WIDTH 3
/* The starting row of the gameboard */
#define STARTING_ROW 1
/* Total width of the board in chars */
#define DISPLAY_WIDTH (BOARD_WIDTH * COLUMN_WIDTH) + INDEX_WIDTH

/* The offset between displayed dimensions and positions in the array */
#define ARRAY_OFFSET 1

/* type definition of a game_board. It is just a 2-dimensional array*/
typedef enum cell game_board[BOARD_HEIGHT][BOARD_WIDTH];

/* Initialises all positions on the board to be BLANK */
void init_game_board(game_board board);

/* Displays the board, some info about the players and calculates whether
 * there are any possible moves. The first player passed to it is assumed to
 * be the current player
 */
void display_board(game_board board, struct player *human,
                   struct player *computer);

/** Prints character char for length times and a newline at the end **/
void print_divider(char character,int length);

void print_player_info(struct player *printme);


#endif /* ifndef GAMEBOARD_H */
