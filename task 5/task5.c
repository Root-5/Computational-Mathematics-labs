#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;

double n_appr_error_exp(double* y, int n, double h) {
    double sum = 0;
    for (int k = 0; k < n + 1; k++) {
        sum += abs(exp(k * h) - y[k]) * h;
    }
    return sum;
}

double n2_appr_error_exp(double* y, int n, double h) {
    double sum = 0;
    for (int k = 0; k < n + 1; k++) {
        sum += abs(exp(2 * k * h) - y[2 * k]) * h;
    }
    return sum;
}

double n_appr_error_sin(double* y, int n, double h) {
    double sum = 0;
    for (int k = 0; k < n + 1; k++) {
        sum += abs(2 - cos(k * h) - y[k]) * h;
    }
    return sum;
}

double n2_appr_error_sin(double* y, int n, double h) {
    double sum = 0;
    for (int k = 0; k < n + 1; k++) {
        sum += abs(2 - cos(2 * k * h) - y[2 * k]) * h;
    }
    return sum;
}

int main(int argc, char* argv[]) {
    double x0 = 0, x1 = 10;
    int n = 20;
    int n2 = 40;
    double h = (x1 - x0) / n;
    double h2 = (x1 - x0) / n2;

    double* y = new double[n + 1];
    double* y2 = new double[n2 + 1];
    double* g1 = new double[n + 1];
    double* g1_2 = new double[n2 + 1];
    double* g2 = new double[n + 1];
    double* g2_2 = new double[n2 + 1];

    cout.setf(ios::fixed);
    cout.precision(2);

    for (int i = 0; i < n + 1; i++) {
        g1[i] = exp(i * h);
        g2[i] = sin(i * h);
    }

    for (int i = 0; i < n2 + 1; i++) {
        g1_2[i] = exp(i * h2);
        g2_2[i] = sin(i * h2);
    }

    y[0] = 1;
    cout << "g = EXP" << endl << "k = 1" << endl;
    for (int j = 0; j < n + 1; j++) {
        y[j + 1] = y[j] + h * g1[j];
        //cout << "x = " << j * h << " y_appr = " << y[j] << " y_real = " << g1[j] << endl;
    }

    double approx_error = n_appr_error_exp(y, n, h);
    cout << "n = " << n <<" appr1_error = " << approx_error << endl;

    y2[0] = 1;
    for (int j = 0; j < n2 + 1; j++) {
        y2[j + 1] = y2[j] + h2 * g1_2[j];
        //cout << "x = " << j * h2 << " y_appr = " << y2[j] << " y_real = " << g1_2[j] << endl;
    }

    approx_error = n2_appr_error_exp(y2, n, h2);
    cout << "n = " << n2  << " appr1_error = " << approx_error << endl;

    y[1] = y[0] + h * g1[1];
    cout << endl << endl << "k = 2" << endl;
    for (int j = 2; j < n + 1; j++) {
        y[j] = y[j - 2] + h * (g1[j - 2] + g1[j]);
        //cout << "x = " << j * h << " y_appr = " << y[j] << " y_real = " << g1[j] << endl;
    }

    approx_error = n_appr_error_exp(y, n, h);
    cout << "n = " << n << " appr2_error = " << approx_error << endl;

    y2[1] = y2[0] + h2 * g1_2[1];
    for (int j = 2; j < n2 + 1; j++) {
        y2[j] = y2[j - 2] + h2 * (g1_2[j - 2] + g1_2[j]);
    }

    approx_error = n2_appr_error_exp(y2, n, h2);
    cout << "n = " << n2 << " appr2_error = " << approx_error << endl;

    cout << endl << endl << "k = 4" << endl;
    //cout << "y[1] = " << y[1] << endl;
    y[1] = (g1[0] + g1[1] + exp(h)) * h / 3 + y[0];
    for (int j = 2; j < n + 1; j++) {
        y[j] = y[j - 2] + h * (g1[j - 2] + 4 * g1[j - 1] + g1[j]) / 3;
        //cout << "x = " << j * h << " y_appr = " << y[j] << " y_real = " << g1[j] << endl;
    }

    approx_error = n_appr_error_exp(y, n, h);
    cout << "n = " << n << " appr4_error = " << approx_error << endl;

    y2[1] = (g1_2[0] + g1_2[1] + exp(h2)) * h2 / 3 + y2[0];
    for (int j = 2; j < n2 + 1; j++) {
        y2[j] = y2[j - 2] + h2 * (g1_2[j - 2] + 4 * g1_2[j - 1] + g1_2[j]) / 3;
    }

    approx_error = n2_appr_error_exp(y2, n, h2);
    cout << "n = " << n2 << " appr4_error = " << approx_error << endl;

    cout << endl << endl << endl << "g = SIN" << endl << "k = 1" << endl;
    y[0] = 1;
    for (int j = 0; j < n + 1; j++) {
        y[j + 1] = y[j] + h * g2[j];
        //cout << "x = " << j * h << " y_appr = " << y[j] << " y_real = " << 2 - cos(j * h) << endl;
    }

    approx_error = n_appr_error_sin(y, n, h);
    cout << "n = " << n << " appr1_error = " << approx_error << endl;

    y2[0] = 1;
    for (int j = 0; j < n2 + 1; j++) {
        y2[j + 1] = y2[j] + h2 * g2_2[j];
        //cout << "x = " << j * h2 << " y_appr = " << y2[j] << " y_real = " << 2 - cos(j * h2) << endl;
    }
    
    approx_error = n2_appr_error_sin(y2, n, h2);
    cout << "n = " << n2 << " appr1_error = " << approx_error << endl;


    cout << endl << endl << "k = 2" << endl;
    y[1] = sin(h);
    cout << y[1];
    for (int j = 2; j < n + 1; j++) {
        y[j] = y[j - 2] + h * (g2[j - 2] + g2[j]);
        cout << "x = " << j * h << " y_appr = " << y[j] << " y_real = " << 2 - cos(j * h) << endl;
    }

    approx_error = n_appr_error_sin(y, n, h);
    cout << "n = " << n << " appr2_error = " << approx_error << endl;

    y2[1] = sin(h2);
    for (int j = 2; j < n2 + 1; j++) {
        y2[j] = y2[j - 2] + h2 * (g2_2[j - 2] + g2_2[j]);
    }

    approx_error = n2_appr_error_sin(y2, n, h2);
    cout << "n = " << n2 << " appr2_error = " << approx_error << endl;

    cout << endl << endl << "k = 4" << endl;
    y[1] = (g2[0] + g2[1] + sin(h)) * h / 3 + y[0];
    //cout << "y[1] = " << y[1] << endl;
    for (int j = 2; j < n + 1; j++) {
        y[j] = y[j - 2] + h * (g2[j - 2] + 4 * g2[j - 1] + g2[j]) / 3;
        //cout << "x = " << j * h << " y_appr = " << y[j] << " y_real = " << 2 - cos(j * h) << endl;
    }

    approx_error = n_appr_error_sin(y, n, h);
    cout << "n = " << n << " appr4_error = " << approx_error << endl;

    y2[1] = (g2_2[0] + g2_2[1] + sin(h2)) * h2 / 3 + y2[0];
    for (int j = 2; j < n2 + 1; j++) {
        y2[j] = y2[j - 2] + h2 * (g2_2[j - 2] + 4 * g2_2[j - 1] + g2_2[j]) / 3;
        //cout << "x = " << j * h << " y_appr = " << y[j] << " y_real = " << 2 - cos(j * h) << endl;
    }

    approx_error = n2_appr_error_sin(y2, n, h2);
    cout << "n = " << n2 << " appr4_error = " << approx_error << endl;

    return 0;
}