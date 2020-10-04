#include "alphabet.h"
#include <malloc.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    //проверяем, что есть аргумент с названием файла
    if (argc == 2) {
        char strings[MAX_LENGTH_FILE][MAX_LENGTH_STRING];
        FILE* f = open_file(argv[1], "r");
        if (f == NULL) {
            return ERROR_OPEN_FILE;
        }
        //Сортируем слова
        int count = check_file(f, strings);
        //Выводим строки
        output(strings, count);
        return OK;
    } else {
        //Если аргумента нет, выводим ошибку
        printf("Введите путь до файла\nexample: ./bin/main input.txt");
        return ERROR_CONSOLE_ARGUMENT;
    }
}