module;

//#pragma optimize("", off)

//#include <Windows.h>
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
    struct X {
        void operator ()(this X self)
        {}
    };
    std::cout << typeid(mylib::function_object_traits<X>::function_object_category).name();
}                                                                                                                                                                                                                                                                                                // unused
