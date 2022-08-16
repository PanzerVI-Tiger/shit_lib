#pragma once

#include "dec.h"
#include "repet.h"
#include "macro_base.h"


#define mylib_pp_iota_impl(m, n)                           \
    mylib_pp_variadic_drop(                                \
        m,                                                 \
        mylib_pp_repeat_call(                              \
            mylib_pp_dec(n), mylib_pp_forward, mylib_comma \
        )                                                  \
    )
    
#define mylib_pp_iota(m, n)  \
    mylib_pp_iota_impl(m, n)
