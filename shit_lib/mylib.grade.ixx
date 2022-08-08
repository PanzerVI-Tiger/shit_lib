export module mylib.grade;

import std.core;


export namespace mylib {
    
    template<typename ElementType>
        requires std::is_integral_v<ElementType>
    struct grade {
        using TemplateParameter = ElementType;
        using SignedType        = std::make_signed_t<ElementType>;
        using UnsignedType      = std::make_unsigned_t<ElementType>;

        UnsignedType denominator;
        SignedType   numerator;

        constexpr grade(long long numerator, long long denominator = 1) noexcept {
            long long d = std::gcd(numerator, denominator);
            numerator = std::abs(numerator / d);
            if ((numerator ^ denominator) < 0) {
                numerator = -numerator;
            }
            denominator = std::abs(denominator / d);
        };

        constexpr grade(const grade&) noexcept = default;
        constexpr grade() noexcept = default;

        constexpr grade operator -() const noexcept {
            return grade{ -numerator, denominator };
        }

        constexpr grade operator +(const grade& right) const noexcept {
            long long d = std::lcm(denominator, right.denominator);
            SignedType x1 = d / denominator, x2 = d / right.denominator;
            SignedType n = numerator * x1 + right.numerator * x2;
            SignedType i = std::gcd(d, n);
            return { n / i, (int)(d / i) };
        }

        constexpr grade operator -(const grade& right) const noexcept {
            long long d = std::lcm(denominator, right.denominator);
            SignedType x1 = d / denominator, x2 = d / right.denominator;
            SignedType n = numerator * x1 - right.numerator * x2;
            SignedType i = std::gcd(d, n);
            return { n / i, (int)(d / i) };
        }

        constexpr grade operator /(const grade& right) const noexcept {
            long long d = (long long)denominator * right.numerator;
            long long n = (long long)numerator * right.denominator;
            long long i = std::gcd(d, n);
            return { (int)(n / i), (int)(d / i) };
        }

        constexpr grade operator *(const grade& right) const noexcept {
            long long d = (long long)denominator * right.denominator;
            long long n = (long long)numerator * right.numerator;
            long long i = std::gcd(d, n);
            return { (SignedType)(n / i), (SignedType)(d / i) };
        }

        constexpr explicit operator double() noexcept {
            return numerator / (double)denominator;
        }


        template<typename ElementType>
            requires std::is_integral_v<ElementType>
        friend inline std::ostream& operator <<(std::ostream& os, grade<ElementType> const& grade) noexcept
        {
            os << (long long)grade.numerator << " \\ " << (unsigned long long)grade.denominator;

            return os;
        }
    };

    template<typename ElementType>
        requires std::is_integral_v<ElementType>
    constexpr bool operator < (const grade<ElementType>& _L, const grade<ElementType>& right) noexcept {
        long long d = std::lcm(_L.denominator, right.denominator);
        typename grade<ElementType>::SignedType x1 = d / _L.denominator, x2 = d / right.denominator;

        return _L.numerator * x1 < right.numerator* x2;
    }
}
