#ifndef LIST_CHILD_H
#define LIST_CHILD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

#include "list_item_child.h"

#module list_child

#struct
list_item_child *begin;
list_item_child *read_pos;
list_item_child *write_pos;
size_t size;

#init ()

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
			is_set = 1;
		}
	}

	return is_set;
}

#include "mod_undef.h"

#endif	/* LIST_CHILD_H */
