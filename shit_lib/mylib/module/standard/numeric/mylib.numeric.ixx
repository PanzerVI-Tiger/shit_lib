module;

#include "cpp/non_standard/macro/mylib_assert.h"

#ifdef __INTELLISENSE__

#include <ranges>
#include <utility>
#include <iterator>

#endif

export module mylib.numeric;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.functional;
import mylib.type_traits;

export namespace mylib {
    
    // C++11
    template<typename ForardIterator, typename ValueType>
    constexpr void iota(ForardIterator first, ForardIterator last, ValueType value) noexcept {
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);
        
        for (; first != last; ++first, ++value) {
            *first = value;
        }
    }

    // non-standard
    template<std::weakly_incrementable ValueType, std::ranges::range Range>
    constexpr void iota(Range& r, ValueType value) noexcept {
        []<typename Range>(
            this auto self, Range& r, ValueType& value
        ) constexpr noexcept -> void {

            for (auto& i : r) {
                using SubRange = std::ranges::range_value_t<Range>;

                constexpr bool isAssignable = std::is_assignable_v<SubRange&, ValueType>;
                
                if constexpr (
                    std::ranges::range<SubRange> && !isAssignable
                ) {
                    self(i, value);
                } else {
                    static_assert(
                        isAssignable,
                        "The ValueType should assignable to the Range's final value type"
                    );
                    i = value;
                    ++value;
                }
            }
        }(r, value);
    }

    template<typename InputIterator, typename ValueType, typename BinaryFunction>
    constexpr ValueType accumulate(
        InputIterator first,        InputIterator  last, 
        ValueType     initialValue, BinaryFunction binaryFunc
    ) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);
        
        for (; first != last; ++first) {
            initialValue = binaryFunc(std::move(initialValue), *first);
        }
        
        return initialValue;
    }

    template<typename InputIterator, typename ValueType>
    constexpr ValueType accumulate(
        InputIterator first, InputIterator  last,
        ValueType     initialValue
    ) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);
        
        return mylib::accumulate(first, last, initialValue, plus{});
    }

    // C++17
    template<typename InputIterator, typename ValueType, typename BinaryFunction>
    constexpr ValueType reduce(
        InputIterator first,        InputIterator  last,
        ValueType     initialValue, BinaryFunction binaryFunc
    ) noexcept {
    
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);
        
        for (; first != last; ++first) {
            initialValue = binaryFunc(std::move(initialValue), *first);
        }

        return initialValue;
    }

    // C++17
    template<typename InputIterator, typename ValueType>
    constexpr ValueType reduce(
        InputIterator first, InputIterator last,
        ValueType     initialValue
    ) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);
        
        return mylib::reduce(first, last, initialValue, plus{});
    }

    // C++17
    template<typename InputIterator>
    constexpr std::iter_value_t<InputIterator> reduce(
        InputIterator first, InputIterator last
    ) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);
        
        return mylib::reduce(first, last, std::iter_value_t<InputIterator>{});
    }
    
    // C++17
    template<typename Type1, typename Type2>
    constexpr std::common_type_t<Type1, Type2> gcd(Type1 value1, Type2 value2) noexcept {
        // TODO: use stein gcd
        if (value1 < value2) {
            std::swap(value1, value2);
        }
        
        while (value2 != 0) {
            std::common_type_t<Type1, Type2> temp = value1 % value2;
            
            value1 = std::move(value2);
            value2 = std::move(temp);
        }

        return value1;
    }
    
    // C++17
    template<typename Type1, typename Type2>
    constexpr std::common_type_t<Type1, Type2> lcm(Type1 value1, Type2 value2) noexcept {
        return value1 / mylib::gcd(value1, value2) * value2;
    }
}
