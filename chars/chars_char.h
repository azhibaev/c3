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

FUNCTION_INLINE unsigned char FUNC(char_read)(T *s)
{
	unsigned char c = 0;

	if (FUNC(check_read)(s))
	{
		c = s->buf[s->rpos];
	}

	return c;
}

FUNCTION_INLINE unsigned char FUNC(char_read_next)(T *s)
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

FUNCTION_INLINE unsigned char FUNC(read_next)(T *s)
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

FUNCTION_INLINE unsigned char FUNC(char_get)(T *s)
{
	unsigned char c = 0;

	if (FUNC(check_read)(s))
	{
		if (s->rpos > s->gpos)
		{
			s->gpos = s->rpos;
		}
		if (s->rpos < s->wpos &&
				s->rpos <= s->gpos &&
				s->gpos < s->wpos)
		{
			c = s->buf[s->gpos];
		}
	}

	return c;
}

FUNCTION_INLINE unsigned char FUNC(char_get_next)(T *s)
{
	unsigned char c = 0;

	if (FUNC(check_read)(s))
	{
		if (s->rpos < s->wpos)
		{
			if (s->rpos <= s->gpos &&
					s->gpos < s->wpos)
			{
				s->gpos++;
				c = s->buf[s->gpos];
			}
		}
	}

	return c;
}

FUNCTION_INLINE int FUNC(get_next)(T *s)
{
	int is_set = 0;

	if (FUNC(check_read)(s))
	{
		if (s->rpos < s->wpos)
		{
			if (s->rpos <= s->gpos &&
					s->gpos < s->wpos)
			{
				s->gpos++;
				is_set = 1;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE unsigned char FUNC(char_get_first)(T *s)
{
	unsigned char c = 0;

	if (FUNC(check_read)(s))
	{
		s->gpos = s->rpos;
		c = s->buf[s->gpos];
	}

	return c;
}

/* To set rpos equal of gpos call flush function
*/
FUNCTION_INLINE unsigned char FUNC(char_get_last)(T *s)
{
	unsigned char c = 0;

	if (FUNC(check_read)(s))
	{
		s->gpos = s->wpos - 1;
		c = s->buf[s->gpos];
	}

	return c;
}

FUNCTION_INLINE unsigned char FUNC(char_get_prev)(T *s)
{
	unsigned char c = 0;

	if (FUNC(check_read)(s))
	{
		if (s->rpos < s->wpos &&
				s->rpos < s->gpos &&
				s->gpos < s->wpos)
		{
			s->gpos--;
			c = s->buf[s->gpos];
		}
	}

	return c;
}

FUNCTION_INLINE int FUNC(get_prev)(T *s)
{
	int is_set = 0;

	if (FUNC(check_read)(s))
	{
		if (s->rpos < s->wpos &&
				s->rpos < s->gpos &&
				s->gpos < s->wpos)
		{
			s->gpos--;
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(set_get_pos)(T *s)
{
	int is_set = 0;

	if (FUNC(check_read)(s))
	{
		s->gpos = s->rpos;
		is_set++;
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(reset_get_pos)(T *s)
{
	int is_set = 0;

	if (FUNC(check_read)(s))
	{
		s->gpos = 0;
		is_set++;
	}

	return is_set;
}

