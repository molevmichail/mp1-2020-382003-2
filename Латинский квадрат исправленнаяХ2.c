#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include <malloc.h>
#include <locale.h>


bool comparison(int A[], int B[], int size) {
	int i, j, key;
	bool flag = false;
	for (i = 0; i < size; i++) {
		key = B[i];
		flag = false;
		for (j = 0; j < size; j++) {
			if (A[j] == key) {
				flag = true;
				B[i] = size + 1;
				flag;
				break;
			}
		}
		if (flag == false)
			break;
	}
	return flag;
}

void randArray(int* Arr, int n)
{
	int a, b;
	printf("Ââåäèòå ãðàíèöû ìàññèâà\n");
	scanf_s("%d %d", &a, &b);
	int i;
	for (i = 0; i < n; i++)
		Arr[i] = rand() % (b - a) + a;
}

void main() {
	int n = 2;
	int i, j;
	setlocale(LC_ALL, "Rus");
	int N;
	printf("Ââåäèòå ðàçìåð ìàññèâà\n");
	scanf_s("%d", &N);

	int** Arr = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		Arr[i] = (int*)malloc(N * sizeof(int));
		randArray(Arr[i], N);
	}
	int* B;
	B = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		B[i] = 0;
	}
	int* C;
	C = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		C[i] = 0;
	}
	int* Z;
	Z = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		Z[i] = 0;
	}
	bool flag1 = false;
	bool flag2 = false;
	for (i = 0; i < N; i++) {
		B[i] = i + 1;
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			C[i] = Arr[i][j];
			Z[i] = Arr[j][i];
		}
		flag1 = (comparison(C, B, N));
		flag2 = (comparison(Z, B, N));
	}
	if (flag1 && flag2)
		printf("Yes");
	else
		printf("No");
	for (i = 0; i < N; i++)
		free(Arr[i]);
}