#pragma once


#define mylib_pp_variadic_size_helper(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, \
        e62, e63, e64, en, ...                                                     \
    ) en

#ifdef __cplusplus

#define mylib_pp_variadic_size(...)                                                  \
    mylib_pp_variadic_size_helper(                                                   \
        0, __VA_ARGS__ __VA_OPT__(,)                                                 \
        64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46,  \
        45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32 ,31, 30, 29, 28, 27,  \
        26, 25, 24 ,23, 22, 21 ,20, 19 ,18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, \
        6, 5, 4, 3, 2, 1, 0                                                          \
    )

#elif defined(_MSC_VER)

// need compiler extension `, ## __VA_ARGS__`
#define mylib_pp_variadic_size(...)                                                  \
    mylib_pp_variadic_size_helper(                                                   \
        , ## __VA_ARGS__,                                                            \
        64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46,  \
        45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32 ,31, 30, 29, 28, 27,  \
        26, 25, 24 ,23, 22, 21 ,20, 19 ,18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, \
        6, 5, 4, 3, 2, 1, 0                                                          \
    )

#else

// when params is empty will return 1!!!
#define mylib_pp_variadic_size(...)                                                  \
    mylib_pp_variadic_size_helper(                                                   \
        , __VA_ARGS__,                                                               \
        64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46,  \
        45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32 ,31, 30, 29, 28, 27,  \
        26, 25, 24 ,23, 22, 21 ,20, 19 ,18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, \
        6, 5, 4, 3, 2, 1, 0                                                          \
    )

#endif

#define mylib_pp_variadic_take0(\
        ...                     \
    )
#define mylib_pp_variadic_take1(\
        e0, ...                 \
    )                           \
    e0
#define mylib_pp_variadic_take2(\
        e0, e1, ...             \
    )                           \
    e0, e1
#define mylib_pp_variadic_take3(\
        e0, e1, e2, ...         \
    )                           \
    e0, e1, e2
#define mylib_pp_variadic_take4(\
        e0, e1, e2, e3, ...     \
    )                           \
    e0, e1, e2, e3
#define mylib_pp_variadic_take5(\
        e0, e1, e2, e3, e4, ... \
    )                           \
    e0, e1, e2, e3, e4
#define mylib_pp_variadic_take6(    \
        e0, e1, e2, e3, e4, e5, ... \
    )                               \
    e0, e1, e2, e3, e4, e5
#define mylib_pp_variadic_take7(        \
        e0, e1, e2, e3, e4, e5, e6, ... \
    )                                   \
    e0, e1, e2, e3, e4, e5, e6
#define mylib_pp_variadic_take8(            \
        e0, e1, e2, e3, e4, e5, e6, e7, ... \
    )                                       \
    e0, e1, e2, e3, e4, e5, e6, e7
#define mylib_pp_variadic_take9(                \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, ... \
    )                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8
#define mylib_pp_variadic_take10(                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, ... \
    )                                               \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9
#define mylib_pp_variadic_take11(                        \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, ... \
    )                                                    \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10
#define mylib_pp_variadic_take12(                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, ... \
    )                                                         \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11
#define mylib_pp_variadic_take13(                                  \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, ... \
    )                                                              \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12
#define mylib_pp_variadic_take14(                                       \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, ... \
    )                                                                   \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13
#define mylib_pp_variadic_take15(                                            \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, ... \
    )                                                                        \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e12, e13, e14, e15
#define mylib_pp_variadic_take16(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        ...                                                                   \
    )                                                                         \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15
#define mylib_pp_variadic_take17(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, ...                                                              \
    )                                                                         \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16
