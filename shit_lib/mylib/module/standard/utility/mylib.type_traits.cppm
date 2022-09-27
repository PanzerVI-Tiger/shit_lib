module;

#ifdef __INTELLISENSE__

#include <tuple>
#include <cstddef>

#endif

export module mylib.type_traits;

#ifndef __INTELLISENSE__

import std.core;

#endif


export namespace mylib {

    // non-standard
    template<typename Type, Type typeValue>
    struct constant {
        using value_type = Type;
        using type       = constant;

        // C++11
        constexpr operator value_type() const noexcept {
            return typeValue;
        }

        // C++14
        constexpr value_type operator ()() const noexcept {
            return typeValue;
        }

        static constexpr value_type value = typeValue;
    };

    // C++17
    template<bool boolValue>
    using bool_constant = mylib::constant<bool, boolValue>;

    // C++11
    using true_type  = mylib::bool_constant<true>;
    // C++11
    using false_type = mylib::bool_constant<false>;

    // is ^^ better than vv? 
    // using new methon to implement them all!

    // using true_type  = mylib::constant<bool, true>;
    // using false_type = mylib::constant<bool, false>;

    // non-standard
    template<typename Type, Type... constants>
    struct sequence {
        using value_type = Type;

        // C++11
        static constexpr size_t size() noexcept {
            return sizeof...(constants);
        }
    };

    // C++17
    template<typename BoolConstant>
    struct negation :
        mylib::bool_constant<!static_cast<bool>(BoolConstant::value)> {
    };

    // C++17
    template<typename BoolConstant>
    using negation_t = typename mylib::negation<BoolConstant>::type;

    // C++11
    template<bool cond, typename TrueCase, typename FalseCase>
    struct conditional {
        using type = TrueCase;
    };

    // C++11
    template<typename TrueCase, typename FalseCase>
    struct conditional<false, TrueCase, FalseCase> {
        using type = FalseCase;
    };

    // C++14
    template<bool cond, typename TrueCase, typename FalseCase>
    using conditional_t = typename conditional<cond, TrueCase, FalseCase>::type;
}

namespace mylib::detail {
    // use disjunction_impl to avoid too many inherit
    // implementation
    template<bool firstValue, typename FirstConstant, typename... BoolConstants>
    struct conjunction_impl { // handle false case and end, will end try
        using type = FirstConstant;
    };

    // implementation
    template<typename FirstConstant, typename NextConstant, typename... BoolConstants>
    struct conjunction_impl<true, FirstConstant, NextConstant, BoolConstants...> {
        // handle false case, then try to next
        using type =
            typename conjunction_impl<
                static_cast<bool>(NextConstant::value),
                NextConstant,
                BoolConstants...
            >::type;
    };
}

export namespace mylib {

    // C++17
    template<typename... BoolConstants>
    struct conjunction :
        mylib::true_type // if BoolConstants is empty, true_type
    {};

    // C++17
    template<typename BoolConstant1, typename... BoolConstants>
    struct conjunction<BoolConstant1, BoolConstants...> :
        mylib::detail::conjunction_impl<
            BoolConstant1::value, BoolConstant1, BoolConstants...
        > 
    {};

    // C++17
    template<typename... BoolConstants>
    using conjunction_t = typename conjunction<BoolConstants...>::type;
}

namespace mylib::detail {
    // use disjunction_impl to avoid too many inherit
    // implementation
    template<bool firstValue, typename FirstConstant, typename... BoolConstants>
    struct disjunction_impl { // handle true case and end, will end try
        using type = FirstConstant;
    };

    // implementation
    template<typename FirstConstant, typename NextConstant, typename... BoolConstants>
    struct disjunction_impl<false, FirstConstant, NextConstant, BoolConstants...> {
        // handle false case, then try to next
        using type =
            typename disjunction_impl<
                static_cast<bool>(NextConstant::value),
                NextConstant,
                BoolConstants...
            >::type;
    };
}

export namespace mylib {

    // C++17
    template<typename... BoolConstants>
    struct disjunction :
        mylib::false_type // if BoolConstants is empty, false_type
    {
    };

    // C++17
    template<typename BoolConstant1, typename... BoolConstants>
    struct disjunction<BoolConstant1, BoolConstants...> :
        mylib::detail::disjunction_impl<
        BoolConstant1::value, BoolConstant1, BoolConstants...
        > {
    };

    // C++17
    template<typename... BoolConstants>
    using disjunction_t = typename mylib::disjunction<BoolConstants...>::type;

    // C++20
    template<typename Type>
    struct type_identity {
        using type = Type;
    };

    // C++20
    template<typename Type>
    using type_identity_t = typename mylib::type_identity<Type>::type;

    // C++17
    template<typename...>
    using void_t = void;

    // non-standard
    template<typename...>
    inline constexpr bool always_true  = true;

    // non-standard
    template<typename...>
    inline constexpr bool always_false = false;

    // C++11
    template<typename Type>
    struct remove_const {
        using type = Type;
    };

    // C++11
    template<typename Type>
    struct remove_const<const Type> {
        using type = Type;
    };

    // C++14
    template<typename Type>
    using remove_const_t = typename mylib::remove_const<Type>::type;

    // C++11
    template<typename Type>
    struct remove_volatile {
        using type = Type;
    };

    // C++11
    template<typename Type>
    struct remove_volatile<volatile Type> {
        using type = Type;
    };

    // C++14
    template<typename Type>
    using remove_volatile_t = typename mylib::remove_volatile<Type>::type;

    // C++11
    template<typename Type>
    struct remove_cv {
        using type = Type;
    };

    // C++11
    template<typename Type>
    struct remove_cv<const Type> {
        using type = Type;
    };

    // C++11
    template<typename Type>
    struct remove_cv<volatile Type> {
        using type = Type;
    };

    // C++11
    template<typename Type>
    struct remove_cv<const volatile Type> {
        using type = Type;
    };

    // C++14
    template<typename Type>
    using remove_cv_t = typename mylib::remove_cv<Type>::type;

    // C++11
    template<typename Type>
    struct add_const {
        using type = const Type;
    };

    // C++14
    template<typename Type>
    using add_const_t = typename mylib::add_const<Type>::type;

    // C++11
    template<typename Type>
    struct add_volatile {
        using type = volatile Type;
    };

    // C++14
    template<typename Type>
    using add_volatile_t = typename mylib::add_volatile<Type>::type;

    // C++11
    template<typename Type>
    struct add_cv {
        using type = const volatile Type;
    };

    // C++14
    template<typename Type>
    using add_cv_t = typename mylib::add_cv<Type>::type;

    // C++11
    template<typename Type>
    struct remove_reference {
        using type = Type;
    };

    // C++11
    template<typename Type>
    struct remove_reference<Type&> {
        using type = Type;
    };

    // C++11
    template<typename Type>
    struct remove_reference<Type&&> {
        using type = Type;
    };

    // C++14
    template<typename Type>
    using remove_reference_t = typename mylib::remove_reference<Type>::type;

    // non-standard
    template<typename Type, typename = void>
    struct add_reference {
        using lvalue_reference = Type;
        using rvalue_reference = Type;
    };

    // non-standard
    template<typename Type>
    struct add_reference<Type, mylib::void_t<Type&>> {
        using lvalue_reference = Type&;
        using rvalue_reference = Type&&;
    };

