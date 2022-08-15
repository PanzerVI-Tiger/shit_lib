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

//import mylib;


export int main() noexcept
{
    //using namespace mylib::literals;
    
    constexpr int arr[]{ mylib_pp_variadic_slice(2, 5, mylib_pp_iota(0, 10)) };
    
    return 0;
}
