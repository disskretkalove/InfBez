// lab4(1).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool IsSimple(int c)
{
    for (int i = c - 1; i > 1; i--)
    {
        if (c % i == 0) return false;
    }
    return true;
}

vector<int> GetCombinations(int multNumber)
{
    vector<int> combVector;

    for (int c = 1111; c < 10000; c++)
    {
        int check = c;
        int multiply = 1;

        while (check)
        {
            multiply *= check % 10;
            check /= 10;
        }

        if (multiply == multNumber && IsSimple(c))
        {
            combVector.push_back(c);
        }

    }

    return combVector;
}

void Output(vector<int> resultVector)
{
    ofstream fout("output.txt");

    if (fout.is_open())
    {
        fout << resultVector.size() << " ";

        for (int i = 0; i < resultVector.size(); i++)
        {
            fout << resultVector[i] << " ";
        }
    }
    else
    {
        cout << "file does not exist.";
    }

    fout.close();
}


int main()
{
    vector<int> test;
    test = GetCombinations(243);
    Output(test);
}
