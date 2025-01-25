/*
 * File:  list.mod.h
 * Description: List functions
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

#include "item2.h"

#module list2

#struct
item2 *p;		/* selected item */
item2 *pf;		/* first item */
item2 *pl;		/* last item */
size_t count;

#init ()

#free
item2 *it;
item2 *next;
it = p->pf;
while (it)
{
	next = it->next;
	item2_free(it);
	it = next;
}

#include "mod.h"

FUNCTION_INLINE item2* FUNC(get)(T *p)
{
	if (p)
	{
		if (p->p)
		{
			return p->p;
		}
	}

	return NULL;
}

FUNCTION_INLINE int FUNC(set)(T *p,
		item2 *it)
{
	int is_set = 0;

	if (p)
	{
		if (it)
		{
			if (p->pl)
			{
				p->pl->next = it;
				it->prev = p->pl;
				p->pl = it;
				is_set++;
			}
			else if (!p->pf)
			{
				p->pf = it;
				p->pl = it;
				is_set++;
			}
			p->p = it;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(reset)(T *p)
{
	int is_set = 0;

	if (p)
	{
		if (p->pf)
		{
			p->p = p->pf;
			is_set++;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(clear)(T *p)
{
	int is_set = 0;
	item2 *it = NULL;
	item2 *next = NULL;

	if (p)
	{
		it = p->pf;
		while (it)
		{
			next = it->next;
			item2_free(it);
			it = next;
			is_set++;
		}
		p->p = NULL;
		p->pf = NULL;
		p->pl = NULL;
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(read)(T *p,
		void *v,
		int type)
{
	int is_set = 0;
	item2 *it = NULL;

	if (p)
	{
		it = item2_create(1);
		if (it)
		{
			if (item2_init(it, v, type))
			{
				if (FUNC(set)(p, it))
				{
					it = NULL;
					is_set++;
				}
			}
			if (it)
			{
				item2_free(it);
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(delete)(T *p,
		item2 *it)
{
	int is_set = 0;

	if (p)
	{
		if (it)
		{
			if (p->pl == it)
			{
				p->pl = it->prev;
				if (p->pf == it)
				{
					p->p = NULL;
					p->pf = NULL;
					p->pl = NULL;
				}
			}
			else if (p->pf == it)
			{
				p->pf = it->next;
			}
			else
			{
				if (it->next)
				{
					it->next->prev = it->prev;
				}
				if (it->prev)
				{
					it->prev->next = it->next;
				}
			}
			if (p->p == it)
			{
				if (it->next)
				{
					p->p = it->next;
				}
				else if (it->prev)
				{
					p->p = it->prev;
				}
				else
				{
					p->p = NULL;
				}
			}
			item2_free(it);
			is_set++;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(next)(T *p)
{
	int is_set = 0;

	if (p)
	{
		if (p->p)
		{
			p->p = p->p->next;
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
		if (p->p)
		{
			p->p = p->p->prev;
			is_set++;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(free_value)(T *p,
		int (*fn)(void*, int))
{
	int is_set = 0;
	item2 *it = NULL;

	if (p)
	{
		if (fn)
		{
			if (FUNC(reset)(p))
			{
				while ((it = FUNC(get)(p)))
				{
					is_set += fn(it->p, it->type);
					it->p = NULL;
					FUNC(next)(p);
				}
			}
		}
	}

	return is_set;
}

#include "mod_undef.h"

#endif	/* LIST_H */
