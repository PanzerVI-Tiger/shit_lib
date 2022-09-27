module;

#ifndef __cpp_size_t_suffix

#include <cstddef>

#endif

#include "macro_meta.hpp"

#undef NULL

export module mylib.cstddef;


export namespace mylib {
    
    using nullptr_t = decltype(nullptr);

#   ifdef __cpp_size_t_suffix

    using size_t = decltype(0uz);

#   else

    using size_t = std::size_t;

#   define decl_size_t_suffix(name)                                                     \
    constexpr mylib::size_t operator "" name(unsigned long long value) noexcept {       \
        return static_cast<mylib::size_t>(value);                                       \
    }
}

export {
    mylib_pp_repeat_each(
        decl_size_t_suffix,
        mylib_semicolon,
        uz, uZ, Uz, UZ, zu, zU, Zu, ZU
    );
}

export namespace mylib {
    
#   endif

    inline constexpr mylib::nullptr_t NULL = nullptr;
    
    inline constexpr mylib::size_t    npos = static_cast<mylib::size_t>(-1);

    using ptrdiff_t                        = decltype(&npos - &npos);
    
    struct nullarg
    {}; 
}
