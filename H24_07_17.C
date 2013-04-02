/* 数理情報学演習III H24_07_17.C */
/* BGM,BMPファイルI/O */
/* 2012.07.17, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	unsigned char gray;
} color;

typedef struct{
	unsigned char gray;
} color2;

typedef struct{
	unsigned short x;
	unsigned short y;
	unsigned char max;
} mapsize;

char bmpload(const char *, mapsize *, color **);
char bmpsave(const char *, mapsize, const color *, unsigned char);
double entropy(const short *, unsigned long, short);
void MTF(short*, short);

void main(void)
{
	char s[32000];
	mapsize size = {0, 0};
	color *maps;
	short *Tei1, *Tei2, mtftable[512], cnt;
	unsigned long count;

	/* 画像入力 */
	printf("入力するファイルの名前を入力してください。\n");
	gets(s);

	printf("LOAD   : %s\n", bmpload(s, &size, &maps) ? "NG" : "OK");

	printf("SIZE   : %dx%d\nDEPTH  : %d\n", size.x, size.y, size.max);

	if (maps == NULL) return;

	Tei1 = (short *)malloc(size.x * size.y * sizeof(short));

	for (count = 0; count < (unsigned)(size.x * size.y); count++) Tei1[count] = maps[count].gray;

	printf("元データー\nENTROPY: %lf\n", entropy(Tei1, size.x * size.y, (short)(size.max + 1)));

	Tei2 = (short *)malloc(size.x * size.y * sizeof(short));

	/* 予測符号化 */

	Tei2[0] = Tei1[0];
	for (count = 1; count < (unsigned)(size.x * size.y); count++)
		Tei2[count] = (Tei1[count - 1] - Tei1[count]) + 255;

	printf("予測符号化\nENTROPY: %lf\n", entropy(Tei2, size.x * size.y, (short)(size.max + 256)));

	/* Move-To-Front法 */
	for (count = 0; count < 512; mtftable[count++] = count);	/* テーブル初期化 */

	for (count = 0; count < (unsigned)(size.x * size.y); MTF(mtftable, Tei2[count++] = cnt))
		for (cnt = 0; cnt < 512 && mtftable[cnt] != Tei1[count]; cnt++);

	printf("Move-To-Front法\nENTROPY: %lf\n", entropy(Tei2, size.x * size.y, (short)(size.max + 256)));

	/* 画像出力 */
	s[0] = '\0';
	printf("出力するファイルの名前を入力してください。\n(拡張子は要りません。未入力returnで保存せず終了します。)\n");
	gets(s);

	if (s[0] != '\0') printf("SAVE   : %s\n", bmpsave(s, size, maps, 3) ? "NG" : "OK");

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

	for (count = 0; count < max; count++)
		if (h[count] != 0) H -= log((double)h[count] / size) / log(2) * h[count] / size;

	free(h);
	return H;
}

char bmpload(const char *file, mapsize *size, color **maps)
{
	unsigned char buf[32000] = {0}, hoge, mode, os2 = 0, err = 0;
    unsigned short bfReserved[2], biPlanes, biBitCount, bcWidth, bcHeight;
	unsigned long bfSize, bfOffBits, biSize, biWidth, biHeight, biCompression, biSizeImage, biClrUsed, biClrImportant, count;
	FILE *fp;

	*maps = NULL;	/* 失敗時用 */

	/* ファイル読み込み処理 */
	if ((fp = fopen(file, "rb")) == NULL) return 1;

	switch (fgetc(fp))
	{
	case 'B':	/* BITMAP入力 */
		size->max = 255;

		if (err = (fgetc(fp) != 'M')) break;

		/* BITMAPFILEHEADER */
		fread(&bfSize, sizeof(unsigned long), 1, fp);
		fread(bfReserved, sizeof(unsigned short), 2, fp);
		fread(&bfOffBits, sizeof(unsigned long), 1, fp);

		if (err = (bfReserved[0] != 0 || bfReserved[1] != 0)) break;

		/* BMPINFOHEADER */
		fread(&biSize, sizeof(unsigned long), 1, fp);
		switch (biSize)
		{
		case 12:	/* OS/2 V1 */
			os2 = 1;
			fread(&bcWidth, sizeof(unsigned short), 1, fp);
			fread(&bcHeight, sizeof(unsigned short), 1, fp);
			fread(&biPlanes, sizeof(unsigned short), 1, fp);
			fread(&biBitCount, sizeof(unsigned short), 1, fp);
			size->x = bcWidth;
			size->y = bcHeight;
			break;

		case 64:	/* OS/2 V2 */
			os2 = 1;
		case 40:	/* Windows V3 */
		case 108:	/* Windows V4 */
		case 124:	/* Windows V5 */
			fread(&biWidth, sizeof(unsigned long), 1, fp);
			fread(&biHeight, sizeof(unsigned long), 1, fp);
			fread(&biPlanes, sizeof(unsigned short), 1, fp);
			fread(&biBitCount, sizeof(unsigned short), 1, fp);
			fread(&biCompression, sizeof(unsigned long), 1, fp);
			fread(&biSizeImage, sizeof(unsigned long), 1, fp);
			for(count = 0; count < 8; count++)
				fread(&hoge, sizeof(unsigned char), 1, fp);	/* 読み飛ばす */
			fread(&biClrUsed, sizeof(unsigned long), 1, fp);
			fread(&biClrImportant, sizeof(unsigned long), 1, fp);
			for(count = 40; count < biSize; count++)
				fread(&hoge, sizeof(unsigned char), 1, fp);	/* 読み飛ばす */
			size->x = biWidth;
			size->y = biHeight;
			break;

		default:
			err = 1;
			break;
		}
		err |= biPlanes != 1;
		if (err != 0) break;

		return 1;	/* DEBUG */

		/* DATA */
		//for(countZ = size.y; countZ > 0; countZ--)	/* 左下から右上へ */
		//{
		//	for(count = countZ * size.x - size.x; count < size.x + countZ * size.x - size.x; count++)
		//		fwrite(&maps[count], sizeof(color), 1, fp);

		//	/* 1ラインは必ず4バイトの倍数に */
		//	for(count = 0; count < (4 - size.x * sizeof(color) % 4) % 4; count++)
		//		fprintf(fp, "%c", 0);
		//}
		break;

	case 'P':	/* PGM入力 */
	case 'p':
		mode = fgetc(fp);
		do {
			fgets(buf, 31999, fp);	/* 改行+コメント行を読み飛ばす */
		}while (buf[0] < '0' || '9' < buf[0]);

		sscanf(buf, "%d %d", &size->x, &size->y);

		fscanf(fp, "%d%*c", &size->max);

		if (err = (*maps = (color *)malloc(size->x * size->y * sizeof(color))) == NULL) break;

		for(count = 0; count < size->x * size->y && err == 0; count++)
			switch (mode)
			{
			case '2':
				/* fscanf(fp, "%d", &(*maps)[count].gray); ヒープ領域破壊主犯 撤去 */
				fscanf(fp, "%d", &hoge);
				(*maps)[count].gray = hoge;
				break;
			case '5':
				(*maps)[count].gray = (unsigned char)fgetc(fp);
				break;
			default:
				err = 1;
				break;
			}
		break;

	default:
		err = 1;
		break;
	}
	fclose(fp);
	return err;
}

