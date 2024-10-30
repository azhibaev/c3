/*
 * File:  item_command_def.h
 * Description: Module framework
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef ITEM_T
#define ITEM_T(t,s,en,ru) ITEM_T_STR(t,s,en,ru)
#endif	/* ITEM_T */
#ifndef ITEM
#define ITEM(s,en,ru,f1,f2) ITEM_T(T,s,en,ru)
#endif	/* ITEM */
