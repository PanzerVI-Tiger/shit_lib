#pragma once

#include "if.h"
#include "inc.h"
#include "for.h"
#include "variadic.h"
#include "macro_base.h"

#define mylib_pp_tuple_impl(...) (, __VA_ARGS__, )
#define mylib_pp_tuple(...)      mylib_pp_tuple_impl(__VA_ARGS__)

#define mylib_pp_tuple_size(tuple) \
    mylib_pp_variadic_size tuple

#define mylib_pp_tuple_extend(tuple) \
    mylib_pp_forward tuple

#define mylib_pp_tuple_take(tuple, count)                         \
    (mylib_pp_variadic_take(count, mylib_pp_tuple_extend(tuple)))

#define mylib_pp_tuple_drop(tuple, count)                         \
    (mylib_pp_variadic_drop(count, mylib_pp_tuple_extend(tuple)))

#define mylib_pp_tuple_slice(tuple, first, last)                         \
    (mylib_pp_variadic_slice(first, last, mylib_pp_tuple_extend(tuple)))

#define mylib_pp_tuple_get(tuple, index)                       \
    mylib_pp_variadic_get(index, mylib_pp_tuple_extend(tuple))

#define mylib_pp_tuple_set_impl(tuple, index, value)                       \
   (mylib_pp_if(index)                                                     \
        (mylib_pp_tuple_extend(mylib_pp_tuple_take(tuple, index)),)        \
        ()                                                                 \
    value,                                                                 \
   mylib_pp_tuple_extend(mylib_pp_tuple_drop(tuple, mylib_pp_inc(index))))
#define mylib_pp_tuple_set(tuple, index, value)  \
    mylib_pp_tuple_set_impl(tuple, index, value)

#define mylib_pp_tuple_cat_n_impl(count, ...)                                    \
    (mylib_pp_foreach_n(count, mylib_pp_tuple_extend, mylib_comma, __VA_ARGS__))
#define mylib_pp_tuple_cat_n(count, ...)          \
    mylib_pp_tuple_cat_n_impl(count, __VA_ARGS__)
#define mylib_pp_tuple_cat(...)                                            \
    mylib_pp_tuple_cat_n(mylib_pp_variadic_size(__VA_ARGS__), __VA_ARGS__)
