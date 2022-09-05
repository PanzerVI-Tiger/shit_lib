module;

#ifdef __INTELLISENSE__

#include <cstddef>

#endif

export module mylib.type_traits;

#ifndef __INTELLISENSE__

import std.core;

#endif

export namespace mylib {

    template<typename Type, Type typeValue>
    struct integral_constant {
        using value_type = Type;
        using type = integral_constant;

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
    using bool_constant = mylib::integral_constant<bool, boolValue>;

    using true_type  = mylib::bool_constant<true>;
    using false_type = mylib::bool_constant<false>;

    // is ^^ better than vv? 
    // using new methon to implement them all!

    /*
        using true_type  = mylib::integral_constant<bool, true>;
        using false_type = mylib::integral_constant<bool, false>;
    */

    // C++17
    template<typename BoolConstant>
    struct negation :
        mylib::bool_constant<!static_cast<bool>(BoolConstant::value)> {
    };

    // C++17
    template<typename BoolConstant>
    using negation_t = typename mylib::negation<BoolConstant>::type;

    template<bool cond, typename TrueCase, typename FalseCase>
    struct conditional {
        using type = TrueCase;
    };

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
        false_type // if BoolConstants is empty, false_type
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
        false_type // if BoolConstants is empty, false_type
    {};

    // C++17
    template<typename BoolConstant1, typename... BoolConstants>
    struct disjunction<BoolConstant1, BoolConstants...> :
        mylib::detail::disjunction_impl<
        BoolConstant1::value, BoolConstant1, BoolConstants...
        > 
    {};

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

    template<typename...>
    using void_t = void;

    // not standard
    template<typename>
    inline constexpr bool always_true = true;

    // not standard
    template<typename>
    inline constexpr bool always_false = false;

    template<typename Type>
    struct remove_const {
        using type = Type;
    };

    template<typename Type>
    struct remove_const<const Type> {
        using type = Type;
    };

    // C++14
    template<typename Type>
    using remove_const_t = typename mylib::remove_const<Type>::type;

    template<typename Type>
    struct remove_volatile {
        using type = Type;
    };

    template<typename Type>
    struct remove_volatile<volatile Type> {
        using type = Type;
    };

    // C++14
    template<typename Type>
    using remove_volatile_t = typename mylib::remove_volatile<Type>::type;

    template<typename Type>
    struct remove_cv {
        using type = Type;
    };

    template<typename Type>
    struct remove_cv<const Type> {
        using type = Type;
    };

    template<typename Type>
    struct remove_cv<volatile Type> {
        using type = Type;
    };

    template<typename Type>
    struct remove_cv<const volatile Type> {
        using type = Type;
    };

    // C++14
    template<typename Type>
    using remove_cv_t = typename mylib::remove_cv<Type>::type;

    template<typename Type>
    struct add_const {
        using type = const Type;
    };

    // C++14
    template<typename Type>
    using add_const_t = typename mylib::add_const<Type>::type;

    template<typename Type>
    struct add_volatile {
        using type = volatile Type;
    };

    // C++14
    template<typename Type>
    using add_volatile_t = typename mylib::add_volatile<Type>::type;

    template<typename Type>
    struct add_cv {
        using type = const volatile Type;
    };

    // C++14
    template<typename Type>
    using add_cv_t = typename mylib::add_cv<Type>::type;

    template<typename Type>
    struct remove_reference {
        using type = Type;
    };

    template<typename Type>
    struct remove_reference<Type&> {
        using type = Type;
    };

    template<typename Type>
    struct remove_reference<Type&&> {
        using type = Type;
    };

    // C++14
    template<typename Type>
    using remove_reference_t = typename mylib::remove_reference<Type>::type;

    // not standard
    template<typename Type, typename = void>
    struct add_reference {
        using lvalue_reference = Type;
        using rvalue_reference = Type;
    };

    // not standard
    template<typename Type>
    struct add_reference<Type, mylib::void_t<Type&>> {
        using lvalue_reference = Type&;
        using rvalue_reference = Type&&;
    };

    template<typename Type>
    struct add_rvalue_reference {
        using type = typename mylib::add_reference<Type>::rvalue_reference;
    };

