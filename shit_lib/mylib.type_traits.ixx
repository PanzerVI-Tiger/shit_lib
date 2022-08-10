export module mylib.type_traits;

import mylib.container_traits;


export namespace mylib {
    
    template<typename Type, Type typeValue>
    struct integral_constant {
        using value_type = Type;
        using type       = integral_constant;
        
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
    using bool_constant = integral_constant<bool, boolValue>;

    using true_type  = bool_constant<true>;
    using false_type = bool_constant<false>;
    
    // is ^^ better than vv? 
    // using new methon to implement them all!
    
    /*
        using true_type  = integral_constant<bool, true>;
        using false_type = integral_constant<bool, false>;
    */

    // C++17
    template<typename BoolConstant>
    struct negation : bool_constant<!bool(BoolConstant::value)> {};
    
    // C++17
    template<typename BoolConstant>
    using negation_t = typename negation<BoolConstant>::type;
    
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
    
    namespace detail {
        // use auxiliary_disjunction to avoid too many inherit
        // auxiliary template
        template<bool firstValue, typename FirstConstant, typename... BoolConstants>
        struct auxiliary_conjunction { // handle false case and end, will end try
            using type = FirstConstant;
        };

        // auxiliary template
        template<typename FirstConstant, typename NextConstant, typename... BoolConstants>
        struct auxiliary_conjunction<true, FirstConstant, NextConstant, BoolConstants...> {
            // handle false case, then try to next
            using type =
                typename auxiliary_conjunction<
                    NextConstant::value,
                    NextConstant,
                    BoolConstants...
                >::type;
        };
    }

    // C++17
    template<typename... BoolConstants>
    struct conjunction : false_type // if BoolConstants is empty, false_type
    {};

    // C++17
    template<typename BoolConstant1, typename... BoolConstants>
    struct conjunction<BoolConstant1, BoolConstants...> :
        detail::auxiliary_conjunction<BoolConstant1::value, BoolConstant1, BoolConstants...> {
    };

    // C++17
    template<typename... BoolConstants>
    using conjunction_t = typename conjunction<BoolConstants...>::type;
    
    namespace detail {
        // use auxiliary_disjunction to avoid too many inherit
        // auxiliary template
        template<bool firstValue, typename FirstConstant, typename... BoolConstants>
        struct auxiliary_disjunction { // handle true case and end, will end try
            using type = FirstConstant;
        };

        // auxiliary template
        template<typename FirstConstant, typename NextConstant, typename... BoolConstants>
        struct auxiliary_disjunction<false, FirstConstant, NextConstant, BoolConstants...> {
            // handle false case, then try to next
            using type =
                typename auxiliary_disjunction<
                    NextConstant::value,
                    NextConstant,
                    BoolConstants...
                >::type;
        };
    }
    
    // C++17
    template<typename... BoolConstants>
    struct disjunction : false_type // if BoolConstants is empty, false_type
    {};
    
    // C++17
    template<typename BoolConstant1, typename... BoolConstants>
    struct disjunction<BoolConstant1, BoolConstants...> : 
        detail::auxiliary_disjunction<BoolConstant1::value, BoolConstant1, BoolConstants...>
    {};

    // C++17
    template<typename... BoolConstants>
    using disjunction_t = typename disjunction<BoolConstants...>::type;

    // C++20
    template<typename Type>
    struct type_identity {
        using type = Type;
    };

    // C++20
    template<typename Type>
    using type_identity_t = typename type_identity<Type>::type;

    template<typename...>
    using void_t = void;

    // not standard
    template<typename>
    inline constexpr bool always_true  = true;
    
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
    using remove_const_t = typename remove_const<Type>::type;

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
    using remove_volatile_t = typename remove_volatile<Type>::type;

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
    using remove_cv_t = typename remove_cv<Type>::type;

    template<typename Type>
    struct add_const {
        using type = const Type;
    };

    // C++14
    template<typename Type>
    using add_const_t = typename add_const<Type>::type;
    
    template<typename Type>
    struct add_volatile {
        using type = volatile Type;
    };

    // C++14
    template<typename Type>
    using add_volatile_t = typename add_volatile<Type>::type;

    template<typename Type>
    struct add_cv {
        using type = const volatile Type;
    };

    // C++14
    template<typename Type>
    using add_cv_t = typename add_cv<Type>::type;
    
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
    using remove_reference_t = typename remove_reference<Type>::type;
    
    // not standard
    template<typename Type, typename = void>
    struct add_reference {
        using lvalue_reference = Type;
        using rvalue_reference = Type;
    };

