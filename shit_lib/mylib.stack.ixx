export module mylib.stack;

import mylib.deque;


export namespace mylib {

    template<typename _ElementType, typename _Container = deque<_ElementType>>
    class stack {
    public:
        using value_type      = typename _Container::value_type;
        using reference       = typename _Container::reference;
        using const_reference = typename _Container::const_reference;
        using size_type       = typename _Container::size_type;
        using container_type  = _Container;

        stack() = default;
        explicit stack(const _Container& _Cont) noexcept : c{ _Cont } {}
        explicit stack(_Container&& _Cont) noexcept : c(std::move(_Cont)) {}
        template<typename _InputIterator>
        stack(_InputIterator _First, _InputIterator _Last) noexcept : c{ _First, _Last } {}

        void push(const value_type& _Val) noexcept {
            c.push_back(_Val);
        }

        void push(value_type&& _Val) noexcept {
            c.push_back(std::move(_Val));
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

        void swap(stack& _Right) noexcept {
            c.swap(_Right);
        }

    private:
        _Container c;
    };
}