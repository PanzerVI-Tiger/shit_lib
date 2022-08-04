module;

#pragma optimize("", off)
#include <Windows.h>
#include <stdio.h>
//#include "mylib_assert.h"
//#include <execution>

export module mylib.main;

import mylib;
import std.core;

template<char... chars>
constexpr auto operator ""_sb() noexcept {
    return std::string{ chars... };
}

export int main() noexcept
{
    using namespace mylib::string_literals;
    using mylib::operator <<;
    
    constexpr auto x = "ss"_ss;
    
    //std::cout << x << ", " << x.size() << std::endl;
    
    return 0;
}
