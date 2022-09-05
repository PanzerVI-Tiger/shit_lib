#include <bit>
#include <climits>
#include <type_traits>

export module mylib.fixed;

import mylib.type_traits;


namespace mylib::detail {
    template<
        typename ElementType, 
        bool     isBigEndian = std::endian::native == std::endian::big
    > struct fixed_underlying;

    template<typename ElementType>
    struct fixed_common {
        using value_type = ElementType;

        constexpr ElementType& value() noexcept {
            return std::bit_cast<ElementType&>(*this);
        }

        constexpr const ElementType& value() const noexcept {
            return std::bit_cast<const ElementType&>(*this);
        }
    };

    template<typename ElementType>
    struct fixed_underlying<ElementType, true> :
        fixed_common<fixed_underlying<ElementType, true>> 
    {
        ElementType                       integer  : sizeof(ElementType) * CHAR_BIT / 2;
        std::make_unsigned_t<ElementType> decimals : sizeof(ElementType) * CHAR_BIT / 2;
    };

    template<typename ElementType>
    struct fixed_underlying<ElementType, false> :
        fixed_common<fixed_underlying<ElementType, false>>  
    {
        ElementType                       decimals : sizeof(ElementType) * CHAR_BIT / 2;
        std::make_unsigned_t<ElementType> integer  : sizeof(ElementType) * CHAR_BIT / 2;
    };
}


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
