export module mylib.stack_string;

import std.core;
import mylib.algorithm;
import mylib.type_traits;
import mylib.templates_utility;


export namespace mylib {
    
    template<
        size_t   stringSize,
        typename CharType, 
        typename CharTraits
    > struct stack_string;
    
    template<
        typename CharType, 
        typename CharTraits, 
        size_t... stringSizes>
    constexpr auto concat(const stack_string<stringSizes, CharType, CharTraits>&... strings) noexcept;
    
    template<
        size_t   stringSize,
        typename CharType   = char,
        typename CharTraits = std::char_traits<CharType>
    > struct stack_string {
        
        template<size_t rightSize>
        constexpr stack_string<
            stringSize + rightSize - 1,
            CharType,
            CharTraits
        > operator +(
            const stack_string<rightSize, CharType, CharTraits>& right
            ) noexcept {

            stack_string<
                stringSize + rightSize,
                CharType,
                CharTraits
            > result;

            return concat(*this, right);
        }

        constexpr CharType* data() noexcept {
            return chars;
        }

        constexpr const CharType* data() const noexcept {
            return chars;
        }

        constexpr size_t size() const noexcept {
            return stringSize - 1;
        }
        
        CharType chars[stringSize];
    };

    
    template<typename CharType>
    struct stack_string<size_t(-1), CharType> {

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
        size_t... stringSizes
    > constexpr auto concat(
        const stack_string<stringSizes, CharType, CharTraits>&... strings
    ) noexcept {
        
        stack_string<
            plus_v<(stringSizes == size_t(-1) ? 64 : stringSizes)...> -
                sizeof...(stringSizes) + 1,
            CharType,
            CharTraits
        > result{};

        if constexpr (sizeof...(stringSizes) == 1) {
            return [](const auto& x) constexpr noexcept {
                return x;
            }(strings...);
        } else {
            
            auto l = 
                [pos = result.data()]<size_t size1, size_t... sizes> (
                    this  auto                                     &    self,
                    const stack_string<size1, CharType, CharTraits>&    first,
                    const stack_string<sizes, CharType, CharTraits>&... strings
                ) constexpr noexcept {               
                    copy(first.data(), first.data() + first.size(), pos);
                    pos += first.size();
                    if constexpr (sizeof...(sizes) != 0) {
                        self(strings...);
                    }
                };
            
            l(strings...);
            
            return result;
        }
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
            constexpr stack_string<size_t(-1)> operator ""_ss(const char* str, size_t size) noexcept {
                return stack_string<size_t(-1)>{ str, size };
            }
        }
    }
}
