module;

//#pragma optimize("", off)

//#include <Windows.h>

#include "preprocessor.h"
//#include <boost/sort/sort.hpp>
//#include <boost/preprocessor.hpp>
//#include <boost/type_traits.hpp>
//#include <fast_io.h>
//#include <Windows.h>


export module mylib.main;

#include "cpp/cxxstd.h"

import mylib;
import mylib.new_binary_tree;

using mylib::operator <<;
using namespace std::literals;
using namespace mylib::literals;

template<stdr::range Range>
class flatten_all_view :
    public stdr::view_interface<flatten_all_view<Range>> 
{
    
};

template<typename... Types1>
struct is_convertible_prefix_of_pack;

template<>
struct is_convertible_prefix_of_pack<>
{
    template<bool cond, typename... Types2>
    struct helper {
        static constexpr bool value = cond;

    };
    
    template<typename... Types2>
    struct type {
        static constexpr bool value = true;
    };

    template<typename... Types2>
    static constexpr bool value = true;
    
};

template<typename Type1, typename... Types1>
struct is_convertible_prefix_of_pack<Type1, Types1...>
{
    template<bool cond, typename... Types2>
    struct helper {
        static constexpr bool value = false;
            
    };

    template<typename Type2, typename... Types2>
    struct helper<true, Type2, Types2...> {
        static constexpr bool value =
            is_convertible_prefix_of_pack<Types1...>::
                template helper<mylib::is_convertible_v<Type1, Type2>, Types2...>::value;
    };
    
    template<typename... Types2>
    struct type {
        static constexpr bool value =
            mylib::conditional_t<
                (sizeof...(Types1) <= sizeof...(Types2)),
                helper<true, Types2...>,
                mylib::false_type
            >::value;
    };
    
    template<typename... Types2>
    static constexpr bool value = type<Types2...>::value;
};

template<size_t count, typename... Types>
struct take_pack;

template<size_t count, typename Type, typename... Types1>
struct take_pack<count, Type, Types1...>
{
    template<typename... Types2>
    using helper = take_pack<count - 1, Types1...>::template helper<Types2..., Type>;

    using type = helper<>;
};

template<typename... Types>
struct take_pack<0, Types...>
{
    template<typename... Types2>
    using helper = std::tuple<Types2...>;

    using type = helper<>;
};

template<size_t count, typename... Types>
using take_pack_t = typename take_pack<count, Types...>::type;
    
template<typename Result, typename... Params>
class curried_function;

template<typename Derived, typename Params>
struct curried_function_interface_helper;

template<typename Derived, typename... Params>
struct curried_function_interface_helper<Derived, std::tuple<Params...>>
{
    auto operator ()(Params... args) {
        return static_cast<Derived&>(*this)()(args...);
    }
};

template<size_t paramsSize, typename Result, typename... Params>
struct curried_function_interface :
    curried_function_interface<paramsSize - 1, Result, Params...>,
    curried_function_interface_helper<
        curried_function_interface<paramsSize, Result, Params...>,
        take_pack_t<paramsSize, Params...>
    >
{};

template<typename Result, typename... Params>
struct curried_function_interface<0, Result, Params...>
{
    using result_type = Result;
    using params_type = std::tuple<Params...>;
    
    constexpr auto operator ()() const noexcept {
        return
        [this]<typename... LambdaParams1>(
            this auto self, LambdaParams1... args1
        ) constexpr noexcept(sizeof...(LambdaParams1) != 0) {
            if constexpr (!is_convertible_prefix_of_pack<LambdaParams1...>::template value<Params...>) {
                static_assert(mylib::always_false<LambdaParams1...>, "not match parameter list!");
            } else if constexpr (sizeof...(LambdaParams1) == sizeof...(Params)) {
                return static_cast<const curried_function<Result, Params...>&>(*this).func(args1...);
            } else {
                return
                [self, args1...]<typename... LambdaParams2>(LambdaParams2... args2) {
                    return self(args1..., args2...);
                };
            }
        };
    }

    constexpr size_t size() const noexcept {
        return sizeof...(Params);
    }
};

template<typename Result, typename... Params>
class curried_function :
    public curried_function_interface<sizeof...(Params), Result, Params...>
{
public:
    using base_type = curried_function_interface<sizeof...(Params), Result, Params...>;

    constexpr curried_function(Result(*_func)(Params...)) noexcept :
        func{ _func }
    {}
    
    template<size_t paramsSize, typename Result1, typename... Params1>
    friend struct curried_function_interface;
    
private:
    Result(*func)(Params...);
};

template<typename Callable>
constexpr auto currying(Callable callable) noexcept
{
    return curried_function{ +callable };
}

export int main() noexcept
{
    auto x = currying([](int a, int b, int c) { return a + b + c; });
    
    std::cout
        << x(1, 2, 3) << "\n"
        << x(2, 3)(4) << "\n"
        << x(3)(4, 5) << "\n"
        << x(4)(5)(6) << "\n";

    return 0;
}
                                                                                                                                                                                                                                                                                                                                                        // unused