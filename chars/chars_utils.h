/*
 * File:  chars_utils.h
 * Description: Chars string functions
 * Author: Askar Azhibaev
 * Date: June 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

FUNCTION_INLINE size_t FUNC(get_mark)(T *p);
FUNCTION_INLINE int FUNC(set_mark)(T *p,
		size_t read_mark);
FUNCTION_INLINE int FUNC(read_pchar)(T *p,
	const char *s,
	size_t s_size,
	unsigned int flags);
FUNCTION_INLINE char* FUNC(write_pchar)(T *p,
		char *s,
		size_t s_size,
		unsigned int flags);
FUNCTION_INLINE size_t FUNC(find_crlf)(T *p);

/*
Checks that the pointer p has been created,
done initialization,
buffer p->buf created,
read position <= write position,
write position <= p->size
*/
FUNCTION_INLINE int FUNC(check)(T *p)
{
    int is_set = 0;

    if (p)
    {
        if (p->is_init &&
                p->buf &&
                p->rpos <= p->wpos &&
                p->wpos <= p->size)
        {
            is_set = 1;
        }
    }

    return is_set;
}

/*
Checks that the pointer p has been created,
done initialization,
buffer p->buf created,
read position < write position,
there is data to read,
write position <= p->size
*/
FUNCTION_INLINE int FUNC(check_read)(T *p)
{
    int is_set = 0;

    if (p)
    {
        if (p->is_init &&
                p->buf &&
                p->rpos < p->wpos &&
                p->wpos <= p->size)
        {
            is_set = 1;
        }
    }

    return is_set;
}

/*
Allocates a new buffer if there is not enough space
CHARS_FLAG_GROWTH_FACTOR - uses factor
*/
FUNCTION_INLINE int FUNC(realloc)(T *p,
		size_t size,
		unsigned int flags)
{
	int is_set = 0;
	char *buf = NULL;
	size_t s_size = 0;

	if (FUNC(check)(p))
	{
		if (CHARS_FLAG_GROWTH_FACTOR & flags)
		{
			s_size = p->size * p->factor;
			if (size < s_size)
			{
				size = s_size;
			}
		}
		if (size)
		{
			if (size > p->size)
			{
				buf = malloc(size * sizeof(char));
				if (buf)
				{
					if (p->buf)
					{
						memcpy(buf, p->buf, p->wpos);
						if (p->wpos < size)
						{
							buf[p->wpos] = 0;
						}
						if (p->is_alloc)
						{
							free(p->buf);
						}
					}
					p->buf = buf;
					p->size = size;
					p->is_alloc = 1;
				}
			}
		}
	}

	return is_set;
}

