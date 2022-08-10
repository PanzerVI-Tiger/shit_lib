module;

//#pragma optimize("", off)

//#include <fast_io.h>

export module mylib.main;

#include "cxxstd.h"

import mylib;


export int main() noexcept
{
    struct X {
        operator int() noexcept {}
    };
    mylib::is_nothrow_convertible_v<X, int>;

    mylib::is_object_v<

    //std::cout << se.source_line();
    return 0;
}
