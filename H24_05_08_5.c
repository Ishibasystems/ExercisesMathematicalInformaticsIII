/* 数理情報学演習III H24_05_08_5.c */
/* 発展課題その2 Hatten402 */
/* 2012.05.08, 10RU004, 石橋祥太 */

#include <stdio.h>
int shisha_gonyu(float);

int main(void)
{
	float x[100];
	int count, i, sum = 0;

	for(count = 0;; count++)
	{
		printf("実数を入力してください >");
		scanf("%f", &(x[count]));
		if (x[count] <= 0.0) break;
	}
	for(i = 0; i < count; i++)
	{
		sum += shisha_gonyu(x[i]);
	}
	printf("四捨五入後の総和は %d です。\n", sum);
	return 0;
}

int shisha_gonyu(float jissu)
{
	return (int)jissu + !(jissu - (int)jissu < 0.5);
}
