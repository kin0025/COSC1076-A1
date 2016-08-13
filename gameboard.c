
/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : EDIT HERE
 * Student Number   : EDIT HERE
 * Course Code      : EDIT HERE
 * Program Code     : EDIT HERE
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include "gameboard.h"
#include "player.h"

#define CENTRE_SIZE 2
#define DISPLAY_WIDTH BOARD_WIDTH+INDEX_WIDTH
#define INDEX_WIDTH 2

/**
 * initialise the game board to be consistent with the screenshot provided
 * in your assignment specification. 
 *
 * All squares should be initialised to be blank other than the four
 * squares in the middle of the board. In that case they are initialised to 
 * appropriate colored tokens
 **/
void init_game_board(game_board board) {
    int i, j, k;


    //Set all values to 0
    for (i = 0; i < BOARD_HEIGHT; i++) {
        for (j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = BLANK;
        }
    }

    k = 0;
    for (i = 0; i < CENTRE_SIZE; i++) {

        for (j = 0; j < CENTRE_SIZE; j += 2) {
            if (isEven(k)) {
                board[i][j] = RED;
            } else {
                board[i][j] = BLUE;
            }
        }
        k++;
    }
}

/**
 * display the board as specified in the assignment specification. You should 
 * make every effort to create a board consistent with the screenshots in the 
 * assignment specification. 
 **/
void display_board(game_board board, struct player *first, struct player *second) {
    int i, j, row;
    cell current;
    //print top rows
    for (i = 0; i < DISPLAY_WIDTH; i++) {
        if (i < INDEX_WIDTH) {
            printf(" ");
        } else {
            printf("%d ", i);
        }
    }
    for (i = 0; i < DISPLAY_WIDTH; i++) {
        printf("=");
    }
    //Print gameboard
    for (i = 0; i < BOARD_HEIGHT; i++) {
        printf("%d|",i);
        for (j = 0; j < BOARD_WIDTH; j++) {
            current = board[i][j];
            if (current == RED) {
                printf("%s 0 %s", COLOR_BLUE, COLOR_RESET);
            } else if (current == BLUE) {
                printf("%s 0 %s", COLOR_BLUE, COLOR_RESET);
            } else {
                printf(" ");
            }
            printf("|");
        }
        for(j = 0; j < DISPLAY_WIDTH; j++){
            printf("-");
        }
        printf("\n");
    }
}

