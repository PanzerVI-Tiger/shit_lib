module;

//#pragma optimize("", off)

//#include <Windows.h>
#include "macro_meta.hpp"
//#include <boost/preprocessor.hpp>
//#include <Windows.h>

export module mylib.main;

using namespace std;

#include "cpp/cxxstd.hpp"

import mylib;


//using mylib::operator <<;
using namespace std::literals;
using namespace mylib::literals;


export int main() noexcept
{
    constexpr auto str = U"我的MnZn"_ss + U"，嘿嘿嘿"_ss;
    std::cout
        << typeid(str).name() << '\n'
        << stdf::path(str.operator std::u32string()).string();
}                                                                                                                                                                                                                                                                                                // unused