char bmpsave(const char *filename, mapsize size, const color *maps, unsigned char bmp)
{
	unsigned short BMPHEADERm[2] = {0};
	unsigned long BMPHEADER[10];
	unsigned long count, countX, countY;
	char file[32000];
	FILE *fp;

	sprintf(file, "%s.%s", filename, bmp & 1 ? "bmp" : "pgm");

	/* ファイル書き込み処理 */
	if ((fp = fopen(file, "wb")) == NULL) return 1;

	/* 0.P2 1.BMP(24bit) 2.P5 3.BMP(8bit) */
	if (bmp & 1)
	{
		/* BITMAP出力 構造体のアライメント回避が(クロスプラットフォームだとコンパイラの指定変更とか)
		   面倒なので非構造体で書き出し */

		/* BMPFILEHEADER */
		fprintf(fp, "BM");	/* bfType */
		BMPHEADER[0] = 54 + (bmp & 2 ? 256 : 0) * 4 + sizeof(color) * size.x * size.y * (bmp & 2 ? 1 : 3);	/* bfSize */
		memcpy(&BMPHEADER[1], BMPHEADERm, 4);	/* bfReserved1 + bfReserved2 */
		BMPHEADER[2] = 54 + (bmp & 2 ? 256 : 0) * 4;	/* bfOffBits */
		fwrite(BMPHEADER, sizeof(unsigned long), 3, fp);

		/* BMPINFOHEADER */
		BMPHEADER[0] = 40;	/* biSize */
		BMPHEADER[1] = size.x;	/* biWidth */
		BMPHEADER[2] = size.y;	/* biHeight */
		BMPHEADERm[0] = 1;	/* biPlanes */
		BMPHEADERm[1] = bmp & 2 ? 8 : 24;	/* biBitCount */
		memcpy(&BMPHEADER[3], BMPHEADERm, 4);
		BMPHEADER[4] = 0;	/* biCompression */
		BMPHEADER[5] = sizeof(color) * size.x * size.y * (bmp & 2 ? 1 : 3);	/* biSizeImage */
		BMPHEADER[6] = 0;	/* biXPelsPerMeter */
		BMPHEADER[7] = 0;	/* biYPelsPerMeter */
		BMPHEADER[8] = bmp & 2 ? 256 : 0;	/* biClrUsed */
		BMPHEADER[9] = BMPHEADER[8];	/* biClrImportant */
		fwrite(BMPHEADER, sizeof(unsigned long), 10, fp);

		/* RGBQUAD */
		if (bmp & 2)
			for(countY = 0; countY < 256; countY++)
			{
				for(countX = 0; countX < 3; countX++)
					fprintf(fp, "%c", countY);

				fprintf(fp, "%c", 0);
			}

		/* DATA */
		for(countY = size.y; countY > 0; countY--)	/* 左下から右上へ */
		{
			for(count = (countY - 1) * size.x; count < countY * size.x; count++)
				for(countX = 0; countX < (bmp & 2 ? 1 : 3); countX++)
					fwrite(&maps[count], sizeof(color), 1, fp);

			/* 1ラインは必ず4バイトの倍数に */
			for(count = 0; count < (4 - size.x * sizeof(color) * (bmp & 2 ? 1 : 3) % 4) % 4; count++)
				fprintf(fp, "%c", 0);
		}
	}
	else
	{
		/* BGM出力 */
		fprintf(fp, "P%d\n# 10RU004 石橋祥太\n%d %d\n255\n", bmp & 2 ? 5 : 2, size.x, size.y);

		if (bmp & 2)	/* P5出力 */
			for(count = 0; count < size.x * size.y; count++)
				fprintf(fp, "%c", maps[count].gray);

		else	/* P2出力 */
			for(countY = 0; countY < size.y; countY++)
				for(countX = 0; countX < size.x; countX++)
					fprintf(fp, "%03d%s", maps[size.x * countY + countX].gray, countX + 1 == size.x ? "\n" : " ");
	}
	fclose(fp);
	return 0;
}