#define mylib_pp_variadic_take18(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, ...                                                          \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17
#define mylib_pp_variadic_take19(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, ...                                                     \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18
#define mylib_pp_variadic_take20(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, ...                                                \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19
#define mylib_pp_variadic_take21(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, ...                                           \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20
#define mylib_pp_variadic_take22(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, ...                                      \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21
#define mylib_pp_variadic_take23(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, ...                                 \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22
#define mylib_pp_variadic_take24(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, ...                            \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23
#define mylib_pp_variadic_take25(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, ...                       \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24
#define mylib_pp_variadic_take26(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, ...                  \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25
#define mylib_pp_variadic_take27(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, ...             \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26
#define mylib_pp_variadic_take28(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, ...        \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27
#define mylib_pp_variadic_take29(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, ...   \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28
#define mylib_pp_variadic_take30(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        ...                                                                    \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29
#define mylib_pp_variadic_take31(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, ...                                                               \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30
#define mylib_pp_variadic_take32(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, ...                                                          \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31
#define mylib_pp_variadic_take33(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, ...                                                     \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32
#define mylib_pp_variadic_take34(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, ...                                                \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33
#define mylib_pp_variadic_take35(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, ...                                           \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34
#define mylib_pp_variadic_take36(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, ...                                      \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35
#define mylib_pp_variadic_take37(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, ...                                 \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36
#define mylib_pp_variadic_take38(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, ...                            \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37
#define mylib_pp_variadic_take39(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, ...                       \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38
#define mylib_pp_variadic_take40(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, ...                  \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39
#define mylib_pp_variadic_take41(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, ...             \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40
#define mylib_pp_variadic_take42(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, ...        \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41
#define mylib_pp_variadic_take43(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, ...   \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42
#define mylib_pp_variadic_take44(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        ...                                                                    \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43
#define mylib_pp_variadic_take45(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, ...                                                               \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44
#define mylib_pp_variadic_take46(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, ...                                                          \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45
#define mylib_pp_variadic_take47(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, ...                                                     \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46
#define mylib_pp_variadic_take48(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, ...                                                \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47
#define mylib_pp_variadic_take49(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, ...                                           \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48
#define mylib_pp_variadic_take50(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, ...                                      \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49
#define mylib_pp_variadic_take51(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, e50, ...                                 \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50
#define mylib_pp_variadic_take52(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, e50, e51, ...                            \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50, e51
#define mylib_pp_variadic_take53(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, ...                       \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50, e51, e52
#define mylib_pp_variadic_take54(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, ...                  \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50, e51, e52, e53
#define mylib_pp_variadic_take55(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, ...             \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50, e51, e52, e53, e54
#define mylib_pp_variadic_take56(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, ...        \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50, e51, e52, e53, e54, e55
#define mylib_pp_variadic_take57(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, ...   \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50, e51, e52, e53, e54, e55, e56
#define mylib_pp_variadic_take58(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57,  \
        ...                                                                    \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57
#define mylib_pp_variadic_take59(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57,  \
        e58, ...                                                               \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58
#define mylib_pp_variadic_take60(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57,  \
        e58, e59, ...                                                          \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59
#define mylib_pp_variadic_take61(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57,  \
        e58, e59, e60, ...                                                     \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60
#define mylib_pp_variadic_take62(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57,  \
        e58, e59, e60, e61, ...                                                \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61
#define mylib_pp_variadic_take63(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57,  \
        e58, e59, e60, e61, e62, ...                                           \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, \
    e62
#define mylib_pp_variadic_take64(                                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,  \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29,  \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43,  \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57,  \
        e58, e59, e60, e61, e62, e63, ...                                      \
    )                                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, \
    e62, e63 

#define mylib_pp_variadic_take(count, ...) \
    mylib_pp_variadic_take ## count(__VA_ARGS__)

