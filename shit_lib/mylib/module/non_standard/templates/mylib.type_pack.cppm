export module mylib.type_pack;

import mylib.cstddef;
import mylib.type_traits;


namespace mylib {

    template<typename... Types>
    struct type_list;
}

export namespace mylib {
    
    // non-standard
    template<typename... TypesPack>
    struct front_pack;

    // non-standard
    template<typename Front, typename... TypesPack>
    struct front_pack<Front, TypesPack...> {
        using type = Front;
    };

    // non-standard
    template<typename... TypesPack>
    using front_pack_t = typename mylib::front_pack<TypesPack...>::type;
    
    template<typename... TypesPack>
    struct back_pack; // empty pack match this
    
    template<typename Front, typename... TypesPack>
    struct back_pack<Front, TypesPack...> {
        using type = typename mylib::back_pack<TypesPack...>::type;
    };
    
    template<typename Back>
    struct back_pack<Back> {
        using type = Back;
    };

    template<typename... TypesPack>
    using back_pack_t = typename mylib::back_pack<TypesPack...>::type;
    
    template<size_t index, typename... TypesPack>
    struct at_pack;

    template<size_t index, typename Front, typename... TypesPack>
    struct at_pack<index, Front, TypesPack...> {
        using type = at_pack<index - 1, TypesPack...>;
    };

    template<typename Front, typename... TypesPack>
    struct at_pack<0, Front, TypesPack...> {
        using type = Front;
    };

    template<size_t index, typename... TypesPack>
    using at_pack_t = typename mylib::at_pack<index, TypesPack...>::type;
    
}

namespace mylib::detail {

    template<size_t pos, typename Target, typename... TypesPack>
    struct index_of_in_pack_impl;

    // continue to find
    template<size_t pos, typename Target, typename Front, typename... TypesPack>
    struct index_of_in_pack_impl<pos, Target, Front, TypesPack...> :
        index_of_in_pack_impl<pos + 1, Target, TypesPack...>
    {};
    
    // found it!
    template<size_t pos, typename Target, typename... TypesPack>
    struct index_of_in_pack_impl<pos, Target, Target, TypesPack...> :
        mylib::integral_constant<size_t, pos>
    {};

    // not found
    template<size_t pos, typename Target>
    struct index_of_in_pack_impl<pos, Target> :
        mylib::integral_constant<size_t, mylib::npos>
    {};
}

export namespace mylib {

    template<typename Target, typename... TypesPack>
    inline constexpr size_t index_of_in_pack_v =
        mylib::detail::index_of_in_pack_impl<0, Target, TypesPack...>::value;

    template<typename Target, typename... TypesPack>
    struct index_of_in_pack :
        mylib::integral_constant<size_t, mylib::index_of_in_pack_v<Target, TypesPack...>>
    {};
    
    template<typename Target, typename... TypesPack>
    inline constexpr bool is_contain_in_pack_v =
        mylib::index_of_in_pack_v<Target, TypesPack...> != mylib::npos;
    
    template<typename Target, typename... TypesPack>
    struct is_contain_in_pack :
        mylib::bool_constant<mylib::is_contain_in_pack_v<Target, TypesPack...>>
    {};   

    template<typename Target, typename... TypesPack>
    struct is_unique_in_pack;

    // continue to find
    template<typename Target, typename Front, typename... TypesPack>
    struct is_unique_in_pack<Target, Front, TypesPack...> :
        is_unique_in_pack<Target, TypesPack...>
    {};
    
    // continue found other Target, if found, return false
    template<typename Target, typename... TypesPack>
    struct is_unique_in_pack<Target, Target, TypesPack...> :
        mylib::bool_constant<!mylib::is_contain_in_pack_v<Target, TypesPack...>>
    {};

    // not found
    template<typename Target>
    struct is_unique_in_pack<Target> :
        mylib::false_type
    {};

    template<typename Target>
    inline constexpr bool is_unique_in_pack_v =
        mylib::is_unique_in_pack<Target>::value;
    
    // empty pack match this
    template<typename... TypesPack>
    inline constexpr bool is_pack_unique_v = true;

