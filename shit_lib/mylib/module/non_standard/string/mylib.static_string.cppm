module;

#ifdef __INTELLISENSE__

#include <string>
#include <compare>

#endif

#include "macro_meta.hpp"

export module mylib.static_string;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.algorithm;
import mylib.type_traits;
import mylib.char_sequence;
import mylib.string_literal;
import mylib.templates_utility;


export namespace mylib {
    
    template<
        typename CharType,
        size_t   maxStringSize,
        typename CharTraits = std::char_traits<CharType>
    > struct basic_static_string {

        using traits_type     = std::char_traits<CharType>;
        using value_type      = CharType;
        using size_type       = size_t;
        using difference_type = ptrdiff_t;
        using reference       = CharType&;
        using const_reference = const CharType&;
        using pointer         = CharType*;
        using const_pointer   = const CharType*;
        
        constexpr basic_static_string() : 
            stringSize{}, charArray{}
        {}

        // copy
        template<size_t rightSize>
        constexpr basic_static_string(
            const basic_static_string<CharType, rightSize, CharTraits>& other
        ) : stringSize{ std::min(maxStringSize, other.stringSize) }, charArray{} {
            traits_type::copy(charArray, other.charArray, stringSize);
        }
        
        template<size_t size>
        constexpr basic_static_string(const CharType(&str)[size]) noexcept :
            stringSize{ maxStringSize }, charArray{} 
        {
            traits_type::copy(charArray, str, stringSize);
        };

        template<CharType... chars>
        constexpr basic_static_string(mylib::char_sequence<CharType, chars...>) noexcept :
            stringSize{ std::min(maxStringSize - 1, sizeof...(chars)) }, charArray{ chars... }
        {};
        
        constexpr basic_static_string(const CharType* str) noexcept :
            stringSize{ std::min(traits_type::length(str), maxStringSize) }, charArray{} 
        {           
            traits_type::copy(charArray, str, stringSize);
        };

        constexpr basic_static_string(mylib::basic_string_literal<CharType> str) noexcept :
            stringSize{ std::min(str.size(), maxStringSize) }, charArray{} 
        {
            traits_type::copy(charArray, str.data(), stringSize);
        };

        template<size_t rightSize>
        constexpr basic_static_string operator =(
            const basic_static_string<CharType, rightSize, CharTraits>& right
        ) noexcept {
            
            stringSize = std::min(maxStringSize, right.stringSize);
            traits_type::copy(charArray, right.charArray, stringSize);
            
            return *this;
        }

        template<size_t rightSize>
        constexpr bool operator ==(
            const basic_static_string<CharType, rightSize, CharTraits>& right
        ) const noexcept {
            return 
                length() == right.length() &&
                traits_type::compare(
                    c_str(), right.c_str(), std::min(size(), right.size())
                ) == 0;
        }

        template<size_t rightSize>
        constexpr std::strong_ordering operator <=>(
            const basic_static_string<CharType, rightSize, CharTraits>& right
        ) const noexcept {
            
            auto compareResult = length() <=> right.length();

            [[unlikely]]
            if (compareResult != std::strong_ordering::equal) {
                return compareResult;
            } else {
                return
                    traits_type::compare(
                        c_str(), right.c_str(), std::min(size(), right.size())
                    ) <=> 0;
            }
        }
        
        constexpr operator std::basic_string<CharType, CharTraits>() const noexcept {
            return std::basic_string<CharType, CharTraits>{ c_str(), capacity() };
        }

        constexpr operator std::basic_string_view<CharType, CharTraits>() const noexcept {
            return std::basic_string_view<CharType, CharTraits>{ c_str(), capacity() };
        }

        constexpr CharType& operator [](size_type index) noexcept {
            return charArray[index];
        }
        
        constexpr const CharType& operator [](size_type index) const noexcept {
            return charArray[index];
        }
        
        constexpr CharType* data() noexcept {
            return charArray;
        }

        constexpr const CharType* data() const noexcept {
            return charArray;
        }

        constexpr const CharType* c_str() const noexcept {
            return charArray;
        }

        constexpr size_t size() const noexcept {
            return stringSize;
        }

        constexpr size_t length() const noexcept {
            return stringSize;
        }
        
        constexpr size_t capacity() const noexcept {
            return maxStringSize;
        }
        
        size_t   stringSize;
        CharType charArray[maxStringSize + 1];
    };  

    template<
        size_t size, typename CharType
    > basic_static_string(const CharType(&str)[size]) ->
        basic_static_string<CharType, size - 1>;

    template<
        size_t   rightSize,
        typename CharType,
        typename CharTraits
    > basic_static_string(
        const basic_static_string<CharType, rightSize, CharTraits>&other
    ) -> basic_static_string<CharType, rightSize, CharTraits>;
    
    template<typename CharType, CharType... chars>
    basic_static_string(const char_sequence<CharType, chars...>& str) ->
        basic_static_string<CharType, sizeof...(chars)>;

    template<
        typename CharType,
        typename CharTraits = std::char_traits<CharType>,
        size_t   size
    > auto make_static_string(
        const CharType(&str)[size]
    ) noexcept ->
        mylib::basic_static_string<CharType, size - 1, CharTraits>
    {
        return { str };
    }

    template<
        size_t   size,
        typename CharType,
        typename CharTraits = std::char_traits<CharType>
    > auto make_static_string(
        const CharType* str
    ) noexcept ->
        mylib::basic_static_string<CharType, size, CharTraits>
    {
        return { str };
    }

    template<
        size_t   size,
        typename CharType,
        typename CharTraits = std::char_traits<CharType>
    > auto make_static_string(
        const basic_static_string<CharType, size, CharTraits>& str
    ) noexcept ->
        mylib::basic_static_string<CharType, size, CharTraits>
    {
        return { str };
    }

    template<
        size_t   size,
        typename CharType,
        typename CharTraits
    > auto make_static_string(
        std::basic_string<CharType, CharTraits> str
    ) noexcept ->
        mylib::basic_static_string<CharType, size, CharTraits>
    {
        return { str.c_str() };
    }

    template<
        size_t   size,
        typename CharType,
        typename CharTraits
    > auto make_static_string(
        std::basic_string_view<CharType, CharTraits> str
    ) noexcept ->
        mylib::basic_static_string<CharType, size, CharTraits>
    {
        return { str.data() };
    }

    template<
        size_t   stringSize,
        typename CharType,
        typename CharTraits
    > std::ostream& operator <<(
        std::ostream& os,
        const basic_static_string<CharType, stringSize, CharTraits>& str
    ) noexcept {
        os << str.data();
        
        return os;
    }

    inline namespace literals {
        inline namespace basic_static_string_literals {
            
            // will crash intellisense
#           ifndef __INTELLISENSE__

            template<mylib::basic_static_string literal>
            constexpr auto operator ""_ss() noexcept {
                return literal;
            }
            
#           else

#           define define_static_string_suffix(Type)                                    \
            constexpr auto operator ""_ss(const Type* str, size_t size) noexcept        \
                -> mylib::basic_static_string<Type, 255>                                \
            {                                                                           \
                return mylib::basic_static_string<Type, 255>{ str };                    \
            }

            mylib_pp_repeat_each(
                define_static_string_suffix,
                mylib_semicolon,
                char, wchar_t, char8_t, char16_t, char32_t
            );
            
#           endif
        }
    }
}
