/*
 *	Warning !
 *	This file is generated automatically.
 *	DO NOT EDIT.
 *	Edit the "sha256/sha256.mod.h" file.
 */
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

#ifndef MODULE_NAME
#define MODULE_NAME sha256
#else
#define MODULE_NAME_SUFFIX sha256
#endif

#define MODULE_STRUCT sha256_struct.h
#define MODULE_INIT sha256_init.h
#define MODULE_FREE sha256_free.h
#include "mod.h"

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
			printf("%08x", p->h[i]);
		}
		printf("\n");
	}

	return is_set;
}

#include "mod_undef.h"

#endif	/* SHA123_H */

