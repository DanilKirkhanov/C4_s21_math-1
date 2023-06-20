#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

int int_array[] = {0, 10, -10, 123, (int)INFINITY, (int)-INFINITY};
double asin_acos_array[] = {0.2, 1, 1, 0.001, 0.123, 0.3};
double double_array[] = {1.2, 005, -1.01, 2, -5, 5};
double test_nans[] = {NAN, -NAN};

Suite *s21_math_test();

int main() {
  int faile = 0;
  Suite *s;
  SRunner *tc;
  s = s21_math_test();
  tc = srunner_create(s);
  srunner_run_all(tc, CK_NORMAL);
  faile = srunner_ntests_failed(tc);
  srunner_free(tc);
  return (!faile) ? EXIT_SUCCESS : EXIT_FAILURE;
}

START_TEST(test_abs) {
  ck_assert_int_eq(s21_abs(int_array[_i]), abs(int_array[_i]));
}
END_TEST

START_TEST(test_acos) {
  ck_assert_double_eq_tol(s21_acos(asin_acos_array[_i]),
                          acos(asin_acos_array[_i]), 1e-7);
}
END_TEST

START_TEST(test_asin) {
  ck_assert_double_eq_tol(s21_asin(asin_acos_array[_i]),
                          asin(asin_acos_array[_i]), 1e-7);
}
END_TEST

START_TEST(test_atan) {
  ck_assert_double_eq_tol(s21_atan(asin_acos_array[_i]),
                          atan(asin_acos_array[_i]), 1e-7);
}
END_TEST

START_TEST(test_ceil) {
  ck_assert_double_eq_tol(s21_ceil(asin_acos_array[_i]),
                          ceil(asin_acos_array[_i]), 1e-7);
}
END_TEST

START_TEST(test_cos) {
  ck_assert_double_eq_tol(s21_cos(asin_acos_array[_i]),
                          cos(asin_acos_array[_i]), 1e-7);
}
END_TEST

START_TEST(test_exp) {
  ck_assert_double_eq_tol(s21_exp(asin_acos_array[_i]),
                          exp(asin_acos_array[_i]), 1e-7);
}
END_TEST

START_TEST(test_fabs) {
  ck_assert_double_eq_tol(s21_fabs(asin_acos_array[_i]),
                          fabs(asin_acos_array[_i]), 1e-7);
}
END_TEST

START_TEST(test_floor) {
  ck_assert_double_eq_tol(s21_floor(asin_acos_array[_i]),
                          floor(asin_acos_array[_i]), 1e-7);
}
END_TEST

START_TEST(test_fmod) {
  ck_assert_double_eq_tol(s21_fmod(asin_acos_array[_i], double_array[_i]),
                          fmod(asin_acos_array[_i], double_array[_i]), 1e-7);
}
END_TEST

START_TEST(test_log) {
  ck_assert_double_eq_tol(s21_log(asin_acos_array[_i]),
                          log(asin_acos_array[_i]), 1e-7);
}
END_TEST

START_TEST(test_pow) {
  ck_assert_double_eq_tol(s21_pow(asin_acos_array[_i], double_array[_i]),
                          pow(asin_acos_array[_i], double_array[_i]), 1e-7);
}
END_TEST

START_TEST(test_sin) {
  ck_assert_double_eq_tol(s21_sin(asin_acos_array[_i]),
                          sin(asin_acos_array[_i]), 1e-7);
}
END_TEST

START_TEST(test_sqrt) {
  ck_assert_double_eq_tol(s21_sqrt(asin_acos_array[_i]),
                          sqrt(asin_acos_array[_i]), 1e-7);
}
END_TEST

START_TEST(test_tan) {
  ck_assert_double_eq_tol(s21_tan(asin_acos_array[_i]),
                          tan(asin_acos_array[_i]), 1e-7);
}
END_TEST

