/* 数理情報学演習III H24_05_22_1.c */
/* 演習課題その1 Kadai0601 */
/* 2012.05.22, 10RU004, 石橋祥太 */

#include <stdio.h>

void shiftXYZ(double*, double*, double*);

int main(void)
{
	double x, y, z;

	printf("Xデータを入力してください。>");
	scanf("%lf", &x);

	printf("Yデータを入力してください。>");
	scanf("%lf", &y);

	printf("Zデータを入力してください。>");
	scanf("%lf", &z);

	shiftXYZ(&x, &y, &z);

	printf("Xデータ>%lf\nYデータ>%lf\nZデータ>%lf\n", x, y, z);

	return 0;
}

void shiftXYZ(double *X, double *Y, double *Z)
{
	double W = *X;
	*X = *Y;
	*Y = *Z;
	*Z = W;
	return;
}
