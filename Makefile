CC=gcc
STD=c99
TESTS=test/
LIBS=$(wildcard lib/*)
INCLUDE_PATH=lib/

tests: libs
	mkdir bin/$(TESTS)
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)iqa_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)iqa_test -lm
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)qO2_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)qO2_test -lm
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)qPH_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)qPH_test -lm
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)qCF_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)qCF_test -lm
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)qDBO_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)qDBO_test -lm
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)qNT_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)qNT_test -lm
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)qFT_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)qFT_test -lm
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)qDT_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)qDT_test -lm
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)qTU_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)qTU_test -lm
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)qST_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)qST_test -lm
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)read_input_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)read_input_test -lm
	$(CC) -std=$(STD) -W -Wall -Wpedantic $(TESTS)glade_test.c $(wildcard src/*) -I$(INCLUDE_PATH) -o bin/$(TESTS)glade_test -lm `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
	$(CC) -std=$(STD) -W -Wall -Wpedantic main.c $(wildcard src/*) -I$(INCLUDE_PATH) -o iqa -lm `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`

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
