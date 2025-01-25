#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "for_operator.h"

int main(int argc, const char *argv[])
{
	for_operator *for1 = NULL;
	int re = 0;
	size_t count = 3;

	for1 = for_operator_create(count);
	for_operator_init(for1, 9, 0, -1);
	for_operator_init(for1 + 1, 0, 9, 1);
	for_operator_init(for1 + 2, 0, 9, 1);
	for_operator_parent_array(for1, count);

	while ((re = for_operator_run(for1)))
	{
		for_operator_print(for1, 0);
		printf(" (%d)\n", re);
	}

	return 0;
}
