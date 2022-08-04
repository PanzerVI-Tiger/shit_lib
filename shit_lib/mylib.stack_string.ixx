export module mylib.stack_string;

import std.core;
import mylib.algorithm;
import mylib.type_traits;
import mylib.templates_utility;


export namespace mylib {
    
    template<
        size_t   stringSize,
        typename CharType   = char,
        typename CharTraits = std::char_traits<CharType>
    > struct stack_string {

        constexpr CharType* data() noexcept {
            return chars;
        }

        constexpr const CharType* data() const noexcept {
            return chars;
        }

        constexpr size_t size() const noexcept {
            return stringSize;
        }
        
        CharType chars[stringSize + 1];
    };
    
    template<typename CharType>
    struct stack_string<size_t(-1), CharType> {

        constexpr stack_string(const CharType* str) noexcept : 
            chars{ str }, stringSize{ std::char_traits<CharType>::length(str) } {}
        constexpr const CharType* data() const noexcept {
            return chars;
        }
        
        constexpr size_t size() const noexcept {
            return stringSize;
        }

        const CharType* chars;
        size_t          stringSize;
    };

    template<
        typename  CharType,
        typename  CharTraits,
        size_t    stringSize,
        size_t... stringSizes
    > constexpr void concat_implement(
        CharType*                                                 buff,
        const stack_string<stringSize,  CharType, CharTraits>&    first,
        const stack_string<stringSizes, CharType, CharTraits>&... strings
    ) noexcept {
        copy(first.data(), first.data() + first.size(), buff);
        buff += first.size();
        if constexpr (sizeof...(stringSizes) != 0) {
            concat_implement(buff, strings...);
        } else {
            *buff = '\0';
        }
    }
    
    template<
        typename  CharType,
        typename  CharTraits,
        size_t... stringSizes
    > constexpr auto concat(
        const stack_string<stringSizes, CharType, CharTraits>&... strings
    ) noexcept {
        
        stack_string<
            plus_v<stringSizes...> -
            sizeof...(stringSizes) + 1,
            CharType,
            CharTraits
        > result{};

        if constexpr (sizeof...(stringSizes) == 1) {
            return [](const auto& x) constexpr noexcept {
                return x;
            }(strings...);
        } else {
            concat_implement(result.data(), strings...);
            return result;
        }
    }

    template<
        size_t   leftSize, size_t   rightSize,
        typename CharType, typename CharTraits
    > constexpr auto operator +(
        const stack_string<leftSize, CharType, CharTraits>&  left,
        const stack_string<rightSize, CharType, CharTraits>& right
        ) noexcept {

        return concat(left, right);
    }

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
        inline namespace string_literals {
            template<stack_string<size_t(-1)> str>
            constexpr auto operator ""_ss() noexcept {
                stack_string<str.size()> result{};
                copy(str.data(), str.data() + str.size() - 1, result.data());
                
                return result;
            }
        }
    }
}
