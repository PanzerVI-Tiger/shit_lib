export module mylib.meta_functional;

import mylib.utility;
import mylib.type_pack;
import mylib.type_traits;


namespace mylib {
    
    template<typename... Types>
    struct type_list;
}

export namespace mylib {
    
    // non-standard
    template<
        template<typename...>
        typename    MetaFunction,
        typename... Arguments
    > struct meta_invoke {
        using type = typename MetaFunction<Arguments...>::type;
    };

    // non-standard
    template<
        template<typename...>
        typename    MetaFunction,
        typename... Arguments
    > using meta_invoke_t =
        typename mylib::meta_invoke<MetaFunction, Arguments...>::type;
    
    // non-standard
    template<
        template<typename...>
        typename    MetaFunction,
        template<typename...>
        typename... MetaFunctions
    > struct meta_compose {
        
        template<typename... Params>
        struct meta_fn {
            using type =
                typename MetaFunction<
                    typename meta_compose<MetaFunctions...>
                  ::template meta_fn<Params...>
                  ::type
                >::type;
        };

        template<typename... Params>
        using meta_fn_t = typename meta_fn<Params...>::type;
    };
    
    // non-standard
    template<
        template<typename>
        typename MetaFunction
    > struct meta_compose<MetaFunction> {
        
        template<typename... Params>
        struct meta_fn {
            using type = typename MetaFunction<Params...>::type;
        };
        
        template<typename... Params>
        using meta_fn_t = typename meta_fn<Params...>::type;
    };
    
    // non-standard
    template<int index>
    struct meta_placeholder
    {};

    // non-standard
    template<typename Type>
    struct is_meta_placeholder :
        mylib::integral_constant<int, 0>
    {};

    // non-standard
    template<int index>
    struct is_meta_placeholder<mylib::meta_placeholder<index>> :
        mylib::integral_constant<int, index>
    {};
    
    // non-standard
    template<typename Type>
    inline constexpr int is_meta_placeholder_v = mylib::is_meta_placeholder<Type>::value;

    namespace meta_placeholders {
        
        // non-standard
        using _1  = mylib::meta_placeholder<1>;
        // non-standard
        using _2  = mylib::meta_placeholder<2>;
        // non-standard
        using _3  = mylib::meta_placeholder<3>;
        // non-standard
        using _4  = mylib::meta_placeholder<4>;
        // non-standard
        using _5  = mylib::meta_placeholder<5>;
        // non-standard
        using _6  = mylib::meta_placeholder<6>;
        // non-standard
        using _7  = mylib::meta_placeholder<7>;
        // non-standard
        using _8  = mylib::meta_placeholder<8>;
        // non-standard
        using _9  = mylib::meta_placeholder<9>;
        // non-standard
        using _10 = mylib::meta_placeholder<10>;
        // non-standard
        using _11 = mylib::meta_placeholder<11>;
        // non-standard
        using _12 = mylib::meta_placeholder<12>;
        // non-standard
        using _13 = mylib::meta_placeholder<13>;
        // non-standard
        using _14 = mylib::meta_placeholder<14>;
        // non-standard
        using _15 = mylib::meta_placeholder<15>;
        // non-standard
        using _16 = mylib::meta_placeholder<16>;
        // non-standard
        using _17 = mylib::meta_placeholder<17>;
        // non-standard
        using _18 = mylib::meta_placeholder<18>;
        // non-standard
        using _19 = mylib::meta_placeholder<19>;
        // non-standard
        using _10 = mylib::meta_placeholder<10>;
        // non-standard
        using _21 = mylib::meta_placeholder<21>;
        // non-standard
        using _22 = mylib::meta_placeholder<22>;
        // non-standard
        using _23 = mylib::meta_placeholder<23>;
        // non-standard
        using _24 = mylib::meta_placeholder<24>;
        // non-standard
        using _25 = mylib::meta_placeholder<25>;
        // non-standard
        using _26 = mylib::meta_placeholder<26>;
        // non-standard
        using _27 = mylib::meta_placeholder<27>;
        // non-standard
        using _28 = mylib::meta_placeholder<28>;
        // non-standard
        using _29 = mylib::meta_placeholder<29>;
        // non-standard
        using _30 = mylib::meta_placeholder<30>;
        // non-standard
        using _31 = mylib::meta_placeholder<31>;
        // non-standard
        using _32 = mylib::meta_placeholder<32>;
    }

    // non-standard
    template<
        template<typename...>
        typename    MetaFunction,
        typename... Arguments
    > struct meta_bind {
        
        template<typename... Types>
        struct meta_fn {
        private:
            template<typename TypeList, typename... Types0>
            struct helper;

            template<typename... Types0, typename Type, typename... Types1>
                requires (mylib::is_meta_placeholder_v<Type> != 0)
            struct helper<mylib::type_list<Types0...>, Type, Types1...> {
                using type =
                    typename helper<
                        mylib::type_list<
                            Types0...,
                            mylib::at_pack_t<
                                mylib::is_meta_placeholder_v<Type> - 1,
                                Types...
                            >
                        >,
                        Types1...
                    >::type;
            };

            template<typename... Types0, typename Type, typename... Types1>
            struct helper<mylib::type_list<Types0...>, Type, Types1...> {
                using type =
                    typename helper<
                        mylib::type_list<Types0..., Type>,
                        Types1...
                    >::type;
            };

            template<typename... Types0>
            struct helper<mylib::type_list<Types0...>> {
                using type = typename MetaFunction<Types0...>::type;
            };
            
        public:
            using type = typename helper<mylib::type_list<>, Arguments...>::type;
        };
        
        template<typename... Types>
        using meta_fn_t = typename meta_fn<Types...>::type;
    };
        
