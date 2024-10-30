/*
 * File:  common_def.h
 * Description: Common definitions
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef COMMON_DEF_H
#define COMMON_DEF_H

#ifndef FUNCTION_INLINE
#ifdef _WIN32
#define FUNCTION_INLINE static __inline
#else
#define FUNCTION_INLINE static inline
#endif	/* _WIN32 */
#endif	/* FUNCTION_INLINE */

#ifndef KB
#define KB * (1 << 10)
#endif	/* KB */

#endif	/* COMMON_DEF_H */

