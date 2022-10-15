export module mylib.concat;


import mylib.string;
import mylib.type_traits;
import mylib.static_string;
import mylib.string_literal;
import mylib.templates_utility;


export namespace mylib {

    /*
     *  concat can connect tuple, array, and string
     *
     *  concat's argument must concatable
     *  if arguments have tuple, return type is tuple
     *  if arguments have base_string or pointer to character, concat return type is base_string,
     *  else return basic_static_string
     */

    template<typename Type>
    inline constexpr bool is_concatable_v = false;

    template<typename Type>
    struct is_concatable :
        bool_constant<mylib::is_concatable_v<Type>> {
    };

    template<typename Type>
    concept concatable = mylib::is_concatable_v<Type>;

    template<typename Type>
    struct concatable_traits {

    };

    template<typename... Types>
    struct concat_result {

    };

    template<typename... Types>
    using concat_result_t = typename mylib::concat_result<Types...>::type;

}

namespace mylib::detail {
    template<
        typename  CharType,
        typename  CharTraits,
        size_t    stringSize,
        size_t... stringSizes
    > constexpr void concat_implement(
        CharType* buff,
        const basic_static_string<CharType, stringSize,  CharTraits>& first,
        const basic_static_string<CharType, stringSizes, CharTraits>&... strings
    ) noexcept {

        CharTraits::copy(buff, first.data(), first.size());
        buff += first.size();

        if constexpr (sizeof...(stringSizes) != 0) {
            mylib::detail::concat_implement(buff, strings...);
        } else {
            *buff = CharType{};
        }
    }
}

export namespace mylib {

    template<
        typename  CharType,
        typename  CharTraits,
        size_t... stringSizes
    > constexpr auto concat(
        const basic_static_string<CharType, stringSizes, CharTraits>&... strings
    ) noexcept {

        if constexpr (sizeof...(stringSizes) == 1) {
            return [](const auto& x) constexpr noexcept {
                return x;
            }(strings...);
        } else {
            mylib::basic_static_string<
                CharType,
                mylib::plus_v<stringSizes...>,
                CharTraits
            > result{};

            mylib::detail::concat_implement(result.data(), strings...);
            
            return result;
        }
    }

    template<
        typename CharType,
        size_t   leftSize,
        size_t   rightSize,
        typename CharTraits
    > constexpr auto operator +(
        const basic_static_string<CharType, leftSize,  CharTraits>& left,
        const basic_static_string<CharType, rightSize, CharTraits>& right
        ) noexcept {

        return mylib::concat(left, right);
    }
}
