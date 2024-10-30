/*
 * File:  mod_to_h.c
 * Description: Preprocessor of the 'mod.h' files
 * Author: Askar Azhibaev
 * Date:  December 2022
 * Copyright (c) 2022-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "parse.h"
#include "utopia_parse.h"

int main(int argc, const char *argv[])
{
	utopia_parse *parse = NULL;

	if (argc < 3)
	{
		fprintf(stderr,
				"Usage: %s file_name output_dir\n",
				argv[0]);
		return 1;
	}

	parse = utopia_parse_create_init(1,
			(char*) argv[1],
			(char*) argv[2]);

	utopia_parse_run(parse);

	utopia_parse_free(parse);

	return 0;
}