    // continue try to find
    template<typename Front, typename Next, typename... TypesPack>
    inline constexpr bool is_pack_unique_v<Front, Next, TypesPack...> =
        is_pack_unique_v<Next, TypesPack...>;

    // exist consecutive duplicate elements
    template<typename Type, typename... TypesPack>
    inline constexpr bool  is_pack_unique_v<Type, Type, TypesPack...> =
        false;
    
    template<typename... TypesPack>
    struct is_pack_unique :
        mylib::bool_constant<mylib::is_pack_unique_v<TypesPack...>>
    {};

    template<
        template<typename, typename>
        typename    BinaryMetaPredicate,
        typename... Types1
    > struct is_pack_match_by {
        
        template<typename... Types2>
        static constexpr bool with_v = false;

        template<typename... Types2>
            requires (sizeof...(Types1) == sizeof...(Types2))
        static constexpr bool with_v<Types2...> =
            static_cast<bool>(
                mylib::conjunction_t<BinaryMetaPredicate<Types1, Types2>...>{}
            );

        template<typename... Types2>
        struct with :
            mylib::bool_constant<with_v<Types2...>>
        {};
    };
    
    template<typename... Types1>
    struct is_pack_same {             
        template<typename... Types2>
        static constexpr bool as_v =
            mylib::is_same_v<mylib::type_list<Types1...>, mylib::type_list<Types2...>>;
        
        template<typename... Types2>
        struct as :
            mylib::bool_constant<as_v<Types2...>>
        {};
    };
    
    template<typename... Types1>
    struct is_pack_convertible
    {
        template<typename... Types2>
        static constexpr bool to_v =
            static_cast<bool>(
                mylib::conjunction_t<mylib::is_convertible<Types1, Types2>...>{}
            );
        
        template<typename... Types2>
        struct to :
            mylib::bool_constant<to_v<Types2...>>
        {};
    };
    
    // non-standard
    template<
        template<typename, typename>
        typename    BinaryMetaPredicate,
        typename... Types1
    > struct is_prefix_by;

    // non-standard
    template<
        template<typename, typename>
        typename BinaryMetaPredicate
    > struct is_prefix_by<BinaryMetaPredicate> {

        template<bool cond, typename... Types2>
        struct helper :
            mylib::bool_constant<cond>
        {};
    
        template<typename... Types2>
        struct of :
            mylib::true_type
        {};

        template<typename... Types2>
        static constexpr bool of_v = true;
    };

    // non-standard
    template<
        template<typename, typename>
        typename    BinaryMetaPredicate,
        typename    Type1,
        typename... Types1
    > struct is_prefix_by<BinaryMetaPredicate, Type1, Types1...> {
    private:
        
        template<
            template<typename, typename>
            typename,
            typename...
        > friend struct is_prefix_by;
        
        template<bool cond, typename... Types2>
        struct helper :
            mylib::false_type
        {};

        template<typename Type2, typename... Types2>
        struct helper<true, Type2, Types2...> :
                mylib::bool_constant<
                    is_prefix_by<BinaryMetaPredicate, Types1...>::
                        template helper<
                            static_cast<bool>(BinaryMetaPredicate<Type1, Type2>{}),
                            Types2...
                        >::value
                >
        {};
    
    public:
        template<typename... Types2>
        static constexpr bool of_v = false;

        template<typename... Types2>
            requires (sizeof...(Types1) <= sizeof...(Types2))
        static constexpr bool of_v<Types2...> = helper<true, Types2...>::value;
        
        template<typename... Types2>
        struct of :
            mylib::bool_constant<of_v<Types2...>>
        {};
    };

    // non-standard
    template<typename... Types1>
    struct is_prefix :
        mylib::is_prefix_by<mylib::is_same, Types1...>
    {};

    // non-standard
    template<typename... Types1>
    struct is_convertible_prefix :
        mylib::is_prefix_by<mylib::is_convertible, Types1...>
    {};

    template<
        template<typename, typename>
        typename    BinaryMetaPredicate,
        typename... Types1
    > struct is_suffix_by {
        
    };

