

#include <iostream>   
#include <vector>  
#include <string>
#include <ctime>
using namespace std;

string RW_gen() // рандоматор прав доступа на чтение и запись
{
	int a = rand() % 2;
	if (a == 0)
		return "R";
	if (a == 1)
		return "W";

}


int main()
{
	setlocale(LC_ALL, "RUS");
	int n, m; // число субъектов(программ обработчиков) n и число объектов(содержат информацию) m 
	cout << "Введите число субъектов и объектов через строку" << endl;
	cin >> n >> m;
	cout << "Ручной ввод - 0, автоматический - 1" << endl;
	int inp = 0;
	cin >> inp;

	vector < vector <string> > RW(n, vector <string>(m));
	vector <int> LS(n); // уровни допуска субъектов S
	vector <int> LO(m); // уровень секретности объектов O
	srand(time(0));
	cout << "Генерация RW" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (inp == 0)
				cin >> RW[i][j];
			else
				RW[i][j] = RW_gen();
		}
	cout << "Вывод сгенерированной матрицы на права записи и чтения" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << RW[i][j] << ' ';
		cout << endl;
	}

	cout << "Генерация LS" << endl;

	for (int i = 0; i < n; i++)
	{
		if (inp == 0)
			cin >> LS[i];
		else
			LS[i] = rand() % 3 + 1;
	}

	cout << "Генерация LO" << endl;

	for (int i = 0; i < m; i++)
	{
		if (inp == 0)
			cin >> LO[i];
		else
			LO[i] = rand() % 3 + 1;
	}
	cout << "Вывод сгенерированного массива уровней допуска субъектов S" << endl;
	for (int i = 0; i < n; i++)
		cout << LS[i] << " ";
	cout << endl;
	cout << "Вывод сгенерированного массива уровней секретности объектов O" << endl;
	for (int i = 0; i < m; i++)
		cout << LO[i] << " ";
	cout << endl;
	bool ok = true;
	for (int i = 0; i < n; i++)
	{
		if (ok == false)
			break;
		for (int j = 0; j < m; j++)
		{
			if (RW[i][j].size() == 1)
			{
				if (((LS[i] < LO[j] && RW[i][j] == "W") || (LS[i] > LO[j] && RW[i][j] == "R")))
				{
					ok = false;
					break;
				}
			}

		}
	}
	cout << ok;



}