    // C++11
    template<typename Type>
    struct add_rvalue_reference {
        using type = typename mylib::add_reference<Type>::rvalue_reference;
    };

    // C++14
    template<typename Type>
    using add_rvalue_reference_t = typename mylib::add_rvalue_reference<Type>::type;

    // C++11
    template<typename Type>
    struct add_lvalue_reference {
        using type = typename mylib::add_reference<Type>::lvalue_reference;
    };

    // C++14
    template<typename Type>
    using add_lvalue_reference_t = typename mylib::add_lvalue_reference<Type>::type;

    // define declval from utility,
    // to avoid circular dependency and import whole utility,
    template<typename Type>
    mylib::add_rvalue_reference_t<Type> declval() noexcept {
        static_assert(mylib::always_false<Type>, "declval shouldn't be called!");
    }

    // C++11
    template<typename Type>
    struct remove_pointer {
        using type = Type;
    };

    // C++11
    template<typename Type>
    struct remove_pointer<Type*> {
        using type = Type;
    };

    // C++11
    template<typename Type>
    struct remove_pointer<Type* const> {
        using type = Type;
    };

    // C++11
    template<typename Type>
    struct remove_pointer<Type* volatile> {
        using type = Type;
    };

    // C++11
    template<typename Type>
    struct remove_pointer<Type* const volatile> {
        using type = Type;
    };

    // C++14
    template<typename Type>
    using remove_pointer_t = typename mylib::remove_pointer<Type>::type;

    // C++11
    template<typename Type, typename = void>
    struct add_pointer {
        using type = Type;
    };

    // C++11
    template<typename Type>
    struct add_pointer<Type, mylib::void_t<mylib::remove_reference_t<Type>*>> {
        using type = remove_reference_t<Type>*;
    };

#   ifdef __clang__

    // C++17
    // __is_same is clang only
    template<typename Type1, typename Type2>
    inline constexpr bool is_same_v = __is_same(Type1, Type2);

    // C++11
    // __is_same is clang only
    template<typename Type1, typename Type2>
    struct is_same :
        mylib::bool_constant<__is_same(Type1, Type2)> {
    };

#   else

    // C++17
    template<typename Type1, typename Type2>
    inline constexpr bool is_same_v = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_same_v<Type, Type> = true;

    // C++11
    template<typename Type1, typename Type2>
    struct is_same :
        mylib::bool_constant<mylib::is_same_v<Type1, Type2>> {
    };

#   endif

    // non-standard
    template<typename Type, typename... Types>
    inline constexpr bool is_any_of_v =
        mylib::disjunction_t<is_same<Type, Types>...>::value;

    // non-standard
    template<typename Type, typename... Types>
    struct is_any_of :
        mylib::bool_constant<mylib::is_any_of_v<Type, Types...>> {
    };

    // C++17
    template<typename Type>
    inline constexpr bool is_void_v = mylib::is_same_v<remove_cv_t<Type>, void>;

    // C++11
    template<typename Type>
    struct is_void :
        mylib::bool_constant<mylib::is_void_v<Type>> {
    };

    // C++17
    template<typename Type>
    inline constexpr bool is_null_pointer_v =
        mylib::is_same_v<remove_cv_t<Type>, nullptr_t>;

    // C++14
    template<typename Type>
    struct is_null_pointer :
        mylib::bool_constant<mylib::is_null_pointer_v<Type>> {
    };

    // C++17
    template<typename Type>
    inline constexpr bool is_integral_v =
        is_any_of_v<
            remove_cv_t<Type>,
            bool,
            char,      signed char, unsigned char,
            char8_t,   char16_t,    char32_t,
            short,     unsigned     short,
            int,       unsigned int,
            long,      unsigned long,
            long long, unsigned long long
        >;

    // C++11
    template<typename Type>
    struct is_integral :
        mylib::bool_constant<mylib::is_integral_v<Type>> {
    };

    // C++11
    template<typename Integer, Integer value>
        requires mylib::is_integral_v<Integer>
    using integral_constant = mylib::constant<Integer, value>;
    
    // C++11
    // from utility, but defined in type_traits
    template<typename Integer, Integer... integers>
    using integer_sequence = mylib::sequence<Integer, integers...>;

    // C++17
    template<typename Type>
    inline constexpr bool is_floating_point_v =
        mylib::is_any_of_v<remove_cv_t<Type>, float, double, long double>;

    // C++11
    template<typename Type>
    struct is_floating_point :
        mylib::bool_constant<mylib::is_floating_point_v<Type>> {
    };

    // non-standard
    template<typename Type>
    inline constexpr bool is_character_v =
        mylib::is_any_of_v<Type, char, wchar_t, char8_t, char16_t, char32_t>;

    // non-standard
    template<typename Type>
    struct is_character :
        mylib::bool_constant<mylib::is_character_v<Type>> {
    };

    // C++17
    template<typename Type>
    inline constexpr bool is_array_v             = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_array_v<Type[]>     = true;

    // C++17
    template<typename Type, size_t size>
    inline constexpr bool is_array_v<Type[size]> = true;

    // C++11
    template<typename Type>
    struct is_array :
        mylib::bool_constant<mylib::is_array_v<Type>> {
    };

    // C++17
    template<typename Type>
    inline constexpr bool is_enum_v = __is_enum(Type);

    // C++11
    template<typename Type>
    struct is_enum :
        mylib::bool_constant<__is_enum(Type)> {
    };

    // always true
#   if defined(__cpp_concepts) && !defined(_MSVC_LANG)

    // non-standard
    template<typename Type>
    inline constexpr bool is_class_type_v =
        requires { mylib::declval<void (int Type::*)>()(nullptr); };

#   else

}
    
namespace mylib::detail {

    template<typename Type>
    mylib::true_type  test_is_class_type(int Type::*) noexcept
    {}

    template<typename Type>
    mylib::false_type test_is_class_type(...)         noexcept
    {}
}

export namespace mylib {
    
    // non-standard
    template<typename Type>
    inline constexpr bool is_class_type_v =
        decltype(mylib::detail::test_is_class_type<Type>(nullptr))::value;

#   endif

    // non-standard
    template<typename Type>
    struct is_class_type :
        mylib::bool_constant<mylib::is_class_type_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_union_v = __is_union(Type);

    // C++11
    template<typename Type>
    struct is_union :
        mylib::bool_constant<__is_union(Type)> {
    };

    // always true
#   if true

    // C++17
    template<typename Type>
    inline constexpr bool is_class_v = __is_class(Type);

#   else

    // C++17
    template<typename Type>
    inline constexpr bool is_class_v =
        mylib::is_class_type_v<Type> &&
       !mylib::is_union_v<Type>;

#   endif

    // C++11
    template<typename Type>
    struct is_class :
        mylib::bool_constant<mylib::is_class_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_const_v             = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_const_v<const Type> = true;

    // C++11
    template<typename Type>
    struct is_const :
        mylib::bool_constant<mylib::is_const_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_lvalue_reference_v        = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_lvalue_reference_v<Type&> = true;

    // C++11
    template<typename Type>
    struct is_lvalue_reference :
        mylib::bool_constant<mylib::is_lvalue_reference_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_rvalue_reference_v        = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_rvalue_reference_v<Type&> = true;

