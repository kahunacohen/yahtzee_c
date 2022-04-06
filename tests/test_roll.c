#include <stdio.h>
#include <check.h>
#include <stdbool.h>
#include "../src/turn.h"

// START_TEST (roll_dice_test) {
//     Roll roll;
//     roll_dice(&roll, 1);
//     fail_unless(roll.dice[0] > 0 && roll.dice[0] <= 6);
// }
// END_TEST

START_TEST (foo) {
    init_dice();
    Turn turn;
    take_turn(&turn, true, true, true, true, true);
    printf("turn first dice: %d\n", turn.rolls[0].dice[0]);
}
END_TEST


// START_TEST (roll_dice_is_independent) {
//     Roll roll;
//     Roll roll2;
//     roll.num_dice = 1;
//     roll_dice(&roll);
//     fail_unless(roll.dice[1] == 0);

//     roll2.num_dice = 5;
//     fail_unless(roll2.dice[4] != 0);

//     // Confirm roll 2 doesn't interfere with roll 1.
//     fail_unless(roll.dice[1] == 0);
// }
// END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    //tcase_add_test(tc1_1, roll_dice_test);
    tcase_add_test(tc1_1, foo);



    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}