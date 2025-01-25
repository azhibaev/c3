/*
 *	Warning !
 *	This file is generated automatically.
 *	DO NOT EDIT.
 *	Edit the "utils/int_array.mod.h" file.
 */
#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

#include "chars.h"

#ifndef MODULE_NAME
#define MODULE_NAME int_array
#else
#define MODULE_NAME_SUFFIX int_array
#endif

#define MODULE_STRUCT int_array_struct.h
/* Defaults */

#define INT_ARRAY_DEFAULT_BASE 10

#define MODULE_INIT int_array_init.h
#define MODULE_INIT_VAR int_array_init_var.h
#define MODULE_FREE int_array_free.h
/* Defines */

#define INT_ARRAY_DIGIT (c >= '0' && c <= '9')
#define INT_ARRAY_DIGIT_HEX_L (c >= 'a' && c <= 'f')
#define INT_ARRAY_DIGIT_HEX_H (c >= 'A' && c <= 'F')
#define INT_ARRAY_DIGIT_HEX (INT_ARRAY_DIGIT_HEX_L || INT_ARRAY_DIGIT_HEX_H)

/* Flags */

#define INT_ARRAY_FLAG_IS_REVERSE (1 << 1)
#define INT_ARRAY_FLAG_IS_INDEX (1 << 2)
#define INT_ARRAY_FLAG_IS_NEWLINE (1 << 3)
#define INT_ARRAY_FLAG_IS_INDEX_NEWLINE (1 << 4)
#define INT_ARRAY_FLAG_IS_INDEX_SPACE (1 << 5)
#define INT_ARRAY_FLAG_IS_INDEX_TAB (1 << 6)
#define INT_ARRAY_FLAG_IS_SKIP_LEADING_ZERO (1 << 7)
#define INT_ARRAY_FLAG_TO_STRING (1 << 8)
#define INT_ARRAY_FLAG_TO_STRING_RESET (1 << 9)
#define INT_ARRAY_FLAG_IS_ADD_LEADING_ZERO (1 << 10)
#define INT_ARRAY_FLAG_IS_PADDING_ZERO (1 << 11)

/* Change flags */

#define INT_ARRAY_FLAG_ADD (1 << 0)
#define INT_ARRAY_FLAG_MUL (1 << 1)

#include "mod.h"

FUNCTION_INLINE int FUNC(get_base)(T *p,
		const char *s);
FUNCTION_INLINE int FUNC(get)(T *p,
		size_t i);
FUNCTION_INLINE int FUNC(set)(T *p,
		size_t i,
		int value);

FUNCTION_INLINE size_t FUNC(atoi)(T *p,
		const char *s, 
		size_t size,
		unsigned int flags)
{
	size_t n = 0;
	size_t i = 0;
	char c = 0;
	int is_leading_zero = 0;
	int is_padding_zero = 0;

	if (p)
	{
		if (s)
		{
			n = strlen(s);
			if (size && size < n)
			{
				n = size;
			}
			if (n)
			{
				if (INT_ARRAY_FLAG_IS_SKIP_LEADING_ZERO & flags)
				{
					for (i = 0; i < n; i++)
					{
						if (*s != '0')
						{
							break;
						}
						s++;
					}
					n -= i;
				}
				if (INT_ARRAY_FLAG_IS_ADD_LEADING_ZERO & flags)
				{
					is_leading_zero = 1;
				}
				if (INT_ARRAY_FLAG_IS_PADDING_ZERO & flags)
				{
					if ((n + is_leading_zero) % 2)
					{
						is_padding_zero = 1;
					}
				}
				if (FUNC(init)(p, n + is_leading_zero + is_padding_zero))
				{
				}
				if (p->a)
				{
					p->is_leading_zero = is_leading_zero;
					p->is_padding_zero = is_padding_zero;
					p->base = FUNC(get_base)(p, s);
					for (i = 0; i < n; i++)
					{
						c = s[i];
						if (INT_ARRAY_DIGIT)
						{
							FUNC(set)(p, n - i - 1 + is_padding_zero, c & 0xf);
						}
						else if (INT_ARRAY_DIGIT_HEX)
						{
							FUNC(set)(p, n - i - 1 + is_padding_zero, (c & 0xf) + 9);
						}
					}
					p->rpos = 0;
					p->wpos = i;
				}
				else
				{
					n = 0;
				}
			}
		}
	}

	return n;
}

