export module mylib.stack_string;

import std.core;
import mylib.algorithm;
import mylib.type_traits;
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
            stringSize{}, chars{}
        {}

        template<size_t rightSize>
        constexpr stack_string(
            const stack_string<rightSize, CharType, CharTraits>& other
        ) : stringSize{ std::min(maxStringSize, other.stringSize) }, chars{} {    
            traits_type::copy(chars, other.chars, stringSize);
        }
        
        constexpr stack_string(const CharType* str) noexcept :
            stringSize{ std::min(traits_type::length(str), maxStringSize) }, chars{} 
        {           
            traits_type::copy(chars, str, stringSize);
        };

        template<size_t size>
        constexpr stack_string(const CharType(&str)[size]) noexcept :
            stringSize{ maxStringSize }, chars{} {

            traits_type::copy(chars, str, stringSize);
        };

        template<size_t rightSize>
        constexpr stack_string operator =(
            const stack_string<rightSize, CharType, CharTraits>& right
        ) noexcept {
            
            stringSize = std::min(maxStringSize, right.stringSize);
            traits_type::copy(chars, right.chars, stringSize);
            
            return *this;
        }
        
        constexpr CharType* data() noexcept {
            return chars;
        }

        constexpr const CharType* data() const noexcept {
            return chars;
        }

        constexpr const CharType* c_str() const noexcept {
            return chars;
        }

        constexpr size_t size() const noexcept {
            return stringSize;
        }

        constexpr size_t length() const noexcept {
            return stringSize;
        }
        
        constexpr size_t capacity() const noexcept {
            return maxStringSize + 1;
        }
        
        size_t   stringSize;
        CharType chars[maxStringSize + 1];
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
            
            template<stack_string literal>
            constexpr auto operator ""_ss() noexcept {
                return literal;
            }
        }
    }
}
