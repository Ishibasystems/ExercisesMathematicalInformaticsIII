/* �������w���KIII H24_06_12_1.c */
/* ���K�ۑ肻��1 Kadai0901 */
/* 2012.06.12, 10RU004, �΋��ˑ� */

#include <stdio.h>

struct person
{
	char name[40];
	float longer;
};

int main(void)
{
	int cnt;
	struct person hito[2];

	for (cnt = 0; cnt < 2; cnt++)
	{
		printf("%d: ���O����͂��Ă��������B>", cnt + 1);
		scanf("%s", hito[cnt].name);

		printf("%d: �g��(cm)����͂��Ă��������B>", cnt + 1);
		scanf("%f", &hito[cnt].longer);
	}

	printf("�w�������̂�%s����Őg����%fcm�ł�\n", hito[0].longer > hito[1].longer ? hito[0].name : hito[1].name, hito[0].longer > hito[1].longer ? hito[0].longer : hito[1].longer);

	return 0;
}
