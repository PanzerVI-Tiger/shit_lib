#pragma once

#include "dec.h"
#include "inc.h"
#include "repet.h"
#include "tuple.h"
#include "numeric.h"
#include "compare.h"
#include "variadic.h"

#define mylib_pp_plus(left, right)                \
    mylib_pp_if(mylib_pp_logical_or(left, right)) \
   (mylib_pp_variadic_size(                       \
        mylib_pp_if(left)                         \
            (mylib_pp_iota(0, left), )            \
            ()                                    \
        mylib_pp_iota(0, right)                   \
   ))                                             \
   (0)

#define mylib_pp_minus(left, right)                                                \
    mylib_pp_if(mylib_pp_logical_or(left, right))                                  \
   (mylib_pp_variadic_size(mylib_pp_variadic_drop(right, mylib_pp_iota(0, left)))) \
   (0)

#define mylib_pp_multiples(left, right)                                   \
    mylib_pp_tuple_size(                                                  \
        mylib_pp_tuple_cat_n(                                             \
            left,                                                         \
            mylib_pp_repeat(left, (mylib_pp_iota(0, right)), mylib_comma) \
        )                                                                 \
    )

// (a, b): a != 64 && b != 0
#define mylib_pp_plus_check_pred(tuple)                       \
    mylib_pp_logical_and(                                     \
        mylib_pp_not_equal(mylib_pp_tuple_get(tuple, 0), 64), \
        mylib_pp_not_equal(mylib_pp_tuple_get(tuple, 1), 0)   \
    )

// (a, b) => (a + 1, b - 1)
#define mylib_pp_plus_check_inc(tuple)                                                  \
    mylib_pp_tuple_set_f(mylib_pp_tuple_set_f(tuple, 0, mylib_pp_inc), 1, mylib_pp_dec)

// overflow will return max num
#define mylib_pp_plus_check(left, right) \
    mylib_pp_tuple_get(                  \
        mylib_pp_for(                    \
            (left, right),               \
            mylib_pp_plus_check_pred,    \
            mylib_pp_plus_check_inc      \
        ),                               \
        0                                \
    )

// (a, b): a != 0 && b != 0
#define mylib_pp_minus_check_pred(tuple)                     \
    mylib_pp_logical_and(                                    \
        mylib_pp_not_equal(mylib_pp_tuple_get(tuple, 0), 0), \
        mylib_pp_not_equal(mylib_pp_tuple_get(tuple, 1), 0) \
    )

// (a, b) => (a - 1, b - 1)
#define mylib_pp_minus_check_inc(tuple)                                                 \
    mylib_pp_tuple_set_f(mylib_pp_tuple_set_f(tuple, 0, mylib_pp_dec), 1, mylib_pp_dec)

// underflow will return 0
#define mylib_pp_minus_check(left, right) \
    mylib_pp_tuple_get(                   \
        mylib_pp_for(                     \
            (left, right),                \
            mylib_pp_minus_check_pred,    \
            mylib_pp_minus_check_inc      \
        ),                                \
        0                                 \
    )

#define mylib_pp_less_equal(left, right)                 \
    mylib_pp_equal(mylib_pp_minus_check(left, right), 0)
