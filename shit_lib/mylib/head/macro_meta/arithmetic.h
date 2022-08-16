#pragma once

#include "repet.h"
#include "tuple.h"
#include "numeric.h"
#include "variadic.h"


#define mylib_pp_plus(left, right) \
    mylib_pp_variadic_size(mylib_pp_iota(0, right), mylib_pp_iota(0, right))

#define mylib_pp_minus(left, right) \
    mylib_pp_variadic_size(mylib_pp_variadic_drop(right, mylib_pp_iota(0, left)))

#define mylib_pp_multiples(left, right)                                   \
    mylib_pp_tuple_size(                                                  \
        mylib_pp_tuple_cat_n(                                             \
            left,                                                         \
            mylib_pp_repeat(left, (mylib_pp_iota(0, right)), mylib_comma) \
        )                                                                 \
    )

