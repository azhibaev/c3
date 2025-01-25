#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "money.h"

int main(int argc, const char *argv[])
{
	money *p = NULL;
	const char *file_name = NULL;

	if (argc < 2)
	{
		printf("Usage: %s file_name\n", argv[0]);
		return 1;
	}

	file_name = argv[1];

	p = money_create(1);

	if (money_init(p))
	{
		if (money_read_file(p, file_name))
		{
		}
	}

	money_free(p);

	return 0;
}
