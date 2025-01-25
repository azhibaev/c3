/*
 * File:  module_free.h
 * Description: Module framework
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FUNCTION_INLINE int FUNC(free)(T *p
#ifdef MODULE_FREE
#ifdef MODULE_FREE_VAR
#ifndef MODULE_FREE_VAR_H
#define MODULE_FREE_VAR_H STR(T_NAME(free_var.h))
#endif	/* MODULE_FREE_VAR_H */
#define PARAMETER(t,s) ,t s
#define VAR(t,s)
#include MODULE_FREE_VAR_H
#undef VAR
#undef PARAMETER
)
{
#define PARAMETER(t,s)
#define VAR(t,s) t s;
#include MODULE_FREE_VAR_H
#undef VAR
#undef PARAMETER
#undef MODULE_FREE_VAR_H
#else	/* MODULE_FREE_VAR */
)
{
#endif	/* MODULE_FREE_VAR */
	int is_free = 0;

	if (p)
	{
		#ifndef MODULE_FREE_H
		#define MODULE_FREE_H STR(T_NAME(free.h))
		#endif	/* MODULE_FREE_H */
		#include MODULE_FREE_H
		#undef MODULE_FREE_H
#else	/* MODULE_FREE */
)
{ 
	int is_free = 0;

	if (p) {
#endif	/* MODULE_FREE */
		#ifdef MODULE_STRUCT
		#define MODULE_STRUCT_H STR(T_NAME(struct.h))
		#include "mod_free_def.h"
		#undef MODULE_STRUCT_H
		#endif	/* MODULE_STRUCT */
		free(p);
        is_free = 1;
	}

	return is_free;
}

