#pragma once

#include "macro_meta/variadic.h"


#define mylib_space()     
#define mylib_colon()     :
#define mylib_comma()     ,
#define mylib_semicolon() ;

// sign of operation
#define mylib_plus_sign()       +
#define mylib_minus_sign()      -
#define mylib_divides_sign()    /
#define mylib_multiplies_sign() *

// token to string literal
#define mylib_pp_ttoa_impl(...)         #__VA_ARGS__
#define mylib_pp_ttoa(...)              mylib_pp_ttoa_impl(__VA_ARGS__)

#define mylib_pp_cat_ttoa_impl(...)     mylib_pp_ttoa(mylib_pp_cat(__VA_ARGS__))
#define mylib_pp_cat_ttoa(...)          mylib_pp_cat_ttoa_impl(__VA_ARGS__)

// cat token
#define mylib_pp_cat_n_impl(count, ...) mylib_pp_cat ## count(__VA_ARGS__)

#define mylib_pp_cat_n(count, ...)      mylib_pp_cat_n_impl(count, __VA_ARGS__)

#define mylib_pp_cat(...) \
    mylib_pp_call(mylib_pp_cat_n, mylib_pp_variadic_size(__VA_ARGS__), __VA_ARGS__)

// universal version
#define mylib_pp_forward(...)    __VA_ARGS__

#define mylib_pp_forward1(...)   __VA_ARGS__
#define mylib_pp_forward2(...)   __VA_ARGS__
#define mylib_pp_forward3(...)   __VA_ARGS__
#define mylib_pp_forward4(...)   __VA_ARGS__
#define mylib_pp_forward5(...)   __VA_ARGS__
#define mylib_pp_forward6(...)   __VA_ARGS__
#define mylib_pp_forward7(...)   __VA_ARGS__
#define mylib_pp_forward8(...)   __VA_ARGS__
#define mylib_pp_forward9(...)   __VA_ARGS__
#define mylib_pp_forward10(...)  __VA_ARGS__
#define mylib_pp_forward11(...)  __VA_ARGS__
#define mylib_pp_forward12(...)  __VA_ARGS__
#define mylib_pp_forward13(...)  __VA_ARGS__
#define mylib_pp_forward14(...)  __VA_ARGS__
#define mylib_pp_forward15(...)  __VA_ARGS__
#define mylib_pp_forward16(...)  __VA_ARGS__
#define mylib_pp_forward17(...)  __VA_ARGS__
#define mylib_pp_forward18(...)  __VA_ARGS__
#define mylib_pp_forward19(...)  __VA_ARGS__
#define mylib_pp_forward20(...)  __VA_ARGS__
#define mylib_pp_forward21(...)  __VA_ARGS__
#define mylib_pp_forward22(...)  __VA_ARGS__
#define mylib_pp_forward23(...)  __VA_ARGS__
#define mylib_pp_forward24(...)  __VA_ARGS__
#define mylib_pp_forward25(...)  __VA_ARGS__
#define mylib_pp_forward26(...)  __VA_ARGS__
#define mylib_pp_forward27(...)  __VA_ARGS__
#define mylib_pp_forward28(...)  __VA_ARGS__
#define mylib_pp_forward29(...)  __VA_ARGS__
#define mylib_pp_forward30(...)  __VA_ARGS__
#define mylib_pp_forward31(...)  __VA_ARGS__
#define mylib_pp_forward32(...)  __VA_ARGS__
#define mylib_pp_forward33(...)  __VA_ARGS__
#define mylib_pp_forward34(...)  __VA_ARGS__
#define mylib_pp_forward35(...)  __VA_ARGS__
#define mylib_pp_forward36(...)  __VA_ARGS__
#define mylib_pp_forward37(...)  __VA_ARGS__
#define mylib_pp_forward38(...)  __VA_ARGS__
#define mylib_pp_forward39(...)  __VA_ARGS__
#define mylib_pp_forward40(...)  __VA_ARGS__
#define mylib_pp_forward41(...)  __VA_ARGS__
#define mylib_pp_forward42(...)  __VA_ARGS__
#define mylib_pp_forward43(...)  __VA_ARGS__
#define mylib_pp_forward44(...)  __VA_ARGS__
#define mylib_pp_forward45(...)  __VA_ARGS__
#define mylib_pp_forward46(...)  __VA_ARGS__
#define mylib_pp_forward47(...)  __VA_ARGS__
#define mylib_pp_forward48(...)  __VA_ARGS__
#define mylib_pp_forward49(...)  __VA_ARGS__
#define mylib_pp_forward50(...)  __VA_ARGS__
#define mylib_pp_forward51(...)  __VA_ARGS__
#define mylib_pp_forward52(...)  __VA_ARGS__
#define mylib_pp_forward53(...)  __VA_ARGS__
#define mylib_pp_forward54(...)  __VA_ARGS__
#define mylib_pp_forward55(...)  __VA_ARGS__
#define mylib_pp_forward56(...)  __VA_ARGS__
#define mylib_pp_forward57(...)  __VA_ARGS__
#define mylib_pp_forward58(...)  __VA_ARGS__
#define mylib_pp_forward59(...)  __VA_ARGS__
#define mylib_pp_forward60(...)  __VA_ARGS__
#define mylib_pp_forward61(...)  __VA_ARGS__
#define mylib_pp_forward62(...)  __VA_ARGS__
#define mylib_pp_forward63(...)  __VA_ARGS__
#define mylib_pp_forward64(...)  __VA_ARGS__

