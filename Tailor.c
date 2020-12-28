#include "math.h"
#include "stdio.h"
#include "stdlib.h"

/*������ ������� ������� ��������, �� ������� ������ ����������� ���������� � ���� ���������� ������� sin(x) � ������� ����� � ������� main*/
double Nextsin(double x, int i)
{
	double result;
	result = pow(-1, i) * pow(x, 2 * i) / (2 * i * (2 * i + 1));
	return result;
}

/*������ ������� ������� ��������, �� ������� ������ ����������� ���������� � ���� ���������� ������� cos(x) � ������� ����� � ������� main*/
double Nextcos(double x, int i)
{
	double result;
	result = pow(-1, i) * pow(x, 2 * i) / (2 * i(2 * i - 1));
	return result;
}

/*������ ������� ������� ��������, �� ������� ������ ����������� ���������� � ���� ���������� ������� arctg(x) � ������� ����� � ������� main*/
double Nextarctan(double x, int i)
{
	double result;
	result = pow(-1, i) * pow(x, 2 * i);
	return result;
}

/*������ ������� ������� � ������� �������� �������� � ����������� �� ��������� x*/
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