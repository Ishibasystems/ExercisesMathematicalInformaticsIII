/* �������w���KIII H24_05_22_4.c */
/* ���K�ۑ肻��3 Kadai0603 */
/* 2012.05.22, 10RU004, �΋��ˑ� */

#include <stdio.h>

void swapInt(int*, int*);

int main(void)
{
	int i, j, a[10] = {10, 21, 45, 33, 9, 72, 89, 64, 25, 18}, cnt;

	printf("�f�[�^i����͂��Ă��������B>");
	scanf("%d", &i);
	printf("�f�[�^j����͂��Ă��������B>");
	scanf("%d", &j);

	if (i < 0 || i > 9 || j < 0 || j > 9)
	{
		printf("�z��w��G���[\n");
		return 0;
	}

	swapInt(&a[i], &a[j]);

	for (cnt = 0; cnt < 10; cnt++)
		printf("�f�[�^a[%d]>%d\n", cnt, a[cnt]);

	return 0;
}

void swapInt(int *p, int *q)
{
	double c = *p;
	*p = *q;
	*q = c;
	return;
}
