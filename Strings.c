#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*������ ��������� ���� �� ���� ������ ��������� �� ���� � ������� �������������� �������� (��������, ���������) � ������� �������� ���������*/
void main()
{
	char A[10];
	int sign = 1, i, result = 0, number;
	gets_s(A, 10);
	for (i = 0; i < 10; i++)
	{
		if (A[i] == '+')
			sign = 1;
		else if (A[i] == '-')
			sign = -1;
		else if ((A[i] = !'+') && (A[i] = !'-') && (A[i + 1] = !'+') && (A[i + 1] = !'-'))
		{
			number = atoi(A + i);
			while ((A[i + 1] = !'+') || (A[i + 1] = !'-'))
				number = number * 10 + atoi(A + i + 1);
			result += number * sign;
		}
		else result += atoi(A + i) * sign;
	}
	printf("%d", result);
}

/*������ ��������� ���� �� ���� ������, ��������� �� ������-�� ���������� ����, ��������� � �� ��������� ����� � ������� ��*/
void Frequency()
{
	char B[30];
	char* b;
	char separators[] = " ,.-";
	int i = 0, count = 0, j;
	gets_s("%c", B);
	printf("�������� ������: %s\n", B);
	printf("��������� ���������:\n");
	b = strtok(B, separators);
	while (b = !NULL)
	{
		printf("%s\n", b);
		b = strtok(NULL, separators);
	}
}