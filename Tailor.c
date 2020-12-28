#include "math.h"
#include "stdio.h"
#include "stdlib.h"

/*Данная функция считает значение, на которое должно домножаться предыдущее в ходе вычисления функции sin(x) с помощью цикла в функции main*/
double Nextsin(double x, int i)
{
	double result;
	result = pow(-1, i) * pow(x, 2 * i) / (2 * i * (2 * i + 1));
	return result;
}

/*Данная функция считает значение, на которое должно домножаться предыдущее в ходе вычисления функции cos(x) с помощью цикла в функции main*/
double Nextcos(double x, int i)
{
	double result;
	result = pow(-1, i) * pow(x, 2 * i) / (2 * i(2 * i - 1));
	return result;
}

/*Данная функция считает значение, на которое должно домножаться предыдущее в ходе вычисления функции arctg(x) с помощью цикла в функции main*/
double Nextarctan(double x, int i)
{
	double result;
	result = pow(-1, i) * pow(x, 2 * i);
	return result;
}

/*Данная функция считает и выводит значения тангенса и арктангенса от вводимого x*/
void Tangent()
{
	double x, sin, cos, tan, arctan, elem, elemNext;
	int i, K;
	scanf_s("%lf", &x);
	scanf_s("%lf", &K);
	arctan = x;
	elem = arctan;
	for (i = 1; i < K; i++)
	{
		elemNext = elem * Nextarctan(x, i) / (2 * i + 1);
		arctan += elemNext;
	}
	sin = x;
	elem = sin;
	for (i = 1; i < K; i++)
	{
		elemNext = elem * Nextsin(x, i);
		sin += elemNext;
	}
	cos = 1;
	elem = cos;
	for (i = 1; i < K; i++)
	{
		elemNext = elem * Nextcos(x, i);
		cos += elemNext;
	}
	tan = sin / cos;
	printf("tan=%lf arctan=%lf", tan, arctan);
}