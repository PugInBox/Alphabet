
all: main

ERROR_OPTIONS=-Wall -Werror

.PHONY:
	clear all

main:
	gcc $(ERROR_OPTIONS) main.c -o main