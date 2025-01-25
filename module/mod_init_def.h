/*
 * File:  module_init_def.h
 * Description: Module framework
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#define VAR(t,s)
#define VAR_POINTER(t,s)
#define VAR_STRUCT(t,s)
#define VAR_STRUCT_POINTER(t,s)
#define VAR_STRUCT_POINTER_CREATE(t,s) VAR_POINTER_CREATE(t,s)
#define VAR_STRUCT_POINTER_INIT(t,s) VAR_POINTER_INIT(t,s)
#define VAR_STRUCT_POINTER_FREE(t,s) VAR_POINTER_FREE(t,s)
#define VAR_STRUCT_POINTER_NATIVE_CREATE(t,s) VAR_POINTER_NATIVE_CREATE(t,s)
#define VAR_STRUCT_POINTER_NATIVE_INIT(t,s) VAR_POINTER_NATIVE_INIT(t,s)
#define VAR_STRUCT_POINTER_NATIVE_FREE(t,s) VAR_POINTER_NATIVE_FREE(t,s)
#define VAR_POINTER_CREATE(t,s) \
	if (!p->s) p->s = t ## _create(1);
#define VAR_POINTER_INIT(t,s) \
	if (!p->s) p->s = t ## _create(1); \
	if (p->s) \
	{ \
		t ## _init_default(p->s); \
	}
#define VAR_POINTER_FREE(t,s)
#define VAR_POINTER_NATIVE_CREATE(t,s) \
	if (!p->s) p->s = (t*) malloc(sizeof(t));
#define VAR_POINTER_NATIVE_INIT(t,s) \
	if (!p->s) p->s = (t*) malloc(sizeof(t)); \
	if (p->s) \
	{ \
		memset(p->s, 0, sizeof(t)); \
	}
#define VAR_POINTER_NATIVE_FREE(t,s)
#define FLAGS(s)
#define FLAG(s)
#include MODULE_STRUCT_H
#undef FLAG
#undef FLAGS
#undef VAR_STRUCT_POINTER_NATIVE_CREATE
#undef VAR_STRUCT_POINTER_NATIVE_INIT
#undef VAR_STRUCT_POINTER_NATIVE_FREE
#undef VAR_STRUCT_POINTER_CREATE
#undef VAR_STRUCT_POINTER_INIT
#undef VAR_STRUCT_POINTER_FREE
#undef VAR_STRUCT_POINTER
#undef VAR_STRUCT
#undef VAR_POINTER_NATIVE_CREATE
#undef VAR_POINTER_NATIVE_INIT
#undef VAR_POINTER_NATIVE_FREE
#undef VAR_POINTER_CREATE
#undef VAR_POINTER_INIT
#undef VAR_POINTER_FREE
#undef VAR_POINTER
#undef VAR

