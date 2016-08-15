
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
#include "shared.h"

#define CENTRE_SIZE 2
#define INDEX_WIDTH 3
#define STARTING_ROW 1
#define DISPLAY_WIDTH (BOARD_WIDTH * COLUMN_WIDTH) + INDEX_WIDTH
#define ARRAY_OFFSET 1

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


    /*Set all values to 0*/
    for (i = 0; i < BOARD_HEIGHT; i++) {
        for (j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = BLANK;
        }
    }

    k = 0;
    for (i = BOARD_WIDTH/2; i < BOARD_WIDTH/2 + CENTRE_SIZE; i++) {

        for (j = BOARD_HEIGHT/2; j < BOARD_HEIGHT/2 + CENTRE_SIZE; j ++) {
            if (isEven(k) == TRUE) {
                board[i-ARRAY_OFFSET][j-ARRAY_OFFSET] = RED;
            } else {
                board[i-ARRAY_OFFSET][j-ARRAY_OFFSET] = BLUE;
            }
            k++;
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
    int i, j, k, row;
    enum cell current;
    /*print top rows*/
    printf("Other Player:\n");
    if(second->token == RED){
        printf("Name: %-20s  Score: %4d  Token Color %s 0 %s\n",second->name,second->score,COLOR_RED,COLOR_RESET);
    }else{
        printf("Name: %-20s  Score: %4d  Token Color %s 0 %s\n",second->name,second->score,COLOR_BLUE,COLOR_RESET);
    }
    for (i = 0; i <= (DISPLAY_WIDTH + NAMELEN); i++) {
        printf("=");
    }
    printf("\n");
    printf("Current Player:\n");
    if(first->token == RED){
        printf("Name: %-20s  Score: %4d  Token Color %s 0 %s\n",first->name,first->score,COLOR_RED,COLOR_RESET);
    }else{
        printf("Name: %-20s  Score: %4d  Token Color %s 0 %s\n",first->name,first->score,COLOR_BLUE,COLOR_RESET);
    }
    for (i = 0; i <= (DISPLAY_WIDTH + NAMELEN); i++) {
        printf("=");
    }
    printf("\n");

    for (i = 0; i <= INDEX_WIDTH; i++) {
        printf(" ");
    }
    for (i = 1; i <= BOARD_WIDTH; i++) {
        printf(" %d  ", i);
    }
    printf("\n");
    for (i = 0; i <= DISPLAY_WIDTH; i++) {
        printf("=");
    }

    row = STARTING_ROW;
    /*Print board*/
    for (i = 0; i < BOARD_HEIGHT; i++) {
        printf("\n %d |", row);
        for (j = 0; j < BOARD_WIDTH; j++) {
            current = board[j][i];
            if (current == RED) {
                printf("%s 0 %s|", COLOR_RED, COLOR_RESET);
            } else if (current == BLUE) {
                printf("%s 0 %s|", COLOR_BLUE, COLOR_RESET);
            } else {
                printf("   |");
            }
        }
        printf("\n");
        for (k = 0; k <= DISPLAY_WIDTH; k++) {
            printf("-");
        }

        row++;
    }
    printf("\n");
    for (i = 0; i <= DISPLAY_WIDTH; i++) {
        printf("=");
    }
    printf("\n");

}

