#include "s21_math.h"
#include "stdio.h"

int abs(int x) {
    return x<0 ? x : -x;
}

// long double acos(double x) {

// }

// long double asin(double x) {

// }
//вычисляет арксинус

// long double atan(double x) {

// }
//вычисляет арктангенс

long double ceil(double x) {
    int xi = (int)x;
    return x < xi ? xi + 1 : xi;
}
//возвращает ближайшее целое число, не меньшее заданного значения

// long double cos(double x){
//     for 
// }

long double exp(double x){
    long double sum = 1;
    long double term = 1;
    for (int i = 1; i < 10000; i++) {
        term = term * x / i;
        sum += term;
    }
    return sum;
}
//возвращает значение e, возведенное в заданную степень

long double fabs(double x){
    long unsigned mask = 0x7FFFFFFFFFFFFFFF; // Маска для обнуления знакового бита
    long unsigned bits = *(long unsigned *)&x; // Получаем битовое представление x
    bits &= mask; // Обнуляем знаковый бит
    return *(double *)&bits;
}
//вычисляет абсолютное значение числа с плавающей точкой

long double floor(long double x){
    int xi = (int)x;
    return x < xi ? xi - 1 : xi;
}
//возвращает ближайшее целое число, не превышающее заданное значение

// long double fmod(double x, double y){

// }
// //остаток операции деления с плавающей точкой

long double log(double x){
    double y = x;
    for (int i = 0; i < 1000; i++) {
        y = y - (exp(y) - x) / exp(y);
    }
    return y;
}

long double pow(double base, double expo){
    // int mult = base;
    // if(exp < 0) {
    //     base = 1/base;
    //     exp *= -1;
    // }
    // if(exp > 0){
    //     for (int i = 1; i < exp; exp--) {
    //         base *= mult;
    //     }
    //     if(exp > 0 && exp != 1) base = pow(base, (1/exp));
    // }
    // return base;
    return exp(expo * log(base));
}

// long double sin(double x){

// }

long double sqrt(double x){
//   double x = 1; // Начальное приближение
//   int a = 0;
//   double eps = 0.000001; // Точность
//   double dx; // Разность между двумя приближениями
//   do {
//     dx = (x * x - a) / (2 * x); // Вычисляем разность
//     x = x - dx; // Вычисляем следующее приближение
//   } while (fabs(dx) > eps); // Повторяем пока разность больше точности
//   return x; // Возвращаем приближенный корень
    long double ans = pow(x, 0.5);
    // printf("%f\n", pow(x, 2));
    return ans;
}

// long double tan(double x){

// }
int main(){
    printf("%Lf\n", ceil(3.0));
    return 0;
}