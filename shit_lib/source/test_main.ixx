module;

//#pragma optimize("", off)

//#include <Windows.h>

#include "preprocessor.h"
//#include <boost/sort/sort.hpp>
//#include <boost/preprocessor.hpp>
//#include <boost/type_traits.hpp>
//#include <fast_io.h>
//#include <Windows.h>


export module mylib.main;

#include "cpp/cxxstd.h"

import mylib;
import mylib.new_binary_tree;

using mylib::operator <<;
using namespace std::literals;
using namespace mylib::literals;

template<stdr::input_range View>
class flatten_all_view :
    public stdr::view_interface<flatten_all_view<View>> 
{
    
};

export int main() noexcept
{
    auto x = mylib::currying([](int a, int b, int c) { return a + b + c; });
    //std::cout << x(1, 2, 3)()();
    struct X {
        void f()
        {}
    };

}
                                                                                                                                                                                                                                                                                                                                                        // unused