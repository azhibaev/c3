/*
 * File:  section_init.h
 * Description: Utopia preprocessor of the 'mod.h' files
 * Author: Askar Azhibaev
 * Date:  December 2022
 * Copyright (c) 2022-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef SECTION_INIT_H
#define SECTION_INIT_H

#define SECTION_INIT_FILE_NAME "init.h"
#define SECTION_INIT_VAR_FILE_NAME "init_var.h"

FUNCTION_INLINE int FUNC(section_init)(T *p)
{
	int is_set = 0;
	size_t pos = 0;
	int is_var = 1;
	int is_pointer = 0;
	size_t pos_var = 0;
	size_t pos_var_type = 0;

	if (p)
	{
		if (p->f_in)
		{
			chars_reset(p->s_init);
			chars_reset(p->s_init_var);
			if (parse_lws(p->s_in))
			{
			}
			if (parse_ch(p->s_in,
						'('))
			{
				pos = chars_get_mark(p->s_in);
				while (parse_identifier(p->s_in))
				{
					chars_reset(p->s_var_type);
					chars_read_pchar(p->s_var_type,
							p->s_in->buf + pos,
							p->s_in->rpos - pos,
							0);
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
						p->s_in->rpos = pos;
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
						chars_reset(p->s_var);
						chars_read_pchar(p->s_var,
								p->s_in->buf + pos,
								p->s_in->rpos - pos,
								0);
						chars_read_pchar(p->s_init_var,
								"PARAMETER",
								0,
								0);
						if (is_pointer)
						{
							chars_read_pchar(p->s_init_var,
									"_POINTER",
									0,
									0);
							is_pointer = 0;
						}
						chars_read_pchar(p->s_init_var,
								"(",
								0,
								0);
						chars_copy(p->s_init_var,
								p->s_var_type,
								0,
								0);
						chars_read_pchar(p->s_init_var,
								",",
								0,
								0);
						chars_copy(p->s_init_var,
								p->s_var,
								0,
								0);
						chars_read_pchar(p->s_init_var,
								")\n",
								0,
								0);
					}
					if (parse_lws(p->s_in))
					{
					}
					if (parse_ch(p->s_in,
								')'))
					{
						break;
					}
					if (!parse_ch(p->s_in,
								','))
					{
						break;
					}
					if (parse_lws(p->s_in))
					{
					}
					pos = chars_get_mark(p->s_in);
				}
			}
			chars_reset(p->s_in);
			while (file_write_chars(p->f_in,
						p->s_in,
						FILE_FLAG_WRITE_LINE))
			{
				if (chars_check(p->s_in))
				{
					if (is_var)
					{
						is_var = 0;
						pos = chars_get_mark(p->s_in);
						if (parse_identifier(p->s_in))
						{
							// var type
							chars_reset(p->s_var_type);
							chars_read_pchar(p->s_var_type,
									p->s_in->buf + pos,
									p->s_in->rpos - pos,
									0);
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
							pos = chars_get_mark(p->s_in);
							if (parse_identifier(p->s_in))
							{
								// var
								if (parse_lws(p->s_in))
								{
								}
								if (parse_ch(p->s_in,
											'='))
								{
									if (chars_check(p->s_in))
									{
										if (p->s_in->buf[p->f_in->s->wpos - 1] == ';')
										{
											p->s_in->rpos = p->f_in->s->wpos - 1;
											chars_reset(p->s_var);
											chars_read_pchar(p->s_var,
													p->s_in->buf + pos,
													p->s_in->rpos - pos,
													0);
											is_var++;
											chars_read_pchar(p->s_init_var,
													"VAR",
													0,
													0);
											if (is_pointer)
											{
												chars_read_pchar(p->s_init_var,
														"_POINTER",
														0,
														0);
												is_pointer = 0;
											}
											chars_read_pchar(p->s_init_var,
													"(",
													0,
													0);
											chars_copy(p->s_init_var,
													p->s_var_type,
													0,
													0);
											chars_read_pchar(p->s_init_var,
													",",
													0,
													0);
											chars_copy(p->s_init_var,
													p->s_var,
													0,
													0);
											chars_read_pchar(p->s_init_var,
													")\n",
													0,
													0);
											is_set++;
										}
									}
								}
							}
						}
					}
					if (!is_var)	
					{
						p->s_in->rpos = 0;
						/*
						if (p->s_in->buf[p->f_in->s->wpos] == '\n')
						{
							p->s_in->wpos++;
						}
						*/
						chars_copy(p->s_init,
								p->s_in,
								0,
								0);
						is_set++;
					}
				}
				if (p->s_in->wpos &&
						*p->s_in->buf == '\n')
				{
					break;
				}
				chars_reset(p->s_in);
			}
			if (is_set > 0)
			{
				if (chars_check_read(p->s_init))
				{
					if (FUNC(open_file)(p,
								SECTION_INIT_FILE_NAME,
								FILE_FLAG_WRITE))
					{
						chars_reset(p->f_section->s);
						chars_copy(p->f_section->s,
								p->s_init,
								0,
								0);
						is_set = file_read_chars(p->f_section,
								p->f_section->s,
								0,
								0);
						if (is_set > 0)
						{
							chars_reset(p->s_in);
							chars_read_pchar(p->s_in,
									"#define MODULE_INIT ",
									0,
									0);
							chars_copy(p->s_in,
									p->s_module,
									0,
									0);
							chars_read_pchar(p->s_in,
									"_" SECTION_INIT_FILE_NAME "\n",
									0,
									0);
							is_set = FUNC(write_out)(p);
						}
					}
				}
				if (chars_check_read(p->s_init_var))
				{
					if (FUNC(open_file)(p,
								SECTION_INIT_VAR_FILE_NAME,
								FILE_FLAG_WRITE))
					{
						chars_reset(p->f_section->s);
						chars_copy(p->f_section->s,
								p->s_init_var,
								0,
								0);
						is_set = file_read_chars(p->f_section,
								p->f_section->s,
								0,
								0);
						if (is_set > 0)
						{
							chars_reset(p->s_in);
							chars_read_pchar(p->s_in,
									"#define MODULE_INIT_VAR ",
									0,
									0);
							chars_copy(p->s_in,
									p->s_module,
									0,
									0);
							chars_read_pchar(p->s_in,
									"_" SECTION_INIT_VAR_FILE_NAME "\n",
									0,
									0);
							is_set = FUNC(write_out)(p);
						}
					}
				}
			}
		}
	}

	return is_set;
}

#undef SECTION_INIT_FILE_NAME
#undef SECTION_INIT_VAR_FILE_NAME

#endif	/* SECTION_INIT_H */

