#pragma once

#include "if.hpp"
#include "variadic.hpp"

#define mylib_pp_for_each_impl(count, var, inc, ...)                                    \
    mylib_pp_for_each ## count(var, inc, __VA_ARGS__)                                   
#define mylib_pp_for_each_n(count, var, inc, ...)                                       \
    mylib_pp_for_each_impl(count, var, inc, __VA_ARGS__)                                
#define mylib_pp_for_each(var, inc, ...)                                                \
    mylib_pp_for_each_n(                                                                \
        mylib_pp_variadic_size(__VA_ARGS__),                                            \
        var,                                                                            \
        inc,                                                                            \
        __VA_ARGS__                                                                     \
    )                                                                                   
                                                                                        
#define mylib_pp_for_impl(var, pred, inc)                                               \
    mylib_pp_for64(var, pred, inc)                                                      
#define mylib_pp_for(var, pred, inc)                                                    \
    mylib_pp_for_impl(var, pred, inc)                                                   
                                                                                        
#define mylib_pp_for_each0(                                                             \
        var, inc, ...                                                                   \
    )                                                                                   \
    var                                                                                 
#define mylib_pp_for_each1(                                                             \
        var, inc, e0, ...                                                               \
    )                                                                                   \
    inc(var, e0)
#define mylib_pp_for_each2(                                                             \
        var, inc, e0, e1, ...                                                           \
    )                                                                                   \
    inc(inc(var, e0), e1)                                                               
#define mylib_pp_for_each3(                                                             \
        var, inc, e0, e1, e2, ...                                                       \
    )                                                                                   \
    inc(inc(inc(var, e0), e1), e2)                                                      
#define mylib_pp_for_each4(                                                             \
        var, inc, e0, e1, e2, e3, ...                                                   \
    )                                                                                   \
    inc(inc(inc(inc(var, e0), e1), e2), e3)                                             
#define mylib_pp_for_each5(                                                             \
        var, inc, e0, e1, e2, e3, e4, ...                                               \
    )                                                                                   \
    inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4)                                    
#define mylib_pp_for_each6(                                                             \
        var, inc, e0, e1, e2, e3, e4, e5, ...                                           \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5)
#define mylib_pp_for_each7(                                                             \
        var, inc, e0, e1, e2, e3, e4, e5, e6, ...                                       \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6)
#define mylib_pp_for_each8(                                                             \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, ...                                   \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7)
#define mylib_pp_for_each9(                                                             \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, ...                               \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7),    \
    e8)
#define mylib_pp_for_each10(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, ...                           \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6),     \
    e7), e8), e9)
#define mylib_pp_for_each11(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, ...                      \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), \
    e7), e8), e9), e10)
#define mylib_pp_for_each12(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, ...                 \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5),  \
    e6), e7), e8), e9), e10), e11)
#define mylib_pp_for_each13(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, ...            \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4),   \
    e5), e6), e7), e8), e9), e10), e11), e12)                                      
#define mylib_pp_for_each14(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, ...       \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3),    \
    e4), e5), e6), e7), e8), e9), e10), e11), e12), e13)                           
#define mylib_pp_for_each15(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, ...  \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2),     \
    e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14)                     
#define mylib_pp_for_each16(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        ...                                                                             \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), \
    e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15)
#define mylib_pp_for_each17(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, ...                                                                        \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0),       \
    e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15),    \
    e16)                                                                                
#define mylib_pp_for_each18(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, ...                                                                   \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0),   \
    e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15),    \
    e16), e17)
#define mylib_pp_for_each19(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14,      \
        e15, e16, e17, e18, ...                                                         \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var,    \
    e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14),     \
    e15), e16), e17), e18)                                                              
#define mylib_pp_for_each20(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, ...                                                         \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13),      \
    e14), e15), e16), e17), e18), e19)
#define mylib_pp_for_each21(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14,      \
        e15, e16, e17, e18, e19, e20, ...                                               \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13),  \
    e14), e15), e16), e17), e18), e19), e20)                                            
