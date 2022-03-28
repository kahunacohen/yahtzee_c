#include <stdio.h>
#include <check.h>
#include "../src/lib.h"

START_TEST (sanity_check)
{
    printf("hey: %d\n", foo());
    fail_unless(5 == 5, "this should succeed");
    fail_unless(6 == 5, "this should fail");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, sanity_check);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}