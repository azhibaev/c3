#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

typedef struct list list;
#include "list_item.h"

#module list

#struct
list_item *begin;
list_item *read_pos;
list_item *end;
list_item *parent;
size_t size;

#init (list_item *parent)
p->parent = parent;

#include "mod.h"

FUNCTION_INLINE int FUNC(add_after)(T *p,
		list_item *pos,
		list_item *item)
{
	int is_set = 0;
	list_item *next = NULL;

	if (p)
	{
		if (pos &&
				item)
		{
			next = pos->next;
			pos->next = item;
			item->prev = pos;
			item->next = next;
			if (next)
			{
				next->prev = item;
			}
			p->size++;
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(add_before)(T *p,
		list_item *pos,
		list_item *item)
{
	int is_set = 0;
	list_item *prev = NULL;

	if (p)
	{
		if (pos &&
				item)
		{
			prev = pos->prev;
			pos->prev = item;
			item->next = pos;
			item->prev = prev;
			if (prev)
			{
				prev->next = item;
			}
			p->size++;
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(add_begin)(T *p,
		list_item *item)
{
	int is_set = 0;
	list_item *pos = NULL;

	if (p)
	{
		if (item)
		{
			if (!p->begin)
			{
				p->begin = item;
				p->end = item;
				item->next = NULL;
				item->prev = NULL;
				p->size++;
				is_set = 1;
			}
			else
			{
				pos = p->begin;
				item->next = pos;
				item->prev = NULL;
				pos->prev = item;
				p->size++;
				is_set = 1;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(add_end)(T *p,
		list_item *item)
{
	int is_set = 0;

	if (p)
	{
		if (item)
		{
			if (!p->begin)
			{
				if (FUNC(add_begin)(p,
							item))
				{
					is_set = 1;
				}
			}
			else if (FUNC(add_after)(p,
						p->end,
						item))
			{
				p->end = p->end->next;
				is_set = 1;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(add)(T *p,
		void *s)
{
	int is_set = 0;
	list_item *item = NULL;

	if (p)
	{
		item = list_item_create_init(1,
				s);
		if (item)
		{
			is_set = FUNC(add_end)(p,
					item);
			if (!is_set)
			{
				list_item_free(item);
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(begin)(T *p)
{
	int is_set = 0;

	if (p)
	{
		p->read_pos = p->begin;
		if (p->read_pos)
		{
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(next)(T *p)
{
	int is_set = 0;

	if (p)
	{
		if (p->read_pos)
		{
			p->read_pos = p->read_pos->next;
			if (p->read_pos)
			{
				is_set = 1;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(prev)(T *p)
{
	int is_set = 0;

	if (p)
	{
		if (p->read_pos)
		{
			p->read_pos = p->read_pos->prev;
			if (p->read_pos)
			{
				is_set = 1;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(end)(T *p)
{
	int is_set = 0;

	if (p)
	{
		p->read_pos = p->end;
		if (p->read_pos)
		{
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE list_item* FUNC(get_item)(T *p)
{
	list_item *item = NULL;

	if (p)
	{
		if (p->read_pos)
		{
			item = p->read_pos;
		}
	}

	return item;
}

FUNCTION_INLINE list_item* FUNC(get_next_item)(T *p)
{
	list_item *item = NULL;

	if (p)
	{
		if (FUNC(next)(p))
		{
			item = FUNC(get_item)(p);
		}
	}

	return item;
}

FUNCTION_INLINE int FUNC(set_item)(T *p,
		list_item *item)
{
	int is_set = 0;

	if (p)
	{
		p->read_pos = item;
		if (p->read_pos)
		{
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(remove)(T *p)
{
	int is_set = 0;
	list_item *next = NULL;
	list_item *prev = NULL;

	if (p)
	{
		if (p->read_pos)
		{
			next = p->read_pos->next;
			prev = p->read_pos->prev;
			if (next)
			{
				next->prev = prev;
			}
			if (prev)
			{
				prev->next = next;
			}
			if (p->begin == p->read_pos)
			{
				p->begin = next;
			}
			if (p->end == p->read_pos)
			{
				p->end = prev;
			}
			list_item_free(p->read_pos);
			p->read_pos = next;
			if (p->size)
			{
				p->size--;
			}
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(remove_if)(T *p,
		list_item_cmp cmp_eq)
{
	int is_set = 0;
	list_item *i1 = NULL;
	list_item *i2 = NULL;

	if (p)
	{
		FUNC(begin)(p);
		for (i1 = FUNC(get_item)(p);
				i1;
				FUNC(set_item)(p,
					i1),
				i1 = FUNC(get_next_item)(p))
		{
			for (i2 = FUNC(get_next_item)(p);
					i2;
					i2 = FUNC(get_item)(p))
			{
				if (cmp_eq(i1, i2))
				{
					printf("remove\n");
					FUNC(remove)(p);
				}
				else
				{
					FUNC(next)(p);
				}
			}
		}
	}

	return is_set;
}

#include "mod_undef.h"

#endif	/* LIST_H */
