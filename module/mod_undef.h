/*
 * File:  module_undef.h
 * Description: Module framework
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#undef T_MODULE_NAME_SUFFIX_STR
#undef T_MODULE_NAME_SUFFIX
#undef T_MODULE_NAME_PREFIX_SUFFIX_STR
#undef T_MODULE_NAME_PREFIX_SUFFIX
#undef T_MODULE_NAME_PREFIX_STR
#undef T_MODULE_NAME_PREFIX
#undef T_MODULE_NAME_STR
#undef T_MODULE_NAME
#undef T_PREFIX_NAME
#undef FUNC
#undef T_NAME
#undef T_STR
#undef T
#undef MODULE_DEBUG

#ifndef MODULE_NAME_SUFFIX
#undef MODULE_NAME
#endif	/* MODULE_NAME_SUFFIX */
#undef MODULE_NAME_SUFFIX
#undef MODULE_STRUCT
#undef MODULE_FUNC_DEF
#undef MODULE_CREATE
#undef MODULE_CREATE_VAR
#undef MODULE_INIT
#undef MODULE_INIT_VAR
#undef MODULE_FREE
#undef MODULE_FREE_VAR
/* Timely until automatic function name recognition */
#undef FUNC_PARENT
#undef T_NAME_PARENT
#undef T_PREFIX_NAME_PARENT
#undef T_PARENT
