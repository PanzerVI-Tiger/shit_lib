module;

//#pragma optimize("", off)

//#include <Windows.h>
//#include <fast_io.h>
//#include <iostream>
//#include <boost/stacktrace.hpp>
//#include <stacktrace>
//#include <iostream>

export module mylib.main;

#include "cpp/cxxstd.h"
//#include "preprocessor.h"
//#include <boost/preprocessor.hpp>

import mylib;
import mylib.new_binary_tree;


export int main() noexcept
{
    using mylib::operator <<;
    
    return 0;
}
