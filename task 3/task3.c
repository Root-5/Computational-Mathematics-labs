#include <stdio.h>
#include <math.h>

double func(double x)
{
    return exp(x) + 1;
}

double trapezoidal_integral(double a, double b, int n)
{
    const double dy = (b - a) / n;

    double result = 0;
    for (int step = 0; step < n; ++step)
    {
        const double x1 = a + step * dy;
        const double x2 = a + (step + 1) * dy;

        result += 0.5 * (x2 - x1) * (func(x1) + func(x2));
    }

    return result;
}

int main()
{
    double result = trapezoidal_integral(0, 3.14, 10);
    printf("Result: %lf\n", result);
    printf("Diff: %lf", fabs(25.2822852863691 - result));
    return 0;
}