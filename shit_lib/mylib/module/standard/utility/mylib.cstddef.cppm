module;

#ifdef __INTELLISENSE__

#include <limits>

#endif

#include <cstddef>

#undef NULL

export module mylib.cstddef;

#ifndef __INTELLISENSE__

import std.core;

#endif

export namespace mylib {
    
    using nullptr_t = decltype(nullptr);

    inline constexpr mylib::nullptr_t NULL = nullptr;
    
    inline constexpr size_t npos = std::numeric_limits<size_t>::max();

    struct nullarg
    {};
}
