/* 数理情報学演習III H24_05_01_3.c */
/* 演習課題その1 Kadai0303 */
/* 2012.05.01, 10RU004, 石橋祥太 */

#include <stdio.h>

int main(void)
{
	int i, x;
	for (i = 0; i < 10; i++)
	{
		printf("整数を入力してください>");
		scanf("%d", &x);
		if (x < 60) printf("不");
		printf("合格\n");
	}
	return 0;
}