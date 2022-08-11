module;

//#pragma optimize("", off)

#include <Windows.h>
//#include <fast_io.h>

export module mylib.main;

#include "cxxstd.h"

import mylib;


export int main() noexcept
{
    int a[100];
    stdr::iota(a, 0);
    std::cout << a;
    
    return 0;
}
