/* �������w���KIII H24_05_01_5.c */
/* 2�d���[�v��2�����z�� ���1 */
/* 2012.05.01, 10RU004, �΋��ˑ� */

#include <stdio.h>

int main(void)
{
	int i, j, k;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			k = i * j;
			printf("%dx%d=%#2d", i, j, k);
			if (j < 9) printf(", ");
		}
		printf("\n");
	}
	return 0;
}