#include <stdio.h>
#include <check.h>
#include <stdbool.h>

#include "../src/dice.h"
#include "../src/rules.h"


START_TEST (roll_die_returns_correct_amount) {
    for (int i = 0; i < 20; i++) {
      char result = roll_die();
      fail_unless(result > 0 && result <=6);
    }
}
END_TEST

START_TEST (roll_dice_rolls_n_dice) {
  char num_dice = 5;
  char* roll = roll_dice(num_dice);
  for (int i = 0; i <= num_dice - 1; i++) {
    fail_unless(roll[i] > 0 && roll[i] <=6);
  }
}
END_TEST

START_TEST (is_yahtzee_true) {
  char roll[5] = {1, 1, 1, 1, 1};
  fail_unless(is_yahtzee(roll, 5));
}
END_TEST

START_TEST (is_yahtzee_false) {
  char roll[5] = {1, 1, 3, 1, 1};
  fail_if(is_yahtzee(roll, 5));
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, roll_die_returns_correct_amount);
    tcase_add_test(tc1_1, roll_dice_rolls_n_dice);
    tcase_add_test(tc1_1, is_yahtzee_true);
    tcase_add_test(tc1_1, is_yahtzee_false);


    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}