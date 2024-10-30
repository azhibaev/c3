/*
 * File:  utopia.mod.h
 * Description: Utopia preprocessor of the 'mod.h' files
 * Author: Askar Azhibaev
 * Date:  December 2022
 * Copyright (c) 2022-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef UTOPIA_H
#define UTOPIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"
#include "chars.h"
#include "parse.h"
#include "file.h"


#module utopia

#struct
int a;
char c;
create chars *s;
init chars *s1;
free chars *s2;
FILE *f;
init
alloc

#init(int a, int b, char *s)
int c = 0;
s = chars_init(s, 0);
f = fopen(s, "r");

#free
if (f)
{
	fclose(f);
}


#endif	/* UTOPIA_H */

