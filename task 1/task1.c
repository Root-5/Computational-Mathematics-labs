#include <stdio.h>
#include <math.h>

double func(double a, double b, double c, double d, double x)
{
    return (a * pow(x, 3) + b * pow(x, 2) + c * x + d);
}

int main()
{
    double epsilon = 0.0000001;
    double delta = 0.1;
    int a = 1, b = -6, c = 11, d = -6;
    printf("%dx^3 + %dx^2 + %dx + %d", a, b, c, d);
    double discriminant = b * b - (4 * a * c);
    
}