export module mylib.concat;


import mylib.string;
import mylib.type_traits;
import mylib.stack_string;
import mylib.string_literal;
import mylib.templates_utility;


export namespace mylib {
    
    /*
     *  concat can connect tuple, array, and string
     *
     *  if arguments have tuple, return type is tuple
     *  if arguments have base_string or pointer to character, concat return type is base_string,
     *  else return stack_string
     */

    template<typename Type>
    inline constexpr bool is_concatable = false;

    template<typename Type>
    concept concatable = is_concatable<Type>;

    
    template<typename Type>
    struct concatable_traits {
        
    };

    template<typename... Types>
    struct concat_result {

    };

    template<typename... Types>
    using concat_result_t = typename concat_result<Types...>::type;
    
    template<
        typename  CharType,
        typename  CharTraits,
        size_t    stringSize,
        size_t... stringSizes
    > constexpr void concat_implement(
        CharType* buff,
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

        if constexpr (sizeof...(stringSizes) == 1) {
            return [](const auto& x) constexpr noexcept {
                return x;
            }(strings...);
        } else {
            stack_string<
                plus_v<stringSizes...>,
                CharType,
                CharTraits
            > result{};

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
}
