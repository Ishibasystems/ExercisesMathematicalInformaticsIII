/* 数理情報学演習III H24_04_17.c */
/* エントロピー算出 */
/* 2012.04.18, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long input(char *s, long len)
{
	fgets(s, len, stdin);
	s[len - 1] = '\0';

	if (strchr(s, '\n') != 0) s[strlen(s) - 1] = '\0';
	else while(getchar() != '\n');

	return atol(s);
}

double entropy(double *array1, long len)
{
	long count;
	double a = 0.0;

	for (count = 0; count < len; count++)
		if (array1[count] != 0.0)
			a -= array1[count] * log(array1[count]) / log(2);

	return a;
}

/*void main(void)
{
	char buf[256];
	long d, count;
	double *array1, a = 0.0;

	printf("[信号の種類を入力して下さい]: ");
	input(buf, 256);
	sscanf(buf, "%d%*[^\n]", &d);

	array1 = malloc(sizeof(double) * d);

	if (array1 == NULL)
	{
		printf("Error:メモリを確保できませんでした。");
		exit(1);
	}

	for (count = 0; count < d; count++)
	{
		printf("[%dつ目の信号の出現確立を実数で入力して下さい]: ", count + 1);
		input(buf, 256);
		sscanf(buf, "%lf%*[^\n]", &(array1[count]));
	}

	for (count = 0; count < 30; count++) printf("-");

	printf("\nエントロピーは %lf\n", entropy(array1, d));

	a = 0.0;
	for(count = 0; count < d; count++) a += array1[count];

	printf("確認:確立の総和は %lf", a);

	free(array1);

	return;
}*/

void main(void)
{
	char buf[4096], s[4096];
	long a0 = 0, a1 = 0, d, count;
	double array1[10];

	printf("[01信号を入力して下さい]: ");
	input(buf, 4096);
	sscanf(buf, "%s4096%*[^\n]", s);

	buf[0] = '\0';

	/* if (s[0] == '1') sprintf(buf, "0"); */

	for (count = 0; s[count] != '\0'; count++)
	{
		d = 0;
		if (s[count] == '0')
			while (s[count + d] == '0') d++;
		else if (s[count] == '1')
			while (s[count + d] == '1') d++;
		else
		{
			printf("\nError:01以外の文字がありました。\n");
			exit(1);
		}

		if (d > 9)
		{
			printf("\nError:連続が9を超えました。\n");
			exit(1);
		}

		if (s[count] == '0')
			a0 += d;
		else  a1 += d;

		sprintf(buf, "%s%d", buf, d);
		count += d - 1;
	}

	printf("%s\n", buf);

	array1[0] = (double) a0 / strlen(s);
	array1[1] = (double) a1 / strlen(s);
	printf("01信号データ量は %lf\n", entropy(array1, 2) * strlen(s));

	for (count = 0; count < 10; array1[count++] = 0.0);

	for (count = 0; buf[count] != '\0'; array1[buf[count++] - '0']++);

	for (count = 0; count < 10; array1[count++] /= strlen(buf));

	printf("ラングレス符号データ量は %lf\n", entropy(array1, 10) * strlen(buf));
	return;
}