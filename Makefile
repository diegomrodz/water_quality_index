CC=gcc
STD=c99
LIBS=lib/test
INCLUDE_PATH=lib/

tests: libs
	mkdir bin/
	$(CC) -std=$(STD) -W -Wall -Wpedantic main.c $(wildcard src/*) -I$(INCLUDE_PATH) -lm -o bin/test

libs:
	mkdir src/
	for dir in $(LIBS); do \
		cd $$dir; \
		gcc -c *.c -I../; \
		mv *.o ../../src; \
		cd -; \
	done;

clean:
	rm -rf src/ bin/
