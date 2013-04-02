/* 数理情報学演習III H24_05_22_4.c */
/* 演習課題その3 Kadai0603 */
/* 2012.05.22, 10RU004, 石橋祥太 */

#include <stdio.h>

void swapInt(int*, int*);

int main(void)
{
	int i, j, a[10] = {10, 21, 45, 33, 9, 72, 89, 64, 25, 18}, cnt;

	printf("データiを入力してください。>");
	scanf("%d", &i);
	printf("データjを入力してください。>");
	scanf("%d", &j);

	if (i < 0 || i > 9 || j < 0 || j > 9)
	{
		printf("配列指定エラー\n");
		return 0;
	}

	swapInt(&a[i], &a[j]);

	for (cnt = 0; cnt < 10; cnt++)
		printf("データa[%d]>%d\n", cnt, a[cnt]);

	return 0;
}

void swapInt(int *p, int *q)
{
	double c = *p;
	*p = *q;
	*q = c;
	return;
}
