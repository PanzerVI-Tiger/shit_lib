export module mylib.queue;

import std.core;
import mylib.deque;


export namespace mylib {
    template<typename ElementType, typename Container = deque<ElementType>>
    class queue {
    public:
        using value_type      = typename Container::value_type;
        using reference       = typename Container::reference;
        using const_reference = typename Container::const_reference;
        using size_type       = typename Container::size_type;
        using container_type  = Container;

        queue() = default;
        constexpr explicit queue(const Container& container) noexcept : c{ container } {}
        constexpr explicit queue(Container&& container) noexcept : c{ std::move(container) } {}
        template<typename InputIterator>
        constexpr queue(InputIterator first, InputIterator last) noexcept : c{ first, last } {}

        constexpr void push(const value_type& value) noexcept {
            c.push_back(value);
        }

        constexpr void push(value_type&& value) noexcept {
            c.push_back(std::move(value));
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

        constexpr void swap(queue& right) noexcept {
            c.swap(right);
        }

    private:
        Container c;
    };
}