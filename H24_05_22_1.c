/* �������w���KIII H24_05_22_1.c */
/* ���K�ۑ肻��1 Kadai0601 */
/* 2012.05.22, 10RU004, �΋��ˑ� */

#include <stdio.h>

void shiftXYZ(double*, double*, double*);

int main(void)
{
	double x, y, z;

	printf("X�f�[�^����͂��Ă��������B>");
	scanf("%lf", &x);

	printf("Y�f�[�^����͂��Ă��������B>");
	scanf("%lf", &y);

	printf("Z�f�[�^����͂��Ă��������B>");
	scanf("%lf", &z);

	shiftXYZ(&x, &y, &z);

	printf("X�f�[�^>%lf\nY�f�[�^>%lf\nZ�f�[�^>%lf\n", x, y, z);

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
