/* 数理情報学演習III H24_05_08_2.c */
/* 演習課題その2 Kadai0402 */
/* 2012.05.08, 10RU004, 石橋祥太 */

#include <stdio.h>
int souwa(int);
int sowa(int);

int main(void)
{
	int x;

	printf("整数を入力してください >");
	scanf("%d", &x);
	printf("%d までの自然数の総和は %d です。\n", x, souwa(x));
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