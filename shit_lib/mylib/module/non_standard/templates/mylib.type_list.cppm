export module mylib.type_list;

import mylib.cstddef;
import mylib.type_pack;
import mylib.type_traits;
import mylib.meta_functional;


export namespace mylib {
    
    template<typename... Types>
    struct type_list;
}

export namespace mylib {
    
    template<typename TypeList>
    struct type_list_size;

    // non-standard
    // get index of first Type in TypeList,
    // or mylib::integral_constant<size_t, mylib::npos> if not found
    template<typename TypeList, typename Type>
    struct type_list_index_of;
    
    template<typename... Types, typename Type>
    struct type_list_index_of<mylib::type_list<Types...>, Type> :
        mylib::index_of_in_pack<Type, Types...>
    {};

    // non-standard
    // get index of first Type in TypeList, or mylib::npos if not found
    template<typename TypeList, typename Type>
    inline constexpr size_t type_list_index_of_v =
        mylib::type_list_index_of<TypeList, Type>::value;

    // non-standard
    // push some Types to the front of the TypeList
    // example: 
    // type_list_push_front<mylib::type_list<int>, double, char>::type
    // = mylib::type_list<double, char, int>
    template<typename TypeList, typename... Types>
    struct type_list_push_front;

    template<typename... Types0, typename... Types1>
    struct type_list_push_front<mylib::type_list<Types0...>, Types1...> {
        using type = mylib::type_list<Types1..., Types0...>;
    };
    
    template<typename TypeList, typename... Types>
    using type_list_push_front_t =
        typename mylib::type_list_push_front<TypeList, Types...>::type;

    template<typename TypeList, typename... Types>
    struct type_list_push_back;

    template<typename... Types0, typename... Types1>
    struct type_list_push_back<mylib::type_list<Types0...>, Types1...> {
        using type = mylib::type_list<Types1..., Types0...>;
    };
    
    template<typename TypeList, typename... Types>
    using type_list_push_back_t =
        typename mylib::type_list_push_back<TypeList, Types...>::type;

    template<typename TypeList, size_t index>
    struct type_list_at;

    template<typename Type, typename... Types, size_t index>
    struct type_list_at<mylib::type_list<Type, Types...>, index> {
        using type = mylib::at_pack_t<index, Types...>;
    };

    template<typename TypeList, size_t index>
    using type_list_at_t = typename mylib::type_list_at<TypeList, index>::type;
}

namespace mylib::detail {
    
    template<typename Result, typename... Types1>
    struct type_list_reverse_impl {
        using type = Result;
    };
    
    template<typename Type, typename... Types1, typename... Types2>
    struct type_list_reverse_impl<mylib::type_list<Types2...>, Type, Types1...> {
        using type =
            typename type_list_reverse_impl<
                mylib::type_list<Type, Types2...>,
                Types1...
            >::type;
    };
}

export namespace mylib {

    template<typename... Types>
    struct type_list_reverse {
        using type =
            typename mylib::detail::type_list_reverse_impl<
                mylib::type_list<>, Types...
            >::type;
    };

    template<typename... Types>
    using type_list_reverse_t = type_list_reverse<Types...>;

    template<typename... TypeLists>
    struct type_list_cat;
    
    template<>
    struct type_list_cat<> {
        using type = mylib::type_list<>;
    };

    template<typename... Types0, typename... Types1>
    struct type_list_cat<mylib::type_list<Types0...>, mylib::type_list<Types1...>>
    {
        using type = typename mylib::type_list<Types0..., Types1...>;
    };

    template<typename... Types, typename... TypeLists>
    struct type_list_cat<mylib::type_list<Types...>, TypeLists...> {
        using type =
            typename mylib::type_list_cat<
                mylib::type_list<Types...>,
                typename mylib::type_list_cat<TypeLists...>::type
            >::type;
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
    using to_type_list_t = typename mylib::to_type_list<Type>::type::type;
}

namespace mylib::detail {

    template<typename TypeList, size_t count, typename... Types>
    struct type_list_take_impl {
        using type = TypeList;
    };