    // C++14
    template<typename Type>
    using add_rvalue_reference_t = typename mylib::add_rvalue_reference<Type>::type;

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
    constexpr add_rvalue_reference_t<Type> declval() noexcept {
        static_assert(mylib::always_false<Type>, "declval shouldn't be called!");
    }

    template<typename Type>
    struct remove_pointer {
        using type = Type;
    };

    template<typename Type>
    struct remove_pointer<Type*> {
        using type = Type;
    };

    template<typename Type>
    struct remove_pointer<Type* const> {
        using type = Type;
    };

    template<typename Type>
    struct remove_pointer<Type* volatile> {
        using type = Type;
    };

    template<typename Type>
    struct remove_pointer<Type* const volatile> {
        using type = Type;
    };

    // C++14
    template<typename Type>
    using remove_pointer_t = typename mylib::remove_pointer<Type>::type;

    template<typename Type, typename = void>
    struct add_pointer {
        using type = Type;
    };

    template<typename Type>
    struct add_pointer<Type, mylib::void_t<mylib::remove_reference_t<Type>*>> {
        using type = remove_reference_t<Type>*;
    };

#   ifdef __clang__

    // C++17
    // __is_same is clang only
    template<typename Type1, typename Type2>
    inline constexpr bool is_same_v = __is_same(Type1, Type2);

#   else

    // C++17
    template<typename Type1, typename Type2>
    inline constexpr bool is_same_v = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_same_v<Type, Type> = true;

#   endif

    template<typename Type1, typename Type2>
    struct is_same :
        mylib::bool_constant<mylib::is_same_v<Type1, Type2>> {
    };

    // not standard
    template<typename Type, typename... Types>
    inline constexpr bool is_any_of_v =
        mylib::disjunction_t<is_same<Type, Types>...>::value;

    // not standard
    template<typename Type, typename... Types>
    struct is_any_of :
        mylib::bool_constant<mylib::is_any_of_v<Type, Types...>> {
    };

    // C++17
    template<typename Type>
    inline constexpr bool is_void_v = mylib::is_same_v<remove_cv_t<Type>, void>;

    template<typename Type>
    struct is_void :
        mylib::bool_constant<mylib::is_void_v<Type>> {
    };

    // C++17
    template<typename Type>
    inline constexpr bool is_null_pointer_v =
        mylib::is_same_v<remove_cv_t<Type>, std::nullptr_t>;

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

    template<typename Type>
    struct is_integral :
        mylib::bool_constant<mylib::is_integral_v<Type>> 
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_floating_point_v =
        mylib::is_any_of_v<remove_cv_t<Type>, float, double, long double>;

    template<typename Type>
    struct is_floating_point :
        mylib::bool_constant<mylib::is_floating_point_v<Type>>
    {};

    // not standard
    template<typename Type>
    inline constexpr bool is_character_v =
        mylib::is_any_of_v<Type, char, wchar_t, char8_t, char16_t, char32_t>;

    // not standard
    template<typename Type>
    struct is_character :
        mylib::bool_constant<mylib::is_character_v<Type>> 
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_array_v = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_array_v<Type[]> = true;

    // C++17
    template<typename Type, size_t size>
    inline constexpr bool is_array_v<Type[size]> = true;

    template<typename Type>
    struct is_array :
        mylib::bool_constant<mylib::is_array_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_enum_v = __is_enum(Type);

    template<typename Type>
    struct is_enum :
        mylib::bool_constant<mylib::is_enum_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_union_v = __is_union(Type);

    template<typename Type>
    struct is_union :
        mylib::bool_constant<mylib::is_union_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_class_v = __is_class(Type);

    template<typename Type>
    struct is_class :
        mylib::bool_constant<mylib::is_class_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_const_v = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_const_v<const Type> = true;

    template<typename Type>
    struct is_const :
        mylib::bool_constant<mylib::is_const_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_lvalue_reference_v = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_lvalue_reference_v<Type&> = true;

    template<typename Type>
    struct is_lvalue_reference :
        mylib::bool_constant<mylib::is_lvalue_reference_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_rvalue_reference_v = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_rvalue_reference_v<Type&> = true;

    template<typename Type>
    struct is_rvalue_reference :
        mylib::bool_constant<mylib::is_rvalue_reference_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_reference_v = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_reference_v<Type&> = true;

    // C++17
    template<typename Type>
    inline constexpr bool is_reference_v<Type&&> = true;

