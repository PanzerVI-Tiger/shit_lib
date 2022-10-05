module;

#ifdef __INTELLISENSE__

#include <concepts>
#include <functional>

#endif

#include "macro_meta.hpp"

export module mylib.functional;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.utility;
import mylib.type_list;
import mylib.type_traits;

export namespace mylib {

    template<typename Function>
    struct function_traits;

    // due to too complex, may will crash intellisense
#   ifndef __INTELLISENSE__n

    // ref: 0: without     reference qualifier,
    //      1: with lvalue reference qualifier,
    //      2: with rvalue reference qualifier
#   define define_function_traits(isVararg, isConst, isVolatile, ref, isNoexcept)       \
        template<typename Result, typename... Params>                                   \
        struct function_traits<                                                         \
            Result(                                                                     \
                Params...                                                               \
                mylib_pp_if(isVararg)(...)()                                            \
            )                                                                           \
            mylib_pp_if(isConst)(const)()                                               \
            mylib_pp_if(isVolatile)(volatile)()                                         \
            mylib_pp_if(mylib_pp_equal(ref, 1))                                         \
            (&)                                                                         \
            (mylib_pp_if(mylib_pp_equal(ref, 2))                                        \
            (&&)())                                                                     \
            mylib_pp_if(isNoexcept)(noexcept)()                                         \
        >                                                                               \
        {                                                                               \
            using function = function_traits;                                           \
                                                                                        \
            using type =                                                                \
                Result(                                                                 \
                    Params...                                                           \
                    mylib_pp_if(isVararg)(...)()                                        \
                )                                                                       \
                mylib_pp_if(isConst)(const)()                                           \
                mylib_pp_if(isVolatile)(volatile)()                                     \
                mylib_pp_if(mylib_pp_equal(ref, 1))                                     \
                (&)                                                                     \
                (mylib_pp_if(mylib_pp_equal(ref, 2))                                    \
                (&&)())                                                                 \
                mylib_pp_if(isNoexcept)(noexcept)();                                    \
                                                                                        \
            using function_type  = type;                                                \
                                                                                        \
            using argument_types = mylib::type_list<Params...>;                         \
                                                                                        \
            using result_type    = Result;                                              \
                                                                                        \
            using add_vararg =                                                          \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                        ...                                                             \
                    )                                                                   \
                    mylib_pp_if(isConst)(const)()                                       \
                    mylib_pp_if(isVolatile)(volatile)()                                 \
                    mylib_pp_if(mylib_pp_equal(ref, 1))                                 \
                    (&)                                                                 \
                    (mylib_pp_if(mylib_pp_equal(ref, 2))                                \
                    (&&)())                                                             \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            using add_vararg_t = typename add_vararg::type;                             \
                                                                                        \
            using add_const =                                                           \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    const                                                               \
                    mylib_pp_if(isVolatile)(volatile)()                                 \
                    mylib_pp_if(mylib_pp_equal(ref, 1))                                 \
                    (&)                                                                 \
                    (mylib_pp_if(mylib_pp_equal(ref, 2))                                \
                    (&&)())                                                             \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            using add_const_t = typename add_const::type;                               \
                                                                                        \
            using add_volatile =                                                        \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    mylib_pp_if(isConst)(const)()                                       \
                    volatile                                                            \
                    mylib_pp_if(mylib_pp_equal(ref, 1))                                 \
                    (&)                                                                 \
                    (mylib_pp_if(mylib_pp_equal(ref, 2))                                \
                    (&&)())                                                             \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            using add_volatile_t = typename add_volatile::type;                         \
                                                                                        \
            using add_cv =                                                              \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    const                                                               \
                    volatile                                                            \
                    mylib_pp_if(mylib_pp_equal(ref, 1))                                 \
                    (&)                                                                 \
                    (mylib_pp_if(mylib_pp_equal(ref, 2))                                \
                    (&&)())                                                             \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            using add_cv_t = typename add_cv::type;                                     \
                                                                                        \
            using add_lvalueref_qualifier =                                             \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    mylib_pp_if(isConst)(const)()                                       \
                    mylib_pp_if(isVolatile)(volatile)()                                 \
                    &                                                                   \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            using add_lvalueref_qualifier_t = typename add_lvalueref_qualifier::type;   \
                                                                                        \
            using add_rvalueref_qualifier =                                             \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    mylib_pp_if(isConst)(const)()                                       \
                    mylib_pp_if(isVolatile)(volatile)()                                 \
                    &&                                                                  \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            using add_rvalueref_qualifier_t = typename add_rvalueref_qualifier::type;   \
                                                                                        \
            using add_noexcept =                                                        \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    mylib_pp_if(isConst)(const)()                                       \
                    mylib_pp_if(isVolatile)(volatile)()                                 \
                    mylib_pp_if(mylib_pp_equal(ref, 1))                                 \
                    (&)                                                                 \
                    (mylib_pp_if(mylib_pp_equal(ref, 2))                                \
                    (&&)())                                                             \
                    noexcept                                                            \
                >;                                                                      \
                                                                                        \
            using add_noexcept_t = typename add_noexcept::type;                         \
                                                                                        \
            using remove_vararg =                                                       \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                    )                                                                   \
                    mylib_pp_if(isConst)(const)()                                       \
                    mylib_pp_if(isVolatile)(volatile)()                                 \
                    mylib_pp_if(mylib_pp_equal(ref, 1))                                 \
                    (&)                                                                 \
                    (mylib_pp_if(mylib_pp_equal(ref, 2))                                \
                    (&&)())                                                             \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            using remove_vararg_t = typename remove_vararg::type;                       \
                                                                                        \
            using remove_const =                                                        \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    mylib_pp_if(isVolatile)(volatile)()                                 \
                    mylib_pp_if(mylib_pp_equal(ref, 1))                                 \
                    (&)                                                                 \
                    (mylib_pp_if(mylib_pp_equal(ref, 2))                                \
                    (&&)())                                                             \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            using remove_const_t = typename remove_const::type;                         \
                                                                                        \
            using remove_volatile =                                                     \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    mylib_pp_if(isConst)(const)()                                       \
                    mylib_pp_if(mylib_pp_equal(ref, 1))                                 \
                    (&)                                                                 \
                    (mylib_pp_if(mylib_pp_equal(ref, 2))                                \
                    (&&)())                                                             \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            using remove_volatile_t = typename remove_volatile::type;                   \
                                                                                        \
            using remove_cv =                                                           \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    mylib_pp_if(mylib_pp_equal(ref, 1))                                 \
                    (&)                                                                 \
                    (mylib_pp_if(mylib_pp_equal(ref, 2))                                \
                    (&&)())                                                             \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            using remove_cv_t = typename remove_cv::type;                               \
                                                                                        \
            using remove_lvalueref_qualifier =                                          \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    mylib_pp_if(isConst)(const)()                                       \
                    mylib_pp_if(isVolatile)(volatile)()                                 \
                    mylib_pp_if(mylib_pp_equal(ref, 2))                                 \
                    (&&)()                                                              \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            using remove_lvalueref_qualifier_t =                                        \
                typename remove_lvalueref_qualifier::type;                              \
                                                                                        \
            using remove_rvalueref_qualifier =                                          \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    mylib_pp_if(isConst)(const)()                                       \
                    mylib_pp_if(isVolatile)(volatile)()                                 \
                    mylib_pp_if(mylib_pp_equal(ref, 1))                                 \
                    (&)()                                                               \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            using remove_rvalueref_qualifier_t =                                        \
                typename remove_rvalueref_qualifier::type;                              \
                                                                                        \
            using remove_reference_qualifier =                                          \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    mylib_pp_if(isConst)(const)()                                       \
                    mylib_pp_if(isVolatile)(volatile)()                                 \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            using remove_reference_qualifier_t =                                        \
                typename remove_reference_qualifier::type;                              \
                                                                                        \
            using remove_noexcept =                                                     \
                function_traits<                                                        \
                    Result(                                                             \
                        Params...                                                       \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    mylib_pp_if(isConst)(const)()                                       \
                    mylib_pp_if(isVolatile)(volatile)()                                 \
                    mylib_pp_if(mylib_pp_equal(ref, 1))                                 \
                    (&)                                                                 \
                    (mylib_pp_if(mylib_pp_equal(ref, 2))                                \
                    (&&)())                                                             \
                >;                                                                      \
                                                                                        \
            using remove_noexcept_t = typename remove_noexcept::type;                   \
                                                                                        \
            template<typename NewResult>                                                \
            using replace_result =                                                      \
                function_traits<                                                        \
                    NewResult(                                                          \
                        Params...                                                       \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    mylib_pp_if(isConst)(const)()                                       \
                    mylib_pp_if(isVolatile)(volatile)()                                 \
                    mylib_pp_if(mylib_pp_equal(ref, 1))                                 \
                    (&)                                                                 \
                    (mylib_pp_if(mylib_pp_equal(ref, 2))                                \
                    (&&)())                                                             \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            template<typename NewResult>                                                \
            using replace_result_t = typename replace_result<NewResult>::type;          \
                                                                                        \
            template<typename... NewParams>                                             \
            using replace_arguments =                                                   \
                function_traits<                                                        \
                    Result(                                                             \
                        NewParams...                                                    \
                        mylib_pp_if(isVararg)(...)()                                    \
                    )                                                                   \
                    mylib_pp_if(isConst)(const)()                                       \
                    mylib_pp_if(isVolatile)(volatile)()                                 \
                    mylib_pp_if(mylib_pp_equal(ref, 1))                                 \
                    (&)                                                                 \
                    (mylib_pp_if(mylib_pp_equal(ref, 2))                                \
                    (&&)())                                                             \
                    mylib_pp_if(isNoexcept)(noexcept)()                                 \
                >;                                                                      \
                                                                                        \
            template<typename... NewParams>                                             \
            using replace_arguments_t = typename replace_arguments<NewParams...>::type; \
                                                                                        \
            static constexpr bool is_vararg()               noexcept {                  \
                return isVararg;                                                        \
            }                                                                           \
                                                                                        \
            static constexpr bool is_const()                noexcept {                  \
                return isConst;                                                         \
            }                                                                           \
                                                                                        \
            static constexpr bool is_volatile()             noexcept {                  \
                return isVolatile;                                                      \
            }                                                                           \
                                                                                        \
            static constexpr bool has_lvalueref_qualifier() noexcept {                  \
                return ref == 1;                                                        \
            }                                                                           \
                                                                                        \
            static constexpr bool has_rvalueref_qualifier() noexcept {                  \
                return ref == 2;                                                        \
            }                                                                           \
                                                                                        \
            static constexpr bool has_reference_qualifier() noexcept {                  \
                return ref;                                                             \
            }                                                                           \
                                                                                        \
            static constexpr bool is_noexcept()             noexcept {                  \
                return isNoexcept;                                                      \
            }                                                                           \
        }

#   define function_traits_applicator(tuple)                                            \
        mylib_pp_tuple_apply(tuple, define_function_traits)

    mylib_pp_repeat_each(
        function_traits_applicator,
        mylib_semicolon,
        (0, 0, 0, 0, 0), (1, 0, 0, 0, 0), (0, 1, 0, 0, 0), (1, 1, 0, 0, 0),
        (0, 0, 1, 0, 0), (1, 0, 1, 0, 0), (0, 1, 1, 0, 0), (1, 1, 1, 0, 0),
        (0, 0, 0, 1, 0), (1, 0, 0, 1, 0), (0, 1, 0, 1, 0), (1, 1, 0, 1, 0),
        (0, 0, 1, 1, 0), (1, 0, 1, 1, 0), (0, 1, 1, 1, 0), (1, 1, 1, 1, 0),
        (0, 0, 0, 2, 0), (1, 0, 0, 2, 0), (0, 1, 0, 2, 0), (1, 1, 0, 2, 0),
        (0, 0, 1, 2, 0), (1, 0, 1, 2, 0), (0, 1, 1, 2, 0), (1, 1, 1, 2, 0),
        (0, 0, 0, 0, 1), (1, 0, 0, 0, 1), (0, 1, 0, 0, 1), (1, 1, 0, 0, 1),
        (0, 0, 1, 0, 1), (1, 0, 1, 0, 1), (0, 1, 1, 0, 1), (1, 1, 1, 0, 1),
        (0, 0, 0, 1, 1), (1, 0, 0, 1, 1), (0, 1, 0, 1, 1), (1, 1, 0, 1, 1),
        (0, 0, 1, 1, 1), (1, 0, 1, 1, 1), (0, 1, 1, 1, 1), (1, 1, 1, 1, 1),
        (0, 0, 0, 2, 1), (1, 0, 0, 2, 1), (0, 1, 0, 2, 1), (1, 1, 0, 2, 1),
        (0, 0, 1, 2, 1), (1, 0, 1, 2, 1), (0, 1, 1, 2, 1), (1, 1, 1, 2, 1)
    );

    #   else

    template<typename Function>
        requires mylib::is_function_v<Function>
    struct function_traits<Function> {
        using type                         = Function;
        
        using function_type                = Function;

        using argument_types               = mylib::type_list<int>;
        
        using result_type                  = void;
                                           
        using add_vararg                   = function_traits<Function>;
                                           
        using add_vararg_t                 = Function;
                                           
        using add_const                    = function_traits<Function>;
                                           
        using add_const_t                  = Function;
                                           
        using add_volatile                 = function_traits<Function>;
                                           
        using add_volatile_t               = Function;

        using add_cv                       = function_traits<Function>;

        using add_cv_t                     = Function;
                                           
        using add_lvalueref_qualifier      = function_traits<Function>;
                                           
        using add_lvalueref_qualifier_t    = Function;
                                           
        using add_rvalueref_qualifier      = function_traits<Function>;
                                           
        using add_rvalueref_qualifier_t    = Function;
                                           
        using remove_vararg                = function_traits<Function>;
                                           
        using remove_vararg_t              = Function;
                                           
        using remove_const                 = function_traits<Function>;
                                           
        using remove_const_t               = Function;
                                           
        using remove_volatile              = function_traits<Function>;
                                           
        using remove_volatile_t            = Function;

        using remove_cv                    = function_traits<Function>;

        using remove_cv_t                  = Function;

        using remove_lvalueref_qualifier   = function_traits<Function>;
        
        using remove_lvalueref_qualifier_t = Function;

        using remove_rvalueref_qualifier   = function_traits<Function>;

        using remove_rvalueref_qualifier_t = Function;

        using remove_reference_qualifier   = function_traits<Function>;

        using remove_reference_qualifier_t = Function;

        using remove_noexcept              = function_traits<Function>;

        using remove_noexcept_t            = Function;

        template<typename NewResult>
        using replace_result               = function_traits<Function>;

        template<typename NewResult>
        using replace_result_t             = Function;

        template<typename... NewParams>
        using replace_arguments            = function_traits<Function>;

        template<typename... NewParams>
        using replace_arguments_t          = Function;
        
        static constexpr bool is_vararg()               noexcept {
            return false;
        }

        static constexpr bool is_const()                noexcept {
            return false;
        }

        static constexpr bool is_volatile()             noexcept {
            return false;
        }

        static constexpr bool has_lvalueref_qualifier() noexcept {
            return false;
        }

        static constexpr bool has_rvalueref_qualifier() noexcept {
            return false;
        }

        static constexpr bool has_reference_qualifier() noexcept {
            return false;
        }

        static constexpr bool is_noexcept()             noexcept {
            return true;
        }
    };

#   endif

    template<typename Result, typename... Params>
    using make_function   = mylib::function_traits<Result (Params...)>;

    template<typename Result, typename... Params>
    using make_function_t = typename make_function<Result, Params...>::type;

    struct member_pointer_tag
    {};
    
    struct member_object_pointer_tag :
        mylib::member_pointer_tag
    {};

    struct member_function_pointer_tag :
        mylib::member_pointer_tag
    {};
    
    template<typename MemberPointer>
    struct member_pointer_traits;

    // for member object pointers
    template<typename MemberType, typename Class>
        requires (!mylib::is_function_v<MemberType>)
    struct member_pointer_traits<MemberType Class::*> :
        mylib::function_traits<MemberType(Class)>
    {
        using type                                    = MemberType Class::*;
        using member_pointer_type                     = MemberType Class::*;
        
        using member_pointer_category                 = mylib::member_object_pointer_tag;
        
        using member_type                             = MemberType;
        using class_type                              = Class;
        
        using const_function_type                     = MemberType(const Class);
        using volatile_function_type                  = MemberType(volatile Class);
        using const_volatile_function_type            = MemberType(const volatile Class);
        using lvalue_reference_function_type          = MemberType(Class&);
        using rvalue_reference_function_type          = MemberType(Class&&);
        using const_lvalue_reference_function_type    = MemberType(const Class&);
        using const_rvalue_reference_function_type    = MemberType(const Class&&);
        using volatile_lvalue_reference_function_type = MemberType(volatile Class&);
        using volatile_rvalue_reference_function_type = MemberType(volatile Class&&);
        using cv_lvalue_reference_function_type       = MemberType(const volatile Class&);
        using cv_rvalue_reference_function_type       = MemberType(const volatile Class&&);

        using const_function                          =
            mylib::function_traits<const_function_type>;
        
        using volatile_function                       =
            mylib::function_traits<volatile_function_type>;
        
        using const_volatile_function                 =
            mylib::function_traits<const_volatile_function_type>;
        
        using lvalue_reference_function               =
            mylib::function_traits<lvalue_reference_function_type>;
        
        using rvalue_reference_function               =
            mylib::function_traits<rvalue_reference_function_type>;
        
        using const_lvalue_reference_function         =
            mylib::function_traits<const_lvalue_reference_function_type>;
        
        using const_rvalue_reference_function         =
            mylib::function_traits<const_rvalue_reference_function_type>;
        
        using volatile_lvalue_reference_function      =
            mylib::function_traits<volatile_lvalue_reference_function_type>;
        
        using volatile_rvalue_reference_function      =
            mylib::function_traits<volatile_rvalue_reference_function_type>;
        
        using cv_lvalue_reference_function            =
            mylib::function_traits<cv_lvalue_reference_function_type>;
        
        using cv_rvalue_reference_function            =
            mylib::function_traits<cv_rvalue_reference_function_type>;
    };

    // for member function pointers
    template<typename MemberType, typename Class>
        requires mylib::is_function_v<MemberType>
    struct member_pointer_traits<MemberType Class::*> :
        mylib::function_traits<MemberType>
      ::argument_types
      ::template push_front<Class>
      ::template to<
            mylib::function_traits<MemberType>
          ::template replace_arguments
        >
    {
        using type                                    = MemberType Class::*;
        using member_pointer_type                     = MemberType Class::*;
        
        using member_pointer_category                 = mylib::member_function_pointer_tag;
        
        using member_type                             = MemberType;
        using class_type                              = Class;
        
    private:
        template<typename ObjectArgument>
        using make_function                      =
            typename mylib::function_traits<MemberType>
          ::argument_types
          ::template push_front<ObjectArgument>
          ::template to<
                mylib::function_traits<MemberType>
              ::template replace_arguments
            >;
        
    public:
        using const_function                          = make_function<const Class>;
        using volatile_function                       = make_function<volatile Class>;
        using const_volatile_function                 = make_function<const volatile Class>;
        using lvalue_reference_function               = make_function<Class&>;
        using rvalue_reference_function               = make_function<Class&&>;
        using const_lvalue_reference_function         = make_function<const Class&>;
        using const_rvalue_reference_function         = make_function<const Class&&>;
        using volatile_lvalue_reference_function      = make_function<volatile Class&>;
        using volatile_rvalue_reference_function      = make_function<volatile Class&&>;
        using cv_lvalue_reference_function            = make_function<const volatile Class&>;
        using cv_rvalue_reference_function            = make_function<const volatile Class&&>;
                                                      
        using const_function_type                     =
            typename const_function::type;
        
        using volatile_function_type                  =
            typename volatile_function::type;
        
        using const_volatile_function_type            =
            typename const_volatile_function::type;
        
        using lvalue_reference_function_type          =
            typename lvalue_reference_function::type;
        
        using rvalue_reference_function_type          =
            typename rvalue_reference_function::type;
        
        using const_lvalue_reference_function_type    =
            typename const_lvalue_reference_function::type;
        
        using const_rvalue_reference_function_type    =
            typename const_rvalue_reference_function::type;
        
        using volatile_lvalue_reference_function_type =
            typename volatile_lvalue_reference_function::type;
        
        using volatile_rvalue_reference_function_type =
            typename volatile_rvalue_reference_function::type;
        
        using cv_lvalue_reference_function_type       =
            typename cv_lvalue_reference_function::type;
        
        using cv_rvalue_reference_function_type       =
            typename cv_rvalue_reference_function::type;
    };
    
    struct static_or_explict_object_argument_call_operator_tag
    {};

    struct implict_object_argument_call_operator_tag
    {};

    // valid only for function objects that have only one operator () overload
    template<typename FunctionObject>
    struct function_object_traits;

    // for function object with a static or explict object argument operator ()
    template<typename FunctionObject>
        requires
            requires {
                requires mylib::is_function_pointer_v<
                    decltype(&FunctionObject::operator ())
                >;
            }
    struct function_object_traits<FunctionObject> :
        mylib::function_traits<decltype(FunctionObject::operator ())>
    {
        using type                     = FunctionObject;
        using function_object_type     = FunctionObject;

        using function_object_category =
            mylib::static_or_explict_object_argument_call_operator_tag;

        static constexpr bool
        is_implict_object_argument_call_operator() noexcept {
            return false;
        }

        static constexpr bool
        is_static_or_explict_object_argument_call_operator() noexcept {
            return true;
        }
    };

    // for function object with a implict object argument operator ()
    template<typename FunctionObject>
        requires
            requires {
                // use is_member_function_pointer_v will crash intellisene
                requires (!mylib::is_function_pointer_v<
                    decltype(&FunctionObject::operator ())
                >);
            }
    struct function_object_traits<FunctionObject> :
        mylib::member_pointer_traits<decltype(&FunctionObject::operator ())>
    {
        using type                     = FunctionObject;
        using function_object_type     = FunctionObject;
        
        using function_object_category =
            mylib::implict_object_argument_call_operator_tag;

        static constexpr bool
        is_implict_object_argument_call_operator() noexcept {
            return true;
        }

        static constexpr bool
        is_static_or_explict_object_argument_call_operator() noexcept {
            return false;
        }
    };

    struct function_tag
    {};

    struct function_pointer_tag
    {};

    struct function_object_tag
    {};

    template<typename Invocation>
    struct invocation_traits
    {
        using type = Invocation;
    };

    // for function
    template<typename Function>
        requires mylib::is_function_v<Function>
    struct invocation_traits<Function> :
        mylib::function_traits<Function>
    {
        using type                = Function;
        using invocation_type     = Function;
        
        using invocation_category = mylib::function_tag;
    };

    // for function pointer
    template<typename FunctionPointer>
        requires mylib::is_function_pointer_v<FunctionPointer>
    struct invocation_traits<FunctionPointer> :
        mylib::function_traits<mylib::remove_pointer_t<FunctionPointer>>
    {
        using type                = FunctionPointer;
        using invocation_type     = FunctionPointer;

        using invocation_category = mylib::function_pointer_tag;
    };

#   ifndef __INTELLISENSE__

    // for function object with non-static implict object operator ()
    template<typename FunctionObject>
        requires
            requires { &FunctionObject::operator (); } &&
            mylib::is_member_function_pointer_v<decltype(&FunctionObject::operator ())>
    struct invocation_traits<FunctionObject> :
        mylib::function_traits<
            typename mylib::member_pointer_traits<
                decltype(&FunctionObject::operator ())
            >::member_type
        >
    {
        using type                = FunctionObject;
        using invocation_category = mylib::member_function_pointer_tag;
        
        static constexpr bool is_static_or_explict_object_argument() noexcept {
            return false;
        }
    };
            
    // for function object with static  or explict object argument operator ()
    template<typename FunctionObject>
        requires
            requires { FunctionObject::operator (); } &&
            mylib::is_function_v<decltype(FunctionObject::operator ())> 
    struct invocation_traits<FunctionObject> :
        mylib::function_traits<decltype(FunctionObject::operator ())>
    {
        using type                = FunctionObject;
        using invocation_category = mylib::member_function_pointer_tag;

        static constexpr bool is_static_or_explict_object_argument() noexcept {
            return true;
        }
    };

#   else

    template<typename FunctionObject>
        requires
            requires { &FunctionObject::operator (); }
    struct invocation_traits<FunctionObject> :
        mylib::function_traits<void()>
    {
        using type                = FunctionObject;
        using invocation_category = mylib::member_function_pointer_tag;

        static constexpr bool is_static_or_explict_object_argument() noexcept {
            return false;
        }
    };

#   endif
    
    // vv will cause intellisense to crash vv
    
    // for member function pointer
    template<typename MemberFunctionPointer>
        requires mylib::is_member_function_pointer_v<MemberFunctionPointer>
    struct invocation_traits<MemberFunctionPointer> :
        mylib::function_traits<
            typename mylib::member_pointer_traits<MemberFunctionPointer>::member_type
        >
    {
        using type                = MemberFunctionPointer;
        using invocation_category = mylib::member_function_pointer_tag;
    };

    // vv will cause intellisense to crash vv
    
    // for member object pointer
    template<typename MemberObjectPointer>
        requires mylib::is_member_object_pointer_v<MemberObjectPointer>
    struct invocation_traits<MemberObjectPointer> {
        using type                = MemberObjectPointer;
        
        using invocation_category = mylib::member_object_pointer_tag;
        
        using result_type         =
            typename mylib::member_pointer_traits<MemberObjectPointer>::member_type;
        
        using argument_types      =
            mylib::type_list<
                typename mylib::member_pointer_traits<MemberObjectPointer>::class_type*
            >;
        template<size_t index>
            requires (index == 0)
        using argument_type       = typename argument_types::template at<0>;
        
        using function_type       = result_type (argument_type<0>) noexcept;

        static constexpr bool is_vararg()               noexcept {
            return false;
        }
        
        static constexpr bool is_const()                noexcept {
            return false;
        }
        
        static constexpr bool is_volatile()             noexcept {
            return false;
        }
        
        static constexpr bool has_lvalueref_qualifier() noexcept {
            return false;
        }
        
        static constexpr bool has_rvalueref_qualifier() noexcept {
            return false;
        }
        
        static constexpr bool has_reference_qualifier() noexcept {
            return false;
        }
        
        static constexpr bool is_noexcept()             noexcept {
            return true;
        }
    };
    
    template<typename FunctionType>
    class function;

    template<typename Result, typename... Params>
    class function<Result (Params...)> {
        using result_type    = Result;
        using argument_types = mylib::type_list<Params...>;
    };
    
    template<typename Type = void>
    struct plus {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left + right;
        }
    };

    template<>
    struct plus<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left + right;
        }
    };

    template<typename Type = void>
    struct minus {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left - right;
        }
    };

    template<>
    struct minus<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left - right;
        }
    };

    template<typename Type = void>
    struct multiplies {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left * right;
        }
    };

    template<>
    struct multiplies<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left * right;
        }
    };

    template<typename Type = void>
    struct divides {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left / right;
        }
    };

    template<>
    struct divides<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left / right;
        }
    };

    template<typename Type = void>
    struct modulus {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left % right;
        }
    };
    
    template<>
    struct modulus<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left % right;
        }
    };

    template<typename Type = void>
    struct negate {
        Type operator()(const Type& left) const noexcept {
            return -left;
        }
    };

    template<>
    struct negate<void> {
        template<typename Type>
        Type operator()(const Type& left) const noexcept {
            return -left;
        }
    };

    template<typename Type = void>
    struct equal_to {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left == right;
        }
    };

    template<>
    struct equal_to<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left == right;
        }
    };

    template<typename Type = void>
    struct not_equal_to {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left != right;
        }
    };

    template<>
    struct not_equal_to<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left != right;
        }
    };

    template<typename Type = void>
    struct greater {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left > right;
        }
    };

    template<>
    struct greater<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left > right;
        }
    };

    template<typename Type = void>
    struct less {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left < right;
        }
    };

    template<>
    struct less<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left < right;
        }
    };
    
    template<typename Type = void>
    struct greater_equal {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left >= right;
        }
    };

    template<>
    struct greater_equal<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left >= right;
        }
    };

    template<typename Type = void>
    struct less_equal {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left <= right;
        }
    };

    template<>
    struct less_equal<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left <= right;
        }
    };

    template<typename Type = void>
    struct logical_and {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left && right;
        }
    };

    template<>
    struct logical_and<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left && right;
        }
    };

    template<typename Type = void>
    struct logical_or {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left || right;
        }
    };

    template<>
    struct logical_or<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left || right;
        }
    };

    template<typename Type = void>
    struct logical_not {
        bool operator()(const Type& left) const noexcept {
            return !left;
        }
    };

    template<>
    struct logical_not<void> {
        template<typename Type>
        bool operator()(const Type& left) const noexcept {
            return !left;
        }
    };

    template<typename Type = void>
    struct bit_and {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left & right;
        }
    };

    template<>
    struct bit_and<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left & right;
        }
    };

    template<typename Type = void>
    struct bit_or {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left | right;
        }
    };

    template<>
    struct bit_or<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left | right;
        }
    };

    template<typename Type = void>
    struct bit_xor {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left ^ right;
        }
    };

    template<>
    struct bit_xor<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left ^ right;
        }
    };

    template<typename Type = void>
    struct bit_not {
        Type operator()(const Type& left) const noexcept {
            return ~left;
        }
    };

    template<>
    struct bit_not<void> {
        template<typename Type>
        Type operator()(const Type& left) const noexcept {
            return ~left;
        }
    };

    template<typename Invocation, typename... Arguments>
    class curried_function
    {
    public:
        template<typename, typename...>
        friend class curried_function;
        
        using result_type =
            mylib::conditional_t<
                std::is_invocable_v<Invocation, Arguments...>,
                std::invoke_result<Invocation, Arguments...>,
                mylib::type_identity<void>
            >::type;

        static constexpr bool is_evalutable() noexcept {
            return std::is_invocable_v<Invocation, Arguments...>;
        }
        
        constexpr curried_function(
            Invocation&& _func, Arguments&&... _arguments
        ) noexcept :
            func        { std::forward<Invocation>(_func) },
            arguments   {mylib::forward<Arguments>(_arguments)...},
            is_invocated{}
        {}

    private:
        template<typename... Arguments1, typename... Arguments2>
        constexpr curried_function(
            bool                                               isInvocated,
            const curried_function<Invocation, Arguments1...>& old,
            std::tuple<Arguments2...>                       && arguments
        ) noexcept :
            func        { old.func },
            arguments   { std::tuple_cat(old.arguments, std::move(arguments)) },
            is_invocated{ isInvocated }
        {}

        template<typename... Arguments1, typename... Arguments2>
        constexpr curried_function(
            bool                                          isInvocated,
            curried_function<Invocation, Arguments1...>&& old,
            std::tuple<Arguments2...>                  && arguments
        ) noexcept :
            func{ std::move(old.func) },
            arguments{ std::tuple_cat(std::move(old.arguments), std::move(arguments)) },
            is_invocated{ isInvocated }
        {}
        
    public:
        constexpr ~curried_function() noexcept {
            if constexpr (is_evalutable()) {
                if (is_invocated) {
                    operator result_type();
                }
            }
        }
        
        template<typename... Arguments2>
        constexpr auto operator ()(Arguments2&&... args) const& noexcept {
            is_invocated = false;
            return
                curried_function<Invocation, Arguments..., Arguments2...>{
                    true, *this, std::make_tuple(std::forward<Arguments2>(args)...)
                };
        }

        template<typename... Arguments2>
        constexpr auto operator ()(Arguments2&&... args) && noexcept {
            is_invocated = false;
            return
                curried_function<Invocation, Arguments..., Arguments2...>{
                true, std::move(*this), std::make_tuple(std::move(args)...)
            };
        }
        
        constexpr operator result_type() noexcept
        {
            if (is_evalutable()) {
                is_invocated = false;
                return std::apply(func, arguments);
            }
        }
        
    private:
        mutable bool             is_invocated;
        Invocation               func;
        std::tuple<Arguments...> arguments;
    };

    template<typename Invocation, typename... Arguments>
    constexpr auto currying(Invocation&& callable, Arguments&&... args) noexcept
    {
        return 
            mylib::curried_function{
                std::forward<Invocation>(callable), std::forward<Arguments>(args)...
            };
    }
}
