export module mylib.type_list;

import mylib.type_traits;


export namespace mylib {
    
    template<typename... Types>
    struct type_list;
    
    // non-standard
    template<typename... Types>
    struct front_pack;

    // non-standard
    template<typename Type, typename... Types>
    struct front_pack<Type, Types...> {
        using type = Type;
    };

    // non-standard
    template<typename... Types>
    using front_pack_t = typename mylib::front_pack<Types...>::type;
    
    template<typename... Types>
    struct back_pack; // empty pack match this
    
    template<typename Type, typename... Types>
    struct back_pack<Type, Types...> {
        using type = typename mylib::back_pack<Types...>::type;
    };
    
    template<typename Type>
    struct back_pack<Type> {
        using type = Type;
    };

    template<typename... Types>
    using back_pack_t = typename mylib::back_pack<Types...>::type;
    
    template<size_t index, typename... Types>
    struct at_pack;

    template<size_t index, typename Type, typename... Types>
    struct at_pack<index, Type, Types...> {
        using type = at_pack<index - 1, Types...>;
    };

    template<typename Type, typename... Types>
    struct at_pack<0, Type, Types...> {
        using type = Type;
    };

    template<size_t index, typename... Types>
    using at_pack_t = typename mylib::at_pack<index, Types...>::type;
    
    template<
        template<typename, typename>
        typename    BinaryMetaPredicate,
        typename... Types1
    > struct is_match_by {
        
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
}

namespace mylib::detail {
    
    template<typename Result, typename... Types1>
    struct reverse_pack_impl {
        using type = Result;
    };
    
    template<typename Type, typename... Types1, typename... Types2>
    struct reverse_pack_impl<mylib::type_list<Types2...>, Type, Types1...> {
        using type =
            typename reverse_pack_impl<
                mylib::type_list<Type, Types2...>,
                Types1...
            >::type;
    };
}

export namespace mylib {

    template<typename... Types>
    struct reverse_pack {
        using type =
            typename mylib::detail::reverse_pack_impl<
                mylib::type_list<>, Types...
            >::type;
    };

    template<typename... Types>
    using reverse_pack_t = reverse_pack<Types...>;

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
    
    template<typename... Types>
    struct type_list_cat {
        using type = type_list<Types...>;
    };
    
    template<typename... Types, typename... Types2>
    struct type_list_cat<mylib::type_list<Types...>, Types2...>
    {
        using type = typename type_list_cat<Types2..., Types...>::type;
    };
    
    template<typename... Types>
    using type_list_cat_t = typename mylib::type_list_cat<Types...>::type;

    template<typename Type>
    struct to_type_list;

    template<typename Type, Type... values>
    struct to_type_list<mylib::integer_sequence<Type, values...>> {
        using type = mylib::type_list<mylib::integral_constant<Type, values>...>;
    };
    
    template<
        template<typename...>
        typename    Template,
        typename... Types
    > struct to_type_list<Template<Types...>> {
        using type = mylib::type_list<Types...>;
    };
    
    template<typename Type>
    using to_type_list_t = typename mylib::to_type_list<Type>::type;
}

export namespace mylib::detail {

    template<size_t count, typename TypeList, typename... Types>
    struct type_list_take_impl {
        using type = TypeList;
    };

    template<size_t count, typename Type, typename... Types0, typename... Types1>
        requires (count != 0)
    struct type_list_take_impl<count, mylib::type_list<Types1...>, Type, Types0...> {
        using type =
            typename type_list_take_impl<
                count - 1,
                mylib::type_list<Types1..., Type>,
                Types0...
            >::type;
    };

    template<size_t count, typename... Types>
    struct type_list_drop_impl {
        using type = type_list<Types...>;
    };

    template<size_t count, typename Type, typename... Types>
        requires (count != 0)
    struct type_list_drop_impl<count, Type, Types...> {
        using type = typename type_list_drop_impl<count - 1, Types...>::type;
    };
    
    template<typename... Types>
    struct type_list_pop_front_impl;

    template<typename Type, typename... Types>
    struct type_list_pop_front_impl<Type, Types...> {
        using type = mylib::type_list<Types...>;
    };

    template<
        template<typename...>
        typename MetaPredicate
    > struct not_meta_func {
        template<typename... Types>
        struct temp :
            mylib::negation_t<typename MetaPredicate<Types...>::type>
        {};
    };
    
    template<
        template<typename, typename>
        typename BinaryMetaPredicate,
        typename TypeList
    > struct sort_pack_impl {
        using type = TypeList;        
    };
    
    template<
        template<typename, typename>
        typename BinaryMetaPredicate,
        typename partition
    > struct sort_filter_pred {
        template<typename Type>
        struct temp :
            BinaryMetaPredicate<partition, Type>
        {};
    };
        
