#include "s21_math.h"

// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
int s21_abs(int x) { return x < 0 ? -x : x; }

long double s21_atan(double x) {
  long double result = x > -1 && x < 1 ? x : 1.0 / x;
  if (x == S21_INF)
    result = S21_PI / 2.0;
  else if (x == -S21_INF)
    result = -S21_PI / 2.0;
  else if (x == 1)
    result = 0.785398163;
  else if (x == -1)
    result = -0.785398163;
  else {
    long double term = x;
    for (int i = 1; i < 1000; i++) {
      term *= (-1) * x * x;
      result += x > -1 && x < 1 ? (term / (2 * i + 1)) : 1 / term / (2 * i + 1);
    }
    if (!(x > -1 && x < 1)) result = (S21_PI * s21_fabs(x) / (2 * x)) - result;
  }
  return result;
}
long double s21_asin(double x) {
  long double result = S21_NAN;
  if (x == 1) result = S21_PI / 2;
  if (x == -1) result = -S21_PI / 2;
  if (x != S21_INF && x != -S21_INF && x != S21_NAN)
    result = s21_atan(x / s21_sqrt(1 - (x * x)));
  return result;
}
long double s21_acos(double x) { return S21_PI / 2 - s21_asin(x); }
long double s21_sin(double x) {
  long double result;
  if (x != -S21_INF && x != S21_INF && x != S21_NAN) {
    while (x >= S21_PI * 2) x -= 2 * S21_PI;
    while (x <= -S21_PI * 2) x += 2 * S21_PI;
    long double i = 1;
    result = x;
    long double term = (long double)x;
    while (term > S21_EPS || term < -S21_EPS) {
      term *= ((-1) * x * x) / ((2.0 * i + 1) * (2.0 * i));
      result += term;
      i++;
    }
  } else
    result = S21_NAN;
  return result;
}

long double s21_cos(double x) {
  while (x >= S21_PI * 2) x -= 2 * S21_PI;
  while (x <= -S21_PI * 2) x += 2 * S21_PI;
  long double sin2 = s21_sin(x);
  long double result = s21_sqrt(1 - sin2 * sin2);
  if ((x > S21_PI / 2 && x < 3 * S21_PI / 2) ||
      (x < -S21_PI / 2 && x > 3 * S21_PI / 2))
    result *= -1;
  return result;
}
long double s21_tan(double x) {
  long double result = s21_sin(x) / s21_cos(x);
  return result;
}

long double s21_ceil(double x) {
  long double xi = (long int)x;
  long double result;
  if (x == S21_INF || x == -S21_INF || x != x)
    result = x;
  else
    result = x > xi ? xi + 1 : xi;
  return result;
}

long double s21_exp(double x) {
  long double result = 1;
  long double temp = 1;
  if (x > 710)
    result = S21_INF;
  else if (x == -S21_INF)
    result = 0;
  else if (x < 0)
    result = 1 / s21_exp(-x);
  else if (x == 0)
    result = 1;
  else {
    for (int i = 1; temp > S21_EPS; i++) {
      temp *= x / i;
      result += temp;
    }
  }
  return result;
}
// возвращает значение e, возведенное в заданную степень

long double s21_fabs(double x) {
  long unsigned mask =
      0x7FFFFFFFFFFFFFFF;  // Маска для обнуления знакового бита
  long unsigned bits =
      *(long unsigned *)&x;  // Получаем битовое представление x
  bits &= mask;              // Обнуляем знаковый бит
  return *(double *)&bits;
}
// вычисляет абсолютное значение числа с плавающей точкой

long double s21_floor(double x) {
  int xi = (int)x;
  long double result;
  if (x == S21_INF || x == -S21_INF || x != x)
    result = x;
  else
    result = x < xi ? xi - 1 : xi;
  return result;
}
// возвращает ближайшее целое число, не превышающее заданное значение

long double s21_fmod(double x, double y) {
  long double num = 0;
  if (x == S21_INF || x == !x || x == -S21_INF || y == 0.0)
    num = S21_NAN;
  else if (y == S21_INF || y == -S21_INF)
    num = x;

  else
    num = x - (int)(x / y) * y;
  return num;
}
// //остаток операции деления с плавающей точкой

long double s21_log(double x) {
  long double y = 0;
  if (x < 0)
    y = S21_NAN;
  else if (x == 0)
    y = -S21_INF;
  else if (x == S21_INF)
    y = S21_INF;
  else {
    for (int i = 0; i < 100; i++) {
      y += 2 * (x - s21_exp(y)) / (x + s21_exp(y));
    }
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
  else if (base != base || exp != exp)
    result = S21_NAN;
  else if ((base == 0 && exp > 0) ||
           ((base == -S21_INF || base == S21_INF) && exp < 0) ||
           (exp == -S21_INF && base != 0))
    result = 0;
  else if ((base == 0 && exp < 0) ||
           ((base == -S21_INF || base == S21_INF) && exp > 0) || exp == S21_INF)
    result = S21_INF;
  else if ((base < 0 && exp != (int)exp))
    result = S21_NAN;

  else {
    if (base < 0 && s21_fabs(s21_fmod(exp, 2)) == 1) result = -1;
    result *= s21_exp(exp * s21_log(s21_fabs(base)));
  }

  return result;
}

long double s21_sqrt(double x) {
  long double ans = s21_pow(x, 0.5);
  return ans;
}

// // }
int main() {
  //   double a[6] = {NAN, 0, 2, -5.23134, INFINITY, -INFINITY};
  //   // int count = 1;
  //   double x;
  //   for (int i = 0; i < 6; i++) {
  //     for (int j = 0; j < 6; j++) {
  //       // scanf("%lf %lf", &x, &y);
  //       scanf("%lf", &x);

  //       // printf("%d)x: %.0lf y %.0lf\n", count, a[j], a[i]);
  //       printf("orig %lf\n", log(x));
  //       printf("our %Lf\n", s21_log(x));
  //       // printf("%lf\n", x);
  //     }
  //   }
  return 0;
}
