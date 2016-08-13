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
    bool quitting;

    init_first_player(first, BLUE);
    init_second_player(second, RED);
    init_game_board(board);

    current = &first;
    other = &second;

    if (other->token == RED) {
        swap_players();
    }
    do {
        display_board(board, current, other);
        make_move(current, board);

        swap_players(current, other);
        //Get quitting input
        if (input == "quit") {
            quitting = TRUE;
        }
    } while (!quitting);

    if (first->score >= second->score) {
        winner = &first;
    } else {
        winner = &second;
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
    enum direction *dir = {NORTH,SOUTH,EAST,WEST,NORTH_EAST,NORTH_WEST,SOUTH_EAST,SOUTH_WEST}, *current_dir = NULL;
    unsigned captured_pieces = 0;
    int i;
    int * examined_position[2]={x,y};
    bool more_squares = true;
    for(i=0;i<NUM_DIRS;i++){
        current_dir = dir[i];
        do{

        }while(more_squares);
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
}

/**
 * swap the two player pointers passed in so that first points to the player
 * pointer that originally contained the second player and vice versa.
 **/
void swap_players(struct player **first, struct player **second) {
    player *temp;
    temp = first;
    first = second;
    second = temp;
}