    // C++11
    template<typename Type>
    struct is_rvalue_reference :
        mylib::bool_constant<mylib::is_rvalue_reference_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_reference_v         = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_reference_v<Type&>  = true;

    // C++17
    template<typename Type>
    inline constexpr bool is_reference_v<Type&&> = true;

    // C++11
    template<typename Type>
    struct is_reference :
        mylib::bool_constant<mylib::is_reference_v<Type>>
    {};

#   ifdef __clang__

    // C++17
    // __is_function is clang only
    template<typename Type>
    inline constexpr bool is_function_v = __is_function(Type);

    // C++11
    // __is_function is clang only
    template<typename Type>
    struct is_function :
        mylib::bool_constant<__is_function(Type)>
    {};

#   elif true

    // C++17
    // only function types and reference types can't be const qualified
    template<typename Type>
    inline constexpr bool is_function_v =
        !mylib::is_const_v<const Type> && !mylib::is_reference_v<Type>;

    // C++11
    template<typename Type>
    struct is_function :
        mylib::bool_constant<mylib::is_function_v<Type>>
    {};

    // never used
#   elif false

    // C++17
    template<typename Type>
    inline constexpr bool is_function_v =
        false;

    // Result (Params...[, ...]) [const] [volatile] [& | &&] [noexcept] => 2 * 2 * 2 * 3 * 2 = 48

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...)>                                =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const>                          =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) volatile>                       =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const volatile>                 =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) &>                              =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const&>                         =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) volatile&>                      =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const volatile&>                =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) &&>                             =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const&&>                        =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) volatile&&>                     =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const volatile&&>               =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...)>                           =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const>                     =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) volatile>                  =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const volatile>            =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) &>                         =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const&>                    =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) volatile&>                 =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const volatile&>           =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) &&>                        =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const&&>                   =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) volatile&&>                =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const volatile&&>          =
        true;

    // noexcept, after C++17
    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) noexcept>                       =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const noexcept>                 =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) volatile noexcept>              =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const volatile noexcept>        =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) & noexcept>                     =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const& noexcept>                =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) volatile& noexcept>             =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const volatile& noexcept>       =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) && noexcept>                    =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const&& noexcept>               =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) volatile&& noexcept>            =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const volatile&& noexcept>      =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) noexcept>                  =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const noexcept>            =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) volatile noexcept>         =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const volatile noexcept>   =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) & noexcept>                =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const& noexcept>           =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) volatile& noexcept>        =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const volatile& noexcept>  =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) && noexcept>               =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const&& noexcept>          =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) volatile&& noexcept>       =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const volatile&& noexcept> =
        true;

    // C++11
    template<typename Type>
    struct is_function :
        mylib::bool_constant<mylib::is_function_v<Type>>
    {};

#   endif
}

namespace mylib::detail {
    // implementation
    template<typename Type>
    inline constexpr bool is_pointer_v_impl        = false;

    // implementation
    template<typename Type>
    inline constexpr bool is_pointer_v_impl<Type*> = true;
}

export namespace mylib {

    // C++17
    template<typename Type>
    inline constexpr bool is_pointer_v =
        mylib::detail::is_pointer_v_impl<mylib::remove_cv_t<Type>>;

    // C++11
    template<typename Type>
    struct is_pointer :
        mylib::bool_constant<mylib::is_pointer_v<Type>>
    {};

    // non-standard
    template<typename Type>
    inline constexpr bool is_function_pointer_v =
        mylib::is_pointer_v<Type> && mylib::is_function_v<mylib::remove_pointer_t<Type>>;

    // non-standard
    template<typename Type>
    struct is_function_pointer :
        mylib::bool_constant<mylib::is_function_pointer_v<Type>>
    {};

#   ifdef __clang__

    // C++17
    // __is_member_pointer is clang only
    template<typename Type>
    inline constexpr bool is_member_pointer_v = __is_member_pointer(Type);

    // C++11
    // __is_member_pointer is clang only
    template<typename Type>
    struct is_member_pointer :
        mylib::bool_constant<__is_member_pointer(Type)>
    {};

#   else

}

namespace mylib::detail {
    // implementation
    template<typename Type>
    inline constexpr bool is_member_pointer_v_impl                      = false;

    // implementation
    template<typename MemberType, typename Class>
    inline constexpr bool is_member_pointer_v_impl<MemberType Class::*> = true;
}
  
export namespace mylib {

    // C++17
    template<typename Type>
    inline constexpr bool is_member_pointer_v =
        mylib::detail::is_member_pointer_v_impl<mylib::remove_cv_t<Type>>;

    // C++11
    template<typename Type>
    struct is_member_pointer :
        mylib::bool_constant<mylib::is_member_pointer_v<Type>>
    {};

#   endif

#   ifdef __clang__

    // C++17
    // __is_member_object_pointer_v is clang only
    template<typename Type>
    inline constexpr bool is_member_object_pointer_v =
        __is_member_object_pointer(Type);

    // C++11
    // __is_member_object_pointer_v is clang only
    template<typename Type>
    struct is_member_object_pointer :
        mylib::bool_constant<__is_member_object_pointer(Type)>
    {};

#   else

}

namespace mylib::detail {
    // implementation
    template<typename Type>
    inline constexpr bool is_member_object_pointer_v_impl                      =
        false;

    // implementation
    template<typename MemberType, typename Class>
    inline constexpr bool is_member_object_pointer_v_impl<MemberType Class::*> =
        !mylib::is_function_v<MemberType>;
}

export namespace mylib {

    // C++17
    template<typename Type>
    inline constexpr bool is_member_object_pointer_v
        = mylib::detail::is_member_object_pointer_v_impl<mylib::remove_cv_t<Type>>;

    // C++11
    template<typename Type>
    struct is_member_object_pointer :
        mylib::bool_constant<mylib::is_member_object_pointer_v<Type>>
    {};

#endif

#   ifdef __clang__

    // C++17
    // __is_member_function_pointer_v is clang only
    template<typename Type>
    inline constexpr bool is_member_function_pointer_v =
        __is_member_function_pointer(Type);

    // C++11
    // __is_member_function_pointer_v is clang only
    template<typename Type>
    struct is_member_function_pointer :
        mylib::bool_constant<__is_member_function_pointer(Type)>
    {};

#   else

}

namespace mylib::detail {

    // implementation
    template<typename Type>
    inline constexpr bool is_member_function_pointer_v_impl                      =
        false;

    // implementation
    template<typename MemberType, typename Class>
    inline constexpr bool is_member_function_pointer_v_impl<MemberType Class::*> =
        is_function_v<MemberType>;
}

export namespace mylib {

    // C++17
    template<typename Type>
    inline constexpr bool is_member_function_pointer_v =
        mylib::detail::is_member_function_pointer_v_impl<mylib::remove_cv_t<Type>>;

    
    // C++11
    template<typename Type>
    struct is_member_function_pointer :
        mylib::bool_constant<mylib::is_member_function_pointer_v<Type>>
    {};

#   endif
    
    // always true
#   ifdef __cpp_concepts

    // non-standard
    template<typename Type>
    inline constexpr bool is_complete_v = requires { sizeof(Type); };

#   else

}

namespace mylib::detail {

    template<class T>
    auto test_is_complete(int) ->
        decltype(sizeof(T), mylib::true_type{})
    {}

    template<class>
    auto test_is_complete(...) ->
        mylib::false_type
    {}
}

export namespace mylib {

