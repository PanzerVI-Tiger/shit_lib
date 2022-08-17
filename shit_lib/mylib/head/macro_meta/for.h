#pragma once

#include "if.h"
#include "variadic.h"

#define mylib_pp_foreach_impl(count, callable, getSeparator, ...)  \
    mylib_pp_foreach ## count(callable, getSeparator, __VA_ARGS__)
#define mylib_pp_foreach_n(count, callable, getSeparator, ...)        \
    mylib_pp_foreach_impl(count, callable, getSeparator, __VA_ARGS__)
#define mylib_pp_foreach(callable, getSeparator, ...)                            \
    mylib_pp_foreach_n(                                                          \
        mylib_pp_variadic_size(__VA_ARGS__), callable, getSeparator, __VA_ARGS__ \
    )

#define mylib_pp_for_impl(var, pred, inc) \
    mylib_pp_for64(var, pred, inc)
#define mylib_pp_for(var, pred, inc)  \
    mylib_pp_for_impl(var, pred, inc)
    

#define mylib_pp_foreach0(\
        c, s              \
    )
#define mylib_pp_foreach1(\
        c, s, e0          \
    )                     \
    c(e0)
#define mylib_pp_foreach2(\
        c, s, e0, e1      \
    )                     \
    c(e0) s() c(e1)
#define mylib_pp_foreach3(    \
        c, s, e0, e1, e2      \
    )                         \
    c(e0) s() c(e1) s() c(e2)
#define mylib_pp_foreach4(              \
        c, s, e0, e1, e2, e3            \
    )                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3)
#define mylib_pp_foreach5(                        \
        c, s, e0, e1, e2, e3, e4                  \
    )                                             \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4)
#define mylib_pp_foreach6(                                  \
        c, s, e0, e1, e2, e3, e4, e5                        \
    )                                                       \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5)
#define mylib_pp_foreach7(                                            \
        c, s, e0, e1, e2, e3, e4, e5, e6                              \
    )                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6)
#define mylib_pp_foreach8(                                                      \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7                                    \
    )                                                                           \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7)
#define mylib_pp_foreach9(                                                          \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8                                    \
    )                                                                               \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s() \
    c(e8)
#define mylib_pp_foreach10(                                                         \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9                                \
    )                                                                               \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s() \
    c(e8) s() c(e9)
#define mylib_pp_foreach11(                                                         \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10                           \
    )                                                                               \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s() \
    c(e8) s() c(e9) s() c(e10)
#define mylib_pp_foreach12(                                                         \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11                      \
    )                                                                               \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s() \
    c(e8) s() c(e9) s() c(e10) s() c(e11)
#define mylib_pp_foreach13(                                                         \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12                 \
    )                                                                               \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s() \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12)
#define mylib_pp_foreach14(                                                         \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13            \
    )                                                                               \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s() \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13)
#define mylib_pp_foreach15(                                                         \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14       \
    )                                                                               \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s() \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14)
#define mylib_pp_foreach16(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15    \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)
#define mylib_pp_foreach17(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,   \
        e16                                                                           \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15) \
    s() c(e16)
#define mylib_pp_foreach18(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,   \
        e16, e17                                                                      \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15) \
    s() c(e16) s() c(e17)
#define mylib_pp_foreach19(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,   \
        e16, e17, e18                                                                 \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15) \
    s() c(e16) s() c(e17) s() c(e18)
#define mylib_pp_foreach20(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,   \
        e16, e17, e18, e19                                                            \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15) \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19)
#define mylib_pp_foreach21(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,   \
        e16, e17, e18, e19, e20                                                       \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15) \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20)
#define mylib_pp_foreach22(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,   \
        e16, e17, e18, e19, e20, e21                                                  \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15) \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21)
#define mylib_pp_foreach23(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,   \
        e16, e17, e18, e19, e20, e21, e22                                             \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15) \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22)
#define mylib_pp_foreach24(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,   \
        e16, e17, e18, e19, e20, e21, e22, e23                                        \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15) \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()  \
    c(e23)
#define mylib_pp_foreach25(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,   \
        e16, e17, e18, e19, e20, e21, e22, e23, e24                                   \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15) \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()  \
    c(e23) s() c(e24)
#define mylib_pp_foreach26(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,   \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25                              \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15) \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()  \
    c(e23) s() c(e24) s() c(e25)
#define mylib_pp_foreach27(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,   \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26                         \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15) \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()  \
    c(e23) s() c(e24) s() c(e25) s() c(e26)
#define mylib_pp_foreach28(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,   \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27                    \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15) \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()  \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27)
#define mylib_pp_foreach29(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,   \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28               \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15) \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()  \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28)
#define mylib_pp_foreach30(                                                           \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,   \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29          \
    )                                                                                 \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()   \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15) \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()  \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29)
