/* �������w���KIII H24_05_15_2.c */
/* ���K�ۑ肻��2 Kadai0502 */
/* 2012.05.15, 10RU004, �΋��ˑ� */

#include <stdio.h>

float maxi(int, int[]);
int main(void)
{
	int i, a[100];
	for(i = 0; i < 100; i++){
		printf("�f�[�^����͂��Ă��������B>");
		scanf("%d", &a[i]);
		if (a[i] < 0) break;
	}
	printf("�ő�l��%d�B\n", maxi(i, a));
	return 0;
}

float maxi(int m, int c[])
{
	int i, max = -1;
	for(i = 0; i < m; i++)
		if (max < c[i]) max = c[i];
	return max;
}
