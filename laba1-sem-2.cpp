#include <iostream>
#include <locale.h>
using namespace std;
const int N = 20;
int a[N][N];
double b[N][N];
template <typename Cin>
Cin CinMassive(Cin a[][N], int n)
{
		for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
		cin >> a[i][j];
		
		}	
	}
}
template <typename Sr, typename Sr2>
Sr2 SredneeAr(Sr a[][N], int n, Sr2 log)
{
	double sum = 0, temp = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j % 2 != 0)
			{
				sum+=a[i][j];
				temp++;
			}
	    }
	}
	double sr = sum / temp;
	return sr;
}
int main()
{

	setlocale(LC_ALL, "rus");
	int n;
		cout << "Введите размер квадратной матрицы --- > ";
	cin >> n;
		cout << "Всё просто! Если хочешь целочисленный массив, то введи неотрицательное число, если дробный, то отрицательное число! ";
		cout << endl << "Выбор за тобой ---> ";
		double t;
		cin >> t; 
	if (t >= 0)
	{
	CinMassive<int>(a, n);
		cout << "Посчитаем среднее арифметическое суммы элементов чётных столбцов ---> ";
		double log;
		cout << SredneeAr(a, n, log);
	}
	else
	{
	CinMassive<double>(b, n);
		cout << "Посчитаем среднее арифметическое суммы элементов чётных столбцов ---> ";
		double log;
		cout << SredneeAr(b, n, log);
	}
    return 0;
}
