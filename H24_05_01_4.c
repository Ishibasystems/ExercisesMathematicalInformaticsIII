/* 数理情報学演習III H24_05_01_4.c */
/* 演習課題その1 Kadai0304 */
/* 2012.05.01, 10RU004, 石橋祥太 */

#include <stdio.h>

int main(void)
{
	int x;
	printf("整数を入力してください>");
	scanf("%d", &x);
	if (x < 60) printf("不可\n");
	else if (x < 70) printf("可\n");
	else if (x < 80) printf("良\n");
	else printf("優\n");
	return 0;
}