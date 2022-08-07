export module mylib.string_traits;

import std.core;
import mylib.type_traits;


export namespace mylib {
    
    template<typename Type>
    inline constexpr bool is_string_v = false;

    template<typename Type>
    struct is_string : 
        bool_constant<is_string_v<Type>>
    {};
    
    template<
        typename Type, 
        typename CharTraits = std::char_traits<remove_pointer_t<Type>>
    > struct string_traits {
        
    };

    template<typename Type>
    struct string_traits<Type, typename Type::traits_type> {

    };
}