    template<typename... Types1, size_t count, typename Type, typename... Types0>
        requires (count != 0)
    struct type_list_take_impl<mylib::type_list<Types1...>, count, Type, Types0...> {
        using type =
            typename type_list_take_impl<
                mylib::type_list<Types1..., Type>,
                count - 1,
                Types0...
            >::type;
    };
}

export namespace mylib {

    // avoid intellisense show `incomplete type`
#   ifdef __INTELLISENSE__
    
    template<typename TypeList, size_t count>
    struct type_list_take {
        template<typename TypeList>
        struct helper;
        
        template<typename... Types>
        struct helper<mylib::type_list<Types...>> {
            using type =
                typename mylib::detail::type_list_take_impl<
                    mylib::type_list<>, count, Types...
                >::type;
        };

        using type = typename helper<TypeList>::type;
    };
    
#   else

    template<typename TypeList, size_t count>
    struct type_list_take;
    
    template<typename... Types, size_t count>
    struct type_list_take<mylib::type_list<Types...>, count> {
        using type =
            typename mylib::detail::type_list_take_impl<
                mylib::type_list<>, count, Types...
            >::type;
    };
    
#   endif
    
    template<typename TypeList, size_t count>
    using type_list_take_t = typename mylib::type_list_take<TypeList, count>::type;
    
}

namespace mylib::detail {
    
    template<size_t count, typename... Types>
    struct type_list_drop_impl {
        using type = type_list<Types...>;
    };

    template<size_t count, typename Type, typename... Types>
        requires (count != 0)
    struct type_list_drop_impl<count, Type, Types...> {
        using type = typename type_list_drop_impl<count - 1, Types...>::type;
    };
}

export namespace mylib {
    
    template<typename TypeList, size_t count>
    struct type_list_drop;

    template<typename... Types, size_t count>
    struct type_list_drop<mylib::type_list<Types...>, count> {
        using type = typename mylib::detail::type_list_drop_impl<count, Types...>::type;
    };

    template<typename TypeList, size_t count>
    using type_list_drop_t = typename mylib::type_list_drop<TypeList, count>::type;
    
    template<typename TypeList, size_t count = 1>
    struct type_list_pop_front {
        using type = typename mylib::type_list_drop_t<TypeList, count>;
    };

    template<typename TypeList, size_t count = 1>
    using type_list_pop_front_t =
        typename mylib::type_list_pop_front<TypeList, count>::type;

    template<typename TypeList, size_t count = 1>
    struct type_list_pop_back;
    
    template<typename... Types, size_t count>
    struct type_list_pop_back<mylib::type_list<Types...>, count> {
        using type =
            mylib::type_list_take_t<mylib::type_list<Types...>, sizeof...(Types) - count>;
    };

    template<typename TypeList, size_t count = 1>
    using type_list_pop_back_t =
        typename mylib::type_list_pop_back<TypeList, count>::type;
}

namespace mylib::detail {
    
    template<typename... Types>
    struct type_list_join_impl;

    template<>
    struct type_list_join_impl<> {
        using type = mylib::type_list<>;
    };

    template<typename Type, typename... Types>
    struct type_list_join_impl<Type, Types...> {
        using type =
            mylib::type_list_push_front_t<
                typename type_list_join_impl<Types...>::type,
                Type
            >;
    };

    template<
        template<typename...>
        typename    Template,
        typename... Types0,
        typename... Types1
    > struct type_list_join_impl<Template<Types0...>, Types1...> {
        using type =
            mylib::type_list_push_front_t<
                typename type_list_join_impl<Types1...>::type,
                mylib::type_list<Types0...>
            >;
    };
}

export namespace mylib {

    template<typename TypeList>
    struct type_list_join;

    template<typename... Types>
    struct type_list_join<mylib::type_list<Types...>> {
        using type = typename mylib::detail::type_list_join_impl<Types...>::type;
    };
    
    template<typename TypeList>
    using type_list_join_t = typename mylib::type_list_join<TypeList>::type;

    // avoid intellisense show `incomplete type`
#   ifndef __INTELLISENSE__
    
