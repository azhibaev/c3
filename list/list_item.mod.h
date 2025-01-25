#ifndef LIST_ITEM_H
#define LIST_ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

#module list_item

#struct
void *item;
list_item *next;
list_item *prev;
list *child;

#init (void *s)
p->item = s;

#define MODULE_FUNC_DEF list_item_func_def.h

#include "mod.h"

FUNCTION_INLINE int FUNC(add_child)(T *p,
		list *child)
{
	int is_set = 0;

	if (p)
	{
		p->child = child;
		is_set = 1;
	}

	return is_set;
}

FUNCTION_INLINE list* FUNC(get_child)(T *p)
{
	list *list = NULL;

	if (p)
	{
		list = p->child;
	}

	return list;
}

#include "mod_undef.h"

#endif	/* LIST_ITEM_H */
