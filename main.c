#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define NUM_DICE_SIDES 6
#define NUM_DICE 5

void usage(void);
char* roll_dice(void);
char roll_die(void);

int main(int argc, char *argv[] ) {
    usage();
    srand(time(NULL));
    char* rolls = roll_dice();
    for (int i = 0; i < NUM_DICE; i++) {
        printf("die: %d\n", rolls[i]);
    }
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
    return (rand() % NUM_DICE_SIDES) + 1;
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
 * @brief Roll a series of 5 die.
 * @return char* A sorted array of 5 die rolls.
 * The caller is responsible for freeing the memory allocated
 * for the array of rolls.
 */
char* roll_dice(void) {
    size_t size_of_alloc =  NUM_DICE * sizeof(char);
    char *rolls = malloc(size_of_alloc);
    if (rolls == NULL) {
        fprintf(stderr, "Fatal: failed to allocate %zu bytes when rolling dice.\n", size_of_alloc);
        exit(1);
    }
    for (int i = 0; i < NUM_DICE; i++ ) {
        rolls[i] = roll_die();
    }

    qsort(rolls, NUM_DICE, sizeof(char), comparator);
    return rolls;
}