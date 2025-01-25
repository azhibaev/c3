/*
 *	Warning !
 *	This file is generated automatically.
 *	DO NOT EDIT.
 *	Edit the "file/file.mod.h" file.
 */
/*
 * File:  file.mod.h
 * Description: File functions
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"
#include "chars.h"

#ifndef MODULE_NAME
#define MODULE_NAME file
#else
#define MODULE_NAME_SUFFIX file
#endif

#define MODULE_STRUCT file_struct.h
#define FILE_FLAG_READ (1 << 1)
#define FILE_FLAG_WRITE (1 << 2)
#define FILE_FLAG_READ_LINE (1 << 3)
#define FILE_FLAG_WRITE_LINE (1 << 4)

#define MODULE_INIT file_init.h
#define MODULE_INIT_VAR file_init_var.h
#define MODULE_FREE file_free.h
#include "mod.h"

FUNCTION_INLINE int FUNC(read)(T *p)
{
	int is_set = 0;

	if (p)
	{
		if (p->is_read)
		{
			if (p->s->is_init &&
					p->s->is_alloc)
			{
				if (p->s->wpos < p->s->size)
				{
					p->read_bytes = fread(p->s->buf + p->s->wpos, 1, p->s->size - p->s->wpos, p->f);
					if (p->read_bytes)
					{
						p->s->wpos += p->read_bytes;
						is_set++;
					}
				}
				else if (p->s->rpos < p->s->wpos)
				{
					is_set++;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(write_chars)(T *p,
		chars *s,
		unsigned int flags)
{
	int is_set = 0;
	size_t pos1 = 0;
	size_t pos2 = 0;
	size_t size = 0;

	if (p)
	{
		if (s)
		{
			if (FILE_FLAG_WRITE_LINE & flags)
			{
				while (!is_set)
				{
					pos1 = chars_get_mark(p->s);
					if (chars_find_crlf(p->s))
					{
						pos2 = chars_get_mark(p->s);
						size = pos2 - pos1;
						chars_set_mark(p->s, pos1);
						if (size)
						{
							if (chars_copy(s, p->s, size, CHARS_FLAG_ADVANCE_READ_POS))
							{
								is_set++;
								break;
							}
						}
					}
					else
					{
						chars_set_mark(p->s, pos1);
						size = p->s->wpos - p->s->rpos;
						if (size)
						{
							chars_copy(s, p->s, size, CHARS_FLAG_ADVANCE_READ_POS);
						}
						chars_compact(p->s);
						if (!FUNC(read)(p))
						{
							if (!size)
							{
								break;
							}
						}
					}
				}
			}
			else
			{
				if (chars_check(p->s))
				{
					if (chars_read_pchar(s, p->s->buf + p->s->rpos, p->s->wpos - p->s->rpos, 0))
					{
						chars_reset(p->s);
						is_set++;
					}
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(read_chars)(T *p,
		chars *s,
		size_t s_size,
		unsigned int flags)
{
	int is_set = 0;
	size_t pos1 = 0;
	size_t pos2 = 0;
	size_t size = 0;

	if (p)
	{
		if (s)
		{
			if (FILE_FLAG_READ_LINE & flags)
			{
				pos1 = chars_get_mark(s);
				if (chars_find_crlf(s))
				{
					pos2 = chars_get_mark(s);
					size = pos2 - pos1;
					chars_set_mark(s, pos1);
					if (size)
					{
						p->write_bytes = fwrite(s->buf + s->rpos, sizeof(char), size, p->f);
						if (p->write_bytes)
						{
							s->rpos += p->write_bytes;
							is_set++;
						}
					}
				}
				else
				{
					chars_set_mark(s, pos1);
					size = s->wpos - s->rpos;
					if (size)
					{
						p->write_bytes = fwrite(s->buf + s->rpos, sizeof(char), size, p->f);
						if (p->write_bytes)
						{
							s->rpos += p->write_bytes;
							is_set++;
						}
					}
				}
			}
			else
			{
				if (chars_check(s))
				{
					p->write_bytes = fwrite(s->buf + s->rpos, sizeof(char), s->wpos - s->rpos, p->f);
					if (p->write_bytes)
					{
						s->rpos += p->write_bytes;
						is_set++;
					}
				}
			}
		}
	}

	return is_set;
}

#include "mod_undef.h"

#endif	/* FILE_H */
