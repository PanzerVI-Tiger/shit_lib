module;

//#pragma optimize("", off)

//#include <Windows.h>
//#include <fast_io.h>
//#include <iostream>
//#include <boost/stacktrace.hpp>

export module mylib.main;

#include "cpp/cxxstd.h"
#include "preprocessor.h"
#include <boost/preprocessor.hpp>

#define checknil        1
#define checkneq0(c, a) 0
#define checkneq1(c, a) 0

#define neq0(c, a) mylib_pp_if(c) (nil) (a(1, a))
#define neq1(c, a) mylib_pp_if(c) (nil) (a(1, a))
#define neq(a, b)  mylib_pp_cat(check, neq ## a(0, neq ## b))

export int main() noexcept
{
    //using namespace mylib::literals;
    
    constexpr int arr[]{ mylib_pp_variadic_slice(2, 5, mylib_pp_iota(0, 10)) };
    constexpr char str[] = 
        mylib_pp_ttoa(
            mylib_pp_tuple_cat(
                (5, 5, 5),
                (1, 1, 4, 5, 1, 4),
                mylib_pp_tuple_set((mylib_pp_iota(0, 10)), 2, 100)
            )
        );

    std::cout << str;
    
    return 0;
}
