/* �������w���KIII H24_06_05_2.c */
/* ���K�ۑ肻��2 Kadai0802 */
/* 2012.06.05, 10RU004, �΋��ˑ� */

#include <stdio.h>

int main(void)
{
	char name[20], filename[20], kakuchou[5]={".txt"};
	int cnt = 0;
	FILE *fp;

	printf("���O����͂��Ă��������B\n");
	scanf("%s", name);
	sprintf(filename, "%s%s", name, kakuchou);
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("�t�@�C���I�[�v���Ɏ��s���܂����B\n");
		return 1;
	}
	while(name[cnt++] != '\0');
	fprintf(fp, "%d\n", cnt);
	if (fclose(fp) == EOF)
	{
		printf("�t�@�C���N���[�Y�Ɏ��s���܂����B\n");
		return 1;
	}
	return 0;
}
