module;

//#pragma optimize("", off)
#include <Windows.h>
#include <stdio.h>
#include "mylib_assert.h"
//#include <execution>

export module mylib.main;

import std.core;
import mylib;

template<typename Type1, typename Type2>
constexpr void fuck(Type1 t1, Type2 t2) noexcept 
{
    []<typename Type1>(Type1 t1, Type2 t2) constexpr noexcept {
    }(t2, t2);
}

export int main() noexcept
{
    struct Fuck{};
    
    fuck(1, Fuck{});
    
    return 0;
}

