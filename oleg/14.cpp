#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

typedef struct order
{
    int rsplat;
    int rspoluch;
    int summa;
} ORDER;

int main()
{
    setlocale(LC_ALL, "ru");
    const int n = 8;
    int x;
    ORDER a[n];
    //вводим данные
    for (int i = 0; i < 8; i++)
    {
        cin >> a[i].rsplat >> a[i].rspoluch >> a[i].summa;
    }
    cin >> x;
    int prover = 0;
    for (int i = 0; i < 8; i++)
    {

        if (a[i].rspoluch == x)
        {
            prover++;
            cout << a[i].rsplat << endl;
        }
    }
    if (prover == 0)
        cout << "Данного расчетного счета нет" << endl;
}