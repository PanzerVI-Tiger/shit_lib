module;

#ifdef __INTELLISENSE__

#include <utility>

#endif

export module mylib.tuple;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.utility;
import mylib.type_list;
import mylib.type_traits;

export namespace mylib {
    
    template<
        size_t   index,
        typename Type
    > struct tuple_data
    {
    protected:
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
    protected:
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
    struct tuple_impl
    {};

    template<size_t... indices, typename... Types>
    struct tuple_impl<std::index_sequence<indices...>, Types...> :
        tuple_data<indices, Types>...
    {
        template<size_t index>
        using base_type = tuple_data<index, mylib::at_pack_t<index, Types...>>;
    
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
    };

    template<typename... Types>
    struct tuple : 
        protected tuple_impl<std::index_sequence_for<Types...>, Types...>
    {
        using base_type = tuple_impl<std::index_sequence_for<Types...>, Types...>;

        using base_type::base_type;
        using base_type::get;
    };
}
