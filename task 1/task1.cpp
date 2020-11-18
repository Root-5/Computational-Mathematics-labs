#include <stdio.h>
#include <math.h>

#define MAX_ITER 100000

double f(double x) {
    return x * x * x - 4 * x * x + x + 1;
}

double getRoot(double a_, double b_, double epsilon) {
    double a = a_;
    double b = b_;
    int iter = 0;
    double result = (a + b) / 2;
    while ((b - a) > epsilon) {
        double tmp_a = f(a);
        double tmp_result = f(result);
        if ((tmp_a > 0 && tmp_result < 0) || (tmp_a < 0 && tmp_result > 0))
            b = result;
        else
            a = result;
        result = (a + b) / 2;
        iter++;
        if (iter > MAX_ITER) return result;
    }
    return result;
}

int main() {
    double a = -1;
    double b = 0;
    double epsilon = 0.001;
    printf("Started\n");
    double res = getRoot(a, b, epsilon);
    printf("Result: %f", res);
}