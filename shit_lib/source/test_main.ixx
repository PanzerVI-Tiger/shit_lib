module;

//#pragma optimize("", off)

//#include <Windows.h>
//#include <fast_io.h>
//#include <iostream>
//#include <boost/stacktrace.hpp>

export module mylib.main;

#include "cpp/cxxstd.h"
#include "preprocessor.h"
#include <boost/preprocessor.hpp>

//import mylib;


#define x(a)   #a
#define y(...) #__VA_ARGS__
#define z(...) y(__VA_ARGS__)
#define x1(a) x(a)

struct X {
    auto operator [](auto x) const {}
};


export int main() noexcept
{
    //using namespace mylib::literals;
    
    return 0;
}
