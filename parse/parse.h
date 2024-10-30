/*
 * File:  parse.h
 * Description: String parser
 * Author: Askar Azhibaev
 * Date: April 2022
 * Copyright (c) 2022-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"
#include "chars.h"
#include "array_index.h"

// module
// parse
#define MODULE_NAME parse

// struct
//#define MODULE_STRUCT parse_struct.h
//#define MODULE_INIT parse_init.h
//#define MODULE_INIT_VAR parse_init_var.h
//#define MODULE_FREE parse_free.h

#include "module.h"

#define OCTET (c >= 0 && c <= 255)
#define CHAR (c >= 0 && c <= 127)
#define UPALPHA (c >= 'A' && c <= 'Z')
#define LOALPHA (c >= 'a' && c <= 'z')
#define ALPHA (UPALPHA || LOALPHA)
#define DIGIT (c >= '0' && c <= '9')
#define CTL ((c >= 0 && c <= 31) || c == 127)
#define CR (c == '\r')
#define LF (c == '\n')
#define SP (c == ' ')
#define HT (c == '\t')
#define DQ_MARK (c == '"')
#define HEX (c >= 'A' && c <= 'F' || c >= 'a' && c <= 'f' || DIGIT)
#define SEPARATORS (c == '(' || c == ')' || c == '<' || c == '>' \
		|| c == ',' || c == ';' || c == ':' || c == '\\' \
		|| c == '"' || c == '/' || c == '[' || c == ']' \
		|| c == '?' || c == '=' || c == '{' || c == '}' \
		|| SP || HT)
#define UNDERLINE (c == '_')
#define OPERATOR (c == '!' || c == '\"' || c == '#' || c == '$' || c == '%' || c == '&' || c == '\'' || c == '*' || c == '+' || c == '-' || c == '/' || c == '<' || c == '=' || c == '>' || c == '@' || c == '\\' || c == '^' || c == '_' || c == '`' || c == '|' || c == '~')
#define DIGIT_0 (c == '0')
#define DIGIT_OCTAL (c >= '0' && c <= '7')
#define ALPHA_E (c == 'E' || c == 'e')
#define ALPHA_F (c == 'F' || c == 'f')
#define ALPHA_L (c == 'L' || c == 'l')
#define ALPHA_U (c == 'U' || c == 'u')
#define ALPHA_X (c == 'X' || c == 'x')
#define ALPHA_HEX ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
#define ALPHA_NL (c == 'n')
#define ALPHA_LF (c == 'n')
#define ALPHA_HT (c == 't')
#define ALPHA_VT (c == 'v')
#define ALPHA_BS (c == 'b')
#define ALPHA_CR (c == 'r')
#define ALPHA_FF (c == 'f')
#define ALPHA_BEL (c == 'a')
#define ALPHA_BACKSLASH (c == '\\')
#define ALPHA_QUESTION_MARK (c == '?')
#define ALPHA_SINGLE_QUOTE (c == '\'')
#define ALPHA_DOUBLE_QUOTE (c == '\"')
#define ESCAPE_NL (c == '\n')
#define ESCAPE_LF (c == '\n')
#define ESCAPE_HT (c == '\t')
#define ESCAPE_VT (c == '\v')
#define ESCAPE_BS (c == '\b')
#define ESCAPE_CR (c == '\r')
#define ESCAPE_FF (c == '\f')
#define ESCAPE_BEL (c == '\a')

#define ESCAPE_BACKSLASH (c == '\\')
#define ESCAPE_QUESTION_MARK (c == '\?')
#define ESCAPE_SINGLE_QUOTE (c == '\'')
#define ESCAPE_DOUBLE_QUOTE (c == '\"')
#define ALPHA_ESCAPE (ALPHA_NL || ALPHA_LF || ALPHA_HT || ALPHA_VT || ALPHA_BS || ALPHA_CR || ALPHA_FF || ALPHA_BEL || ALPHA_BACKSLASH || ALPHA_QUESTION_MARK || ALPHA_SINGLE_QUOTE || ALPHA_DOUBLE_QUOTE)
/*
enum parse_storage_class_specifier_e
{
	ARRAY_INDEX_E(auto),
	ARRAY_INDEX_E(register),
	ARRAY_INDEX_E(static),
	ARRAY_INDEX_E(extern),
	ARRAY_INDEX_E(typedef),
};

static array_index parse_storage_class_specifier_a[] =
{
	ARRAY_INDEX(auto),
	ARRAY_INDEX(register),
	ARRAY_INDEX(static),
	ARRAY_INDEX(extern),
	ARRAY_INDEX(typedef),
};

enum parse_type_specifier_e
{
	ARRAY_INDEX_E(void),
	ARRAY_INDEX_E(char),
	ARRAY_INDEX_E(short),
	ARRAY_INDEX_E(int),
	ARRAY_INDEX_E(long),
	ARRAY_INDEX_E(float),
	ARRAY_INDEX_E(double),
	ARRAY_INDEX_E(signed),
	ARRAY_INDEX_E(unsigned),
};

static array_index parse_type_specifier_a[] =
{
	ARRAY_INDEX(void),
	ARRAY_INDEX(char),
	ARRAY_INDEX(short),
	ARRAY_INDEX(int),
	ARRAY_INDEX(long),
	ARRAY_INDEX(float),
	ARRAY_INDEX(double),
	ARRAY_INDEX(signed),
	ARRAY_INDEX(unsigned),
};
*/