#define mylib_pp_for_each22(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, ...                                               \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12),    \
    e13), e14), e15), e16), e17), e18), e19), e20), e21)                                
#define mylib_pp_for_each23(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, ...                                          \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11),      \
    e12), e13), e14), e15), e16), e17), e18), e19), e20), e21), e22)
#define mylib_pp_for_each24(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, ...                                     \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11),  \
    e12), e13), e14), e15), e16), e17), e18), e19), e20), e21), e22), e23)              
#define mylib_pp_for_each25(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14,      \
        e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, ...                           \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10),    \
    e11), e12), e13), e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), e24)
#define mylib_pp_for_each26(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, ...                           \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9),      \
    e10), e11), e12), e13), e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), \
    e24), e25)
#define mylib_pp_for_each27(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, ...                      \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9),  \
    e10), e11), e12), e13), e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), \
    e24), e25), e26)
#define mylib_pp_for_each28(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, ...                 \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8),   \
    e9), e10), e11), e12), e13), e14), e15), e16), e17), e18), e19), e20), e21), e22),  \
    e23), e24), e25), e26), e27)
#define mylib_pp_for_each29(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, ...            \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7),    \
    e8), e9), e10), e11), e12), e13), e14), e15), e16), e17), e18), e19), e20), e21),   \
    e22), e23), e24), e25), e26), e27), e28)
#define mylib_pp_for_each30(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, ...       \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6),     \
    e7), e8), e9), e10), e11), e12), e13), e14), e15), e16), e17), e18), e19), e20),    \
    e21), e22), e23), e24), e25), e26), e27), e28), e29)
#define mylib_pp_for_each31(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, ...  \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), \
    e7), e8), e9), e10), e11), e12), e13), e14), e15), e16), e17), e18), e19), e20),    \
    e21), e22), e23), e24), e25), e26), e27), e28), e29), e30)
#define mylib_pp_for_each32(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        ...                                                                             \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5),  \
    e6), e7), e8), e9), e10), e11), e12), e13), e14), e15), e16), e17), e18), e19),     \
    e20), e21), e22), e23), e24), e25), e26), e27), e28), e29), e30), e31)
#define mylib_pp_for_each33(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, ...                                                                        \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4),   \
    e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15), e16), e17), e18),      \
    e19), e20), e21), e22), e23), e24), e25), e26), e27), e28), e29), e30), e31), e32)
#define mylib_pp_for_each34(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, ...                                                                   \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3),    \
    e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15), e16), e17), e18), \
    e19), e20), e21), e22), e23), e24), e25), e26), e27), e28), e29), e30), e31), e32), \
    e33)
#define mylib_pp_for_each35(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, ...                                                              \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2),     \
    e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15), e16), e17),  \
    e18), e19), e20), e21), e22), e23), e24), e25), e26), e27), e28), e29), e30), e31), \
    e32), e33), e34)
#define mylib_pp_for_each36(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, ...                                                         \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), \
    e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15), e16), e17),  \
    e18), e19), e20), e21), e22), e23), e24), e25), e26), e27), e28), e29), e30), e31), \
    e32), e33), e34), e35)
#define mylib_pp_for_each37(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, ...                                                    \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1),  \
    e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15), e16),   \
    e17), e18), e19), e20), e21), e22), e23), e24), e25), e26), e27), e28), e29), e30), \
    e31), e32), e33), e34), e35), e36)
#define mylib_pp_for_each38(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, ...                                               \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0),   \
    e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15),    \
    e16), e17), e18), e19), e20), e21), e22), e23), e24), e25), e26), e27), e28), e29), \
    e30), e31), e32), e33), e34), e35), e36), e37)
#define mylib_pp_for_each39(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, ...                                          \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var,    \
    e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14),     \
    e15), e16), e17), e18), e19), e20), e21), e22), e23), e24), e25), e26), e27), e28), \
    e29), e30), e31), e32), e33), e34), e35), e36), e37), e38)
