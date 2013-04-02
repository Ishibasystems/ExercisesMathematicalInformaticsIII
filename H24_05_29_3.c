/* �������w���KIII H24_05_29_3.c */
/* ���K�ۑ肻��3 Kadai0703 */
/* 2012.05.29, 10RU004, �΋��ˑ� */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char niji_houteishiki(double, double, double, double*, double*);
void niji_houteishiki_text(double, double, double);
char is_int(double);
int gcd(int, int);

int main(void)
{
	double a, b, c, x, y;

	printf("a��b��c����͂��Ă��������B\n");
	scanf("%lf %lf %lf", &a, &b, &c);

	switch (niji_houteishiki(a, b, c, &x, &y))
	{
	case 1:	/* ������x2 */
		printf("������1: %lf\n", x);
		printf("������2: %lf\n", y);
		break;

	case 0:	/* ������x1 */
		printf("������: %lf\n", x);
		break;

	case -1:	/* ������x2 */
		printf("������1: %lf +%lfi\n", x, y);
		printf("������2: %lf -%lfi\n", x, y);
		break;

	default:
		break;
	}

	niji_houteishiki_text(a, b, c);

	return 0;
}

char niji_houteishiki(double a, double b, double c, double *x, double *y)
{
	*x = *y = -b;	/* ������x1 or ������x2 */

	if (b * b - 4 * a * c > 0)
	{
		*x = -b + sqrt(b * b - 4 * a * c);	/* ������x2 */
		*y = -b - sqrt(b * b - 4 * a * c);
	}

	if (b * b < 4 * a * c) *y = sqrt(4 * a * c - b * b);	/* ������x2 */

	*x /= 2 * a;
	*y /= 2 * a;

	return ((b * b - 4 * a * c) > 0) - ((b * b - 4 * a * c) < 0);
}

void niji_houteishiki_text(double a, double b, double c)
{
	char buffer[3][32000];
	double a_, x, y;
	x = -b;
	y = sqrt(fabs(b * b - 4 * a * c));
	a_ = 2 * a;
	/*if (b * b < 4 * a * c)*/
	if (is_int(x) && is_int(a_));
	if (is_int(y) && is_int(a_));
	return;
}

char is_int(double x)
{
	return ceil(x) != floor(x);
}

int gcd(int a, int b)
{
	int m, n, k;

	m = a > b ? a : b;
	n = a < b ? a : b;

	if (n == 0) return m;

	while (m % n != 0)
	{
		k = m % n;
		m = n;
		n = k;
	}

	return n;
}
