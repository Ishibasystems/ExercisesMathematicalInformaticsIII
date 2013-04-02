/* 数理情報学演習III H24_06_12_1.c */
/* 演習課題その1 Kadai0901 */
/* 2012.06.12, 10RU004, 石橋祥太 */

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
		printf("%d: 名前を入力してください。>", cnt + 1);
		scanf("%s", hito[cnt].name);

		printf("%d: 身長(cm)を入力してください。>", cnt + 1);
		scanf("%f", &hito[cnt].longer);
	}

	printf("背が高いのは%sさんで身長は%fcmです\n", hito[0].longer > hito[1].longer ? hito[0].name : hito[1].name, hito[0].longer > hito[1].longer ? hito[0].longer : hito[1].longer);

	return 0;
}
