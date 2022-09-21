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

export int main() noexcept
{
    
}                                                                                                                                                                                                                                                                                                // unused