    template<typename Type>
    struct is_reference :
        bool_constant<mylib::is_reference_v<Type>>
    {};

#   ifdef __clang__

    // C++17
    // __is_function is clang only
    template<typename Type>
    inline constexpr bool is_function_v = __is_function(Type);

#   elif 1 

    // C++17
    // only function types and reference types can't be const qualified
    template<typename Type>
    inline constexpr bool is_function_v =
        !mylib::is_const_v<const Type> && !mylib::is_reference_v<Type>;

    // never used
#   elif 0

    // C++17
    template<typename Type>
    inline constexpr bool is_function_v =
        false;

    // Result (Params...[, ...]) [const] [volatile] [& | &&] [noexcept] => 2 * 2 * 2 * 3 * 2 = 48

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...)> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) volatile> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const volatile> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) &> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) volatile&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const volatile&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) &&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const&&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) volatile&&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const volatile&&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...)> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) volatile> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const volatile> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) &> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) volatile&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const volatile&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) &&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const&&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) volatile&&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const volatile&&> =
        true;

    // noexcept, after C++17
    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) volatile noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const volatile noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) & noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) volatile& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const volatile& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) && noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const&& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) volatile&& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params...) const volatile&& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) volatile noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const volatile noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) & noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) volatile& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const volatile& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) && noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const&& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) volatile&& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result (Params..., ...) const volatile&& noexcept> =
        true;

#   endif

    template<typename Type>
    struct is_function :
        bool_constant<mylib::is_function_v<Type>>
    {};
}

namespace mylib::detail {
    // implementation
    template<typename Type>
    inline constexpr bool is_pointer_v_impl = false;

    // implementation
    template<typename Type>
    inline constexpr bool is_pointer_v_impl<Type*> = true;
}

export namespace mylib {

    // C++17
    template<typename Type>
    inline constexpr bool is_pointer_v =
        mylib::detail::is_pointer_v_impl<mylib::remove_cv_t<Type>>;

    template<typename Type>
    struct is_pointer :
        mylib::bool_constant<mylib::is_pointer_v<Type>>
    {};

#   ifdef __clang__

    // C++17
    // __is_member_pointer is clang only
    template<typename Type>
    inline constexpr bool is_member_pointer_v
        = __is_member_pointer(Type);

#   else
}

namespace mylib::detail {
    // implementation
    template<typename Type>
    inline constexpr bool is_member_pointer_v_impl
        = false;

    // implementation
    template<typename MemberType, typename ClassType>
    inline constexpr bool is_member_pointer_v_impl<MemberType ClassType::*>
        = true;
}
  
export namespace mylib {

    // C++17
    template<typename Type>
    inline constexpr bool is_member_pointer_v =
        mylib::detail::is_member_pointer_v_impl<mylib::remove_cv_t<Type>>;

#   endif

    template<typename Type>
    struct is_member_pointer :
        mylib::bool_constant<mylib::is_member_pointer_v<Type>>
    {};

#   ifdef __clang__

    // C++17
    // __is_member_object_pointer_v is clang only
    template<typename Type>
    inline constexpr bool is_member_object_pointer_v =
        __is_member_object_pointer(Type);

#   else
}

namespace mylib::detail {
    // implementation
    template<typename Type>
    inline constexpr bool is_member_object_pointer_v_impl
        = false;

    // implementation
    template<typename MemberType, typename ClassType>
    inline constexpr bool is_member_object_pointer_v_impl<MemberType ClassType::*>
        = !mylib::is_function_v<MemberType>;
}

export namespace mylib {

    // C++17
    template<typename Type>
    inline constexpr bool is_member_object_pointer_v
        = mylib::detail::is_member_object_pointer_v_impl<mylib::remove_cv_t<Type>>;

#endif

    template<typename Type>
    struct is_member_object_pointer :
        mylib::bool_constant<mylib::is_member_object_pointer_v<Type>> {
    };

#   ifdef __clang__

    // C++17
    // __is_member_function_pointer_v is clang only
    template<typename Type>
    inline constexpr bool is_member_function_pointer_v =
        __is_member_function_pointer(Type);

#   else
}

namespace mylib::detail {
    // implementation
    template<typename Type>
    inline constexpr bool is_member_function_pointer_v_impl
        = false;

