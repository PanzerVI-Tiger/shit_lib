export module mylib.string_literal;

import std.core;
import mylib.algorithm;

export namespace mylib {

    template<typename CharType>
    struct base_string_literal {

        using value_type      = CharType;
        using size_type       = size_t;
        using difference_type = ptrdiff_t;
        
        template<size_t strSize>
        constexpr base_string_literal(const CharType(&str)[strSize]) noexcept :
            string{ str }, stringSize{ strSize - 1 }
        {}
        
        constexpr size_t size() const noexcept {
            return stringSize;
        }
        
        constexpr size_t length() const noexcept {
            return stringSize;
        }

        constexpr const CharType* data() const noexcept {
            return string;
        }

        constexpr const CharType* c_str() const noexcept {
            return string;
        }
        
        const CharType* string;
        size_t          stringSize;
    };

    using string_literal    = base_string_literal<char>;
    using wstring_literal   = base_string_literal<wchar_t>;
    using u8string_literal  = base_string_literal<char8_t>;
    using u16string_literal = base_string_literal<char16_t>;
    using u32string_literal = base_string_literal<char32_t>;

    inline namespace literals {
        inline namespace string_literals {
            
            template<base_string_literal literal>
            auto operator""_sl() noexcept {
                return literal;
            }
        }
    }
}
