/* 数理情報学演習III H24_05_15_2.c */
/* 演習課題その2 Kadai0502 */
/* 2012.05.15, 10RU004, 石橋祥太 */

#include <stdio.h>

float maxi(int, int[]);
int main(void)
{
	int i, a[100];
	for(i = 0; i < 100; i++){
		printf("データを入力してください。>");
		scanf("%d", &a[i]);
		if (a[i] < 0) break;
	}
	printf("最大値は%d。\n", maxi(i, a));
	return 0;
}

float maxi(int m, int c[])
{
	int i, max = -1;
	for(i = 0; i < m; i++)
		if (max < c[i]) max = c[i];
	return max;
}
