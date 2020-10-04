#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    char strings[10][1000], str[1000];
        FILE *f;
        int count = 0, i, j;
        f = fopen ("input.txt","r");
        if(f == NULL){
    return 1;
}
//Считываем строки
    while (feof(f) == 0 && count < 10)
        {
        fscanf (f, "%s", str);
        strcpy(strings[count++], str);
    }
    for(i = 1; i < count; i++)
        for(j = 0; j < count - i; j++)
            if(strcmp(strings[j], strings[j+1]) > 0){
                strcpy(str, strings[j]);
                strcpy(strings[j], strings[j+1]);
                strcpy(strings[j+1], str);
            }
//Выводим строки
    for(i = 0; i < count; i++)
        printf("%s\n", strings[i]);
    putchar('\n');
    return 0;
}