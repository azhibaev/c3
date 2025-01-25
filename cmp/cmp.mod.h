#ifndef MOD_H
#define MOD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

#include "file.h"
#include "chars.h"
#include "parse.h"

#module cmp

#struct
create chars* s1;
create chars* s2;
create file* f1;
create file* f2;

#init (const char* file_name1, const char* file_name2)
file_init(p->f1, file_name1, FILE_FLAG_READ);
file_init(p->f2, file_name2, FILE_FLAG_READ);

#include "mod.h"

/* Compare two files
   first token
   print diff strings
*/
FUNCTION_INLINE int FUNC(run)(T *p)
{
	int is_set = 0;
	int pos1 = 0;
	int pos2 = 0;

	if (p)
	{
		while (file_write_chars(p->f1,
					p->s1,
					FILE_FLAG_WRITE_LINE))
		{
		}
		while (file_write_chars(p->f2,
					p->s2,
					FILE_FLAG_WRITE_LINE))
		{
			pos1 = chars_get_mark(p->s2);
			if (parse_token(p->s2))
			{
				pos2 = p->s2->rpos;
				chars_set_mark(p->s2,
						pos1);
				if (!chars_find_pchar(p->s1,
							p->s2->buf + p->s2->rpos,
							pos2 - p->s1->rpos,
							0))
				{
					chars_print(p->s2,
							CHARS_FLAG_PRINT_NEWLINE | CHARS_FLAG_PRINT_ALL);
				}
			}
			chars_reset(p->s2);
		}
	}

	return is_set;
}

#include "mod_undef.h"

#endif	/* MOD_H */
