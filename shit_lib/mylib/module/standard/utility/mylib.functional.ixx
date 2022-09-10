export module mylib.functional;

import mylib.utility;
import mylib.type_traits;


export namespace mylib {
    
    template<typename FunctionType>
    class function {
        
    };
    
    template<typename Type = void>
    struct plus {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left + right;
        }
    };

    template<>
    struct plus<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left + right;
        }
    };

    template<typename Type = void>
    struct minus {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left - right;
        }
    };

    template<>
    struct minus<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left - right;
        }
    };

    template<typename Type = void>
    struct multiplies {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left * right;
        }
    };

    template<>
    struct multiplies<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left * right;
        }
    };

    template<typename Type = void>
    struct divides {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left / right;
        }
    };

    template<>
    struct divides<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left / right;
        }
    };

    template<typename Type = void>
    struct modulus {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left % right;
        }
    };
    
    template<>
    struct modulus<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left % right;
        }
    };

    template<typename Type = void>
    struct negate {
        Type operator()(const Type& left) const noexcept {
            return -left;
        }
    };

    template<>
    struct negate<void> {
        template<typename Type>
        Type operator()(const Type& left) const noexcept {
            return -left;
        }
    };

    template<typename Type = void>
    struct equal_to {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left == right;
        }
    };

    template<>
    struct equal_to<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left == right;
        }
    };

    template<typename Type = void>
    struct not_equal_to {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left != right;
        }
    };

    template<>
    struct not_equal_to<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left != right;
        }
    };

    template<typename Type = void>
    struct greater {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left > right;
        }
    };

    template<>
    struct greater<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left > right;
        }
    };

    template<typename Type = void>
    struct less {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left < right;
        }
    };

    template<>
    struct less<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left < right;
        }
    };
    
    template<typename Type = void>
    struct greater_equal {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left >= right;
        }
    };

    template<>
    struct greater_equal<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left >= right;
        }
    };

    template<typename Type = void>
    struct less_equal {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left <= right;
        }
    };

    template<>
    struct less_equal<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left <= right;
        }
    };

    template<typename Type = void>
    struct logical_and {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left && right;
        }
    };

    template<>
    struct logical_and<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left && right;
        }
    };

    template<typename Type = void>
    struct logical_or {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left || right;
        }
    };

    template<>
    struct logical_or<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left || right;
        }
    };

    template<typename Type = void>
    struct logical_not {
        bool operator()(const Type& left) const noexcept {
            return !left;
        }
    };

    template<>
    struct logical_not<void> {
        template<typename Type>
        bool operator()(const Type& left) const noexcept {
            return !left;
        }
    };

    template<typename Type = void>
    struct bit_and {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left & right;
        }
    };

    template<>
    struct bit_and<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left & right;
        }
    };

    template<typename Type = void>
    struct bit_or {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left | right;
        }
    };

    template<>
    struct bit_or<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left | right;
        }
    };

    template<typename Type = void>
    struct bit_xor {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left ^ right;
        }
    };

    template<>
    struct bit_xor<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left ^ right;
        }
    };

    template<typename Type = void>
    struct bit_not {
        Type operator()(const Type& left) const noexcept {
            return ~left;
        }
    };

    template<>
    struct bit_not<void> {
        template<typename Type>
        Type operator()(const Type& left) const noexcept {
            return ~left;
        }
    };

    template<typename Type = void>
    class curried_function_result
    {
    public:
        constexpr curried_function_result(Type&& type) noexcept :
            result{ mylib::forward<Type>(type) }
        {}

        constexpr curried_function_result operator ()() const& noexcept {
            return *this;
        }

        constexpr curried_function_result operator ()() && noexcept {
            return mylib::move(*this);
        }

        constexpr operator const Type&() const noexcept {
            return result;
        }

        constexpr operator Type&&() noexcept {
            return mylib::forward<Type>(result);
        }

        constexpr const Type& value() const noexcept {
            return result;
        }

        constexpr Type&& value() noexcept {
            return mylib::forward<Type>(result);
        }

    private:
        Type result;
    };

    template<>
    class curried_function_result<void>
    {
    public:
        constexpr curried_function_result operator ()() const noexcept {
            return *this;
        }

        constexpr operator void() const noexcept
        {}

        constexpr void value() const noexcept
        {}
    };

    template<typename Result, typename... Params>
    class curried_function
    {
    public:
        constexpr curried_function(Result(*_func)(Params...)) noexcept :
            func{ _func }
        {}

        template<typename... Params1>
            requires mylib::is_convertible_prefix_of_pack<Params1...>::template value<Params...>
        constexpr auto operator ()(Params1... args1) const noexcept(sizeof...(Params1) != 0) {
            if constexpr (sizeof...(Params1) == sizeof...(Params)) {
                if constexpr (mylib::is_same_v<mylib::remove_cv_t<Result>, void>) {
                    func(mylib::forward<decltype(args1)>(args1)...);
                    return mylib::curried_function_result<>{};
                } else {
                    return
                        mylib::curried_function_result{
                            func(mylib::forward<decltype(args1)>(args1)...)
                        };
                }
            } else {
                return
                [this, args1...](auto... args2) {
                    return (*this)(args1..., mylib::forward<decltype(args2)>(args2)...);
                };
            }
        }
    
    private:
        Result(*func)(Params...);
    };

    template<typename Callable>
    constexpr auto currying(Callable callable) noexcept
    {
        return mylib::curried_function{ +callable };
    }
}