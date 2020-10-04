#include "alphabet.h"
#include <stdio.h>
#include <string.h>

FILE* open_file(char* file_name, char* mode)
{
    FILE* file = fopen(file_name, mode);
    if (file == NULL) {
        return NULL;
    }
    return file;
}

int check_file(FILE* file, char strings[][MAX_LENGTH_STRING])
{
    char str[MAX_LENGTH_STRING];
    int count = 0;
    while (feof(file) == 0 && count < MAX_LENGTH_FILE) {
        fscanf(file, "%s", str);
        strcpy(strings[count++], str);
    }

    for (int i = 1; i < count; i++) {
        for (int j = 0; j < count - i; j++) {
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                strcpy(str, strings[j]);
                strcpy(strings[j], strings[j + 1]);
                strcpy(strings[j + 1], str);
            }
        }
    }
    return count;
}

void output(char strings[][MAX_LENGTH_STRING], int count)
{
    for (int i = 0; i < count; i++)
        printf("%s\n", strings[i]);
    putchar('\n');
}