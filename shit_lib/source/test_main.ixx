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


export int main() noexcept
{
    (mylib::assert)(false, "What do you Fuck do!!!");
    

    return 0;
}
