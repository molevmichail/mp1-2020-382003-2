#include "math.h"
#include "stdio.h"
#include "stdlib.h"

typedef double(*functionType) (double, int);

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
	result = pow(-1, i) * pow(x, 2 * i) * (2 * i - 1) / (2 * i + 1);
	return result;
}

/*Данная функция производит суммирование домножаемых элементов до тех пор, пока они не достигнут желаемой точности*/
double SUM(functionType ff, double x, double a1, double e)
{
	double i = 1, elem = x, elemNext, result = x;
	while (fabs(result - a1) > e)
	{
		elemNext = elem * ff(x, i);
		result += elemNext;
		i++;
	}
	return result;
}

/*Данная функция считает и выводит значения тангенса и арктангенса от вводимого x*/
void Tangent()
{
	double x, sinus, cosinus, tg, arctangent, t1, arctg, s1, c1;
	int i, t;
	scanf_s("%lf", &x);
	scanf_s("%d", &t);
	t1 = pow(10.0, -1 * t);
	s1 = sin(x);
	c1 = cos(x);
	arctg = atan(x);
	sinus = SUM(Nextsin, x, s1, t1);
	cosinus = SUM(Nextcos, 1, c1, t1);
	arctangent = SUM(Nextarctan, x, arctg, t1);
	tg = sinus / cosinus;
	printf("tan=%lf arctan=%lf", tg, arctangent);
}