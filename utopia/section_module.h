/*
 * File:  section_module.h
 * Description: Utopia preprocessor of the 'mod.h' files
 * Author: Askar Azhibaev
 * Date:  December 2022
 * Copyright (c) 2022-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef SECTION_MODULE_H
#define SECTION_MODULE_H

FUNCTION_INLINE int FUNC(section_module)(T *p)
{
	int is_set = 0;
	size_t pos = 0;
	size_t size = 0;

	if (p)
	{
		if (p->f_in)
		{
			if (chars_check(p->s_in))
			{
				if (parse_lws(p->s_in))
				{
				}
				chars_reset(p->s_module);
				pos = chars_get_mark(p->s_in);
				if (parse_identifier(p->s_in))
				{
					size = chars_get_mark(p->s_in) - pos;
					if (size)
					{
						chars_set_mark(p->s_in, pos);
						chars_copy(p->s_module,
								p->s_in,
								size,
								0);
						p->is_module = 1;
						chars_reset(p->s_in);
						chars_read_pchar(p->s_in,
								"#ifndef MODULE_NAME\n\
#define MODULE_NAME ",
								0,
								0);
						chars_copy(p->s_in,
								p->s_module,
								0,
								0);
						chars_read_pchar(p->s_in,
								"\n\
#else\n\
#define MODULE_NAME_SUFFIX ",
								0,
								0);
						chars_copy(p->s_in,
								p->s_module,
								0,
								0);
						chars_read_pchar(p->s_in,
								"\n#endif\n",
								0,
								0);
						is_set = FUNC(write_out)(p);
					}
				}
			}
		}
	}

	return is_set;
}

#endif	/* SECTION_MODULE_H */

