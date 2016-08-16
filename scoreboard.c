/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alexander Chi-Cheng Kinross-Smith
 * Student Number   : s3603437
 * Course Code      : COSC1076
 * Program Code     : BH094
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include "scoreboard.h"

#define INITIAL_SCORE 0
#define SCRBRD_OFFSET 1

/**
 * initalise the scoreboard so that the scores for each element of the array
 * is set to 0.
 **/
void init_scoreboard(score scores[MAX_SCORES]) {
    int i;
    struct player player1;
    strcpy(player1.name, "");
    player1.score = INITIAL_SCORE;
    for (i = 0; i < MAX_SCORES; i++) {

        scores[i] = player1;

    }
}


/**
 * insert the top scorer from the last game played in sorted order according
 * to their score 
 **/
BOOLEAN add_to_scoreboard(score scores[MAX_SCORES], struct player *winner) {
    int i;
    for (i = 0; i < MAX_SCORES; i++) {
        scores[MAX_SCORES - INDEX_OFFSET - i] = scores[MAX_SCORES - INDEX_OFFSET - i - SCRBRD_OFFSET];
    }
    scores[0] = *winner;

    return TRUE;
}

/**
 * display the scores in the scoreboard according to their order. Your output
 * should match that provided in the assignment specification.
 **/
void display_scores(score scores[MAX_SCORES]) {
    int i;
    printf("=== SCOREBOARD ===\n ==================\n");
    for (i = 0; i < MAX_SCORES; i++) {
        if (strlen(scores[i].name)!=0) {
            printf("|%-20s | %4d | \n\n", scores[i].name, scores[i].score);
        }
    }
}
