#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmp.h"

int main(int argc, const char *argv[])
{
	cmp *p = NULL;

	p = cmp_create(1);
	cmp_init(p, argv[1], argv[2]);

	cmp_run(p);

	cmp_free(p);

	return 0;
}
