/* �������w���KIII H24_05_08_4.c */
/* ���W�ۑ肻��1 Hatten401 */
/* 2012.05.08, 10RU004, �΋��ˑ� */

#include <stdio.h>
int abs(int);

int main(void)
{
	int x, count;

	for(count = 0; count < 5; count++)
	{
		printf("��������͂��Ă������� >");
		scanf("%d", &x);
		printf("��Βl�� %d �ł��B\n", abs(x));
	}
	return 0;
}

int abs(int a)
{
	return a < 0 ? -a : a;
}
