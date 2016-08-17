/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alexander Chi-Cheng Kinross-Smith
 * Student Number   : s3603437
 * Course Code      : COSC1076
 * Program Code     : BH094
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include "shared.h"
#include <limits.h>

#ifndef UTILITY_H
#define UTILITY_H

/* the default line length for input / output */
#define LINELEN 80

/* the last two characters required in a string as returned from fgets */
#define EXTRACHARS 2

/* newline character required for I/O functions */
#define NEWLINE '\n'

/* A value for errors */
#define ERROR_VALUE -1

/* Used to mod numbers to get whether they are even */
#define EVEN_NUM 2


void read_rest_of_line(void);

int read_int(void);

BOOLEAN read_game_input(char *buffer, int length);

BOOLEAN isEven(int input);

#endif /* ifndef UTILITY_H */
