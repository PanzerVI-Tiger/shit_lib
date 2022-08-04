module;

//#pragma optimize("", off)
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
    
    mylib::stack_string s{ "ssss" };
    
    std::cout << mylib::concat("sb"_ss, "nmsl"_ss, s) << std::endl;
    
    return 0;
}
