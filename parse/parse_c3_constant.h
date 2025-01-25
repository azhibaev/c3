/*
 * File:  parse_c3_constant.h
 * Description: C3 extension parser for C programming language
 * Author: Askar Azhibaev
 * Date: June 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

FUNCTION_INLINE int FUNC(string_constant)(T *p,
		unsigned int flags)
{
	int is_set = 0;
	unsigned char c = 0;
	int i = 0;
	chars *s = NULL;
	size_t pos = 0;

	if (p)
	{
		s = p->s;
		if (chars_check_read(s))
		{
			pos = chars_get_mark(s);
			c = chars_char_read(s);
			if (PARSE_C3_ALPHA_L)
			{
				is_set++;
				c = chars_char_read_next(s);
			}
			if (PARSE_C3_ALPHA_DOUBLE_QUOTE)
			{
				is_set++;
				c = chars_char_read_next(s);
				while (c)
				{
					if (PARSE_C3_ALPHA_DOUBLE_QUOTE)
					{
						is_set++;
						c = chars_char_read_next(s);
						break;
					}
					else if (PARSE_C3_ALPHA_BACKSLASH)
					{
						is_set++;
						c = chars_char_read_next(s);
						/* escape */
						if (PARSE_C3_ALPHA_ESCAPE)
						{
							is_set++;
							c = chars_char_read_next(s);
						}
						else if (PARSE_C3_DIGIT_OCTAL)
						{
							is_set++;
							c = chars_char_read_next(s);
							for (i = 1; i < 3; i++)
							{
								if (PARSE_C3_DIGIT_OCTAL)
								{
									is_set++;
									c = chars_char_read_next(s);
								}
								else
								{
									break;
								}
							}
						}
						else if (PARSE_C3_ALPHA_X)
						{
							is_set++;
							c = chars_char_read_next(s);
							while (PARSE_C3_DIGIT || PARSE_C3_ALPHA_HEX)
							{
								is_set++;
								c = chars_char_read_next(s);
							}
						}
						else
						{
							/* error */
							break;
						}
					}
					else if (PARSE_C3_ESCAPE_LF || PARSE_C3_ESCAPE_HT || PARSE_C3_ESCAPE_VT || PARSE_C3_ESCAPE_BS || PARSE_C3_ESCAPE_CR || PARSE_C3_ESCAPE_FF || PARSE_C3_ESCAPE_BEL)
					{
						/* error */
						break;
					}
					else
					{
						is_set++;
						c = chars_char_read_next(s);
					}
				}
			}
			if (is_set)
			{
				chars_read_pchar(p->s_string_constant, s->buf + pos, s->rpos - pos, 0);
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


