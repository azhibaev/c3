#ifndef FOR_OPERATOR_H
#define FOR_OPERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

#define FOR_OPERATOR_FLAG_PRINT_NEWLINE (1 << 1)

#module for_operator

#struct
int i;
int start;
int end;
int step;
T *p;
up;
down;
start;

#init (int i_start, int i_end, int i_step)
p->start = i_start;
p->end = i_end;
p->step = i_step;
p->i = p->start;
p->is_start = 1;
p->p = NULL;
if (p->start < p->end &&
		p->step > 0)
{
	p->is_up = 1;
}
else if (p->start > p->end &&
		p->step < 0)
{
	p->is_down = 1;
}

#include "mod.h"

FUNCTION_INLINE int FUNC(run)(T *p);
FUNCTION_INLINE int FUNC(reset)(T *p);

FUNCTION_INLINE int FUNC(next)(T *p)
{
	int is_set = 0;

	if (p)
	{
		if (p->is_up)
		{
			p->i += p->step;
			if (p->i <= p->end)
			{
				is_set++;
			}
			else
			{
				if (p->p)
				{
					is_set += FUNC(next)(p->p);
					is_set *= 2;
					if (is_set)
					{
						p->i = p->start;
						is_set++;
					}
					else
					{
						p->is_up = 0;
					}
				}
				else
				{
					p->is_up = 0;
				}
			}
		}
		else if (p->is_down)
		{
			p->i += p->step;
			if (p->i >= p->end)
			{
				is_set++;
			}
			else
			{
				if (p->p)
				{
					is_set += FUNC(next)(p->p);
					is_set *= 2;
					if (is_set)
					{
						p->i = p->start;
						is_set++;
					}
					else
					{
						p->is_down = 0;
					}
				}
				else
				{
					p->is_down = 0;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(run)(T *p)
{
	int is_set = 0;

	if (p)
	{
		if (p->is_start)
		{
			p->is_start = 0;
			p->i = p->start;
			is_set++;
		}
		else
		{
			is_set = FUNC(next)(p);
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(reset)(T *p)
{
	int is_set = 0;

	if (p)
	{
		p->is_start = 1;
		p->i = p->start;
		is_set++;
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(parent)(T *p,
		T *parent)
{
	int is_set = 0;

	if (p)
	{
		if (parent)
		{
			p->p = parent;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(parent_array)(T *p,
		size_t count)
{
	int is_set = 0;
	size_t i = 0;

	if (p)
	{
		if (count > 0)
		{
			for (i = 0; i < count - 1; i++)
			{
				is_set += FUNC(parent)(p + i, p + i + 1);
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(print)(T *p,
		unsigned int flags)
{
	int is_set = 0;

	if (p)
	{
		printf("%d", p->i);
		is_set++;
		if (p->p)
		{
			printf(" : ");
			is_set += FUNC(print)(p->p, 0);
		}
		if (flags & FOR_OPERATOR_FLAG_PRINT_NEWLINE)
		{
			printf("\n");
		}
	}

	return is_set;
}

#include "mod_undef.h"

#endif	/* FOR_OPERATOR_H */
