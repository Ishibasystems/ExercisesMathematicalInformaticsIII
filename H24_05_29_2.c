/* 数理情報学演習III H24_05_29_2.c */
/* 演習課題その2 Kadai0702 */
/* 2012.05.29, 10RU004, 石橋祥太 */

#include <stdio.h>

char turu_kame(int, int, int*, int*);

int main(void)
{
	int a, b, x, y;

	printf("頭の数と足の数を入力してください。\n");
	scanf("%d %d", &a, &b);
	if (turu_kame(a, b, &x, &y)) printf("無効な数値が入力されました。\n", x);
	printf("鶴の数 %d\n", x);
	printf("亀の数 %d\n", y);
	return 0;
}

char turu_kame(int a, int b, int *x, int *y)
{
	*x = 2 * a - b / 2;
	*y = a - *x;
	if (*x < 0 || *y < 0 || b % 2 == 1) return 1;
	return 0;
}
