#ifndef LIST_ITEM_CHILD_H
#define LIST_ITEM_CHILD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

#include "list_item.h"
#include "list.h"

#module list_item_child

#struct
list_item *item;
list *parent;
list *child;

#init (void *s)
p->item = s;

#include "mod.h"

FUNCTION_INLINE int FUNC(add)(T *p)
{
	int is_set = 0;

	if (p)
	{
	}

	return is_set;
}

#include "mod_undef.h"

#endif	/* LIST_ITEM_CHILD_H */
