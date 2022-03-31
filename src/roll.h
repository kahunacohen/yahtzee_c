
#include <stdlib.h>
#define DIE_SIDES 6
#define MAX_DICE_PER_ROLL 5

typedef struct Roll {
    int   dice[MAX_DICE_PER_ROLL];
    int   num_dice;
} Roll;

void roll_dice(Roll*, int num_dice);
int roll_die(void);
int* get_dice(Roll*);

/**
 * Roll one die.
 */
int roll_die(void) {
    return (rand() % DIE_SIDES) + 1;
}

void roll_dice(Roll* roll, int num_dice) {
    roll->num_dice = num_dice;
    for (int i = 0; i < MAX_DICE_PER_ROLL; i++) {
        roll->dice[i] = roll_die();
    }
}

int* get_dice(Roll* roll) {
    int* arr[roll->num_dice];
    for (int i = 0; i < roll->dice; i++) {
        arr[i] = roll->dice[i];
    }
    return arr;
}

