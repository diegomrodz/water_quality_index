CC=gcc
STD=c99
TESTS=test/
LIBS=$(wildcard lib/*)
INCLUDE_PATH=lib/

tests: libs
	mkdir bin/$(TESTS)
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)qO2_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)qO2_test -lm
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)qPH_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)qPH_test -lm
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)qCF_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)qCF_test -lm

libs:
	mkdir src/ bin/
	for dir in $(LIBS); do \
		cd $$dir; \
		gcc -c *.c -I../; \
		mv *.o ../../src; \
		cd -; \
	done;

clean:
	rm -rf src/ bin/
