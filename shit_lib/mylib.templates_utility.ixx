export module mylib.templates;

import std.core;


namespace mylib {

    template<std::integral auto... _Numbers>
    inline constexpr auto plus_v		= (... + _Numbers);

    template<std::integral auto... _Numbers>
    inline constexpr auto minus_v		= (... - _Numbers);

    template<std::integral auto... _Numbers>
    inline constexpr auto multiplies_v	= (... * _Numbers);

    template<std::integral auto... _Numbers>
    inline constexpr auto divides_v		= (... / _Numbers);

    template<std::integral auto... _Numbers>
    inline constexpr auto modulus_v		= (... % _Numbers);

    template<std::integral auto... _Numbers>
    inline constexpr auto and_v			= (... & _Numbers);

    template<std::integral auto... _Numbers>
    inline constexpr auto or_v			= (... | _Numbers);

    template<std::integral auto... _Numbers>
    inline constexpr auto xor_v			= (... ^ _Numbers);

    template<bool... _Numbers>
    inline constexpr auto logical_and_v = (... && _Numbers);

    template<bool... _Numbers>
    inline constexpr auto logical_or_v  = (... || _Numbers);

    template<std::integral auto... _Numbers>
    inline constexpr auto max_v		    = std::max({ _Numbers... });

    template<std::integral auto... _Numbers>
    inline constexpr auto min_v		    = std::min({ _Numbers... });

    template<std::integral auto... _Numbers1>
    struct merge_greater{
        using numbers1_common_type = std::common_type_t<decltype(_Numbers1)...>;

        static constexpr size_t size() {
            return sizeof...(_Numbers1);
        }

        template<std::integral auto... _Numbers2>
        using integer_sequence =
            std::integer_sequence<
                std::common_type_t<
                    numbers1_common_type, decltype(_Numbers2)...
                >, 
                std::max(_Numbers1, _Numbers2)...
            >;
    };

    template<std::integral auto... _Numbers1>
    struct merge_less {
        using numbers1_common_type = std::common_type_t<decltype(_Numbers1)...>;

        static constexpr size_t size() {
            return sizeof...(_Numbers1);
        }

        template<std::integral auto... _Numbers2>
        using integer_sequence =
            std::integer_sequence <
                std::common_type_t<
                    numbers1_common_type, decltype(_Numbers2)...
                >,
                std::min(_Numbers1, _Numbers2)...
            >;
    };
}
