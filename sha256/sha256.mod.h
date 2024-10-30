/*
 * File:  sha256.mod.h
 * Description: SHA 256 module sample
 * Author: Askar Azhibaev
 * Date:  July 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef SHA256_H
#define SHA256_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

#include "chars.h"

#module sha256

#struct
unsigned int *h;
unsigned int *k;
unsigned int *w;
unsigned int *a;
unsigned char *m;

#init ()
p->h = malloc(8 * sizeof(unsigned int));
p->a = malloc(8 * sizeof(unsigned int));
p->k = malloc(64 * sizeof(unsigned int));
p->w = malloc(64 * sizeof(unsigned int));
p->m = malloc(64 * sizeof(unsigned char));
p->h[0] = 0x6A09E667;
p->h[1] = 0xBB67AE85;
p->h[2] = 0x3C6EF372;
p->h[3] = 0xA54FF53A;
p->h[4] = 0x510E527F;
p->h[5] = 0x9B05688C;
p->h[6] = 0x1F83D9AB;
p->h[7] = 0x5BE0CD19;
p->k[0] = 0x428A2F98;
p->k[1] = 0x71374491;
p->k[2] = 0xB5C0FBCF;
p->k[3] = 0xE9B5DBA5;
p->k[4] = 0x3956C25B;
p->k[5] = 0x59F111F1;
p->k[6] = 0x923F82A4;
p->k[7] = 0xAB1C5ED5;
p->k[8] = 0xD807AA98;
p->k[9] = 0x12835B01;
p->k[10] = 0x243185BE;
p->k[11] = 0x550C7DC3;
p->k[12] = 0x72BE5D74;
p->k[13] = 0x80DEB1FE;
p->k[14] = 0x9BDC06A7;
p->k[15] = 0xC19BF174;
p->k[16] = 0xE49B69C1;
p->k[17] = 0xEFBE4786;
p->k[18] = 0x0FC19DC6;
p->k[19] = 0x240CA1CC;
p->k[20] = 0x2DE92C6F;
p->k[21] = 0x4A7484AA;
p->k[22] = 0x5CB0A9DC;
p->k[23] = 0x76F988DA;
p->k[24] = 0x983E5152;
p->k[25] = 0xA831C66D;
p->k[26] = 0xB00327C8;
p->k[27] = 0xBF597FC7;
p->k[28] = 0xC6E00BF3;
p->k[29] = 0xD5A79147;
p->k[30] = 0x06CA6351;
p->k[31] = 0x14292967;
p->k[32] = 0x27B70A85;
p->k[33] = 0x2E1B2138;
p->k[34] = 0x4D2C6DFC;
p->k[35] = 0x53380D13;
p->k[36] = 0x650A7354;
p->k[37] = 0x766A0ABB;
p->k[38] = 0x81C2C92E;
p->k[39] = 0x92722C85;
p->k[40] = 0xA2BFE8A1;
p->k[41] = 0xA81A664B;
p->k[42] = 0xC24B8B70;
p->k[43] = 0xC76C51A3;
p->k[44] = 0xD192E819;
p->k[45] = 0xD6990624;
p->k[46] = 0xF40E3585;
p->k[47] = 0x106AA070;
p->k[48] = 0x19A4C116;
p->k[49] = 0x1E376C08;
p->k[50] = 0x2748774C;
p->k[51] = 0x34B0BCB5;
p->k[52] = 0x391C0CB3;
p->k[53] = 0x4ED8AA4A;
p->k[54] = 0x5B9CCA4F;
p->k[55] = 0x682E6FF3;
p->k[56] = 0x748F82EE;
p->k[57] = 0x78A5636F;
p->k[58] = 0x84C87814;
p->k[59] = 0x8CC70208;
p->k[60] = 0x90BEFFFA;
p->k[61] = 0xA4506CEB;
p->k[62] = 0xBEF9A3F7;
p->k[63] = 0xC67178F2;

#free ()
if (p->h)
{
	free(p->h);
	p->h = NULL;
}
if (p->a)
{
	free(p->a);
	p->a = NULL;
}
if (p->k)
{
	free(p->k);
	p->k = NULL;
}
if (p->w)
{
	free(p->w);
	p->w = NULL;
}
if (p->m)
{
	free(p->m);
	p->m = NULL;
}

#include "module.h"

FUNCTION_INLINE unsigned int FUNC(rightrotate)(unsigned int i,
		unsigned int n);

FUNCTION_INLINE int FUNC(set_m)(T *p,
		const char *s)
{
	int is_set = 0;
	int i = 0;
	int j = 0;

	if (p)
	{
		if (s)
		{
			for (i = 0; i < 55; i++)
			{
				if (!s[i])
				{
					break;
				}
				p->m[i] = s[i];
			}
			is_set = i;
			p->m[i] = 0x80;
			for (j = i + 1; j < 56; j++)
			{
				p->m[j] = 0;
			}
			i *= 8;
			for (j = 63; j >= 56; j--)
			{
				p->m[j] = i & 0xff;
				i >>= 8;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(set_w)(T *p)
{
	int is_set = 0;
	int i = 0;
	int j = 0;
	unsigned int s0 = 0;
	unsigned int s1 = 0;

	if (p)
	{
		for (i = 0; i < 16; i++)
		{
			p->w[i] = p->m[i * 4];
			p->w[i] <<= 8;
			p->w[i] |= p->m[i * 4 + 1];
			p->w[i] <<= 8;
			p->w[i] |= p->m[i * 4 + 2];
			p->w[i] <<= 8;
			p->w[i] |= p->m[i * 4 + 3];
		}
		for (j = i; j < 64; j++)
		{
			s0 = (FUNC(rightrotate)(p->w[j - 15], 7) ^
					FUNC(rightrotate)(p->w[j - 15], 18) ^
					p->w[j - 15] >> 3);
			s1 = (FUNC(rightrotate)(p->w[j - 2], 17) ^
					FUNC(rightrotate)(p->w[j - 2], 19) ^
					p->w[j - 2] >> 10);
			p->w[j] = p->w[j - 16] + s0 + p->w[j - 7] + s1;
		}
		is_set = i;
	}

	return is_set;
}

FUNCTION_INLINE unsigned int FUNC(rightrotate)(unsigned int i,
		unsigned int n)
{
	unsigned int c = 0;
	unsigned int cn = 0;

	cn = (1 << n) - 1;
	c = i & cn;
	i >>= n;
	c <<= 32 - n;
	i |= c;

	return i;
}

FUNCTION_INLINE int FUNC(compress)(T *p)
{
	int is_set = 0;
	int i = 0;
	unsigned int s0 = 0;
	unsigned int s1 = 0;
	unsigned int ch = 0;
	unsigned int temp1 = 0;
	unsigned int temp2 = 0;
	unsigned int maj = 0;
	const int b = 1;
	const int c = 2;
	const int d = 3;
	const int e = 4;
	const int f = 5;
	const int g = 6;
	const int h = 7;

	if (p)
	{
		for (i = 0; i < 8; i++)
		{
			p->a[i] = p->h[i];
		}
		for (i = 0; i < 64; i++)
		{
			s1 = (FUNC(rightrotate)(p->a[e], 6) ^
					FUNC(rightrotate)(p->a[e], 11) ^
					FUNC(rightrotate)(p->a[e], 25));
			ch = (p->a[e] & p->a[f]) ^
				(~(p->a[e]) & p->a[g]);
			temp1 = p->a[h] + s1 + ch + p->k[i] + p->w[i];
			s0 = (FUNC(rightrotate)(p->a[0], 2) ^
					FUNC(rightrotate)(p->a[0], 13) ^
					FUNC(rightrotate)(p->a[0], 22));
			maj = (p->a[0] & p->a[b]) ^
				(p->a[0] & p->a[c]) ^
				(p->a[b] & p->a[c]);
			temp2 = s0 + maj;
			p->a[h] = p->a[g];
			p->a[g] = p->a[f];
			p->a[f] = p->a[e];
			p->a[e] = p->a[d] + temp1;
			p->a[d] = p->a[c];
			p->a[c] = p->a[b];
			p->a[b] = p->a[0];
			p->a[0] = temp1 + temp2;
		}
		is_set = i;
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(set_h)(T *p)
{
	int is_set = 0;
	int i = 0;

	if (p)
	{
		for (i = 0; i < 8; i++)
		{
			p->h[i] += p->a[i];
		}
		is_set = i;
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(print)(T *p)
{
	int is_set = 0;
	int i = 0;

	if (p)
	{
		for (i = 0; i < 8; i++)
		{
			printf("%8x", p->h[i]);
		}
		printf("\n");
	}

	return is_set;
}

#include "module_undef.h"

#endif	/* SHA123_H */

