/* �������w���KIII H24_04_24_4.c */
/* �t�@�C�����o�� �ۑ�1 */
/* 2012.04.24, 10RU004, �΋��ˑ� */

#include <stdio.h>

int main(void)
{
	FILE *fp;
	int a[100], count = 0;

	fp = fopen("data1.txt", "w");
	if (fp == NULL)
	{
		printf("�t�@�C���̃I�[�v���Ɏ��s");
		return 1;
	}

	
	for (count = 0; count < 100; count++)
	{
		scanf("%d", &(a[count]));
		if (1 > a[count] || a[count] > 100) break;
	}

	a[count + 1] = 0;

	for (count = 0; count < 100 && 1 <= a[count] && a[count] <= 100; fprintf(fp, "%d\n", a[count++]));

	if (fclose(fp) == EOF)
	{
		printf("�t�@�C���̃N���[�Y�Ɏ��s");
		return 1;
	}

	return 0;
}