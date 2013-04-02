/* ”—î•ñŠw‰‰KIII H24_05_01_1.c */
/* ‰‰K‰Û‘è‚»‚Ì1 Kadai0301 */
/* 2012.05.01, 10RU004, Î‹´Ë‘¾ */

#include <stdio.h>

int main(void)
{
	int i, x, count;
	count = 0;
	for (i = 1; i <= 5; i = i + 1)
	{
		printf("®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢>");
		scanf("%d", &x);
		if (x % 3 == 0) count = count + 1;
	}
	printf("3‚Ì”{”‚Í%dŒÂ‚Å‚·B\n", count);
	return 0;
}