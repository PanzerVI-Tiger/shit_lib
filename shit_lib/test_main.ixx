module;

//#pragma optimize("", off)
#include <Windows.h>
#include <stdio.h>
//#include "mylib_assert.h"
//#include <string>
//#include <fast_io.h>
//#include <format>
//#include <xutility>

export module mylib.main;

import std.core;
import mylib;


export int main() noexcept
{
    using namespace mylib::string_literals;
    using mylib::operator <<;
    
    struct X {
        int i, j, k, l, m, n, o, p, q, r, s, t, u;
        int h[10];
    } static x;
    
    std::cout << mylib::aggregate_to_string(x);
    
    return 0;
}
