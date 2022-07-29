export module mylib.matrix;

import std.core;
import mylib.container_traits;


export namespace mylib::matrix {
    
    template<typename ElementType, size_t vertical, size_t horizontal>
    class matrix {
    public:
        using size_type              = size_t;
        using difference_type        = ptrdiff_t;
        
        using value_type             = ElementType;
        using reference              = value_type&;
        using const_reference        = const value_type&;
        using pointer                = value_type*;
        using const_pointer          = const value_type*;
        
        using iterator               = ElementType*;
        using const_iterator         = const ElementType*;
        using reverse_iterator       = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;
        
        using mylib_tag              = mylib_container_tag;
        
        value_type data[vertical][horizontal];
    };
}
