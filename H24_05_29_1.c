/* ”—î•ñŠw‰‰KIII H24_05_29_1.c */
/* ‰‰K‰Û‘è‚»‚Ì1 Kadai0701 */
/* 2012.05.29, 10RU004, Î‹´Ë‘¾ */

#include <stdio.h>

void shisoku(double, double, double*, double*, double*, double*);

int main(void)
{
	double a, b, p, q, r, s;

	printf("À”’l‚ğ“ñ‚Â“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n");
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
