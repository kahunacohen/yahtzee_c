#include <stdio.h>
#include <check.h>
#include <stdbool.h>
#include "../src/turn.h"
START_TEST (init_turn_test) {
    Turn * turn = init_turn();
    for (int i = 0; i <= MAX_ROLLS - 1; i++) {
        Roll roll = turn->rolls[i];
        fail_unless(roll.num_dice == 0);
        for (int j = 0; j <= MAX_DICE_PER_ROLL - 1; j++) {
            fail_unless(roll.dice[j] == 0);
            fail_unless(roll.which_rolled[j] == false);
        }
    }
    free(turn);
} END_TEST
START_TEST (take_turn_test) {
    // Take a turn, rolling all 5 dice. Don't seed the random
    // numbers so we can test.
    Turn * turn = init_turn();

    take_turn(turn, 0, (bool[]){true, true, true, true, true});
    for (int i = 0; i <= MAX_DICE_PER_ROLL - 1; i++) {
        // Confirm that all the rolled dice are between 1-6
        int* first_roll_dice = turn->rolls[0].dice;
        fail_unless(first_roll_dice[i] >=1 && first_roll_dice[i] <= 6);
    }
    // Take a second turn, rolling the first and last dice.
    take_turn(turn, 1, (bool[]){true, false, false, false, true});
    for (int i = 0; i <= MAX_DICE_PER_ROLL - 1; i++) {
        // Confirm the first and last die are different than the first.
        int* first_roll_dice = turn->rolls[0].dice;
        int* second_roll_dice = turn->rolls[1].dice;
        // The first and last dice should be different.
        if (i == 0 || i == 4) {
            fail_unless(first_roll_dice[i] != second_roll_dice[i]);
        } else {
            // The dice not in the first or last position should be the same
            // since we didn't roll them from the last turn.
            fail_unless(first_roll_dice[i] == second_roll_dice[i]);
        }
    }
    free(turn);
}
END_TEST

// START_TEST (test_is_yahtzee) {
//     Roll roll;
//     Turn turn;

//     // Manually create a roll that's a yahtzee.
//     roll.num_dice = 5;
//     for (int i = 0; i <= MAX_DICE_PER_ROLL - 1; i++) {
//         // Every dice is rolled.
//         roll.which_rolled[i] = true;

//         // Each one is a 1
//         roll.dice[i] = 1;
//     }

//     // Set the turn's first roll to this roll.
//     turn.rolls[0] = roll;
//     turn.curr_roll = 0;
//     is_yahtzee(&turn);
// }
// END_TEST


int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, init_turn_test);
    tcase_add_test(tc1_1, take_turn_test);
    // tcase_add_test(tc1_1, test_is_yahtzee);




    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}