    // implementation
    template<typename MemberType, typename ClassType>
    inline constexpr bool is_member_function_pointer_v_impl<MemberType ClassType::*>
        = is_function_v<MemberType>;
}

export namespace mylib {

    // C++17
    template<typename Type>
    inline constexpr bool is_member_function_pointer_v
        = mylib::detail::is_member_function_pointer_v_impl<mylib::remove_cv_t<Type>>;

#   endif

    template<typename Type>
    struct is_member_function_pointer :
        mylib::bool_constant<mylib::is_member_function_pointer_v<Type>>
    {};

    // always true
#   ifdef __cpp_concepts

    // not standard
    template<typename Type>
    inline constexpr bool is_sizable_v = requires { sizeof(Type); };

#   else
}

namespace mylib::detail {

    template<class T>
    constexpr auto test_is_sizable(int) ->
        decltype(sizeof(T), std::true_type{})
    {}

    template<class>
    constexpr auto test_is_sizable(...) ->
        std::false_type
    {}
}

export namespace mylib {

    template<typename Type>
    inline constexpr bool is_sizable_v =
        decltype(detail::test_is_sizable<Type>(0))::value;
    
#   endif

    // not standard
    template<typename Type>
    struct is_sizable :
        mylib::bool_constant<mylib::is_sizable_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_arithmetic_v =
        mylib::is_integral_v<Type> || mylib::is_floating_point_v<Type>;

    template<typename Type>
    struct is_arithmetic :
        mylib::bool_constant<mylib::is_arithmetic_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_fundamental_v =
        mylib::is_arithmetic_v<Type> || mylib::is_void_v<Type> || 
        mylib::is_null_pointer_v<Type>;

    template<typename Type>
    struct is_fundamental :
        mylib::bool_constant<mylib::is_fundamental_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_scalar_type_v =
        mylib::is_arithmetic_v<Type> || mylib::is_enum_v<Type>           ||
        mylib::is_pointer_v<Type>    || mylib::is_member_pointer_v<Type> ||
        mylib::is_null_pointer_v<Type>;

    // always true
#   if 1
       
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

    template<typename Type>
    struct is_object :
        mylib::bool_constant<mylib::is_object_v<Type>>
    {};

    // always true
#   ifdef __cpp_concepts

    // not standard
    template<typename Type>
    inline constexpr bool is_returnable_v =
        requires {
            static_cast<Type(*)()>(nullptr);
        };

#   else
}

namespace mylib::detail {

    template<typename Type>
    constexpr auto test_is_returnable(int) ->
        decltype(static_cast<Type(*)()>(nullptr), true_type{})
    {}

    template<typename Type>
    constexpr auto test_is_returnable(...) ->
        false_type
    {}
}

export namespace mylib {

    // not standard
    template<typename Type>
    inline constexpr bool is_returnable_v =
        decltype(detail::test_is_returnable<Type>(0))::value;

#   endif

    // not standard
    template<typename Type>
    struct is_returnable :
        bool_constant<is_returnable_v<Type>>
    {};
    
    // C++17
    template<typename Type>
    inline constexpr bool is_volatile_v                = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_volatile_v<volatile Type> = true;

    template<typename Type>
    struct is_volatile :
        bool_constant<is_volatile_v<Type>>
    {};
    
#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)
    
    // C++17
    // __is_base_of is available in clang, gcc and msvc
    template<typename BaseClass, typename DerivedClass>
    inline constexpr bool is_base_of_v = __is_base_of(BaseClass, DerivedClass);

#   else
}

namespace mylib::detail {
        
    // helper function template
    // if To is argument's type or it's base class, match this,
    // and when To is argument's private, protected or ambigous base class, will result in failure
    template<typename To>
    constexpr true_type  test_is_pointer_convertible(const volatile To*)   noexcept
    {}

    // helper function template
    // else match this
    template<typename To>
    constexpr false_type test_is_pointer_convertible(const volatile void*) noexcept
    {}

    // helper function template
    // a private, protected or ambigous base class will match this function template
    template<typename BaseClass, typename DerivedClass>
    constexpr auto test_is_base_of(...) noexcept -> true_type
    {}

    // helper function template
    template<typename BaseClass, typename DerivedClass>
    constexpr auto test_is_base_of(int) noexcept ->
        // check can the derived class cast to base class
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