#define mylib_pp_foreach31(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30       \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30)
#define mylib_pp_foreach32(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31  \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31)
#define mylib_pp_foreach33(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32                                                                             \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32)
#define mylib_pp_foreach34(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33                                                                        \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33)
#define mylib_pp_foreach35(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34                                                                   \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34)
#define mylib_pp_foreach36(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35                                                              \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35)
#define mylib_pp_foreach37(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36                                                         \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36)
#define mylib_pp_foreach38(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37                                                    \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37)
#define mylib_pp_foreach39(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38                                               \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38)
#define mylib_pp_foreach40(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39                                          \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39)
#define mylib_pp_foreach41(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40                                     \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40)
#define mylib_pp_foreach42(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41                                \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41)
#define mylib_pp_foreach43(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42                           \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42)
#define mylib_pp_foreach44(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43                      \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43)
#define mylib_pp_foreach45(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44                 \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44)
#define mylib_pp_foreach46(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45            \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45)
#define mylib_pp_foreach47(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46       \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46)
#define mylib_pp_foreach48(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47  \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47)
#define mylib_pp_foreach49(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48                                                                             \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48)
#define mylib_pp_foreach50(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49                                                                        \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49)
#define mylib_pp_foreach51(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50                                                                   \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49) s() c(e50)
#define mylib_pp_foreach52(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51                                                              \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49) s() c(e50) s() c(e51)
#define mylib_pp_foreach53(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52                                                         \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49) s() c(e50) s() c(e51) s() c(e52)
#define mylib_pp_foreach54(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53                                                    \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49) s() c(e50) s() c(e51) s() c(e52) s()    \
    c(e53)
#define mylib_pp_foreach55(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54                                               \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49) s() c(e50) s() c(e51) s() c(e52) s()    \
    c(e53) s() c(e54)
#define mylib_pp_foreach56(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55                                          \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49) s() c(e50) s() c(e51) s() c(e52) s()    \
    c(e53) s() c(e54) s() c(e55)
#define mylib_pp_foreach57(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56                                     \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49) s() c(e50) s() c(e51) s() c(e52) s()    \
    c(e53) s() c(e54) s() c(e55) s() c(e56)
#define mylib_pp_foreach58(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, e57                                \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49) s() c(e50) s() c(e51) s() c(e52) s()    \
    c(e53) s() c(e54) s() c(e55) s() c(e56) s() c(e57)
#define mylib_pp_foreach59(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58                           \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49) s() c(e50) s() c(e51) s() c(e52) s()    \
    c(e53) s() c(e54) s() c(e55) s() c(e56) s() c(e57) s() c(e58)
#define mylib_pp_foreach60(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59                      \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49) s() c(e50) s() c(e51) s() c(e52) s()    \
    c(e53) s() c(e54) s() c(e55) s() c(e56) s() c(e57) s() c(e58) s() c(e59)
#define mylib_pp_foreach61(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60                 \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49) s() c(e50) s() c(e51) s() c(e52) s()    \
    c(e53) s() c(e54) s() c(e55) s() c(e56) s() c(e57) s() c(e58) s() c(e59) s() c(e60)
#define mylib_pp_foreach62(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61            \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49) s() c(e50) s() c(e51) s() c(e52) s()    \
    c(e53) s() c(e54) s() c(e55) s() c(e56) s() c(e57) s() c(e58) s() c(e59) s() c(e60) \
    s() c(e61)
#define mylib_pp_foreach63(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62       \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49) s() c(e50) s() c(e51) s() c(e52) s()    \
    c(e53) s() c(e54) s() c(e55) s() c(e56) s() c(e57) s() c(e58) s() c(e59) s() c(e60) \
    s() c(e61) s() c(e62)
#define mylib_pp_foreach64(                                                             \
        c, s, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,     \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63  \
    )                                                                                   \
    c(e0) s() c(e1) s() c(e2) s() c(e3) s() c(e4) s() c(e5) s() c(e6) s() c(e7) s()     \
    c(e8) s() c(e9) s() c(e10) s() c(e11) s() c(e12) s() c(e13) s() c(e14) s() c(e15)   \
    s() c(e16) s() c(e17) s() c(e18) s() c(e19) s() c(e20) s() c(e21) s() c(e22) s()    \
    c(e23) s() c(e24) s() c(e25) s() c(e26) s() c(e27) s() c(e28) s() c(e29) s() c(e30) \
    s() c(e31) s() c(e32) s() c(e33) s() c(e34) s() c(e35) s() c(e36) s() c(e37) s()    \
    c(e38) s() c(e39) s() c(e40) s() c(e41) s() c(e42) s() c(e43) s() c(e44) s() c(e45) \
    s() c(e46) s() c(e47) s() c(e48) s() c(e49) s() c(e50) s() c(e51) s() c(e52) s()    \
    c(e53) s() c(e54) s() c(e55) s() c(e56) s() c(e57) s() c(e58) s() c(e59) s() c(e60) \
    s() c(e61) s() c(e62) s() c(e63)

#define mylib_pp_for0(var, pred, inc) \
    mylib_pp_if(pred(var)) (var) (var)
