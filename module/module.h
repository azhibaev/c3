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

#include "module_def.h"

#ifdef MODULE_STRUCT
#include "module_struct.h"
#include "module_create.h"
#include "module_init.h"
#include "module_create_init.h"
#include "module_init_default.h"
#include "module_free.h"
#endif	/* MODULE_STRUCT */

