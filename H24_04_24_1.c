/* 数理情報学演習III H24_04_24_1.c */
/* ファイル入出力 例題1 */
/* 2012.04.24, 10RU004, 石橋祥太 */

#include <stdio.h>

void main(void)
{
	FILE *fp;

	fp = fopen("output.txt", "w");
	fprintf(fp, "こんにちは。");
	fprintf(fp, "石橋 祥太です。");
	fclose(fp);
	return;
}