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
        using meta_fn =
                MetaFunction<
                    typename meta_compose<MetaFunctions...>
                  ::template meta_fn<Params...>
                  ::type
                >;

        template<typename... Params>
        using meta_fn_t = typename meta_fn<Params...>::type;

        template<typename... Params>
        static constexpr auto meta_fn_v = meta_fn<Params...>::value;
    };
    
    // non-standard
    template<
        template<typename>
        typename MetaFunction
    > struct meta_compose<MetaFunction> {
        
        template<typename... Params>
        using meta_fn   = MetaFunction<Params...>;
        
        template<typename... Params>
        using meta_fn_t = typename meta_fn<Params...>::type;

        template<typename... Params>
        static constexpr auto meta_fn_v = meta_fn<Params...>::value;
    };
    
    // non-standard
    template<int index>
    struct placeholder
    {};

    // non-standard
    template<typename Type>
    struct is_placeholder :
        mylib::constant<int, 0>
    {};

    // non-standard
    template<int index>
    struct is_placeholder<mylib::placeholder<index>> :
        mylib::constant<int, index>
    {};
    
    // non-standard
    template<typename Type>
    inline constexpr int is_placeholder_v = mylib::is_placeholder<Type>::value;

    namespace placeholders {
        
        // non-standard
        using _1t  = mylib::placeholder<1>;
        // non-standard
        using _2t  = mylib::placeholder<2>;
        // non-standard
        using _3t  = mylib::placeholder<3>;
        // non-standard
        using _4t  = mylib::placeholder<4>;
        // non-standard
        using _5t  = mylib::placeholder<5>;
        // non-standard
        using _6t  = mylib::placeholder<6>;
        // non-standard
        using _7t  = mylib::placeholder<7>;
        // non-standard
        using _8t  = mylib::placeholder<8>;
        // non-standard
        using _9t  = mylib::placeholder<9>;
        // non-standard
        using _10t = mylib::placeholder<10>;
        // non-standard
        using _11t = mylib::placeholder<11>;
        // non-standard
        using _12t = mylib::placeholder<12>;
        // non-standard
        using _13t = mylib::placeholder<13>;
        // non-standard
        using _14t = mylib::placeholder<14>;
        // non-standard
        using _15t = mylib::placeholder<15>;
        // non-standard
        using _16t = mylib::placeholder<16>;
        // non-standard
        using _17t = mylib::placeholder<17>;
        // non-standard
        using _18t = mylib::placeholder<18>;
        // non-standard
        using _19t = mylib::placeholder<19>;
        // non-standard
        using _10t = mylib::placeholder<10>;
        // non-standard
        using _21t = mylib::placeholder<21>;
        // non-standard
        using _22t = mylib::placeholder<22>;
        // non-standard
        using _23t = mylib::placeholder<23>;
        // non-standard
        using _24t = mylib::placeholder<24>;
        // non-standard
        using _25t = mylib::placeholder<25>;
        // non-standard
        using _26t = mylib::placeholder<26>;
        // non-standard
        using _27t = mylib::placeholder<27>;
        // non-standard
        using _28t = mylib::placeholder<28>;
        // non-standard
        using _29t = mylib::placeholder<29>;
        // non-standard
        using _30t = mylib::placeholder<30>;
        // non-standard
        using _31t = mylib::placeholder<31>;
        // non-standard
        using _32t = mylib::placeholder<32>;
        // non-standard
        template<size_t index>
        using _nt  = mylib::placeholder<index>;
    }

    // non-standard
    template<
        template<typename...>
        typename    MetaFunction,
        typename... Arguments
    > struct meta_bind {
    private:
        template<typename... Types>
        struct meta_fn_helper {
        private:
            template<typename TypeList, typename... Types0>
            struct helper;

            template<typename... Types0, typename Type, typename... Types1>
                requires (mylib::is_placeholder_v<Type> != 0)
            struct helper<mylib::type_list<Types0...>, Type, Types1...> {
                using type =
                    typename helper<
                        mylib::type_list<
                            Types0...,
                            mylib::at_pack_t<
                                mylib::is_placeholder_v<Type> - 1,
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
                using type = typename MetaFunction<Types0...>;
            };
            
        public:
            using type = typename helper<mylib::type_list<>, Arguments...>::type;
        };

    public:
        template<typename... Types>
        using meta_fn = typename meta_fn_helper<Types...>::type;
        
        template<typename... Types>
        using meta_fn_t = typename meta_fn<Types...>::type;

        template<typename... Types>
        static constexpr auto meta_fn_v = meta_fn<Types...>::value;
    };
        
    // non-standard
    template<
        template<typename...>
        typename    MetaFunction,
        typename... Arguments
    > struct meta_bind_front {
        
        template<typename... Types>
        using meta_fn   = MetaFunction<Arguments..., Types...>;

        template<typename... Types>
        using meta_fn_t = typename meta_fn<Types...>::type;

        template<typename... Types>
        static constexpr auto meta_fn_v = meta_fn<Types...>::value;
    };
    
    // non-standard
    template<
        template<typename...>
        typename    MetaFunction,
        typename... Arguments
    > struct meta_bind_back {
        
        template<typename... Types>
        using meta_fn   = MetaFunction<Types..., Arguments...>;

        template<typename... Types>
        using meta_fn_t = typename meta_fn<Types...>::type;

        template<typename... Types>
        static constexpr auto meta_fn_v = meta_fn<Types...>::value;
    };
    
    template<
        auto invocation
    > struct meta_function_wrapper {
        template<typename... Params>
        using meta_fn = decltype(invocation(mylib::declval<Params>()...));

        template<typename... Params>
        using meta_fn_t = typename meta_fn<Params...>::type;

        template<typename... Types>
        static constexpr auto meta_fn_v = meta_fn<Types...>::value;
    };
    
    // non-standard
    template<
        template<typename...>
        typename    MetaFunction,
        typename... Arguments
    > struct meta_currying {
        
        template<typename... Params>
        using meta_fn   = meta_currying<MetaFunction, Arguments..., Params...>;

        using type      = MetaFunction<Arguments...>;
    };
    
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
    template<typename operand>
    struct meta_negate;

    // non-standard
    template<typename operand>
    using meta_negate_t = typename mylib::meta_negate<operand>::type;

    
    template<typename Type, Type left, Type right>
    struct mylib::meta_plus<
        mylib::constant<Type, left>,
        mylib::constant<Type, right>
    > : mylib::constant<Type, left + right>
    {};

    template<typename Type, Type left, Type right>
    struct mylib::meta_minus<
        mylib::constant<Type, left>,
        mylib::constant<Type, right>
    > : mylib::constant<Type, left - right>
    {};

    template<typename Type, Type left, Type right>
    struct mylib::meta_multiplies<
        mylib::constant<Type, left>,
        mylib::constant<Type, right>
    > : mylib::constant<Type, left * right>
    {};

    template<typename Type, Type left, Type right>
    struct mylib::meta_divides<
        mylib::constant<Type, left>,
        mylib::constant<Type, right>
    > : mylib::constant<Type, left / right>
    {};

    template<typename Type, Type left, Type right>
    struct mylib::meta_modulus<
        mylib::constant<Type, left>,
        mylib::constant<Type, right>
    > : mylib::constant<Type, left % right>
    {};

    template<typename Type, Type value>
    struct mylib::meta_negate<
        mylib::constant<Type, value>
    > : mylib::negation<mylib::constant<Type, value>>
    {};
    
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
        using meta_fn = mylib::negation_t<MetaPredicate<Types...>>;
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
