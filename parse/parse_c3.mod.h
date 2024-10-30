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

#module parse_c3

#struct
init chars *s;
init chars *s_identifier;
init chars *s_string_constant;

#init(char *s)
chars_read_pchar(p->s, s, 0, 0);

#free

#include "module.h"

/* Flags */
#define PARSE_C3_FLAG_SKIP_LWS		(1 << 2)

#include STR(T_NAME(define_compare.h))	/* parse_c3_define_compare.h */
#include STR(T_NAME(whitespace.h))		/* parse_c3_whitespace.h */
#include STR(T_NAME(identifier.h))		/* parse_c3_identifier.h */
#include STR(T_NAME(constant.h))		/* parse_c3_constant.h */

#include "module_undef.h"

#endif	/* PARSE_C3_H */

