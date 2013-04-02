/* 数理情報学演習III H24_06_05_3.c */
/* 演習課題その3 Kadai0803 */
/* 2012.06.05, 10RU004, 石橋祥太 */

#include <stdio.h>

void swapInt(char*, char*);
void shiftTab(char*, int, int);

int main(void)
{
	char str[20];
	int cnt, k;

	printf("文字列を入力してください。\n");
	scanf("%s", str);

	for (cnt = 0; str[cnt] != '\0'; cnt++);

	printf("サイクリックシフトする個数を入力>");
	scanf("%d", &k);

	shiftTab(str, cnt, k);

	printf("%s\n", str);

	return 0;
}

void swapInt(char *p, char *q)
{
	char c = *p;
	*p = *q;
	*q = c;
	return;
}

void shiftTab(char *a, int n, int m)
{
	int cnt, count;
	for (cnt = 0; cnt < m; cnt++)
		for (count = 0; count < n - 1; count++)
			swapInt(a + count, a + (count + 1) % n);
	return;
}