FUNCTION_INLINE int FUNC(integer_constant)(chars *s);
FUNCTION_INLINE int FUNC(character_constant)(chars *s);
FUNCTION_INLINE int FUNC(floating_constant)(chars *s);
FUNCTION_INLINE int FUNC(string_constant)(chars *s);

FUNCTION_INLINE unsigned char FUNC(get_char)(chars *s)
{
	unsigned char c = 0;

	if (chars_check(s))
	{
		c = s->buf[s->rpos];
	}

	return c;
}

FUNCTION_INLINE unsigned char FUNC(get_next_char)(chars *s)
{
	unsigned char c = 0;

	if (chars_check(s))
	{
		if (s->rpos < s->wpos)
		{
			s->rpos++;
			c = s->buf[s->rpos];
		}
	}

	return c;
}

FUNCTION_INLINE unsigned char FUNC(next_char)(chars *s)
{
	int is_set = 0;

	if (chars_check(s))
	{
		if (s->rpos < s->wpos)
		{
			s->rpos++;
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(crlf)(chars *s)
{
	int is_set = 0;
	unsigned char c = 0;

	c = FUNC(get_char)(s);
	if (CR)
	{
		c = FUNC(get_next_char)(s);
		if (LF)
		{
			c = FUNC(get_next_char)(s);
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(crlf_any)(chars *s)
{
	int is_set = 0;
	unsigned char c = 0;

	c = FUNC(get_char)(s);
	if (CR)
	{
		c = FUNC(get_next_char)(s);
		if (LF)
		{
			c = FUNC(get_next_char)(s);
			is_set = 1;
		}
	}
	else if (LF)
	{
		c = FUNC(get_next_char)(s);
		is_set = 1;
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(lws)(chars *s)
{
	int is_set = 0;
	unsigned char c = 0;

	if (FUNC(crlf)(s))
	{
	}

	c = FUNC(get_char)(s);
	while (SP || HT)
	{
		is_set++;
		c = FUNC(get_next_char)(s);
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(ch)(chars *s,
		char ch)
{
	int is_set = 0;
	unsigned char c = 0;

	c = FUNC(get_char)(s);
	if (c == ch)
	{
		FUNC(next_char)(s);
		is_set = 1;
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(asterisk)(chars *s)
{
	return FUNC(ch)(s,
			'*');
}

FUNCTION_INLINE int FUNC(hash)(chars *s)
{
	return FUNC(ch)(s,
			'#');
}

FUNCTION_INLINE int FUNC(comment)(chars *s)
{
	int is_set = 0;
	unsigned char c = 0;

	if (chars_check(s))
	{
		c = FUNC(get_char)(s);
		if (c == '/')
		{
			if (FUNC(next_char)(s))
			{
				c = FUNC(get_char)(s);
				if (c == '/')
				{
					is_set = 1;
					if (FUNC(next_char)(s))
					{
					}
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(token)(chars *s)
{
	int is_set = 0;
	unsigned char c = 0;

	if (chars_check(s))
	{
		c = FUNC(get_char)(s);
		while (CHAR)
		{
			if (CTL || SEPARATORS)
			{
				break;
			}
			is_set++;
			if (FUNC(next_char)(s))
			{
				c = FUNC(get_char)(s);
			}
			else
			{
				break;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(identifier)(chars *s)
{
	int is_set = 0;
	unsigned char c = 0;

	if (chars_check(s))
	{
		c = FUNC(get_char)(s);
		if (ALPHA || UNDERLINE)
		{
			if (ALPHA)
			{
				is_set++;
			}
			while (FUNC(next_char)(s))
			{
				c = FUNC(get_char)(s);
				if (ALPHA || DIGIT || UNDERLINE)
				{
					is_set++;
				}
				else
				{
					break;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(operator)(chars *s)
{
	int is_set = 0;
	unsigned char c = 0;

	if (chars_check(s))
	{
		c = FUNC(get_char)(s);
		while (c)
		{
			if (OPERATOR)
			{
				is_set++;
			}
			else
			{
				break;
			}
			c = FUNC(get_next_char)(s);
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(literal)(chars *s)
{
	int is_set = 0;
	unsigned char c = 0;

	if (chars_check(s))
	{
		c = FUNC(get_char)(s);
		if (c == '"')
		{
			c = FUNC(get_next_char)(s);
			while (c)
			{
				if (c == '\\')
				{
					c = FUNC(get_next_char)(s);
					if (c == '"')
					{
					}
				}
				else if (c == '"')
				{
					c = FUNC(get_next_char)(s);
					break;
				}
				is_set++;
				c = FUNC(get_next_char)(s);
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(char)(chars *s,
		char *s_c)
{
	int is_set = 0;
	unsigned char c = 0;
	char *p_s = NULL;

	if (chars_check(s))
	{
		if (s_c)
		{
			c = FUNC(get_char)(s);
			for (p_s = s_c; *p_s; p_s++)
			{
				if (*p_s == c)
				{
					is_set++;
					c = FUNC(get_next_char)(s);
					if (!c)
					{
						is_set = 0;
						break;
					}
				}
				else
				{
					is_set = 0;
					break;
				}
			}
		}
	}

	return is_set;
}

/*
integer_constant()
	DIGIT ?
		is_set++
		next c ?
			DIGIT_0 ?
				get c
				ALPHA_X ?
					next c
					hex()
				:
					oct()
			:
				get c
				dec()
			ALPHA_L || ALPHA_U ?
				next c

dec()
	while (DIGIT)
		is_set++
		get_next c

hex()
	while (DIGIT || ALPHA_HEX)
		is_set++
		get_next c

oct()
	while (DIGIT_OCTAL)
		is_set++
		get_next c
*/

FUNCTION_INLINE int FUNC(integer_constant)(chars *s)
{
	int is_set = 0;
	unsigned char c = 0;
	size_t pos = 0;

	if (chars_check(s))
	{
		pos = chars_get_mark(s);
		c = FUNC(get_char)(s);
		if (DIGIT)
		{
			is_set++;
			if (FUNC(next_char)(s))
			{
				if (DIGIT_0)
				{
					c = FUNC(get_char)(s);
					if (ALPHA_X)
					{
						/* hex */
						c = FUNC(get_next_char)(s);
						while (DIGIT || ALPHA_HEX)
						{
							is_set++;
							c = FUNC(get_next_char)(s);
						}
					}
					else
					{
						/* octal */
						while (DIGIT_OCTAL)
						{
							is_set++;
							c = FUNC(get_next_char)(s);
						}
					}
				}
				else
				{
					/* dec */
					c = FUNC(get_char)(s);
					while (DIGIT)
					{
						is_set++;
						c = FUNC(get_next_char)(s);
					}
				}
				/* suffix */
				if (ALPHA_L || ALPHA_U)
				{
					is_set++;
					if (FUNC(next_char)(s))
					{
					}
				}
			}
		}
		if (!is_set)
		{
			chars_set_mark(s, pos);
		}
	}

	return is_set;
}

/*
character_constant()
L ?
	get_next c
' ?
	while get_next c
		\ ?
			escape()
		:
			is_set++

escape()
n t v b r f a \ \? ' " ?
	is_set++
o ?
	get_next c
	while DIGIT_OCTAL
		is_set++
		get_next c
: x ?
	get_next c
	while DIGIT_HEX
		is_set++
		get_next c

*/

FUNCTION_INLINE int FUNC(character_constant)(chars *s)
{
	int is_set = 0;
	unsigned char c = 0;
	int i = 0;

	if (chars_check(s))
	{
		c = FUNC(get_char)(s);
		if (ALPHA_L)
		{
			is_set++;
			c = FUNC(get_next_char)(s);
		}
		if (ALPHA_SINGLE_QUOTE)
		{
			is_set++;
			c = FUNC(get_next_char)(s);
			while (c)
			{
				if (ALPHA_SINGLE_QUOTE)
				{
					is_set++;
					c = FUNC(get_next_char)(s);
					break;
				}
				else if (ALPHA_BACKSLASH)
				{
					is_set++;
					c = FUNC(get_next_char)(s);
					/* escape */
					if (ALPHA_ESCAPE)
					{
						is_set++;
						c = FUNC(get_next_char)(s);
					}
					else if (DIGIT_OCTAL)
					{
						is_set++;
						c = FUNC(get_next_char)(s);
						for (i = 1; i < 3; i++)
						{
							if (DIGIT_OCTAL)
							{
								is_set++;
								c = FUNC(get_next_char)(s);
							}
							else
							{
								break;
							}
						}
					}
					else if (ALPHA_X)
					{
						is_set++;
						c = FUNC(get_next_char)(s);
						while (DIGIT || ALPHA_HEX)
						{
							is_set++;
							c = FUNC(get_next_char)(s);
						}
					}
					else
					{
						/* error */
						break;
					}
				}
				else if (ESCAPE_LF || ESCAPE_HT || ESCAPE_VT || ESCAPE_BS || ESCAPE_CR || ESCAPE_FF || ESCAPE_BEL)
				{
					/* error */
					break;
				}
				else
				{
					is_set++;
					c = FUNC(get_next_char)(s);
				}
			}
		}
	}

	return is_set;
}

/*
floating_constant()
	integer_part() ? is_integer_part
	decimal_point() ? is_decimal_point
	fraction_part() ? is_fraction_part
	exponent() ? is_exponent
	ALPHA_F ?
		is_set++
		get_next c
	is_integer_part || is_fraction_part ?
		is_decimal_point || is_exponent ?
			is_set++

integer_part()
	while DIGIT
		is_set++
		get_next c

decimal_point()
	. ?
		is_set++
		get_next c

fraction_part()
	while DIGIT
		is_set++
		get_next c

exponent()
	ALPHA_E ?
		is_set++
		get_next c
	+ || - ?
		is_set++
		get_next c
	while DIGIT
		is_set++
		get_next c

*/

FUNCTION_INLINE int FUNC(floating_constant)(chars *s)
{
	int is_set = 0;
	unsigned char c = 0;
	int is_integer_part = 0;
	int is_decimal_point = 0;
	int is_fraction_part = 0;
	int is_exponent = 0;
	int is_sign = 0;
	size_t pos = 0;

	if (chars_check(s))
	{
		pos = chars_get_mark(s);
		c = FUNC(get_char)(s);
		while (DIGIT)
		{
			is_integer_part++;
			c = FUNC(get_next_char)(s);
		}
		if (c == '.')
		{
			is_decimal_point++;
			c = FUNC(get_next_char)(s);
			while (DIGIT)
			{
				is_fraction_part++;
				c = FUNC(get_next_char)(s);
			}
		}
		if (is_integer_part || is_fraction_part)
		{
			if (ALPHA_E)
			{
				c = FUNC(get_next_char)(s);
				if (c == '+' || c == '-')
				{
					is_sign++;
					c = FUNC(get_next_char)(s);
				}
				while (DIGIT)
				{
					is_exponent++;
					c = FUNC(get_next_char)(s);
				}
				if (is_exponent)
				{
					is_exponent += is_sign + 1;
				}
			}
			if (is_decimal_point || is_exponent)
			{
				is_set += is_integer_part + is_fraction_part + is_decimal_point + is_exponent;
				if (ALPHA_F || ALPHA_L)
				{
					is_set++;
					c = FUNC(get_next_char)(s);
				}
			}
		}
		if (!is_set)
		{
			chars_set_mark(s, pos);
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(string_constant)(chars *s)
{
	int is_set = 0;
	unsigned char c = 0;
	int i = 0;

	if (chars_check(s))
	{
		c = FUNC(get_char)(s);
		if (ALPHA_L)
		{
			is_set++;
			c = FUNC(get_next_char)(s);
		}
		if (ALPHA_DOUBLE_QUOTE)
		{
			is_set++;
			c = FUNC(get_next_char)(s);
			while (c)
			{
				if (ALPHA_DOUBLE_QUOTE)
				{
					is_set++;
					c = FUNC(get_next_char)(s);
					break;
				}
				else if (ALPHA_BACKSLASH)
				{
					is_set++;
					c = FUNC(get_next_char)(s);
					/* escape */
					if (ALPHA_ESCAPE)
					{
						is_set++;
						c = FUNC(get_next_char)(s);
					}
					else if (DIGIT_OCTAL)
					{
						is_set++;
						c = FUNC(get_next_char)(s);
						for (i = 1; i < 3; i++)
						{
							if (DIGIT_OCTAL)
							{
								is_set++;
								c = FUNC(get_next_char)(s);
							}
							else
							{
								break;
							}
						}
					}
					else if (ALPHA_X)
					{
						is_set++;
						c = FUNC(get_next_char)(s);
						while (DIGIT || ALPHA_HEX)
						{
							is_set++;
							c = FUNC(get_next_char)(s);
						}
					}
					else
					{
						/* error */
						break;
					}
				}
				else if (ESCAPE_LF || ESCAPE_HT || ESCAPE_VT || ESCAPE_BS || ESCAPE_CR || ESCAPE_FF || ESCAPE_BEL)
				{
					/* error */
					break;
				}
				else
				{
					is_set++;
					c = FUNC(get_next_char)(s);
				}
			}
		}
	}

	return is_set;
}

#include "module_undef.h"

#endif	/* PARSE_H */

