module;

//#pragma optimize("", off)

//#include <Windows.h>

#include "preprocessor.hpp"
//#include <boost/mpl/front_inserter.hpp>
//#include <boost/preprocessor.hpp>
//#include <fast_io.h>
//#include <Windows.h>

export module mylib.main;

#include "cpp/cxxstd.hpp"

import mylib;
import mylib.new_binary_tree;

using mylib::operator <<;
using namespace std::literals;
using namespace mylib::literals;

struct big_five {
    big_five() {
        std::cout << "default\n";
    }

    big_five(const big_five&) {
        std::cout << "copy\n";
    }

    big_five(big_five&&) {
        std::cout << "move\n";
    }

    void operator =(const big_five&) {
        std::cout << "copy assign\n";
    }

    void operator =(big_five&&) {
        std::cout << "move assign\n";
    }
};

void f()
{
    std::cout << "f()\n";
}

void f(big_five, big_five)
{
    std::cout << "f(big_five, big_five)\n";
}

void f(big_five, big_five, big_five)
{
    std::cout << "f(big_five, big_five, big_five)\n";
}

template<
    typename Type1,
    typename Type2
> using pred =
    std::bool_constant<(Type1{} < Type2{})>;

export int main() noexcept
{
    std::cout <<
        typeid(
            mylib::to_type_list_t<mylib::integer_sequence<int, 2, 4, 9, 6, 4, 3, 2, 1>>
          ::sort<pred>
          ::to_integer_sequence<>
        ).name();
    
}                                                                                                                                                                                                                                                                                                                                                        // unused
