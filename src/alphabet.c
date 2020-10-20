#include "alphabet.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void UpperToLower(char* string)
{
    int i = 0;
    while (string[i] != '\0') {
        string[i] = tolower(string[i]);
        i++;
    }
}

int check_file(FILE* file, char strings[][MAX_LENGTH_STRING])
{
    char str[100];
    int count = 0;
    while (feof(file) == 0 && count < MAX_LENGTH_STRING) {
        fscanf(file, "%s", str);
        strcpy(strings[count++], str);
    }
    UpperToLower(strings);
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
