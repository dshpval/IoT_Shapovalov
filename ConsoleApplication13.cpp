#include <pch.h>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int* insertionSort(int mas[], const int n)
{
	int x = 0, j = 0;
	for (int i = 1; i < n; i++)
	{
		x = mas[i];
		j = i - 1;
		while (j >= 0 && mas[j] < x)
		{
			mas[j + 1] = mas[j];
			j--;
		}
		mas[j + 1] = x;
	}
	return mas;
}

double sortAndCount(int mas[])
{
	const int n = 5;
	int x[n][n], y[n], s;
	double f[n], F = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			x[i][j] = mas[5 * i + j];
		}
	}
	/*sort()*/
	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			y[i] = x[i][j];
		}
		y[n] = (int)insertionSort(y, n);
		for (int i = 0; i < n; i++)
		{
			x[i][j] = y[i];
		}
	}
	cout << '\n' << "Vidsortovanyi masyv :\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(3) << x[i][j] << '\t';
		}
		cout << endl;
	}
	/*count()*/
	f[0] = 0;
	for (int i = 1; i < n; i++)
	{
		s = 1;
		for (int j = 0; j < n; j++)
		{
			if (j < i)
			{
				s *= x[i][j];
			}
		}
		f[i] = pow(abs(s), 1.0 / i);
	}
	cout << '\n' << "Seredne geometryche ryadkiv:\n";
	for (int i = 1; i < n; i++)
	{
		cout << f[i] << '\n';
	}
	for (int i = 0; i < n; i++)
	{
		F = F + f[i];
	}
	for (int i = 0; i < n; i++)
	{
		y[i] = 0;
	}
	return F;
}

int main()
{
	const int n = 5;
	int a[n][n], b[n * n];
	double f[n], F;
	cout << '\n' << "Vvedit elementy masivu:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[5 * i + j] = a[i][j];
		}
	}

	F = sortAndCount(b);
	cout << '\n' << "Seredne geometriche=" << F;
	return 0;
}

