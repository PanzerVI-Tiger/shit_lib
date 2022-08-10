module;

//#pragma optimize("", off)
//#include <Windows.h>
//#include <stdio.h>
//#include "mylib_assert.h"
//#include <string>
//#include <fast_io.h>
//#include <format>
//#include <type_traits>
//#include <stacktrace>

export module mylib.main;

import mylib;

#include "cxxstd.h"

export int main() noexcept
{
    using mylib::operator <<;
    
    struct X {
        std::tuple<int, double> t;
        int i[10][10];
    } x{ { 1, 55.66 } };
    
    auto z = stdr::iota((int(&)[100])(x.i), 0);
    
    //std::cout << mylib::aggregate_to_string(x);
    
    std::stacktrace_entry se;
    
    std::cout << se.description();
    
    return 0;
}
