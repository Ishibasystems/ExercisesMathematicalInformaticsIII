/* �������w���KIII H24_05_15_4.c */
/* ���K�ۑ肻��4 Kadai0504 */
/* 2012.05.15, 10RU004, �΋��ˑ� */

#include <stdio.h>

int search(int, int*, int);

int main(void)
{
	int i, n, a[100], key;
	printf("�f�[�^�̌�����͂��Ă��������B>");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("�f�[�^����͂��Ă��������B>");
		scanf("%d", &a[i]);
	}
	printf("��������f�[�^����͂��Ă��������B>");
	scanf("%d", &key);

	if (search(n, a, key)) printf("����܂����B\n");
	else printf("����܂���ł����B\n");
	return 0;
}

int search(int n, int a[], int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == key) return 1;
	return 0;
}
