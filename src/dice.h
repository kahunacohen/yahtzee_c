#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h> 
#include "rules.h"

char* roll_dice(char);
char roll_die(void);

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