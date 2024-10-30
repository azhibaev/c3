/*
 * File:  chars_pchar.h
 * Description: Chars string functions
 * Author: Askar Azhibaev
 * Date: June 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

/*
Writes from char *s to (p->buf + p->wpos)
CHARS_FLAG_NOT_NULL_TERMINATED - does not add NULL at the end of a string
CHARS_FLAG_RESET - writes from the beginning
*/
FUNCTION_INLINE int FUNC(read_pchar)(T *p,
	const char *s,
	size_t s_size,
	unsigned int flags)
{
	int is_set = 0;
	size_t size = 0;

	if (p)
	{
		if (!p->is_init)
		{
			chars_init(p, s_size ? s_size + 2 : 0);
		}
		if (FUNC(check)(p))
		{
			if (s)
			{
				if (CHARS_FLAG_RESET & flags)
				{
					if (!FUNC(reset)(p))
					{
						/* Error */
					}
				}
				/* Check size */
				if (s_size)
				{
					size = s_size;
				}
				else
				{
					size = strlen(s);
				}

				/* Check p->size */
				if (p->size - p->wpos < size + 1 ||
						!p->is_alloc)
				{
					if (!FUNC(realloc)(p, p->wpos + size + 1, CHARS_FLAG_GROWTH_FACTOR))
					{
						/* Error */
					}
				}

				memcpy(p->buf + p->wpos, s, size);
				p->wpos += size;
				if (!(CHARS_FLAG_NOT_NULL_TERMINATED & flags))
				{
					p->buf[p->wpos] = 0;
				}
				is_set = 1;
			}
		}
	}

	return is_set;
}

/*
Copy from (p->buf + p->rpos) of length s_size
returns a pointer,
size of s must be 1 byte larger than s_size,
CHARS_FLAG_ALLOC - allocate memory, call free() after use,
CHARS_FLAG_POINTER - returns a pointer to (p->buf + p->rpos),
CHARS_FLAG_NOT_NULL_TERMINATED - does not add NULL at the end of a string
CHARS_FLAG_ADVANCE_READ_POS - shift read position by size
CHARS_FLAG_RESET - reads from the beginning
*/
FUNCTION_INLINE char* FUNC(write_pchar)(T *p,
		char *s,
		size_t s_size,
		unsigned int flags)
{
	size_t size = 0;
	char *buf = NULL;

	if (FUNC(check)(p))
	{
		/* Check size */
		size = p->wpos - p->rpos;
		if (!size ||
				size < s_size)
		{
			s_size = size;
		}

		if (CHARS_FLAG_RESET & flags)
		{
			p->rpos = 0;
		}
		if (CHARS_FLAG_POINTER & flags)
		{
			buf = p->buf + p->rpos;
		}
		else if (CHARS_FLAG_ALLOC & flags)
		{
			if (CHARS_FLAG_NOT_NULL_TERMINATED & flags)
			{
				buf = malloc((s_size) * sizeof(char));
				if (buf)
				{
					memcpy(buf, p->buf + p->rpos, s_size);
				}
			}
			else
			{
				buf = malloc((s_size + 2) * sizeof(char));
				if (buf)
				{
					memcpy(buf, p->buf + p->rpos, s_size);
					buf[s_size] = 0;
				}
			}
		}
		else
		{
			memcpy(s, p->buf + p->rpos, s_size);
			if (!(CHARS_FLAG_NOT_NULL_TERMINATED & flags))
			{
				s[s_size] = 0;
			}
			buf = s;
		}

		p->rpos += s_size;
	}

	return buf;
}