    template<typename Type>
    struct add_reference<Type, void_t<Type&>> {
        using lvalue_reference = Type&;
        using rvalue_reference = Type&&;
    };
    
    template<typename Type>
    struct add_rvalue_reference {
        using type = typename add_reference<Type>::rvalue_reference;
    };
    
    // C++14
    template<typename Type>
    using add_rvalue_reference_t = typename add_rvalue_reference<Type>::type;

    template<typename Type>
    struct add_lvalue_reference {
        using type = typename add_reference<Type>::lvalue_reference;
    };

    // C++14
    template<typename Type>
    using add_lvalue_reference_t = typename add_lvalue_reference<Type>::type;

    // define declval from utility,
    // to avoid circular dependency and import whole utility,
    template<typename Type>
    constexpr add_rvalue_reference_t<Type> declval() noexcept {
        static_assert(always_false<Type>, "declval shouldn't be called!");
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
    using remove_pointer_t = typename remove_pointer<Type>::type;

    template<typename Type, typename = void>
    struct add_pointer {
        using type = Type;
    };

    template<typename Type>
    struct add_pointer<Type, void_t<remove_reference_t<Type>*>> {
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
    inline constexpr bool is_same_v             = false;
    
    // C++17
    template<typename Type>
    inline constexpr bool is_same_v<Type, Type> = true;

#   endif
    
    template<typename Type1, typename Type2>
    struct is_same : 
        bool_constant<is_same_v<Type1, Type2>> 
    {};

    // not standard
    template<typename Type, typename... Types>
    inline constexpr bool is_any_of_v = disjunction_t<is_same<Type, Types>...>::value;
    
    // not standard
    template<typename Type, typename... Types>
    struct is_any_of : 
        bool_constant<is_any_of_v<Type, Types...>> 
    {};
    
    // C++17
    template<typename Type>
    inline constexpr bool is_void_v = is_same_v<remove_cv_t<Type>, void>;
    
    template<typename Type>
    struct is_void :
        bool_constant<is_void_v<Type>> 
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_null_pointer_v = is_same_v<remove_cv_t<Type>, std::nullptr_t>;

    template<typename Type>
    struct is_null_pointer :
        bool_constant<is_null_pointer_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_integral_v = 
        is_any_of_v<
            remove_cv_t<Type>,
            bool     ,
            char     , signed char   , unsigned char,
            char8_t  , char16_t      , char32_t     ,
            short    , unsigned short,
            int      , unsigned int  ,
            long     , unsigned long ,
            long long, unsigned long long
        >;

    template<typename Type>
    struct is_integral : 
        bool_constant<is_integral_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_floating_point_v =
        is_any_of_v<remove_cv_t<Type>, float, double, long double>;

    template<typename Type>
    struct is_floating_point :
        bool_constant<is_floating_point_v<Type>>
    {};

    // not standard
    template<typename Type>
    inline constexpr bool is_character_v =
        is_any_of_v<Type, char, wchar_t, char8_t, char16_t, char32_t>;

    // not standard
    template<typename Type>
    struct is_character :
        bool_constant<is_character_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_array_v             = false;
    
    // C++17
    template<typename Type>
    inline constexpr bool is_array_v<Type[]>     = true;
    
    // C++17
    template<typename Type, size_t size>
    inline constexpr bool is_array_v<Type[size]> = true;

    template<typename Type>
    struct is_array :
        bool_constant<is_array_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_enum_v  = __is_enum(Type);

    template<typename Type>
    struct is_enum :
        bool_constant<is_enum_v<Type>>
    {};
    
    // C++17
    template<typename Type>
    inline constexpr bool is_union_v = __is_union(Type);

    template<typename Type>
    struct is_union :
        bool_constant<is_union_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_class_v = __is_class(Type);

    template<typename Type>
    struct is_class :
        bool_constant<is_class_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_lvalue_reference_v        = false;
    
    // C++17
    template<typename Type>
    inline constexpr bool is_lvalue_reference_v<Type&> = true;

    template<typename Type>
    struct is_lvalue_reference :
        bool_constant<is_lvalue_reference_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_rvalue_reference_v        = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_rvalue_reference_v<Type&> = true;

    template<typename Type>
    struct is_rvalue_reference :
        bool_constant<is_rvalue_reference_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_reference_v = false;

    // C++17
    template<typename Type>
    inline constexpr bool is_reference_v<Type&>  = true;
    
    // C++17
    template<typename Type>
    inline constexpr bool is_reference_v<Type&&> = true;

    template<typename Type>
    struct is_reference :
        bool_constant<is_reference_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_const_v             = false;
    
    // C++17
    template<typename Type>
    inline constexpr bool is_const_v<const Type> = true;

    template<typename Type>
    struct is_const :
        bool_constant<is_const_v<Type>>
    {};

    // always true
#   ifdef __cpp_concepts
    
    // not standard
    template<typename Type>
    inline constexpr bool is_sizable_v = requires{ sizeof(Type); };

#   else

    namespace detail
    {
        template<class T>
        constexpr auto test_is_sizable(int) -> 
            decltype(sizeof(T), std::true_type{})
        {}
        
        template<class>
        constexpr auto test_is_sizable(...) -> 
            std::false_type
        {}
    }
    
    template<typename Type>
    inline constexpr bool is_sizable_v =
        decltype(detail::test_is_sizable<Type>(0))::value;
    
#   endif

    // not standard
    template<typename Type>
    struct is_sizable :
        bool_constant<is_sizable_v<Type>>
    {};
    
#   if defined(__clang__)
    
    // C++17
    // __is_function is only for clang
    template<typename Type>
    inline constexpr bool is_function_v = __is_function(Type);
    
#   elif 1 
    
    // C++17
    // only function types and reference types can't be const qualified
    template<typename Type>
    inline constexpr bool is_function_v =
        !is_const_v<const Type> && !is_reference_v<Type>;

    // never use
#   elif 0

    // C++17
    template<typename Type>
    inline constexpr bool is_function_v =
        false;
    
    // Result(Params...[, ...]) [const] [volatile] [& | &&] [noexcept] => 2 * 2 * 2 * 3 * 2 = 48
    
    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...)> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) const> =
        true;
    
    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) volatile> =
        true;
    
    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) const volatile> =
        true;
    
    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) &> =
        true;
    
    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) const &> =
        true;
    
    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) volatile &> =
        true;
    
    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) const volatile &> =
        true;
    
    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) &&> =
        true;
    
    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) const &&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) volatile &&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) const volatile &&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...)> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) const> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) volatile> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) const volatile> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) &> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) const&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) volatile&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) const volatile&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) &&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) const&&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) volatile&&> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) const volatile&&> =
        true;
    
    // noexcept, after C++17
    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) const noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) volatile noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) const volatile noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) & noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) const& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) volatile& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) const volatile& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) && noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) const&& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) volatile&& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params...) const volatile&& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) const noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) volatile noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) const volatile noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...)& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) const& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) volatile& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) const volatile& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...)&& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) const&& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) volatile&& noexcept> =
        true;

    template<typename Result, typename... Params>
    inline constexpr bool is_function_v<Result(Params..., ...) const volatile&& noexcept> =
        true;  

