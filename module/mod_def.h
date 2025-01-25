/*
 * File:  module_def.h
 * Description: Module framework
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef STR
#ifndef STR2
#define STR2(s) #s
#define STR(s) STR2(s)
#endif	/* STR2 */
#endif	/* STR */

#ifndef T_MODULE_NAME_SUFFIX_STR
#define T_MODULE_NAME_SUFFIX_STR(module,suffix,name) module ## _ ## suffix ## _ ## name
#endif	/* T_MODULE_NAME_SUFFIX_STR */

#ifndef T_MODULE_NAME_SUFFIX
#define T_MODULE_NAME_SUFFIX(module,suffix,name) T_MODULE_NAME_SUFFIX_STR(module,suffix,name)
#endif	/* T_MODULE_NAME_SUFFIX */

#ifndef T_MODULE_NAME_PREFIX_SUFFIX_STR
#define T_MODULE_NAME_PREFIX_SUFFIX_STR(prefix,module,suffix,name) prefix ## _ ##  module ## _ ## suffix ## _ ## name
#endif	/* T_MODULE_NAME_PREFIX_SUFFIX_STR */

#ifndef T_MODULE_NAME_PREFIX_SUFFIX
#define T_MODULE_NAME_PREFIX_SUFFIX(prefix,module,suffix,name) T_MODULE_NAME_PREFIX_SUFFIX_STR(prefix,module,suffix,name)
#endif	/* T_MODULE_NAME_PREFIX_SUFFIX */

#ifndef T_MODULE_NAME_PREFIX_STR
#define T_MODULE_NAME_PREFIX_STR(prefix,module,name) prefix ## _ ## module ## _ ## name
#endif	/* T_MODULE_NAME_PREFIX_STR */

#ifndef T_MODULE_NAME_PREFIX
#define T_MODULE_NAME_PREFIX(prefix,module,name) T_MODULE_NAME_PREFIX_STR(prefix,module,name)
#endif	/* T_MODULE_NAME_PREFIX */

#ifndef T_MODULE_NAME_STR
#define T_MODULE_NAME_STR(module,name) module ## _ ## name
#endif	/* T_MODULE_NAME_STR */

#ifndef T_MODULE_NAME
#define T_MODULE_NAME(module,name) T_MODULE_NAME_STR(module,name)
#endif	/* T_MODULE_NAME */

#ifdef MODULE_NAME_SUFFIX

#define FUNC(name) T_MODULE_NAME_SUFFIX(MODULE_NAME,MODULE_NAME_SUFFIX,name)
#define T_NAME(name) T_MODULE_NAME_SUFFIX(MODULE_NAME,MODULE_NAME_SUFFIX,name)
#define T_PREFIX_NAME(prefix,name) T_MODULE_NAME_PREFIX_SUFFIX(prefix,MODULE_NAME,MODULE_NAME_SUFFIX,name)
#define T T_MODULE_NAME(MODULE_NAME,MODULE_NAME_SUFFIX)
/* Timely until automatic function name recognition */
#define FUNC_PARENT(name) T_MODULE_NAME(MODULE_NAME,name)
#define T_NAME_PARENT(name) T_MODULE_NAME(MODULE_NAME,name)
#define T_PREFIX_NAME_PARENT(prefix,name) T_MODULE_NAME_PREFIX(prefix,MODULE_NAME,name)
#define T_PARENT MODULE_NAME

#else	/* MODULE_NAME_SUFFIX */

#define FUNC(name) T_MODULE_NAME(MODULE_NAME,name)
#define T_NAME(name) T_MODULE_NAME(MODULE_NAME,name)
#define T_PREFIX_NAME(prefix,name) T_MODULE_NAME_PREFIX(prefix,MODULE_NAME,name)
#define T MODULE_NAME

#endif	/* MODULE_NAME_SUFFIX */

#ifdef _DEBUG
#define MODULE_DEBUG(p) {p}
#else
#define MODULE_DEBUG(p)
#endif	/* _DEBUG */

