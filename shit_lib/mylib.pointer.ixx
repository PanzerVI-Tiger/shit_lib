export module mylib.pointer;


export namespace mylib::inline pointer {
    
    template<typename ValueType>
    struct compressive_pointer {
        using value_type    = ValueType;
        using pointer       = value_type*;
        using const_pointer = const value_type*;

        constexpr compressive_pointer(const_pointer pointer) noexcept :
            compressedPointer{ reinterpret_cast<size_t>(pointer) } {}

        constexpr compressive_pointer(const_pointer prior, const_pointer next) noexcept :
            compressedPointer{ reinterpret_cast<size_t>(prior) ^ reinterpret_cast<size_t>(next) } {}

        constexpr compressive_pointer& operator =(pointer pointer) noexcept {
            compressedPointer = reinterpret_cast<size_t>(pointer);

            return *this;
        }

        constexpr pointer       get_another(pointer one)       const noexcept {
            return reinterpret_cast<pointer>(compressedPointer ^ reinterpret_cast<size_t>(one));
        }

        constexpr const_pointer get_another(const_pointer one) const noexcept {
            return reinterpret_cast<const_pointer>(compressedPointer ^ reinterpret_cast<size_t>(one));
        }

        pointer to_pointer() const noexcept {
            return reinterpret_cast<pointer>(compressedPointer);
        }

        constexpr compressive_pointer  operator ^ (compressive_pointer compressivePointer) const noexcept {
            return compressive_pointer{ compressedPointer ^ compressivePointer.compressedPointer };
        }

        constexpr compressive_pointer& operator ^=(compressive_pointer compressivePointer) noexcept {
            compressedPointer ^= compressivePointer.compressedPointer;

            return *this;
        }

        size_t compressedPointer;
    };
}