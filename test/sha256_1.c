/*
 * File:  sha256_1.c
 * Description: SHA 256 module test program
 * Author: Askar Azhibaev
 * Date:  July 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "sha256.h"

int main(int argc, const char *argv[])
{
	sha256 *p = NULL;

	p = sha256_create(1);
	sha256_init(p);

	sha256_set_m(p, "hello world");

	sha256_set_w(p);
	sha256_compress(p);
	sha256_set_h(p);

	sha256_print(p);

	return 0;
}
