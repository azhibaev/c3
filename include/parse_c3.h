/*
 *	Warning !
 *	This file is generated automatically.
 *	DO NOT EDIT.
 *	Edit the "parse/parse_c3.mod.h" file.
 */
/*
 * File:  parse_c3.mod.h
 * Description: C3 extension parser for C programming language
 * Author: Askar Azhibaev
 * Date: June 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef PARSE_C3_H
#define PARSE_C3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

#include "chars.h"

#define MODULE_NAME parse_c3

#define MODULE_STRUCT parse_c3_struct.h
#define MODULE_INIT parse_c3_init.h
#define MODULE_INIT_VAR parse_c3_init_var.h
#define MODULE_FREE parse_c3_free.h
#include "module.h"

/* Flags */
#define PARSE_C3_FLAG_SKIP_LWS		(1 << 2)

#include STR(T_NAME(define_compare.h))	/* parse_c3_define_compare.h */
#include STR(T_NAME(whitespace.h))		/* parse_c3_whitespace.h */
#include STR(T_NAME(identifier.h))		/* parse_c3_identifier.h */
#include STR(T_NAME(constant.h))		/* parse_c3_constant.h */

#include "module_undef.h"

#endif	/* PARSE_C3_H */

