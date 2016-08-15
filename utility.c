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
void read_rest_of_line(void)
{
    int ch;
    while(ch = getc(stdin), ch != EOF && ch != NEWLINE)
        ;
    clearerr(stdin);
}



int read_int(void)
{
    char buffer[LINELEN + EXTRACHARS];
    int output;
    char* ptr = NULL;

    fgets(buffer,LINELEN,stdin);

    output = (int)strtol(buffer,&ptr,BASE);    

    if( output == -1 || ptr == buffer){
         printf("ERROR");
         return ERROR_VALUE;
    }

    return output;
}

BOOLEAN read_game_input(char * buffer, int length, BOOLEAN removeReturn)
{
    BOOLEAN result = TRUE;
    if(fgets(buffer,length,stdin) == NULL){
                result = FALSE;
    }
    if(removeReturn){
        buffer[strlen(buffer)-1] = NULL_TERMINATOR;
    }

    return result;
}

BOOLEAN isEven(int input){
    if(input % EVEN_NUM == 0){
        return TRUE;
    }else
        return FALSE;
}