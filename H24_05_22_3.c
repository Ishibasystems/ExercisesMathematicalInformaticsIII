/* 数理情報学演習III H24_05_22_3.c */
/* 演習課題その2 Kadai0602 */
/* 2012.05.22, 10RU004, 石橋祥太 */

#include <stdio.h>

void swapInt(int*, int*);
void reverseAtoE(int*, int*, int*, int*, int*);

int main(void)
{
	int i, a, b, c, d, e;

	printf("データaを入力してください。>");
	scanf("%d", &a);
	printf("データbを入力してください。>");
	scanf("%d", &b);
	printf("データcを入力してください。>");
	scanf("%d", &c);
	printf("データdを入力してください。>");
	scanf("%d", &d);
	printf("データeを入力してください。>");
	scanf("%d", &e);

	reverseAtoE(&a, &b, &c, &d, &e);

	printf("データa>%d\n", a);
	printf("データb>%d\n", b);
	printf("データc>%d\n", c);
	printf("データd>%d\n", d);
	printf("データe>%d\n", e);

	return 0;
}

void reverseAtoE(int *a, int *b, int *c, int *d, int *e)
{
	swapInt(a, e);
	swapInt(b, d);
	return;
}

void swapInt(int *p, int *q)
{
	double c = *p;
	*p = *q;
	*q = c;
	return;
}
