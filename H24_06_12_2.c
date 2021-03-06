/* 数理情報学演習III H24_06_12_2.c */
/* 演習課題その2 Kadai0902 */
/* 2012.06.12, 10RU004, 石橋祥太 */

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
		printf("%d: x座標を入力してください。>", cnt + 1);
		scanf("%d", &pos[cnt].x);

		printf("%d: y座標を入力してください。>", cnt + 1);
		scanf("%d", &pos[cnt].y);
	}

	for (cnt = 0; cnt < 3; cnt++)
		dist += point2point(pos[cnt], pos[(cnt + 1) % 3]);

	printf("三角辺の長さの総和は %lf\n", dist);

	return 0;
}

double point2point(struct point a, struct point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
