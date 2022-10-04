module;

//#pragma optimize("", off)

//#include <Windows.h>
#include <fmt/color.h>
#include "macro_meta.hpp"
//#include <boost/preprocessor.hpp>
//#include <Windows.h>

export module mylib.main;

#include "cpp/cxxstd.hpp"

import mylib;

using mylib::operator <<;
using namespace std::literals;
using namespace mylib::literals;


export int main() noexcept
{
    struct X
    {
        int i;
    };
}                                                                                                                                                                                                                                                                                                // unused
