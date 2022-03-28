#include <assert.h>
#include <stdbool.h>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define DIE_SIDES 6
#define MAX_DICE_PER_ROLL 5

void usage(void);
char* roll_dice(char);
char roll_die(void);
_Bool is_yahtzee(char*, char n_die);
size_t get_n_dice_in_roll(char*, char n_die);

int main(int argc, char *argv[] ) {
    //usage();
    srand(time(NULL));
    char n_die = 5;
    char* rolls = roll_dice(n_die);
    int i = 1;
    while(!is_yahtzee(rolls, n_die)) {
        rolls = roll_dice(n_die);
        // for (int i = 0; i < n_die; i++) {
        //     printf("rolled: %d\n", rolls[i]);
        // }
        i++;
        //printf("\n");
    }
    printf("yahtzee on roll %d!\n", i);
    free(rolls);
}

void usage(void) {
    printf("NAME\n\tyahtzee - simulate yahtzee games and report probability of selected rolls.\n");
}

/**
 * @brief Roll one die.
 * 
 * @return char 
 */
char roll_die(void) {
    return (rand() % DIE_SIDES) + 1;
}

/**
 * @brief Compare function for sorting a roll of n dice.
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int comparator(const void * a, const void * b) {
   return ( *(char*)a - *(char*)b );
}

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


/**
 * @brief Roll a series of n die.
 * @param n_die - Number of die to roll (between 1-5).
 * @return char* A sorted array of 5 die rolls.
 * The caller is responsible for freeing the memory allocated
 * for the array of rolls.
 */
char* roll_dice(char n_die) {
    assert(n_die > 0 && n_die <= MAX_DICE_PER_ROLL);
    size_t size_of_alloc =  n_die * sizeof(char);
    char *rolls = malloc(size_of_alloc);
    if (rolls == NULL) {
        fprintf(stderr, "Fatal: failed to allocate %zu bytes when rolling dice.\n", size_of_alloc);
        exit(1);
    }
    for (int i = 0; i <= n_die; i++ ) {
        rolls[i] = roll_die();
    }
    qsort(rolls, n_die, sizeof(char), comparator);
    return rolls;
}
