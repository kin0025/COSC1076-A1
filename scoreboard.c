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
#define SCRBRD_WIDTH 29
/**
 * initalise the scoreboard so that the scores for each element of the array
 * is set to 0.
 **/
void init_scoreboard(score scores[MAX_SCORES]) {
    int i;
    struct player temp;
    strcpy(temp.name, "");
    temp.score = 0;
    temp.token = BLANK;
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
    printf("\n=== %sSCOREBOARD%s ===\n==================\n",MENU_COLOUR,COLOR_RESET);
    for(i=0;i<SCRBRD_WIDTH;i++){
        printf("-");
    }
    printf("\n|Name                 |Score|\n");
    for(i=0;i<SCRBRD_WIDTH;i++){
        printf("-");
    }
    printf("\n");
    for (i = 0; i < MAX_SCORES; i++) {
        if (scores[i].score!=0) {
            printf("|%-20s | %2d  |\n", scores[i].name, scores[i].score);
        }else if(i==0){
            printf("No-one has won a game! Go play some games and check back.");
            break;
        }
    }
}
