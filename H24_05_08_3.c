/* �������w���KIII H24_05_08_3.c */
/* ���K�ۑ肻��3 Kadai0403 */
/* 2012.05.08, 10RU004, �΋��ˑ� */

#include <stdio.h>
int gcd(int, int);

int main(void)
{
	int x, y;

	printf("��̐�������͂��Ă������� >");
	scanf("%d %d", &x, &y);
	printf("%d �� %d �̎��R���̑��a�ő���񐔂� %d �ł��B\n", x, y, gcd(x, y));
	return 0;
}

int gcd(int a, int b)
{
	int m, n, k;

	m = a > b ? a : b;
	n = a < b ? a : b;

	if (n == 0) return m;

	while (m % n != 0)
	{
		k = m % n;
		m = n;
		n = k;
	}

	return n;
}
