export module mylib.fixed;

import std.core;


export namespace mylib {

    template<typename ElementType>
        requires (std::is_integral_v<ElementType> && (!std::is_same_v<ElementType, long long>))
    struct fixed {
        union {
            struct {
                ElementType decimals : sizeof(ElementType) << 2;
                ElementType integer  : sizeof(ElementType) << 2;
            };
            ElementType entiretyPart;
        };
        
        constexpr fixed() : entiretyPart{ 0 } {};
        constexpr fixed(const fixed&) = default;
        constexpr fixed(ElementType integer) : integer{ integer }, decimals{ 0 } {};
        constexpr fixed(ElementType integer, unsigned _Scaling) : integer{ integer }, decimals{ 0 } {
            *this = *this / _Scaling;
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
            result.integer = entiretyPart / right.entiretyPart;
            result.decimals = ((long long)(entiretyPart % right.entiretyPart) << (sizeof(ElementType) << 2)) / right.entiretyPart;

            return result;
        }

        constexpr explicit operator double() noexcept {
            return (double)entiretyPart / (1 << (sizeof(ElementType) * 4));
        }
    };
}
