
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


void init_dice(void);
int roll_die(void);
Roll roll_dice(bool*);
void debug_roll(Roll*);

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
Roll roll_dice(bool* which_dice) {
    Roll roll;

    // set num_dice and which_rolled according to boolean
    // parameters.
    int num_dice = 0;
    for (int i = 0; i <= MAX_DICE_PER_ROLL - 1; i++) {
        bool rolled = which_dice[i];
        if (rolled) {
            num_dice++;
        }
        roll.dice[i] = roll_die();
        roll.which_rolled[i] = rolled;
    }
    roll.num_dice = num_dice;
    // qsort(roll.dice, MAX_DICE_PER_ROLL, sizeof(int), cmpfunc);
    return roll;
}
void debug_roll(Roll* roll) {
    printf("You rolled %d dice total.\n", roll->num_dice);
    for (int i = 0; i < MAX_DICE_PER_ROLL -1; i++) {
        if (roll->which_rolled[i]) {
            printf("In position %d and is a \"%d\"\n", i + 1, roll->dice[i]);
        }
    }
}
