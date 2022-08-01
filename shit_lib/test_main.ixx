module;

//#pragma optimize("", off)
#include <Windows.h>
#include <stdio.h>
#include "mylib_assert.h"
//#include <execution>

export module mylib.main;

import std.core;
import mylib;

template<typename Type>
constexpr void print_aggregate_traits(const Type& type) noexcept {
    using mylib::operator <<;
    using traits = mylib::aggregate_traits<Type>;
    
    std::cout << typeid(Type).name()         << " {\n"
              << "  size: "                  << traits::size()               << ",\n"
              << "  member objects' type: (" << traits::types_string()       << "),\n"
              << "  member objects: "        << traits::member_objects(type) << '\n'
              << "}";
}

export int main() noexcept
{
    using mylib::operator<<;
    
    struct A {
        int         nmb;
        std::string cnm;
    } a{ 1, "fuck" };

    struct B {
        int sb;
        int gb[4];
        int bb;
    } b{ 1, { 1, 2, 3, 4 }, 8 };
    
    // print all
    print_aggregate_traits(a);
    std::cout << '\n';
    print_aggregate_traits(b);
    std::cout << '\n' << mylib::get<1>(b);
    
	return 0;
}
