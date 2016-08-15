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


#define ERROR_VALUE -1
#define EVEN_NUM 2


void read_rest_of_line(void);

int read_int(void);

BOOLEAN read_game_input(char * buffer, int length,BOOLEAN);

BOOLEAN isEven(int input);

#endif /* ifndef UTILITY_H */
