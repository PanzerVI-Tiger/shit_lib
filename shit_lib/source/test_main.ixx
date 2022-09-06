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


export int main() noexcept
{
    std::vector<int> v;
    int arr[10];
    std::ranges::iota(arr, 0);

    std::ranges::copy(arr, std::back_inserter(v));

    std::cout << v;

    return 0;
}
                                                                                                                                                                                                                                                                                                                                                        // unused