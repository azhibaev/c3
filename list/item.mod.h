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

typedef struct list list;

#module item

#struct
item *next;
item *prev;
list *l;
void *p;
int type;

#init (void *v, int type)
p->p = v;
p->type = type;
p->next = NULL;
p->prev = NULL;
p->l = NULL;
is_init = 1;

#include "module.h"

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

#include "module_undef.h"

#endif	/* ITEM_H */
