/* 数理情報学演習III TAX.C */
/* BGM,BMPファイルI/O */
/* 2012.07.09, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	unsigned char gray;
} color;

typedef struct{
	FILE *bmp;
	unsigned short x;
	unsigned short y;
	unsigned char max;
} mapsize;

void bmpsize(mapsize *);
void bmpload(mapsize, color *);
char bmpsave(const char *, mapsize, color *, unsigned char);
double entropy(const short *, unsigned long, short);
void MTF(short*, short);

void main(void)
{
	char s[3200], *s_;
	mapsize size = {NULL, 0, 0, 0};
	color *maps;
	short *Tei1, *Tei2, mtftable[512], cnt;
	unsigned long count;

	/* 画像入力 */
	printf("入力するファイルの名前を入力してください。\n");
	scanf("%s", s);

	if ((size.bmp = fopen(s, "rb")) == NULL) exit(1);

	bmpsize(&size);

	maps = (color *)calloc(size.x * size.y, sizeof(color));
	
	bmpload(size, maps);

	printf("SIZE   : %dx%d\nDEPTH  : %d\n", size.x, size.y, size.max);

	fclose(size.bmp);

	Tei1 = (short *)calloc(size.x * size.y, sizeof(short));

	for (count = 0; count < (unsigned)(size.x * size.y); count++) Tei1[count] = maps[count].gray;

	printf("元データー\nENTROPY: %lf\n", entropy(Tei1, size.x * size.y, size.max + 1));

	/* 予測符号化 */
	Tei2 = (short *)calloc(size.x * size.y, sizeof(short));

	Tei2[0] = Tei1[0];
	for (count = 1; count < (unsigned)(size.x * size.y); count++)
		Tei2[count] = (Tei1[count - 1] - Tei1[count]) + 255;

	printf("予測符号化\nENTROPY: %lf\n", entropy(Tei2, size.x * size.y, size.max * 2 + 1));

	/* Move-To-Front法 */
	for (count = 0; count < 512;  mtftable[count++] = (short)count);	/* テーブル初期化 */

	for (count = 0; count < (unsigned)(size.x * size.y); MTF(mtftable, Tei2[count++] = cnt))
		for (cnt = 0; cnt < 512 && mtftable[cnt] != Tei1[count]; cnt++);

	printf("Move-To-Front法\nENTROPY: %lf\n", entropy(Tei2, size.x * size.y, size.max * 2 + 1));

	/* 画像出力
	s_ = s;
	while(*(s_++) != '.');
	*(s_ - 1) = '\0';
	sprintf(s, "%s_after", s); */

	//printf("SAVE   : %s\n", bmpsave(s, size, maps[0], 1) ? "NG" : "OK");

	/* 解放 */
	free(Tei2);
	free(Tei1);
	free(maps);
	return;
}

void MTF(short *a, short n)
{
	int c, count;
	for (count = n; count > 0; count--)
	{
		c = a[count % (n + 1)];
		a[count % (n + 1)] = a[count - 1];
		a[count - 1] = c;
	}
	return;
}

double entropy(const short *c, unsigned long size, short max)
{
	unsigned long count, *h;
	double H = 0.0;

	h = (unsigned long *)calloc(max, sizeof(unsigned long));

	for (count = 0; count < size; count++)
		h[c[count]]++;

	for (count = 0; count < (unsigned)max; count++)
		if (h[count] != 0) H -= log((double)h[count] / size) / logf(2) * h[count] / size;

	free(h);
	return H;
}

void bmpsize(mapsize *size)
{
	char buf[32000] = {0};

	switch (fgetc(size->bmp))
	{
	case 'P':
	case 'p':
		switch (fgetc(size->bmp))
		{
		case '2':
			do {
				fgets(buf, 32000, size->bmp);	/* 改行+コメント行を読み飛ばす */
			}while(buf[0] < '0' || '9' < buf[0]);

			sscanf(buf, "%d %d", &size->x, &size->y);
	
			fscanf(size->bmp, "%d", &size->max);
			break;
		}
		break;
	}
}

