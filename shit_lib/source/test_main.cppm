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

template<typename... Types>
struct fuck {
    using type = mylib::type_list<Types...>;
};

template<typename Type, Type left, Type right>
struct mylib::meta_plus<
    mylib::integral_constant<Type, left>,
    mylib::integral_constant<Type, right>
>
{
    using type = mylib::integral_constant<Type, left + right>;
};

template<typename Type>
Type add(Type left, Type right)
{
    return left + right;
}

export int main() noexcept
{
    std::cout <<
        typeid(
            mylib::type_list<int>
          ::pop_back<>
        ).name();
}                                                                                                                                                                                                                                                                                                // unused
