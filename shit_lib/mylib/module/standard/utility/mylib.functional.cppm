module;

#ifdef __INTELLISENSE__

#include <concepts>
#include <functional>

#endif

export module mylib.functional;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.utility;
import mylib.type_traits;


export namespace mylib {

    template<typename Function>
    struct function_traits {

    };

    template<typename Invocation>
    struct invocation_traits {

    };

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

    template<typename Invocation, typename... Arguments>
    class curried_function
    {
    public:
        template<typename, typename...>
        friend class curried_function;
        
        using result_type =
            mylib::conditional_t<
                std::is_invocable_v<Invocation, Arguments...>,
                std::invoke_result<Invocation, Arguments...>,
                mylib::type_identity<void>
            >::type;

        static constexpr bool is_evalutable = std::is_invocable_v<Invocation, Arguments...>;
        
        constexpr curried_function(Invocation&& _func, Arguments&&... _arguments) noexcept :
            func{ std::forward<Invocation>(_func) }, arguments{mylib::forward<Arguments>(_arguments)...}, is_invocated{}
        {}

    private:
        template<typename... Arguments1, typename... Arguments2>
        constexpr curried_function(
            bool isInvocated, const curried_function<Invocation, Arguments1...>& old, std::tuple<Arguments2...>&& arguments
        ) noexcept :
            func{ old.func }, arguments{ std::tuple_cat(old.arguments, std::move(arguments)) }, is_invocated{ isInvocated }
        {}

        template<typename... Arguments1, typename... Arguments2>
        constexpr curried_function(
            bool isInvocated, curried_function<Invocation, Arguments1...>&& old, std::tuple<Arguments2...>&& arguments
        ) noexcept :
            func{ std::move(old.func) }, arguments{ std::tuple_cat(std::move(old.arguments), std::move(arguments)) }, is_invocated{ isInvocated }
        {}
        
    public:
        constexpr ~curried_function() noexcept {
            if constexpr (is_evalutable) {
                if (is_invocated) {
                    operator result_type();
                }
            }
        }
        
        template<typename... Arguments2>
        constexpr auto operator ()(Arguments2&&... args) & noexcept {
            is_invocated = false;
            return
                curried_function<Invocation, Arguments..., Arguments2...>{
                    true, *this, std::make_tuple(std::forward<Arguments2>(args)...)
                };
        }

        template<typename... Arguments2>
        constexpr auto operator ()(Arguments2&&... args) && noexcept {
            is_invocated = false;
            return
                curried_function<Invocation, Arguments..., Arguments2...>{
                true, std::move(*this), std::make_tuple(std::move(args)...)
            };
        }
        
        constexpr operator result_type() noexcept
        {
            if (is_evalutable) {
                is_invocated = false;
                return std::apply(func, arguments);
            }
        }
        
    private:
        bool                     is_invocated;
        Invocation               func;
        std::tuple<Arguments...> arguments;
    };

    template<typename Invocation, typename... Arguments>
    constexpr auto currying(Invocation&& callable, Arguments&&... args) noexcept
    {
        return 
            mylib::curried_function{
                std::forward<Invocation>(callable), std::forward<Arguments>(args)...
            };
    }
}
