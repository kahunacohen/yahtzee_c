#include <stdlib.h>
#include <stdio.h>

#include "roll.h"
#include "rules.h"

void usage(void);


int main(int argc, char *argv[] ) {
    printf("hi");
    //usage();
    // init_dice();
    // char n_die = 5;
    // char* rolls = roll_dice(n_die);
    // int i = 1;
    // while(!is_yahtzee(rolls, n_die)) {
    //     rolls = roll_dice(n_die);
    //     // for (int i = 0; i < n_die; i++) {
    //     //     printf("rolled: %d\n", rolls[i]);
    //     // }
    //     i++;
    //     //printf("\n");
    // }
    // printf("yahtzee on roll %d!\n", i);
    // free(rolls);
}

void usage(void) {
    printf("NAME\n\tyahtzee - simulate yahtzee games and report probability of selected rolls.\n");
}

