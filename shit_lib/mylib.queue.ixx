export module mylib.queue;

import std.core;
import mylib.deque;


export namespace mylib {
	template<typename _ElementType, typename _Container = deque<_ElementType>>
	class queue {
	public:
		using value_type	  = typename _Container::value_type;
		using reference		  = typename _Container::reference;
		using const_reference = typename _Container::const_reference;
		using size_type		  = typename _Container::size_type;
		using container_type  = _Container;

		queue() = default;
		constexpr explicit queue(const _Container& _Cont) noexcept : c{ _Cont } {}
		constexpr explicit queue(_Container&& _Cont) noexcept : c(std::move(_Cont)) {}
		template<typename _InputIterator>
		constexpr queue(_InputIterator _First, _InputIterator _Last) noexcept : c{ _First, _Last } {}

		constexpr void push(const value_type& _Val) noexcept {
			c.push_back(_Val);
		}

		constexpr void push(value_type&& _Val) noexcept {
			c.push_back(std::move(_Val));
		}

		constexpr void pop() noexcept {
			c.pop_front();
		}

		constexpr reference back() noexcept {
			return c.back();
		}

		constexpr const_reference back() const noexcept {
			return c.back();
		}

		constexpr reference front() noexcept {
			return c.front();
		}

		constexpr const_reference front() const noexcept {
			return c.front();
		}

		constexpr size_type size() noexcept {
			return c.size();
		}

		constexpr bool empty() noexcept {
			return c.empty();
		}

		constexpr void swap(queue& _Right) noexcept {
			c.swap(_Right);
		}

	private:
		_Container c;
	};
}