#include <stdlib.h>
#include <check.h>
#include "../src/roman.c"

START_TEST(test_add_roman)
{
    ck_assert_str_eq(add_roman("I", "I"), "II");

}
END_TEST

Suite * roman_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_add_roman);

    return s;
}

int main(void)
{
    int unsigned number_failed;
    Suite *s;
    SRunner *sr;

    s = roman_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
