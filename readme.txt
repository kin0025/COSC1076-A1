/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alexander Chi-Cheng Kinross-Smith
 * Student Number   : s3603437
 * Course Code      : COSC1076
 * Program Code     : BH094
 * Start up code provided by Paul Miller 
 **********************************************************************/

 This file is for you to provide any extra information that your
 markers may find useful. For example. Bugs, inconsistencies, incomplete
 functionality, reasoning for design choices etc.

No known bugs, inconsistencies.

The user is prompted of several scenarios in which they will have to end 
the game, but the game is never ended for them. 

See scenario:
6,4
4,3
3,4
6,5
5,6
6,3
7,4
5,3
5,2
The Blue Player has no tokens left

Users will also be notified if there are no possible moves.

An extra display feature was added that displays what squares are valid 
moves, it is activated by changing DISPLAY_MARKERS to TRUE in shared.h

I have designed the program so the current player will be the first player
passed to the program, as opposed to players always been passed in the same
position. This it to make it easier to see the current player when the board
is displayed, and to allow move markers to be printed based upon this 
assumption

A Singleplayer mode was added where one player is a computer. This is
entirely contained in the end of game.c (functional splitting be dammed) and
contains mainly duplicated code from the main function, as boolean flags
could not be added to the initial functions to tell the game what kind of
players are playing.
This functionality is enabled through setting ENABLE_SP to TRUE in shared.h

The AI is not very effective :(.

