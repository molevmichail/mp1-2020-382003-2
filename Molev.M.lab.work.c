#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"
#include "windows.h"

void RandArray(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		A[i] = rand() % (200 - 1) + 1;
}
void DoubleSort(int A[], int n)
{
	int i, j, max = 0, min = 10000, nmax, nmin, change, count = 1;
	for (i = 0; i <= n / 2; i++)
	{
		for (j = i; j < n - count + 1; j++)
		{
			if (A[j] > max)
			{
				max = A[j];
				nmax = j;
			}
			change = A[n - count];
			A[n - count] = A[nmax];
			A[nmax] = change;
			max = 0;
			if (A[j] < min)
			{
				min = A[j];
				nmin = j;
			}
			change = A[i];
			A[i] = A[nmin];
			A[nmin] = change;
			min = 10000;
		}
		count++;
	}
	PrintArray(A, n);
}

void InsertSort(int C[], int n)
{
	int i, GivenElement;
	for (i = 1; i < n; i++)
	{
		GivenElement = C[i];
		while (i >= 1 && C[i] < C[i-1])
		{
			C[i] = C[i - 1];
			i = i - 1;
		}
		C[i] = GivenElement;
	}
	PrintArray(C, n);
}

void ShellSort(int D[], int n)
{
	int i, j, change, step;
	for(step = n/2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			change = D[i];
			for (j = i; j >= step; j -= step)
			{
				if (change < D[j - step])
					D[j] = D[j - step];
				else
					break;
			}
			D[j] = change;
		}
	PrintArray(D, n);
}

void BubbleSort(int B[], int n)
{
	int i, j;
	int tmp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (B[j] > B[j + 1])
			{
				tmp = B[j];
				B[j] = B[j + 1];
				B[j + 1] = tmp;
			}
		}
	}
	PrintArray(B, n);
}

void MergeSort(int E[], int n)
{
	int A[], B[];
	int i, j, t=0, k;
	for (i = 0; i < n / 2; i++)
	{
		A[i] = E[i];
		t++;
	}
	for (i = t; i < n; i++)
		B[i - t] = E[i];
	BubbleSort(A, t);
	BubbleSort(B, n - t);
	i = 0;
	j = 0;
	for (k = 0; k < n; k++)
	{
		if (A[i] < B[j])
		{
			E[k] = A[i];
			i++;
		}
		if (B[j] < A[i])
		{
			E[k] = B[j];
			j++;
		}
		if (A[i] = B[j])
		{
			E[k] = A[i];
			i++;
		}
	}
	PrintArray(E, n);
}


void PrintArray(int D[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d\n", D[i]);
}

void menu()
{
	printf("\nMENU\n");
	printf("1. RandArray\n");
	printf("2. DoubleSort\n");
	printf("3. InsertSort\n");
	printf("4. ShellSort\n");
	printf("5. BubbleSort\n");
	printf("6. MergeSort\n");
	printf("0. Exit\n");
}

void main()
{
	int A[150];
	int n;
	int t = 10;
	LARGE_INTEGER freq, start, finish;
	double timeDouble, timeInsert, timeShell, timeBubble, timeMerge;

	QueryPerformanceFrequency(&freq);

	printf("start\n");

	while (t != 0)
	{
		menu();
		scanf_s("d", &t);
		switch (t)
		{
		case 1: {
			RandArray(A, n);
			break;
		}
		case 2: {
			printf("Please enter the number of array elements\n");
			scanf_s("%d", &n);

			QueryPerformanceCounter(&start);
			DoubleSort(A, n);
			QueryPerformanceCounter(&finish);
			timeDouble = (double)(finish.QuadPart - start.QuadPart);
			printf("%lf\n", timeDouble);
			break;
		}
		case 3: {
			printf("Please enter the number of array elements\n");
			scanf_s("%d", &n);
			QueryPerformanceCounter(&start);
			InsertSort(A, n);
			QueryPerformanceCounter(&finish);
			timeInsert = (double)(finish.QuadPart - start.QuadPart);
			printf("%lf\n", timeInsert);
			break;
		}
		case 4: {
			printf("Please enter the number of array elements\n");
			scanf_s("%d", &n);
			QueryPerformanceCounter(&start);
			ShellSort(A, n);
			QueryPerformanceCounter(&finish);
			timeShell = (double)(finish.QuadPart - start.QuadPart);
			printf("%lf\n", timeShell);
			break;
		}
		case 5: {
			printf("Please enter the number of array elements\n");
			scanf_s("%d", &n);
			QueryPerformanceCounter(&start);
			BubbleSort(A, n);
			QueryPerformanceCounter(&finish);
			timeBubble = (double)(finish.QuadPart - start.QuadPart);
			printf("%lf\n", timeBubble);
			break;
		}
		case 6: {
			printf("Please enter the number of array elements\n");
			scanf_s("%d", &n);
			QueryPerformanceCounter(&start);
			MergeSort(A, n);
			QueryPerformanceCounter(&finish);
			timeMerge = (double)(finish.QuadPart - start.QuadPart);
			printf("%lf\n", timeMerge);
			break;
		}
		default: printf("error\n");
			break;
		}
	}
}