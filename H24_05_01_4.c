/* �������w���KIII H24_05_01_4.c */
/* ���K�ۑ肻��1 Kadai0304 */
/* 2012.05.01, 10RU004, �΋��ˑ� */

#include <stdio.h>

int main(void)
{
	int x;
	printf("��������͂��Ă�������>");
	scanf("%d", &x);
	if (x < 60) printf("�s��\n");
	else if (x < 70) printf("��\n");
	else if (x < 80) printf("��\n");
	else printf("�D\n");
	return 0;
}