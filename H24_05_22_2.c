/* �������w���KIII H24_05_22_2.c */
/* ���K�ۑ肻��2 Kadai0602 */
/* 2012.05.22, 10RU004, �΋��ˑ� */

#include <stdio.h>

#define max 5

void swapInt(int*, int*);
void reverseAtoE(int*, int);

int main(void)
{
	int i, a[max];

	for (i = 0; i < max; i++)
	{
		printf("�f�[�^%d����͂��Ă��������B>", i + 1);
		scanf("%d", &a[i]);
	}

	reverseAtoE(a, max);

	for (i = 0; i < max; i++)
		printf("�f�[�^%d>%d\n", i + 1, a[i]);

	return 0;
}

void reverseAtoE(int *a, int cnt)
{
	int i;
	if (cnt < 2) return;
	for (i = 0; i < cnt / 2; i++) swapInt(&a[i], &a[cnt - i - 1]);
	return;
}

void swapInt(int *p, int *q)
{
	double c = *p;
	*p = *q;
	*q = c;
	return;
}
