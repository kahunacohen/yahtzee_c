
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define DIE_SIDES 6
#define MAX_DICE_PER_ROLL 5
#define MAX_ROLLS  3

/**
 * A Roll is an independent roll of n dice.
 * For simplicity, there is always a roll of
 * 5 dice, but we specify n dice to take from
 * and that's stored in the struct.
 */
typedef struct Roll {
    int   dice[MAX_DICE_PER_ROLL];
    int   num_dice;
    bool  which_rolled[MAX_DICE_PER_ROLL];
} Roll;

typedef struct Turn {
    Roll rolls[MAX_ROLLS];
} Turn;

void init_dice(void);
int roll_die(void);
Roll roll_dice(bool, bool, bool, bool, bool);
void debug_dice_rolled(Roll*);
void take_turn(Turn*, bool, bool, bool, bool, bool);

void init_dice() {
    srand(time(NULL));
}

/**
 * Roll one die.
 */
int roll_die(void) {
    return (rand() % DIE_SIDES) + 1;
}
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
/**
 * Roll n dice.
 */
Roll roll_dice(bool first, bool second, bool third, bool fourth, bool fifth) {
    Roll roll;
    // initialize which roll

    // Always roll 5 dice. It makes it easier to have an array
    // of a fixed size.
    for (int i = 0; i < MAX_DICE_PER_ROLL; i++) {
        roll.dice[i] = roll_die();
        // init which rolled to false.
        roll.which_rolled[i] = false;
    }
    // set num_dice and which_rolled according to boolean
    // parameters.
    int num_dice = 0;
    if (first) {
        num_dice++;
        roll.which_rolled[0] = true;
    }
    if (second) {
        num_dice++;
        roll.which_rolled[1] = true;
    }
    if(third) {
        num_dice++;
        roll.which_rolled[2] = true;
    }
    if (fourth) {
        num_dice++;
        roll.which_rolled[3] = true;
    }
    if (fifth) {
        num_dice++;
        roll.which_rolled[4] = true;
    }
    roll.num_dice = num_dice;
    qsort(roll.dice, MAX_DICE_PER_ROLL, sizeof(int), cmpfunc);
    return roll;
}
void debug_dice_rolled(Roll* roll) {
    printf("You rolled %d dice total.\n", roll->num_dice);
    for (int i = 0; i < MAX_DICE_PER_ROLL; i++) {
        if (roll->which_rolled[i]) {
            printf("In position %d and is a \"%d\"\n", i + 1, roll->dice[i]);
        }
    }
}
void take_turn(Turn* turn, bool first, bool second, bool third, bool fourth, bool fifth) {
    turn->rolls = roll_dice(first, second, third, fourth, fifth);
}
