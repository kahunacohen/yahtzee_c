#include <stdio.h>
#include <check.h>
#include <stdbool.h>
#include "../src/turn.h"

START_TEST (take_turn_test) {
    // Take a turn, rolling all 5 dice. Don't seed the random
    // numbers so we can test.
    Turn turn;
    take_turn(&turn, 0, (bool[]){true, true, true, true, true});
    for (int i = 0; i <= MAX_DICE_PER_ROLL - 1; i++) {
        // Confirm that all the rolled dice are between 1-6
        int* first_rolled_dice = turn.rolls[0].dice;
        fail_unless(first_rolled_dice[i] >=1 && first_rolled_dice[i] <= 6);
    }
    printf("\n");
    // debug_roll(&turn.rolls[0]);
    // Take a second turn, rolling the first and last dice.
    take_turn(&turn, 1, (bool[]){true, false, false, false, true});
    for (int i = 0; i <= MAX_DICE_PER_ROLL - 1; i++) {
        // Confirm the first and last die are different than the first.
        int* first_rolled_dice = turn.rolls[0].dice;
        int* second_rolled_dice = turn.rolls[1].dice;
        // The first and last dice should be different.
        if (i == 0 || i == 4) {
            fail_unless(first_rolled_dice[i] != second_rolled_dice[i]);
        } else {
            // The dice not in the first or last position should be the same
            // since we didn't roll them from the last turn.
            fail_unless(first_rolled_dice[i] == second_rolled_dice[i]);
        }
    }
}
END_TEST


int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    // tcase_add_test(tc1_1, roll_dice_test);
    tcase_add_test(tc1_1, take_turn_test);




    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}