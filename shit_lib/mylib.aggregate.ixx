export module mylib.aggregate;

import std.core;
import mylib.utility;


export namespace mylib::inline aggregate {

    template<typename Type, size_t argumentsSize>
    inline constexpr bool can_n_argument_construct = false;

    template<typename Type>
    inline constexpr bool can_n_argument_construct<Type, 0> = requires{ Type{}; };

    template<typename Type>
    inline constexpr bool can_n_argument_construct<Type, 1> = requires{ Type{ {} }; };

    template<typename Type>
    inline constexpr bool can_n_argument_construct<Type, 2> = requires{ Type{ {}, {} }; };

    template<typename Type>
    inline constexpr bool can_n_argument_construct<Type, 3> = requires{ Type{ {}, {}, {} }; };

    template<typename Type>
    inline constexpr bool can_n_argument_construct<Type, 4> = requires{ Type{ {}, {}, {}, {} }; };

    template<typename Type, size_t memberSize>
    concept has_n_member = !can_n_argument_construct<Type, memberSize + 1> && can_n_argument_construct<Type, memberSize>;

    template<typename Type>
    constexpr size_t members_size() noexcept
    {
        if constexpr (has_n_member<Type, 0>) {
            return 0;
        } else if constexpr (has_n_member<Type, 1>) {
            return 1;
        } else if constexpr (has_n_member<Type, 2>) {
            return 2;
        } else if constexpr (has_n_member<Type, 3>) {
            return 3;
        } else if constexpr (has_n_member<Type, 4>) {
            return 4;
        } else {
            return 0;
        }
    }

    template<typename Type>
    constexpr auto members_tuple(const Type& type) noexcept
    {
        if constexpr (has_n_member<Type, 0>) {
            return std::make_tuple();
        } else if constexpr (has_n_member<Type, 1>) {
            auto [a] = type;
            std::tuple<decltype(a)> result;
            assignment(get<0>(result), a);
            return result;
        } else if constexpr (has_n_member<Type, 2>) {
            auto [a, b] = type;
            std::tuple<decltype(a), decltype(b)> result;
            assignment(get<0>(result), a);
            assignment(get<1>(result), b);
            return result;
        } else if constexpr (has_n_member<Type, 3>) {
            auto [a, b, c] = type;
            std::tuple<decltype(a), decltype(b), decltype(c)> result;
            assignment(get<0>(result), a);
            assignment(get<1>(result), b);
            assignment(get<2>(result), c);
            return result;
        } else if constexpr (has_n_member<Type, 4>) {
            auto [a, b, c, d] = type;
            std::tuple<decltype(a), decltype(b), decltype(c), decltype(d)> result;
            assignment(get<0>(result), a);
            assignment(get<1>(result), b);
            assignment(get<2>(result), c);
            assignment(get<3>(result), d);
            return result;
        } else {
            return std::make_tuple();
        }
    }

    template<typename Type>
    constexpr auto members_ref_tuple(Type& type) noexcept
    {
        if constexpr (has_n_member<Type, 0>) {
            return std::make_tuple();
        } else if constexpr (has_n_member<Type, 1>) {
            auto& [a] = type;
            std::tuple<decltype(a)&> result{ a };
            return result;
        } else if constexpr (has_n_member<Type, 2>) {
            auto& [a, b] = type;
            std::tuple<decltype(a)&, decltype(b)&> result{ a, b };
            return result;
        } else if constexpr (has_n_member<Type, 3>) {
            auto& [a, b, c] = type;
            std::tuple<decltype(a)&, decltype(b)&, decltype(c)&> result{a, b, c};
            return result;
        } else if constexpr (has_n_member<Type, 4>) {
            auto& [a, b, c, d] = type;
            std::tuple<decltype(a)&, decltype(b)&, decltype(c)&, decltype(d)&> result{a, b, c, d};
            return result;
        } else {
            return std::make_tuple();
        }
    }

    template<typename Type>
    struct aggregate_traits {
        using type = Type;
        using members_type = decltype(members_tuple(mylib::declval<Type>()));

        static size_t members_size() noexcept {
            return membersSize;
        }

        inline static constexpr size_t membersSize = mylib::members_size<Type>();
    };

    template<typename... Types>
    struct aggregate_traits<std::tuple<Types...>> {
        using type = std::tuple<Types...>;
        using members_type = std::tuple<Types...>;

        static size_t members_size() noexcept {
            return sizeof...(Types);
        }

        inline static constexpr size_t membersSize = sizeof...(Types);
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
    
    template<typename Type, size_t size>
    struct aggregate_traits<Type[size]> {
        using type         = Type[size];
        using members_type = decltype(detail::make_n_same_type_tuple<Type, size>());

        static size_t members_size() noexcept {
            return size;
        }

        inline static constexpr size_t membersSize = size;
    };

    template<size_t index, typename Type>
    auto&& get(Type& type) noexcept {
        return std::get<index>(members_ref_tuple(type));
    }
}
