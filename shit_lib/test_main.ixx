module;

//#pragma optimize("", off)
#include <Windows.h>
#include <stdio.h>
//#include "mylib_assert.h"
//#include <type_traits>

export module mylib.main;

import std.core;
import mylib;


export int main() noexcept
{
    using namespace mylib::string_literals;
    using mylib::operator <<;

    "sss"_ss;
    
    return 0;
}
