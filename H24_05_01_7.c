/* 数理情報学演習III H24_05_01_7.c */
/* 演習課題その2 Kadai0305 */
/* 2012.05.01, 10RU004, 石橋祥太 */

#include <stdio.h>

int main(void)
{
	int ten[3][5], i, j;
	double s;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("学生%dの取った科目%dの点数を入力してください。\n", i, j);
			scanf("%d", &ten[i][j]);
		}
	}
	for (i = 0; i < 5; i++)
	{
		s = 0.0;
		for (j = 0; j < 3; j++)
		{
			s += (double) ten[j][i] / 3;
		}
		printf("%d番目の教科の平均点は%lf点です。\n", i, s);
	}
	return 0;
}