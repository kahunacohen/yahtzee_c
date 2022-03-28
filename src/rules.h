#ifndef RULES_H
#define RULES_H
#include <stdbool.h>

#define DIE_SIDES 6
#define MAX_DICE_PER_ROLL 5

_Bool is_yahtzee(char*, char n_die);

_Bool is_yahtzee(char* roll, char n_die) {
    char last;
    for (int i = 0; i <= n_die; i++) {
        if (i > 0) {
            if (roll[i] != last) {
                return false;
            }
        }
        last = roll[i];
    }
    return true;
}
#endif