#define mylib_pp_for1(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for0(inc(var), pred, inc)) (var)
#define mylib_pp_for2(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for1(inc(var), pred, inc)) (var)
#define mylib_pp_for3(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for2(inc(var), pred, inc)) (var)
#define mylib_pp_for4(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for3(inc(var), pred, inc)) (var)
#define mylib_pp_for5(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for4(inc(var), pred, inc)) (var)
#define mylib_pp_for6(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for5(inc(var), pred, inc)) (var)
#define mylib_pp_for7(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for6(inc(var), pred, inc)) (var)
#define mylib_pp_for8(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for7(inc(var), pred, inc)) (var)
#define mylib_pp_for9(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for8(inc(var), pred, inc)) (var)
#define mylib_pp_for10(var, pred, inc)                                \
    mylib_pp_if(pred(var)) (mylib_pp_for9(inc(var), pred, inc)) (var)
#define mylib_pp_for11(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for10(inc(var), pred, inc)) (var)
#define mylib_pp_for12(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for11(inc(var), pred, inc)) (var)
#define mylib_pp_for13(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for12(inc(var), pred, inc)) (var)
#define mylib_pp_for14(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for13(inc(var), pred, inc)) (var)
#define mylib_pp_for15(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for14(inc(var), pred, inc)) (var)
#define mylib_pp_for16(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for15(inc(var), pred, inc)) (var)
#define mylib_pp_for17(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for16(inc(var), pred, inc)) (var)
#define mylib_pp_for18(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for17(inc(var), pred, inc)) (var)
#define mylib_pp_for19(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for18(inc(var), pred, inc)) (var)
#define mylib_pp_for20(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for19(inc(var), pred, inc)) (var)
#define mylib_pp_for21(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for20(inc(var), pred, inc)) (var)
#define mylib_pp_for22(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for21(inc(var), pred, inc)) (var)
#define mylib_pp_for23(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for22(inc(var), pred, inc)) (var)
#define mylib_pp_for24(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for23(inc(var), pred, inc)) (var)
#define mylib_pp_for25(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for24(inc(var), pred, inc)) (var)
#define mylib_pp_for26(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for25(inc(var), pred, inc)) (var)
#define mylib_pp_for27(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for26(inc(var), pred, inc)) (var)
#define mylib_pp_for28(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for27(inc(var), pred, inc)) (var)
#define mylib_pp_for29(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for28(inc(var), pred, inc)) (var)
#define mylib_pp_for30(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for29(inc(var), pred, inc)) (var)
#define mylib_pp_for31(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for30(inc(var), pred, inc)) (var)
#define mylib_pp_for32(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for31(inc(var), pred, inc)) (var)
#define mylib_pp_for33(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for32(inc(var), pred, inc)) (var)
#define mylib_pp_for34(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for33(inc(var), pred, inc)) (var)
#define mylib_pp_for35(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for34(inc(var), pred, inc)) (var)
#define mylib_pp_for36(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for35(inc(var), pred, inc)) (var)
#define mylib_pp_for37(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for36(inc(var), pred, inc)) (var)
#define mylib_pp_for38(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for37(inc(var), pred, inc)) (var)
#define mylib_pp_for39(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for38(inc(var), pred, inc)) (var)
#define mylib_pp_for40(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for39(inc(var), pred, inc)) (var)
#define mylib_pp_for41(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for40(inc(var), pred, inc)) (var)
#define mylib_pp_for42(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for41(inc(var), pred, inc)) (var)
#define mylib_pp_for43(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for42(inc(var), pred, inc)) (var)
#define mylib_pp_for44(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for43(inc(var), pred, inc)) (var)
#define mylib_pp_for45(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for44(inc(var), pred, inc)) (var)
#define mylib_pp_for46(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for45(inc(var), pred, inc)) (var)
#define mylib_pp_for47(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for46(inc(var), pred, inc)) (var)
#define mylib_pp_for48(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for47(inc(var), pred, inc)) (var)
#define mylib_pp_for49(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for48(inc(var), pred, inc)) (var)
#define mylib_pp_for50(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for49(inc(var), pred, inc)) (var)
#define mylib_pp_for51(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for50(inc(var), pred, inc)) (var)
#define mylib_pp_for52(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for51(inc(var), pred, inc)) (var)
#define mylib_pp_for53(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for52(inc(var), pred, inc)) (var)
#define mylib_pp_for54(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for53(inc(var), pred, inc)) (var)
#define mylib_pp_for55(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for54(inc(var), pred, inc)) (var)
#define mylib_pp_for56(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for55(inc(var), pred, inc)) (var)
#define mylib_pp_for57(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for56(inc(var), pred, inc)) (var)
#define mylib_pp_for58(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for57(inc(var), pred, inc)) (var)
#define mylib_pp_for59(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for58(inc(var), pred, inc)) (var)
#define mylib_pp_for60(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for59(inc(var), pred, inc)) (var)
#define mylib_pp_for61(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for60(inc(var), pred, inc)) (var)
#define mylib_pp_for62(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for61(inc(var), pred, inc)) (var)
#define mylib_pp_for63(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for62(inc(var), pred, inc)) (var)
#define mylib_pp_for64(var, pred, inc)                                 \
    mylib_pp_if(pred(var)) (mylib_pp_for63(inc(var), pred, inc)) (var)
