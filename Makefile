.DEFAULT_GOAL := run

build:
	gcc ./src/main.c -o yahtzee
run: build
	./yahtzee
build_test:

	gcc ./tests/test.c -Wall -o test -lcheck -pthread -pthread -lm	
test: build build_test
	./test

