module;

#ifdef __INTELLISENSE__

#include <type_traits>

#endif

export module mylib.utility;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.compare;

export import mylib.type_traits;

export namespace mylib {
    
    // already defined in type_traits
    /*
        // C++11
        template<typename Type>
        add_rvalue_reference_t<Type> declval() noexcept {
            static_assert(always_false<Type>, "declval shouldn't be called!");
        }
    */

    // non-standard
    template<typename Type>
        requires std::is_assignable_v<Type&, Type&> // to prevent ambiguity with array overload
    void assignment(Type& destination, const Type& source) noexcept
    {
        destination = source;
    }

    // non-standard
    template<typename Type, size_t size>
    void assignment(Type(&destination)[size], const Type(&source)[size]) noexcept
    {
        for (size_t i = 0; i != size; ++i) {
            assignment(destination[i], source[i]);
        }
    }
}