// universal version
#define mylib_pp_call(callable, ...)   callable(__VA_ARGS__)

#define mylib_pp_call1(callable, ...)  callable(__VA_ARGS__)
#define mylib_pp_call2(callable, ...)  callable(__VA_ARGS__)
#define mylib_pp_call3(callable, ...)  callable(__VA_ARGS__)
#define mylib_pp_call4(callable, ...)  callable(__VA_ARGS__)
#define mylib_pp_call5(callable, ...)  callable(__VA_ARGS__)
#define mylib_pp_call6(callable, ...)  callable(__VA_ARGS__)
#define mylib_pp_call7(callable, ...)  callable(__VA_ARGS__)
#define mylib_pp_call8(callable, ...)  callable(__VA_ARGS__)
#define mylib_pp_call9(callable, ...)  callable(__VA_ARGS__)
#define mylib_pp_call10(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call11(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call12(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call13(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call14(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call15(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call16(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call17(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call18(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call19(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call20(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call21(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call22(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call23(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call24(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call25(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call26(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call27(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call28(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call29(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call30(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call31(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call32(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call33(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call34(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call35(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call36(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call37(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call38(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call39(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call40(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call41(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call42(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call43(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call44(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call45(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call46(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call47(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call48(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call49(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call50(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call51(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call52(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call53(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call54(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call55(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call56(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call57(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call58(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call59(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call60(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call61(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call62(callable, ...) callable(__VA_ARGS__)
#define mylib_pp_call63(callable, ...) callable(__VA_ARGS__)            
#define mylib_pp_call64(callable, ...) callable(__VA_ARGS__)

#define mylib_pp_cat0()            
#define mylib_pp_cat1(                                                                  \
        t0                                                                              \
    )                                                                                   \
    t0
#define mylib_pp_cat2(                                                                  \
        t0, t1                                                                          \
    )                                                                                   \
    t0 ## t1
#define mylib_pp_cat3(                                                                  \
        t0, t1, t2                                                                      \
    )                                                                                   \
    t0 ## t1 ## t2
#define mylib_pp_cat4(                                                                  \
        t0, t1, t2, t3                                                                  \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3
#define mylib_pp_cat5(                                                                  \
        t0, t1, t2, t3, t4                                                              \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4
#define mylib_pp_cat6(                                                                  \
        t0, t1, t2, t3, t4, t5                                                          \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5
#define mylib_pp_cat7(                                                                  \
        t0, t1, t2, t3, t4, t5, t6                                                      \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6
#define mylib_pp_cat8(                                                                  \
        t0, t1, t2, t3, t4, t5, t6, t7                                                  \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7
#define mylib_pp_cat9(                                                                  \
        t0, t1, t2, t3, t4, t5, t6, t7, t8                                              \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8
#define mylib_pp_cat10(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9                                          \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9
#define mylib_pp_cat11(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10                                     \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10
#define mylib_pp_cat12(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11                                \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11
#define mylib_pp_cat13(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12                           \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12
#define mylib_pp_cat14(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13                      \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13
#define mylib_pp_cat15(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14                 \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14
#define mylib_pp_cat16(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15            \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15
#define mylib_pp_cat17(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16       \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16
#define mylib_pp_cat18(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17  \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17
#define mylib_pp_cat19(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18                                                                             \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18
#define mylib_pp_cat20(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19                                                                        \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19
#define mylib_pp_cat21(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20                                                                   \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20
#define mylib_pp_cat22(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21                                                              \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21
#define mylib_pp_cat23(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22                                                         \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22
#define mylib_pp_cat24(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16,      \
        t17, t18, t19, t20, t21, t22, t23                                               \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23
