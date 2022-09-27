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

    template<typename Type>
    constexpr mylib::remove_reference_t<Type>&& move(
        Type&& value
    ) noexcept {
        return static_cast<mylib::remove_reference_t<Type>&&>(value);
    }

    template<typename Type>
    constexpr Type&& forward(mylib::remove_reference_t<Type>&& value) noexcept {
        static_assert(
            !mylib::is_lvalue_reference_v<Type>,
            "error forward call, can't forward a rvalue as lvalue!"
        );
        return static_cast<Type&&>(value);
    }

    template<typename Type>
    constexpr Type&& forward(mylib::remove_reference_t<Type>& value) noexcept {
        return static_cast<Type&&>(value);
    }

    
    // non-standard
    struct cast_any {
        
        template<typename Type>
        constexpr operator Type&() const noexcept {
            return {};
        }

        template<typename Type>
        constexpr operator Type&&() const noexcept {
            return {};
        }
    };

    // non-standard
    template<typename Type1, typename Type2>
        requires std::is_assignable_v<Type1&, const Type2&> // to prevent ambiguity with array overload
    void assign(Type1& destination, const Type2& source) noexcept
    {
        destination = source;
    }

    // non-standard
    template<typename Type1, size_t size1, typename Type2, size_t size2>
    void assign(Type1(&destination)[size1], const Type2(&source)[size2]) noexcept
    {
        for (size_t i = 0; i != size1 < size2 ? size1 : size2; ++i) {
            assign(destination[i], source[i]);
        }
    }
}
