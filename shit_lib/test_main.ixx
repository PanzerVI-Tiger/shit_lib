module;

//#pragma optimize("", off)
#include <Windows.h>
#include <stdio.h>
//#include "mylib_assert.h"
//#include <string>
//#include <fast_io.h>

export module mylib.main;

import std.core;
import mylib;


export int main() noexcept
{
    using namespace mylib::string_literals;
    using mylib::operator <<;
    
    int i = 0;

    return 0;
}
