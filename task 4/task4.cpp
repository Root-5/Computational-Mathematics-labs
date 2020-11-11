#include <iostream>
#include <vector>
#include <math.h>

double function(double x)
{
    return pow(x, 3) - exp(x) + 1;
}

double interpolaton(std::vector<double> x_vector, std::vector<double> y_vector, double x)
{
    double result = 0;
    for (int i = 0; i < x_vector.size(); i++)
    {
        double multiplication = 1;
        for (int j = 0; j < x_vector.size(); j++)
        {
            if (i != j)
            {
                multiplication *= (x - x_vector[j]) / (x_vector[i] - x_vector[j]);
            }
        }
        result += multiplication * y_vector[i];
    }
    return result;
}

int main(int argc, char const *argv[])
{
    double a = 0, b = 10, x = 8.1;
    int k = 10;
    double h = (b - a) / (k - 1);

    std::vector<double> x_vector;
    std::vector<double> y_vector;

    for (int i = 0; i < k; ++i)
    {
        x_vector.push_back(a + i * h);
        y_vector.push_back(function(x_vector[i]));
    }

    double result = interpolaton(x_vector, y_vector, x);
    printf("Ln(x): %lf \nf(x): %lf\nError: %lf\n", result, function(x), std::abs(function(x) - result));

    return 0;
}
