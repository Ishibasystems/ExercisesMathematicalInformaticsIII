/* 数理情報学演習III TAX.C */
/* BGM,BMPファイルI/O */
/* 2012.06.12, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	unsigned char gray;
} color;

typedef struct{
	unsigned short x;
	unsigned short y;
	unsigned char max;
} mapsize;

char bmpload(const char *, mapsize *, color **);
char bmpsave(const char *, mapsize, color *, unsigned char);
double entropy(const color *, unsigned long, short);

void main()
{
	char s[32000], *s_;
	mapsize size = {0, 0};
	color *Tei, *maps;
	unsigned long count;

	/* 画像入力 */
	printf("入力するファイルの名前を入力してください。\n");
	scanf("%s", s);

	printf("LOAD   : %s\n", bmpload(s, &size, &maps) ? "NG" : "OK");

/*	printf("%d %d\n", size.x, size.y);
	for (y = 0; y < 10; y++)
	{
		for (x = 0; x < size.x; x++)
			printf("%03d ", (*maps)[size.x * y + x].gray);

		printf("\n");
	}*/
	printf("SIZE   : %dx%d\nDEPTH  : %d\n", size.x, size.y, size.max);

	printf("ENTROPY: %lf\n", entropy(maps, size.x * size.y, size.max + 1));

	/* エントロピー低減 */
	Tei = (color *)calloc(size.x * size.y, sizeof(color));

	Tei[0].gray = maps[0].gray;
	for (count = 0; count < size.x * size.y; count++)
		Tei[count].gray = (maps[count - 1].gray - maps[count].gray + 256) % 256;

	printf("ENTROPY: %lf\n", entropy(Tei, size.x * size.y, size.max + 1));

	/* 画像出力 */
	s_ = s;
	while(*(s_++) != '.');
	*(s_ - 1) = '\0';
	sprintf(s, "%s_after", s);

	//printf("SAVE   : %s\n", bmpsave(s, size, maps[0], 1) ? "NG" : "OK");

	/* 解放 */
	free(maps);
	return;
}

double entropy(const color *col, unsigned long size, short max)
{
	unsigned long count, *h;
	double H = 0.0;

	h = (unsigned long *)calloc(max, sizeof(unsigned long));

	for (count = 0; count < size; count++)
		h[col[count].gray]++;

	for (count = 0; count < max; count++)
		if (h[count] != 0) H -= log((double)h[count] / size) / log(2) * h[count] / size;

	free(h);
	return H;
}

char bmpload(const char *file, mapsize *size, color **maps)
{
	unsigned short BMPHEADERm[4] = {0, 0, 1, 24};
	unsigned long BMPHEADER[10];
	unsigned short countZ, countT;
	unsigned long count, bufc;
	unsigned char buf[32000] = {0}, max;
	FILE *fp;

	/* ファイル読み込み処理 */
	if ((fp = fopen(file, "rb")) == NULL) return 1;

	switch (fgetc(fp))
	{
	//if (bmp)
	//{
	//	/* BITMAP出力 構造体のアライメント回避が(クロスプラットフォームだとコンパイラの指定変更とか)
	//	   面倒なので非構造体で書き出し */

	//	/* BMPFILEHEADER */
	//	fprintf(fp, "BM");	/* bfType */
	//	BMPHEADER[0] = 54 + sizeof(color) * size.x * size.y;	/* bfSize */
	//	memcpy(&BMPHEADER[1], BMPHEADERm, 4);	/* bfReserved1 + bfReserved2 */
	//	BMPHEADER[2] = 54;	/* bfOffBits */
	//	fwrite(BMPHEADER, sizeof(unsigned long), 3, fp);

	//	/* BMPINFOHEADER */
	//	BMPHEADER[0] = 40;	/* biSize */
	//	BMPHEADER[1] = size.x;	/* biWidth */
	//	BMPHEADER[2] = size.y;	/* biHeight */
	//	memcpy(&BMPHEADER[3], &BMPHEADERm[2], 4);	/* biPlanes + biBitCount */
	//	BMPHEADER[4] = 0;	/* biCompression */
	//	BMPHEADER[5] = sizeof(color) * size.x * size.y;	/* biSizeImage */
	//	BMPHEADER[6] = 0;	/* biXPelsPerMeter */
	//	BMPHEADER[7] = 0;	/* biYPelsPerMeter */
	//	BMPHEADER[8] = 0;	/* biClrUsed */
	//	BMPHEADER[9] = 0;	/* biClrImportant */
	//	fwrite(BMPHEADER, sizeof(unsigned long), 10, fp);

	//	/* DATA */
	//	for(countZ = size.y; countZ > 0; countZ--)	/* 左下から右上へ */
	//	{
	//		for(count = countZ * size.x - size.x; count < size.x + countZ * size.x - size.x; count++)
	//			fwrite(&maps[count], sizeof(color), 1, fp);

	//		/* 1ラインは必ず4バイトの倍数に */
	//		for(count = 0; count < (4 - size.x * sizeof(color) % 4) % 4; count++)
	//			fprintf(fp, "%c", 0);
	//	}
	//}
	case 'P':
	case 'p':
		switch (fgetc(fp))
		{
		case '2':
		/* P2入力 */
			do {
				fgets(buf, 32000, fp);	/* 改行+コメント行を読み飛ばす */
			}while(buf[0] < '0' || '9' < buf[0]);

			sscanf(buf, "%d %d", &BMPHEADERm[0], &BMPHEADERm[1]);	/* 別の変数を介さないとデータ破壊される なぜ? */
			size->x = BMPHEADERm[0];
			size->y = BMPHEADERm[1];

			fscanf(fp, "%d", &max);
			size->max = max;

			*maps = (color *)malloc(sizeof(color) * size->x * size->y);

			for(count = 0; count < size->x * size->y; count++)
				fscanf(fp, "%d", &(*maps)[count].gray);
			break;

		case '5':
			///* P5出力 なぜかずれる(PPMバイナリフォーマットの理解できてない? IrfanView側の問題?)ので放置（ぉぃ */
			///*fprintf(fp, "P5\n# 10RU004 石橋祥太\n%d %d\n255\n", size.x, size.y);

			//for(count = 0; count < size.x * size.y; count++)
			//	fprintf(fp, "%c", maps[count].gray);
			//*/
			break;
		}
		break;

	default:
		break;
	}
	fclose(fp);
	return 0;
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