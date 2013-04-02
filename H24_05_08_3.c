/* ”—î•ñŠw‰‰KIII H24_05_08_3.c */
/* ‰‰K‰Û‘è‚»‚Ì3 Kadai0403 */
/* 2012.05.08, 10RU004, Î‹´Ë‘¾ */

#include <stdio.h>
int gcd(int, int);

int main(void)
{
	int x, y;

	printf("“ñ‚Â‚Ì®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
	scanf("%d %d", &x, &y);
	printf("%d ‚Æ %d ‚Ì©‘R”‚Ì‘˜aÅ‘åŒö–ñ”‚Í %d ‚Å‚·B\n", x, y, gcd(x, y));
	return 0;
}

int gcd(int a, int b)
{
	int m, n, k;

	m = a > b ? a : b;
	n = a < b ? a : b;

	if (n == 0) return m;

	while (m % n != 0)
	{
		k = m % n;
		m = n;
		n = k;
	}

	return n;
}
