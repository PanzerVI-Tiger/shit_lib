module;

#ifdef __INTELLISENSE__

#include <tuple>
#include <string>
#include <iostream>

#endif

export module mylib.aggregate;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.string;
import mylib.utility;
import mylib.type_traits;
import mylib.stream_output;


export namespace mylib {

    // maybe will be used??
    struct cast_any {
        template<typename Type>
        operator Type& () const {
            mylib::remove_reference_t<Type> result{};

            return result;
        }
    };
    
    template<typename Type, size_t argumentsSize>
    struct can_n_arguments_construct : false_type {
        static_assert(mylib::always_false<Type>, "can't handle so many arguments!");
    };

    template<typename Type>
    struct can_n_arguments_construct<Type, 0> :
        bool_constant<requires{ Type{}; }>
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 1> :
        bool_constant<requires{ Type{ {} }; }>
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 2> :
        bool_constant<requires{ Type{ {}, {} }; }>
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 3> :
        bool_constant<requires{ Type{ {}, {}, {} }; }>
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 4> :
        bool_constant<requires{ Type{ {}, {}, {}, {} }; }>
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 5> :
        bool_constant<requires{ Type{ {}, {}, {}, {}, {} }; }>
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 6> :
        bool_constant<requires{ Type{ {}, {}, {}, {}, {}, {} }; }> 
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 7> :
        bool_constant<requires{ Type{ {}, {}, {}, {}, {}, {}, {} }; }> 
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 8> :
        bool_constant<requires{ Type{ {}, {}, {}, {}, {}, {}, {}, {} }; }> 
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 9> :
        bool_constant<requires{ Type{ {}, {}, {}, {}, {}, {}, {}, {}, {} }; }> 
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 10> :
        bool_constant<requires{ Type{ {}, {}, {}, {}, {}, {}, {}, {}, {}, {} }; }> 
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 11> :
        bool_constant<requires{ Type{ {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {} }; }> 
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 12> :
        bool_constant<requires{ Type{ {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {} }; }> 
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 13> :
        bool_constant<requires{ Type{ {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {} }; }> 
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 14> :
        bool_constant<requires{ Type{ {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {} }; }> 
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 15> :
        bool_constant<requires{ Type{ {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {} }; }> 
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 16> :
        bool_constant<requires{ Type{ {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {} }; }> 
    {};

    template<typename Type>
    struct can_n_arguments_construct<Type, 17> :
        bool_constant<requires{ Type{ {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {} }; }> 
    {};
    
    template<typename Type, size_t argumentsSize>
    inline constexpr bool can_n_arguments_construct_v = 
        mylib::can_n_arguments_construct<Type, argumentsSize>::value;

    template<typename Type, size_t memberSize>
    concept have_n_member_objects = 
       !mylib::can_n_arguments_construct_v<Type, memberSize + 1> && 
        mylib::can_n_arguments_construct_v<Type, memberSize>;

    template<typename Type>
    constexpr size_t member_objects_size() noexcept {
        if constexpr (mylib::have_n_member_objects<Type, 0>) {
            return 0;
        } else if constexpr (mylib::have_n_member_objects<Type, 1>) {
            return 1;
        } else if constexpr (mylib::have_n_member_objects<Type, 2>) {
            return 2;
        } else if constexpr (mylib::have_n_member_objects<Type, 3>) {
            return 3;
        } else if constexpr (mylib::have_n_member_objects<Type, 4>) {
            return 4;
        } else if constexpr (mylib::have_n_member_objects<Type, 5>) {
            return 5;
        } else if constexpr (mylib::have_n_member_objects<Type, 6>) {
            return 6;
        } else if constexpr (mylib::have_n_member_objects<Type, 7>) {
            return 7;
        } else if constexpr (mylib::have_n_member_objects<Type, 8>) {
            return 8;
        } else if constexpr (mylib::have_n_member_objects<Type, 9>) {
            return 9;
        } else if constexpr (mylib::have_n_member_objects<Type, 10>) {
            return 10;
        } else if constexpr (mylib::have_n_member_objects<Type, 11>) {
            return 11;
        } else if constexpr (mylib::have_n_member_objects<Type, 12>) {
            return 12;
        } else if constexpr (mylib::have_n_member_objects<Type, 13>) {
            return 13;
        } else if constexpr (mylib::have_n_member_objects<Type, 14>) {
            return 14;
        } else if constexpr (mylib::have_n_member_objects<Type, 15>) {
            return 15;
        } else if constexpr (mylib::have_n_member_objects<Type, 16>) {
            return 16;
        } else {
            static_assert(mylib::always_false<Type>, "can't handle so many members!");
        }
    }

    template<typename Type>
    constexpr auto member_objects(const Type& object) noexcept
    {
        if constexpr (mylib::have_n_member_objects<Type, 0>) {
            return std::make_tuple();
        } else if constexpr (mylib::have_n_member_objects<Type, 1>) {
            auto [a] = object;
            std::tuple<decltype(a)> result;
            assignment(std::get<0>(result), a);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 2>) {
            auto [a, b] = object;
            std::tuple<decltype(a), decltype(b)> result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 3>) {
            auto [a, b, c] = object;
            std::tuple<decltype(a), decltype(b), decltype(c)> result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 4>) {
            auto [a, b, c, d] = object;
            std::tuple<decltype(a), decltype(b), decltype(c), decltype(d)> result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 5>) {
            auto [a, b, c, d, e] = object;
            std::tuple<decltype(a), decltype(b), decltype(c), decltype(d), decltype(e)> result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            assignment(std::get<4>(result), e);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 6>) {
            auto [a, b, c, d, e, f] = object;
            std::tuple<
                decltype(a), decltype(b), decltype(c), decltype(d), decltype(e), decltype(f)
            > result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            assignment(std::get<4>(result), e);
            assignment(std::get<5>(result), f);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 7>) {
            auto [a, b, c, d, e, f, g] = object;
            std::tuple<
                decltype(a), decltype(b), decltype(c), decltype(d), 
                decltype(e), decltype(f), decltype(g)
            > result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            assignment(std::get<4>(result), e);
            assignment(std::get<5>(result), f);
            assignment(std::get<6>(result), g);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 8>) {
            auto [a, b, c, d, e, f, g, h] = object;
            std::tuple<
                decltype(a), decltype(b), decltype(c), decltype(d), 
                decltype(e), decltype(f), decltype(g), decltype(h)
            > result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            assignment(std::get<4>(result), e);
            assignment(std::get<5>(result), f);
            assignment(std::get<6>(result), g);
            assignment(std::get<7>(result), h);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 9>) {
            auto [a, b, c, d, e, f, g, h, i] = object;
            std::tuple<
                decltype(a), decltype(b), decltype(c), decltype(d), decltype(e), 
                decltype(f), decltype(g), decltype(h), decltype(i)
            > result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            assignment(std::get<4>(result), e);
            assignment(std::get<5>(result), f);
            assignment(std::get<6>(result), g);
            assignment(std::get<7>(result), h);
            assignment(std::get<8>(result), i);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 10>) {
            auto [a, b, c, d, e, f, g, h, i, j] = object;
            std::tuple<
                decltype(a), decltype(b), decltype(c), decltype(d), decltype(e), 
                decltype(f), decltype(g), decltype(h), decltype(i), decltype(j)
            > result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            assignment(std::get<4>(result), e);
            assignment(std::get<5>(result), f);
            assignment(std::get<6>(result), g);
            assignment(std::get<7>(result), h);
            assignment(std::get<8>(result), i);
            assignment(std::get<9>(result), j);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 11>) {
            auto [a, b, c, d, e, f, g, h, i, j, k] = object;
            std::tuple<
                decltype(a), decltype(b), decltype(c), decltype(d), decltype(e), decltype(f), 
                decltype(g), decltype(h), decltype(i), decltype(j), decltype(k)
            > result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            assignment(std::get<4>(result), e);
            assignment(std::get<5>(result), f);
            assignment(std::get<6>(result), g);
            assignment(std::get<7>(result), h);
            assignment(std::get<8>(result), i);
            assignment(std::get<9>(result), j);
            assignment(std::get<10>(result), k);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 12>) {
            auto [a, b, c, d, e, f, g, h, i, j, k, l] = object;
            std::tuple<
                decltype(a), decltype(b), decltype(c), decltype(d), decltype(e), decltype(f), 
                decltype(g), decltype(h), decltype(i), decltype(j), decltype(k), decltype(l)
            > result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            assignment(std::get<4>(result), e);
            assignment(std::get<5>(result), f);
            assignment(std::get<6>(result), g);
            assignment(std::get<7>(result), h);
            assignment(std::get<8>(result), i);
            assignment(std::get<9>(result), j);
            assignment(std::get<10>(result), k);
            assignment(std::get<11>(result), l);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 13>) {
            auto [a, b, c, d, e, f, g, h, i, j, k, l, m] = object;
            std::tuple<
                decltype(a), decltype(b), decltype(c), decltype(d), decltype(e), 
                decltype(f), decltype(g), decltype(h), decltype(i), decltype(j), 
                decltype(k), decltype(l), decltype(m)
            > result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            assignment(std::get<4>(result), e);
            assignment(std::get<5>(result), f);
            assignment(std::get<6>(result), g);
            assignment(std::get<7>(result), h);
            assignment(std::get<8>(result), i);
            assignment(std::get<9>(result), j);
            assignment(std::get<10>(result), k);
            assignment(std::get<11>(result), l);
            assignment(std::get<12>(result), m);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 14>) {
            auto [a, b, c, d, e, f, g, h, i, j, k, l, m, n] = object;
            std::tuple<
                decltype(a), decltype(b), decltype(c), decltype(d), decltype(e), 
                decltype(f), decltype(g), decltype(h), decltype(i), decltype(j), 
                decltype(k), decltype(l), decltype(m), decltype(n)
            > result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            assignment(std::get<4>(result), e);
            assignment(std::get<5>(result), f);
            assignment(std::get<6>(result), g);
            assignment(std::get<7>(result), h);
            assignment(std::get<8>(result), i);
            assignment(std::get<9>(result), j);
            assignment(std::get<10>(result), k);
            assignment(std::get<11>(result), l);
            assignment(std::get<12>(result), m);
            assignment(std::get<13>(result), n);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 15>) {
            auto [a, b, c, d, e, f, g, h, i, j, k, l, m, n, o] = object;
            std::tuple<
                decltype(a), decltype(b), decltype(c), decltype(d), decltype(e), 
                decltype(f), decltype(g), decltype(h), decltype(i), decltype(j), 
                decltype(k), decltype(l), decltype(m), decltype(n), decltype(o)
            > result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            assignment(std::get<4>(result), e);
            assignment(std::get<5>(result), f);
            assignment(std::get<6>(result), g);
            assignment(std::get<7>(result), h);
            assignment(std::get<8>(result), i);
            assignment(std::get<9>(result), j);
            assignment(std::get<10>(result), k);
            assignment(std::get<11>(result), l);
            assignment(std::get<12>(result), m);
            assignment(std::get<13>(result), n);
            assignment(std::get<14>(result), o);
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 16>) {
            auto [a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p] = object;
            std::tuple<
                decltype(a), decltype(b), decltype(c), decltype(d), decltype(e), decltype(f), 
                decltype(g), decltype(h), decltype(i), decltype(j), decltype(k), decltype(l), 
                decltype(m), decltype(n), decltype(o), decltype(p)
            > result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            assignment(std::get<4>(result), e);
            assignment(std::get<5>(result), f);
            assignment(std::get<6>(result), g);
            assignment(std::get<7>(result), h);
            assignment(std::get<8>(result), i);
            assignment(std::get<9>(result), j);
            assignment(std::get<10>(result), k);
            assignment(std::get<11>(result), l);
            assignment(std::get<12>(result), m);
            assignment(std::get<13>(result), n);
            assignment(std::get<14>(result), o);
            assignment(std::get<15>(result), p);
            return result;
        } else {
            static_assert(mylib::always_false<Type>, "can't handle so many members!");
        }
    }

    template<typename Type>
    constexpr auto member_objects_ref(Type& object) noexcept
    {
        if constexpr (mylib::have_n_member_objects<Type, 0>) {
            return std::make_tuple();
        } else if constexpr (mylib::have_n_member_objects<Type, 1>) {
            auto& [a] = object;
            std::tuple<decltype(a)&> result{ a };
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 2>) {
            auto& [a, b] = object;
            std::tuple<decltype(a)&, decltype(b)&> result{ a, b };
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 3>) {
            auto& [a, b, c] = object;
            std::tuple<decltype(a)&, decltype(b)&, decltype(c)&> result{ a, b, c };
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 4>) {
            auto& [a, b, c, d] = object;
            std::tuple<decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&> result{ a, b, c, d };
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 5>) {
            auto& [a, b, c, d, e] = object;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&
            > result{ a, b, c, d, e };
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 6>) {
            auto& [a, b, c, d, e, f] = object;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, decltype(f)&
            > result{ a, b, c, d, e, f };
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 7>) {
            auto& [a, b, c, d, e, f, g] = object;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, 
                decltype(e)&, decltype(f)&, decltype(g)&
            > result{ a, b, c, d, e, f, g };
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 8>) {
            auto& [a, b, c, d, e, f, g, h] = object;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, 
                decltype(e)&, decltype(f)&, decltype(g)&, decltype(h)&
            > result{ a, b, c, d, e, f, g, h };
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 9>) {
            auto& [a, b, c, d, e, f, g, h, i] = object;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, 
                decltype(f)&, decltype(g)&, decltype(h)&, decltype(i)&
            > result{ a, b, c, d, e, f, g, h, i };
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 10>) {
            auto& [a, b, c, d, e, f, g, h, i, j] = object;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, 
                decltype(f)&, decltype(g)&, decltype(h)&, decltype(i)&, decltype(j)&
            > result{ a, b, c, d, e, f, g, h, i, j };
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 11>) {
            auto& [a, b, c, d, e, f, g, h, i, j, k] = object;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, decltype(f)&, 
                decltype(g)&, decltype(h)&, decltype(i)&, decltype(j)&, decltype(k)&
            > result{ a, b, c, d, e, f, g, h, i, j, k };
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 12>) {
            auto& [a, b, c, d, e, f, g, h, i, j, k, l] = object;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, decltype(f)&, 
                decltype(g)&, decltype(h)&, decltype(i)&, decltype(j)&, decltype(k)&, decltype(l)&
            > result{ a, b, c, d, e, f, g, h, i, j, k, l };
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 13>) {
            auto& [a, b, c, d, e, f, g, h, i, j, k, l, m] = object;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, 
                decltype(f)&, decltype(g)&, decltype(h)&, decltype(i)&, decltype(j)&, 
                decltype(k)&, decltype(l)&, decltype(m)&
            > result{ a, b, c, d, e, f, g, h, i, j, k, l, m };
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 14>) {
            auto& [a, b, c, d, e, f, g, h, i, j, k, l, m, n] = object;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, 
                decltype(f)&, decltype(g)&, decltype(h)&, decltype(i)&, decltype(j)&, 
                decltype(k)&, decltype(l)&, decltype(m)&, decltype(n)&
            > result{ a, b, c, d, e, f, g, h, i, j, k, l, m, n };
            return result;
        } else if constexpr (mylib::have_n_member_objects<Type, 15>) {
            auto& [a, b, c, d, e, f, g, h, i, j, k, l, m, n, o] = object;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, 
                decltype(f)&, decltype(g)&, decltype(h)&, decltype(i)&, decltype(j)&, 
                decltype(k)&, decltype(l)&, decltype(m)&, decltype(n)&, decltype(o)&
            > result{ a, b, c, d, e, f, g, h, i, j, k, l, m, n, o };
        } else if constexpr (mylib::have_n_member_objects<Type, 16>) {
            auto& [a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p] = object;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, decltype(f)&, 
                decltype(g)&, decltype(h)&, decltype(i)&, decltype(j)&, decltype(k)&, decltype(l)&, 
                decltype(m)&, decltype(n)&, decltype(o)&, decltype(p)&
            > result{ a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p };
        } else {
            static_assert(mylib::always_false<Type>, "can't handle so many members!");
        }
    }

    template<size_t index, typename Type>
    constexpr decltype(auto) get(Type& object) noexcept {
        return std::get<index>(mylib::member_objects_ref(object));
    }

    template<size_t index, typename Type, size_t arraySize>
    constexpr decltype(auto) get(Type (&object)[arraySize]) noexcept {
        return arraySize[index];
    }

    template<typename Type>
    struct aggregate_traits {
        using type  = Type;
        using types = decltype(mylib::member_objects(mylib::declval<Type>()));

        static constexpr size_t size() noexcept {
            return membersSize;
        }

        static constexpr auto member_objects(const Type& object) noexcept {
            return mylib::member_objects(object);
        }

        static constexpr auto member_objects_ref(Type& object) noexcept {
            return mylib::member_objects_ref(object);
        }

        static constexpr std::string types_string() noexcept {
            using namespace std::string_literals;

            std::string name{ "" };
            [&name] <typename... Types> (
                std::tuple<Types...>
            ) constexpr noexcept {
                bool isStart = true;
                (..., (name += (isStart ? isStart = false, ""s : ", "s) + typeid(Types).name()));
            }(member_objects({}));

            return name;
        }

        template<size_t index>
        static auto get(Type& object) noexcept {
            return mylib::get<index>(object);
        }

        static constexpr size_t membersSize = mylib::member_objects_size<Type>();
    };

    template<size_t count, typename Type, typename... Types>
    struct make_n_same_type_tuple_impl {
        using type =
            typename mylib::make_n_same_type_tuple_impl<
                count - 1, Type, Type, Types...
            >::type;
    };

    template<typename Type, typename... Types>
    struct make_n_same_type_tuple_impl<0, Type, Types...> {
        using type = std::tuple<Types...>;
    };

    template<size_t count, typename Type>
    struct make_n_same_type_tuple {
        using type = typename mylib::make_n_same_type_tuple_impl<count, Type>::type;
    };

    template<size_t count, typename Type>
    using make_n_same_type_tuple_t = typename mylib::make_n_same_type_tuple<count, Type>::type;
    
    template<typename Type, size_t arraySize>
    struct aggregate_traits<Type[arraySize]> {
        using type  = Type[arraySize];
        using types = mylib::make_n_same_type_tuple_t<arraySize, Type>;

        static size_t size() noexcept {
            return arraySize;
        }

        static constexpr std::string types_string() noexcept {
            std::string name;
            std::string type_name{ typeid(Type).name() };
            
            for (size_t i = 0; i != arraySize; ++i) {
                name += (i == 0 ? "" : ", ") + type_name;
            }

            return name;
        }

        static constexpr auto member_objects(const Type (&object)[arraySize]) noexcept {
            return
                [&object]<size_t... indices> (
                    std::index_sequence<indices...>
                ) constexpr noexcept {
                    return types{ object[indices]... };
                }(std::make_index_sequence<arraySize>{});
        }

        static constexpr auto member_objects_ref(Type (&object)[arraySize]) noexcept {
            return
                [&object]<size_t... indices> (std::index_sequence<indices...>) constexpr noexcept {
                    return mylib::make_n_same_type_tuple_t<arraySize, Type&>{ object[indices]... };
                }(std::make_index_sequence<arraySize>{});
        }

        template<size_t index>
        static auto get(Type& object) noexcept {
            return mylib::get<index>(object);
        }

        static constexpr size_t membersSize = arraySize;
    };

    template<typename Type>
    constexpr std::string member_objects_types_string() noexcept {
        return mylib::aggregate_traits<Type>::member_objects_types_string();
    }

    template<typename Type>
    constexpr std::string aggregate_to_string(const Type& object) noexcept {
        using traits = mylib::aggregate_traits<Type>;

#       ifndef __INTELLISENSE__
        
        return 
            std::string{ typeid(Type).name() }                                            + " {\n"
            "    size: "                    + to_string(traits::size())                   + ",\n"
            "    member objects' types: <"  + traits::types_string()                      + ">,\n"
            "    member objects: "          + to_string(traits::member_objects(object))   + "\n"
            "}";
#       endif
    }

    namespace unittest {
        
        template<typename Void = void>
        constexpr bool assert_test_aggregate() noexcept {
            // TODO: static test
            struct A {
                int    a;
                double b;
                char   c;
            } a{ 1, 2.0, 'F'};

            struct B {
                int         a;
                std::string b;
                double&     c;
                int         d[4];
            } b{ 1, "hello", a.b, { 1, 2, 3, 4 } };

            using traitA = mylib::aggregate_traits<A>;
            using traitB = mylib::aggregate_traits<B>;
            
            if constexpr (
                !mylib::is_same_v<typename traitA::types, std::tuple<int, double, char>>/* &&
                !mylib::is_same_v<typename traitB::types, std::tuple<int, std::string, double&, int[4]>>*/
            ) {
                static_assert(mylib::always_false<Void>, "member objects' type are not correct!");
            }
            
            return true;
        }
        
        static_assert(mylib::unittest::assert_test_aggregate(), "aggregate have bug!");

        void print_test_aggregate() {
            using mylib::operator <<;
        
            // test class A
            struct A {
                int         nmb;
                std::string cnm;
            } a{ 1, "fuck" };

            // test class B
            struct B {
                int sb;
                int gb[4];
                int bb;
            } b{ 1, { 1, 2, 3, 4 }, 8 };

            // test array
            int arr[]{ 1, 2, 3, 4, 5 };

            // print all
            std::cout << mylib::aggregate_to_string(a)
                      << "\n\n"
                      << mylib::aggregate_to_string(b)
                      << "\n\n"
                      << mylib::aggregate_to_string(arr)
                      << "\n\n"
                      << mylib::get<1>(b);
        }
    }
}