#define mylib_pp_variadic_drop0(\
        ...                     \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop1(\
        e0, ...                 \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop2(\
        e0, e1, ...             \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop3(\
        e0, e1, e2, ...         \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop4(\
        e0, e1, e2, e3, ...     \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop5(\
        e0, e1, e2, e3, e4, ... \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop6(    \
        e0, e1, e2, e3, e4, e5, ... \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop7(        \
        e0, e1, e2, e3, e4, e5, e6, ... \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop8(            \
        e0, e1, e2, e3, e4, e5, e6, e7, ... \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop9(                \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, ... \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop10(                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, ... \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop11(                        \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, ... \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop12(                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, ... \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop13(                                  \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, ... \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop14(                                       \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, ... \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop15(                                            \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, ... \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop16(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        ...                                                                   \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop17(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, ...                                                              \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop18(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, ...                                                         \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop19(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, ...                                                    \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop20(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, ...                                               \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop21(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, ...                                          \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop22(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, ...                                     \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop23(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, ...                                \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop24(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, ...                           \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop25(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, ...                      \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop26(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, ...                 \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop27(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, ...            \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop28(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, ...       \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop29(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, ...  \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop30(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        ...                                                                   \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop31(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, ...                                                              \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop32(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, ...                                                         \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop33(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, ...                                                    \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop34(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, ...                                               \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop35(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, ...                                          \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop36(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, ...                                     \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop37(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, ...                                \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop38(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, ...                           \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop39(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, ...                      \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop40(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, ...                 \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop41(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, ...            \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop42(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, ...       \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop43(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, ...  \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop44(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        ...                                                                   \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop45(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, ...                                                              \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop46(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, ...                                                         \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop47(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, ...                                                    \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop48(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, ...                                               \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop49(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, ...                                          \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop50(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, ...                                     \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop51(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, e50, ...                                \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop52(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, e50, e51, ...                           \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop53(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, ...                      \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop54(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, ...                 \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop55(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, ...            \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop56(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, ...       \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop57(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, ...  \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop58(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, \
        ...                                                                   \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop59(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, \
        e58, ...                                                              \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop60(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, \
        e58, e59, ...                                                         \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop61(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, \
        e58, e59, e60, ...                                                    \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop62(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, \
        e58, e59, e60, e61, ...                                               \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop63(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, \
        e58, e59, e60, e61, e62, ...                                          \
    ) __VA_ARGS__
#define mylib_pp_variadic_drop64(                                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, \
        e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, \
        e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, \
        e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, \
        e58, e59, e60, e61, e62, e63, ...                                     \
    ) __VA_ARGS__

#define mylib_pp_variadic_drop(count, ...) \
    mylib_pp_variadic_drop ## count(__VA_ARGS__)

#define mylib_pp_variadic_get0(\
        e0, ...                \
    ) e0
#define mylib_pp_variadic_get1(\
        e0, e1, ...            \
    ) e1
#define mylib_pp_variadic_get2(\
        e0, e1, e2, ...        \
    ) e2
#define mylib_pp_variadic_get3(\
        e0, e1, e2, e3, ...    \
    ) e3
#define mylib_pp_variadic_get4( \
        e0, e1, e2, e3, e4, ... \
    ) e4
#define mylib_pp_variadic_get5(     \
        e0, e1, e2, e3, e4, e5, ... \
    ) e5
#define mylib_pp_variadic_get6(         \
        e0, e1, e2, e3, e4, e5, e6, ... \
    ) e6
#define mylib_pp_variadic_get7(             \
        e0, e1, e2, e3, e4, e5, e6, e7, ... \
    ) e7
#define mylib_pp_variadic_get8(                 \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, ... \
    ) e8
#define mylib_pp_variadic_get9(                     \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, ... \
    ) e9
#define mylib_pp_variadic_get10(                         \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, ... \
    ) e10
#define mylib_pp_variadic_get11(                             \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, ...\
    ) e11
#define mylib_pp_variadic_get12(                                  \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, ...\
    ) e12
#define mylib_pp_variadic_get13(                                       \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, ...\
    ) e13
#define mylib_pp_variadic_get14(                                            \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, ...\
    ) e14
#define mylib_pp_variadic_get15(                                                 \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, ...\
    ) e15
#define mylib_pp_variadic_get16(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        ...                                                                        \
    ) e16
#define mylib_pp_variadic_get17(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, ...                                                                   \
    ) e17
#define mylib_pp_variadic_get18(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, ...                                                              \
    ) e18
#define mylib_pp_variadic_get19(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, ...                                                         \
    ) e19
#define mylib_pp_variadic_get20(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, ...                                                    \
    ) e20
#define mylib_pp_variadic_get21(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, ...                                               \
    ) e21
#define mylib_pp_variadic_get22(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, ...                                          \
    ) e22
#define mylib_pp_variadic_get23(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, ...                                     \
    ) e23
#define mylib_pp_variadic_get24(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, ...                                \
    ) e24
#define mylib_pp_variadic_get25(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, ...                           \
    ) e25
#define mylib_pp_variadic_get26(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, ...                      \
    ) e26
#define mylib_pp_variadic_get27(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, ...                 \
    ) e27
#define mylib_pp_variadic_get28(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, ...            \
    ) e28
#define mylib_pp_variadic_get29(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, ...       \
    ) e29
#define mylib_pp_variadic_get30(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, ...  \
    ) e30
#define mylib_pp_variadic_get31(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        ...                                                                        \
    ) e31
#define mylib_pp_variadic_get32(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, ...                                                                   \
    ) e32
#define mylib_pp_variadic_get33(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, ...                                                              \
    ) e33
#define mylib_pp_variadic_get34(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, ...                                                         \
    ) e34
#define mylib_pp_variadic_get35(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, ...                                                    \
    ) e35
#define mylib_pp_variadic_get36(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, ...                                               \
    ) e36
#define mylib_pp_variadic_get37(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, ...                                          \
    ) e37
#define mylib_pp_variadic_get38(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, ...                                     \
    ) e38
#define mylib_pp_variadic_get39(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, ...                                \
    ) e39
#define mylib_pp_variadic_get40(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, ...                           \
    ) e40
#define mylib_pp_variadic_get41(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, ...                      \
    ) e41
#define mylib_pp_variadic_get42(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, ...                 \
    ) e42
#define mylib_pp_variadic_get43(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, ...            \
    ) e43
#define mylib_pp_variadic_get44(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, ...       \
    ) e44
#define mylib_pp_variadic_get45(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, ...  \
    ) e45
#define mylib_pp_variadic_get46(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        ...                                                                        \
    ) e46
#define mylib_pp_variadic_get47(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, ...                                                                   \
    ) e47
#define mylib_pp_variadic_get48(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, ...                                                              \
    ) e48
#define mylib_pp_variadic_get49(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, ...                                                         \
    ) e49
#define mylib_pp_variadic_get50(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, ...                                                    \
    ) e50
#define mylib_pp_variadic_get51(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, e51, ...                                               \
    ) e51
#define mylib_pp_variadic_get52(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, e51, e52, ...                                          \
    ) e52
#define mylib_pp_variadic_get53(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, e51, e52, e53, ...                                     \
    ) e53
#define mylib_pp_variadic_get54(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, e51, e52, e53, e54, ...                                \
    ) e54
#define mylib_pp_variadic_get55(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, e51, e52, e53, e54, e55, ...                           \
    ) e55
#define mylib_pp_variadic_get56(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, ...                      \
    ) e56
#define mylib_pp_variadic_get57(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, ...                 \
    ) e57
#define mylib_pp_variadic_get58(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, ...            \
    ) e58
#define mylib_pp_variadic_get59(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, ...       \
    ) e59
#define mylib_pp_variadic_get60(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, ...  \
    ) e60
#define mylib_pp_variadic_get61(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, \
        ...                                                                        \
    ) e61
#define mylib_pp_variadic_get62(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, \
        e62, ...                                                                   \
    ) e62
#define mylib_pp_variadic_get63(                                                   \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
        e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
        e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
        e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, \
        e62, e63, ...                                                              \
    ) e63

#define mylib_pp_variadic_get(index, ...) \
    mylib_pp_variadic_get ## index(__VA_ARGS__)
