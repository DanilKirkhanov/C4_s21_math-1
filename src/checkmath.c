#include <stdio.h>
#include <math.h>
#define S21_INF 1.0/0.0
#define S21_NAN 0.0/0.0
#define S21_PI 3.14159265358979323846
#define S21_EPS 1e-17
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
int main(){
    double x;
    while(1){
        scanf("%lf", &x);
    printf("%.10Lf\n", s21_asin(x));
    printf("%.10lf\n\n", asin(x));
    printf("%.10Lf\n", s21_acos(x));
    printf("%.10lf\n\n", acos(x));
    printf("%.10Lf\n", s21_atan(x));
    printf("%.10lf\n\n\n", atan(x));
    }
}


long double s21_sin(double x){
long double result;
    if (x!=-S21_INF && x!=S21_INF && x!=S21_NAN) {
    while (x>=S21_PI * 2) x-=2*S21_PI;
    while (x<=-S21_PI * 2) x+=2*S21_PI;
long double i = 1;
result = x;
long double term = (long double)x;
while( term > S21_EPS || term < -S21_EPS){
    term *= ((-1) * x * x) / ((2.0 * i + 1) * (2.0 * i));
    result+=term;
    i++;
}
    } else result = S21_NAN;
    return result;
}

long double s21_cos(double x){
    while (x>=S21_PI * 2) x-=2*S21_PI;
    while (x<=-S21_PI * 2) x+=2*S21_PI;
    long double sin2 = s21_sin(x);
    long double result = sqrt(1-sin2*sin2);
    if (x>S21_PI/2 && x<3*S21_PI/2 || x<-S21_PI/2 && x>3*S21_PI/2) result*=-1;
    return result;
}
 long double s21_tan(double x){
     long double result = sin(x)/cos(x);
     return result;
 }



long double s21_atan(double x){
    long double result = x > -1 && x < 1 ? x : 1.0/x;
    
    if (x == S21_INF) result = S21_PI/2.0;
    else if (x== -S21_INF) result = -S21_PI/2.0;
    else if (x==1) result = 0.785398163;
    else if (x==-1) result = -0.785398163;
    else {
    long double term = x;
    for (int i = 1; i < 1000; i++){
        term *= (-1) * x * x;
        result+= x > -1 && x < 1 ? (term/(2*i+1)) : 1/term/(2*i+1);
    }
    if (!(x > -1 && x < 1)) result = (S21_PI * fabs(x) / (2 * x)) - result;
    }
    return result;
}
long double s21_asin (double x){
    long double result = S21_NAN;
    if (x==1) result = S21_PI/2;
    if (x==-1) result = -S21_PI/2;
    if (x!=S21_INF && x!=-S21_INF && x!=S21_NAN) result = s21_atan(x/sqrt(1-(x*x)));
    return result;
}
long double s21_acos(double x){
    return S21_PI/2 - s21_asin(x);
}