    template<
        template<typename, typename>
        typename    BinaryMetaPredicate,
        typename    Type,
        typename... Types
    > struct sort_pack_impl<BinaryMetaPredicate, mylib::type_list<Type, Types...>> {
        using list     = mylib::type_list<Types...>;
        template<typename Type1>
        using pred     =
            mylib::detail::sort_filter_pred<
                BinaryMetaPredicate, Type
            >::template temp<Type1>;
        using not_pred = mylib::detail::not_meta_func<pred>;
        
        using left_part =
            typename sort_pack_impl<
                BinaryMetaPredicate,
                typename list
              ::template filter<not_pred::temp>
            >::type;
        
        using right_part =
            typename sort_pack_impl<
                BinaryMetaPredicate,
                typename list
              ::template filter<pred>
            >::type
          ::template push_front<Type>;
        
        using type =
            mylib::type_list_cat_t<
                left_part,
                right_part
            >;
    };

    template<typename... Types>
    struct type_list_base {
        
        template<typename... Types1>
        using append_front =
            type_list_cat_t<
                mylib::to_type_list<Types1>..., type_list<Types...>
            >;
        
        template<typename... Types1>
        using append_back  =
            mylib::type_list_cat_t<
                type_list<Types...>, mylib::to_type_list_t<Types1>...
            >;

        template<typename... Types1>
        using push_front   = type_list<Types1..., Types...>;       

        template<typename... Types1>
        using push_back    = type_list<Types..., Types1...>;

        template<
            template<typename>
            typename UnaryMetaFunction
        > using transform = type_list<typename UnaryMetaFunction<Types>::type...>;
        
        template<
            template<typename...>
            typename Template
        > using to = Template<Types...>;
        
    private:
        struct to_integer_sequence_impl {
            template<typename... IntegralSequences>
            struct helper {
                using type = mylib::integer_sequence<size_t>;
            };

            template<typename Type, Type... values>
            struct helper<mylib::integral_constant<Type, values>...> {
                using type = mylib::integer_sequence<Type, values...>;
            };

            using type = typename helper<Types...>::type;
        };

    public:

        template<bool = true>
            requires (!mylib::is_same_v<typename to_integer_sequence_impl::type, void>)
        using to_integer_sequence = typename to_integer_sequence_impl::type;
                
        template<
            template<typename, typename>
            typename BinaryMetaFunction,
            typename Initial
        > using fold_left =
            mylib::fold_left_pack_t<BinaryMetaFunction, Initial, Types...>;
                    
        template<
            template<typename, typename>
            typename BinaryMetaFunction,
            typename Initial
        > using fold_right =
            mylib::fold_right_pack_t<BinaryMetaFunction, Initial, Types...>;
                    
#       ifndef __INTELLISENSE__
        
        template<bool = true>
        using reverse = typename mylib::reverse_pack_t<Types...>::type;

#       else
        
        template<bool = true>
        using reverse = type_list<>;

#       endif
        
        template<
            template<typename>
            typename UnaryMetaPredicate
        > using filter = 
            type_list_cat_t<
                mylib::conditional_t<
                    UnaryMetaPredicate<Types>::value,
                    type_list<Types>,
                    type_list<>
                >...
            >;
        
        template<
            template<typename, typename>
            typename BinaryMetaPredicate
        > using sort =
            typename mylib::detail::sort_pack_impl<
                BinaryMetaPredicate, type_list<Types...>
            >::type;

        static constexpr size_t size() noexcept {
            return sizeof...(Types);
        }
    };
}

export namespace mylib {
    
    template<typename... Types>
    struct type_list :
        mylib::detail::type_list_base<Types...>
    {
        using type = type_list;

        template<size_t count>
        using take =
            typename mylib::detail::type_list_take_impl<
                count, mylib::type_list<>, Types...
            >::type;

        template<size_t count>
        using drop =
            typename mylib::detail::type_list_drop_impl<count, Types...>::type;

        template<bool = true>
        using pop_front =
            typename mylib::detail::type_list_pop_front_impl<Types...>::type;

        template<bool = true>
        using pop_back = take<sizeof...(Types) - 1>;

        template<bool = true>
        using front = mylib::front_pack_t<Types...>;

        template<bool = true>
        using back = mylib::back_pack_t<Types...>;

        template<bool = true>
        using head = pop_back<>;

        template<bool = true>
        using tail = pop_front<>;

        template<size_t index>
        using at = mylib::at_pack_t<index, Types...>;

        template<
            template<typename, typename>
            typename BinaryMetaFunction
        > using fold_left_first =
            mylib::fold_left_first_pack_t<BinaryMetaFunction, Types...>;

        template<
            template<typename, typename>
            typename BinaryMetaFunction
        > using fold_right_first =
            mylib::fold_right_first_pack_t<BinaryMetaFunction, Types...>;
    };

    template<>
    struct type_list<> :
        mylib::detail::type_list_base<>
    {
        using type = type_list;
    };
}
