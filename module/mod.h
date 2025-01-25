/*
 * File:  module.h
 * Description: Module framework
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#include "mod_def.h"

#ifdef MODULE_STRUCT
#include "mod_struct.h"
#include "mod_create.h"
#include "mod_init.h"
#include "mod_create_init.h"
#include "mod_init_default.h"
#include "mod_free.h"
#endif	/* MODULE_STRUCT */

