/* �������w���KIII H24_05_15_1.c */
/* ���K�ۑ肻��1 Kadai0501 */
/* 2012.05.15, 10RU004, �΋��ˑ� */

#include <stdio.h>
#include <math.h>

float heikin(int, float[]);
int main(void)
{
	int i, n;
	float a[10], b[10], ave, var, dev;
	printf("�f�[�^�̌�����͂��Ă��������B>");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("�f�[�^����͂��Ă��������B>");
		scanf("%f", &a[i]);
	}
	ave = heikin(n, a);
	for(i = 0; i < n; i = i + 1){
		b[i] = (a[i] - ave) * (a[i] - ave);
	}
	var = heikin(n, b);
	dev = sqrt(var);
	printf("���ς�%f�A�W���΍��l��%f�B\n", ave, dev);
	return 0;
}

float heikin(int m, float c[])
{
	int i;
	float sum, kotae;
	sum = 0.0;
	for(i = 0; i < m; i = i + 1){
		sum = sum + c[i];
	}
	kotae = sum / m;
	return kotae;
}
