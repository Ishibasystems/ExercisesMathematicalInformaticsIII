/* 数理情報学演習III H24_04_24_5.c */
/* ファイル入出力 課題2 */
/* 2012.04.24, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <math.h>

double entropy(double *array1, long len)
{
	long count;
	double a = 0.0;

	for (count = 0; count < len; count++)
		if (array1[count] != 0.0)
			a -= array1[count] * log(array1[count]) / log(2);

	return a;
}

int main(void)
{
	FILE *fp;
	char a[100], b[100], count = 0, cont, cnt = 0;
	double c[100];

	fp = fopen("data1.txt", "r");
	if (fp == NULL)
	{
		printf("ファイルのオープンに失敗");
		return 1;
	}

	
	for (cont = 0; cont < 100; cont++)
	{
		fscanf(fp, "%d", &(a[cont]));
		if (1 > a[cont] || a[cont] > 100) break;
	}

	if (fclose(fp) == EOF)
	{
		printf("ファイルのクローズに失敗");
		return 1;
	}
	fp = NULL;

	for (count = 0; count < 100; b[count++] = 0);

	for (count = 0; count < cont; b[a[count++] - 1]++);

	printf("出現確立は\n");

	for (count = 0; count < 100; count++)
		if (b[count] != 0) printf("%#3d %lf\n", count + 1, c[cnt++] = (double) b[count] / cont);

	printf("エントロピーは %lf\n", entropy(c, cnt));

	return 0;
}