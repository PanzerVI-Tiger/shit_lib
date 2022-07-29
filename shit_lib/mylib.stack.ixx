export module mylib.stack;

import std.core;
import mylib.deque;

export namespace mylib {

    template<typename ElementType, typename Container = deque<ElementType>>
    class stack {
    public:
        using value_type      = typename Container::value_type;
        using reference       = typename Container::reference;
        using const_reference = typename Container::const_reference;
        using size_type       = typename Container::size_type;
        using container_type  = Container;

        stack() = default;
        explicit stack(const Container& container) noexcept : c{ container } {}
        explicit stack(Container&& container) noexcept : c{ std::move(container) } {}
        template<typename InputIterator>
        stack(InputIterator first, InputIterator last) noexcept : c{ first, last } {}

        void push(const value_type& value) noexcept {
            c.push_back(value);
        }

        void push(value_type&& value) noexcept {
            c.push_back(std::move(value));
        }

        void pop() noexcept {
            c.pop_back();
        }

        reference top() noexcept {
            return c.back();
        }

        const_reference top() const noexcept {
            return c.back();
        }

        size_type size() noexcept {
            return c.size();
        }

        bool empty() noexcept {
            return c.empty();
        }

        void swap(stack& right) noexcept {
            c.swap(right);
        }

    private:
        Container c;
    };
}