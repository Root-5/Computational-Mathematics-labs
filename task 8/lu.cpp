#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    double sum = 0;

    cout << "Введите порядок матрицы\n n = ";
    cin >> n;

    double A[n][n];
    double L[n][n];
    double U[n][n];
    double B[n];
    //задаем матрицу A[][] ...

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "\na[" << i << "][" << j << "] = ";
            cin >> A[i][j];

            L[i][j] = 0;
            U[i][j] = 0;

            if (i == j)
                U[i][j] = 1;
        }
    }

    //задаем решение B[]
    for (int i = 0; i < n; i++)
    {
        cout << "\nb[" << i << "] = ";
        cin >> B[i];
    }
    cout << endl
         << endl;

    //==============================================

    //находим первый столбец L[][] и первую строку U[][]

    int start = clock();
    for (int i = 0; i < n; i++)
    {
        L[i][0] = A[i][0];
        U[0][i] = A[0][i] / L[0][0];
    }

    //дальше вычисляем L[][], U[][] по формуле

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i >= j) //нижний треугольник
            {
                sum = 0;
                for (int k = 0; k < j; k++)
                    sum += L[i][k] * U[k][j];

                L[i][j] = A[i][j] - sum;
            }
            else // верхний
            {
                sum = 0;
                for (int k = 0; k < i; k++)
                    sum += L[i][k] * U[k][j];

                U[i][j] = (A[i][j] - sum) / L[i][i];
            }
        }
    }

    //====================================================
    cout << "\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "  " << L[i][j] << "   ";
        cout << "\n\n";
    }

    cout << "\n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "  " << U[i][j] << "   ";
        cout << "\n\n";
    }

    cout << endl
         << endl;
    cout << "y vector:" << endl;

    double *y = (double *)malloc(sizeof(double) * n);
    y[0] = B[0] / L[0][0];

    for (int i = 1; i < n; i++)
    {
        double summa = 0;
        for (int k = 0; k < i; k++)
        {
            summa += L[i][k] * y[k];
            //printf("\nsumma on iteration #%f : %f\n", i, summa);
        }
        y[i] = (B[i] - summa) / L[i][i];
        //printf("\ny[%d] on iteration #%d : %f\n", i, i, summa);
    }

    for (int i = 0; i < n; i++)
        cout << y[i] << " ";
    cout << endl;

    double *x = (double *)malloc(sizeof(double) * n); //Находим x[n] по формуле

    x[n - 1] = y[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        double summa = 0;
        for (int k = i + 1; k < n; k++)
        {
            summa += U[i][k] * x[k];
        }
        x[i] = y[i] - summa;
    }
    int endtime = clock();
    cout << endl
         << endl;
    cout << "X vector: " << endl;
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
    cout << endtime - start << endl;
    free(x);
    return 0;
}