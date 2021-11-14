#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRow(int** a, const int rowNo, const int K, const int N, const int Low, const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(a, rowNo,K, N, Low, High, colNo + 1);
}
void CreateRows(int** a, const int K, const int N, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo,K, N, Low, High, 0);
	if (rowNo < K - 1)
		CreateRows(a,K, N, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int K, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(a, rowNo, K,N, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int K, const int N, int rowNo)
{
	PrintRow(a, rowNo,K, N, 0);
	if (rowNo < K - 1)
		PrintRows(a,K, N, rowNo + 1);
	else
		cout << endl;
}
void MinRow(int** a, const int rowNo, const int colCount, int colNo, int& min)
{
	if (a[rowNo][colNo] < min)
		min = a[rowNo][colNo];
	if (colNo < colCount - 1)
		MinRow(a, rowNo, colCount, colNo + 1, min);
}
void MaxMinRows(int** a, const int rowCount, const int colCount, int rowNo, int& max)
{
	int min = a[rowNo][0];
	MinRow(a, rowNo, colCount, 1, min);
	if (rowNo == 0)
		max = min;
	if (min > max)
		max = min;
	if (rowNo < rowCount - 1)
		MaxMinRows(a, rowCount, colCount, rowNo + 1, max);
}
int main()
{
	srand((unsigned)time(NULL));
	int N;
	int K;
	cout << "rowCount = "; cin >> K;
	cout << "colCount = "; cin >> N;
	cout << endl;
	int** a = new int* [K];
	for (int i = 0; i < K; i++)
		a[i] = new int[N];
	int Low = 1, High = 20;
	CreateRows(a, K, N, Low, High, 0);
	PrintRows(a, K, N, 0);
	int max;
	MaxMinRows(a, K, N, 0, max);
	cout << max << endl;
	delete[] a;
	return 0;
}
