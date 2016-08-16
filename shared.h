/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alexander Chi-Cheng Kinross-Smith
 * Student Number   : s3603437
 * Course Code      : COSC1076
 * Program Code     : BH094
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#ifndef SHARED_H
#define SHARED_H

/* definition of the boolean type */
typedef enum
{
        FALSE, TRUE
} BOOLEAN;

/* how many colors are their in the game? required by the random number 
 * generation
 */
#define NUM_COLORS 2


#define NULL_TERMINATOR '\0'

#define BASE 10

#define NUM_DIMS 2

#define INDEX_OFFSET 1

/* Length of the string we expect to receive as co-ordinates input */
#define COORDS_LEN 3
/* what values could be contained in a cell on the board? */
enum cell
{
        BLANK, RED, BLUE
};

/* color codes required to display the tokens on the board */
#define COLOR_RED     "\33[31m"
#define COLOR_BLUE    "\33[34m"
#define MENU_COLOUR   "\33[33m\33[41m"
#define COLOR_RESET   "\33[0m"
#define MAX_COLOR_LENGTH 7
#endif /* defined SHARED_H */
