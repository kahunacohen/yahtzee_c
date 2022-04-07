#include <stdio.h>
#include <check.h>
#include <stdbool.h>
#include "../src/turn.h"

START_TEST (roll_dice_test) {
    init_dice();
    Roll roll = roll_dice(false, false, true, false, false);
    debug_dice_rolled(&roll);
    fail_unless(roll.num_dice == 1);
    fail_unless(roll.dice[0] > 0 && roll.dice[0] <= 6);

    for (int i = 0; i <=5; i++) {
        if(i == 2) {
            fail_unless(roll.which_rolled[i]);
        } else {
            fail_unless(!roll.which_rolled[i]);
        }
    }
    Roll roll2 = roll_dice(true, true, true, true, true);
    debug_dice_rolled(&roll2);

}
END_TEST


int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, roll_dice_test);




    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}