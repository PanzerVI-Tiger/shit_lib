#pragma once

#include "macro_meta/bool.h"
#include "macro_meta/macro_base.h"

#define mylib_pp_if_impl(cond) mylib_pp_if ## cond
#define mylib_pp_if(value)     mylib_pp_if_impl(mylib_pp_bool(value))

#define mylib_pp_then_impl(...)
#define mylib_pp_then(...)      __VA_ARGS__ mylib_pp_then_impl

#define mylib_pp_else_impl(...) __VA_ARGS__
#define mylib_pp_else(...)      mylib_pp_else_impl

#define mylib_pp_if1(...) mylib_pp_then(__VA_ARGS__)
#define mylib_pp_if0(...) mylib_pp_else(__VA_ARGS__)
