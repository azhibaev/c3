/*
 * File:  chars.mod.h
 * Description: Chars string functions
 * Author: Askar Azhibaev
 * Date: June 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef CHARS_H
#define CHARS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

/* Defaults */
#define CHARS_DEFAULT_BUFFER_SIZE		1 KB
#define CHARS_DEFAULT_GROWTH_FACTOR		1.5

#module chars

#struct
char *buf;
size_t size;
size_t rpos;
size_t wpos;
float factor;
init;
alloc;

#init (size_t size)
if (!size)
{
	size = CHARS_DEFAULT_BUFFER_SIZE;
}
p->buf = malloc(size * sizeof(char));
if (p->buf)
{
	p->size = size;
	p->is_init = 1;
	p->is_alloc = 1;
}
else
{
	p->is_alloc = 0;
}
p->factor = CHARS_DEFAULT_GROWTH_FACTOR;
is_init = 1;

#free
if (p->buf)
{
	free(p->buf);
	p->buf = NULL;
}

#include "module.h"

/* Flags */

/* Flags for print */
#define CHARS_FLAG_PRINT_NEWLINE	(1 << 8)
#define CHARS_FLAG_PRINT_HEX		(1 << 9)
#define CHARS_FLAG_PRINT_ALL		(1 << 10)
#define CHARS_FLAG_PRINT_SPACE		(1 << 11)

/* Flags for write, read */
#define CHARS_FLAG_NO_CHECK				(1 << 1)
#define CHARS_FLAG_RESET				(1 << 2)
#define CHARS_FLAG_POINTER				(1 << 3)
#define CHARS_FLAG_NOT_NULL_TERMINATED	(1 << 4)
#define CHARS_FLAG_ADVANCE_READ_POS		(1 << 5)
#define CHARS_FLAG_ALLOC				(1 << 6)
#define CHARS_FLAG_GROWTH_FACTOR		(1 << 8)

enum T_NAME(info_type)
{
	T_PREFIX_NAME(info_type,int),
	T_PREFIX_NAME(info_type,size_t),
	T_PREFIX_NAME(info_type,char),
	T_PREFIX_NAME(info_type,float),
	T_PREFIX_NAME(info_type,double),
};

#include STR(T_NAME(utils.h))		/* chars_utils.h */
#include STR(T_NAME(char.h))		/* chars_char.h */
#include STR(T_NAME(pchar.h))		/* chars_pchar.h */
#include STR(T_NAME(mark.h))		/* chars_mark.h */
#include STR(T_NAME(find.h))		/* chars_find.h */

#include "module_undef.h"

#endif	/* CHARS_H */

