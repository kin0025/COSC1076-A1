/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : EDIT HERE
 * Student Number   : EDIT HERE
 * Course Code      : EDIT HERE
 * Program Code     : EDIT HERE
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include "game.h"

/**
 * The heart of the game itself. You should do ALL initialisation required 
 * for the game in here or call function required for that purpose. For example
 * both players should be initialised from here, you should seed the random 
 * number generator, that kind of thing. 
 *
 * Next, you should set the initial player - the initial player is the player 
 * whose token was set by initialisation to RED. 
 *
 * Next, you will need to manage the game loop in here. In each loop of the 
 * game, you should display the game board, including player scores 
 * display whose turn it is, etc in the format specified in the assignment
 * specification. Finally at the end of each turn you will calculate the score 
 * for each player you will calculate their score and store it and then you 
 * will need to swap the current player and other player 
 * using the swap_player() function. 
 * 
 * A game will end when either player presses enter or ctrl-d on a newline. 
 * 
 * When you detect a request to end the game, you should do a final calculation
 * of the scores for the two players and return the player with the highest
 * score.
 **/
struct player *play_game(struct player *first, struct player *second) {
    game_board board;
    enum cell token;
    struct player *current, *other, *winner;
    BOOLEAN quitting;
    srand(time(NULL));

    if (!init_first_player(first, &token) || !init_second_player(second, first->token)) {
        printf("Quitting Game and returning to menu \n \n");
        return NULL;
    }

    init_game_board(board);
    first->score = game_score(board,first->token);
    second->score = game_score(board,second->token);
    current = first;
    other = second;

    if (current->token == BLUE) {
        swap_players(&current, &other);
    }

    while (!quitting) {
        display_board(board, current, other);
        if(current->score == 0){
            /* This may be impossible */
            printf("%s You currently have no tokens on the board and it is impossible to win. %s\n",MENU_COLOUR,COLOR_RESET);
        }
        if(current->score + other->score == 64){
            printf("There are no blank squares. The game is over. Press enter to see who has won!\n");
        }
        if (!make_move(current, board)) {
            printf("Quitting Game and returning to menu \n \n");
            quitting = TRUE;
        }

        swap_players(&current, &other);
        first->score = game_score(board,first->token);
        second->score = game_score(board,second->token);
    }
    first->score = game_score(board,first->token);
    second->score = game_score(board,second->token);


    if (first->score > second->score) {
        winner = first;
    }else if(second->score > first->score){
        winner = second;
    }
    else {
        printf("The game was a draw! No one was added to scoreboard.\n");
        winner = NULL;
    }
    if(winner!= NULL){
        printf("%s won! Congratulations\n",winner->name);
    }
    return winner;
}

/**
 * does the work of applying the move requested by the user to the game board.
 * It iterates over all the directions from the coordinate specified to see
 * whether there are any pieces that can be captured. If there are no pieces
 * that can be captured in any direction, it is an invalid move.
 **/
BOOLEAN apply_move(game_board board, unsigned y, unsigned x, enum cell player_token) {
    enum direction dir[NUM_DIRS] = {NORTH, SOUTH, EAST, WEST, NORTH_EAST, NORTH_WEST, SOUTH_EAST,
                                    SOUTH_WEST}, *current_dir = NULL;
    unsigned captured_pieces = 0, captured_dir = 0;
    int i, xa, ya;
    int adder_amount[2];
    BOOLEAN more_squares = TRUE;
    enum cell other_token;
    /* Moved to work with arrays */
    x--;
    y--;

    if (player_token == BLUE) {
        other_token = RED;
    } else {
        other_token = BLUE;
    }
    /** Iterate through all possible directions **/
    if(board[x][y] != BLANK){
        return FALSE;
    }

    for (i = 0; i < NUM_DIRS; i++) {
        more_squares = TRUE;
        current_dir = &dir[i];
        captured_dir = 0;
        switch (*current_dir) {
            case NORTH:
                adder_amount[0] = 0;
                adder_amount[1] = -1;
                 break;
            case SOUTH:
                adder_amount[0] = 0;
                adder_amount[1] = 1;break;
            case EAST:
                adder_amount[0] = 1;
                adder_amount[1] = 0;

                break;
            case WEST:
                adder_amount[0] = -1;
                adder_amount[1] = 0;
                break;
            case NORTH_WEST:
                adder_amount[0] = -1;
                adder_amount[1] = -1;
                break;
            case NORTH_EAST:
                adder_amount[0] = 1;
                adder_amount[1] = -1;
                break;
            case SOUTH_WEST:
                adder_amount[0] = -1;
                adder_amount[1] = 1;
                break;
            case SOUTH_EAST:
                adder_amount[0] = 1;
                adder_amount[1] = 1;
                break;
            default:
                adder_amount[0] = 0;
                adder_amount[1] = 0;
        }


            xa = x;
            ya = y;


        while (more_squares) {
            if (x + adder_amount[0] < 0 || y + adder_amount[1] < 0 || x + adder_amount[0] > 7 || y + adder_amount[1] > 7 ) {
                /*printf("Would have exceeded bounds, skipping operation %d %d\n", xa + adder_amount[0], ya + adder_amount[1]);*/
                break;
            }
                xa += adder_amount[0];
            ya += adder_amount[1];

            /* Iterate till we get to the first blank cell, or the first cell of same colour. */
            if (board[xa][ya] == other_token) {
                more_squares = TRUE;
            } else if (board[xa][ya] == player_token) {
                more_squares= FALSE;
                /*capture the pieces! */
                xa -= adder_amount[0];
                ya -= adder_amount[1];
                while (xa != x || ya != y) {
                    board[xa][ya] = player_token;
                    captured_pieces++;
                    captured_dir++;
                    xa -= adder_amount[0];
                    ya -= adder_amount[1];
                    }
                if(captured_dir > 0){
                    board[x][y] = player_token;
                }
            } else {
                more_squares = FALSE;
            }
        }
    }

    if (captured_pieces != 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * simply count up how many locations contain the player_token 
 * specified on the game_board.
 **/
unsigned game_score(game_board board, enum cell player_token) {
    int x, y, total = 0;
    for (x = 0; x < BOARD_WIDTH; x++) {
        for (y = 0; y < BOARD_HEIGHT; y++) {
            if (board[y][x] == player_token) {
                total++;
            }
        }
    }
    return total;
}

/**
 * swap the two player pointers passed in so that first points to the player
 * pointer that originally contained the second player and vice versa.
 **/
void swap_players(struct player **first, struct player **second) {
    struct player *temp;
    temp = *first;
    *first = *second;
    *second = temp;
}
