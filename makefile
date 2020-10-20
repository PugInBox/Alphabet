all: bin/main bin/test format

ERROR_OPTIONS=-Wall

.PHONY:
	clear format all

bin/main: build/src/main.o build/src/alphabet.o
	gcc $(ERROR_OPTIONS) build/src/main.o build/src/alphabet.o -o bin/main

build/src/main.o: src/main.c  src/alphabet.h
	gcc $(ERROR_OPTIONS) -c src/main.c -o build/src/main.o

build/src/alphabet.o: src/alphabet.c src/alphabet.h
	gcc $(ERROR_OPTIONS) -c src/alphabet.c -o build/src/alphabet.o

bin/test: build/test/main.o build/test/test.o build/src/alphabet.o
	gcc $(ERROR_OPTIONS) build/test/main.o build/test/test.o build/src/alphabet.o -o bin/test

build/test/main.o: thirdparty/ctest.h test/main.c
	gcc $(ERROR_OPTIONS) -c test/main.c -o build/test/main.o

build/test/test.o: thirdparty/ctest.h test/test.c
	gcc $(ERROR_OPTIONS) -c test/test.c -o build/test/test.o

format:
	clang-format -i src/main.c src/alphabet.h src/alphabet.c test/test.c test/main.c

clear:
	rm -rf build/src/*.o build/test/*.o bin/main bin/test
