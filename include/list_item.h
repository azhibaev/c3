/*
 *	Warning !
 *	This file is generated automatically.
 *	DO NOT EDIT.
 *	Edit the "list/list_item.mod.h" file.
 */
#ifndef LIST_ITEM_H
#define LIST_ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

#ifndef MODULE_NAME
#define MODULE_NAME list_item
#else
#define MODULE_NAME_SUFFIX list_item
#endif

#define MODULE_STRUCT list_item_struct.h
#define MODULE_INIT list_item_init.h
#define MODULE_INIT_VAR list_item_init_var.h
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