    // non-standard
    template<typename Type> 
    inline constexpr bool is_complete_v =
        decltype(detail::test_is_complete<Type>(0))::value;
    
#   endif

    // non-standard
    template<typename Type>
    struct is_complete :
        mylib::bool_constant<mylib::is_complete_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_arithmetic_v =
        mylib::is_integral_v<Type> || mylib::is_floating_point_v<Type>;

    // C++11
    template<typename Type>
    struct is_arithmetic :
        mylib::bool_constant<mylib::is_arithmetic_v<Type>>
    {};
    
    // C++17
    template<typename Type>
    inline constexpr bool is_fundamental_v =
        mylib::is_arithmetic_v<Type> || mylib::is_void_v<Type> || 
        mylib::is_null_pointer_v<Type>;

    // C++11
    template<typename Type>
    struct is_fundamental :
        mylib::bool_constant<mylib::is_fundamental_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_scalar_type_v =
        mylib::is_arithmetic_v<Type>  || mylib::is_enum_v<Type>           ||
        mylib::is_pointer_v<Type>     || mylib::is_member_pointer_v<Type> ||
        mylib::is_null_pointer_v<Type>;

    // C++11
    template<typename Type>
    struct is_scalar_type :
        mylib::bool_constant<mylib::is_scalar_type_v<Type>>
    {};

    // always true
#   if true
       
    // C++17
    // a non-void types that can be const qualified
    template<typename Type>
    inline constexpr bool is_object_v =
        mylib::is_const_v<const Type> && !mylib::is_void_v<Type>;
    // ^^ only function types and reference types can't be const qualified

#   else
    
    // C++17
    // standard implementation
    // a type that is one of the scalar types, array types and class type
    template<typename Type>
    inline constexpr bool is_object_v =
        mylib::is_scalar_type_v<Type> || mylib::is_array_v<Type> ||
        mylib::is_union_v<Type>       || mylib::is_class_v<Type>;

#   endif

    // C++11
    template<typename Type>
    struct is_object :
        mylib::bool_constant<mylib::is_object_v<Type>>
    {};

    // always true
#   if true

    // C++17
    // a type that is not fundamental types
    template<typename Type>
    inline constexpr bool is_compound_v = !mylib::is_fundamental_v<Type>;

#   else

    // C++17
    // a type that is one of the reference types, pointer types, pointer-to-member types,
    // array types, function types, enumeration types, class types
    template<typename Type>
    inline constexpr bool is_compound_v =
        mylib::is_reference_v<Type>      || mylib::is_pointer_v<Type> ||
        mylib::is_member_pointer_v<Type> || mylib::is_array_v<Type>   ||
        mylib::is_function_v<Type>       || mylib::is_enum_v<Type>    ||
        mylib::is_union_v<Type>          || mylib::is_class_v<Type>;

#   endif

    // C++11
    template<typename Type>
    struct is_compound :
        mylib::bool_constant<mylib::is_compound_v<Type>>
    {};

    // always true
#   ifdef __cpp_concepts

    // non-standard
    template<typename Type>
    inline constexpr bool is_returnable_v =
        requires {
            static_cast<Type(*)()>(nullptr);
        };

#   else

}

namespace mylib::detail {

    template<typename Type>
    auto test_is_returnable(int) ->
        decltype(static_cast<Type(*)()>(nullptr), mylib::true_type{})
    {}

    template<typename Type>
    auto test_is_returnable(...) ->
        mylib::false_type
    {}
}

export namespace mylib {

    // non-standard
    template<typename Type>
    inline constexpr bool is_returnable_v =
        decltype(detail::test_is_returnable<Type>(0))::value;

#   endif

    // non-standard
    template<typename Type>
    struct is_returnable :
        mylib::bool_constant<is_returnable_v<Type>>
    {};
    
    // C++17
    template<typename Type>
    inline constexpr bool is_volatile_v                = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_volatile_v<volatile Type> = true;

    // C++11
    template<typename Type>
    struct is_volatile :
        mylib::bool_constant<is_volatile_v<Type>>
    {};

    // always true
#   if true

    // C++17
    template<typename Type>
    inline constexpr bool is_trivial_v = __is_trivial(Type);

    // C++11
    template<typename Type>
    struct is_trivial :
        mylib::bool_constant<__is_trivial(Type)>
    {};

#   else

    // C++17
    // a type that can be trivially constructure and trivially copy
    template<typename Type>
    inline constexpr bool is_trivial_v =
        __is_trivially_constructible(Type) && __is_trivially_copyable(Type);

    // C++11
    // a type that can be trivially constructure and trivially copy
    template<typename Type>
    struct is_trivial :
        mylib::bool_constant<
            __is_trivially_constructible(Type) && __is_trivially_copyable(Type)
        >
    {};

#   endif

    // C++17
    template<typename Type>
    inline constexpr bool is_trivially_copyable_v = __is_trivially_copyable(Type);

    // C++11
    template<typename Type>
    struct is_trivially_copyable :
        mylib::bool_constant<__is_trivially_copyable(Type)>
    {};
    
    // C++17
    template<typename Type>
    inline constexpr bool is_standard_layout_v = __is_standard_layout(Type);

    // C++11
    template<typename Type>
    struct is_standard_layout :
        mylib::bool_constant<__is_standard_layout(Type)>
    {};

    // C++17
    // is deprecated
    template<typename Type>
    [[deprecated(
        "The is_pod_v is deprecated in C++20, may will removed in later standard! "
        "Consider use is_trivially_copyable_v and/or is_standard_layout_v to replace it"
    )]]
    inline constexpr bool is_pod_v = __is_pod(Type);

    // C++11
    // is deprecated
    template<typename Type>
    struct
    [[deprecated(
        "The is_pod is deprecated in C++20, may will removed in later standard! "
        "Consider use mylib::is_trivially_copyable and/or is_standard_layout to replace it"
    )]]
    is_pod :
        mylib::bool_constant<__is_pod(Type)>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool has_unique_object_representations_v =
        __has_unique_object_representations(Type);

    // C++11
    template<typename Type>
    struct has_unique_object_representations :
        mylib::bool_constant<__has_unique_object_representations(Type)>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_empty_v = __is_empty(Type);

    // C++11
    template<typename Type>
    struct is_empty :
        mylib::bool_constant<__is_empty(Type)>
    {};

#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)

    // C++17
    // __is_polymorphic is valid in clang, gcc and msvc
    template<typename Type>
    inline constexpr bool is_polymorphic_v = __is_polymorphic(Type);
    
    // C++11
    // __is_polymorphic is valid in clang, gcc and msvc
    template<typename Type>
    struct is_polymorphic :
        mylib::bool_constant<__is_polymorphic(Type)>
    {};

#   elif defined(__cpp_concepts)

    // C++17
    template<typename Type>
    inline constexpr bool is_polymorphic_v =
        requires { dynamic_cast<const volatile void*>(mylib::declval<Type*>()) };
    
    // C++11
    template<typename Type>
    struct is_polymorphic :
        mylib::bool_constant<mylib::is_polymorphic_v<Type>>
    {};

    // always false
#   else

}

namespace mylib::detail {

    template<typename Type>
    mylib::true_type  test_is_polymorphic(
        decltype(dynamic_cast<const volatile void*>(static_cast<Type*>(nullptr)))
    ) noexcept
    {}