#   endif
    
    template<typename Type>
    struct is_function :
        bool_constant<is_function_v<Type>>
    {};

#   ifdef __clang__
    
    // C++17
    // __is_member_pointer is clang only
    template<typename Type>
    inline constexpr bool is_member_pointer_v 
        = __is_member_pointer(Type);
    
#   else
    
    // auxiliary template
    template<typename Type>
    inline constexpr bool auxiliary_is_member_pointer_v
        = false;
    
    // auxiliary template
    template<typename MemberType, typename ClassType>
    inline constexpr bool auxiliary_is_member_pointer_v<MemberType ClassType::*> 
        = true;
    
    // C++17
    template<typename Type>
    inline constexpr bool is_member_pointer_v = 
        auxiliary_is_member_pointer_v<remove_cv_t<Type>>;
    
#   endif

    template<typename Type>
    struct is_member_pointer :
        bool_constant<is_member_pointer_v<Type>>
    {};

#   ifdef __clang__
    
    // C++17
    // __is_member_object_pointer_v is clang only
    template<typename Type>
    inline constexpr bool is_member_object_pointer_v = 
        __is_member_object_pointer(Type);

#   else
    
    // auxiliary template
    template<typename Type>
    inline constexpr bool auxiliary_is_member_object_pointer_v
        = false;

    // auxiliary templatye
    template<typename MemberType, typename ClassType>
    inline constexpr bool auxiliary_is_member_object_pointer_v<MemberType ClassType::*>
        = !is_function_v<MemberType>;

    // C++17
    template<typename Type>
    inline constexpr bool is_member_object_pointer_v 
        = auxiliary_is_member_object_pointer_v<remove_cv_t<Type>>;
    
#endif

    template<typename Type>
    struct is_member_object_pointer :
        bool_constant<is_member_object_pointer_v<Type>>
    {};

#   ifdef __clang__
    
    // C++17
    // __is_member_function_pointer_v is clang only
    template<typename Type>
    inline constexpr bool is_member_function_pointer_v =
        __is_member_function_pointer(Type);

