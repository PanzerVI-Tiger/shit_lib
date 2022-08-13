#ifdef __INTELLISENSE__

#include <cString>
#include <iostream>
#include <type_traits>

#endif

export module mylib.string_literal;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.algorithm;
import mylib.templates_utility;


export namespace mylib {

    template<typename CharType>
    struct basic_string_literal {

        using value_type      = CharType;
        using size_type       = size_t;
        using difference_type = ptrdiff_t;
        using traits_type     = std::char_traits<CharType>;
        
        constexpr basic_string_literal() noexcept :
            cString{}, stringSize{}
        {}
        
        template<size_t strSize>
        constexpr basic_string_literal(const CharType(&str)[strSize]) noexcept :
            stringSize{ strSize - 1 }, cString{ str }
        {}

        constexpr basic_string_literal(const CharType* str, size_t strSize) noexcept :
            stringSize{ strSize }, cString{ str }
        {}
        
        constexpr basic_string_literal(const CharType* str) noexcept :
            stringSize{ traits_type::length(str) }, cString{str}
        {}
        
        // copy
        constexpr basic_string_literal(const basic_string_literal&) noexcept = default;

        constexpr basic_string_literal& operator =(const basic_string_literal&)                    = default;

        constexpr operator std::basic_string<CharType>() const noexcept {
            return std::basic_string<CharType>(cString, stringSize);
        }
        
        constexpr const CharType& operator[](size_t index) const noexcept {
            return cString[index];
        }
        
        constexpr size_t size() const noexcept {
            return stringSize;
        }
        
        constexpr size_t length() const noexcept {
            return stringSize;
        }

        constexpr size_t capacity() const noexcept {
            return stringSize;
        }

        constexpr const CharType* data() const noexcept {
            return cString;
        }

        constexpr const CharType* c_str() const noexcept {
            return cString;
        }
        
        const CharType* cString;
        size_t          stringSize;
    };

    template<typename CharType>
    std::ostream& operator <<(std::ostream& os, const basic_string_literal<CharType>& str) {
        return os << str.c_str();
    }

    using string_literal    = basic_string_literal<char>;
    using wstring_literal   = basic_string_literal<wchar_t>;
    using u8string_literal  = basic_string_literal<char8_t>;
    using u16string_literal = basic_string_literal<char16_t>;
    using u32string_literal = basic_string_literal<char32_t>;
    
    template<typename CharType, CharType... chars>
    struct char_sequence :
        std::integer_sequence<CharType, chars...>
    {
        constexpr CharType operator [](size_t index) noexcept {
            return data_at<index, chars...>;
        }
        
        constexpr operator std::basic_string<CharType>() const noexcept {
            return { { chars... } };
        }

        template<typename CharType, CharType... rightChars>
        constexpr char_sequence<CharType, chars..., rightChars...>
            operator +(char_sequence<CharType, rightChars...>) noexcept 
        {}

        template<size_t index>
        static constexpr CharType char_at = data_at<index, chars...>;
    };

    inline namespace literals {
        
        inline namespace string_literal_literals {
            // string literal
            constexpr string_literal    operator""_sl(const char* str, size_t size) noexcept {
                return string_literal{ str, size };
            }

            // string literal
            constexpr wstring_literal   operator""_sl(const wchar_t* str, size_t size) noexcept {
                return wstring_literal{ str, size };
            }

            // string literal
            constexpr u8string_literal  operator""_sl(const char8_t* str, size_t size) noexcept {
                return u8string_literal{ str, size };
            }

            // string literal
            constexpr u16string_literal operator""_sl(const char16_t* str, size_t size) noexcept {
                return u16string_literal{ str, size };
            }

            // string literal
            constexpr u32string_literal operator""_sl(const char32_t* str, size_t size) noexcept {
                return u32string_literal{ str, size };
            }
        }
        
        inline namespace char_sequence_literals {
            // chars sequence
            template<basic_string_literal literal>
            constexpr auto operator ""_cs() noexcept {
                return[]<size_t... indices>(std::index_sequence<indices...>) constexpr noexcept {
                    return
                        char_sequence<
                            typename decltype(literal)::value_type, literal[indices]...
                        >{};
                }(std::make_index_sequence<literal.length()>{});
            }
        }
    }
}
