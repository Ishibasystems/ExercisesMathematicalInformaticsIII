/* 数理情報学演習III H24_06_05_2.c */
/* 演習課題その2 Kadai0802 */
/* 2012.06.05, 10RU004, 石橋祥太 */

#include <stdio.h>

int main(void)
{
	char name[20], filename[20], kakuchou[5]={".txt"};
	int cnt = 0;
	FILE *fp;

	printf("名前を入力してください。\n");
	scanf("%s", name);
	sprintf(filename, "%s%s", name, kakuchou);
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("ファイルオープンに失敗しました。\n");
		return 1;
	}
	while(name[cnt++] != '\0');
	fprintf(fp, "%d\n", cnt);
	if (fclose(fp) == EOF)
	{
		printf("ファイルクローズに失敗しました。\n");
		return 1;
	}
	return 0;
}