    template <typename BaseClass, typename DerivedClass>
    inline constexpr bool is_base_of_v =
        mylib::is_class_v<BaseClass>    && // base    class must be a class
        mylib::is_class_v<DerivedClass> && // derived class must be a class too
        decltype(
            mylib::detail::test_is_base_of<
                BaseClass, DerivedClass
            >(0)
        )::value;                          // check 
    
#   endif

    template<typename BaseClass, typename DerivedClass>
    struct is_base_of :
        mylib::bool_constant<mylib::is_base_of_v<BaseClass, DerivedClass>>
    {};

    template<
        typename Type, 
        template<typename...>
        typename Template
    > inline constexpr bool is_specialization_v
        = false;

    template<
        template<typename...>
        typename    Template,
        typename... Types
    > inline constexpr bool is_specialization_v<Template<Types...>, Template> 
        = true;

#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)

    // C++17
    // __is_convertible_v is available in clang, gcc and msvc
    template<typename From, typename To>
    inline constexpr bool is_convertible_v = __is_convertible_to(From, To);
    
#   elif defined(__cpp_concepts)

    // C++17
    template<typename From, typename To>
    inline constexpr bool is_convertible_v =
        requires {
            static_cast<To(*)(To)>(nullptr)(mylib::declval<From>());
        }               ||
       (mylib::is_void_v<From> &&
           mylib::is_void_v<To>);
    
    // always false
#   else
}  
namespace detail {

    template<typename From, typename To>
    constexpr auto test_is_convertible_v(int) noexcept ->
        decltype(static_cast<To(*)(To)>(nullptr)(mylib::declval<From>()), true_type{})
    {}

    template<typename From, typename To>
    constexpr auto test_is_convertible_v(...) noexcept ->
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
    
#   endif

    template<typename From, typename To>
    struct is_convertible :
        mylib::bool_constant<mylib::is_convertible_v<From, To>>
    {};

    // always true
#   ifdef __cpp_concepts
    
    // C++20
    template<typename From, typename To>
    inline constexpr bool is_nothrow_convertible_v =
        requires {
            { static_cast<To(*)(To) noexcept>(nullptr)(mylib::declval<From>()) } noexcept;
        }                      ||
       (mylib::is_void_v<From> &&
        mylib::is_void_v<To>);
        
#   else
}

namespace detail {

    template<typename From, typename To>
    constexpr auto test_is_nothrow_convertible_v(int) noexcept ->
        mylib::bool_constant<
            noexcept(
                static_cast<To(*)(To) noexcept>(nullptr)(mylib::declval<From>())
            )
        >
    {}

    template<typename From, typename To>
    constexpr auto test_is_nothrow_convertible_v(...) noexcept ->
        mylib::false_type
    {}
}

export namespace mylib {

    // C++20
    template<typename From, typename To>
    inline constexpr bool is_nothrow_convertible_v =
       (decltype(
           mylib::detail::test_is_nothrow_convertible_v<From, To>(0)
       )::value)                  ||
       (mylib::is_void_v<From>    &&
        mylib::is_void_v<To>);

#   endif

    
    // C++20
    template<typename From, typename To>
    struct is_nothrow_convertible :
        mylib::bool_constant<mylib::is_nothrow_convertible_v<From, To>>
    {};

    
#   ifdef MYLIB_UNITTEST

    namespace unittest {
        
