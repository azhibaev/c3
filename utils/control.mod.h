/*
 * File:  control.mod.h
 * Description: functions
 * Author: Askar Azhibaev
 * Date: February 2024
 * Copyright (c) 2021-2024  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef CONTROL_H
#define CONTROL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

typedef struct list list;

#module control

#include "mod.h"

FUNCTION_INLINE int FUNC(wait_key)()
{
	return fgetc(stdin);

	return 0;
}

#include "mod_undef.h"

#endif	/* CONTROL_H */
