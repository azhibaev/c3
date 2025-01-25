/*
 * File:  chars_find.h
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
Find CRLF \r\n
*/
FUNCTION_INLINE size_t FUNC(find_crlf)(T *p)
{
	int is_set = 0;
	char c = 0;

	if (p)
	{
		if (FUNC(check)(p))
		{
			c = FUNC(char_read)(p);
			while (c)
			{
				if (c == '\r')
				{
					is_set++;
					c = FUNC(char_read_next)(p);
					if (c == '\n')
					{
						is_set++;
						c = FUNC(char_read_next)(p);
					}
					break;
				}
				else if (c == '\n')
				{
					is_set++;
					c = FUNC(char_read_next)(p);
					break;
				}
				c = FUNC(char_read_next)(p);
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE size_t FUNC(find_pchar_last)(T *p,
		char *s,
		size_t s_size,
		unsigned int flags)
{
	size_t is_set = 0;
	char c = 0;
	size_t s_pos = 0;

	if (p)
	{
		if (s)
		{
			if (!s_size)
			{
				s_size = strlen(s);
			}
			if (s_size)
			{
				if (FUNC(check)(p))
				{
					s_pos = s_size - 1;
					p->is_prefix = 0;
					p->is_suffix = 0;
					c = FUNC(char_get_last)(p);
					while (c)
					{
						if (c == s[s_pos])
						{
							is_set++;
							if (!s_pos)
							{
								p->fpos = p->gpos;
								if (p->wpos - p->gpos == s_size)
								{
									p->is_suffix = 1;
								}
								if (p->gpos == p->rpos)
								{
									p->is_prefix = 1;
								}
								break;
							}
							s_pos--;
						}
						else
						{
							if (is_set)
							{
								s_pos = s_size - 1;
								is_set = 0;
							}
						}
						c = FUNC(char_get_prev)(p);
					}
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE size_t FUNC(find_pchar)(T *p,
		char *s,
		size_t s_size,
		unsigned int flags)
{
	char c = 0;
	size_t s_pos = 0;

	if (p)
	{
		if (s)
		{
			if (flags & CHARS_FLAG_FIND_LAST)
			{
				return FUNC(find_pchar_last(p,
							s,
							s_size,
							flags));
			}
			if (!s_size)
			{
				s_size = strlen(s);
			}
			if (s_size)
			{
				if (FUNC(check)(p))
				{
					p->is_prefix = 0;
					p->is_suffix = 0;
					c = FUNC(char_get_first)(p);
					while (c)
					{
						if (c == s[s_pos])
						{
							if (!s_pos)
							{
								p->fpos = p->gpos;
							}
							s_pos++;
							if (s_pos == s_size)
							{
								if (p->gpos + 1 == p->wpos)
								{
									p->is_suffix = 1;
								}
								if (p->gpos == p->rpos)
								{
									p->is_prefix = 1;
								}
								break;
							}
						}
						else
						{
							if (s_pos)
							{
								s_pos = 0;
							}
						}
						c = FUNC(char_get_next)(p);
					}
				}
			}
		}
	}

	return s_pos;
}

/* Basename is remainder from directory and suffix of filename
1. suffix .mod.h
2. find last "/" or "\"
*/
FUNCTION_INLINE int FUNC(basename)(T *p,
		T *name,
		char *suffix,
		size_t suffix_size)
{
	int is_set = 0;
	size_t pos_suffix = 0;
	size_t pos_slash = 0;

	if (p)
	{
		if (FUNC(find_pchar)(p,
					suffix,
					suffix_size,
					CHARS_FLAG_FIND_LAST))
		{
			if (p->is_suffix)
			{
				pos_suffix = p->fpos;

/*
Sun Aug 25 11:20:05 UTC 2024
TODO: Add here windows dir delimiter "\"
*/
				if (FUNC(find_pchar)(p,
							"/",
							0,
							CHARS_FLAG_FIND_LAST))
				{
					pos_slash = p->fpos + 1;

					if (FUNC(read_pchar)(name,
								p->buf + pos_slash,
								pos_suffix - pos_slash,
								CHARS_FLAG_RESET))
					{
						is_set++;
					}
				}
			}
		}
	}

	return is_set;
}


