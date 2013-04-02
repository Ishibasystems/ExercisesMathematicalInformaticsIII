/* 数理情報学演習III H24_04_24_2.c */
/* ファイル入出力 例題2 */
/* 2012.04.24, 10RU004, 石橋祥太 */

#include <stdio.h>

void main(void)
{
	FILE *fp;
	int a, b;

	scanf("%d %d", &a, &b);

	fp = fopen("data.txt", "w");
	fprintf(fp, "%d %d\n", a, b);
	fclose(fp);
	return;
}