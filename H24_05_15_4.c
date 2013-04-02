/* 数理情報学演習III H24_05_15_4.c */
/* 演習課題その4 Kadai0504 */
/* 2012.05.15, 10RU004, 石橋祥太 */

#include <stdio.h>

int search(int, int*, int);

int main(void)
{
	int i, n, a[100], key;
	printf("データの個数を入力してください。>");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("データを入力してください。>");
		scanf("%d", &a[i]);
	}
	printf("検索するデータを入力してください。>");
	scanf("%d", &key);

	if (search(n, a, key)) printf("ありました。\n");
	else printf("ありませんでした。\n");
	return 0;
}

int search(int n, int a[], int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == key) return 1;
	return 0;
}
