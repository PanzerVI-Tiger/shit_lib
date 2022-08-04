module;

#pragma optimize("", off)
#include <Windows.h>
#include <stdio.h>
//#include "mylib_assert.h"
//#include <execution>

export module mylib.main;

import mylib;
import std.core;


export int main() noexcept
{
    using namespace mylib::literals;
    using mylib::operator <<;
    
    constexpr auto x = "ss"_ss;

    //std::cout << x << ", " << x.size() << std::endl;
    
    return 0;
}
