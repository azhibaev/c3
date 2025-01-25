/*
 * File:  module_create_init.h
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

FUNCTION_INLINE T* FUNC(create_init)(size_t count
#define MODULE_CREATE_CREATE if (!p) { p = FUNC(create)(count); }
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
	T *p = NULL;
	MODULE_CREATE_CREATE
	if (p)
	{
		FUNC(init)(p
#define PARAMETER(t,s) ,s
#define PARAMETER_POINTER(t,s) ,s
#define VAR(t,s)
#define VAR_POINTER(t,s)
#include MODULE_INIT_VAR_H
#undef VAR_POINTER
#undef VAR
#undef PARAMETER_POINTER
#undef PARAMETER
);
#undef MODULE_INIT_VAR_H
#else	/* MODULE_INIT_VAR */
)
{
	T *p = NULL;
	MODULE_CREATE_CREATE
	if (p)
	{
		FUNC(init)(p);
#endif	/* MODULE_INIT_VAR */
#else	/* MODULE_INIT */
)
{ 
	T *p = NULL;
	MODULE_CREATE_CREATE 
	if (p) {
		FUNC(init)(p);
#endif	/* MODULE_INIT */
#undef MODULE_CREATE_CREATE
	}

	return p;
}