void bmpload(mapsize size, color *maps)
{
	unsigned short BMPHEADERm[4] = {0, 0, 1, 24};
	unsigned long BMPHEADER[10];
	unsigned short countZ, countT;
	unsigned long count, bufc;
	char buf[32000] = {0};

	rewind(size.bmp);

	switch (fgetc(size.bmp))
	{
	case 'P':
	case 'p':
		switch (fgetc(size.bmp))
		{
		case '2':
			do {
				fgets(buf, 32000, size.bmp);	/* 改行+コメント行を読み飛ばす */
			}while(buf[0] < '0' || '9' < buf[0]);

			fscanf(size.bmp, "%*d");

			for(count = 0; count < (unsigned)(size.x * size.y); count++)
				fscanf(size.bmp, "%d", &maps[count].gray);
			break;
		}
		break;
	}
}

char bmpsave(const char *filename, mapsize size, color *maps, unsigned char bmp)
{
	unsigned short BMPHEADERm[4] = {0, 0, 1, 24};
	unsigned long BMPHEADER[10];
	unsigned long count, countX, countY;
	char file[32000];
	FILE *fp;

	sprintf(file, "%s.%s", filename, bmp ? "bmp" : "pgm");

	/* ファイル書き込み処理 */
	if ((fp = fopen(file, "w")) == NULL) return 1;

	if (bmp)
	{
		/* BITMAP出力 構造体のアライメント回避が(クロスプラットフォームだとコンパイラの指定変更とか)
		   面倒なので非構造体で書き出し */

		/* BMPFILEHEADER */
		fprintf(fp, "BM");	/* bfType */
		BMPHEADER[0] = 54 + sizeof(color) * size.x * size.y * 3;	/* bfSize */
		memcpy(&BMPHEADER[1], BMPHEADERm, 4);	/* bfReserved1 + bfReserved2 */
		BMPHEADER[2] = 54;	/* bfOffBits */
		fwrite(BMPHEADER, sizeof(unsigned long), 3, fp);

		/* BMPINFOHEADER */
		BMPHEADER[0] = 40;	/* biSize */
		BMPHEADER[1] = size.x;	/* biWidth */
		BMPHEADER[2] = size.y;	/* biHeight */
		memcpy(&BMPHEADER[3], &BMPHEADERm[2], 4);	/* biPlanes + biBitCount */
		BMPHEADER[4] = 0;	/* biCompression */
		BMPHEADER[5] = sizeof(color) * size.x * size.y * 3;	/* biSizeImage */
		BMPHEADER[6] = 0;	/* biXPelsPerMeter */
		BMPHEADER[7] = 0;	/* biYPelsPerMeter */
		BMPHEADER[8] = 0;	/* biClrUsed */
		BMPHEADER[9] = 0;	/* biClrImportant */
		fwrite(BMPHEADER, sizeof(unsigned long), 10, fp);

		/* DATA */
		for(countY = size.y; countY > 0; countY--)	/* 左下から右上へ */
		{
			for(count = (countY - 1) * size.x; count < countY * size.x; count++)
			{
				fwrite(&maps[count], sizeof(color), 1, fp);
				fwrite(&maps[count], sizeof(color), 1, fp);
				fwrite(&maps[count], sizeof(color), 1, fp);
			}
			/* 1ラインは必ず4バイトの倍数に */
			for(count = 0; count < (4 - size.x * sizeof(color) * 3 % 4) % 4; count++)
				fprintf(fp, "%c", 0);
		}
	}
	else
	{
		/* P2出力 */
		fprintf(fp, "P2\n# 10RU004 石橋祥太\n%d %d\n255\n", size.x, size.y);

		for(countY = 0; countY < size.y; countY++)
			for(countX = 0; countX < size.x; countX++)
				fprintf(fp, "%03d%s", maps[size.x * countY + countX].gray, countX + 1 == size.x ? "\n" : " ");

		/* P5出力 なぜかずれる(PPMバイナリフォーマットの理解できてない? IrfanView側の問題?)ので放置（ぉぃ */
		/*fprintf(fp, "P5\n# 10RU004 石橋祥太\n%d %d\n255\n", size.x, size.y);

		for(count = 0; count < size.x * size.y; count++)
			fprintf(fp, "%c", maps[count].gray);
		*/
	}
	fclose(fp);
	return 0;
}