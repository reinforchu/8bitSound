﻿#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	int i, j;
	unsigned char header[44] = { 0x52, 0x49, 0x46, 0x46, 0x34, 0xb1, 0x02, 0x00, 0x57, 0x41, 0x56, 0x45, 0x66, 0x6d, 0x74, 0x20, 0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x44, 0xac, 0x00, 0x00, 0x44, 0xac, 0x00, 0x00, 0x01, 0x00, 0x08, 0x00, 0x64, 0x61, 0x74, 0x61, 0x10, 0xb1, 0x02, 0x00 };
	FILE* fp;
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	unsigned char buff[44100 / 4] = { 0 };
	int p = 0;
	if ((fopen_s(&fp, "out.wav", "wb")) == NULL) {
		// exit(EXIT_FAILURE);
	}
	fwrite(header, 1, 44, fp);
	for (i = 0; i < 16; i++)
	{
		int key;
		scanf_s("%d", &key);
		for (j = 0; j < 44100 / 4; j++)
		{
			unsigned char a = (unsigned char)((sin(x) >= 0.0 ? 1.0 : -1.0) * 127.0 + 128.0);
			buff[p] = a;
			p = (p + 1) % (44100 / 4);
			fwrite(&a, 1, 1, fp);
			x += (441.0 + sin(y) * 10.0) * pow(2.0, (double)key / 12.0) * 2.0 * 3.14159265358979 / 44100.0;
			y += 5.0 * 2.0 * 3.14159265358979 / 44100.0;
			z += (441.0 + sin(y) * 10.0) * pow(2.0, (double)(key + 7) / 12.0) * 2.0 * 3.14159265358979 / 44100.0;
		}
	}
	fclose(fp);
	return 0;
}
