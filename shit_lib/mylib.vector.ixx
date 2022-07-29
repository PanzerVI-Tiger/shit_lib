export module mylib.vector;

import std.core;


export namespace mylib {

    template<typename _ElementType, typename _Allocator = std::allocator<_ElementType>>
    class vector {
    public:
        using size_type       = typename std::allocator_traits<_Allocator>::size_type;

        using value_type      = _ElementType;

        using allocator_type  = _Allocator;

        using reference       = value_type&;

        using const_reference = const value_type&;

        using difference_type = typename std::allocator_traits<_Allocator>::difference_type;

        using pointer         = typename std::allocator_traits<_Allocator>::pointer;
        using const_point     = typename std::allocator_traits<_Allocator>::const_pointer;

    private:
        pointer   pData;
        size_type dataSize;
    };
}