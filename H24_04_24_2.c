/* �������w���KIII H24_04_24_2.c */
/* �t�@�C�����o�� ���2 */
/* 2012.04.24, 10RU004, �΋��ˑ� */

#include <stdio.h>

void main(void)
{
	FILE *fp;
	int a, b;

	scanf("%d %d", &a, &b);

	fp = fopen("data.txt", "w");
	fprintf(fp, "%d %d\n", a, b);
	fclose(fp);
	return;
}