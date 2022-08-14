module;

//#pragma optimize("", off)

//#include <Windows.h>
//#include <fast_io.h>
//#include <iostream>
//#include <boost/stacktrace.hpp>

export module mylib.main;

#include "cpp/cxxstd.h"
#include "macro_meta.h"

import mylib;


#define x(a)   #a
#define y(...) #__VA_ARGS__
#define z(...) y(__VA_ARGS__)

struct X {};

[[msvc::noinline]]
void f(X)
{
    std::cout << "hello!\n";
}

export int main() noexcept
{
    using namespace mylib::literals;
    
    
    return 0;
}