    template<typename... TypeLists>
    struct type_list_cartesian_product;

    
    template<typename... Types>
    struct type_list_cartesian_product<mylib::type_list<Types...>> {
        using type = mylib::type_list<mylib::type_list<Types>...>;
    };

    template<typename... Types, typename... TypeLists>
    struct type_list_cartesian_product<mylib::type_list<Types...>, TypeLists...> {
        using type =
            mylib::type_list_cat_t<
                typename type_list_cartesian_product<TypeLists...>
              ::type
              ::template transform<
                    mylib::meta_bind_back<
                        mylib::type_list_push_back, Types
                    >::meta_fn
                >...
            >;
    };
    
#   else

    template<typename... TypeLists>
    struct type_list_cartesian_product {
    private:
        template<typename... TypeLists>
        struct helper;

        template<typename... Types>
        struct helper<mylib::type_list<Types...>> {
            using type = mylib::type_list<mylib::type_list<Types>...>;
        };

        template<typename... Types, typename... TypeLists>
        struct helper<mylib::type_list<Types...>, TypeLists...> {
            using type =
                mylib::type_list_cat_t<
                    typename type_list_cartesian_product<TypeLists...>
                  ::type
                  ::template transform<
                        mylib::meta_bind_back<
                            mylib::type_list_push_back, Types
                        >::meta_fn
                    >...
                >;
        };

    public:
        using type = typename helper<TypeLists...>::type;
    };


#   endif

    template<typename... TypeLists>
    using type_list_cartesian_product_t =
        typename mylib::type_list_cartesian_product<TypeLists...>::type;
    
    template<
        template<typename, typename>
        typename BinaryMetaPredicate,
        typename TypeList
    > struct sort_pack_impl {
        using type = TypeList;        
    };
        
    template<
        template<typename, typename>
        typename    BinaryMetaPredicate,
        typename    Type,
        typename... Types
    > struct sort_pack_impl<BinaryMetaPredicate, mylib::type_list<Type, Types...>> {
        using list = mylib::type_list<Types...>;
        template<typename Type1>
        using pred = mylib::meta_bind_front<BinaryMetaPredicate, Type>::meta_fn;
        
        using left_part =
            typename sort_pack_impl<
                BinaryMetaPredicate,
                typename list
              ::template filter<mylib::meta_not_fn<pred>::meta_fn>
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
}

namespace mylib::detail {
    
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
            typename mylib::detail::type_list_join_impl<Types...>::type;

        template<typename... TypeList>
        using cartesian_product =
            typename mylib::type_list_cartesian_product<
                mylib::type_list<Types...>, TypeList...
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
        > using fold = fold_left<BinaryMetaFunction, Initial>;
                    
        template<
            template<typename, typename>
            typename BinaryMetaFunction,
            typename Initial
        > using fold_right =
            mylib::fold_right_pack_t<BinaryMetaFunction, Initial, Types...>;
                    
#       ifndef __INTELLISENSE__
        
        template<bool = true>
        using reverse = typename mylib::type_list_reverse_t<Types...>::type;

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
            typename mylib::sort_pack_impl<
                BinaryMetaPredicate, type_list<Types...>
            >::type;

        static constexpr size_t size() noexcept {
            return sizeof...(Types);
        }
    };
}

export namespace mylib {
    
    // as a specialization rather than main template to avoid intellisense show `incomplete type`
#   ifdef __INTELLISENSE__
    template<typename... Types>
        requires (sizeof...(Types) != 0)
    struct type_list<Types...> :
#   else
    template<typename... Types>
    struct type_list :  
#   endif
        mylib::detail::type_list_base<Types...>
    {
        using type = type_list;

        template<size_t count>
        using take = mylib::detail::type_list_take_impl<type_list<>, count, Types...>;

        template<size_t count>
        using drop =
            typename mylib::detail::type_list_drop_impl<count, Types...>::type;

        template<size_t count = 1>
        using pop_front =
            drop<count>;

        template<size_t count = 1>
        using pop_back = take<sizeof...(Types) - count>;

        template<bool = true>
        using front = mylib::front_pack_t<Types...>;

        template<bool = true>
        using back  = mylib::back_pack_t<Types...>;

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