#define mylib_pp_for_each40(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, ...                                     \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13),      \
    e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), e24), e25), e26), e27), \
    e28), e29), e30), e31), e32), e33), e34), e35), e36), e37), e38), e39)
#define mylib_pp_for_each41(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, ...                                \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13),  \
    e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), e24), e25), e26), e27), \
    e28), e29), e30), e31), e32), e33), e34), e35), e36), e37), e38), e39), e40)
#define mylib_pp_for_each42(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, ...                           \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12),    \
    e13), e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), e24), e25), e26), \
    e27), e28), e29), e30), e31), e32), e33), e34), e35), e36), e37), e38), e39), e40), \
    e41)
#define mylib_pp_for_each43(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, ...                      \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11),      \
    e12), e13), e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), e24), e25), \
    e26), e27), e28), e29), e30), e31), e32), e33), e34), e35), e36), e37), e38), e39), \
    e40), e41), e42)
#define mylib_pp_for_each44(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, ...                 \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11),  \
    e12), e13), e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), e24), e25), \
    e26), e27), e28), e29), e30), e31), e32), e33), e34), e35), e36), e37), e38), e39), \
    e40), e41), e42), e43)
#define mylib_pp_for_each45(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, ...            \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10),    \
    e11), e12), e13), e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), e24), \
    e25), e26), e27), e28), e29), e30), e31), e32), e33), e34), e35), e36), e37), e38), \
    e39), e40), e41), e42), e43), e44)
#define mylib_pp_for_each46(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, ...       \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9),      \
    e10), e11), e12), e13), e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), \
    e24), e25), e26), e27), e28), e29), e30), e31), e32), e33), e34), e35), e36), e37), \
    e38), e39), e40), e41), e42), e43), e44), e45)
#define mylib_pp_for_each47(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, ...  \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9),  \
    e10), e11), e12), e13), e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), \
    e24), e25), e26), e27), e28), e29), e30), e31), e32), e33), e34), e35), e36), e37), \
    e38), e39), e40), e41), e42), e43), e44), e45), e46)
#define mylib_pp_for_each48(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        ...                                                                             \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8),   \
    e9), e10), e11), e12), e13), e14), e15), e16), e17), e18), e19), e20), e21), e22),  \
    e23), e24), e25), e26), e27), e28), e29), e30), e31), e32), e33), e34), e35), e36), \
    e37), e38), e39), e40), e41), e42), e43), e44), e45), e46), e47)
#define mylib_pp_for_each49(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, ...                                                                        \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7),    \
    e8), e9), e10), e11), e12), e13), e14), e15), e16), e17), e18), e19), e20), e21),   \
    e22), e23), e24), e25), e26), e27), e28), e29), e30), e31), e32), e33), e34), e35), \
    e36), e37), e38), e39), e40), e41), e42), e43), e44), e45), e46), e47), e48)
#define mylib_pp_for_each50(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, ...                                                                   \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6),     \
    e7), e8), e9), e10), e11), e12), e13), e14), e15), e16), e17), e18), e19), e20),    \
    e21), e22), e23), e24), e25), e26), e27), e28), e29), e30), e31), e32), e33), e34), \
    e35), e36), e37), e38), e39), e40), e41), e42), e43), e44), e45), e46), e47), e48), \
    e49)
#define mylib_pp_for_each51(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, ...                                                              \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), \
    e7), e8), e9), e10), e11), e12), e13), e14), e15), e16), e17), e18), e19), e20),    \
    e21), e22), e23), e24), e25), e26), e27), e28), e29), e30), e31), e32), e33), e34), \
    e35), e36), e37), e38), e39), e40), e41), e42), e43), e44), e45), e46), e47), e48), \
    e49), e50)
