/*
 * File:  string_write.c
 * Description: Chars module test program
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

#include "chars.h"

int main(int argc, const char *argv[])
{
	chars *s = NULL;

	s = chars_create(1);
	if (chars_init(s, 10 KB))
	{
		printf("%lx %ld\n", (size_t)s->buf, s->size);
		chars_read_pchar(s, "Hello", 0, CHARS_FLAG_RESET);
		chars_print(s, CHARS_FLAG_PRINT_SPACE);
		chars_print(s, CHARS_FLAG_PRINT_NEWLINE | CHARS_FLAG_PRINT_HEX | CHARS_FLAG_PRINT_SPACE);
		printf("%s\n",
				chars_write_pchar(s, 0, 0, CHARS_FLAG_POINTER));
		chars_print_info(s, CHARS_FLAG_PRINT_NEWLINE);
		chars_read_pchar(s, ", World !", 0, 0);
		chars_print(s, CHARS_FLAG_PRINT_SPACE);
		chars_print(s, CHARS_FLAG_PRINT_NEWLINE | CHARS_FLAG_PRINT_HEX | CHARS_FLAG_PRINT_SPACE);
		printf("%s\n",
				chars_write_pchar(s, 0, 0, CHARS_FLAG_POINTER));
		chars_print_info(s, CHARS_FLAG_PRINT_NEWLINE);
		chars_read_pchar(s, "Test", 0, CHARS_FLAG_RESET);
		chars_print(s, CHARS_FLAG_PRINT_SPACE);
		chars_print(s, CHARS_FLAG_PRINT_NEWLINE | CHARS_FLAG_PRINT_HEX | CHARS_FLAG_PRINT_SPACE);
		printf("%s\n",
				chars_write_pchar(s, 0, 0, CHARS_FLAG_POINTER));
		chars_print_info(s, CHARS_FLAG_PRINT_NEWLINE);
	}

	return 0;
}
