/* 数理情報学演習III H24_05_01_1.c */
/* 演習課題その1 Kadai0301 */
/* 2012.05.01, 10RU004, 石橋祥太 */

#include <stdio.h>

int main(void)
{
	int i, x, count;
	count = 0;
	for (i = 1; i <= 5; i = i + 1)
	{
		printf("整数を入力してください>");
		scanf("%d", &x);
		if (x % 3 == 0) count = count + 1;
	}
	printf("3の倍数は%d個です。\n", count);
	return 0;
}