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
   /* Create a player to fill array with */
   struct player temp;
   /* Populate the player */
   strcpy(temp.name, "");
   temp.score = 0;
   temp.token = BLANK;
   /* Fill all entries with the player */
   for (i = 0; i < MAX_SCORES; i++) {

      scores[i] = temp;

   }
}


/**
 * insert the top scorer from the last game played in sorted order according
 * to their score 
 **/
BOOLEAN add_to_scoreboard(score scores[MAX_SCORES], struct player *winner) {
   int i, x;
   BOOLEAN set_score = FALSE;

/* OLD Algorithm */
   /*
   if (winner->score <= scores[MAX_SCORES - ARRAY_OFFSET].score) {
      return FALSE;
   }
   scores[MAX_SCORES - ARRAY_OFFSET] = *winner;
   qsort(scores, MAX_SCORES, sizeof(struct player), score_compare);
   return TRUE;
*/

/* More efficient algorithm that doesn't need qsort? */
   i = 0;
   while (i < MAX_SCORES && !set_score) {
      if (score_compare(winner, &scores[i]) < 0) {
         for (x = MAX_SCORES - ARRAY_OFFSET; x > i; x--) {
            scores[x] = scores[x - ARRAY_OFFSET];
         }
         scores[x] = *winner;
         set_score = TRUE;
      }
      i++;
   }
   return set_score;

}

int score_compare(const void *score1, const void *score2) {
   const struct player *player1 = score1;
   const struct player *player2 = score2;

   /* Logically easier to read than return score2->score - score1->score and
    * less likely to go over INT_MAX, but we are using small numbers.
    */
   /*if (player2->score < player1->score) {
      return -1;
   } else if (player2->score > player1->score) {
      return 1;
   } else {
      return 0;
   }*/
   return (player2->score - player1->score);

}

/**
 * display the scores in the scoreboard according to their order. Your output
 * should match that provided in the assignment specification.
 **/
void display_scores(score scores[MAX_SCORES]) {
   int i;
   /* Print a pretty header */
   printf("\n=== %sSCOREBOARD%s ===\n==================\n", MENU_COLOUR,
          COLOR_RESET);

   print_divider('-', SCRBRD_WIDTH);

   printf("|Name                 |Score|\n");

   print_divider('-', SCRBRD_WIDTH);

   /* Loop through all the scoreboard entries and print them in a formatted
    * fashion */
   for (i = 0; i < MAX_SCORES; i++) {
      /* Print a score if it is not equal to 0. If the first score is equal to
       * zero, print a message */
      if (scores[i].score != 0) {
         printf("|%-*s | %*d  |\n", NAMELEN, scores[i].name, SCORELEN,
                scores[i].score);
      } else if (i == 0) {
         printf("No-one has won a game! Go play some games and check back.");
         break;
      }
   }
}
