#include <stdio.h>
#include <check.h>
#include <stdbool.h>
#include "../src/turn.h"

// START_TEST (roll_dice_test) {
//     init_dice();
//     bool which_dice[MAX_DICE_PER_ROLL] = {false, false, true, false, false};
//     Roll roll = roll_dice(which_dice);
//     debug_dice_rolled(&roll);
//     fail_unless(roll.num_dice == 1);
//     fail_unless(roll.dice[0] > 0 && roll.dice[0] <= 6);

// }
END_TEST
START_TEST (take_turn_test) {
    init_dice();
    //bool which_dice[MAX_DICE_PER_ROLL] = {true, true, true, true, true};
    Turn turn;
    take_turn(&turn, 0, (bool[]){true, true, true, true, true});
    for (int i = 0; i <= MAX_DICE_PER_ROLL - 1; i++) {
        printf("rolled: %d\n", turn.rolls[0].dice[i]);
    }
    printf("\n");
    // debug_roll(&turn.rolls[0]);
    take_turn(&turn, 1, (bool[]){true, false, false, false, true});
    for (int i = 0; i <= MAX_DICE_PER_ROLL - 1; i++) {
        printf("rolled: %d\n", turn.rolls[1].dice[i]);
    }
    
    // debug_roll(&turn.rolls[1]);


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