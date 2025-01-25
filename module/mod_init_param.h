/*
 * File:  module_init_param.h
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

FUNCTION_INLINE int FUNC(init)(T *p
#ifdef MODULE_INIT
#ifdef MODULE_INIT_VAR
#ifndef MODULE_INIT_VAR_H
#define MODULE_INIT_VAR_H STR(T_NAME(init_var.h))
#endif	/* MODULE_INIT_VAR_H */
#define PARAMETER(t,s) ,t s
#define PARAMETER_POINTER(t,s) ,t *s
#define VAR(t,s)
#define VAR_POINTER(t,s)
#include MODULE_INIT_VAR_H
#undef VAR_POINTER
#undef VAR
#undef PARAMETER_POINTER
#undef PARAMETER
)
{
#define PARAMETER(t,s)
#define PARAMETER_POINTER(t,s)
#define VAR(t,s) t s;
#define VAR_POINTER(t,s) t *s;
#include MODULE_INIT_VAR_H
#undef VAR_POINTER
#undef VAR
#undef PARAMETER_POINTER
#undef PARAMETER
#undef MODULE_INIT_VAR_H
#else	/* MODULE_INIT_VAR */
)
{
#endif	/* MODULE_INIT_VAR */
	int is_init = 0;
	if (p)
	{
		#ifdef MODULE_STRUCT
		#define MODULE_STRUCT_H STR(T_NAME(struct.h))
		#include "mod_init_def.h"
		#undef MODULE_STRUCT_H
		#endif	/* MODULE_STRUCT */
		#ifndef MODULE_INIT_H
		#define MODULE_INIT_H STR(T_NAME(init.h))
		#endif	/* MODULE_INIT_H */
		#include MODULE_INIT_H
		#undef MODULE_INIT_H
#else	/* MODULE_INIT */
)
{ 
	int is_init = 0;
	if (p) {
		#ifdef MODULE_STRUCT
		#define MODULE_STRUCT_H STR(T_NAME(struct.h))
		#include "mod_init_def.h"
		#undef MODULE_STRUCT_H
		#endif	/* MODULE_STRUCT */
#endif	/* MODULE_INIT */
		is_init = 1;
	}

	return is_init;
}

