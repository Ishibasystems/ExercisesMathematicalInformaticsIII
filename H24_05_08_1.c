/* 数理情報学演習III H24_05_08_1.c */
/* 演習課題その1 Kadai0401 */
/* 2012.05.08, 10RU004, 石橋祥太 */

#include <stdio.h>
float func(float, float);

int main(void){
	float x, y, z;

	printf("二つの実数を入力してください >");
	scanf("%f %f", &x, &y);
	z = func(x, y);
	printf("2 * %f * %f + %f = %f です。\n", x, x, y, z);
	return 0;
}

float func(float x, float y){
	float kotae;
	kotae = 2.0 * x * x + y;
	return kotae;
}