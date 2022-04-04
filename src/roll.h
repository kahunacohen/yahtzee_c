
#include <stdlib.h>
#include <time.h>

#define DIE_SIDES 6
#define MAX_DICE_PER_ROLL 5

/**
 * A Roll is an independent roll of n dice.
 * For simplicity, there is always a roll of
 * 5 dice, but we specify n dice to take from
 * and that's stored in the struct.
 */
typedef struct Roll {
    int   dice[MAX_DICE_PER_ROLL];
    int   num_dice;
} Roll;

void init_dice(void);
void roll_dice(Roll*, int num_dice);
int roll_die(void);

void init_dice() {
    srand(time(NULL));
}

/**
 * Roll one die.
 */
int roll_die(void) {
    return (rand() % DIE_SIDES) + 1;
}

void roll_dice(Roll* roll, int num_dice) {
    printf("called\n");
    roll->num_dice = num_dice;
    for (int i = 0; i < MAX_DICE_PER_ROLL; i++) {
        //printf("i: %d, roll: %d\n", i, roll_die());
        roll->dice[i] = roll_die();
    }
}

