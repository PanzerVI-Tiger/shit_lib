#pragma once

#include "macro_meta/bool.h"
#include "macro_meta/macro_base.h"

#define mylib_pp_then(a, b) a
#define mylib_pp_else(a, b) b

#define mylib_pp_if0 mylib_pp_else
#define mylib_pp_if1 mylib_pp_then

#define mylib_pp_if_impl(cond) mylib_pp_if ## cond
#define mylib_pp_if(value)     mylib_pp_call(mylib_pp_if_impl, mylib_pp_bool(value))
