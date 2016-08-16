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
    struct player temp;
    strcpy(temp.name, "Name");
    temp.score = 0;
    temp.token = BLANK;
    printf("%s %d",temp.name,temp.score);
    for (i = 0; i < MAX_SCORES; i++) {

        scores[i] = temp;

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
    printf("=== SCOREBOARD ===\n==================\n");
    for (i = 0; i < MAX_SCORES; i++) {
        if (scores[i].score!=0) {
            printf("|%-20s | %2d |\n\n", scores[i].name, scores[i].score);
        }
    }
}
