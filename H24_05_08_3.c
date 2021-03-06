/* 数理情報学演習III H24_05_08_3.c */
/* 演習課題その3 Kadai0403 */
/* 2012.05.08, 10RU004, 石橋祥太 */

#include <stdio.h>
int gcd(int, int);

int main(void)
{
	int x, y;

	printf("二つの整数を入力してください >");
	scanf("%d %d", &x, &y);
	printf("%d と %d の自然数の総和最大公約数は %d です。\n", x, y, gcd(x, y));
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
