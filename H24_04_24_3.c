/* �������w���KIII H24_04_24_3.c */
/* �t�@�C�����o�� ���3 */
/* 2012.04.24, 10RU004, �΋��ˑ� */

#include <stdio.h>

int main(void)
{
	FILE *fpr, *fpw;
	float a, b;

	fpr = fopen("data.txt", "r");
	if (fpr == NULL)
	{
		printf("�t�@�C���̃I�[�v���Ɏ��s");
		return 1;
	}
	fscanf(fpr, "%f %f", &a, &b);
	printf("a = %f b = %f \n", a, b);
	if (fclose(fpr) == EOF)
	{
		printf("�t�@�C���̃N���[�Y�Ɏ��s");
		return 1;
	}

	fpw = fopen("result.txt", "w");
	if (fpw == NULL)
	{
		printf("�t�@�C���̃I�[�v���Ɏ��s");
		return 1;
	}
	fprintf(fpw, "%f + %f = %f \n", a, b, a + b);
	printf("%f + %f = %f \n", a, b, a + b);
	if (fclose(fpw) == EOF)
	{
		printf("�t�@�C���̃N���[�Y�Ɏ��s");
		return 1;
	}
	return 0;
}