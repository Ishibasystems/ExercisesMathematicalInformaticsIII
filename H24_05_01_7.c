/* �������w���KIII H24_05_01_7.c */
/* ���K�ۑ肻��2 Kadai0305 */
/* 2012.05.01, 10RU004, �΋��ˑ� */

#include <stdio.h>

int main(void)
{
	int ten[3][5], i, j;
	double s;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("�w��%d�̎�����Ȗ�%d�̓_������͂��Ă��������B\n", i, j);
			scanf("%d", &ten[i][j]);
		}
	}
	for (i = 0; i < 5; i++)
	{
		s = 0.0;
		for (j = 0; j < 3; j++)
		{
			s += (double) ten[j][i] / 3;
		}
		printf("%d�Ԗڂ̋��Ȃ̕��ϓ_��%lf�_�ł��B\n", i, s);
	}
	return 0;
}