FUNCTION_INLINE size_t FUNC(print_flags)(T *p,
		size_t size,
		unsigned int flags)
{
	size_t i = 0;
	char s[64];

	if (p)
	{
		if (p->a)
		{
			if (!p->s_format->is_init)
			{
				chars_init(p->s_format, 20);
			}
			chars_reset(p->s_format);
			s[0] = 0;
			if (INT_ARRAY_FLAG_IS_INDEX & flags)
			{
				chars_read_pchar(p->s_format, "m[%ld]=", 0, 0);
			}
			if (p->base == 16)
			{
				chars_read_pchar(p->s_format, "%x", 0, 0);
			}
			else
			{
				chars_read_pchar(p->s_format, "%d", 0, 0);
			}
			if (INT_ARRAY_FLAG_IS_INDEX_NEWLINE & flags)
			{
				chars_read_pchar(p->s_format, "\n", 0, 0);
			}
			if (INT_ARRAY_FLAG_IS_INDEX_SPACE & flags)
			{
				chars_read_pchar(p->s_format, " ", 0, 0);
			}
			if (INT_ARRAY_FLAG_IS_INDEX_TAB & flags)
			{
				chars_read_pchar(p->s_format, "\t", 0, 0);
			}
			if (!size ||
					p->size < size)
			{
				size = p->size;
			}
			if (INT_ARRAY_FLAG_TO_STRING & flags)
			{
				if (!p->s_print->is_init)
				{
					chars_init(p->s_print, 128);
				}
				if (INT_ARRAY_FLAG_TO_STRING_RESET & flags)
				{
					chars_reset(p->s_print);
				}
			}
			if (INT_ARRAY_FLAG_IS_REVERSE & flags)
			{
				for (i = 0; i < size; i++)
				{
					if (INT_ARRAY_FLAG_IS_SKIP_LEADING_ZERO & flags &&
							!p->a[size - i - 1])
					{
					}
					else
					{
						if (INT_ARRAY_FLAG_IS_INDEX & flags)
						{
							sprintf(s, p->s_format->buf, size - i - 1, p->a[size - i - 1]);
						}
						else
						{
							sprintf(s, p->s_format->buf, p->a[size - i - 1]);
						}
						if (INT_ARRAY_FLAG_TO_STRING & flags)
						{
							chars_read_pchar(p->s_print, s, 0, 0);
						}
						else
						{
							printf(s);
						}
					}
				}
			}
			else
			{
				for (i = 0; i < size; i++)
				{
					if (INT_ARRAY_FLAG_IS_INDEX & flags)
					{
						sprintf(s, p->s_format->buf, i, p->a[i]);
					}
					else
					{
						sprintf(s, p->s_format->buf, p->a[i]);
					}
					if (INT_ARRAY_FLAG_TO_STRING & flags)
					{
						chars_read_pchar(p->s_print, s, 0, 0);
					}
					else
					{
						printf(s);
					}
				}
			}
			if (INT_ARRAY_FLAG_IS_NEWLINE & flags)
			{
				putchar('\n');
			}
		}
	}

	return i;
}

FUNCTION_INLINE size_t FUNC(print)(T *p,
		unsigned int flags)
{
	size_t i = 0;

	i = FUNC(print_flags)(p,
			0,
			flags |
			INT_ARRAY_FLAG_IS_REVERSE |
			INT_ARRAY_FLAG_IS_NEWLINE);

	return i;
}

