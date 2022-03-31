
#include <stdlib.h>
#define DIE_SIDES 6
#define MAX_DICE_PER_ROLL 5

typedef struct Roll {
    int   dice[MAX_DICE_PER_ROLL];
    int   num_dice;
} Roll;

Roll* roll_dice(int);
int roll_die(void);

/**
 * Roll one die.
 */
int roll_die(void) {
    return (rand() % DIE_SIDES) + 1;
}

/**
 * Roll n dice. If less than 6 die are
 * rolled, zeros out the remaining slots.
 */
Roll* roll_dice(int num_dice) {
    static Roll roll;
    roll.num_dice = num_dice;
    for (int i = 0; i < MAX_DICE_PER_ROLL; i++) {
        if (i < num_dice) {
            roll.dice[i] = roll_die();
        } else {
            // Zero out dice that are not rolled.
            roll.dice[i] = 0;
        }
    }
    return &roll;
}