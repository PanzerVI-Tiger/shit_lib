export module mylib.grade;

import std.core;


export namespace mylib {
    template<typename _ElementType>
        requires std::is_integral_v<_ElementType>
    struct grade {
        using TemplateParameter = _ElementType;
        using SignedType = std::make_signed_t<_ElementType>;
        using UnsignedType = std::make_unsigned_t<_ElementType>;

        UnsignedType denominator;
        SignedType   numerator;

        constexpr grade(long long _Numerator, long long _Denominator = 1) noexcept {
            long long d = std::gcd(_Numerator, _Denominator);
            numerator = std::abs(_Numerator / d);
            if ((_Numerator ^ _Denominator) < 0) {
                numerator = -numerator;
            }
            denominator = std::abs(_Denominator / d);
        };

        constexpr grade(const grade&) noexcept = default;
        constexpr grade() noexcept = default;

        constexpr grade operator -() const noexcept {
            return grade{ -numerator, denominator };
        }

        constexpr grade operator +(const grade& _R) const noexcept {
            long long d = std::lcm(denominator, _R.denominator);
            SignedType x1 = d / denominator, x2 = d / _R.denominator;
            SignedType n = numerator * x1 + _R.numerator * x2;
            SignedType i = std::gcd(d, n);
            return { n / i, (int)(d / i) };
        }

        constexpr grade operator -(const grade& _R) const noexcept {
            long long d = std::lcm(denominator, _R.denominator);
            SignedType x1 = d / denominator, x2 = d / _R.denominator;
            SignedType n = numerator * x1 - _R.numerator * x2;
            SignedType i = std::gcd(d, n);
            return { n / i, (int)(d / i) };
        }

        constexpr grade operator /(const grade& _R) const noexcept {
            long long d = (long long)denominator * _R.numerator;
            long long n = (long long)numerator * _R.denominator;
            long long i = std::gcd(d, n);
            return { (int)(n / i), (int)(d / i) };
        }

        constexpr grade operator *(const grade& _R) const noexcept {
            long long d = (long long)denominator * _R.denominator;
            long long n = (long long)numerator * _R.numerator;
            long long i = std::gcd(d, n);
            return { (SignedType)(n / i), (SignedType)(d / i) };
        }

        constexpr explicit operator double() noexcept {
            return numerator / (double)denominator;
        }


        template<typename _ElementType>
            requires std::is_integral_v<_ElementType>
        friend inline std::ostream& operator <<(std::ostream& _Os, grade<_ElementType> const& _Grade) noexcept
        {
            _Os << (long long)_Grade.numerator << " \\ " << (unsigned long long)_Grade.denominator;

            return _Os;
        }
    };

    template<typename _ElementType>
        requires std::is_integral_v<_ElementType>
    constexpr bool operator < (const grade<_ElementType>& _L, const grade<_ElementType>& _R) noexcept {
        long long d = std::lcm(_L.denominator, _R.denominator);
        typename grade<_ElementType>::SignedType x1 = d / _L.denominator, x2 = d / _R.denominator;

        return _L.numerator * x1 < _R.numerator* x2;
    }
}
