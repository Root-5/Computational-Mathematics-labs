#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x, double l, double h) {
    return l * sin(x) / h;
}

double absolute_value(double x) {
    if (x < 0) return -x;
    return x;
}

double find_root(double start, double epsilon, double l, double h) {
    double start_point = start;
    double x = func(start_point, l, h);
    int i = 1;
    while (absolute_value(x - start_point) > epsilon) {
        start_point = x;
        x = func(start_point, l, h);
        i++;
        printf("\niteration #%d", i);
    }
    printf("\nCount of iterations: %d\n", i);
    return x;
}

//task #2
int main() {
    double l, h, epsilon;
    printf("Enter a variables: l, h, epsilon:");
    scanf("%lf %lf %lf", &l, &h, &epsilon);
    if (l < h)
        return 0;

    if (l > h) {
        printf("Enter start point between 0 and PI/2:");
        double start = 0;
        scanf("%lf", &start);
        printf("%lf\n", find_root(start, epsilon, l, h));
        printf("%lf\n", find_root(-start, epsilon, l, h));
    }
    return 0;
}