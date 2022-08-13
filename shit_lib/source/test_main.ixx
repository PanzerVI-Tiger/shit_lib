module;

//#pragma optimize("", off)

//#include <Windows.h>
//#include <fast_io.h>
//#include <iostream>
//#include <boost\stacktrace.hpp>

export module mylib.main;

#include "cpp/cxxstd.h"
#include "macro_meta.h"

import mylib;
int i = 0;
int j = i;

#define x(a) #a
#define y(...) #__VA_ARGS__
#define z(...) y(__VA_ARGS__)
export int main() noexcept
{
    using namespace mylib::literals;

    int a = 1, b = 1;
    0 ? a : b = 0;
    std::cout << z(mylib_macro_drop_tuple(2, 1, 2, 3, 4));
    
    return 0;
}
