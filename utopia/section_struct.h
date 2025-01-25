/*
 * File:  section_struct.h
 * Description: Utopia preprocessor of the 'mod.h' files
 * Author: Askar Azhibaev
 * Date:  December 2022
 * Copyright (c) 2022-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef SECTION_STRUCT_H
#define SECTION_STRUCT_H

#define SECTION_STRUCT_FILE_NAME "struct.h"

FUNCTION_INLINE int FUNC(section_struct)(T *p)
{
	int is_set = 0;
	size_t pos = 0;
	int is_create = 0;
	int is_init = 0;
	int is_free = 0;
	int is_pointer = 0;
	int is_var_type = 0;
	size_t pos_var = 0;
	size_t pos_var_type = 0;

	if (p)
	{
		if (p->f_in)
		{
			chars_reset(p->s_struct);
			chars_reset(p->s_struct_flags);
			chars_reset(p->s_in);
			while (file_write_chars(p->f_in,
						p->s_in,
						FILE_FLAG_WRITE_LINE))
			{
				if (chars_check(p->s_in))
				{
					if (parse_lws(p->s_in))
					{
					}
					pos = chars_get_mark(p->s_in);
					// "free" ? ->
					if (parse_identifier(p->s_in))
					{
						if (!strncmp(p->s_in->buf + pos,
									"create",
									p->s_in->rpos - pos))
						{
							if (parse_char_read(p->s_in) == ';' ||
									p->s_in->rpos + 1 >= p->f_in->s->wpos)
							{
								is_var_type = 1;
							}
							else
							{
								is_create = 1;
								if (parse_lws(p->s_in))
								{
								}
								pos = chars_get_mark(p->s_in);
								if (parse_identifier(p->s_in))
								{
									is_var_type = 1;
								}
							}
						}
						else if (!strncmp(p->s_in->buf + pos,
									"init",
									p->s_in->rpos - pos))
						{
							if (parse_char_read(p->s_in) == ';' ||
									p->s_in->rpos + 1 >= p->f_in->s->wpos)
							{
								is_var_type = 1;
							}
							else
							{
								is_init = 1;
								if (parse_lws(p->s_in))
								{
								}
								pos = chars_get_mark(p->s_in);
								if (parse_identifier(p->s_in))
								{
									is_var_type = 1;
								}
							}
						}
						else if (!strncmp(p->s_in->buf + pos,
									"free",
									p->s_in->rpos - pos))
						{
							if (parse_char_read(p->s_in) == ';' ||
									p->s_in->rpos + 1 >= p->f_in->s->wpos)
							{
								is_var_type = 1;
							}
							else
							{
								is_free = 1;
								if (parse_lws(p->s_in))
								{
								}
								pos = chars_get_mark(p->s_in);
								if (parse_identifier(p->s_in))
								{
									is_var_type = 1;
								}
							}
						}
						else
						{
							is_var_type = 1;
						}
					}
					if (is_var_type)
					{
						// var type
						chars_reset(p->s_var_type);
						chars_read_pchar(p->s_var_type,
								p->s_in->buf + pos,
								p->s_in->rpos - pos,
								0);
						is_var_type = 0;
						if (parse_lws(p->s_in))
						{
						}
						pos = chars_get_mark(p->s_in);
						pos_var = pos;
						pos_var_type = pos_var;
						while (parse_identifier(p->s_in))
						{
							pos_var_type = pos_var;
							pos_var = chars_get_mark(p->s_in);
							if (is_pointer)
							{
								break;
							}
							if (parse_lws(p->s_in))
							{
							}
							if (parse_asterisk(p->s_in))
							{
								is_pointer = 1;
							}
							if (parse_lws(p->s_in))
							{
							}
						}
						if (pos < pos_var_type)
						{
							chars_read_pchar(p->s_var_type,
									" ",
									1,
									0);
							chars_read_pchar(p->s_var_type,
									p->s_in->buf + pos,
									pos_var_type - pos,
									0);
							p->s_in->rpos = pos_var_type;
							if (parse_lws(p->s_in))
							{
							}
						}
						else
						{
							chars_set_mark(p->s_in, pos);
						}
						if (parse_asterisk(p->s_in))
						{
							is_pointer = 1;
						}
						if (parse_lws(p->s_in))
						{
						}
						pos = chars_get_mark(p->s_in);
						if (parse_identifier(p->s_in))
						{
							pos_var = chars_get_mark(p->s_in);
							// var
							chars_reset(p->s_var);
							chars_read_pchar(p->s_var,
									p->s_in->buf + pos,
									p->s_in->rpos - pos,
									0);
							chars_read_pchar(p->s_struct,
									"VAR",
									0,
									0);
							if (is_pointer)
							{
								chars_read_pchar(p->s_struct,
										"_POINTER",
										0,
										0);
								is_pointer = 0;
								if (is_create)
								{
									chars_read_pchar(p->s_struct,
											"_CREATE",
											0,
											0);
									is_create = 0;
								}
								else if (is_init)
								{
									chars_read_pchar(p->s_struct,
											"_INIT",
											0,
											0);
									is_init = 0;
								}
								else if (is_free)
								{
									chars_read_pchar(p->s_struct,
											"_FREE",
											0,
											0);
									is_free = 0;
								}
							}
							chars_read_pchar(p->s_struct,
									"(",
									0,
									0);
							chars_copy(p->s_struct,
									p->s_var_type,
									0,
									0);
							chars_read_pchar(p->s_struct,
									",",
									0,
									0);
							chars_copy(p->s_struct,
									p->s_var,
									0,
									0);
							chars_read_pchar(p->s_struct,
									")\n",
									0,
									0);
							is_set++;
						}
						else if (!is_create &&
								!is_init &&
								!is_free &&
								!is_pointer)
						{
							// flag
							chars_read_pchar(p->s_struct_flags,
									"FLAG(",
									0,
									0);
							chars_copy(p->s_struct_flags,
									p->s_var_type,
									0,
									0);
							chars_read_pchar(p->s_struct_flags,
									")\n",
									0,
									0);
							is_set++;
						}
						else
						{
							is_create = 0;
							is_init = 0;
							is_free = 0;
							is_pointer = 0;
						}
					}
				}
				if (!chars_get_mark(p->s_in))
				{
					break;
				}
				chars_reset(p->s_in);
			}
			if (is_set > 0)
			{
				if (FUNC(open_file)(p,
							SECTION_STRUCT_FILE_NAME,
							FILE_FLAG_WRITE))
				{
					chars_reset(p->f_section->s);
					chars_copy(p->f_section->s,
							p->s_struct,
							0,
							0);
					if (chars_check_read(p->s_struct_flags))
					{
						chars_read_pchar(p->f_section->s,
								"FLAGS(\n",
								0,
								0);
						chars_copy(p->f_section->s,
								p->s_struct_flags,
								0,
								0);
						chars_read_pchar(p->f_section->s,
								")\n",
								0,
								0);
					}
					is_set = file_read_chars(p->f_section,
							p->f_section->s,
							0,
							0);
					if (is_set > 0)
					{
						chars_reset(p->s_in);
						chars_read_pchar(p->s_in,
								"#define MODULE_STRUCT ",
								0,
								0);
						chars_copy(p->s_in,
								p->s_module,
								0,
								0);
						chars_read_pchar(p->s_in,
								"_" SECTION_STRUCT_FILE_NAME "\n",
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

#undef SECTION_STRUCT_FILE_NAME

#endif	/* SECTION_STRUCT_H */

