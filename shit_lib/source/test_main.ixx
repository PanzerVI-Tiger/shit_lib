module;

//#pragma optimize("", off)

//#include <Windows.h>
//#include <fast_io.h>
//#include <iostream>
//#include <boost\stacktrace.hpp>

export module mylib.main;

#include "cpp\cxxstd.h"


import mylib;


export int main() noexcept
{
    using namespace mylib::literals;
    
    u8"sss"_sl.operator std::u8string();
    
    
    return 0;
}
