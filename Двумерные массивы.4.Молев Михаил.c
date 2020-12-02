#include "stdio.h"
#include "math.h"
//������ ������� ������� ��������� ������������ ���� ���������� �������� ������� n//
int P2(int* A1, int* A2, int n)
{
	int i, j, P=0;
	for (i = 0; i < n; i++)
	{
		P = P + A1[i] * A2[i];
	}
	return P;
}

//������ ������� ���� �� ���� ��������� ������, ��������� �� n ����� � m ��������, � ������� ����� ��������� ������������ ������������ ��� ����� ��������� �������//
int P1(int** A, int n, int m)
{
	int sum, i, j, P=0;
	A[i] = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < n-1; i++)
	{
		for (j = i + 1; j < n; j++)
			P = P + P2(A[i], A[j], m);
	}
	if (P == 0)
		return P;
}

//���� ��������� ������� �� n ����� � m ��������//
void Scan2d(int** B, int m, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			scanf_s("%d", &(B[i][j]));
	}
}

//������ ������� ��� ����� �� ������, �������� �� �������� ������� (��������� ������) �����������������//
void main()
{
	int** A;
	int m=7, n=5, R;
	Scan2d(A, m, n);
	R = P1(A, m, n);
	if (R == 0)
		printf("true");
	else
		printf("false");
}

