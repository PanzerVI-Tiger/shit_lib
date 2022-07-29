export module mylib.utility;

import mylib.compare;
import mylib.type_traits;


export namespace mylib::inline utility {
    
    // C++11
    template<typename Type>
    add_rvalue_reference_t<Type> declval() noexcept {
        static_assert(always_false<Type>, "declval shouldn't be called!");
    }
}
