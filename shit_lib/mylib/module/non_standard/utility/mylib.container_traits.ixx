module;

#ifdef __INTELLISENSE__

#include <iterator>

#endif

export module mylib.container_traits;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.type_traits;


export namespace mylib {
    
    
    struct mylib_class_tag {};
    
    // the iterator type of mylib container.
    struct mylib_iterator_tag :
        mylib::mylib_class_tag
    {};
    
    // the mylib container type tag.
    struct mylib_container_tag : 
        mylib::mylib_class_tag
    {};

    template<typename Type>
    inline constexpr bool is_mylib_class_v     = 
        requires { 
            mylib::is_base_of_v<
                typename Type::mylib_tag, 
                typename std::remove_reference_t<Type>::mylib_tag
            >; 
        };
    
    template<typename Type>
    inline constexpr bool is_mylib_iterator_v  =
        requires { 
            mylib::is_base_of_v<
                typename Type::mylib_tag, 
                typename std::remove_reference_t<Type>::mylib_iterator_tag
            >; 
        };

    template<typename Type>
    inline constexpr bool is_mylib_container_v =
        requires { 
            mylib::is_base_of_v<
                typename Type::mylib_tag, 
                typename std::remove_reference_t<Type>::mylib_container_tag
            >; 
        };
}
