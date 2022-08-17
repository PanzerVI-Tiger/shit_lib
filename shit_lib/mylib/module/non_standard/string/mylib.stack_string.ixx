module;

#ifdef __INTELLISENSE__

#include <string>
#include <compare>

#endif

export module mylib.stack_string;

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
        size_t   maxStringSize,
        typename CharType   = char,
        typename CharTraits = std::char_traits<CharType>
    > struct stack_string {

        using traits_type     = std::char_traits<CharType>;
        using value_type      = CharType;
        using size_type       = size_t;
        using difference_type = ptrdiff_t;
        using reference       = CharType&;
        using const_reference = const CharType&;
        using pointer         = CharType*;
        using const_pointer   = const CharType*;
        
        constexpr stack_string() : 
            stringSize{}, charArray{}
        {}

        // copy
        template<size_t rightSize>
        constexpr stack_string(
            const stack_string<rightSize, CharType, CharTraits>& other
        ) : stringSize{ std::min(maxStringSize, other.stringSize) }, charArray{} {
            traits_type::copy(charArray, other.charArray, stringSize);
        }
        
        template<size_t size>
        constexpr stack_string(const CharType(&str)[size]) noexcept :
            stringSize{ maxStringSize }, charArray{} 
        {
            traits_type::copy(charArray, str, stringSize);
        };

        template<CharType... chars>
        constexpr stack_string(mylib::char_sequence<CharType, chars...>) noexcept :
            stringSize{ std::min(maxStringSize - 1, sizeof...(chars)) }, charArray{ chars... }
        {};
        
        constexpr stack_string(const CharType* str) noexcept :
            stringSize{ std::min(traits_type::length(str), maxStringSize) }, charArray{} 
        {           
            traits_type::copy(charArray, str, stringSize);
        };

        constexpr stack_string(mylib::basic_string_literal<CharType> str) noexcept :
            stringSize{ std::min(str.size(), maxStringSize) }, charArray{} 
        {
            traits_type::copy(charArray, str.data(), stringSize);
        };

        template<size_t rightSize>
        constexpr stack_string operator =(
            const stack_string<rightSize, CharType, CharTraits>& right
        ) noexcept {
            
            stringSize = std::min(maxStringSize, right.stringSize);
            traits_type::copy(charArray, right.charArray, stringSize);
            
            return *this;
        }

        template<size_t rightSize>
        constexpr bool operator ==(
            const stack_string<rightSize, CharType, CharTraits>& right
        ) const noexcept {
            return 
                length() == right.length() &&
                traits_type::compare(
                    c_str(), right.c_str(), std::min(size(), right.size())
                ) == 0;
        }

        template<size_t rightSize>
        constexpr std::strong_ordering operator <=>(
            const stack_string<rightSize, CharType, CharTraits>& right
        ) const noexcept {
            
            auto compareResult = traits_type::compare(
                c_str(), right.c_str(), std::min(size(), right.size())
            ) <=> 0;

            [[unlikely]]
            if (compareResult == std::strong_ordering::equal) {
                return length() <=> right.length();
            } else {
                return compareResult;
            }
        }
        
        constexpr operator std::string() noexcept {
            return std::string{ c_str(), capacity() };
        }

        constexpr operator std::string_view() noexcept {
            return std::string_view{ c_str(), capacity() };
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
    > stack_string(const CharType(&str)[size]) ->
        stack_string<size - 1, CharType>;

    template<
        size_t   rightSize,
        typename CharType,
        typename CharTraits
    > stack_string(
        const stack_string<rightSize, CharType, CharTraits>&other
    ) -> stack_string<rightSize, CharType, CharTraits>;
    
    template<typename CharType, CharType... chars>
    stack_string(const char_sequence<CharType, chars...>& str) ->
        stack_string<sizeof...(chars), CharType>;

    template<
        size_t   stringSize,
        typename CharType,
        typename CharTraits
    > std::ostream& operator <<(
        std::ostream& os,
        const stack_string<stringSize, CharType, CharTraits>& str
    ) noexcept {
        os << str.data();
        
        return os;
    }

    inline namespace literals {
        inline namespace stack_string_literals {
            
            template<mylib::stack_string literal>
            constexpr auto operator ""_ss() noexcept {
                return literal;
            }
        }
    }
}
