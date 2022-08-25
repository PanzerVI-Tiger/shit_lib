module;

//#pragma optimize("", off)

//#include <Windows.h>

#include "preprocessor.h"
#include <boost/preprocessor.hpp>
//#include <fast_io.h>

export module mylib.main;

#include "cpp/cxxstd.h"

import mylib;
import mylib.new_binary_tree;


export int main() noexcept
{
    //using mylib::operator <<;
    //using namespace mylib::literals;

    std::string x = std::filesystem::path{ L"³Ô·¹ÁËÃ»ÌúÖ­" }.string();
    std::cout << x;

    return 0;
}