    template<typename Type>
    mylib::false_type test_is_polymorphic(...) noexcept
    {}
}

export namespace mylib {

    // C++17
    template<typename Type>
    inline constexpr bool is_polymorphic_v =
        decltype(mylib::detail::test_is_polymorphic<Type>(nullptr))::value;
   
    // C++11
    template<typename Type>
    struct is_polymorphic :
        mylib::bool_constant<mylib::is_polymorphic_v<Type>>
    {};

#   endif

    
    // C++17
    template<typename Type>
    inline constexpr bool is_abstract_v = __is_abstract(Type);

    // C++11
    template<typename Type>
    struct is_abstract :
        mylib::bool_constant<__is_abstract(Type)>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_final_v = __is_final(Type);

    // C++11
    template<typename Type>
    struct is_final :
        mylib::bool_constant<__is_final(Type)>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_aggregate_v = __is_aggregate(Type);

    // C++11
    template<typename Type>
    struct is_aggregate :
        mylib::bool_constant< __is_aggregate(Type)>
    {};

}

namespace mylib::detail {

    template<typename Type, bool isArithmetic = mylib::is_arithmetic_v<Type>>
    struct signed_base {
        bool is_signed = Type{ -1 } < Type{};
    };

    template<typename Type>
    struct signed_base<Type, false> {
        bool is_signed = false;
    };
}

export namespace mylib {

    // C++17
    template<typename Type>
    inline constexpr bool is_signed_v = mylib::detail::signed_base<Type>::is_signed;

    // C++11
    template<typename Type>
    struct is_signed :
        mylib::bool_constant<mylib::is_signed_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_unsigned_v = !mylib::detail::signed_base<Type>::is_signed;

    // C++11
    template<typename Type>
    struct is_unsigned :
        mylib::bool_constant<mylib::is_unsigned_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_bounded_array_v             = false;

    // C++17
    template<typename Type, size_t size>
    inline constexpr bool is_bounded_array_v<Type[size]> = true;

    // C++11
    template<typename Type>
    struct is_bounded_array :
        mylib::bool_constant<mylib::is_bounded_array_v<Type>>
    {};
    
    // C++17
    template<typename Type>
    inline constexpr bool is_unbounded_array_v         = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_unbounded_array_v<Type[]> = true;
    
    // C++11
    template<typename Type>
    struct is_unbounded_array :
        mylib::bool_constant<mylib::is_unbounded_array_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr size_t alignment_of_v = alignof(Type);

    // C++11
    template<typename Type>
    struct alignment_of :
        mylib::integral_constant<size_t, alignof(Type)>
    {};

    // C++17
    template<typename Type>
    inline constexpr size_t rank_v             = 0;

    template<typename Type, size_t size>
    inline constexpr size_t rank_v<Type[size]> = 1 + rank_v<Type>;

    template<typename Type>
    inline constexpr size_t rank_v<Type[]>     = 1 + rank_v<Type>;

    // C++11
    template<typename Type>
    struct rank :
        mylib::integral_constant<size_t, mylib::rank_v<Type>>
    {};
    
    // C++17
    template<typename Type, size_t index = 0>
    inline constexpr size_t extent_v = 0;

    template<typename Type, size_t size>
    inline constexpr size_t extent_v<Type[size], 0>     = size;

    template<typename Type, size_t index>
    inline constexpr size_t extent_v<Type[], index> = extent_v<Type, index - 1>;

    template<typename Type, size_t size, size_t index>
    inline constexpr size_t extent_v<Type[size], index> = extent_v<Type, index - 1>;

    // C++11
    template<typename Type, size_t index = 0>
    struct extent :
        mylib::integral_constant<size_t, mylib::extent_v<Type, index>>
    {};

    // C++11
    template<typename Type>
    struct remove_extent {
        using type = Type;
    };

    template<typename Type>
    struct remove_extent<Type[]> {
        using type = Type;
    };

    template<typename Type, size_t size>
    struct remove_extent<Type[size]> {
        using type = Type;
    };

    // C++14
    template<typename Type>
    using remove_extent_t = typename mylib::remove_extent<Type>::type;

    // C++11
    template<typename Type>
    struct remove_all_extents {
        using type = Type;
    };

    template<typename Type>
    struct remove_all_extents<Type[]> {
        using type = typename remove_all_extents<Type>::type;
    };

    template<typename Type, size_t size>
    struct remove_all_extents<Type[size]> {
        using type = typename remove_all_extents<Type>::type;
    };

    // C++14
    template<typename Type>
    using remove_all_extents_t = typename mylib::remove_all_extents<Type>::type;

#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)

    // C++17
    // __is_constructible is valid in clang, gcc and msvc
    template<typename Type, typename... Params>
    inline constexpr bool is_constructible_v = __is_constructible(Type, Params...);

    // C++11
    // __is_constructible is valid in clang, gcc and msvc
    template<typename Type, typename... Params>
    struct is_constuctible :
        mylib::bool_constant<__is_constructible(Type, Params...)>
    {};

#   elif defined(__cpp_concepts)

    // C++17
    template<typename Type, typename... Params>
    inline constexpr bool is_constructible_v =
        requires { Type(mylib::declval<Params>()...); };

    // C++11
    template<typename Type, typename... Params>
    struct is_constructible :
        mylib::bool_constant<mylib::is_constructible_v<Type, Params...>>
    {};

    // always false
#   else

}

namespace mylib::detail {

    template<typename Type, typename... Params>
    auto test_is_constructible(int) noexcept ->
        decltype(Type(mylib::declval<Params>()...), mylib::true_type{})
    {}

    template<typename Type, typename... Params>
    auto test_is_constructible(...) noexcept ->
        mylib::false_type
    {}
}

export namespace mylib {

    // C++17
    template<typename Type, typename... Params>
    inline constexpr bool is_constructible_v =
        decltype(mylib::detail::test_is_constructible<Type, Params...>(0))::value;

    // C++11
    template<typename Type, typename... Params>
    struct is_constructible :
        mylib::bool_constant<mylib::is_constructible_v<Type, Params...>>
    {};

#   endif

    // C++17
    template<typename Type, typename... Params>
    inline constexpr bool is_trivially_constructible_v =
        __is_trivially_constructible(Type, Params...);

    // C++11
    template<typename Type, typename... Params>
    struct is_trivially_constructible :
        mylib::bool_constant<__is_trivially_constructible(Type, Params...)>
    {};

#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)

    // C++17
    // __is_nothrow_constructible is available in clang, gcc and msvc
    template<typename Type, typename... Params>
    inline constexpr bool is_nothrow_constructible_v =
        __is_nothrow_constructible(Type, Params...);

    // C++11
    // __is_nothrow_constructible is available in clang, gcc and msvc
    template<typename Type, typename... Params>
    struct is_nothrow_constructible :
        mylib::bool_constant<__is_nothrow_constructible(Type, Params...)>
    {};

#   elif defined(__cpp_concepts)

    // C++17
    template<typename Type, typename... Params>
    inline constexpr bool is_nothrow_constructible_v =
        requires { { Type(mylib::declval<Params>()...) } noexcept; };

    // C++11
    template<typename Type, typename... Params>
    struct is_nothrow_constructible :
        mylib::bool_constant<mylib::is_nothrow_constructible_v<Type, Params...>>
    {};

