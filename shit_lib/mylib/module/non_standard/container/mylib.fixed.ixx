export module mylib.fixed;

import mylib.type_traits;


export namespace mylib {

    template<typename ElementType>
        requires (
            mylib::is_integral_v<ElementType> && 
          (!mylib::is_same_v<ElementType, long long>))
    struct fixed {
        union {
            struct {
                ElementType decimals : sizeof(ElementType) << 2;
                ElementType integer  : sizeof(ElementType) << 2;
            } separatePart;
            ElementType entiretyPart;
        };
        
        constexpr fixed() : entiretyPart{ 0 } {};
        constexpr fixed(const fixed&) = default;
        constexpr fixed(ElementType integer) :separatePart{ 0, integer } {};
        constexpr fixed(ElementType integer, unsigned scaling) : separatePart{ 0, integer } {
            *this = *this / scaling;
        };

        constexpr bool operator <(const fixed& right) const noexcept {
            return entiretyPart < right.entiretyPart;
        }

        constexpr fixed  operator -() const noexcept {
            fixed f;
            f.entiretyPart = -entiretyPart;
            return f;
        }

        constexpr fixed  operator +(const fixed& right) const noexcept {
            int i = entiretyPart + right.entiretyPart;
            fixed result;
            result.entiretyPart = i;
            return result;
        }

        constexpr fixed  operator -(const fixed& right) const  noexcept {
            int i = entiretyPart - right.entiretyPart;
            fixed result;
            result.entiretyPart = i;
            return result;
        }

        constexpr fixed operator *(const fixed& right) const noexcept {
            int i = ((long long)entiretyPart * right.entiretyPart) >> (sizeof(ElementType) << 2);
            fixed result;
            result.entiretyPart = i;
            return result;
        }

        constexpr fixed operator /(const fixed& right) const noexcept {
            fixed result;
            result.separatePart.integer  = entiretyPart / right.entiretyPart;
            result.separatePart.decimals = 
                (static_cast<long long>(entiretyPart % right.entiretyPart) << 
                (sizeof(ElementType) << 2)) / right.entiretyPart;

            return result;
        }

        constexpr explicit operator double() noexcept {
            return (double)entiretyPart / (1 << (sizeof(ElementType) * 4));
        }
    };
}
