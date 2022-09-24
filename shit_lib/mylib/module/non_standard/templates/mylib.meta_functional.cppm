export module mylib.meta_functional;

import mylib.type_pack;


export namespace mylib {
    
    template<
        template<typename...>
        typename    MetaFunction,
        typename... Arguments
    > struct meta_apply {
        using type = typename MetaFunction<Arguments...>::type;
    };

    template<
        template<typename...>
        typename    MetaFunction,
        typename... Arguments
    > using meta_apply_t =
        typename mylib::meta_apply<MetaFunction, Arguments...>::type;
    
    template<
        template<typename>
        typename    MetaFunction,
        template<typename...>
        typename... MetaFunctions
    > struct meta_compose {
        template<typename... Params>
        struct meta_func {
            using type =
                typename MetaFunction<
                    typename meta_compose<MetaFunctions...>
                  ::template meta_func<Params...>
                  ::type
                >::type;
        };
    };
    
    template<
        template<typename>
        typename MetaFunction
    > struct meta_compose<MetaFunction> {
        template<typename... Params>
        struct meta_func {
            using type = typename MetaFunction<Params...>::type;
        };
    };
    
    template<size_t index>
    struct meta_placeholder {
        static constexpr size_t value = index;
    };
    
    namespace meta_placeholders {
        
        using _0  = mylib::meta_placeholder<0>;
        using _1  = mylib::meta_placeholder<1>;
        using _2  = mylib::meta_placeholder<2>;
        using _3  = mylib::meta_placeholder<3>;
        using _4  = mylib::meta_placeholder<4>;
        using _5  = mylib::meta_placeholder<5>;
        using _6  = mylib::meta_placeholder<6>;
        using _7  = mylib::meta_placeholder<7>;
        using _8  = mylib::meta_placeholder<8>;
        using _9  = mylib::meta_placeholder<9>;
        using _10 = mylib::meta_placeholder<10>;
        using _11 = mylib::meta_placeholder<11>;
        using _12 = mylib::meta_placeholder<12>;
        using _13 = mylib::meta_placeholder<13>;
        using _14 = mylib::meta_placeholder<14>;
        using _15 = mylib::meta_placeholder<15>;
        using _16 = mylib::meta_placeholder<16>;
        using _17 = mylib::meta_placeholder<17>;
        using _18 = mylib::meta_placeholder<18>;
        using _19 = mylib::meta_placeholder<19>;
        using _10 = mylib::meta_placeholder<10>;
        using _21 = mylib::meta_placeholder<21>;
        using _22 = mylib::meta_placeholder<22>;
        using _23 = mylib::meta_placeholder<23>;
        using _24 = mylib::meta_placeholder<24>;
        using _25 = mylib::meta_placeholder<25>;
        using _26 = mylib::meta_placeholder<26>;
        using _27 = mylib::meta_placeholder<27>;
        using _28 = mylib::meta_placeholder<28>;
        using _29 = mylib::meta_placeholder<29>;
        using _30 = mylib::meta_placeholder<30>;
        using _31 = mylib::meta_placeholder<31>;
    }

    template<
        template<typename...>
        typename    MetaFunction,
        typename... Arguments
    > struct meta_bind {
        template<typename... Types>
        struct meta_func {
        
        };
    };
}
