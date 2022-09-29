// infbez3.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
 /*Требуется написать программу, которая по заданному(2 ≤ ≤ 16) выводит в текстовый файл
output.txt последовательность бинарных кодов Грэя.Коды разделяются
пробелом или переводом на новую строку.*/
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
using namespace std;
string printvector(vector <int> a)
{
    ostringstream out;
    copy(a.begin(), a.end() - 1, ostream_iterator<int>(out, " "));
    out << a.back();
    return out.str() + "\n";
}
int sumvector(vector <int> a)
{
    int summa = 0;
    for (int i = 0; i < size(a); i++)
        summa += a[i];
    return summa;
}

string generator(vector <int>& a)
{
    if (sumvector(a) == size(a)) { return printvector(a); }
    else
    {
        if (a[size(a) - 1] == 0) { a[size(a) - 1] = 1;  return printvector(a); }
        else
        {
            a[size(a) - 1] = 0;
            int j = size(a) - 2;
            while (a[j] == 1 && j > 0) {

                if (a[j - 1] == 0)
                {
                    a[j] = 0;
                    a[j - 1] = 1;
                    return printvector(a);
                }
                else {
                    a[j] = 0;
                    a[j - 1] = 1;
                }
                j--;
            }
            if (j > 0)
            {
                a[j] = 1;
                return printvector(a);
            }
            else {
                return printvector(a);
            }

        }
    }
}

int main()
{
    int n;
    setlocale(LC_ALL, "rus");
    cout << "Введите n ";
    cin >> n;
    vector <int> a(n);
    int pow_2 = pow(2, n);
    ofstream out("output.txt");
    out << printvector(a);
    for (int i = 0; i < pow_2 - 1; i++)
        out << generator(a);
    out.close();
}

