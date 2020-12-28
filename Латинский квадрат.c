#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/*Данная функция производит перестановку элементов в строках массива и выполняет проверку на то, что все элементы различны и находятся в интервале от 1 до n*/
int RowPerestanovka(int a[N][N], int k)
{
	int flag = 1, i, * count = (int*)calloc(N + 1, sizeof(int));
	for (i = 0; i < N && flag; i++)
		if (a[k][i] >= 1 && a[k][i] <= N)
			count[a[k][i]]++;
		else flag = 0;
	for (i = 1; i <= N && flag; i++)
		if (count[i] != 1)
			flag = 0;
	free(count);
	return flag;
}

/*Данная функция производит перестановку елементов в столбцах массива и выполняет проверку на то, что все элементы различны и находятся в интервале от 1 до n */
int StPerestanovka(int a[N][N], int k)
{
	int flag = 1, i, * count = (int*)calloc(N + 1, sizeof(int));
	for (i = 0; i < N && flag; i++)
		if (a[i][k] >= 1 && a[i][k] <= N)
			count[a[i][k]]++;
		else flag = 0;
	for (i = 1; i <= N && flag; i++)
		if (count[i] != 1)
			flag = 0;
	free(count);
	return flag;
}

/*Ввод массива*/
void Init(int a[N][N])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &a[i][j]);
}

/*Вывод массива*/
void Print(int a[N][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d ", a[i][j]);
		putchar('\n');
	}
}

/*Данная функция проверяет весь массив на свойство Латинского квадрата*/
int Check(int a[N][N])
{
	int i, flag;
	for (i = 0, flag = 1; i < N && flag; i++)
		if (!RowPerestanovka(a, i) || !StPerestanovka(a, i))
			flag = 0;
	return flag;
}

int main()
{
	int a[N][N];
	Init(a);
	Print(a);
	printf("%s\n", Check(a) ? "yes" : "no");
	getch();
	return 0;
}