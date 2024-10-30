/*
 * File:  utopia_list.h
 * Description: Utopia preprocessor of the 'mod.h' files
 * Author: Askar Azhibaev
 * Date:  December 2022
 * Copyright (c) 2022-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef UTOPIA_LIST_H
#define UTOPIA_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// module
utopia_list

// struct
void *p;
void *start;
void *end;
size_t count;

void* next(T *p)
{
	if (p)
	{
		if (p->p)
		{
			if (p->p->next)
			{
				p->p = p->p->next;
				return p->p;
			}
		}
	}

	return NULL;
}

void* prev(T *p)
{
	if (p)
	{
		if (p->p)
		{
			if (p->p->prev)
			{
				p->p = p->p->prev;
				return p->p;
			}
		}
	}

	return NULL;
}

int print(T *p)
{
	int is_set = 0;

	if (p)
	{
		printf("count = %d\n",
				p->count);
		is_set = 1;
	}

	return is_set;
}


#endif	/* UTOPIA_LIST_H */
