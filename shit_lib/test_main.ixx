module;

//#pragma optimize("", off)
#include <Windows.h>
#include <stdio.h>
//#include "mylib_assert.h"
//#include <execution>

export module mylib.main;

import mylib;
import std.core;

struct L {
    constexpr int operator()() const noexcept {
        return i;
    }
    int i;
};

template<const auto x>
struct X {
};

export int main() noexcept
{
    using namespace mylib::literals;
    "sb"_ss;
    [] {
        if constexpr (std::is_constant_evaluated()) {
            return 0;
        }
    }();

    return 0;
}
