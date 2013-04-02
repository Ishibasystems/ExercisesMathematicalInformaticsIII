/* �������w���KIII H24_06_05_1.c */
/* ���K�ۑ肻��1 Kadai0801 */
/* 2012.06.05, 10RU004, �΋��ˑ� */

#include <stdio.h>

void swapInt(int*, int*);
void shiftTab(int*, int, int);

int main(void)
{
	int k, cnt, a[10] = {10, 21, 45, 33, 9, 72, 89, 64, 25, 18};

	for (cnt = 0; cnt < 10; cnt++)
		printf("a[%d]= %d\n", cnt, a[cnt]);

	printf("�T�C�N���b�N�V�t�g����������>");
	scanf("%d", &k);

	shiftTab(a, 10, k);

	for (cnt = 0; cnt < 10; cnt++)
		printf("a[%d]= %d\n", cnt, a[cnt]);

	return 0;
}

void swapInt(int *p, int *q)
{
	int c = *p;
	*p = *q;
	*q = c;
	return;
}

void shiftTab(int *a, int n, int m)
{
	int cnt, count;
	for (cnt = 0; cnt < m; cnt++)
		for (count = 0; count < n - 1; count++)
			swapInt(a + count, a + (count + 1) % n);
	return;
}
