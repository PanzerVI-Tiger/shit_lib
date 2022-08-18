#pragma once

#include "if.h"
#include "dec.h"
#include "repet.h"
#include "compare.h"
#include "macro_base.h"


#define mylib_pp_iota_impl(m, n)                                                        \
    mylib_pp_if(mylib_pp_not_equal(m, n))                                               \
       (mylib_pp_variadic_drop(                                                         \
            m,                                                                          \
            mylib_pp_repeat_call(                                                       \
                mylib_pp_dec(n), mylib_pp_forward, mylib_comma                          \
            )                                                                           \
       ))                                                                               \
       ()
    
#define mylib_pp_iota(m, n)                                                             \
    mylib_pp_iota_impl(m, n)