#define mylib_pp_cat25(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24                                               \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24
#define mylib_pp_cat26(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25                                          \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25
#define mylib_pp_cat27(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26                                     \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26
#define mylib_pp_cat28(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27                                \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27
#define mylib_pp_cat29(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28                           \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28
#define mylib_pp_cat30(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29                      \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29
#define mylib_pp_cat31(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30                 \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30
#define mylib_pp_cat32(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31            \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31
#define mylib_pp_cat33(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32       \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32
#define mylib_pp_cat34(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33  \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33
#define mylib_pp_cat35(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34                                                                             \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34
#define mylib_pp_cat36(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35                                                                        \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35
#define mylib_pp_cat37(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36                                                                   \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36
#define mylib_pp_cat38(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37                                                              \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37
#define mylib_pp_cat39(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38                                                         \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38
#define mylib_pp_cat40(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39                                                    \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39
#define mylib_pp_cat41(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40                                               \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40
#define mylib_pp_cat42(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41                                          \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41
#define mylib_pp_cat43(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42                                     \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42
#define mylib_pp_cat44(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43                                \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43
#define mylib_pp_cat45(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44                           \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44
#define mylib_pp_cat46(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45                      \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45
#define mylib_pp_cat47(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46                 \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46
#define mylib_pp_cat48(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47            \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47
#define mylib_pp_cat49(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48       \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48
#define mylib_pp_cat50(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49  \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49
#define mylib_pp_cat51(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, \
        t50                                                                             \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49 ## t50
#define mylib_pp_cat52(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, \
        t50, t51                                                                        \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49 ## t50 ## t51
#define mylib_pp_cat53(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, \
        t50, t51, t52                                                                   \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49 ## t50 ## t51 ## t52
#define mylib_pp_cat54(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, \
        t50, t51, t52, t53                                                              \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49 ## t50 ## t51 ## t52 ## t53
#define mylib_pp_cat55(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, \
        t50, t51, t52, t53, t54                                                         \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49 ## t50 ## t51 ## t52 ## t53 ## t54
#define mylib_pp_cat56(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, \
        t50, t51, t52, t53, t54, t55                                                    \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49 ## t50 ## t51 ## t52 ## t53 ## t54 ## t55
#define mylib_pp_cat57(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, \
        t50, t51, t52, t53, t54, t55, t56                                               \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49 ## t50 ## t51 ## t52 ## t53 ## t54 ## t55 ## t56
#define mylib_pp_cat58(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, \
        t50, t51, t52, t53, t54, t55, t56, t57                                          \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49 ## t50 ## t51 ## t52 ## t53 ## t54 ## t55 ##                                    \
    t56 ## t57
#define mylib_pp_cat59(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, \
        t50, t51, t52, t53, t54, t55, t56, t57, t58                                     \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49 ## t50 ## t51 ## t52 ## t53 ## t54 ## t55 ## t56 ## t57 ## t58
#define mylib_pp_cat60(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, \
        t50, t51, t52, t53, t54, t55, t56, t57, t58, t59                                \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49 ## t50 ## t51 ## t52 ## t53 ## t54 ## t55 ## t56 ## t57 ## t58 ## t59
#define mylib_pp_cat61(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, \
        t50, t51, t52, t53, t54, t55, t56, t57, t58, t59, t60                           \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49 ## t50 ## t51 ## t52 ## t53 ## t54 ## t55 ## t56 ## t57 ## t58 ## t59 ## t60
#define mylib_pp_cat62(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, \
        t50, t51, t52, t53, t54, t55, t56, t57, t58, t59, t60, t61                      \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49 ## t50 ## t51 ## t52 ## t53 ## t54 ## t55 ## t56 ## t57 ## t58 ## t59 ## t60 ## \
    t61
#define mylib_pp_cat63(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, \
        t50, t51, t52, t53, t54, t55, t56, t57, t58, t59, t60, t61, t62                 \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49 ## t50 ## t51 ## t52 ## t53 ## t54 ## t55 ## t56 ## t57 ## t58 ## t59 ## t60 ## \
    t61 ## t62
#define mylib_pp_cat64(                                                                 \
        t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, \
        t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, \
        t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, \
        t50, t51, t52, t53, t54, t55, t56, t57, t58, t59, t60, t61, t62, t63            \
    )                                                                                   \
    t0 ## t1 ## t2 ## t3 ## t4 ## t5 ## t6 ## t7 ## t8 ## t9 ## t10 ## t11 ## t12 ##    \
    t13 ## t14 ## t15 ## t16 ## t17 ## t18 ## t19 ## t20 ## t21 ## t22 ## t23 ## t24 ## \
    t25 ## t26 ## t27 ## t28 ## t29 ## t30 ## t31 ## t32 ## t33 ## t34 ## t35 ## t36 ## \
    t37 ## t38 ## t39 ## t40 ## t41 ## t42 ## t43 ## t44 ## t45 ## t46 ## t47 ## t48 ## \
    t49 ## t50 ## t51 ## t52 ## t53 ## t54 ## t55 ## t56 ## t57 ## t58 ## t59 ## t60 ## \
    t61 ## t62 ## t63
