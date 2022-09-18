#ifdef __INTELLISENSE__

#include <memory>

#endif

export module mylib.vector;

#ifndef __INTELLISENSE__

import std.core;

#endif

namespace mylib {

    // used only when you need to check, if not the vector's iterator will be raw pointer
    template<typename Vector>
    struct vector_const_iterator {

    };
}

export namespace mylib {

    template<typename ElementType, typename Allocator = std::allocator<ElementType>>
    class vector {
    public:
        using size_type       = typename std::allocator_traits<Allocator>::size_type;

        using value_type      = ElementType;

        using allocator_type  = Allocator;

        using reference       = value_type&;

        using const_reference = const value_type&;

        using difference_type = typename std::allocator_traits<Allocator>::difference_type;

        using pointer         = typename std::allocator_traits<Allocator>::pointer;
        using const_point     = typename std::allocator_traits<Allocator>::const_pointer;

    private:
        pointer   data;
        size_type dataSize;
    };
}