    // always false
#   else

}

namespace mylib::detail {

    template<typename Type, typename... Params>
    auto test_is_nothrow_constructible(int) noexcept ->
        mylib::bool_constant<noexcept(Type(mylib::declval<Params>()...))>
    {}

    template<typename Type, typename... Params>
    auto test_is_nothrow_constructible(...) noexcept ->
        mylib::false_type
    {}
}

export namespace mylib {

    // C++17
    template<typename Type>
    inline constexpr bool is_nothrow_constructible_v =
        decltype(mylib::detail::test_is_nothrow_constructible<Type>(0))::value;

    // C++11
    template<typename Type>
    struct is_nothrow_constructible :
        mylib::bool_constant<mylib::is_nothrow_constructible_v<Type>>
    {};

#   endif

#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)

    // C++17
    // __is_constructible is available in clang, gcc and msvc
    template<typename Type>
    inline constexpr bool is_default_constructible_v =
        __is_constructible(Type);

    // C++11
    // __is_constructible is available in clang, gcc and msvc
    template<typename Type>
    struct is_default_constructible :
        mylib::bool_constant<__is_constructible(Type)>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_triviallt_default_constructible_v =
        __is_constructible(Type);

    // C++11
    template<typename Type>
    struct is_triviallt_default_constructible :
        mylib::bool_constant<__is_trivially_constructible(Type)>
    {};

    // C++17
    // __is_nothrow_constructible is available in clang, gcc and msvc
    template<typename Type>
    inline constexpr bool is_nothrow_default_constructible_v =
        __is_nothrow_constructible(Type);

    // C++11
    // __is_nothrow_constructible is available in clang, gcc and msvc
    template<typename Type>
    struct is_nothrow_default_constructible :
        mylib::bool_constant<__is_nothrow_constructible(Type)>
    {};

#   else

    // C++17
    template<typename Type>
    inline constexpr bool is_default_constructible_v =
        mylib::is_constructible_v<Type>;

    // C++11
    template<typename Type>
    struct is_default_constructible :
        mylib::bool_constant<is_default_constructible_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_triviallt_default_constructible_v =
        mylib::is_trivially_constructible_v<Type>;

    // C++11
    template<typename Type>
    struct is_triviallt_default_constructible :
        mylib::bool_constant<mylib::is_triviallt_default_constructible_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_nothrow_default_constructible_v =
        mylib::is_nothrow_constructible_v<Type>;

    // C++11
    template<typename Type>
    struct is_nothrow_default_constructible :
        mylib::bool_constant<mylib::is_nothrow_default_constructible_v<Type>>
    {};

#   endif

#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)

    // C++17
    // __is_constructible is available in clang, gcc and msvc
    template<typename Type>
    inline constexpr bool is_copy_constructible_v =
        __is_constructible(Type, mylib::add_rvalue_reference_t<const Type>);

    // C++11
    // __is_constructible is available in clang, gcc and msvc
    template<typename Type>
    struct is_copy_constructible :
        mylib::bool_constant<
            __is_constructible(Type, mylib::add_rvalue_reference_t<const Type>)
        >
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_trivially_copy_constructible_v =
        __is_constructible(Type, mylib::add_rvalue_reference_t<const Type>);

    // C++11
    template<typename Type>
    struct is_trivially_copy_constructible :
        mylib::bool_constant<
            __is_trivially_constructible(Type, mylib::add_rvalue_reference_t<const Type>)
        >
    {};

    // C++17
    // __is_nothrow_constructible is available in clang, gcc and msvc
    template<typename Type>
    inline constexpr bool is_nothrow_copy_constructible_v =
        __is_nothrow_constructible(Type, mylib::add_rvalue_reference_t<const Type>);

    // C++11
    // __is_nothrow_constructible is available in clang, gcc and msvc
    template<typename Type>
    struct is_nothrow_copy_constructible :
        mylib::bool_constant<
            __is_nothrow_constructible(Type, mylib::add_rvalue_reference_t<const Type>)
        >
    {};

#   else

    // C++17
    template<typename Type>
    inline constexpr bool is_copy_constructible_v =
        mylib::is_constructible_v<Type, mylib::add_rvalue_reference_t<const Type>>;

    // C++11
    template<typename Type>
    struct is_copy_constructible :
        mylib::bool_constant<is_copy_constructible_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_trivially_copy_constructible_v =
        mylib::is_trivially_constructible_v<
            Type, mylib::add_rvalue_reference_t<const Type>
        >;

    // C++11
    template<typename Type>
    struct is_trivially_copy_constructible :
        mylib::bool_constant<mylib::is_trivially_copy_constructible_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_nothrow_copy_constructible_v =
        mylib::is_nothrow_constructible_v<
            Type, mylib::add_rvalue_reference_t<const Type>
        >;

    // C++11
    template<typename Type>
    struct is_nothrow_copy_constructible :
        mylib::bool_constant<mylib::is_nothrow_copy_constructible_v<Type>>
    {};

#   endif

    #   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)

    // C++17
    // __is_constructible is available in clang, gcc and msvc
    template<typename Type>
    inline constexpr bool is_move_constructible_v =
        __is_constructible(Type, mylib::add_rvalue_reference_t<Type>);

    // C++11
    // __is_constructible is available in clang, gcc and msvc
    template<typename Type>
    struct is_move_constructible :
        mylib::bool_constant<
            __is_constructible(Type, mylib::add_rvalue_reference_t<Type>)
        >
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_trivially_move_constructible_v =
        __is_constructible(Type, mylib::add_rvalue_reference_t<Type>);

    // C++11
    template<typename Type>
    struct is_trivially_move_constructible :
        mylib::bool_constant<
            __is_trivially_constructible(Type, mylib::add_rvalue_reference_t<Type>)
        >
    {};

    // C++17
    // __is_nothrow_constructible is available in clang, gcc and msvc
    template<typename Type>
    inline constexpr bool is_nothrow_move_constructible_v =
        __is_nothrow_constructible(Type, mylib::add_rvalue_reference_t<Type>);

    // C++11
    // __is_nothrow_constructible is available in clang, gcc and msvc
    template<typename Type>
    struct is_nothrow_move_constructible :
        mylib::bool_constant<
            __is_nothrow_constructible(Type, mylib::add_rvalue_reference_t<Type>)
        >
    {};

#   else

    // C++17
    template<typename Type>
    inline constexpr bool is_move_constructible_v =
        mylib::is_constructible_v<Type, mylib::add_rvalue_reference_t<Type>>;

    // C++11
    template<typename Type>
    struct is_move_constructible :
        mylib::bool_constant<is_move_constructible_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_trivially_move_constructible_v =
        mylib::is_trivially_constructible_v<Type, mylib::add_rvalue_reference_t<Type>>;

    // C++11
    template<typename Type>
    struct is_trivially_move_constructible :
        mylib::bool_constant<mylib::is_trivially_move_constructible_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_nothrow_move_constructible_v =
        mylib::is_nothrow_constructible_v<Type, mylib::add_rvalue_reference_t<Type>>;

    // C++11
    template<typename Type>
    struct is_nothrow_move_constructible :
        mylib::bool_constant<mylib::is_nothrow_move_constructible_v<Type>>
    {};

#   endif

#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)

    template<typename To, typename From>
    inline constexpr bool is_assignable_v = __is_assignable(To, From);

