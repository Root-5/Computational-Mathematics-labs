#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

const double eps = 0.001; ///< желаемая точность
int ITERS = 0;
/// N - размерность матрицы; A[N][N] - матрица коэффициентов, F[N] - столбец свободных членов,
/// X[N] - начальное приближение, ответ записывается также в X[N];
void Jacobi(int N, double **A, double *F, double *X) {
    double *TempX = new double[N];
    double norm; // норма, определяемая как наибольшая разность компонент столбца иксов соседних итераций.

    do {
        for (int i = 0; i < N; i++) {
            TempX[i] = F[i];
            for (int g = 0; g < N; g++) {
                if (i != g)
                    TempX[i] -= A[i][g] * X[g];
            }
            TempX[i] /= A[i][i];
        }
        norm = fabs(X[0] - TempX[0]);
        for (int h = 0; h < N; h++) {
            if (fabs(X[h] - TempX[h]) > norm)
                norm = fabs(X[h] - TempX[h]);
            X[h] = TempX[h];
        }
        ITERS++;
    } while (norm > eps);
    delete[] TempX;
}

int main() {
    int N = 0;
    cout << "Enter matrix dimension:";
    cin >> N;
    double **matrix = (double **) malloc(sizeof(double *) * N);
    for (int i = 0; i < N; ++i) {
        matrix[i] = (double *) malloc(sizeof(double) * N);
    }
    //Enter matrix
    cout << "Enter matrix values" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }
    //Print
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << endl;
        }
    }

    //Enter result values
    cout << "Enter result values" << endl;
    double *f = (double *) malloc(sizeof(double) * N);
    for (int i = 0; i < N; ++i) {
        cin >> f[i];
    }
    //Print result values
    for (int i = 0; i < N; ++i) {
        cout << f[i] << endl;
    }
    double *x = (double *) malloc(sizeof(double) * N);
    //make zero
    for (int i = 0; i < N; ++i) {
        x[i] = 0;
    }
    double start = clock();
    Jacobi(N, matrix, f, x);
    double endtime = clock();
    //Print x
    for (int i = 0; i < N; ++i) {
        cout << x[i] << endl;
    }
    cout << "Iters:" << ITERS << endl;
    return 0;
}