module;

//#pragma optimize("", off)
#include <Windows.h>
#include <stdio.h>
#include "mylib_assert.h"
//#include <execution>

export module mylib.main;

import std.core;
import mylib;

template<typename Result>
Result f()
{
    return 1;
}

export int main() noexcept
{
        
	return 0;
}
