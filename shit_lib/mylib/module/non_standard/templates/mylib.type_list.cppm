export module mylib.type_list;

import mylib.type_pack;
import mylib.type_traits;

export namespace mylib {
    
    template<typename... Types>
    struct type_list;
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
        using type = mylib::type_list<Types...>::type;
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

    template<typename TypeList>
    struct type_list_join_impl;

    template<
        template<typename...>
        typename    Template,
        typename... Types0,
        typename... Types1
    > struct type_list_join_impl<mylib::type_list<Template<Types0...>, Types1...>> {
        using type =
            mylib::type_list_cat_t<
                mylib::type_list<Types0...>,
                typename type_list_join_impl<mylib::type_list<Types1...>>::type
            >;
    };

    template<typename Type, typename... Types>
    struct type_list_join_impl<mylib::type_list<Type, Types...>> {
        using type =
            mylib::type_list_cat_t<
                mylib::type_list<Type>,
                typename type_list_join_impl<mylib::type_list<Types...>>::type
            >;
    };

    template<>
    struct type_list_join_impl<mylib::type_list<>> {
        using type = mylib::type_list<>;
    };
    
    template<typename... Types>
    struct type_list_cartesian_product_helper {
        template<typename Type>
        struct meta_func {
            using type = mylib::type_list<mylib::type_list<Type, Types>...>;
        };
    };

    template<typename TypeList0, typename TypeList1>
    struct type_list_cartesian_product;

    template<typename... Types0, typename... Types1>
    struct type_list_cartesian_product<
        mylib::type_list<Types0...>, mylib::type_list<Types1...>
    >
    {
        using type =
            mylib::type_list<Types0...>
          ::template transform<
                mylib::detail::type_list_cartesian_product_helper<
                    Types1...
                >::template meta_func
            >;
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
        
        template<typename Target>
        using index_of                    = mylib::index_of_in_pack<Target, Types...>;
        
        template<typename Target>
        static constexpr bool index_of_v  = index_of<Target>;
        
        template<typename... Targets>
        using contain =
            mylib::conjunction_t<mylib::is_contain_in_pack<Targets, Types...>...>;

        template<typename... Targets>
        static constexpr bool contain_v   = contain<Targets...>::value;
        
        template<typename... Targets>
        struct is_unique :
            mylib::conjunction_t<
                mylib::is_unique_in_pack<Targets, Types...>...
            >
        {};

        template<>
        struct is_unique<> :
            mylib::is_pack_unique<Types...>
        {};
        
        template<typename Target = mylib::nullarg>
        static constexpr bool is_unique_v = is_unique<Target>::value;

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
        > using transform  = type_list<typename UnaryMetaFunction<Types>::type...>;
        
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
        using to_integer_sequence = typename to_integer_sequence_impl::type;
        
        template<bool = true>
        using join                =
            typename mylib::detail::type_list_join_impl<
                mylib::type_list<Types...>
            >::type;

        template<typename TypeList>
        using cartesian_product =
            typename mylib::detail::type_list_cartesian_product<
                mylib::type_list<Types...>, TypeList
            >::type;

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
