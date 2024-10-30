/*
 * File:  parse_c3_identifier.h
 * Description: C3 extension parser for C programming language
 * Author: Askar Azhibaev
 * Date: June 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

FUNCTION_INLINE int FUNC(identifier)(T *p,
		unsigned int flags)
{
	int is_set = 0;
	unsigned char c = 0;
	chars *s = NULL;
	size_t pos = 0;

	if (p)
	{
		s = p->s;
		if (chars_check_read(s))
		{
			pos = chars_get_mark(s);
			c = chars_get_char(s);
			if (PARSE_C3_ALPHA || PARSE_C3_UNDERLINE)
			{
				if (PARSE_C3_ALPHA)
				{
					is_set++;
				}
				while (chars_next_char(s))
				{
					c = chars_get_char(s);
					if (PARSE_C3_ALPHA || PARSE_C3_DIGIT || PARSE_C3_UNDERLINE)
					{
						is_set++;
					}
					else
					{
						break;
					}
				}
			}
			if (is_set)
			{
				chars_read_pchar(p->s_identifier, s->buf + pos, s->rpos - pos, 0);
				if (PARSE_C3_FLAG_SKIP_LWS & flags)
				{
					if (FUNC(lws)(p))
					{
					}
				}
			}
			else
			{
				chars_set_mark(s, pos);
			}
		}
	}

	return is_set;
}

