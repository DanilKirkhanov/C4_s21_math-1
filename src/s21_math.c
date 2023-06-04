#include "s21_math.h"

// #include <math.h>
#include <stdio.h>

#define LN2 0.693147180559945309417232
long double s21_fuctorial(long long int num);
long double s21_pow_int(double base, double expo);

int s21_abs(int x) { return x < 0 ? x : -x; }

// long double acos(double x) {

// }

// long double asin(double x) {

// }
// вычисляет арксинус

// long double atan(double x) {

// }
// вычисляет арктангенс

long double s21_ceil(double x) {
  int xi = (int)x;
  return x < xi ? xi + 1 : xi;
}
// возвращает ближайшее целое число, не меньшее заданного значения

// long double cos(double x){
//     for
// }

long double s21_exp(double x) {
  //   long double sum = 1;
  //   long double term = 1;
  //   for (int i = 1; i < 1000; i++) {
  //     term = term * x / i;
  //     sum += term;
  //   }
  //   long double sum = 2.71828182845904523536;
  if (x == -1.0 / 0) return 0;
  long double result = 0;
  long double a = (long long int)(x / LN2);
  long double b = x - a * LN2;
  //   printf("a = %Lf, b = %Lf\n", a, b);
  for (int i = 0; i < 50; i++) {
    result += s21_pow_int(b, i) / s21_fuctorial(i);
    // printf("%Lf\n", s21_pow_int(b, i));
  }
  result *= s21_pow_int(2, a);
  return result;
  //   return sum;
}
// возвращает значение e, возведенное в заданную степень

long double s21_pow_int(double base, double expo) {
  double mult = base;
  if (expo < 0) {
    base = 1 / base;
    expo *= -1;
  }
  //   printf("%Lf\n", mult);
  if (expo == 0) base = 1;
  if (expo > 0) {
    for (int i = 1; i < expo; expo--) {
      base *= mult;
    }
    // if (expo > 0 && expo != 1) base = s21_pow(base, (1 / expo));
  }
  return base;
}

long double s21_fuctorial(long long int num) {
  long double res = 1.0;
  if (num == 1 || num == 0) return 1;
  if (num < 0) return -1.0 / 0;
  for (int i = 2; i <= num; i++) {
    res *= i;
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

// long double fmod(double x, double y){

// }
// //остаток операции деления с плавающей точкой

long double s21_log(double x) {
  double y = x;
  for (int i = 0; i < 100; i++) {
    y = y - (s21_exp(y) - x) / s21_exp(y);
  }
  return y;
}

long double s21_pow(double base, double expo) {
  // int mult = base;
  // if(s21_exp < 0) {
  //     base = 1/base;
  //     s21_exp *= -1;
  // }
  // if(s21_exp > 0){
  //     for (int i = 1; i < s21_exp; s21_exp--) {
  //         base *= mult;
  //     }
  //     if(s21_exp > 0 && s21_exp != 1) base = s21_pow(base, (1/s21_exp));
  // }
  // return base;
  return s21_exp(expo * s21_log(base));
}

// long double sin(double x){

// }

long double s21_sqrt(double x) {
  //   double x = 1; // Начальное приближение
  //   int a = 0;
  //   double eps = 0.000001; // Точность
  //   double dx; // Разность между двумя приближениями
  //   do {
  //     dx = (x * x - a) / (2 * x); // Вычисляем разность
  //     x = x - dx; // Вычисляем следующее приближение
  //   } while (s21_fabs(dx) > eps); // Повторяем пока разность больше точности
  //   return x; // Возвращаем приближенный корень
  long double ans = s21_pow(x, 0.5);
  // printf("%f\n", s21_pow(x, 2));
  return ans;
}

// long double tan(double x){

// }
int main() {
  printf("%Lf\n", s21_sqrt(16));
  //   printf("%Lf\n", log(10000.0));
  return 0;
}