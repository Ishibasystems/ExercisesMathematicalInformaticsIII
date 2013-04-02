/* ”—î•ñŠw‰‰KIII H24_05_08_1.c */
/* ‰‰K‰Û‘è‚»‚Ì1 Kadai0401 */
/* 2012.05.08, 10RU004, Î‹´Ë‘¾ */

#include <stdio.h>
float func(float, float);

int main(void){
	float x, y, z;

	printf("“ñ‚Â‚ÌÀ”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
	scanf("%f %f", &x, &y);
	z = func(x, y);
	printf("2 * %f * %f + %f = %f ‚Å‚·B\n", x, x, y, z);
	return 0;
}

float func(float x, float y){
	float kotae;
	kotae = 2.0 * x * x + y;
	return kotae;
}