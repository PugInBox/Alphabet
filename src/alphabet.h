#ifndef ALPHABET_H
#define ALPHABET_H

#include <malloc.h>

#define ERROR_CONSOLE_ARGUMENT -10
#define ERROR_OPEN_FILE -1
#define OK 0

#define MAX_LENGTH_STRING 400
#define MAX_LENGTH_FILE 1000

FILE* open_file(char* file_name, char* mode);
void UpperToLower(char* string);
int check_file(FILE* file, char strings[][MAX_LENGTH_STRING]);
void output(char strings[][MAX_LENGTH_STRING], int count);

#endif