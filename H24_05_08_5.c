/* ”—î•ñŠw‰‰KIII H24_05_08_5.c */
/* ”­“W‰Û‘è‚»‚Ì2 Hatten402 */
/* 2012.05.08, 10RU004, Î‹´Ë‘¾ */

#include <stdio.h>
int shisha_gonyu(float);

int main(void)
{
	float x[100];
	int count, i, sum = 0;

	for(count = 0;; count++)
	{
		printf("À”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
		scanf("%f", &(x[count]));
		if (x[count] <= 0.0) break;
	}
	for(i = 0; i < count; i++)
	{
		sum += shisha_gonyu(x[i]);
	}
	printf("lÌŒÜ“üŒã‚Ì‘˜a‚Í %d ‚Å‚·B\n", sum);
	return 0;
}

int shisha_gonyu(float jissu)
{
	return (int)jissu + !(jissu - (int)jissu < 0.5);
}
