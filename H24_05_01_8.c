/* �������w���KIII H24_05_01_8.c */
/* ���K�ۑ肻��2 Hatten 0301 */
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

	printf("�ǂ�����v�Z�E�\�����܂���\n�e�w���̕��ϓ_: 1\n�e���Ȃ̕��ϓ_: Other\n");
	scanf("%d", &i);

	if (i == 1)
		for (i = 0; i < 3; i++)
		{
			s = 0.0;
			for (j = 0; j < 5; j++)
			{
				s += (double) ten[i][j] / 5;
			}
			printf("%d�Ԗڂ̊w���̕��ϓ_��%lf�_�ł��B\n", i, s);
		}
	else
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