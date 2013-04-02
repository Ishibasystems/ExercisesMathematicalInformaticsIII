/* 数理情報学演習III H24_05_15_1.c */
/* 演習課題その1 Kadai0501 */
/* 2012.05.15, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <math.h>

float heikin(int, float[]);
int main(void)
{
	int i, n;
	float a[10], b[10], ave, var, dev;
	printf("データの個数を入力してください。>");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("データを入力してください。>");
		scanf("%f", &a[i]);
	}
	ave = heikin(n, a);
	for(i = 0; i < n; i = i + 1){
		b[i] = (a[i] - ave) * (a[i] - ave);
	}
	var = heikin(n, b);
	dev = sqrt(var);
	printf("平均は%f、標準偏差値は%f。\n", ave, dev);
	return 0;
}

float heikin(int m, float c[])
{
	int i;
	float sum, kotae;
	sum = 0.0;
	for(i = 0; i < m; i = i + 1){
		sum = sum + c[i];
	}
	kotae = sum / m;
	return kotae;
}
