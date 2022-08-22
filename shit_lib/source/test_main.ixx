module;

//#pragma optimize("", off)

#include <Windows.h>
//#include <fast_io.h>
//#include <iostream>
//#include <boost/stacktrace.hpp>
//#include <stacktrace>
//#include <iostream>
#include "preprocessor.h"
#include <boost/preprocessor.hpp>


export module mylib.main;

#include "cpp/cxxstd.h"

import mylib;
//import mylib.new_binary_tree;

// ((sum), i) => (sum + 1)
#define plus_inc(tuple, i)                                                              \
    mylib_pp_tuple_set_f(tuple, 0, mylib_pp_inc)

#define plus(left, right)                                                               \
    mylib_pp_forward(                                                                   \
        mylib_pp_for_each(                                                              \
            (left),                                                                     \
            plus_inc,                                                                   \
            mylib_pp_iota(0, right)                                                     \
        )                                                                               \
    )

// ((sum), i) => (sum + i)
#define mul_inc(tuple, i)                                                               \
    mylib_pp_tuple_set(                                                                 \
        tuple,                                                                          \
        0,                                                                              \
        plus(                                                                           \
            mylib_pp_tuple_get(tuple, 0),                                               \
            i                                                                           \
        )                                                                               \
    )

#define mul(left, right)                                                                \
    mylib_pp_tuple_get(                                                                 \
        mylib_pp_for_each((0),                                                          \
            mul_inc,                                                                    \
            mylib_pp_repeat(left, right, mylib_comma)                                   \
        ),                                                                              \
        0                                                                               \
    )

template<typename Type>
concept not_invocable =
    !std::invocable<Type>;

#define var not_invocable auto

export int main() noexcept
{
    using mylib::operator <<;
    using namespace mylib::literals;

    var i = 10;
    var l1 = []{};


    return 0;
}
