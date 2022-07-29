export module mylib.fixed;

import std.core;


export namespace mylib {

	template<typename _ElementType>
		requires (std::is_integral_v<_ElementType> && (!std::is_same_v<_ElementType, long long>))
	struct fixed {
		union {
			struct {
				_ElementType decimals : sizeof(_ElementType) << 2;
				_ElementType integer  : sizeof(_ElementType) << 2;
			};
			_ElementType entiretyPart;
		};
		
		constexpr fixed() : entiretyPart{ 0 } {};
		constexpr fixed(const fixed&) = default;
		constexpr fixed(_ElementType _Integer) : integer{ _Integer }, decimals{ 0 } {};
		constexpr fixed(_ElementType _Integer, unsigned _Scaling) : integer{ _Integer }, decimals{ 0 } {
			*this = *this / _Scaling;
		};

		constexpr bool operator <(const fixed& _R) const noexcept {
			return entiretyPart < _R.entiretyPart;
		}

		constexpr fixed  operator -() const noexcept {
			fixed f;
			f.entiretyPart = -entiretyPart;
			return f;
		}

		constexpr fixed  operator +(const fixed& _R) const noexcept {
			int i = entiretyPart + _R.entiretyPart;
			fixed result;
			result.entiretyPart = i;
			return result;
		}

		constexpr fixed  operator -(const fixed& _R) const  noexcept {
			int i = entiretyPart - _R.entiretyPart;
			fixed result;
			result.entiretyPart = i;
			return result;
		}

		constexpr fixed operator *(const fixed& _R) const noexcept {
			int i = ((long long)entiretyPart * _R.entiretyPart) >> (sizeof(_ElementType) << 2);
			fixed result;
			result.entiretyPart = i;
			return result;
		}

		constexpr fixed operator /(const fixed& _R) const noexcept {
			fixed result;
			result.integer = entiretyPart / _R.entiretyPart;
			result.decimals = ((long long)(entiretyPart % _R.entiretyPart) << (sizeof(_ElementType) << 2)) / _R.entiretyPart;

			return result;
		}

		constexpr explicit operator double() noexcept {
			return (double)entiretyPart / (1 << (sizeof(_ElementType) * 4));
		}
	};
}
