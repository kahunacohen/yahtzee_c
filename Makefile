.DEFAULT_GOAL := run

build:
	gcc ./src/main.c -o yahtzee
run: build
	./yahtzee
build_test:
	gcc ./tests/test_roll.c -Wall -o test_roll -lcheck -pthread -pthread -lm	
test: build build_test
	./test_roll