#define mylib_pp_for_each52(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, ...                                                         \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5),  \
    e6), e7), e8), e9), e10), e11), e12), e13), e14), e15), e16), e17), e18), e19),     \
    e20), e21), e22), e23), e24), e25), e26), e27), e28), e29), e30), e31), e32), e33), \
    e34), e35), e36), e37), e38), e39), e40), e41), e42), e43), e44), e45), e46), e47), \
    e48), e49), e50), e51)
#define mylib_pp_for_each53(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, ...                                                    \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3), e4),   \
    e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15), e16), e17), e18),      \
    e19), e20), e21), e22), e23), e24), e25), e26), e27), e28), e29), e30), e31), e32), \
    e33), e34), e35), e36), e37), e38), e39), e40), e41), e42), e43), e44), e45), e46), \
    e47), e48), e49), e50), e51), e52)
#define mylib_pp_for_each54(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, ...                                               \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), e3),    \
    e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15), e16), e17), e18), \
    e19), e20), e21), e22), e23), e24), e25), e26), e27), e28), e29), e30), e31), e32), \
    e33), e34), e35), e36), e37), e38), e39), e40), e41), e42), e43), e44), e45), e46), \
    e47), e48), e49), e50), e51), e52), e53)
#define mylib_pp_for_each55(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, ...                                          \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2),     \
    e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15), e16), e17),  \
    e18), e19), e20), e21), e22), e23), e24), e25), e26), e27), e28), e29), e30), e31), \
    e32), e33), e34), e35), e36), e37), e38), e39), e40), e41), e42), e43), e44), e45), \
    e46), e47), e48), e49), e50), e51), e52), e53), e54)
#define mylib_pp_for_each56(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, ...                                     \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1), e2), \
    e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15), e16), e17),  \
    e18), e19), e20), e21), e22), e23), e24), e25), e26), e27), e28), e29), e30), e31), \
    e32), e33), e34), e35), e36), e37), e38), e39), e40), e41), e42), e43), e44), e45), \
    e46), e47), e48), e49), e50), e51), e52), e53), e54), e55)
#define mylib_pp_for_each57(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, ...                                \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0), e1),  \
    e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15), e16),   \
    e17), e18), e19), e20), e21), e22), e23), e24), e25), e26), e27), e28), e29), e30), \
    e31), e32), e33), e34), e35), e36), e37), e38), e39), e40), e41), e42), e43), e44), \
    e45), e46), e47), e48), e49), e50), e51), e52), e53), e54), e55), e56)
#define mylib_pp_for_each58(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, ...                           \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var, e0),   \
    e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14), e15),    \
    e16), e17), e18), e19), e20), e21), e22), e23), e24), e25), e26), e27), e28), e29), \
    e30), e31), e32), e33), e34), e35), e36), e37), e38), e39), e40), e41), e42), e43), \
    e44), e45), e46), e47), e48), e49), e50), e51), e52), e53), e54), e55), e56), e57)
#define mylib_pp_for_each59(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, ...                      \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(var,    \
    e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13), e14),     \
    e15), e16), e17), e18), e19), e20), e21), e22), e23), e24), e25), e26), e27), e28), \
    e29), e30), e31), e32), e33), e34), e35), e36), e37), e38), e39), e40), e41), e42), \
    e43), e44), e45), e46), e47), e48), e49), e50), e51), e52), e53), e54), e55), e56), \
    e57), e58)
#define mylib_pp_for_each60(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, ...                 \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13),      \
    e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), e24), e25), e26), e27), \
    e28), e29), e30), e31), e32), e33), e34), e35), e36), e37), e38), e39), e40), e41), \
    e42), e43), e44), e45), e46), e47), e48), e49), e50), e51), e52), e53), e54), e55), \
    e56), e57), e58), e59)
#define mylib_pp_for_each61(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, ...            \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12), e13),  \
    e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), e24), e25), e26), e27), \
    e28), e29), e30), e31), e32), e33), e34), e35), e36), e37), e38), e39), e40), e41), \
    e42), e43), e44), e45), e46), e47), e48), e49), e50), e51), e52), e53), e54), e55), \
    e56), e57), e58), e59), e60)
