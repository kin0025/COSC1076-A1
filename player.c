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

#define INITIAL_SCORE 0
#define DELIMS ","

/**
 * These two functions initialise the player structure at the beginning of the 
 * game. In both cases, you should initialise the whole structure to known safe
 * values and then prompt the user for their name. In the init_first_player() 
 * function you should then select a color at random for this player using the 
 * rand() function. This token should be assigned to the first player's token and
 * also returned via the token pointer. In init_second_player() you should just
 * test the value of token and assign the opposite color to the second player.
 **/
BOOLEAN init_first_player(struct player *first, enum cell *token) {
    char *name[NAMELEN + EXTRACHARS]="Player One";

    first->score = INITIAL_SCORE;
    first->name = name;
    if (rand() >= 0) {
        token = BLUE;
    } else {
        token = RED;
    }
    first->token = token;

    first->name = read_string();
}

BOOLEAN init_second_player(struct player *second, enum cell token) {
    second->score = INITIAL_SCORE;
    second->name = "Player One";
    if (token == RED) {
        token = BLUE;
    } else {
        token = RED;
    }
    second->token = token;

    second->name->read_string();
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
    char *input = NULL, *token = NULL;
    int x[], z;
    BOOLEAN run;
    printf("Enter a set of values in the format x , y where you want to place your piece");
    input = read_string();
    token = strtok(input, DELIMS);
    z = 0;
    while (run == TRUE) {
        while (token != null) {
            x[z] = (int) strtol(token);
            z++;
            token = strtok(NULL, DELIMS);
        }
        if (z >= 2) {
            printf("Extra co-ordinates provided, please try again.");
            run = TRUE;
        } else {
            run = FALSE;
        }
    }
    apply_move(board,x[1],x[2],human->token);
}
