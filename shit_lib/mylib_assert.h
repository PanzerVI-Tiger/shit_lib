#pragma once

#define MYLIB_IDENTIFIER_TO_C_STRING(id) # id

#if defined DEBUG || defined MYLIB_ASSERT


#pragma optimize("", off)
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

import mylib.container_traits;

#define MYLIB_OPTION_ARGUMENT(s)                  , s

#define MYLIB_OPTION_CONTAINER_POINTER            const container_type* container

#define MYLIB_OPTION_CONTAINER_POINTER_PARAMETER  , const container_type* pContainer = nullptr

#define MYLIB_OPTION_CONTAINER_POINTER_ARGUMENT   , pContainer

#define MYLIB_OPTION_CONTAINER_POINTER_INITIALIZE , container{ pContainer }

#define MYLIB_ASSERT_COMMON(condition, message) \
    {if (condition) { \
        fprintf(stderr, \
                "in file:  " __FILE__ ",\n" \
                "function: %s,\n" \
                "line:     %d:\n    " \
                message, \
                __func__, \
                __LINE__ \
        ); \
        abort(); \
    }}

#define MYLIB_OPTION_IS_MYLIB_CLASS(object, condition, message) \
    {if constexpr (mylib::is_mylib_class_v<decltype(object)>) { \
        MYLIB_ASSERT_COMMON(condition, message); \
    }}

    //else { \
    //    fputs("MYLIB_OPTION_IS_MYLIB_CLASS: " #object " is not a mylib class\n", stderr); \
    //    fputs(typeid(object).name(), stderr); \
    //    abort(); \
    //}

#define MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(a, b) \
            MYLIB_OPTION_IS_MYLIB_CLASS( \
                a, \
                (a).container != (b).container, \
                "iterator " #a "'s and " #b "'s containers are not same!\n" \
            )

#define MYLIB_CHECK_ITERATOR_IS_BEGIN(a) \
            MYLIB_OPTION_IS_MYLIB_CLASS( \
                a, \
                (a).container->begin() == (a), \
                "iterator " #a " is begin iterator, can't be decrease!\n" \
            )

#define MYLIB_CHECK_ITERATOR_IS_END(a) \
            MYLIB_OPTION_IS_MYLIB_CLASS( \
                a, \
                (a).container->end() == (a), \
                "iterator " #a " is end iterator, can't be increase, deference or remove!\n" \
            )

#define MYLIB_CHECK_CONTAINER_IS_EMPTY(c) \
            MYLIB_OPTION_IS_MYLIB_CLASS( \
                c, \
                (c).empty(), \
                "container " #c " is empty, not element can be use or remove!!\n" \
            )

#else 

#define MYLIB_OPTION_ARGUMENT(s)
#define MYLIB_OPTION_CONTAINER_POINTER
#define MYLIB_OPTION_CONTAINER_POINTER_PARAMETER
#define MYLIB_OPTION_CONTAINER_POINTER_ARGUMENT
#define MYLIB_OPTION_CONTAINER_POINTER_INITIALIZE
#define MYLIB_ASSERT_COMMON(condition, message)
#define MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(a, b)
#define MYLIB_CHECK_ITERATOR_IS_BEGIN(a)
#define MYLIB_CHECK_ITERATOR_IS_END(a)
#define MYLIB_CHECK_CONTAINER_IS_EMPTY()

#endif