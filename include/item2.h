/*
 *	Warning !
 *	This file is generated automatically.
 *	DO NOT EDIT.
 *	Edit the "list/item2.mod.h" file.
 */
/*
 * File:  item.mod.h
 * Description: List functions
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

typedef struct list2 list2;

#ifndef MODULE_NAME
#define MODULE_NAME item2
#else
#define MODULE_NAME_SUFFIX item2
#endif

#define MODULE_STRUCT item2_struct.h
#define MODULE_INIT item2_init.h
#define MODULE_INIT_VAR item2_init_var.h
#include "mod.h"

FUNCTION_INLINE void* FUNC(get)(T *p)
{
	if (p)
	{
		return p->p;
	}

	return NULL;
}

FUNCTION_INLINE int FUNC(set)(T *p,
		void *v)
{
	int is_set = 0;

	if (p)
	{
		p->p = v;
		is_set++;
	}

	return is_set;
}

#include "mod_undef.h"

#endif	/* ITEM_H */
