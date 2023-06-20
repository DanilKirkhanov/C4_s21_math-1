#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

int int_array[] = {0, 10, -10, 123, (int)INFINITY, (int)-INFINITY};
double asin_acos_array[] = {0, -1, 1, 0.001, -0.123, 10};
double double_array[] = {1.2, 005, -1.01, 12.12, -15.15, NAN};

Suite *s21_math_test();

int main() {
  int faile = 0;
  Suite *s;
  Suite *tc;
  s = s21_math_test();
  tc = srunner_create(s);
  srunner_run_all(tc, CK_NORMAL);
  faile = srunner_ntests_failed(tc);
  srunner_free(tc);
  return !faile ? EXIT_SUCCESS : EXIT_FAILURE;
}

START_TEST(test_abs) {
  ck_assert_int_eq(s21_abs(int_array[_i]), abs(int_array[_i]));
}
END_TEST

START_TEST(test_acos) {
  ck_assert_double_eq(s21_acos(asin_acos_array[_i]), acos(asin_acos_array[_i]));
}
END_TEST

START_TEST(test_asin) {
  ck_assert_double_eq(s21_asin(asin_acos_array[_i]), asin(asin_acos_array[_i]));
}
END_TEST

START_TEST(test_atan) {
  ck_assert_double_eq(s21_atan(asin_acos_array[_i]), atan(asin_acos_array[_i]));
}
END_TEST

START_TEST(test_ceil) {
  ck_assert_double_eq(s21_ceil(asin_acos_array[_i]), ceil(asin_acos_array[_i]));
}
END_TEST

START_TEST(test_cos) {
  ck_assert_double_eq(s21_cos(asin_acos_array[_i]), cos(asin_acos_array[_i]));
}
END_TEST

START_TEST(test_exp) {
  ck_assert_double_eq(s21_exp(asin_acos_array[_i]), exp(asin_acos_array[_i]));
}
END_TEST

START_TEST(test_fabs) {
  ck_assert_double_eq(s21_fabs(asin_acos_array[_i]), fabs(asin_acos_array[_i]));
}
END_TEST

START_TEST(test_floor) {
  ck_assert_double_eq(s21_floor(asin_acos_array[_i]),
                      floor(asin_acos_array[_i]));
}
END_TEST

START_TEST(test_fmod) {
  ck_assert_double_eq(s21_fmod(asin_acos_array[_i], double_array[_i]),
                      fmod(asin_acos_array[_i], double_array[_i]));
}
END_TEST

START_TEST(test_log) {
  ck_assert_double_eq(s21_log(asin_acos_array[_i]), log(asin_acos_array[_i]));
}
END_TEST

START_TEST(test_pow) {
  ck_assert_double_eq(s21_pow(asin_acos_array[_i], double_array[_i]),
                      pow(asin_acos_array[_i], double_array[_i]));
}
END_TEST

START_TEST(test_sin) {
  ck_assert_double_eq(s21_sin(asin_acos_array[_i]), sin(asin_acos_array[_i]));
}
END_TEST

START_TEST(test_sqrt) {
  ck_assert_double_eq(s21_sqrt(asin_acos_array[_i]), sqrt(asin_acos_array[_i]));
}
END_TEST

START_TEST(test_tan) {
  ck_assert_double_eq(s21_tan(asin_acos_array[_i]), tan(asin_acos_array[_i]));
}
END_TEST

Suite *s21_math_test() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_math");
  tc = tcase_create("s21_math");
  tcase_add_loop_test(tc, test_abs, 0, sizeof(int_array));
  tcase_add_loop_test(tc, test_acos, 0, sizeof(asin_acos_array));
  tcase_add_loop_test(tc, test_asin, 0, sizeof(asin_acos_array));
  tcase_add_loop_test(tc, test_atan, 0, sizeof(asin_acos_array));
  tcase_add_loop_test(tc, test_ceil, 0, sizeof(asin_acos_array));
  tcase_add_loop_test(tc, test_cos, 0, sizeof(asin_acos_array));
  tcase_add_loop_test(tc, test_exp, 0, sizeof(asin_acos_array));
  tcase_add_loop_test(tc, test_fabs, 0, sizeof(asin_acos_array));
  tcase_add_loop_test(tc, test_floor, 0, sizeof(asin_acos_array));
  tcase_add_loop_test(tc, test_fmod, 0, sizeof(asin_acos_array));
  tcase_add_loop_test(tc, test_log, 0, sizeof(asin_acos_array));
  tcase_add_loop_test(tc, test_pow, 0, sizeof(asin_acos_array));
  tcase_add_loop_test(tc, test_sin, 0, sizeof(asin_acos_array));
  tcase_add_loop_test(tc, test_sqrt, 0, sizeof(asin_acos_array));
  tcase_add_loop_test(tc, test_tan, 0, sizeof(asin_acos_array));
  suite_add_tcase(s, tc);
  return s;
}

// long double s21_cos(double x);
// long double s21_exp(double x);
// long double s21_fabs(double x);
// long double s21_floor(double x);
// long double s21_fmod(double x, double y);
// long double s21_log(double x);
// long double s21_pow(double base, double exp);
// long double s21_sin(double x);
// long double s21_sqrt(double x);
// long double s21_tan(double x);

// long double s21_fuctorial(long long int num);
// long double s21_pow_int(double base, double expo);
