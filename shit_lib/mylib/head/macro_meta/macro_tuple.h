#pragma once


#define mylib_macro_tuple_size_helper(                                         \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, \
    e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, \
    e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, \
    e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, \
    e62, e63, e64, en, ...                                                     \
    ) en

#ifdef __cplusplus

#define mylib_macro_tuple_size(...)                                             \
    mylib_macro_tuple_size_helper(                                              \
        0, __VA_ARGS__ __VA_OPT__(,)                                            \
        64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, \
        46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32 ,31, 30, 29, \
        28, 27, 26, 25, 24 ,23, 22, 21 ,20, 19 ,18, 17, 16, 15, 14, 13, 12, 11, \
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0                                        \
    )

#elif defined(_MSC_VER)

// need compiler extension `, ## __VA_ARGS__`
#define mylib_macro_tuple_size(...)                                             \
    mylib_macro_tuple_size_helper(                                              \
        , ## __VA_ARGS__,                                                       \
        64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, \
        46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32 ,31, 30, 29, \
        28, 27, 26, 25, 24 ,23, 22, 21 ,20, 19 ,18, 17, 16, 15, 14, 13, 12, 11, \
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0                                        \
    )

#else

// when params is empty will return 1!!!
#define mylib_macro_tuple_size(...)                                             \
    mylib_macro_tuple_size_helper(                                              \
        , __VA_ARGS__,                                                          \
        64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, \
        46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32 ,31, 30, 29, \
        28, 27, 26, 25, 24 ,23, 22, 21 ,20, 19 ,18, 17, 16, 15, 14, 13, 12, 11, \
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0                                        \
    )

#endif

#define mylib_macro_take_tuple0(\
        ...                     \
    )
#define mylib_macro_take_tuple1(\
        e0, ...                 \
    )                           \
    e0
#define mylib_macro_take_tuple2(\
        e0, e1, ...             \
    )                           \
    e0, e1
#define mylib_macro_take_tuple3(\
        e0, e1, e2, ...         \
    )                           \
    e0, e1, e2
#define mylib_macro_take_tuple4(\
        e0, e1, e2, e3, ...     \
    )                           \
    e0, e1, e2, e3
#define mylib_macro_take_tuple5(\
        e0, e1, e2, e3, e4, ... \
    )                           \
    e0, e1, e2, e3, e4
#define mylib_macro_take_tuple6(   \
        e0, e1, e2, e3, e4, e5, ...\
    )                              \
    e0, e1, e2, e3, e4, e5
#define mylib_macro_take_tuple7(       \
        e0, e1, e2, e3, e4, e5, e6, ...\
    )                                  \
    e0, e1, e2, e3, e4, e5, e6
#define mylib_macro_take_tuple8(           \
        e0, e1, e2, e3, e4, e5, e6, e7, ...\
    )                                      \
    e0, e1, e2, e3, e4, e5, e6, e7
#define mylib_macro_take_tuple9(               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, ...\
    )                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8
#define mylib_macro_take_tuple10(                  \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, ...\
    )                                              \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9
#define mylib_macro_take_tuple11(                       \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, ...\
    )                                                   \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10
#define mylib_macro_take_tuple12(                            \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, ...\
    )                                                        \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11
#define mylib_macro_take_tuple13(                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, \
        ...                                                    \
    )                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12
#define mylib_macro_take_tuple14(                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, \
        e13, ...                                               \
    )                                                          \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13
#define mylib_macro_take_tuple15(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, ...                                           \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e12, e13, e14, \
    e15
#define mylib_macro_take_tuple16(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, ...                                      \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15
#define mylib_macro_take_tuple17(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, ...                                 \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16
#define mylib_macro_take_tuple18(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, ...                            \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17
#define mylib_macro_take_tuple19(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, ...                       \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17, e18
#define mylib_macro_take_tuple20(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, ...                  \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17, e18, e19
#define mylib_macro_take_tuple21(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, ...             \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17, e18, e19, e20
#define mylib_macro_take_tuple22(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, ...        \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17, e18, e19, e20, e21
#define mylib_macro_take_tuple23(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, ...   \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17, e18, e19, e20, e21, e22
#define mylib_macro_take_tuple24(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        ...                                                     \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17, e18, e19, e20, e21, e22, e23
#define mylib_macro_take_tuple25(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, ...                                                \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24
#define mylib_macro_take_tuple26(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, e25, ...                                           \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25
#define mylib_macro_take_tuple27(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, e25, e26, ...                                      \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, \
    e26
#define mylib_macro_take_tuple28(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, e25, e26, e27, ...                                 \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, \
    e26, e27
#define mylib_macro_take_tuple29(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, e25, e26, e27, e28, ...                            \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, \
    e26, e27, e28
#define mylib_macro_take_tuple30(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, e25, e26, e27, e28, e29, ...                       \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, \
    e26, e27, e28, e29
#define mylib_macro_take_tuple31(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, e25, e26, e27, e28, e29, e30, ...                  \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, \
    e26, e27, e28, e29, e30
#define mylib_macro_take_tuple32(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, e25, e26, e27, e28, e29, e30, e31, ...             \
    )                                                           \
    e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, \
    e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, \
    e26, e27, e28, e29, e30, e31

#define mylib_macro_take_tuple(count, ...) \
    mylib_macro_take_tuple ## count(__VA_ARGS__)

#define mylib_macro_drop_tuple0(\
        ...                     \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple1(\
        e0, ...                 \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple2(\
        e0, e1, ...             \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple3(\
        e0, e1, e2, ...         \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple4(\
        e0, e1, e2, e3, ...     \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple5(\
        e0, e1, e2, e3, e4, ... \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple6(   \
        e0, e1, e2, e3, e4, e5, ...\
    ) __VA_ARGS__
#define mylib_macro_drop_tuple7(       \
        e0, e1, e2, e3, e4, e5, e6, ...\
    ) __VA_ARGS__
#define mylib_macro_drop_tuple8(           \
        e0, e1, e2, e3, e4, e5, e6, e7, ...\
    ) __VA_ARGS__
#define mylib_macro_drop_tuple9(               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, ...\
    ) __VA_ARGS__
#define mylib_macro_drop_tuple10(                  \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, ...\
    ) __VA_ARGS__
#define mylib_macro_drop_tuple11(                       \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, ...\
    ) __VA_ARGS__
#define mylib_macro_drop_tuple12(                            \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, ...\
    ) __VA_ARGS__
#define mylib_macro_drop_tuple13(                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, \
        ...                                                    \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple14(                              \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, \
        e13, ...                                               \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple15(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, ...                                           \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple16(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, ...                                      \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple17(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, ...                                 \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple18(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, ...                            \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple19(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, ...                       \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple20(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, ...                  \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple21(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, ...             \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple22(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, ...        \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple23(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, ...   \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple24(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        ...                                                     \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple25(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, ...                                                \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple26(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, e25, ...                                           \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple27(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, e25, e26, ...                                      \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple28(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, e25, e26, e27, ...                                 \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple29(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, e25, e26, e27, e28, ...                            \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple30(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, e25, e26, e27, e28, e29, ...                       \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple31(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, e25, e26, e27, e28, e29, e30, ...                  \
    ) __VA_ARGS__
#define mylib_macro_drop_tuple32(                               \
        e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12,  \
        e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23,  \
        e24, e25, e26, e27, e28, e29, e30, e31, ...             \
    ) __VA_ARGS__

#define mylib_macro_drop_tuple(count, ...) \
    mylib_macro_drop_tuple ## count(__VA_ARGS__)
