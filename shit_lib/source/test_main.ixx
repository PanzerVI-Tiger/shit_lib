module;

#pragma optimize("", off)

//#include <Windows.h>
#include <typeinfo>

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
    
    return 0;
}
