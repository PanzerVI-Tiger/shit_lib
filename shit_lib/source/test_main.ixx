module;

#pragma optimize("", off)

//#include <Windows.h>

//#include "preprocessor.h"
//#include <boost/sort/sort.hpp>
//#include <boost/preprocessor.hpp>
//#include <boost/type_traits.hpp>
//#include <fast_io.h>
//#include <Windows.h>
//#include <experimental/generator>

export module mylib.main;

#include "cpp/cxxstd.h"

import mylib;
import mylib.new_binary_tree;


using mylib::operator <<;
using namespace std::literals;
using namespace mylib::literals;

namespace mylib::ranges::inline views {
    
    template<std::ranges::range Range, typename ValueType>
    class flatten_map_view :
        public std::ranges::view_interface<
            flatten_map_view<Range, ValueType>
        >
    {
        
    };
    
}


export int main() noexcept
{
    int a[10][10];
    
    mylib::iota(a, 0);
    
    std::cout << a;

    return 0;
}
                                                                                                                                                                                                                                                                                                                                                        // unused