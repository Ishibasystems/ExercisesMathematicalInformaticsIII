/* ”—î•ñŠw‰‰KIII H24_05_08_4.c */
/* ”­“W‰Û‘è‚»‚Ì1 Hatten401 */
/* 2012.05.08, 10RU004, Î‹´Ë‘¾ */

#include <stdio.h>
int abs(int);

int main(void)
{
	int x, count;

	for(count = 0; count < 5; count++)
	{
		printf("®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
		scanf("%d", &x);
		printf("â‘Î’l‚Í %d ‚Å‚·B\n", abs(x));
	}
	return 0;
}

int abs(int a)
{
	return a < 0 ? -a : a;
}
