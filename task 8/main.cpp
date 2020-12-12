#include <iostream>
#define N 3

using namespace std;
/**
	 * n - число уравнений (строк матрицы)
	 * b - диагональ, лежащая над главной (нумеруется: [0;n-2])
	 * c - главная диагональ матрицы A (нумеруется: [0;n-1])
	 * a - диагональ, лежащая под главной (нумеруется: [1;n-1])
	 * f - правая часть (столбец)
	 * x - решение, массив x будет содержать ответ
	 */
void solveMatrix(int n, double *a, double *c, double *b, double *f, double *x)
{
    double m;
    for (int i = 1; i < n; i++)
    {
        m = a[i] / c[i - 1];
        c[i] = c[i] - m * b[i - 1];
        f[i] = f[i] - m * f[i - 1];
    }

    x[n - 1] = f[n - 1] / c[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        x[i] = (f[i] - b[i] * x[i + 1]) / c[i];
    }
}

void example(double a[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                a[i][j] = 1;
            else
            {
                a[i][j] = 0;
            }
        }
}

void printMatrix(double a[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

double *getMainDiagonal(double matrix[N][N])
{
    double *result = (double *)malloc(sizeof(double) * N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                result[i] = matrix[i][j];
        }
    }

    //PRINT
    for (int i = 0; i < N; i++)
        cout << result[i] << " ";
    cout << endl;
    return result;
}
double *getUpperDiagonal(double matrix[N][N])
{
    double *result = (double *)malloc(sizeof(double) * (N - 1));
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j == i + 1 && (i + 1) < N)
                result[i] = matrix[i][j];
        }
    }
    //PRINT
    for (int i = 0; i < N - 1; i++)
        cout << result[i] << " ";
    cout << endl;
    return result;
}
double *getBottomDiagonal(double matrix[N][N])
{
    double *result = (double *)malloc(sizeof(double) * N);
    for (int i = 0; i < N; i++)
        result[i] = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j == i - 1 && (i - 1) >= 0)
                result[i] = matrix[i][j];
        }
    }
    //PRINT
    for (int i = 1; i < N; i++)
        cout << result[i] << " ";
    cout << endl;
    return result;
}

int main()
{

    double matrix[N][N] = {{1, -1, 0},
                           {1.1, 1.01, 1},
                           {0, 1, -1}};
    double res[N] = {1, 2, 3};
    double *f = (double *)malloc(sizeof(double) * N);
    for (int i = 0; i < N; i++)
    {
        f[i] = res[i];
    }
    printMatrix(matrix);
    double *x = (double *)malloc(sizeof(double) * N);
    double *c = getMainDiagonal(matrix);
    double *b = getUpperDiagonal(matrix);
    double *a = getBottomDiagonal(matrix);
    solveMatrix(N, a, c, b, f, x);
    //PRINT X
    cout<<"ANSWER:";
    for (int i = 0; i < N; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
    free(c);
    free(b);
    free(a);
    free(x);
    free(f);
    return 0;
}