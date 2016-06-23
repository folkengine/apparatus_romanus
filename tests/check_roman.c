#include <stdlib.h>
#include <check.h>
#include "../src/roman.c"

START_TEST(test_add_roman)
{
    ck_assert_str_eq(add_roman("I", "I"), "II");
    ck_assert_str_eq(add_roman("IX", "IX"), "XVIII");
    ck_assert_str_eq(add_roman("M", "MMMCCXCVIII"), "MMMMCCXCVIII");

    // Negative Boundary Conditions
    ck_assert_str_eq(add_roman("I", ""), "I");
}
END_TEST

START_TEST(test_subtract_roman)
{
    ck_assert_str_eq(subtract_roman("II", "I"), "I");
    ck_assert_str_eq(subtract_roman("XVIII", "IX"), "IX");
    ck_assert_str_eq(subtract_roman("MMMMCCXCVIII", "MMI"), "MMCCXCVII");

    // Negative Boundary Conditions
    ck_assert_str_eq(subtract_roman("M", "MM"), "");
    ck_assert_str_eq(subtract_roman("M", ""), "M");
}
END_TEST

START_TEST(test_get_roman_value)
{
    // Core Sieve Values
    ck_assert_str_eq(get_roman_value(1), "I");
    ck_assert_str_eq(get_roman_value(5), "V");
    ck_assert_str_eq(get_roman_value(9), "IX");
    ck_assert_str_eq(get_roman_value(10), "X");
    ck_assert_str_eq(get_roman_value(40), "XL");
    ck_assert_str_eq(get_roman_value(50), "L");
    ck_assert_str_eq(get_roman_value(90), "XC");
    ck_assert_str_eq(get_roman_value(100), "C");
    ck_assert_str_eq(get_roman_value(400), "CD");
    ck_assert_str_eq(get_roman_value(500), "D");
    ck_assert_str_eq(get_roman_value(900), "CM");
    ck_assert_str_eq(get_roman_value(1000), "M");

    // More complex values
    ck_assert_str_eq(get_roman_value(3), "III");
    ck_assert_str_eq(get_roman_value(3298), "MMMCCXCVIII");

    // Negative Boundary Conditions
    ck_assert_str_eq(get_roman_value(0), "");
    ck_assert_str_eq(get_roman_value(-1), "");
}
END_TEST

START_TEST(test_get_arabic_value)
{
    ck_assert_int_eq(get_arabic_value("I"), 1);
    ck_assert_int_eq(get_arabic_value("II"), 2);
    ck_assert_int_eq(get_arabic_value("IX"), 9);
    ck_assert_int_eq(get_arabic_value("XX"), 20);
    ck_assert_int_eq(get_arabic_value("IIIX"), 7);
    ck_assert_int_eq(get_arabic_value("MMMCCXCVIII"), 3298);
}
END_TEST

/**
 * Tests every number from 1 to 4,999, validating conversion from Arabic to Roman numbers, and visa versa.
 *
 */
START_TEST(test_brute_force)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;

    fp = fopen("roman_numerals.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((getline(&line, &len, fp)) != -1) {
        char *array[10];
        int i=0;

        array[i] = strtok(line,"=");

        while(array[i] != NULL) {
            array[++i] = strtok(NULL,"=");
        }
        int arabic = atoi(array[0]);
        char *roman = strtok(array[1], "\n");

        ck_assert_str_eq(get_roman_value(arabic), roman);
        ck_assert_int_eq(get_arabic_value(roman), arabic);
    }

    ck_assert_int_eq(get_char_arabic_value('m'), 1000);

    fclose(fp);
    if (line)
        free(line);
}
END_TEST

START_TEST(test_get_char_arabic_value)
{
    ck_assert_int_eq(get_char_arabic_value('I'), 1);
    ck_assert_int_eq(get_char_arabic_value('i'), 1);
    ck_assert_int_eq(get_char_arabic_value('V'), 5);
    ck_assert_int_eq(get_char_arabic_value('v'), 5);
    ck_assert_int_eq(get_char_arabic_value('X'), 10);
    ck_assert_int_eq(get_char_arabic_value('x'), 10);
    ck_assert_int_eq(get_char_arabic_value('L'), 50);
    ck_assert_int_eq(get_char_arabic_value('l'), 50);
    ck_assert_int_eq(get_char_arabic_value('C'), 100);
    ck_assert_int_eq(get_char_arabic_value('c'), 100);
    ck_assert_int_eq(get_char_arabic_value('D'), 500);
    ck_assert_int_eq(get_char_arabic_value('d'), 500);
    ck_assert_int_eq(get_char_arabic_value('M'), 1000);
    ck_assert_int_eq(get_char_arabic_value('m'), 1000);
}
END_TEST

START_TEST(test_sasprintf)
{
    char *q = NULL;
    Sasprintf(q, "select * from tab");
    ck_assert_str_eq(q, "select * from tab");

    int i = 2;
    Sasprintf(q, "%s where row%i is not null", q, i);
    ck_assert_str_eq(q, "select * from tab where row2 is not null");
}
END_TEST

Suite * roman_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_sasprintf);
    tcase_add_test(tc_core, test_get_char_arabic_value);
    tcase_add_test(tc_core, test_get_arabic_value);
    tcase_add_test(tc_core, test_get_roman_value);
    tcase_add_test(tc_core, test_brute_force);
    tcase_add_test(tc_core, test_add_roman);
    tcase_add_test(tc_core, test_subtract_roman);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = roman_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
