/*
 * File:  module_struct.h
 * Description: Module framework
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifdef MODULE_STRUCT
typedef struct T T;
struct T
{
	#ifndef MODULE_STRUCT_H
	#define MODULE_STRUCT_H STR(T_NAME(struct.h))
	#endif	/* MODULE_STRUCT_H */
	#define FLAG(s) unsigned int is_ ## s:1;
	#define FLAGS(flag) \
	union \
	{ \
		unsigned int flags; \
		struct \
		{ \
			flag \
		}; \
	};
	#include "module_struct_def.h"
	#undef FLAGS
	#undef FLAG
	#undef MODULE_STRUCT_H
};
#endif	/* MODULE_STRUCT */
