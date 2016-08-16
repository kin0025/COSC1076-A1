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
    int r = rand() % 2;
    strcpy(first->name, "Player 1");
    printf("Please enter a name for player 1: ");

    if (!read_game_input(first->name, NAMELEN)) {
        return FALSE;
    }


    first->score = INITIAL_SCORE;
    if (r > 0) {
        *token = BLUE;
    } else {
        *token = RED;
    }
    first->token = *token;

    return TRUE;
}

BOOLEAN init_second_player(struct player *second, enum cell token) {

    strcpy(second->name, "Player 2");
    printf("Please enter a name for player 2: ");


    if (!read_game_input(second->name, NAMELEN)) {
        return FALSE;
    }

    second->score = INITIAL_SCORE;
    if (token == RED) {
        token = BLUE;
    } else {
        token = RED;
    }
    second->token = token;
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
    char input[COORDS_LEN + EXTRACHARS];
    char *token = NULL;
    int x[NUM_DIMS] = {0, 0}, runs = 0,z;
    char *ptr = NULL;
    BOOLEAN run= TRUE;

    if (human->token == BLUE) {
        printf("It is %s %s's %s turn:\n", COLOR_BLUE, human->name, COLOR_RESET);
    } else {
        printf("It is %s %s's %s turn\n", COLOR_RED, human->name, COLOR_RESET);
    }
    printf("Enter a set of values in the format x , y where you want to place your piece:\n");

    do {
        if (runs > 0 && run == TRUE) {
            printf("Invalid Move. Please try again:\n");
        }

        if (!read_game_input(input, COORDS_LEN)) {
            return FALSE;
        }


        token = strtok(input, DELIMS);
        z = 0;
        while (token != NULL) {
            x[z] = (int)strtol(token, &ptr, BASE);
            z++;
            token = strtok(NULL, DELIMS);
        }
        if (z != 2) {
            printf("Invalid co-ordinates provided, please try again.\n");
            /* This will still pass us to the conditional, so we have to prevent the second statement from running */
            run = FALSE;
        }else {
            runs++;
            run = TRUE;
        }
    } while (!(run && apply_move(board, x[1], x[0], human->token)));
    return TRUE;
}
