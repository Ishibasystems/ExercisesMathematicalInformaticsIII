/* îñwKIII H24_04_24_2.c */
/* t@CüoÍ áè2 */
/* 2012.04.24, 10RU004, Î´Ë¾ */

#include <stdio.h>

void main(void)
{
	FILE *fp;
	int a, b;

	scanf("%d %d", &a, &b);

	fp = fopen("data.txt", "w");
	fprintf(fp, "%d %d\n", a, b);
	fclose(fp);
	return;
}