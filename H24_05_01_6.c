/* �������w���KIII H24_05_01_6.c */
/* 2�d���[�v��2�����z�� ���2 */
/* 2012.05.01, 10RU004, �΋��ˑ� */

#include <stdio.h>

int main(void)
{
	int ten[3][5], i, j, s;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("�w��%d�̎�����Ȗ�%d�̓_������͂��Ă��������B\n", i, j);
			scanf("%d", &ten[i][j]);
		}
	}
	for (i = 0; i < 3; i++)
	{
		s = 0;
		for (j = 0; j < 5; j++)
		{
			s = s + ten[i][j];
		}
		printf("%d�Ԗڂ̊w���̍��v�_��%d�_�ł��B\n", i, s);
	}
	return 0;
}