    template<typename To, typename From>
    struct is_assignable :
        mylib::bool_constant<__is_assignable(To, From)>
    {};

#   elif defined(__cpp_concepts)

    template<typename To, typename From>
    inline constexpr bool is_assignable_v =
        requires {
            mylib::declval<To>() = mylib::declval<From>();
        };

    template<typename To, typename From>
    struct is_assignable :
        mylib::bool_constant<mylib::is_assignable_v<To, From>>
    {};
    
#   else
    
}

namespace mylib::detail {

    template<typename To, typename From>
    auto test_is_assignable(int) noexcept ->
        decltype(mylib::declval<To>() = mylib::declval<From>(), mylib::true_type())
    {}
    
    template<typename To, typename From>
    auto test_is_assignable(...) noexcept ->
        mylib::false_type
    {}
}

export namespace mylib {

    template<typename To, typename From>
    inline constexpr bool is_assignable_v =
        mylib::detail::test_is_assignable<To, From>(0);

    template<typename To, typename From>
    struct is_assignable :
        mylib::bool_constant<mylib::is_assignable_v<To, From>>
    {};
    
#   endif
    
    template<typename To, typename From>
    inline constexpr bool is_trivially_assignable_v =
        __is_trivially_assignable(To, From);

    template<typename To, typename From>
    struct is_trivially_assignable :
        mylib::bool_constant<__is_trivially_assignable(To, From)>
    {};

#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)
    
    template<typename To, typename From>
    inline constexpr bool is_nothrow_assignable_v =
        __is_nothrow_assignable(To, From);

    template<typename To, typename From>
    struct is_nothrow_assignable :
        mylib::bool_constant<__is_nothrow_assignable(To, From)>
    {};
    
#   elif defined(__cpp_concepts)

    template<typename To, typename From>
    inline constexpr bool is_nothrow_assignable_v =
        requires { { mylib::declval<To>() = mylib::declval<From>() } noexcept; };

    template<typename To, typename From>
    struct is_nothrow_assignable :
        mylib::bool_constant<mylib::is_nothrow_assignable_v<To, From>>
    {};
    
    // always false
#   else

}

namespace mylib::detail {

    template<typename To, typename From>
    auto test_is_noexcept_assignable(int) noexcept ->
        mylib::bool_constant<
            noexcept(mylib::declval<To>() = mylib::declval<From>())
        >
    {}
    
    template<typename To, typename From>
    auto test_is_noexcept_assignable(...) noexcept ->
        mylib::false_type
    {}
}

export namespace mylib {
    
    template<typename To, typename From>
    inline constexpr bool is_nothrow_assignable_v =
        mylib::detail::test_is_noexcept_assignable<To, From>(0);

    template<typename To, typename From>
    struct is_nothrow_assignable :
        mylib::bool_constant<mylib::is_nothrow_assignable_v<To, From>>
    {};

#   endif
    
#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)
    
    template<typename Type>
    inline constexpr bool is_copy_assignable_v =
        __is_assignable(
            mylib::add_lvalue_reference_t<Type>,
            mylib::add_lvalue_reference_t<const Type>
        );

    template<typename Type>
    struct is_copy_assignable :
        mylib::bool_constant<
            __is_assignable(
                mylib::add_lvalue_reference_t<Type>,
                mylib::add_lvalue_reference_t<const Type>
            )
        >
    {};
    
    template<typename Type>
    inline constexpr bool is_trivially_copy_assignable_v =
        __is_trivially_assignable(
            mylib::add_lvalue_reference_t<Type>,
            mylib::add_lvalue_reference_t<const Type>
        );

    template<typename Type>
    struct is_trivially_copy_assignable :
        mylib::bool_constant<
            __is_trivially_assignable(
                mylib::add_lvalue_reference_t<Type>,
                mylib::add_lvalue_reference_t<const Type>
            )
        >
    {};

    template<typename Type>
    inline constexpr bool is_nothrow_copy_assignable_v =
        __is_nothrow_assignable(
            mylib::add_lvalue_reference_t<Type>,
            mylib::add_lvalue_reference_t<const Type>
        );

    template<typename Type>
    struct is_nothrow_copy_assignable :
        mylib::bool_constant<
            __is_nothrow_assignable(
                mylib::add_lvalue_reference_t<Type>,
                mylib::add_lvalue_reference_t<const Type>
            )
        >
    {};
    
#   else

    template<typename Type>
    inline constexpr bool is_copy_assignable_v =
        mylib::is_assignable_v<
            mylib::add_lvalue_reference_t<Type>,
            mylib::add_lvalue_reference_t<const Type>
        >;

    template<typename Type>
    struct is_copy_assignable :
        mylib::bool_constant<mylib::is_copy_assignable_v<Type>>
    {};

    template<typename Type>
    inline constexpr bool is_trivially_copy_assignable_v =
        mylib::is_trivially_assignable_v<
            mylib::add_lvalue_reference_t<Type>,
            mylib::add_lvalue_reference_t<const Type>
        >;

    template<typename Type>
    struct is_trivially_copy_assignable :
        mylib::bool_constant<mylib::is_trivially_copy_assignable_v<Type>>
    {};

    template<typename Type>
    inline constexpr bool is_nothrow_copy_assignable_v =
        mylib::is_nothrow_assignable_v<
            mylib::add_lvalue_reference_t<Type>,
            mylib::add_lvalue_reference_t<const Type>
        >;

    template<typename Type>
    struct is_nothrow_copy_assignable :
        mylib::bool_constant<mylib::is_nothrow_copy_assignable_v<Type>>
    {};

#   endif

    #   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)
    
    template<typename Type>
    inline constexpr bool is_move_assignable_v =
        __is_assignable(
            mylib::add_lvalue_reference_t<Type>,
            mylib::add_rvalue_reference_t<Type>
        );

    template<typename Type>
    struct is_move_assignable :
        mylib::bool_constant<
            __is_assignable(
                mylib::add_lvalue_reference_t<Type>,
                mylib::add_rvalue_reference_t<Type>
            )
        >
    {};
    
    template<typename Type>
    inline constexpr bool is_trivially_move_assignable_v =
        __is_trivially_assignable(
            mylib::add_lvalue_reference_t<Type>,
            mylib::add_rvalue_reference_t<Type>
        );

    template<typename Type>
    struct is_trivially_move_assignable :
        mylib::bool_constant<
            __is_trivially_assignable(
                mylib::add_lvalue_reference_t<Type>,
                mylib::add_rvalue_reference_t<Type>
            )
        >
    {};

    template<typename Type>
    inline constexpr bool is_nothrow_move_assignable_v =
        __is_nothrow_assignable(
            mylib::add_lvalue_reference_t<Type>,
            mylib::add_rvalue_reference_t<Type>
        );

    template<typename Type>
    struct is_nothrow_move_assignable :
        mylib::bool_constant<
            __is_nothrow_assignable(
                mylib::add_lvalue_reference_t<Type>,
                mylib::add_rvalue_reference_t<Type>
            )
        >
    {};
    
#   else

    template<typename Type>
    inline constexpr bool is_move_assignable_v =
        mylib::is_assignable_v<
            mylib::add_lvalue_reference_t<Type>,
            mylib::add_rvalue_reference_t<Type>
        >;

    template<typename Type>
    struct is_move_assignable :
        mylib::bool_constant<mylib::is_move_assignable_v<Type>>
    {};

