/* �������w���KIII H24_06_12_2.c */
/* ���K�ۑ肻��2 Kadai0902 */
/* 2012.06.12, 10RU004, �΋��ˑ� */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point
{
	int x;
	int y;
};

double point2point(struct point, struct point);

int main(void)
{
	int cnt;
	double dist = 0.0;
	struct point pos[3] = {{0, 0}, {0, 0}, {0, 0}};

	for (cnt = 0; cnt < 3; cnt++)
	{
		printf("%d: x���W����͂��Ă��������B>", cnt + 1);
		scanf("%d", &pos[cnt].x);

		printf("%d: y���W����͂��Ă��������B>", cnt + 1);
		scanf("%d", &pos[cnt].y);
	}

	for (cnt = 0; cnt < 3; cnt++)
		dist += point2point(pos[cnt], pos[(cnt + 1) % 3]);

	printf("�O�p�ӂ̒����̑��a�� %lf\n", dist);

	return 0;
}

double point2point(struct point a, struct point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
