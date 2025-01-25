/*
 * File:  utopia_parse.h
 * Description: Utopia preprocessor of the 'mod.h' files
 * Author: Askar Azhibaev
 * Date:  December 2022
 * Copyright (c) 2022-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef UTOPIA_PARSE
#define UTOPIA_PARSE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"
#include "chars.h"
#include "parse.h"
#include "file.h"

// module
// utopia_parse
#define MODULE_NAME utopia_parse

// struct
#define MODULE_STRUCT utopia_parse_struct.h
#define MODULE_INIT utopia_parse_init.h
#define MODULE_INIT_VAR utopia_parse_init_var.h
#define MODULE_FUNC_DEF utopia_parse_func_def.h
#define UTOPIA_PARSE_SECTION_LIST "utopia_parse_section_list.h"
#define UTOPIA_MOD_SUFFIX ".mod.h"

#include "mod.h"

enum utopia_parse_section_name_e
{
#define ITEM(s) ARRAY_INDEX_E(s),
#define ITEM_2(s,i) ARRAY_INDEX_I_E(#s,i),
#include UTOPIA_PARSE_SECTION_LIST
#undef ITEM
#undef ITEM_2
};

struct array_index utopia_parse_section_name_a[] =
{
#define ITEM(s) ARRAY_INDEX(s),
#define ITEM_2(s,i) ARRAY_INDEX_I(#s,i),
#include UTOPIA_PARSE_SECTION_LIST
#undef ITEM
#undef ITEM_2
};

#include "section_module.h"
#include "section_struct.h"
#include "section_init.h"
#include "section_free.h"

FUNCTION_INLINE int FUNC(find_array)(chars *s,
		array_index *a,
		size_t a_size)
{
	int is_set = 0;
	size_t s_size = 0;
	size_t i = 0;

	if (chars_check(s))
	{
		s_size = s->wpos - s->rpos;
		for (i = 0; i < a_size; i++)
		{
			if (s_size >= a[i].size)
			{
				if (!strncmp(s->buf + s->rpos,
							a[i].s,
							a[i].size))
				{
					s->rpos += a[i].size;
					is_set = 1;
					break;
				}
			}
		}
	}

	return is_set ? a[i].index : -1;
}

FUNCTION_INLINE int FUNC(section_name)(chars *s)
{
	int is_set = 0;

	is_set = FUNC(find_array)(s,
			T_NAME(section_name_a),
			ARRAY_INDEX_SIZE(T_NAME(section_name_a)));

	return is_set;
}

FUNCTION_INLINE int FUNC(state)(T *p)
{
	int is_set = 0;

	if (p)
	{
		if (p->is_module)
		{
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(section)(T *p,
		chars *s)
{
	int is_set = 0;

	if (p)
	{
		if (parse_hash(s))
		{
			p->section_index = FUNC(section_name)(s);
			if (p->section_index >= 0)
			{
				is_set = 1;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(write_out)(T *p)
{
	int is_set = 0;

	if (p)
	{
		is_set = 1;
		if (!p->f_out->f)
		{
			if (p->is_module)
			{
				chars_reset(p->s);
				chars_copy(p->s,
						p->s_path_out,
						0,
						0);
				chars_read_pchar(p->s,
						"/",
						0,
						0);
/*
TODO: Add mod file name here
Sat Aug 10 12:57:21 UTC 2024
basename
Sun Aug 25 11:12:08 UTC 2024
DONE: basename is added
*/
				if (chars_check(p->s_basename))
				{
					chars_copy(p->s,
							p->s_basename,
							0,
							0);
				}
				else if (chars_check(p->s_module))
				{
					chars_copy(p->s,
							p->s_module,
							0,
							0);
				}
				chars_read_pchar(p->s,
						".h",
						0,
						0);
				if (file_init(p->f_out,
						p->s->buf,
						FILE_FLAG_WRITE))
				{
					chars_copy(p->s_out,
							p->s_in,
							0,
							0);
					chars_reset(p->f_out->s);
					chars_read_pchar(p->f_out->s,
"/*\n *\tWarning !\n *\tThis file is generated automatically.\n *\tDO NOT EDIT.\n *\tEdit the \"",
							0,
							0);
					chars_copy(p->f_out->s,
							p->f_in->file_name,
							0,
							0);
					chars_read_pchar(p->f_out->s,
"\" file.\n */\n",
							0,
							0);
					chars_copy(p->f_out->s,
							p->s_out,
							0,
							0);
					chars_reset(p->s_out);
				}
				else
				{
					return is_set;
				}
			}
			else
			{
				chars_copy(p->s_out,
						p->s_in,
						0,
						0);
				return is_set;
			}
		}
		else
		{
			chars_reset(p->f_out->s);
			chars_copy(p->f_out->s,
					p->s_in,
					0,
					0);
		}
		is_set = file_read_chars(p->f_out,
				p->f_out->s,
				0,
				0);
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(run)(T *p)
{
	int is_set = 0;
	size_t pos = 0;

	if (p)
	{
		while (file_write_chars(p->f_in,
					p->s_in,
					FILE_FLAG_WRITE_LINE))
		{
			pos = chars_get_mark(p->s_in);
			is_set = FUNC(section)(p,
					p->s_in);
			if (is_set)
			{
				switch (p->section_index)
				{
#define ITEM(s_i) case (s_i ## _index): \
					{ \
						is_set = FUNC(section_ ## s_i)(p); \
						break; \
					}
#define ITEM_2(s,i) ITEM(i)
#include UTOPIA_PARSE_SECTION_LIST
#undef ITEM
#undef ITEM_2
					default:
						{
							break;
						}
				}
				chars_reset(p->s_in);
			}
			else
			{
				chars_set_mark(p->s_in, pos);
				FUNC(write_out)(p);
				chars_reset(p->s_in);
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(open_file)(T *p,
		const char *file_name,
		unsigned int flags)
{
	int is_set = 0;

	if (p)
	{
		if (file_name)
		{
			chars_reset(p->s);
			chars_copy(p->s,
					p->s_path_out,
					0,
					0);
			chars_read_pchar(p->s,
					"/",
					0,
					0);
/* Add basename
Sat Aug 31 10:09:03 UTC 2024
*/
			if (chars_check(p->s_basename))
			{
				chars_copy(p->s,
						p->s_basename,
						0,
						0);
				chars_read_pchar(p->s,
						"_",
						0,
						0);
			}
			else if (chars_check(p->s_module))
			{
				chars_copy(p->s,
						p->s_module,
						0,
						0);
				chars_read_pchar(p->s,
						"_",
						0,
						0);
			}
			chars_read_pchar(p->s,
					file_name,
					0,
					0);
			file_init(p->f_section,
					p->s->buf,
					flags);
			is_set++;
		}
	}

	return is_set;
}

#undef UTOPIA_PARSE_SECTION_LIST

#include "mod_undef.h"

#endif	/* UTOPIA_PARSE */

