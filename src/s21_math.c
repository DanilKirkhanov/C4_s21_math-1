#include "s21_math.h"

#include <math.h>
#include <stdio.h>

#define LN2 0.693147180559945309417232
#define S21_INF 1.0 / 0.0
#define S21_NAN 0.0 / 0.0
long double s21_fuctorial(long long int num);
long double s21_pow_int(double base, double expo);

int s21_abs(int x) {
  if (x) return x < 0 ? x : -x;
}

// long double acos(double x) {

// }

// long double asin(double x) {

// }
// вычисляет арксинус

// long double atan(double x) {

// }
// вычисляет арктангенс

long double s21_ceil(double x) {
  long double xi = (long int)x;
  if (x != x || x != S21_INF && x != -S21_INF) {
    xi = x;
  }
  return x < xi ? xi + 1 : xi;
}
// возвращает ближайшее целое число, не меньшее заданного значения

// long double cos(double x){
//     for
// }

long double s21_exp(double x) {
  long double result = 0;
  long double a = x > 0 ? (long long int)(x / LN2) : (long long int)(-x * LN2);
  long double b = x > 0 ? x - a * LN2 : x + a * LN2;
  if (x > 710)
    result = S21_INF;
  else if (x <= -15)
    result = 0.0;
  else if (!x)
    result = 1;
  else {
    for (int i = 0; i < 50; i++) {
      result += s21_pow_int(b, i) / s21_fuctorial(i);
    }
    if (x > 0)
      result *= s21_pow_int(2, a);
    else
      result /= s21_pow_int(2, a);
  }
  return result;
}
// возвращает значение e, возведенное в заданную степень

long double s21_pow_int(double base, double expo) {
  double mult = base;
  if (expo < 0) {
    base = 1 / base;
    expo *= -1;
  }
  if (expo == 0) base = 1;
  if (expo > 0) {
    for (int i = 1; i < expo; expo--) {
      base *= mult;
    }
  }
  return base;
}

long double s21_fuctorial(long long int num) {
  long double res = 1.0;
  if (num == 1 || num == 0)
    res = 1;
  else if (num < 0)
    res = -1;  // ERROR //return -1.0 / 0;
  else {
    for (int i = 2; i <= num; i++) {
      res *= i;
    }
  }
  return res;
}

long double s21_fabs(double x) {
  long unsigned mask =
      0x7FFFFFFFFFFFFFFF;  // Маска для обнуления знакового бита
  long unsigned bits =
      *(long unsigned *)&x;  // Получаем битовое представление x
  bits &= mask;              // Обнуляем знаковый бит
  return *(double *)&bits;
}
// вычисляет абсолютное значение числа с плавающей точкой

long double s21_floor(long double x) {
  int xi = (int)x;
  return x < xi ? xi - 1 : xi;
}
// возвращает ближайшее целое число, не превышающее заданное значение

long double s21_fmod(double x, double y) {
  long double num = 0;
  num = x - (int)(x / y) * y;
  return num;
}
// //остаток операции деления с плавающей точкой

long double s21_log(double x) {
  double y = x;
  for (int i = 0; i < 100; i++) {
    y = y - (s21_exp(y) - x) / s21_exp(y);
  }
  return y;
}

long double s21_pow(double base, double exp) {
  long double result = 1;
  if (exp == 0 || base == 1 ||
      ((exp == -S21_INF || exp == S21_INF) && base == -1))
    ;
  else if (exp == 1)
    result = base;
  else if (base == 0 && exp > 0 ||
           ((base == -S21_INF || base == S21_INF) && exp < 0) ||
           (exp == -S21_INF && base != 0))
    result = 0;
  else if (base == 0 && exp < 0 ||
           ((base == -S21_INF || base == S21_INF) && exp > 0) || exp == S21_INF)
    result = S21_INF;
  else if (base != base || exp != exp || (base < 0 && exp != (int)exp))
    result = S21_NAN;

  else {
    if (base < 0 && s21_fabs(s21_fmod(exp, 2)) == 1) result = -1;
    result *= s21_exp(exp * s21_log(s21_fabs(base)));
  }

  return result;
}

// long double sin(double x){

// }

long double s21_sqrt(double x) {
  long double ans = s21_pow(x, 0.5);
  return ans;
}

// long double tan(double x){

// }
int main() {
  double a[6] = {NAN, 0, 1, -1, INFINITY, -INFINITY};
  int count = 1;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      printf("%d)base %.0lf exp %.0lf\n", count, a[i], a[j]);
      printf("pow :%.0lf\n s21_pow:%.0Lf\n\n", pow(a[i], a[j]),
             s21_pow(a[i], a[j]));
      count++;
    }
  }
  // int i = 0;
  // while (1) {
  // printf("original = %lf\n", pow(INFINITY, 0));
  // printf("Our Krym = %Lf\n", s21_pow(NAN, NAN));
  // i++;
  // }
  return 0;
}