    template<
        template<typename, typename>
        typename    BinaryMetaFunction,
        typename    Initial,
        typename... Types
    > struct fold_left_pack {
        using type = Initial;
    };

    template<
        template<typename, typename>
        typename    BinaryMetaFunction,
        typename    Initial,
        typename    Type,
        typename... Types
    > struct fold_left_pack<BinaryMetaFunction, Initial, Type, Types...> {
        using type =
            typename fold_left_pack<
                BinaryMetaFunction,
                typename BinaryMetaFunction<Initial, Type>::type,
                Types...
            >::type;
    };

    template<
        template<typename, typename>
        typename    BinaryMetaFunction,
        typename    Initial,
        typename... Types
    > using fold_left_pack_t =
        typename fold_left_pack<BinaryMetaFunction, Initial, Types...>::type;
    
    template<
        template<typename, typename>
        typename    BinaryMetaFunction,
        typename    Type,
        typename... Types
    > struct fold_1eft_pack {
        using type = fold_left_pack_t<BinaryMetaFunction, Type, Types...>;
    };
    
    template<
        template<typename, typename>
        typename    BinaryMetaFunction,
        typename... Types
    > struct fold_left_first_pack {
        using type = typename fold_1eft_pack<BinaryMetaFunction, Types...>::type;
    };
        
    template<
        template<typename, typename>
        typename    BinaryMetaFunction,
        typename... Types
    > using fold_left_first_pack_t =
        typename fold_left_first_pack<BinaryMetaFunction, Types...>::type;
    
    template<
        template<typename, typename>
        typename    BinaryMetaFunction,
        typename    Initial,
        typename... Types
    > using fold_pack =
        typename fold_left_pack<BinaryMetaFunction, Initial, Types...>::type;

    template<
        template<typename, typename>
        typename    BinaryMetaFunction,
        typename    Initial,
        typename... Types
    > using fold_pack_t =
        typename fold_pack<BinaryMetaFunction, Initial, Types...>::type;

    template<
        template<typename, typename>
        typename    BinaryMetaFunction,
        typename... Types
    > using fold_first_pack =
        typename fold_left_first_pack<BinaryMetaFunction, Types...>::type;

    template<
        template<typename, typename>
        typename    BinaryMetaFunction,
        typename... Types
    > using fold_first_pack_t =
        typename fold_first_pack<BinaryMetaFunction, Types...>::type;
    
    template<
        template<typename, typename>
        typename    BinaryMetaFunction,
        typename... Types
    > struct fold_right_first_pack;
    
    template<
        template<typename, typename>
        typename    BinaryMetaFunction,
        typename    Type,
        typename... Types
    > struct fold_right_first_pack<BinaryMetaFunction, Type, Types...> {
        using type =
            typename BinaryMetaFunction<
                Type,
                typename fold_right_first_pack<BinaryMetaFunction, Types...>::type
            >::type;
    };

    template<
        template<typename, typename>
        typename BinaryMetaFunction,
        typename Type
    > struct fold_right_first_pack<BinaryMetaFunction, Type> {
        using type = Type;
    };
    
    template<
        template<typename, typename>
        typename BinaryMetaFunction,
        typename Type1,
        typename Type2
    > struct fold_right_first_pack<BinaryMetaFunction, Type1, Type2> {
        using type = typename BinaryMetaFunction<Type1, Type2>::type;
    };
    
    template<
        template<typename, typename>
        typename    BinaryMetaFunction,
        typename... Types
    > using fold_right_first_pack_t =
        typename fold_right_first_pack<BinaryMetaFunction, Types...>::type;
    
    template<
        template<typename, typename>
        typename    BinaryMetaFunction,
        typename    Initial,
        typename... Types
    > struct fold_right_pack {
        using type = mylib::fold_right_first_pack_t<BinaryMetaFunction, Types..., Initial>;
    };

    template<
        template<typename, typename>
    typename    BinaryMetaFunction,
        typename    Initial,
        typename... Types
    > using fold_right_pack_t =
        typename mylib::fold_right_pack<BinaryMetaFunction, Initial, Types...>::type;
}
