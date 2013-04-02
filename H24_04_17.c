/* �������w���KIII H24_04_17.c */
/* �G���g���s�[�Z�o */
/* 2012.04.18, 10RU004, �΋��ˑ� */

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

	printf("[�M���̎�ނ���͂��ĉ�����]: ");
	input(buf, 256);
	sscanf(buf, "%d%*[^\n]", &d);

	array1 = malloc(sizeof(double) * d);

	if (array1 == NULL)
	{
		printf("Error:���������m�ۂł��܂���ł����B");
		exit(1);
	}

	for (count = 0; count < d; count++)
	{
		printf("[%d�ڂ̐M���̏o���m���������œ��͂��ĉ�����]: ", count + 1);
		input(buf, 256);
		sscanf(buf, "%lf%*[^\n]", &(array1[count]));
	}

	for (count = 0; count < 30; count++) printf("-");

	printf("\n�G���g���s�[�� %lf\n", entropy(array1, d));

	a = 0.0;
	for(count = 0; count < d; count++) a += array1[count];

	printf("�m�F:�m���̑��a�� %lf", a);

	free(array1);

	return;
}*/

void main(void)
{
	char buf[4096], s[4096];
	long a0 = 0, a1 = 0, d, count;
	double array1[10];

	printf("[01�M������͂��ĉ�����]: ");
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
			printf("\nError:01�ȊO�̕���������܂����B\n");
			exit(1);
		}

		if (d > 9)
		{
			printf("\nError:�A����9�𒴂��܂����B\n");
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
	printf("01�M���f�[�^�ʂ� %lf\n", entropy(array1, 2) * strlen(s));

	for (count = 0; count < 10; array1[count++] = 0.0);

	for (count = 0; buf[count] != '\0'; array1[buf[count++] - '0']++);

	for (count = 0; count < 10; array1[count++] /= strlen(buf));

	printf("�����O���X�����f�[�^�ʂ� %lf\n", entropy(array1, 10) * strlen(buf));
	return;
}