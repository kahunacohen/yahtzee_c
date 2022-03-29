#include <stdio.h>
#include <check.h>
#include "../src/dice.h"

START_TEST (roll_die_returns_correct_amount)
{
    for (int i = 0; i < 20; i++) {
      char result = roll_die();
      fail_unless(result > 0 && result <=6);
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
    tcase_add_test(tc1_1, roll_die_returns_correct_amount);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}