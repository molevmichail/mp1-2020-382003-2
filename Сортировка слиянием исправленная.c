#include "stdio.h"
#include "math.h"

void MergeSort(int A[], int n)
{
	int i, j, k, m;
	int	left; /*Первый элемент левого блока*/
	int	right; /*Первый элемент правого блока*/
	int rend; /*Элемент, до которого должно закончиться попарное сравнение блоков*/
	int B[n]; /*Массив, который запоминает положение элементов двух попарно отсортированных элементов*/
	for(k=1; k < n; k*=2)
		for (left = 0; left + k < n; left += k * 2)
		{
			right = left + k;
			rend = right + k; 
			if (rend > n)
				rend = n;
			m = left;
			i = left;
			j = right;
			while (i < right && j < rend)
			{
				if (A[i] <= A[j])
				{
					B[m] = A[i];
					i++;
				}
				else
				{
					B[m] = A[j];
					j++;
				}
				m++;
			}
			while (i < rend)
			{
				B[m] = A[i];
				m++;
				i++;
			}
			while (j < rend)
			{
				B[m] = A[j];
				m++;
				j++;
			}
			for (m = left; m < rend; m++)
				A[m] = B[m];
		}
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
}