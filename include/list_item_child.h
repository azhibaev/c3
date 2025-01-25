/*
 *	Warning !
 *	This file is generated automatically.
 *	DO NOT EDIT.
 *	Edit the "list/list_item_child.mod.h" file.
 */
#ifndef LIST_ITEM_CHILD_H
#define LIST_ITEM_CHILD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

#include "list_item.h"
#include "list.h"

#ifndef MODULE_NAME
#define MODULE_NAME list_item_child
#else
#define MODULE_NAME_SUFFIX list_item_child
#endif

#define MODULE_STRUCT list_item_child_struct.h
#define MODULE_INIT list_item_child_init.h
#define MODULE_INIT_VAR list_item_child_init_var.h
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
