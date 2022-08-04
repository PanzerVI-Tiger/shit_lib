export module mylib.stack_string;

import std.core;
import mylib.algorithm;
import mylib.type_traits;
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
        using difference_type = std::ptrdiff_t;
        using reference       = CharType&;
        using const_reference = const CharType&;
        using pointer         = CharType*;
        using const_pointer   = const CharType*;
        
        constexpr stack_string() : 
            stringSize{}, chars{}
        {}
        
        constexpr stack_string(const CharType* str) noexcept :
            stringSize{ traits_type::length(str) }, chars{} {
            
            traits_type::copy(chars, str, stringSize);
        };

        template<size_t size>
            requires (size - 1 <= maxStringSize)
        constexpr stack_string(const CharType(&str)[size]) noexcept :
            stringSize{ size - 1 }, chars{} {
            
            traits_type::copy(chars, str, stringSize);
        };
        
        constexpr CharType* data() noexcept {
            return chars;
        }

        constexpr const CharType* data() const noexcept {
            return chars;
        }

        constexpr size_t size() const noexcept {
            return stringSize;
        }

        constexpr size_t length() const noexcept {
            return stringSize;
        }
        
        size_t capacity() const noexcept {
            return maxStringSize + 1;
        }
        
        size_t   stringSize;
        CharType chars[maxStringSize + 1];
    };

    template<
        size_t maxStringSize, typename CharType
    > stack_string(const CharType(&str)[maxStringSize]) -> 
        stack_string<maxStringSize, CharType>;
    
    template<typename CharType>
    struct stack_string<size_t(-1), CharType> {
        
        using traits_type     = std::char_traits<CharType>;
        using value_type      = CharType;
        using size_type       = size_t;
        using difference_type = std::ptrdiff_t;
        using reference       = CharType&;
        using const_reference = const CharType&;
        using pointer         = CharType*;
        using const_pointer   = const CharType*;

        template<size_t size>
        constexpr stack_string(const CharType(&str)[size]) noexcept :
            chars{ str }, stringSize{ size } 
        {}
        
        constexpr const CharType* data() const noexcept {
            return chars;
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
        CharTraits::copy(buff, first.data(), first.size());
        buff += first.size();
        
        if constexpr (sizeof...(stringSizes) != 0) {
            concat_implement(buff, strings...);
        } else {
            *buff = CharType{};
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
        const stack_string<leftSize,  CharType, CharTraits>& left,
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
            
            template<stack_string<size_t(-1)> literal>
            constexpr auto operator ""_ss() noexcept {
                constexpr size_t literalSize = literal.size();
                
                stack_string<literalSize> result{ literal.data() };
                
                return result;
            }
        }
    }
}
