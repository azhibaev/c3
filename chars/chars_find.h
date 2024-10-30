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
			c = FUNC(get_char)(p);
			while (c)
			{
				if (c == '\r')
				{
					is_set++;
					c = FUNC(get_next_char)(p);
					if (c == '\n')
					{
						is_set++;
						c = FUNC(get_next_char)(p);
					}
					break;
				}
				else if (c == '\n')
				{
					is_set++;
					c = FUNC(get_next_char)(p);
					break;
				}
				c = FUNC(get_next_char)(p);
			}
		}
	}

	return is_set;
}

