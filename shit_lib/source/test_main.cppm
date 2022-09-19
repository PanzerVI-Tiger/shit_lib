module;

//#pragma optimize("", off)

//#include <Windows.h>

#include "macro_meta.hpp"
//#include <boost/mpl/front_inserter.hpp>
//#include <boost/preprocessor.hpp>
//#include <fast_io.h>
//#include <Windows.h>

export module mylib.main;

#include "cpp/cxxstd.hpp"

import mylib;

using mylib::operator <<;
using namespace std::literals;
using namespace mylib::literals;

template<typename Type1, typename Type2>
using pred = mylib::bool_constant<(Type1{} < Type2{})>;


export int main() noexcept
{
    std::cout <<
        typeid(
            mylib::to_type_list_t<mylib::integer_sequence<size_t, 6, 1, 2, 4, 2, 9, 1, 4, 6, 8, 0>>
          ::sort<pred>
          ::to_integer_sequence<>
        ).name();
}                                                                                                                                                                                                                                                                                                // unused
