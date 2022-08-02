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
    struct A{};
    struct B : A{};
    struct C : A{};
    struct D : B, C{};
    union x{};
    
    std::cout << mylib::is_base_of_v<A, D>;

    return 0;
}

