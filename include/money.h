/*
 *	Warning !
 *	This file is generated automatically.
 *	DO NOT EDIT.
 *	Edit the "money/money.mod.h" file.
 */
#ifndef MONEY_H
#define MONEY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"
#include "chars.h"
#include "parse.h"
#include "file.h"
#include "list2.h"

#ifndef MODULE_NAME
#define MODULE_NAME money
#else
#define MODULE_NAME_SUFFIX money
#endif

#define MODULE_STRUCT money_struct.h
enum
{
	money_int,
	money_float,
	money_double,
};

int money_free_value(void *v,
		int type);

#define MODULE_INIT money_init.h
#define MODULE_FREE money_free.h
#include "mod.h"

FUNCTION_INLINE int FUNC(date)(T *p)
{
	int is_set = 0;
	size_t pos = 0;
	size_t size = 0;

	if (p)
	{
		pos = chars_get_mark(p->s);
		if (parse_integer_constant(p->s))
		{
			size = chars_get_mark(p->s) - pos;
			if (size)
			{
				chars_set_mark(p->s, pos);
				if (chars_write_int(p->s, &p->date, size, 0))
				{
					is_set++;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(debit)(T *p)
{
	int is_set = 0;
	size_t pos = 0;
	size_t size = 0;
	void *v = NULL;

	if (p)
	{
		if (parse_ch(p->s, '-'))
		{
			pos = chars_get_mark(p->s);
			if (parse_floating_constant(p->s))
			{
				size = chars_get_mark(p->s) - pos;
				if (size)
				{
					chars_set_mark(p->s, pos);
					v = malloc(sizeof(float));
					if (v)
					{
						if (chars_write_float(p->s, v, size, 0))
						{
							if (list2_read(p->debit, v, money_float))
							{
								v = NULL;
								is_set++;
							}
						}
						if (v)
						{
							free(v);
						}
					}
				}
			}
			else if (parse_integer_constant(p->s))
			{
				size = chars_get_mark(p->s) - pos;
				if (size)
				{
					chars_set_mark(p->s, pos);
					v = malloc(sizeof(int));
					if (v)
					{
						if (chars_write_int(p->s, v, size, 0))
						{
							if (list2_read(p->debit, v, money_int))
							{
								v = NULL;
								is_set++;
							}
						}
						if (v)
						{
							free(v);
						}
					}
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(print)(T *p)
{
	int is_set = 0;
	int i = 0;
	int month_days = 30;
	float f = 0;
	item2 *it = NULL;

	if (p)
	{
		printf("%d\n\n", p->date);
		p->total_day = 0;
		if (list2_reset(p->debit))
		{
			while ((it = list2_get(p->debit)))
			{
				if (it->p)
				{
					if (it->type == money_int)
					{
						i = *((int*)it->p);
						p->total_day += i;
						printf("-%d\n", i);
					}
					else if (it->type == money_float)
					{
						f = *((float*)it->p);
						p->total_day += f;
						printf("-%.2f\n", f);
					}
				}
				list2_next(p->debit);
			}
		}
		if (month_days < p->date)
		{
			month_days = p->date;
		}
		p->total_month += p->total_day;
		p->avg_date = p->total_month / p->date;
		p->avg_month = p->total_month / month_days;
		printf("=%.2f\n", p->total_day);
		printf("#%.2f\n", p->total_month);
		printf("/%.2f\n", p->avg_date);
		printf("*%.2f\n", p->avg_date * month_days);
		printf("%%%.2f\n", p->avg_month);
		printf("\n");
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(read_file)(T *p, const char *file_name)
{
	int is_set = 0;
	int is_read = 1;
	int is_date = 1;

	if (p)
	{
		if (file_init(p->f, file_name, FILE_FLAG_READ))
		{
			while (is_read)
			{
				is_set = 0;
				is_date = 0;
				while ((is_read = file_write_chars(p->f, p->s, FILE_FLAG_WRITE_LINE)))
				{
					if (FUNC(date)(p))
					{
						is_date++;
					}
					else if (parse_crlf_any(p->s))
					{
						if (is_set)
						{
							break;
						}
					}
					else if (FUNC(debit)(p))
					{
						is_set++;
					}
					chars_reset(p->s);
				}

				if (is_date)
				{
					FUNC(print)(p);
				}

				if (is_set)
				{
					list2_free_value(p->debit, money_free_value);
					list2_clear(p->debit);
				}
			}
			file_free(p->f);
		}
	}

	return is_set;
}

int FUNC(free_value)(void *v,
		int type)
{
	int is_set = 0;

	if (v)
	{
		if (type == money_int)
		{
			free((int*)v);
		}
		else if (type == money_float)
		{
			free((float*)v);
		}
		else if (type == money_double)
		{
			free((double*)v);
		}
		is_set++;
	}

	return is_set;
}

#include "mod_undef.h"

#endif	/* MONEY_H */
