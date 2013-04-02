/* 数理情報学演習III H24_05_01_6.c */
/* 2重ループと2次元配列 例題2 */
/* 2012.05.01, 10RU004, 石橋祥太 */

#include <stdio.h>

int main(void)
{
	int ten[3][5], i, j, s;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("学生%dの取った科目%dの点数を入力してください。\n", i, j);
			scanf("%d", &ten[i][j]);
		}
	}
	for (i = 0; i < 3; i++)
	{
		s = 0;
		for (j = 0; j < 5; j++)
		{
			s = s + ten[i][j];
		}
		printf("%d番目の学生の合計点は%d点です。\n", i, s);
	}
	return 0;
}