#define mylib_pp_for_each62(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, ...       \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11), e12),    \
    e13), e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), e24), e25), e26), \
    e27), e28), e29), e30), e31), e32), e33), e34), e35), e36), e37), e38), e39), e40), \
    e41), e42), e43), e44), e45), e46), e47), e48), e49), e50), e51), e52), e53), e54), \
    e55), e56), e57), e58), e59), e60), e61)
#define mylib_pp_for_each63(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, ...  \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11),      \
    e12), e13), e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), e24), e25), \
    e26), e27), e28), e29), e30), e31), e32), e33), e34), e35), e36), e37), e38), e39), \
    e40), e41), e42), e43), e44), e45), e46), e47), e48), e49), e50), e51), e52), e53), \
    e54), e55), e56), e57), e58), e59), e60), e61), e62)
#define mylib_pp_for_each64(                                                            \
        var, inc, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, \
        e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63, \
        ...                                                                             \
    )                                                                                   \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(inc(    \
    inc(inc(inc(inc(var, e0), e1), e2), e3), e4), e5), e6), e7), e8), e9), e10), e11),  \
    e12), e13), e14), e15), e16), e17), e18), e19), e20), e21), e22), e23), e24), e25), \
    e26), e27), e28), e29), e30), e31), e32), e33), e34), e35), e36), e37), e38), e39), \
    e40), e41), e42), e43), e44), e45), e46), e47), e48), e49), e50), e51), e52), e53), \
    e54), e55), e56), e57), e58), e59), e60), e61), e62), e63)

#define mylib_pp_for0(var, pred, inc)                                                   \
    var                                                  
#define mylib_pp_for1(var, pred, inc)                                                   \
    mylib_pp_if(pred(var)) (mylib_pp_for0(inc(var), pred, inc)) (var)                   
#define mylib_pp_for2(var, pred, inc)                                                   \
    mylib_pp_if(pred(var)) (mylib_pp_for1(inc(var), pred, inc)) (var)                   
#define mylib_pp_for3(var, pred, inc)                                                   \
    mylib_pp_if(pred(var)) (mylib_pp_for2(inc(var), pred, inc)) (var)                   
#define mylib_pp_for4(var, pred, inc)                                                   \
    mylib_pp_if(pred(var)) (mylib_pp_for3(inc(var), pred, inc)) (var)                   
#define mylib_pp_for5(var, pred, inc)                                                   \
    mylib_pp_if(pred(var)) (mylib_pp_for4(inc(var), pred, inc)) (var)                   
#define mylib_pp_for6(var, pred, inc)                                                   \
    mylib_pp_if(pred(var)) (mylib_pp_for5(inc(var), pred, inc)) (var)                   
#define mylib_pp_for7(var, pred, inc)                                                   \
    mylib_pp_if(pred(var)) (mylib_pp_for6(inc(var), pred, inc)) (var)                   
#define mylib_pp_for8(var, pred, inc)                                                   \
    mylib_pp_if(pred(var)) (mylib_pp_for7(inc(var), pred, inc)) (var)                   
#define mylib_pp_for9(var, pred, inc)                                                   \
    mylib_pp_if(pred(var)) (mylib_pp_for8(inc(var), pred, inc)) (var)                   
