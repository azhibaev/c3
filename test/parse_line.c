/*
 * File:  parse_line.c
 * Description: C3 extension parser test
 * Author: Askar Azhibaev
 * Date:  June 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse_c3.h"

int main(int argc, const char *argv[])
{
	parse_c3 *p3 = NULL;

	p3 = parse_c3_create(1);
	parse_c3_init(p3, "s = \"Hello!\"");

	if (parse_c3_identifier(p3, PARSE_C3_FLAG_SKIP_LWS))
	{
		chars_print(p3->s_identifier, CHARS_FLAG_PRINT_NEWLINE);
	}
	chars_next_char(p3->s);
	chars_next_char(p3->s);
	if (parse_c3_string_constant(p3, PARSE_C3_FLAG_SKIP_LWS))
	{
		chars_print(p3->s_string_constant, CHARS_FLAG_PRINT_NEWLINE);
	}
	chars_print(p3->s, CHARS_FLAG_PRINT_NEWLINE);

	return 0;
}