/*
Prints a line from the buffer
CHARS_FLAG_PRINT_NEWLINE - adds a new line
CHARS_FLAG_PRINT_HEX - character values
CHARS_FLAG_PRINT_ALL - prints from the beginning
CHARS_FLAG_PRINT_SPACE - prints spaces
*/
FUNCTION_INLINE int FUNC(print)(T *p,
		unsigned int flags)
{
	int is_set = 0;
	char *s = NULL;
	size_t i = 0;
	char *s_format = NULL;
	char c = 0;
	char s_utf8[10] = {0};

	if (FUNC(check)(p))
	{
		s = p->buf;
		if (!(CHARS_FLAG_PRINT_ALL & flags))
		{
			s += p->rpos;
		}
		if (CHARS_FLAG_PRINT_HEX & flags)
		{
			if (CHARS_FLAG_PRINT_SPACE & flags)
			{
				s_format = "%2x ";
			}
			else
			{
				s_format = "%2x";
			}
			for (i = 0; i < p->wpos && *s; i++)
			{
				printf(s_format, (unsigned char)*s++);
			}
		}
		else
		{
			for (i = 0; i < p->wpos && *s; i++)
			{
				c = *s++;
				if (!(c & 0x80))
				{
					if (c != '\r' && c != '\n' && c != '\t' &&
							(c < 0x20 || c == 0x7f))
					{
						s_utf8[0] = '.';
					}
					else
					{
						s_utf8[0] = c;
					}
					s_utf8[1] = 0;
				}
				else if ((c & 0xe0) == 0xc0)
				{
					if (i + 1 < p->wpos)
					{
						if ((*s & 0xc0) == 0x80)
						{
							s_utf8[0] = c;
							s_utf8[1] = *s++;
							s_utf8[2] = 0;
							i += 1;
						}
					}
				}
				else if ((c & 0xf0) == 0xe0)
				{
					if (i + 2 < p->wpos)
					{
						if ((*s & 0xc0) == 0x80)
						{
							s_utf8[0] = c;
							s_utf8[1] = *s++;
							s_utf8[2] = *s++;
							s_utf8[3] = 0;
							i += 2;
						}
					}
				}
				else if ((c & 0xf8) == 0xf0)
				{
					if (i + 3 < p->wpos)
					{
						if ((*s & 0xc0) == 0x80)
						{
							s_utf8[0] = c;
							s_utf8[1] = *s++;
							s_utf8[2] = *s++;
							s_utf8[3] = *s++;
							s_utf8[4] = 0;
							i += 3;
						}
					}
				}
				printf("%s", s_utf8);
			}
		}
		if (CHARS_FLAG_PRINT_SPACE & flags &&
				!(CHARS_FLAG_PRINT_HEX & flags))
		{
			putchar(' ');
		}
		if (CHARS_FLAG_PRINT_NEWLINE & flags)
		{
			putchar('\n');
		}
	}

	return is_set;
}

/*
Clears a string, resets read and write positions
*/
FUNCTION_INLINE int FUNC(reset)(T *p)
{
	int is_set = 0;

	if (p)
	{
		p->rpos = 0;
		p->gpos = 0;
		p->wpos = 0;
		is_set = 1;
	}

	return is_set;
}
/*
Returns the format string for printf by type
CHARS_FLAG_POINTER - format for pointer address
*/
FUNCTION_INLINE const char* FUNC(get_type_format)(int type,
		unsigned int flags)
{
	char *s_format = NULL;

	switch (type)
	{
		case T_PREFIX_NAME(info_type,int):
			s_format = "%d";
			break;
		case T_PREFIX_NAME(info_type,size_t):
			s_format = "%ld";
			break;
		case T_PREFIX_NAME(info_type,char):
			if (CHARS_FLAG_POINTER & flags)
			{
				s_format = "%lx";
			}
			else
			{
				s_format = "%d";
			}
			break;
		case T_PREFIX_NAME(info_type,float):
		case T_PREFIX_NAME(info_type,double):
			s_format = "%f";
			break;
		default:
			s_format = "%ld";
	}

	return s_format;
}

