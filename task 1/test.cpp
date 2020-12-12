#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

typedef struct sotr
{
    int id;
    string second_name;
    char pol;
    int bd;
    int god;
} sotrudnik;

int main()
{
    setlocale(LC_ALL, "ru");
    const int n = 10;
    int result = 0;

    sotrudnik table[n] = {
        {1, "Анисимов Ю. П.", 'М', 1970, 1989},
        {2, "Иванов И. Н.", 'М', 1980, 2002},
        {3, "Махова О. И.", 'Ж', 1960, 1980},
        {4, "Огарев К. М.", 'М', 1991, 2012},
        {5, "Егорова П. К.", 'Ж', 1993, 2011},
        {6, "Голикова О. И.", 'Ж', 1972, 1990},
        {7, "Сотников Т. С.", 'М', 1963, 1990},
        {8, "Комов В. И.", 'М', 1979, 2005},
        {9, "Лебедев А. А.", 'М', 1959, 1981},
        {10, "Димова В. В.", 'Ж', 1991, 2010},
    };
    //Print table
    for (int i = 0; i <= 9; i++)
    {
        cout << table[i].id << " " << table[i].second_name << " " << table[i].pol << " " << table[i].bd << ' ' << table[i].god << endl;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (2020 - table[i].bd <= 40)
        {
            result++;
        }
    }
    cout << result << endl;
}