#   else

    namespace detail {
        // auxiliary template
        template<typename Type>
        inline constexpr bool auxiliary_is_member_function_pointer_v
            = false;

        // auxiliary template
        template<typename MemberType, typename ClassType>
        inline constexpr bool auxiliary_is_member_function_pointer_v<MemberType ClassType::*>
            = is_function_v<MemberType>;
    }
    
    // C++17
    template<typename Type>
    inline constexpr bool is_member_function_pointer_v
        = detail::auxiliary_is_member_function_pointer_v<remove_cv_t<Type>>;

#   endif

    template<typename Type>
    struct is_member_function_pointer :
        bool_constant<is_member_function_pointer_v<Type>>
    {};

    // C++17
    template<typename Type>
    inline constexpr bool is_arithmetic_v =
        is_integral_v<Type> || is_floating_point_v<Type>;

    template<typename Type>
    struct is_arithmetic :
        bool_constant<is_arithmetic_v<Type>>
    {};

    // always true
#   ifdef __cpp_concepts

    // not standard
    template<typename Type>
    inline constexpr bool is_returnable_v =
        requires{
            static_cast<Type(*)()>(nullptr);
        };

#   else

    namespace detail {
        
        template<typename Type>
        constexpr auto test_is_returnable(int) ->
            decltype(static_cast<Type(*)()>(nullptr), true_type{})
        {}

        template<typename Type>
        constexpr auto test_is_returnable(...) ->
            false_type
        {}
    }

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

#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)
    
    // C++17
    // __is_base_of is available in clang, gcc and msvc
    template<typename BaseClass, typename DerivedClass>
    inline constexpr bool is_base_of_v = __is_base_of(BaseClass, DerivedClass);

#   else

    namespace details {
        
        // auxiliary function template
        // if To is argument's type or it's base class, match this,
        // and when To is argument's private, protected or ambigous base class, will result in failure
        template<typename To>
        constexpr true_type  test_is_pointer_convertible(const volatile To*)   noexcept
        {}
        
        // auxiliary function template
        // else match this
        template<typename To>
        constexpr false_type test_is_pointer_convertible(const volatile void*) noexcept
        {}

        // auxiliary function template
        // a private, protected or ambigous base class will match this function template
        template<typename BaseClass, typename DerivedClass>
        constexpr auto test_is_base_of(...) noexcept -> true_type
        {}
        
        // auxiliary function template
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

    template <typename BaseClass, typename DerivedClass>
    inline constexpr bool is_base_of_v =
        is_class_v<BaseClass>    && // base    class must be a class
        is_class_v<DerivedClass> && // derived class must be a class too
        decltype(
            details::test_is_base_of<
                BaseClass, DerivedClass
            >(0)
        )::value;                   // check 
    
#   endif

    template<typename BaseClass, typename DerivedClass>
    struct is_base_of :
        bool_constant<is_base_of_v<BaseClass, DerivedClass>>
    {};

#   if defined(__clang) || defined(__GNUC__) || defined(_MSVC_LANG)

    // C++17
    // __is_convertible_v is available in clang, gcc and msvc
    template<typename From, typename To>
    inline constexpr bool is_convertible_v = __is_convertible_to(From, To);
    
#   elif defined(__cpp_concepts)

    // C++17
    template<typename From, typename To>
    inline constexpr bool is_convertible_v =
        requires{
            static_cast<To(*)(To)>(nullptr)(declval<From>());
        }               ||
       (is_void_v<From> &&
        is_void_v<To>);
    
    // always false
#   else
    
    namespace detail {

        template<typename From, typename To>
        constexpr auto test_is_convertible_v(int) noexcept ->
            decltype(static_cast<true_type(*)(To)>(nullptr)(declval<From>()))
        {}

        template<typename From, typename To>
        constexpr auto test_is_convertible_v(...) noexcept ->
            false_type
        {}
    }
    
    // C++17
    template<typename From, typename To>
    inline constexpr bool is_convertible_v =
       (is_returnable_v<To>                            &&
        decltype(
            detail::test_is_convertible_v<From, To>(0)
        )::value)                                      ||
       (is_void_v<From>                                &&
        is_void_v<To>);
    
#   endif

    template<typename From, typename To>
    struct is_convertible :
        bool_constant<is_convertible_v<From, To>>
    {};

    namespace unittest {
        
        template<typename Void = void>
        constexpr bool assert_test_type_traits() noexcept {
            return true;
        }
        
        static_assert(assert_test_type_traits(), "type_traits have bug!");
    }
}