START_TEST(test_nan) {
  ck_assert_double_nan(s21_acos(test_nans[_i]));
  ck_assert_double_nan(acos(test_nans[_i]));
  ck_assert_double_nan(s21_asin(test_nans[_i]));
  ck_assert_double_nan(asin(test_nans[_i]));
  ck_assert_double_nan(s21_atan(test_nans[_i]));
  ck_assert_double_nan(atan(test_nans[_i]));
  ck_assert_double_nan(s21_ceil(test_nans[_i]));
  ck_assert_double_nan(ceil(test_nans[_i]));
  ck_assert_double_nan(s21_cos(test_nans[_i]));
  ck_assert_double_nan(cos(test_nans[_i]));
  ck_assert_double_nan(s21_exp(test_nans[_i]));
  ck_assert_double_nan(exp(test_nans[_i]));
  ck_assert_double_nan(s21_fabs(test_nans[_i]));
  ck_assert_double_nan(fabs(test_nans[_i]));
  ck_assert_double_nan(s21_floor(test_nans[_i]));
  ck_assert_double_nan(floor(test_nans[_i]));
  ck_assert_double_nan(s21_fmod(test_nans[_i], test_nans[_i]));
  ck_assert_double_nan(fmod(test_nans[_i], test_nans[_i]));
  ck_assert_double_nan(s21_log(test_nans[_i]));
  ck_assert_double_nan(log(test_nans[_i]));
  ck_assert_double_nan(s21_pow(test_nans[_i], test_nans[_i]));
  ck_assert_double_nan(pow(test_nans[_i], test_nans[_i]));
  ck_assert_double_nan(s21_sin(test_nans[_i]));
  ck_assert_double_nan(sin(test_nans[_i]));
  ck_assert_double_nan(s21_sqrt(test_nans[_i]));
  ck_assert_double_nan(sqrt(test_nans[_i]));
  ck_assert_double_nan(s21_tan(test_nans[_i]));
  ck_assert_double_nan(tan(test_nans[_i]));
}

Suite *s21_math_test() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_math");
  tc = tcase_create("s21_math");
  tcase_add_loop_test(tc, test_abs, 0, sizeof(int_array) / sizeof(int));
  tcase_add_loop_test(tc, test_acos, 0,
                      sizeof(asin_acos_array) / sizeof(double));
  tcase_add_loop_test(tc, test_asin, 0,
                      sizeof(asin_acos_array) / sizeof(double));
  tcase_add_loop_test(tc, test_atan, 0,
                      sizeof(asin_acos_array) / sizeof(double));
  tcase_add_loop_test(tc, test_ceil, 0,
                      sizeof(asin_acos_array) / sizeof(double));
  tcase_add_loop_test(tc, test_cos, 0,
                      sizeof(asin_acos_array) / sizeof(double));
  tcase_add_loop_test(tc, test_exp, 0,
                      sizeof(asin_acos_array) / sizeof(double));
  tcase_add_loop_test(tc, test_fabs, 0,
                      sizeof(asin_acos_array) / sizeof(double));
  tcase_add_loop_test(tc, test_floor, 0,
                      sizeof(asin_acos_array) / sizeof(double));
  tcase_add_loop_test(tc, test_fmod, 0,
                      sizeof(asin_acos_array) / sizeof(double));
  tcase_add_loop_test(tc, test_log, 0,
                      sizeof(asin_acos_array) / sizeof(double));
  tcase_add_loop_test(tc, test_pow, 0,
                      sizeof(asin_acos_array) / sizeof(double));
  tcase_add_loop_test(tc, test_sin, 0,
                      sizeof(asin_acos_array) / sizeof(double));
  tcase_add_loop_test(tc, test_sqrt, 0,
                      sizeof(asin_acos_array) / sizeof(double));
  tcase_add_loop_test(tc, test_tan, 0,
                      sizeof(asin_acos_array) / sizeof(double));
  tcase_add_loop_test(tc, test_nan, 0, sizeof(test_nans) / sizeof(double));
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