        template<typename Void = void>
        constexpr bool type_traits_assert_test() noexcept {
            // test integral_constant
            constexpr mylib::integral_constant<int, 114514> integralConstant1;
            constexpr 
            mylib::integral_constant<long long, 1145141919810LL> integralConstant2;

            // test value
            static_assert(integralConstant1.value == 114514);
            static_assert(integralConstant2.value == 1145141919810LL);
            
            // test operator Type()
            static_assert(integralConstant1 == 114514);
            static_assert(integralConstant2 == 1145141919810LL);

            // test operator()
            static_assert(integralConstant1() == 114514);
            static_assert(integralConstant2() == 1145141919810LL);
            
            // test true_type and false_type
            static_assert( mylib::true_type{});
            static_assert(!mylib::false_type{});

            // test is_void_v
            static_assert(mylib::is_void_v<void>);

            // test is_null_pointer_v
            static_assert(mylib::is_null_pointer_v<nullptr_t>);

            // test is_integral_v
            static_assert( mylib::is_integral_v<char>);
            static_assert( mylib::is_integral_v<long>);
            static_assert( mylib::is_integral_v<char8_t>);
            static_assert( mylib::is_integral_v<char16_t>);
            static_assert( mylib::is_integral_v<char32_t>);
            static_assert( mylib::is_integral_v<long long>);
            static_assert( mylib::is_integral_v<volatile int>);
            static_assert( mylib::is_integral_v<unsigned int>);
            static_assert( mylib::is_integral_v<const volatile short>);
            static_assert( mylib::is_integral_v<const unsigned long long>);

            static_assert(!mylib::is_integral_v<void>);
            static_assert(!mylib::is_integral_v<char*>);
            static_assert(!mylib::is_integral_v<float>);
            static_assert(!mylib::is_integral_v<double>);
            static_assert(!mylib::is_integral_v<nullptr_t>);
            static_assert(!mylib::is_integral_v<long double>);

            // test is_floating_point_v
            static_assert( mylib::is_floating_point_v<float>);
            static_assert( mylib::is_floating_point_v<double>);
            static_assert( mylib::is_floating_point_v<long double>);
            static_assert( mylib::is_floating_point_v<const float>);
            static_assert( mylib::is_floating_point_v<volatile double>);
            static_assert( mylib::is_floating_point_v<const volatile long double>);

            static_assert(!mylib::is_floating_point_v<int>);
            static_assert(!mylib::is_floating_point_v<char>);
            static_assert(!mylib::is_floating_point_v<void>);
            static_assert(!mylib::is_floating_point_v<char*>);
            static_assert(!mylib::is_floating_point_v<long long>);
            static_assert(!mylib::is_floating_point_v<nullptr_t>);
            static_assert(!mylib::is_floating_point_v<unsigned int>);
            static_assert(!mylib::is_floating_point_v<unsigned long long>);

            // test is_array_v
            static_assert( mylib::is_array_v<char[3]>);
            static_assert( mylib::is_array_v<long long[]>);
            static_assert( mylib::is_array_v<const int[3]>);
            static_assert( mylib::is_array_v<volatile double[3]>);
            static_assert( mylib::is_array_v<const volatile long long[3]>);

            static_assert(!mylib::is_array_v<int>);
            static_assert(!mylib::is_array_v<void>);
            static_assert(!mylib::is_array_v<char*>);
            static_assert(!mylib::is_array_v<nullptr_t>);
            static_assert(!mylib::is_array_v<long long>);

            // test is_pointer_v
            static_assert( mylib::is_pointer_v<int*>);
            static_assert( mylib::is_pointer_v<const int*>);
            static_assert( mylib::is_pointer_v<long long*>);

            static_assert(!mylib::is_pointer_v<int>);
            static_assert(!mylib::is_pointer_v<void>);
            static_assert(!mylib::is_pointer_v<long long>);
            static_assert(!mylib::is_pointer_v<nullptr_t>);
            
            enum Enum1 {};

            enum Enum2 : long long {};

            enum class EnumClass1  {};

            enum class EnumClass2 : unsigned long long {};

            // test is_enum

            static_assert( mylib::is_enum_v<Enum1>);
            static_assert( mylib::is_enum_v<Enum2>);
            static_assert( mylib::is_enum_v<EnumClass2>);
            static_assert( mylib::is_enum_v<EnumClass1>);
            static_assert( mylib::is_enum_v<const Enum2>);
            static_assert( mylib::is_enum_v<const EnumClass1>);

            static_assert(!mylib::is_enum_v<int>);
            static_assert(!mylib::is_enum_v<void>);
            static_assert(!mylib::is_enum_v<char*>);
            static_assert(!mylib::is_enum_v<nullptr_t>);
            static_assert(!mylib::is_enum_v<long long>);

            // test is_union
            union Union1 {};

            union Union2 { 
                int       i;
                long long ll;
            };

            struct Struct1 {};

            struct Struct2 {
                long long ll;
                double    d;
            };

            struct Struct3 : 
                Struct1 
            {};


            
            return true;
        }
        
        static_assert(mylib::unittest::type_traits_assert_test(), "type_traits have bug!");
    }

#   endif
    
}
