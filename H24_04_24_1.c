/* �������w���KIII H24_04_24_1.c */
/* �t�@�C�����o�� ���1 */
/* 2012.04.24, 10RU004, �΋��ˑ� */

#include <stdio.h>

void main(void)
{
	FILE *fp;

	fp = fopen("output.txt", "w");
	fprintf(fp, "����ɂ��́B");
	fprintf(fp, "�΋� �ˑ��ł��B");
	fclose(fp);
	return;
}