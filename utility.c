/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alexander Chi-Cheng Kinross-Smith
 * Student Number   : s3603437
 * Course Code      : COSC1076
 * Program Code     : BH094
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * function required to be used when clearing the buffer. It simply reads
 * each char from the buffer until the buffer is empty again. Please refer
 * to the materials on string and buffer handling in the course for more 
 * information.
 **/
void read_rest_of_line(void) {
    int ch;
    while (ch = getc(stdin), ch != EOF && ch != NEWLINE);
    clearerr(stdin);
}

/** 
 * Function that reads integers from the terminal. Validates them, asks for 
 * input if errors encountered.
 **/
int read_int(void) {
    char buffer[LINELEN + EXTRACHARS];
    int output;
    char *ptr = NULL;
    BOOLEAN running = TRUE;
    do {
        /* read the input */
        fgets(buffer, LINELEN, stdin);
        /* check if we overflowed the buffer and fix it if we did*/
        if (buffer[strlen(buffer) - 1] != '\n') {
            read_rest_of_line();
            printf("Input too long, please try again\n");
            running = TRUE;
            continue;
        }
        /* Remove the extra null terminator */
        buffer[strlen(buffer) - 1] = NULL_TERMINATOR;

        /* Convert the remaining to integer */
        output = (int) strtol(buffer, &ptr, BASE);

        /* Check that the integer conversion went successfully */
        if (output == -1 || ptr == buffer) {
            printf("The input was not a parseable number.\n");
            running = TRUE;
        } else if (strlen(ptr) != 0) {
            printf("There was more than just a number entered, please try "
                           "again.\n");
            running = TRUE;
        } else {
            running = FALSE;
        }
    } while (running);
    return output;
}

BOOLEAN read_game_input(char *buffer, int length) {
    BOOLEAN overflow = FALSE;
    do {
        /* Check for EOF input and return false, recieve input */
        if (fgets(buffer, length + EXTRACHARS, stdin) == NULL) {
            return FALSE;
        }

        /* Check for overflow and deal with it */
        if (buffer[strlen(buffer) - 1] != '\n') {
            overflow = TRUE;
            /* Clear the overflow and prompt the user for input again */
            read_rest_of_line();
            printf("Your input has to be less than %d characters long. Please"
                           " try again\n", length);
        } else {
            overflow = FALSE;
        }
    } while (overflow);
    /* Remove the EOL character from string */
    buffer[strlen(buffer) - 1] = NULL_TERMINATOR;
    /*If there was only an EOL character return false */
    if (strlen(buffer) == 0) {
        return FALSE;
    }
    return TRUE;
}

/** Takes an input and returns whether it is even **/
BOOLEAN isEven(int input) {
    if (input % EVEN_NUM == 0) {
        return TRUE;
    } else
        return FALSE;
}