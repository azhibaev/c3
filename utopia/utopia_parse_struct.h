/*
 * File:  utopia_parse_struct.h
 * Description: Utopia preprocessor of the 'mod.h' files
 * Author: Askar Azhibaev
 * Date:  December 2022
 * Copyright (c) 2022-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

VAR(int,section_index)
VAR_POINTER_INIT(chars,s)
VAR_POINTER_INIT(chars,s_in)
VAR_POINTER_INIT(chars,s_out)
VAR_POINTER_INIT(chars,s_module)
VAR_POINTER_INIT(chars,s_struct)
VAR_POINTER_INIT(chars,s_struct_flags)
VAR_POINTER_INIT(chars,s_init)
VAR_POINTER_INIT(chars,s_init_var)
VAR_POINTER_INIT(chars,s_free)
VAR_POINTER_INIT(chars,s_free_var)
VAR_POINTER_INIT(chars,s_include)
VAR_POINTER_INIT(chars,s_var)
VAR_POINTER_INIT(chars,s_var_type)
VAR_POINTER_INIT(chars,s_path_out)
VAR_POINTER_INIT(chars,s_basename)
VAR_POINTER_CREATE(file,f_in)
VAR_POINTER_CREATE(file,f_out)
VAR_POINTER_CREATE(file,f_section)
FLAGS(
FLAG(module)
)
