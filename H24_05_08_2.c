/* �������w���KIII H24_05_08_2.c */
/* ���K�ۑ肻��2 Kadai0402 */
/* 2012.05.08, 10RU004, �΋��ˑ� */

#include <stdio.h>
int souwa(int);
int sowa(int);

int main(void)
{
	int x;

	printf("��������͂��Ă������� >");
	scanf("%d", &x);
	printf("%d �܂ł̎��R���̑��a�� %d �ł��B\n", x, souwa(x));
	return 0;
}

int souwa(int m)
{
	int i, sum = 0;
	for(i = 0; i < m; sum += ++i);
	return sum;
}

int sowa(int m)
{
	return m < 1 ? 0 : m + sowa(m - 1);
}