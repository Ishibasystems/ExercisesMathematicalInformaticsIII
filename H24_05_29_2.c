/* �������w���KIII H24_05_29_2.c */
/* ���K�ۑ肻��2 Kadai0702 */
/* 2012.05.29, 10RU004, �΋��ˑ� */

#include <stdio.h>

char turu_kame(int, int, int*, int*);

int main(void)
{
	int a, b, x, y;

	printf("���̐��Ƒ��̐�����͂��Ă��������B\n");
	scanf("%d %d", &a, &b);
	if (turu_kame(a, b, &x, &y)) printf("�����Ȑ��l�����͂���܂����B\n", x);
	printf("�߂̐� %d\n", x);
	printf("�T�̐� %d\n", y);
	return 0;
}

char turu_kame(int a, int b, int *x, int *y)
{
	*x = 2 * a - b / 2;
	*y = a - *x;
	if (*x < 0 || *y < 0 || b % 2 == 1) return 1;
	return 0;
}
