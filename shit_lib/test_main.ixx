module;

//#pragma optimize("", off)
#include <Windows.h>
#include <stdio.h>
#include "mylib_assert.h"
//#include <execution>

export module mylib.main;

import std.core;
import mylib;

export int main() noexcept
{
    using mylib::operator<<;
    
    struct A {
        int         nmb;
        std::string cnm;
    } a{ 1, "fuck" };

    struct B {
        int sb;
        int gb[4];
        int bb;
    } b{ 1, { 1, 2, 3, 4 }, 8 };
    
    std::cout << mylib::get<1>(b);
    
	return 0;
}
