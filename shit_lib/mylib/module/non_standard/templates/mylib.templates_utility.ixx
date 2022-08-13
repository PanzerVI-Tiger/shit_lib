module;

#ifdef __INTELLISENSE__

#include <cstddef>
#include <concepts>
#include <algorithm>

#endif

export module mylib.templates_utility;

#ifndef __INTELLISENSE__

import std.core;

#endif

export namespace mylib {

    template<std::integral auto... numbers>
    inline constexpr auto plus_v        = (... + numbers);

    template<std::integral auto... numbers>
    inline constexpr auto minus_v       = (... - numbers);

    template<std::integral auto... numbers>
    inline constexpr auto multiplies_v  = (... * numbers);

    template<std::integral auto... numbers>
    inline constexpr auto divides_v     = (... / numbers);

    template<std::integral auto... numbers>
    inline constexpr auto modulus_v     = (... % numbers);

    template<std::integral auto... numbers>
    inline constexpr auto and_v         = (... & numbers);

    template<std::integral auto... numbers>
    inline constexpr auto or_v          = (... | numbers);

    template<std::integral auto... numbers>
    inline constexpr auto xor_v         = (... ^ numbers);

    template<bool... numbers>
    inline constexpr auto logical_and_v = (... && numbers);

    template<bool... numbers>
    inline constexpr auto logical_or_v  = (... || numbers);

    template<std::integral auto... numbers>
    inline constexpr auto max_v         = std::max({ numbers... });

    template<std::integral auto... numbers>
    inline constexpr auto min_v         = std::min({ numbers... });

    template<std::integral auto... numbers1>
    struct merge_greater{
        using numbers1_common_type = std::common_type_t<decltype(numbers1)...>;

        static constexpr size_t size() {
            return sizeof...(numbers1);
        }

        template<std::integral auto... numbers2>
        using integer_sequence =
            std::integer_sequence<
                std::common_type_t<
                    numbers1_common_type, decltype(numbers2)...
                >, 
                std::max(numbers1, numbers2)...
            >;
    };

    template<std::integral auto... numbers1>
    struct merge_less {
        using numbers1_common_type = std::common_type_t<decltype(numbers1)...>;

        static constexpr size_t size() {
            return sizeof...(numbers1);
        }

        template<std::integral auto... numbers2>
        using integer_sequence =
            std::integer_sequence <
                std::common_type_t<
                    numbers1_common_type, decltype(numbers2)...
                >,
                std::min(numbers1, numbers2)...
            >;
    };

    template<size_t index, auto data1, auto... data>
    inline constexpr auto data_at = data_at<index - 1, data...>;

    template<auto data1, auto... data>
    inline constexpr auto data_at<0, data1, data...> = data1;
}
