#include "alphabet.h"
#include <locale.h>
#include <malloc.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    if (argc == 2) {
        char strings[MAX_LENGTH_STRING][MAX_LENGTH_STRING];
        FILE* f = fopen(argv[1], "r");
        if (f == NULL) {
            return ERROR_OPEN_FILE;
        }
        int count = check_file(f, strings);
        output(strings, count);
        return OK;
    } else {
        printf("Введите путь до файла\nexample: ./bin/main input.txt");
        return ERROR_CONSOLE_ARGUMENT;
    }
}