    template<typename Type>
    inline constexpr bool is_trivially_move_assignable_v =
        mylib::is_trivially_assignable_v<
            mylib::add_lvalue_reference_t<Type>,
            mylib::add_rvalue_reference_t<Type>
        >;

    template<typename Type>
    struct is_trivially_move_assignable :
        mylib::bool_constant<mylib::is_trivially_move_assignable_v<Type>>
    {};

    template<typename Type>
    inline constexpr bool is_nothrow_move_assignable_v =
        mylib::is_nothrow_assignable_v<
            mylib::add_lvalue_reference_t<Type>,
            mylib::add_rvalue_reference_t<Type>
        >;

    template<typename Type>
    struct is_nothrow_move_assignable :
        mylib::bool_constant<mylib::is_nothrow_move_assignable_v<Type>>
    {};

#   endif

#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANGs)
    
    template<typename Type>
    inline constexpr bool is_destructible_v = __is_destructible(Type);

    template<typename Type>
    struct is_destructible :
        mylib::bool_constant<__is_destructible(Type)>
    {};

#   elif defined(__cpp_concepts)

    // TODO
    template<typename Type>
    struct is_destructible :
        mylib::bool_constant<
            mylib::is_reference_v<Type> ||
            requires {
                mylib::declval<Type>().~Type();
            }
        >
    {};
    
    template<typename Type>
    inline constexpr bool is_destructible_v =
        mylib::is_destructible<Type>::value;

#   else

}

namespace mylib::detail {

}

export namespace mylib {

#   endif
    
#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)
    
    // C++17
    // __is_base_of is available in clang, gcc and msvc
    template<typename BaseClass, typename DerivedClass>
    inline constexpr bool is_base_of_v = __is_base_of(BaseClass, DerivedClass);
    
    // C++11
    // __is_base_of is available in clang, gcc and msvc
    template<typename BaseClass, typename DerivedClass>
    struct is_base_of :
        mylib::bool_constant<__is_base_of(BaseClass, DerivedClass)>
    {};

#   else

}

namespace mylib::detail {
        
    // helper function template
    // if To is argument's type or it's base class, match this,
    // and when To is argument's private, protected or ambigous base class, will result in failure
    template<typename To>
    mylib::true_type  test_is_pointer_convertible(const volatile To*)   noexcept
    {}

    // helper function template
    // else match this
    template<typename To>
    mylib::false_type test_is_pointer_convertible(const volatile void*) noexcept
    {}

    // helper function template
    // a private, protected or ambigous base class will match this function template
    template<typename BaseClass, typename DerivedClass>
    auto test_is_base_of(...) noexcept ->
        mylib::true_type
    {}

    // helper function template
    template<typename BaseClass, typename DerivedClass>
    auto test_is_base_of(int) noexcept ->
        // check can the derived class cast to the base class
        // failure when the base class is derived class's private, protected or ambigous base class
        decltype(
            test_is_pointer_convertible<BaseClass>(
                static_cast<DerivedClass*>(
                    nullptr
                )
            )
        )
    {}
}

export namespace mylib {

    // C++17
    template <typename BaseClass, typename DerivedClass>
    inline bool is_base_of_v =
        mylib::is_class_v<BaseClass>    && // base    class must be a class
        mylib::is_class_v<DerivedClass> && // derived class must be a class too
        decltype(
            mylib::detail::test_is_base_of<
                BaseClass, DerivedClass
            >(0)
        )::value;                          // check

    // C++11
    template<typename BaseClass, typename DerivedClass>
    struct is_base_of :
        mylib::bool_constant<mylib::is_base_of_v<BaseClass, DerivedClass>>
    {};
    
#   endif

    // non-standard
    template<
        typename Type, 
        template<typename...>
        typename Template
    > inline constexpr bool is_specialization_v                               =
        false;
    
    // non-standard
    template<
        template<typename...>
        typename    Template,
        typename... Types
    > inline constexpr bool is_specialization_v<Template<Types...>, Template> =
        true;

#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)

    // C++17
    // __is_convertible_v is available in clang, gcc and msvc
    template<typename From, typename To>
    inline constexpr bool is_convertible_v = __is_convertible_to(From, To);
    
    // C++11
    // __is_convertible_v is available in clang, gcc and msvc
    template<typename From, typename To>
    struct is_convertible :
        mylib::bool_constant<__is_convertible_to(From, To)>
    {};
    
#   elif defined(__cpp_concepts)

    // C++17
    template<typename From, typename To>
    inline constexpr bool is_convertible_v =
        requires {
            static_cast<To(*)(To)>(nullptr)(mylib::declval<From>());
        }               ||
       (mylib::is_void_v<From> &&
        mylib::is_void_v<To>);

    
    // C++11
    template<typename From, typename To>
    struct is_convertible :
        mylib::bool_constant<mylib::is_convertible_v<From, To>>
    {};
    
    // always false
#   else

}  
namespace detail {

    template<typename From, typename To>
    auto test_is_convertible_v(int) noexcept ->
        decltype(
            static_cast<To(*)(To)>(nullptr)(mylib::declval<From>()), mylib::true_type{}
        )
    {}

    template<typename From, typename To>
    auto test_is_convertible_v(...) noexcept ->
        mylib::false_type
    {}
}

export namespace mylib {
    
    // C++17
    template<typename From, typename To>
    inline constexpr bool is_convertible_v = 
       (decltype(
            detail::test_is_convertible_v<From, To>(0)
       )::value)               ||
       (mylib::is_void_v<From> &&
        mylib::is_void_v<To>);
    
    // C++11
    template<typename From, typename To>
    struct is_convertible :
        mylib::bool_constant<mylib::is_convertible_v<From, To>>
    {};
    
#   endif

    // always true
#   ifdef __cpp_concepts
    
    // C++20
    template<typename From, typename To>
    inline constexpr bool is_nothrow_convertible_v =
        requires {
            { static_cast<To (To) noexcept>(nullptr)(mylib::declval<From>()) } noexcept;
        }                      ||
       (mylib::is_void_v<From> &&
        mylib::is_void_v<To>);
        
#   else

}

namespace detail {

    template<typename From, typename To>
    auto test_is_nothrow_convertible_v(int) noexcept ->
        mylib::bool_constant<
            noexcept(
                static_cast<To(*)(To) noexcept>(nullptr)(mylib::declval<From>())
            )
        >
    {}

    template<typename From, typename To>
    auto test_is_nothrow_convertible_v(...) noexcept ->
        mylib::false_type
    {}
}

export namespace mylib {

    // C++20
    template<typename From, typename To>
    inline constexpr bool is_nothrow_convertible_v =
       (decltype(
           mylib::detail::test_is_nothrow_convertible_v<From, To>(0)
       )::value)               ||
       (mylib::is_void_v<From> &&
        mylib::is_void_v<To>);

#   endif
    
    // C++20
    template<typename From, typename To>
    struct is_nothrow_convertible :
        mylib::bool_constant<mylib::is_nothrow_convertible_v<From, To>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_scoped_enum_v =
        mylib::is_enum_v<Type> && !mylib::is_convertible_v<Type, int>;

    // C++11
    template<typename Type>
    struct is_scoped_enum :
        mylib::bool_constant<mylib::is_scoped_enum_v<Type>>
    {};
}
