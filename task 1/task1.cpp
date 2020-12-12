#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include "math.h"
#include <locale.h>

double func(double x, double a, double b, double c)
{
    return x * x * x + a * x * x + b * x + c;
}
double search(double right_part, double left_part, double a, double b, double c, double epsilon)
{
    double answer = (right_part + left_part) / 2;
    double k = func(right_part, a, b, c) - func(left_part, a, b, c) > 0 ? 1 : -1;
    while (fabs(left_part - right_part) >= epsilon)
    {
        if (func(answer, a, b, c) * k < 0)
            left_part = answer;
        else
            right_part = answer;
        answer = (right_part + left_part) / 2;
    }
    return answer;
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");

    double a, b, c, epsilon;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << std::endl
              << "b = ";
    std::cin >> b;
    std::cout << std::endl
              << "c = ";
    std::cin >> c;
    std::cout << std::endl
              << "epsilon = ";
    scanf("%lf", &epsilon);
    std::cin >> epsilon;
    std::cout << std::endl;
    double discreminant = 4 * (a * a - 3 * b);
    double delta;

    if (discreminant > epsilon * epsilon)
    {
        double alpha = (2 * (-a) - sqrt(discreminant)) / 6;
        double betta = (2 * (-a) + sqrt(discreminant)) / 6;
        double x1 = func(alpha, a, b, c);
        double x2 = func(betta, a, b, c);

        if (x1 > epsilon && x2 > epsilon)
        {
            delta = alpha;
            while (func(delta, a, b, c) > 0)
            {
                delta--;
            }
            std::cout << "answer = " << search(alpha, delta, a, b, c, epsilon) << std::endl;
        }
        if (x1 < -epsilon && x2 < -epsilon)
        {
            delta = betta;
            while (func(delta, a, b, c) < 0)
            {
                delta++;
            }
            std::cout << "answer = " << search(delta, betta, a, b, c, epsilon) << std::endl;
        }
        if (x1 > epsilon && abs(x2) < epsilon)
        {
            std::cout << "answer = " << betta << std::endl;
            delta = alpha;
            while (func(delta, a, b, c) > 0)
            {
                delta--;
            }
            std::cout << "answer = " << search(alpha, delta, a, b, c, epsilon) << std::endl;
        }
        if (abs(x1) < epsilon && x2 < -epsilon)
        {
            std::cout << "answer = " << alpha << std::endl;
            delta = betta;
            while (func(delta, a, b, c) < 0)
            {
                delta++;
            }
            std::cout << "answer = " << search(delta, betta, a, b, c, epsilon) << std::endl;
        }
        if (x1 > epsilon && x2 < -epsilon)
        {
            delta = alpha;
            while (func(delta, a, b, c) > 0)
            {
                delta--;
            }
            std::cout << "answer = " << search(alpha, delta, a, b, c, epsilon) << std::endl;
            std::cout << "answer = " << search(betta, alpha, a, b, c, epsilon) << std::endl;
            delta = betta;
            while (func(delta, a, b, c) < 0)
            {
                delta++;
            }
            std::cout << "answer = " << search(delta, betta, a, b, c, epsilon) << std::endl;
        }
        if (abs(x1) < epsilon && abs(x2) < epsilon)
        {
            std::cout << "answer = " << (alpha + betta) / 2 << std::endl;
        }
    }
    else if (discreminant < epsilon * epsilon)
    {
        if (fabs(func(0, a, b, c)) < epsilon)
        {
            std::cout << "answer = 0";
        }
        if (func(0, a, b, c) < -epsilon)
        {
            delta = 0;
            while (func(delta, a, b, c) < epsilon)
            {
                delta++;
            }
            std::cout << "answer = " << search(delta, 0.0, a, b, c, epsilon) << std::endl;
        }
        if (func(0, a, b, c) > epsilon)
        {
            delta = 0;
            while (func(delta, a, b, c) > 0)
            {
                delta--;
            }
            std::cout << "answer = " << search(0.0, delta, a, b, c, epsilon) << std::endl;
        }
    }
    system("pause");
    return 0;
}