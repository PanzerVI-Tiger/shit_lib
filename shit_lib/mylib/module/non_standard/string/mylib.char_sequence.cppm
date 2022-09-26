module;

#ifdef __INTELLISENSE__

#include <string>
#include <utility>
#include <type_traits>

#endif

#include "macro_meta.hpp"

export module mylib.char_sequence;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.string_literal;
import mylib.templates_utility;


export namespace mylib {

    template<typename CharType, CharType... chars>
    struct char_sequence :
        std::integer_sequence<CharType, chars...> {
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
        inline namespace char_sequence_literals {
            
            // will crash intellisense
#           ifndef __INTELLISENSE__
            
            template<mylib::basic_string_literal literal>
            constexpr auto operator ""_cs() noexcept {
                return[]<size_t... indices>(std::index_sequence<indices...>) constexpr noexcept {
                    return
                        char_sequence<
                        typename decltype(literal)::value_type, literal[indices]...
                        >{};
                }(std::make_index_sequence<literal.length()>{});
            }

#           else

#           define define_char_sequence_suffix(Type)                                    \
            constexpr auto operator ""_cs(const Type* str, size_t size) noexcept        \
                -> mylib::char_sequence<Type>                                           \
            {                                                                           \
                return mylib::char_sequence<Type>{};                                    \
            }

            mylib_pp_repeat_each(
                define_char_sequence_suffix,
                mylib_semicolon,
                char, wchar_t, char8_t, char16_t, char32_t
            );

#           endif
        }
    }
}
