/* �������w���KIII H24_05_01_3.c */
/* ���K�ۑ肻��1 Kadai0303 */
/* 2012.05.01, 10RU004, �΋��ˑ� */

#include <stdio.h>

int main(void)
{
	int i, x;
	for (i = 0; i < 10; i++)
	{
		printf("��������͂��Ă�������>");
		scanf("%d", &x);
		if (x < 60) printf("�s");
		printf("���i\n");
	}
	return 0;
}