#include <stdio.h>
#include <check.h>
#include <stdbool.h>

#include "../src/roll.h"


START_TEST (roll_dice_returns_num_dice_rolled) {
    Roll* roll = roll_dice(1);
    fail_unless(roll->num_dice == 1);
}
END_TEST

START_TEST (roll_dice_is_independent) {
    Roll* roll = roll_dice(1);
    fail_unless(roll->dice[1] == 0);

    Roll* roll2 = roll_dice(5);
    fail_unless(roll2->dice[4] != 0);

    // Oops, roll 2 overwrote roll.
    fail_unless(roll->dice[1] == 0);
}
END_TEST
START_TEST (roll_dice_returns_dice_rolled_with_padding) {
    Roll* roll = roll_dice(1);
    // It's rolled.
    fail_unless(roll->dice[0] > 0 && roll->dice[0] <= 6);
    
    // The rest have not been rolled.
    fail_unless(roll->dice[1] == 0);
    fail_unless(roll->dice[2] == 0);
    fail_unless(roll->dice[3] == 0);
    fail_unless(roll->dice[4] == 0);
}
END_TEST

START_TEST (roll_dice_returns_all_dice_rolled) {
    Roll* roll = roll_dice(5);
    // It's rolled.
    fail_unless(roll->dice[0] > 0 && roll->dice[0] <= 6);
    fail_unless(roll->dice[1] > 0 && roll->dice[1] <= 6);
    fail_unless(roll->dice[2] > 0 && roll->dice[2] <= 6);
    fail_unless(roll->dice[3] > 0 && roll->dice[3] <= 6);
    fail_unless(roll->dice[4] > 0 && roll->dice[4] <= 6);
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, roll_dice_returns_num_dice_rolled);
    tcase_add_test(tc1_1, roll_dice_returns_dice_rolled_with_padding);
    tcase_add_test(tc1_1, roll_dice_returns_all_dice_rolled);
    tcase_add_test(tc1_1, roll_dice_is_independent);


    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}