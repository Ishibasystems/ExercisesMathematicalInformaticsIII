/* 数理情報学演習III H24_05_08_4.c */
/* 発展課題その1 Hatten401 */
/* 2012.05.08, 10RU004, 石橋祥太 */

#include <stdio.h>
int abs(int);

int main(void)
{
	int x, count;

	for(count = 0; count < 5; count++)
	{
		printf("整数を入力してください >");
		scanf("%d", &x);
		printf("絶対値は %d です。\n", abs(x));
	}
	return 0;
}

int abs(int a)
{
	return a < 0 ? -a : a;
}
