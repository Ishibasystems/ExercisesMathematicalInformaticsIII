/* �������w���KIII H24_05_22_3.c */
/* ���K�ۑ肻��2 Kadai0602 */
/* 2012.05.22, 10RU004, �΋��ˑ� */

#include <stdio.h>

void swapInt(int*, int*);
void reverseAtoE(int*, int*, int*, int*, int*);

int main(void)
{
	int i, a, b, c, d, e;

	printf("�f�[�^a����͂��Ă��������B>");
	scanf("%d", &a);
	printf("�f�[�^b����͂��Ă��������B>");
	scanf("%d", &b);
	printf("�f�[�^c����͂��Ă��������B>");
	scanf("%d", &c);
	printf("�f�[�^d����͂��Ă��������B>");
	scanf("%d", &d);
	printf("�f�[�^e����͂��Ă��������B>");
	scanf("%d", &e);

	reverseAtoE(&a, &b, &c, &d, &e);

	printf("�f�[�^a>%d\n", a);
	printf("�f�[�^b>%d\n", b);
	printf("�f�[�^c>%d\n", c);
	printf("�f�[�^d>%d\n", d);
	printf("�f�[�^e>%d\n", e);

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