FUNCTION_INLINE size_t FUNC(print_index)(T *p,
		unsigned int flags)
{
	size_t i = 0;

	i = FUNC(print_flags)(p,
			0,
			flags |
			INT_ARRAY_FLAG_IS_REVERSE |
			INT_ARRAY_FLAG_IS_INDEX |
			INT_ARRAY_FLAG_IS_INDEX_SPACE |
			INT_ARRAY_FLAG_IS_NEWLINE);

	return i;
}
FUNCTION_INLINE size_t FUNC(print_size)(T *p,
		size_t size,
		unsigned int flags)
{
	size_t i = 0;

	i = FUNC(print_flags)(p,
			size,
			flags |
			INT_ARRAY_FLAG_IS_REVERSE |
			INT_ARRAY_FLAG_IS_NEWLINE);

	return i;
}

FUNCTION_INLINE int FUNC(get_base)(T *p,
		const char *s)
{
	char c = 0;
	size_t i = 0;
	size_t size = 0;
	size_t base = INT_ARRAY_DEFAULT_BASE;
	int is_hex = 0;

	if (s)
	{
		size = strlen(s);
		if (size)
		{
			for (i = 0; i < size; i++)
			{
				c = s[i];
				if (i == 0 && c == '0')
				{
					is_hex++;
				}
				else if (i == 1 && (c == 'x' || c == 'X'))
				{
					is_hex++;
				}
				if (is_hex == 2)
				{
					base = 16;
					break;
				}
				if (INT_ARRAY_DIGIT_HEX)
				{
					base = 16;
					break;
				}
			}
		}
	}

	return base;
}

