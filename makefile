all: bin/main format

ERROR_OPTIONS=-Wall -Werror

.PHONY:
	clear format all

bin/main: build/src/main.o build/src/alphabet.o
	gcc $(ERROR_OPTIONS) build/src/main.o build/src/alphabet.o -o bin/main

build/src/main.o: src/main.c src src/alphabet.h
	gcc $(ERROR_OPTIONS) -c src/main.c -o build/src/main.o

build/src/alphabet.o: src/alphabet.c src/alphabet.h
	gcc $(ERROR_OPTIONS) -c src/alphabet.c -o build/src/alphabet.o

format:
	clang-format -i src/main.c src/alphabet.h src/alphabet.c

clear:
	rm -rf build/src/*.o build/test/*.o bin/main bin/test