    // non-standard
    template<
        template<typename...>
        typename    MetaFunction,
        typename... Arguments
    > struct meta_bind_front {
        
        template<typename... Types>
        struct meta_fn {
            using type = typename MetaFunction<Arguments..., Types...>::type;
        };

        template<typename... Types>
        using meta_fn_t = typename meta_fn<Types...>::type;
    };
    
    // non-standard
    template<
        template<typename...>
        typename    MetaFunction,
        typename... Arguments
    > struct meta_bind_back {
        
        template<typename... Types>
        struct meta_fn {
            using type = typename MetaFunction<Types..., Arguments...>::type;
        };

        template<typename... Types>
        using meta_fn_t = typename meta_fn<Types...>::type;
    };
    
    template<
        auto invocation
    > struct meta_function_wrapper {
        template<typename... Params>
        struct meta_fn {
            using type = decltype(invocation(mylib::declval<Params>()...));
        };

        template<typename... Params>
        using meta_fn_t = typename meta_fn<Params...>::type;
    };
    
#   ifdef _MSVC_LANG
    
    // non-standard
    // msvc only
    template<
        template<typename...>
        typename    MetaFunction,
        typename... Arguments
    > struct meta_currying {
        
        template<typename... Types>
        struct meta_fn :
            mylib::meta_currying<MetaFunction, Arguments..., Types...>
        {
            using mylib::meta_currying<MetaFunction, Arguments..., Types...>::meta_fn;
        };

        using type = typename MetaFunction<Arguments...>::type;
    };
    
#   endif
    
    // non-standard
    // used through specialization
    template<typename Left, typename Right>
    struct meta_plus;

    // non-standard
    template<typename Left, typename Right>
    using meta_plus_t = typename mylib::meta_plus<Left, Right>::type;
    
    // non-standard
    // used through specialization
    template<typename Left, typename Right>
    struct meta_minus;

    // non-standard
    template<typename Left, typename Right>
    using meta_minus_t = typename mylib::meta_minus<Left, Right>::type;

    // non-standard
    // used through specialization
    template<typename Left, typename Right>
    struct meta_multiplies;

    // non-standard
    template<typename Left, typename Right>
    using meta_multiplies_t = typename mylib::meta_multiplies<Left, Right>::type;

    // non-standard
    // used through specialization
    template<typename Left, typename Right>
    struct meta_divides;

    // non-standard
    template<typename Left, typename Right>
    using meta_divides_t = typename mylib::meta_divides<Left, Right>::type;
    
    // non-standard
    // used through specialization
    template<typename Left, typename Right>
    struct meta_modulus;

    // non-standard
    template<typename Left, typename Right>
    using meta_modulus_t = typename mylib::meta_modulus<Left, Right>::type;

    // non-standard
    // used through specialization
    template<typename Left, typename Right>
    struct meta_negate;

    // non-standard
    template<typename Left, typename Right>
    using meta_negate_t = typename mylib::meta_negate<Left, Right>::type;

    
    template<typename Type, Type left, Type right>
    struct mylib::meta_plus<
        mylib::integral_constant<Type, left>,
        mylib::integral_constant<Type, right>
    >
    {
        using type = mylib::integral_constant<Type, left + right>;
    };

    template<typename Type, Type left, Type right>
    struct mylib::meta_multiplies<
        mylib::integral_constant<Type, left>,
        mylib::integral_constant<Type, right>
    >
    {
        using type = mylib::integral_constant<Type, left * right>;
    };

    // non-standard
    template<typename Left, typename Right>
    struct meta_euqal_to :
        mylib::bool_constant<(Left::value == Right::value)>
    {};

    // non-standard
    template<typename Left, typename Right>
    inline constexpr bool meta_euqal_to_v = Left::value == Right::value;

    // non-standard
    template<typename Left, typename Right>
    struct meta_not_euqal_to :
        mylib::bool_constant<(Left::value != Right::value)>
    {};

    // non-standard
    template<typename Left, typename Right>
    inline constexpr bool meta_not_equal_to_v = Left::value != Right::value;
    
    // non-standard
    template<typename Left, typename Right>
    struct meta_greater :
        mylib::bool_constant<(Left::value > Right::value)>
    {};

    // non-standard
    template<typename Left, typename Right>
    inline constexpr bool meta_greater_v = Left::value > Right::value;
    
    // non-standard
    template<typename Left, typename Right>
    struct meta_less :
        mylib::bool_constant<(Left::value < Right::value)>
    {};

    // non-standard
    template<typename Left, typename Right>
    inline constexpr bool meta_less_v = Left::value < Right::value;

    // non-standard
    template<typename Left, typename Right>
    struct meta_greater_equal :
        mylib::bool_constant<(Left::value >= Right::value)>
    {};

    // non-standard
    template<typename Left, typename Right>
    inline constexpr bool meta_greater_equal_v = Left::value >= Right::value;
    
    // non-standard
    template<typename Left, typename Right>
    struct meta_less_equal :
        mylib::bool_constant<(Left::value <= Right::value)>
    {};

    // non-standard
    template<typename Left, typename Right>
    inline constexpr bool meta_less_equal_v = Left::value <= Right::value;

    template<
        template<typename...>
        typename MetaPredicate
    > struct meta_not_fn {
        
        template<typename... Types>
        struct meta_fn :
            mylib::negation_t<MetaPredicate<Types...>>
        {};
    };
    
    template<typename Left, typename Right>
    struct meta_max {
        using type =
            mylib::conditional_t<
                meta_less<Left, Right>::type::value,
                Right,
                Left
            >;
    };
}
