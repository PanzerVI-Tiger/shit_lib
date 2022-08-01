export module mylib.utility;

import std.core;
import mylib.compare;
import mylib.type_traits;

export namespace mylib::inline utility {
    
    // C++11
    template<typename Type>
    add_rvalue_reference_t<Type> declval() noexcept {
        static_assert(always_false<Type>, "declval shouldn't be called!");
    }

    // not standard
    template<typename Type>
        requires std::is_assignable_v<Type&, Type&>
    void assignment(Type& destination, const Type& source) noexcept
    {
        destination = source;
    }

    // not standard
    template<typename Type, size_t size>
    void assignment(Type(&destination)[size], const Type(&source)[size]) noexcept
    {
        for (size_t i = 0; i != size; ++i) {
            assignment(destination[i], source[i]);
        }
    }
}