/*
Prints the values of a structure
CHARS_FLAG_PRINT_NEWLINE - transfer to a new line
*/
FUNCTION_INLINE int FUNC(print_info)(T *p,
unsigned int flags)
{
	int is_set = 0;

	if (p)
	{
#define VAR(t,s) \
		printf(#s "="); \
		printf(FUNC(get_type_format)(T_PREFIX_NAME(info_type, t), 0), p->s); \
		putchar(' ');
#define VAR_POINTER(t,s) \
		printf(#s "="); \
		printf(FUNC(get_type_format)(T_PREFIX_NAME(info_type, t), CHARS_FLAG_POINTER), p->s); \
		putchar(' ');
		#define FLAGS(s)
		#define FLAG(s)
#include STR(T_NAME(struct.h))
#undef FLAG
#undef FLAGS
#undef VAR_POINTER
#undef VAR
	if (CHARS_FLAG_PRINT_NEWLINE & flags)
	{
		putchar('\n');
	}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(copy)(T *p,
		chars *s,
		size_t s_size,
		unsigned int flags)
{
	int is_set = 0;
	size_t size = 0;

	if (p)
	{
		if (FUNC(check)(s))
		{
			size = s->wpos - s->rpos;
			if (s_size && s_size < size)
			{
				size = s_size;
			}
			if (size)
			{
				if (FUNC(read_pchar)(p, s->buf + s->rpos, size, flags))
				{
					if (CHARS_FLAG_ADVANCE_READ_POS & flags)
					{
						s->rpos += size;
					}
					is_set++;
				}
			}
		}
	}

	return is_set;
}

/*
Copies a string from s to p before CRLF
*/
FUNCTION_INLINE int FUNC(copy_line)(T *p,
		chars *s,
		unsigned int flags)
{
	int is_set = 0;
	size_t pos = 0;
	size_t size = 0;

	if (p)
	{
		pos = FUNC(get_mark)(s);
		if (FUNC(find_crlf)(s))
		{
			size = FUNC(get_mark)(s) - pos;
			if (size)
			{
				if (FUNC(read_pchar)(p, s->buf + pos, size, 0))
				{
					is_set++;
				}
			}
		}
		else
		{
			FUNC(set_mark)(s, pos);
		}
	}

	return is_set;
}

/*
Copy from previous position to read position
in case of parse
*/
FUNCTION_INLINE int FUNC(copy_from_pos)(T *p,
		chars *s,
		size_t pos,
		unsigned int flags)
{
	int is_set = 0;
	size_t size = 0;

	if (p)
	{
		if (FUNC(check)(s))
		{
			if (pos < s->rpos)
			{
				size = s->rpos - pos;
				if (FUNC(read_pchar)(p, s->buf + pos, size, flags))
				{
					is_set++;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(compact)(T *p)
{
	int is_set = 0;
	size_t size = 0;

	if (p)
	{
		if (FUNC(check)(p))
		{
			if (p->is_alloc)
			{
				if (p->rpos > 0)
				{
					size = p->wpos - p->rpos;
					if (size)
					{
						memmove(p->buf, p->buf + p->rpos, size);
					}
					p->wpos -= p->rpos;
					p->rpos = 0;
					is_set++;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(flush)(T *p)
{
	int is_set = 0;

	if (p)
	{
		if (FUNC(check_read)(p))
		{
			if (p->rpos < p->wpos &&
					p->rpos < p->gpos &&
					p->gpos < p->wpos)
			{
				p->rpos = p->gpos;
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(write_int)(T *p,
		int *i,
		size_t size,
		unsigned int flags)
{
	int is_set = 0;
	char s_int[64];

	if (p)
	{
		if (size &&
				size < 64)
		{
			if (FUNC(write_pchar)(p, s_int, size, 0))
			{
				*i = atoi(s_int);
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(write_float)(T *p,
		float *i,
		size_t size,
		unsigned int flags)
{
	int is_set = 0;
	char s_float[128];

	if (p)
	{
		if (size &&
				size < 128)
		{
			if (FUNC(write_pchar)(p, s_float, size, 0))
			{
				*i = (float) atof(s_float);
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(write_double)(T *p,
		double *i,
		size_t size,
		unsigned int flags)
{
	int is_set = 0;
	char s_double[256];

	if (p)
	{
		if (size &&
				size < 256)
		{
			if (FUNC(write_pchar)(p, s_double, size, 0))
			{
				*i = atof(s_double);
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(reset_write_new_line)(T *p)
{
	int is_set = 0;

	if (FUNC(check)(p))
	{
		if (p->buf[p->wpos] == '\n' &&
				p->wpos < p->size)
		{
			p->wpos++;
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE T* FUNC(reset_init)(T *p)
{
	if (p)
	{
		FUNC(reset)(p);
	}
	else
	{
		p = FUNC(create_init)(1,
				0);
	}

	return p;
}

