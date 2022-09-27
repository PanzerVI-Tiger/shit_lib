module;

#ifdef __INTELLISENSE__

#include <utility>
#include <variant>
#include <optional>


#endif

export module mylib.tuple;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.utility;
import mylib.type_pack;
import mylib.type_traits;

namespace mylib::detail {
    
    template<typename... Types>
    struct tuple;

    template<
        size_t   index,
        typename Type
    > struct tuple_data {
        using type = Type;
        
        constexpr tuple_data() noexcept
        {}
        
        constexpr tuple_data(Type&& _data) noexcept :
            data{ mylib::forward<Type>(_data) }
        {}
    
        constexpr tuple_data(const Type& _data) noexcept :
            data{ _data }
        {}
    
        constexpr Type& get() noexcept {
            return data;
        }

        constexpr const Type& get() const noexcept {
            return data;
        }
    
        Type data;
    };

    template<
        size_t   index,
        typename Type
    > requires (mylib::is_class_v<Type> && !mylib::is_final_v<Type>)
    struct tuple_data<index, Type> :
        Type
    {
        using type = Type;
        
        constexpr tuple_data() noexcept
        {}

        constexpr tuple_data(Type&& _data) noexcept :
            Type{ mylib::forward<Type>(_data) }
        {}
    
        constexpr tuple_data(const Type& _data) noexcept :
            Type{ _data }
        {}
    
        constexpr Type& get() noexcept {
            return *this;
        }

        constexpr const Type& get() const noexcept {
            return *this;
        }
    };

    template<typename IndexSequence, typename... Types>
    struct tuple_impl;

    template<size_t... indices, typename... Types>
    struct tuple_impl<std::index_sequence<indices...>, Types...> :
        mylib::detail::tuple_data<indices, Types>...
    {
        template<size_t index>
        using base_type =
            mylib::detail::tuple_data<index, mylib::at_pack_t<index, Types...>>;
        
        constexpr tuple_impl() noexcept = default;
        
        constexpr tuple_impl(Types&&... data) noexcept :
            tuple_data<indices, Types>{ mylib::forward<Types>(data) }...
        {}
    
        constexpr tuple_impl(const Types&... data) noexcept :
            tuple_data<indices, Types>{ data }...
        {}
    
        template<size_t index>
        auto&& get() noexcept {
            return base_type<index>::get();
        }

        template<size_t index>
        auto&& get() const noexcept {
            return base_type<index>::get();
        }

        
        constexpr std::optional<std::variant<Types...>> operator [](size_t index) const noexcept {
            if (index >= sizeof...(Types)) {
                return std::nullopt;
            }

            std::optional<std::variant<Types...>> arr[]{
                { 
                    indices == index ?
                    std::optional<std::variant<Types...>>{
                        std::in_place, std::variant<Types...>{ std::in_place_index<indices>, get<indices>() }
                    }
                  : std::nullopt
                }...
            };

            return arr[index];
        }
    };
}

export namespace mylib {
    
    template<typename... Types>
    struct tuple : 
        protected mylib::detail::tuple_impl<std::index_sequence_for<Types...>, Types...>
    {
        using base_type =
            mylib::detail::tuple_impl<std::index_sequence_for<Types...>, Types...>;

        using base_type::base_type;

        using base_type::operator [];
        using base_type::get;

        constexpr tuple(const tuple&) noexcept = default;
        constexpr tuple(tuple&&)      noexcept = default;
    };
}
