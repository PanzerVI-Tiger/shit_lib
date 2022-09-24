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

template<typename... Type>
struct twice {
    using type = mylib::type_list<Type..., Type...>;
};

export int main() noexcept
{
    using t =
        mylib::meta_compose<twice, twice, twice>
      ::meta_func<int, char>
      ::type;
    std::cout << typeid(t).name();
}                                                                                                                                                                                                                                                                                                // unused