#define mylib_pp_for10(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for9(inc(var), pred, inc)) (var)
#define mylib_pp_for11(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for10(inc(var), pred, inc)) (var)
#define mylib_pp_for12(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for11(inc(var), pred, inc)) (var)
#define mylib_pp_for13(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for12(inc(var), pred, inc)) (var)
#define mylib_pp_for14(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for13(inc(var), pred, inc)) (var)
#define mylib_pp_for15(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for14(inc(var), pred, inc)) (var)
#define mylib_pp_for16(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for15(inc(var), pred, inc)) (var)
#define mylib_pp_for17(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for16(inc(var), pred, inc)) (var)
#define mylib_pp_for18(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for17(inc(var), pred, inc)) (var)
#define mylib_pp_for19(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for18(inc(var), pred, inc)) (var)
#define mylib_pp_for20(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for19(inc(var), pred, inc)) (var)
#define mylib_pp_for21(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for20(inc(var), pred, inc)) (var)
#define mylib_pp_for22(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for21(inc(var), pred, inc)) (var)
#define mylib_pp_for23(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for22(inc(var), pred, inc)) (var)
#define mylib_pp_for24(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for23(inc(var), pred, inc)) (var)
#define mylib_pp_for25(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for24(inc(var), pred, inc)) (var)
#define mylib_pp_for26(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for25(inc(var), pred, inc)) (var)
#define mylib_pp_for27(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for26(inc(var), pred, inc)) (var)
#define mylib_pp_for28(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for27(inc(var), pred, inc)) (var)
#define mylib_pp_for29(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for28(inc(var), pred, inc)) (var)
#define mylib_pp_for30(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for29(inc(var), pred, inc)) (var)
#define mylib_pp_for31(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for30(inc(var), pred, inc)) (var)
#define mylib_pp_for32(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for31(inc(var), pred, inc)) (var)
#define mylib_pp_for33(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for32(inc(var), pred, inc)) (var)
#define mylib_pp_for34(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for33(inc(var), pred, inc)) (var)
#define mylib_pp_for35(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for34(inc(var), pred, inc)) (var)
#define mylib_pp_for36(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for35(inc(var), pred, inc)) (var)
#define mylib_pp_for37(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for36(inc(var), pred, inc)) (var)
#define mylib_pp_for38(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for37(inc(var), pred, inc)) (var)
#define mylib_pp_for39(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for38(inc(var), pred, inc)) (var)
#define mylib_pp_for40(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for39(inc(var), pred, inc)) (var)
#define mylib_pp_for41(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for40(inc(var), pred, inc)) (var)
#define mylib_pp_for42(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for41(inc(var), pred, inc)) (var)
#define mylib_pp_for43(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for42(inc(var), pred, inc)) (var)
#define mylib_pp_for44(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for43(inc(var), pred, inc)) (var)
#define mylib_pp_for45(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for44(inc(var), pred, inc)) (var)
#define mylib_pp_for46(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for45(inc(var), pred, inc)) (var)
#define mylib_pp_for47(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for46(inc(var), pred, inc)) (var)
#define mylib_pp_for48(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for47(inc(var), pred, inc)) (var)
#define mylib_pp_for49(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for48(inc(var), pred, inc)) (var)
#define mylib_pp_for50(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for49(inc(var), pred, inc)) (var)
#define mylib_pp_for51(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for50(inc(var), pred, inc)) (var)
#define mylib_pp_for52(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for51(inc(var), pred, inc)) (var)
#define mylib_pp_for53(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for52(inc(var), pred, inc)) (var)
#define mylib_pp_for54(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for53(inc(var), pred, inc)) (var)
#define mylib_pp_for55(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for54(inc(var), pred, inc)) (var)
#define mylib_pp_for56(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for55(inc(var), pred, inc)) (var)
#define mylib_pp_for57(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for56(inc(var), pred, inc)) (var)
#define mylib_pp_for58(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for57(inc(var), pred, inc)) (var)
#define mylib_pp_for59(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for58(inc(var), pred, inc)) (var)
#define mylib_pp_for60(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for59(inc(var), pred, inc)) (var)
#define mylib_pp_for61(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for60(inc(var), pred, inc)) (var)
#define mylib_pp_for62(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for61(inc(var), pred, inc)) (var)
#define mylib_pp_for63(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for62(inc(var), pred, inc)) (var)
#define mylib_pp_for64(var, pred, inc)                                                  \
    mylib_pp_if(pred(var)) (mylib_pp_for63(inc(var), pred, inc)) (var)
