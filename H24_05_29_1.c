/* 数理情報学演習III H24_05_29_1.c */
/* 演習課題その1 Kadai0701 */
/* 2012.05.29, 10RU004, 石橋祥太 */

#include <stdio.h>

void shisoku(double, double, double*, double*, double*, double*);

int main(void)
{
	double a, b, p, q, r, s;

	printf("実数値を二つ入力してください。\n");
	scanf("%lf %lf", &a, &b);
	shisoku(a, b, &p, &q, &r, &s);
	printf("%lf + %lf = %lf\n", a, b, p);
	printf("%lf - %lf = %lf\n", a, b, q);
	printf("%lf * %lf = %lf\n", a, b, r);
	printf("%lf / %lf = %lf\n", a, b, s);

	return 0;
}

void shisoku(double a, double b, double *p, double *q, double *r, double *s)
{
	*p = a + b;
	*q = a - b;
	*r = a * b;
	*s = a / b;
	return;
}
