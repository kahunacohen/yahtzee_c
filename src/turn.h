#include <assert.h>
#include "../src/roll.h"

typedef struct Turn {
    Roll rolls[MAX_ROLLS];
    int curr_roll;
} Turn;

Turn * init_turn(void);

void take_turn(Turn *, int take, bool*);
_Bool is_yahtzee(Turn *);

/**
 * @brief Returns a pointer to an initialized turn.
 * An initialized turn has an array of 5 rolls, each one
 * initialized to 0. Further, each roll indicates
 * that each die were not yet rolled by being set to false.  
 * @return Turn* 
 */
Turn * init_turn() {
    struct Turn * turn = malloc(sizeof(*turn));
    if (!turn) {
        perror("malloc for turn failed");
        exit(EXIT_FAILURE);
    }
    turn->curr_roll = 0;
    for (int i = 0; i <= MAX_ROLLS -1; i++) {
        struct Roll roll;
        for (int j = 0; j <= MAX_DICE_PER_ROLL - 1; j++) {
            roll.dice[j] = 0;
            roll.num_dice = 0;
            roll.which_rolled[j] = false;
        }
        turn->rolls[i] = roll;
    }
    return turn;
}
/**
 * @brief Take a turn. The first turn will set the dice to not merge
 * with the last roll since there was no last roll.
 * 
 * In subsequent takes any dice not rolled will be set to the previous roll.
 * 
 * @param turn - A pointer to the turn.
 * @param take  - Which turn to take. Is it the first (0), second (1) etc.?
 * @param which_dice - An array of booleans indicating which dice to roll.
 */
void take_turn(Turn* turn, int take, bool* which_dice) {
    assert(take >= 0 && take <= MAX_DICE_PER_ROLL);
    Roll roll = roll_dice(which_dice);
    if (take > 0) {
        // if not first roll, then the take the dice not rolled from last roll.
        Roll last_roll = turn->rolls[take - 1];
        for (int i = 0; i <= MAX_DICE_PER_ROLL - 1; i++) {
            if (!which_dice[i]) {
                // This one is not rolled, so use last roll.
                roll.dice[i] = last_roll.dice[i];
            }
        }
    }
    turn->rolls[take] = roll;
}


_Bool is_yahtzee(Turn* turn) {
    // For each roll.
    for (int i = 0; i <= MAX_ROLLS - 1; i++) {
        printf("roll\n");
        // Are each of the dice the same?
        int num_rolled = 0;
        for (int j = 0; j <= MAX_DICE_PER_ROLL - 1; j++) {
            int num = turn->rolls[i].dice[j];
            // The die has been rolled
            if (num != 0) {
                printf("dice:%d\n", turn->rolls[i].dice[j]);
            }
        }
    }
    return true;
}