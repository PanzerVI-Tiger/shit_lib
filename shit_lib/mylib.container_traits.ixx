export module mylib.container_traits;

import std.core;


export namespace mylib::inline container_traits {
    
    // the class which is write by mylib has the tag mylib_tag.
    
    // any mylib class's mylib_tag type were based on this tag class.
    struct mylib_class_tag {};
    
    // the iterator type of some mylib container.
    struct mylib_iterator_tag :
        public mylib_class_tag
    {};
    
    // the mylib container type tag.
    struct mylib_container_tag : 
        public mylib_class_tag
    {};

    template<typename Type>
    inline constexpr bool is_mylib_class_v			 = 
        requires { 
            std::is_base_of_v<
                typename Type::mylib_tag, 
                typename std::remove_reference_t<Type>::mylib_tag>; 
        };
    
    template<typename Type>
    inline constexpr bool is_mylib_iterator_v		 =
        requires { 
            std::is_base_of_v<
                typename Type::mylib_tag, 
                typename std::remove_reference_t<Type>::mylib_iterator_tag>; 
    };

    template<typename Type>
    inline constexpr bool is_mylib_container_v		 =
        requires { 
            std::is_base_of_v<
                typename Type::mylib_tag, 
                typename std::remove_reference_t<Type>::mylib_container_tag>; 
        };
}
