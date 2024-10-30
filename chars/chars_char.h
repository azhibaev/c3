/*
 * File:  chars_char.h
 * Description: Chars string functions
 * Author: Askar Azhibaev
 * Date: June 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

FUNCTION_INLINE unsigned char FUNC(get_char)(T *s)
{
	unsigned char c = 0;

	if (FUNC(check_read)(s))
	{
		c = s->buf[s->rpos];
	}

	return c;
}

FUNCTION_INLINE unsigned char FUNC(get_next_char)(T *s)
{
	unsigned char c = 0;

	if (FUNC(check_read)(s))
	{
		if (s->rpos < s->wpos)
		{
			s->rpos++;
			c = s->buf[s->rpos];
		}
	}

	return c;
}

FUNCTION_INLINE unsigned char FUNC(next_char)(T *s)
{
	int is_set = 0;

	if (FUNC(check_read)(s))
	{
		if (s->rpos < s->wpos)
		{
			s->rpos++;
			is_set = 1;
		}
	}

	return is_set;
}

