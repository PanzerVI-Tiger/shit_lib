module;

//#pragma optimize("", off)
#include <Windows.h>
#include <stdio.h>
#include "mylib_assert.h"
//#include <execution>

export module mylib.main;

import std.core;
import mylib;

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
concept has_n_member = !can_n_argument_construct<Type, memberSize + 1> && can_n_argument_construct <Type, memberSize>;

template<typename Type>
constexpr size_t members_size() noexcept {
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
constexpr auto members_tuple(const Type& type) noexcept {
    if constexpr (has_n_member<Type, 0>) {
        return std::make_tuple();
    } else if constexpr (has_n_member<Type, 1>) {
        auto [a] = type;
        std::tuple<decltype(a)> result;
        memcpy(&get<0>(result), &a, sizeof(decltype(a)));     
        return result;
    } else if constexpr (has_n_member<Type, 2>) {
        auto [a, b] = type;
        std::tuple<decltype(a), decltype(b)> result;
        memcpy(&get<0>(result), &a, sizeof(decltype(a)));
        memcpy(&get<1>(result), &b, sizeof(decltype(b)));
        return result;
    } else if constexpr (has_n_member<Type, 3>) {
        auto [a, b, c] = type;
        std::tuple<decltype(a), decltype(b), decltype(c)> result;
        memcpy(&get<0>(result), &a, sizeof(decltype(a)));
        memcpy(&get<1>(result), &b, sizeof(decltype(b)));
        memcpy(&get<2>(result), &c, sizeof(decltype(c)));
        return result;
    } else if constexpr (has_n_member<Type, 4>) {
        auto [a, b, c, d] = type;
        std::tuple<decltype(a), decltype(b), decltype(c), decltype(d)> result;
        memcpy(&get<0>(result), &a, sizeof(decltype(a)));
        memcpy(&get<1>(result), &b, sizeof(decltype(b)));
        memcpy(&get<2>(result), &c, sizeof(decltype(c)));
        memcpy(&get<3>(result), &d, sizeof(decltype(d)));
        return result;
    } else {
        return std::make_tuple();
    }
}

template<typename Type>
constexpr auto members_ref_tuple(Type& type) noexcept {
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
struct aggregation_traits {
    using type         = Type;
    using members_type = decltype(members_tuple(mylib::declval<Type>()));
    
    static size_t members_size() noexcept {
        return membersSize;
    }
    
    inline static constexpr size_t membersSize = ::members_size<Type>();
};

template<typename Type, size_t index>
auto&& get() noexcept {
    
}

export int main() noexcept
{
    using mylib::operator<<;
    
    struct A {
        int         nmb;
        std::string cnm;
    } a{ 1, "fuck" };

    struct B {
        int sb;
        int gb[4];
        int bb;
    } b{ 1, { 1, 2, 3, 4 }, 8 };
    
    aggregation_traits<A> ta;
    aggregation_traits<B> tb;

    std::cout << members_ref_tuple(a) << ' ' << members_ref_tuple(b);
    
	return 0;
}