FUNCTION_INLINE int FUNC(get)(T *p,
		size_t i)
{
	int is_set = 0;

	if (p)
	{
		if (p->a &&
				i < p->size)
		{
			return p->a[i];
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(set)(T *p,
		size_t i,
		int value)
{
	int is_set = 0;

	if (p)
	{
		if (p->a &&
				i < p->size)
		{
			p->a[i] = value;
			p->wpos = i + 1;
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(change)(T *p,
		size_t i,
		int value,
		unsigned int flags)
{
	int is_set = 0;

	if (p)
	{
		if (p->a &&
				i < p->size)
		{
			switch (flags)
			{
				case INT_ARRAY_FLAG_ADD:
					p->a[i] += value;
					is_set = 1;
					break;
				case INT_ARRAY_FLAG_MUL:
					p->a[i] *= value;
					is_set = 1;
					break;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(copy)(T *p,
		T *p_source,
		size_t size)
{
	int is_set = 0;
	size_t i = 0;

	if (p)
	{
		if (p_source)
		{
			if (p_source->a)
			{
				if (!size ||
						size > p_source->size)
				{
					size = p_source->size;
				}
				if (p->size < size)
				{
					FUNC(init)(p, size);
				}
				for (i = 0; i < size; i++)
				{
					p->a[i] = p_source->a[i];
				}
				p->rpos = p_source->rpos;
				p->wpos = p_source->wpos;
				p_source->n = i;
				is_set = 1;
			}
		}
	}

	return is_set;
}

/*
Перемножить m1 * m2
множители могут быть разного размера
результат получить в p
p можно увеличить, если не хватает места
*/
FUNCTION_INLINE int FUNC(mul)(T *p,
		T *m1,
		T *m2)
{
	int is_set = 0;
	size_t n_min = 0;
	size_t n_max = 0;
	size_t p_size = 0;
	int *m_min = NULL;
	int *m_max = NULL;
	size_t i_min = 0;
	size_t i_max = 0;
	size_t i = 0;
	size_t j = 0;
	char *s_format = NULL;

	if (p)
	{
		if (m1 &&
				m2)
		{
			if (m1->size < m2->size)
			{
				n_min = m1->size;
				n_max = m2->size;
				m_min = m1->a;
				m_max = m2->a;
			}
			else
			{
				n_min = m2->size;
				n_max = m1->size;
				m_min = m2->a;
				m_max = m1->a;
			}
			p_size = m1->size + m2->size;
			if (p->size < p_size)
			{
				if (int_array_init(p, p_size))
				{
				}
			}
			if (p->size >= p_size)
			{
				p->base = m1->base;
				i_min = 1;
				if (p->is_print_info)
				{
					if (p->base == 16)
					{
						s_format = "p_c[%ld] += %x * %x; p_c[%ld] = %x\n";
					}
					else
					{
						s_format = "p_c[%ld] += %d * %d; p_c[%ld] = %d\n";
					}
				}
				for (i_max = 0; i_max < n_max; i_max++)
				{
					p->a[i] = 0;
					for (j = 0; j < i_min; j++)
					{
						p->a[i] += m_min[j] * m_max[i_max - j];
						if (p->is_print_info)
						{
							printf(s_format, i, m_min[j], m_max[i_max - j], i, p->a[i]);
						}
					}
					if (i_min < n_min)
						i_min++;
					i++;
				}
				i_min = 1;
				i_max = n_max - 1;
				while (i < p_size)
				{
					p->a[i] = 0;
					for (j = i_min; j < n_min; j++)
					{
						p->a[i] += m_min[j] * m_max[i_max - j + i_min];
						if (p->is_print_info)
						{
							printf(s_format, i, m_min[j], m_max[i_max - j + i_min], i, p->a[i]);
						}
					}
					if (i_min < n_min)
						i_min++;
					i++;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE size_t FUNC(set_carry)(T *p,
		T *pc,
		T *c)
{
	size_t i = 0;
	int a = 0;
	char *s_format = NULL;

	if (p)
	{
		if (pc &&
				pc->size &&
				pc->base > 0)
		{
			if (int_array_init(p, pc->size))
			{
			}
			if (int_array_init(c, pc->size))
			{
			}
			if (p &&
					c)
			{
				p->base = pc->base;
				c->base = pc->base;
				a = 0;
				if (p->is_print_info)
				{
					if (pc->base == 16)
					{
						s_format = "p_c[%ld] = %x; p[%ld] = %x; carry = %x\n";
					}
					else
					{
						s_format = "p_c[%ld] = %d; p[%ld] = %d; carry = %d\n";
					}
				}
				for (i = 0; i < pc->size; i++)
				{
					a += pc->a[i];
					p->a[i] = a % pc->base;
					a /= pc->base;
					c->a[i] = a;
					if (p->is_print_info)
					{
						printf(s_format, i, pc->a[i], i, p->a[i], c->a[i]);
					}
				}
			}
		}
	}

	return i;
}

FUNCTION_INLINE int FUNC(check)(T *p)
{
	int is_set = 0;

	if (p)
	{
		if (p->rpos <= p->wpos &&
				p->wpos <= p->size)
		{
			is_set++;
			if (p->rpos < p->wpos)
			{
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(next)(T *p)
{
	int is_set = 0;

	if (p)
	{
		if (FUNC(check)(p) > 1)
		{
			p->rpos++;
			is_set++;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(prev)(T *p)
{
	int is_set = 0;

	if (p)
	{
		if (FUNC(check)(p) > 1)
		{
			if (p->rpos > 0)
			{
				p->rpos--;
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(get_next_i)(T *p)
{
	int i = 0;

	if (p)
	{
		if (FUNC(check)(p) > 1)
		{
			if (p->rpos + 1 < p->wpos)
			{
				p->rpos++;
				i = p->a[p->rpos];
			}
		}
	}

	return i;
}

FUNCTION_INLINE int FUNC(set_next_i)(T *p,
		int i)
{
	int is_set = 0;

	if (p)
	{
		if (FUNC(check)(p))
		{
			if (p->wpos < p->size)
			{
				p->a[p->wpos] = i;
				p->wpos++;
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(get_prev_i)(T *p)
{
	int i = 0;

	if (p)
	{
		if (FUNC(check)(p) > 1)
		{
			if (p->rpos > 0)
			{
				p->rpos--;
				i = p->a[p->rpos];
			}
		}
	}

	return i;
}

FUNCTION_INLINE int FUNC(set_prev_i)(T *p,
		int i)
{
	int is_set = 0;

	if (p)
	{
		if (FUNC(check)(p))
		{
			if (p->rpos > 0)
			{
				p->rpos--;
				p->a[p->rpos] = i;
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(get_i)(T *p)
{
	int i = 0;

	if (p)
	{
		if (FUNC(check)(p) > 1)
		{
			i = p->a[p->rpos];
		}
	}

	return i;
}

FUNCTION_INLINE int FUNC(set_i)(T *p,
		int i)
{
	int is_set = 0;

	if (p)
	{
		if (FUNC(check)(p))
		{
			if (p->wpos < p->size)
			{
				p->a[p->wpos] = i;
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(get_high_i)(T *p)
{
	int i = 0;

	if (p)
	{
		if (FUNC(check)(p))
		{
			if (p->wpos > 0)
			{
				p->rpos = p->wpos - 1;
				i = p->a[p->rpos];
			}
		}
	}

	return i;
}

FUNCTION_INLINE int FUNC(set_high_i)(T *p,
		int i)
{
	int is_set = 0;

	if (p)
	{
		if (FUNC(check)(p))
		{
			if (p->size > 0)
			{
				p->wpos = p->size - 1;
				p->a[p->wpos] = i;
				p->rpos = p->wpos;
				p->wpos++;
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(get_low_i)(T *p)
{
	int i = 0;

	if (p)
	{
		if (FUNC(check)(p) > 1)
		{
			p->rpos = 0;
			i = p->a[p->rpos];
		}
	}

	return i;
}

FUNCTION_INLINE int FUNC(set_low_i)(T *p,
		int i)
{
	int is_set = 0;

	if (p)
	{
		if (FUNC(check)(p))
		{
			p->rpos = 0;
			p->wpos = 0;
			p->a[p->wpos] = i;
			p->wpos++;
			is_set++;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(reset)(T *p)
{
	int is_set = 0;

	if (p)
	{
		if (FUNC(check)(p))
		{
			p->rpos = 0;
			p->wpos = 0;
			memset(p->a, 0, p->size * sizeof(int));
			is_set++;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(read_uint)(T *p,
		unsigned int m)
{
	int is_set = 0;
	unsigned int c = 0;

	if (p)
	{
		FUNC(reset)(p);
		while (m > 0)
		{
			c = m % p->base;
			FUNC(set_next_i)(p, c);
			m /= p->base;
		}
	}

	return is_set;
}

FUNCTION_INLINE unsigned int FUNC(write_uint)(T *p)
{
	unsigned int s = 0;
	int i = 0;
	int n = 0;

	if (p)
	{
		n = 1;
		for (i = 0; i < p->wpos; i++)
		{
			s += FUNC(get)(p, i) * n;
			n *= p->base;
		}
	}

	return s;
}

FUNCTION_INLINE int FUNC(get_carry_max)(T *p,
		size_t i,
		size_t size)
{
	int carry_max = 0;

	if (p)
	{
		if (!size ||
				size > p->size)
		{
			size = p->size;
		}
		if (size % 2)
		{
			size++;
		}
		if (i + 2 <= size / 2)
		{
			carry_max = (i + 2) * 9;
		}
		else if (i + 2 > size / 2)
		{
			carry_max = (size - i - 2) * 9;
			if (carry_max > 0)
			{
				carry_max--;
			}
		}
	}

	return carry_max;
}

/* Save size of array
other set to 0
*/
FUNCTION_INLINE int FUNC(trim)(T *p,
		size_t size)
{
	int is_set = 0;
	int i = 0;

	if (p)
	{
		if (p->a &&
				size < p->size)
		{
			for (i = size; i < p->size; i++)
			{
				p->a[i] = 0;
				is_set++;
			}
		}
	}

	return is_set;
}

#include "mod_undef.h"

#endif	/* INT_ARRAY_H */

