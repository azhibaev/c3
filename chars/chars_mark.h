/*
 * File:  chars_mark.h
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
Returns the reading position
*/
FUNCTION_INLINE size_t FUNC(get_mark)(T *p)
{
	int is_set = 0;

	if (p)
	{
		return p->rpos;
	}

	return is_set;
}

/*
Sets the reading position
*/
FUNCTION_INLINE int FUNC(set_mark)(T *p,
		size_t read_mark)
{
	int is_set = 0;

	if (FUNC(check)(p))
	{
		if (read_mark < p->wpos)
		{
			p->rpos = read_mark;
			is_set = 1;
		}
	}

	return is_set;
}

/*
Returns the tmp reading position
*/
FUNCTION_INLINE size_t FUNC(get_mark_gpos)(T *p)
{
	int is_set = 0;

	if (p)
	{
		return p->gpos;
	}

	return is_set;
}

/*
Sets the tmp reading position
*/
FUNCTION_INLINE int FUNC(set_mark_gpos)(T *p,
		size_t read_mark)
{
	int is_set = 0;

	if (FUNC(check)(p))
	{
		if (read_mark < p->wpos &&
				p->rpos <= read_mark)
		{
			p->gpos = read_mark;
			is_set = 1;
		}
	}

	return is_set;
}

