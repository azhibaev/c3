/*
 * File:  parse_c3_whitespace.h
 * Description: C3 extension parser for C programming language
 * Author: Askar Azhibaev
 * Date: June 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

FUNCTION_INLINE int FUNC(crlf)(T *p)
{
	int is_set = 0;
	unsigned char c = 0;
	chars *s = NULL;

	if (p)
	{
		s = p->s;
		c = chars_get_char(s);
		if (PARSE_C3_CR)
		{
			c = chars_get_next_char(s);
			if (PARSE_C3_LF)
			{
				c = chars_get_next_char(s);
				is_set = 1;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(lws)(T *p)
{
	int is_set = 0;
	unsigned char c = 0;
	chars *s = NULL;

	if (p)
	{
		s = p->s;
		if (FUNC(crlf)(p))
		{
		}

		c = chars_get_char(s);
		while (PARSE_C3_SP || PARSE_C3_HT)
		{
			is_set++;
			c = chars_get_next_char(s);
		}
	}

	return is_set;
}

