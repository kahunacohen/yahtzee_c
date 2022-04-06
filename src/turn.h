#include <stdio.h>
#include <stdbool.h>
#include "roll.h"

typedef struct Turn {
    Roll   rolls[MAX_DICE_PER_ROLL];
} Turn;

void take_turn(Turn*, bool, bool, bool, bool, bool);


void take_turn(Turn* turn, bool first, bool second, bool third, bool fourth, bool fifth) {
  printf("Take turn!\n");
  Roll roll;
  roll_dice(&roll, 5);
  turn->rolls[0] = roll;
}

