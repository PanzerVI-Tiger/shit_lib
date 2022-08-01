export module mylib.aggregate;

import std.core;
import mylib.utility;
import mylib.type_traits;


export namespace mylib::inline aggregate {

    template<typename Type, size_t argumentsSize>
    struct can_n_arguments_construct : false_type {
        static_assert(always_false<Type>, "can't handle so many arguments!");
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
        bool_constant<requires{ Type{ {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {} }; }> {
    };
    
    template<typename Type, size_t argumentsSize>
    inline constexpr bool can_n_arguments_construct_v = can_n_arguments_construct<Type, argumentsSize>::value;

    template<typename Type, size_t memberSize>
    concept have_n_member_objects = 
        !can_n_arguments_construct_v<Type, memberSize + 1> && can_n_arguments_construct_v<Type, memberSize>;

    namespace detail {
        template<typename Type>
        constexpr size_t member_objects_size() noexcept
        {
            if constexpr (have_n_member_objects<Type, 0>) {
                return 0;
            } else if constexpr (have_n_member_objects<Type, 1>) {
                return 1;
            } else if constexpr (have_n_member_objects<Type, 2>) {
                return 2;
            } else if constexpr (have_n_member_objects<Type, 3>) {
                return 3;
            } else if constexpr (have_n_member_objects<Type, 4>) {
                return 4;
            } else if constexpr (have_n_member_objects<Type, 5>) {
                return 5;
            } else if constexpr (have_n_member_objects<Type, 6>) {
                return 6;
            } else if constexpr (have_n_member_objects<Type, 7>) {
                return 7;
            } else if constexpr (have_n_member_objects<Type, 8>) {
                return 8;
            } else if constexpr (have_n_member_objects<Type, 9>) {
                return 9;
            } else if constexpr (have_n_member_objects<Type, 10>) {
                return 10;
            } else if constexpr (have_n_member_objects<Type, 11>) {
                return 11;
            } else if constexpr (have_n_member_objects<Type, 12>) {
                return 12;
            } else if constexpr (have_n_member_objects<Type, 13>) {
                return 13;
            } else if constexpr (have_n_member_objects<Type, 14>) {
                return 14;
            } else if constexpr (have_n_member_objects<Type, 15>) {
                return 15;
            } else if constexpr (have_n_member_objects<Type, 16>) {
                return 16;
            } else {
                static_assert(always_false<Type>, "can't handle so many members!");
            }
        }
    }

    template<typename Type>
    constexpr auto member_objects(const Type& type) noexcept
    {
        if constexpr (have_n_member_objects<Type, 0>) {
            return std::make_tuple();
        } else if constexpr (have_n_member_objects<Type, 1>) {
            auto [a] = type;
            std::tuple<decltype(a)> result;
            assignment(std::get<0>(result), a);
            return result;
        } else if constexpr (have_n_member_objects<Type, 2>) {
            auto [a, b] = type;
            std::tuple<decltype(a), decltype(b)> result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            return result;
        } else if constexpr (have_n_member_objects<Type, 3>) {
            auto [a, b, c] = type;
            std::tuple<decltype(a), decltype(b), decltype(c)> result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            return result;
        } else if constexpr (have_n_member_objects<Type, 4>) {
            auto [a, b, c, d] = type;
            std::tuple<decltype(a), decltype(b), decltype(c), decltype(d)> result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            return result;
        } else if constexpr (have_n_member_objects<Type, 5>) {
            auto [a, b, c, d, e] = type;
            std::tuple<decltype(a), decltype(b), decltype(c), decltype(d), decltype(e)> result;
            assignment(std::get<0>(result), a);
            assignment(std::get<1>(result), b);
            assignment(std::get<2>(result), c);
            assignment(std::get<3>(result), d);
            assignment(std::get<4>(result), e);
            return result;
        } else if constexpr (have_n_member_objects<Type, 6>) {
            auto [a, b, c, d, e, f] = type;
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
        } else if constexpr (have_n_member_objects<Type, 7>) {
            auto [a, b, c, d, e, f, g] = type;
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
        } else if constexpr (have_n_member_objects<Type, 8>) {
            auto [a, b, c, d, e, f, g, h] = type;
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
        } else if constexpr (have_n_member_objects<Type, 9>) {
            auto [a, b, c, d, e, f, g, h, i] = type;
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
        } else if constexpr (have_n_member_objects<Type, 10>) {
            auto [a, b, c, d, e, f, g, h, i, j] = type;
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
        } else if constexpr (have_n_member_objects<Type, 11>) {
            auto [a, b, c, d, e, f, g, h, i, j, k] = type;
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
        } else if constexpr (have_n_member_objects<Type, 12>) {
            auto [a, b, c, d, e, f, g, h, i, j, k, l] = type;
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
        } else if constexpr (have_n_member_objects<Type, 13>) {
            auto [a, b, c, d, e, f, g, h, i, j, k, l, m] = type;
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
        } else if constexpr (have_n_member_objects<Type, 14>) {
            auto [a, b, c, d, e, f, g, h, i, j, k, l, m, n] = type;
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
        } else if constexpr (have_n_member_objects<Type, 15>) {
            auto [a, b, c, d, e, f, g, h, i, j, k, l, m, n, o] = type;
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
        } else if constexpr (have_n_member_objects<Type, 16>) {
            auto [a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p] = type;
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
            static_assert(always_false<Type>, "can't handle so many members!");
        }
    }

    template<typename Type>
    constexpr auto member_objects_ref(Type& type) noexcept
    {
        if constexpr (have_n_member_objects<Type, 0>) {
            return std::make_tuple();
        } else if constexpr (have_n_member_objects<Type, 1>) {
            auto& [a] = type;
            std::tuple<decltype(a)&> result{ a };
            return result;
        } else if constexpr (have_n_member_objects<Type, 2>) {
            auto& [a, b] = type;
            std::tuple<decltype(a)&, decltype(b)&> result{ a, b };
            return result;
        } else if constexpr (have_n_member_objects<Type, 3>) {
            auto& [a, b, c] = type;
            std::tuple<decltype(a)&, decltype(b)&, decltype(c)&> result{a, b, c};
            return result;
        } else if constexpr (have_n_member_objects<Type, 4>) {
            auto& [a, b, c, d] = type;
            std::tuple<decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&> result{a, b, c, d};
            return result;
        } else if constexpr (have_n_member_objects<Type, 5>) {
            auto& [a, b, c, d, e] = type;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&
            > result{a, b, c, d, e};
            return result;
        } else if constexpr (have_n_member_objects<Type, 6>) {
            auto& [a, b, c, d, e, f] = type;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, decltype(f)&
            > result{a, b, c, d, e, f};
            return result;
        } else if constexpr (have_n_member_objects<Type, 7>) {
            auto& [a, b, c, d, e, f, g] = type;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, 
                decltype(e)&, decltype(f)&, decltype(g)&
            > result{a, b, c, d, e, f, g};
            return result;
        } else if constexpr (have_n_member_objects<Type, 8>) {
            auto& [a, b, c, d, e, f, g, h] = type;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, 
                decltype(e)&, decltype(f)&, decltype(g)&, decltype(h)&
            > result{a, b, c, d, e, f, g, h};
            return result;
        } else if constexpr (have_n_member_objects<Type, 9>) {
            auto& [a, b, c, d, e, f, g, h, i] = type;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, 
                decltype(f)&, decltype(g)&, decltype(h)&, decltype(i)&
            > result{ a, b, c, d, e, f, g, h, i };
            return result;
        } else if constexpr (have_n_member_objects<Type, 10>) {
            auto& [a, b, c, d, e, f, g, h, i, j] = type;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, 
                decltype(f)&, decltype(g)&, decltype(h)&, decltype(i)&, decltype(j)&
            > result{ a, b, c, d, e, f, g, h, i, j };
            return result;
        } else if constexpr (have_n_member_objects<Type, 11>) {
            auto& [a, b, c, d, e, f, g, h, i, j, k] = type;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, decltype(f)&, 
                decltype(g)&, decltype(h)&, decltype(i)&, decltype(j)&, decltype(k)&
            > result{ a, b, c, d, e, f, g, h, i, j, k };
            return result;
        } else if constexpr (have_n_member_objects<Type, 12>) {
            auto& [a, b, c, d, e, f, g, h, i, j, k, l] = type;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, decltype(f)&, 
                decltype(g)&, decltype(h)&, decltype(i)&, decltype(j)&, decltype(k)&, decltype(l)&
            > result{ a, b, c, d, e, f, g, h, i, j, k, l };
            return result;
        } else if constexpr (have_n_member_objects<Type, 13>) {
            auto& [a, b, c, d, e, f, g, h, i, j, k, l, m] = type;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, 
                decltype(f)&, decltype(g)&, decltype(h)&, decltype(i)&, decltype(j)&, 
                decltype(k)&, decltype(l)&, decltype(m)&
            > result{ a, b, c, d, e, f, g, h, i, j, k, l, m };
            return result;
        } else if constexpr (have_n_member_objects<Type, 14>) {
            auto& [a, b, c, d, e, f, g, h, i, j, k, l, m, n] = type;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, 
                decltype(f)&, decltype(g)&, decltype(h)&, decltype(i)&, decltype(j)&, 
                decltype(k)&, decltype(l)&, decltype(m)&, decltype(n)&
            > result{ a, b, c, d, e, f, g, h, i, j, k, l, m, n };
            return result;
        } else if constexpr (have_n_member_objects<Type, 15>) {
            auto& [a, b, c, d, e, f, g, h, i, j, k, l, m, n, o] = type;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, 
                decltype(f)&, decltype(g)&, decltype(h)&, decltype(i)&, decltype(j)&, 
                decltype(k)&, decltype(l)&, decltype(m)&, decltype(n)&, decltype(o)&
            > result{ a, b, c, d, e, f, g, h, i, j, k, l, m, n, o };
        } else if constexpr (have_n_member_objects<Type, 16>) {
            auto& [a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p] = type;
            std::tuple<
                decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&, decltype(e)&, decltype(f)&, 
                decltype(g)&, decltype(h)&, decltype(i)&, decltype(j)&, decltype(k)&, decltype(l)&, 
                decltype(m)&, decltype(n)&, decltype(o)&, decltype(p)&
            > result{ a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p };
        } else {
            static_assert(always_false<Type>, "can't handle so many members!");
        }
    }

    template<size_t index, typename Type>
    constexpr decltype(auto) get(Type& type) noexcept {
        return std::get<index>(member_objects_ref(type));
    }

    template<size_t index, typename Type, size_t arraySize>
    constexpr decltype(auto) get(Type (&type)[arraySize]) noexcept {
        return arraySize[index];
    }

    template<typename Type>
    struct aggregate_traits {
        using type  = Type;
        using types = decltype(member_objects(mylib::declval<Type>()));

        static constexpr size_t size() noexcept {
            return membersSize;
        }

        static constexpr auto member_objects(const Type& type) noexcept {
            return mylib::member_objects(type);
        }

        static constexpr auto member_objects_ref(Type& type) noexcept {
            return mylib::member_objects_ref(type);
        }

        static constexpr std::string types_string() noexcept {
            using namespace std::string_literals;

            std::string name{ "" };
            [&name] <typename... Types> (
                std::tuple<Types...> tuple
            ) constexpr noexcept {
                bool isStart = true;
                (..., (name += (isStart ? isStart = false, ""s : ", "s) + typeid(Types).name()));
            }(member_objects({}));

            return name;
        }

        template<size_t index>
        static auto get(Type& type) noexcept {
            return mylib::get<index>(type);
        }

        inline static constexpr size_t membersSize = detail::member_objects_size<Type>();
    };

    namespace detail {
        template<typename Type, size_t size>
        constexpr auto make_n_same_type_tuple() noexcept {
            return 
                []<size_t index, size_t... indices, typename... Types> (
                    this auto self, std::tuple<Types...> tuple, std::index_sequence<index, indices...> sequence
                ) constexpr noexcept {               
                    if constexpr (sizeof...(indices) == 0) {
                        return std::tuple<Types..., Type>{};
                    } else {
                        return self(std::tuple<Types..., Type>{}, std::index_sequence<indices...>{});
                    }
                }(std::make_tuple(), std::make_index_sequence<size>{});
        }
    }
    
    template<typename Type, size_t arraySize>
    struct aggregate_traits<Type[arraySize]> {
        using type  = Type[arraySize];
        using types = decltype(detail::make_n_same_type_tuple<Type, arraySize>());

        static size_t size() noexcept {
            return arraySize;
        }

        static constexpr std::string types_string() noexcept {
            std::string name{ "" };
            std::string type_name{ typeid(Type).name() };
            
            for (size_t i = 0; i != arraySize; ++i) {
                name += (i == 0 ? "" : ", ") + type_name;
            }

            return name;
        }

        static constexpr auto member_objects(const Type (&object)[arraySize]) noexcept {
            return
                [&object]<size_t... indices> (std::index_sequence<indices...> sequence) constexpr noexcept {
                    return types{ object[indices]... };
                }(std::make_index_sequence<arraySize>{});
        }

        static constexpr auto member_objects_ref(Type (&object)[arraySize]) noexcept {
            return
                [&object]<size_t... indices> (std::index_sequence<indices...> sequence) constexpr noexcept {
                    return decltype(detail::make_n_same_type_tuple<Type&>()){ object[indices]... };
                }(std::make_index_sequence<arraySize>{});
        }

        template<size_t index>
        static auto get(Type& type) noexcept {
            return mylib::get<index>(type);
        }

        inline static constexpr size_t membersSize = arraySize;
    };

    template<typename Type>
    constexpr std::string member_objects_types_string() noexcept {
        return aggregate_traits<Type>::member_objects_types_string();
    }
}
