/* ”—î•ñŠw‰‰KIII H24_05_15_3.c */
/* ‰‰K‰Û‘è‚»‚Ì3 Kadai0503 */
/* 2012.05.15, 10RU004, Î‹´Ë‘¾ */

#include <stdio.h>

int zettai(int);

int main(void)
{
	int n, sum;
	sum = 0;
	while(1){
		printf("®”‚ğ“ü—Í: ");
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		sum = sum + zettai(n);
	}
	printf("â‘Î’s˜b‚Í %d ‚Å‚·B\n", sum);
	return 0;
}

int zettai(int n)
{
	if(n < 0){
		return -n;
	}
	else{
		return n;
	}
}
