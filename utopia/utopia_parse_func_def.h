/*
 * File:  utopia_parse_func_def.h
 * Description: Utopia preprocessor of the 'mod.h' files
 * Author: Askar Azhibaev
 * Date:  December 2022
 * Copyright (c) 2022-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

FUNCTION_INLINE int FUNC(open_file)(T *p,
		const char *file_name,
		unsigned int flags);
FUNCTION_INLINE int FUNC(write_out)(T *p);
