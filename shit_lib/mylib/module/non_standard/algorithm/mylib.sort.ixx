module;

#ifdef __INTELLISENSE__

import <vector>;
import <utility>;
import <algorithm>;

#endif

export module mylib.sort;

import mylib.algorithm;

#ifndef __INTELLISENSE__

import std.core;

#endif



export namespace mylib::inline sorts {

    template<typename BidirectionalIterator, typename Predicate>
    constexpr void bubble_sort(
        BidirectionalIterator first, BidirectionalIterator last, Predicate pred
    ) noexcept {

        for (auto i = last; i != first; --i) {
            for (auto j = first; j != i;) {
                auto temp = j;
                if (pred(*++j, *temp)) {
                    std::swap(*j, *temp);
                }
            }
        }
    }

    template<typename BidirectionalIterator>
    constexpr void bubble_sort(
        BidirectionalIterator first, BidirectionalIterator last
    ) noexcept {
        mylib::bubble_sort(first, last, std::less{});
    }

    template<typename ForwardIterator, typename Predicate>
    constexpr void selection_sort(
        ForwardIterator first, ForwardIterator last, Predicate pred
    ) noexcept {
        
        for (auto i = first; i != last; ++i) {
            std::swap(*i, *std::min_element(i, last, pred));
        }
    }

    template<typename ForwardIterator>
    constexpr void selection_sort(
        ForwardIterator first, ForwardIterator last
    ) noexcept {
        mylib::selection_sort(first, last, std::less{});
    }

    template<typename BidirectionalIterator, typename Predicate>
    constexpr void insertion_sort(
        BidirectionalIterator first, BidirectionalIterator last, Predicate pred
    ) noexcept {
        
        if (first == last) {
            return;
        }

        auto i = first;
        for (++i; i != last; ++i) {
            auto current{ std::move(*i) };
            auto temp = i;
            auto j    = i;
            for (; j != first && pred(current, *--j); temp = j) {
                *temp = std::move(*j);
            }
            *temp = std::move(current);
        }
    }

    template<typename BidirectionalIterator>
    constexpr void insertion_sort(
        BidirectionalIterator first, BidirectionalIterator last
    ) noexcept {
        mylib::insertion_sort(first, last, std::less{});
    }

    template<typename RandomAccessIterator, typename Predicate>
    constexpr void shell_sort(
        RandomAccessIterator first, RandomAccessIterator last, Predicate pred
    ) noexcept {
        
        const size_t buffSize = last - first;
        size_t       distance = 1;

        while (distance < buffSize / 3) {
            distance = distance * 3 + 1;
        }

        while (distance >= 1) {
            for (size_t i = distance; i < buffSize; ++i) {
                auto current{ std::move(first[i]) };
                auto temp = i;
                auto j    = i;
                for (; j >= distance && pred(current, first[j -= distance]); temp = j) {
                    first[temp] = std::move(first[j]);
                }
                first[temp] = std::move(current);
            }
            distance /= 3;
        }
    }

    template<typename RandomAccessIterator>
    constexpr void shell_sort(
        RandomAccessIterator first, RandomAccessIterator last
    ) noexcept {
        
        mylib::shell_sort(first, last, std::less{});
    }
    
    template<typename RandomAccessIterator, typename Predicate>
    constexpr void merge_sort(
        RandomAccessIterator first, RandomAccessIterator last, Predicate pred
    ) noexcept {
        
        using move_iter1 = std::move_iterator<RandomAccessIterator>;

        auto first = move_iter1{ first };
        auto last  = move_iter1{ last  };
        
        const size_t size = last - first;
        std::vector<std::iter_value_t<RandomAccessIterator>> auxiliarySpace(size);
        
        using move_iter2 = std::move_iterator<decltype(auxiliarySpace.begin())>;

        for (size_t i = 0; i < size; i += 16) {
            mylib::insertion_sort(first + i, first + std::min(i + 16, size), pred);
        }

        /*
        for (size_t i = 16; i < size; i <<= 1) {
            for (size_t j = 0; j + i < size; j += i + i) {
                mylib::inplace_merge(first + j, first + j + i, first + std::min(j + i + i, size));
            }
        }
        */
        
        auto buffBegin     = auxiliarySpace.begin();
        auto moveBuffBegin = move_iter2{ buffBegin };
        auto buffEnd       = auxiliarySpace.end();
        size_t count       = 0;
        for (size_t i = 16; i < size; i <<= 1) {
            const size_t limit = size - i;
            if ((count & 1) == 0) {
                size_t j = 0;
                for (; j < limit; j += i + i) {
                    mylib::merge(first + j, first + j + i, first + j + i,
                        first + std::min(j + i + i, size), buffBegin + j, pred);
                }
                if (j < size) {
                    mylib::copy(first + j, first + size, buffBegin + j);
                }
            } else {
                size_t j = 0;
                for (; j < limit; j += i + i) {
                    mylib::merge(moveBuffBegin + j, moveBuffBegin + j + i, moveBuffBegin + j + i,
                        moveBuffBegin + std::min(j + i + i, size), first + j, pred);
                }
                if (j < size) {
                    mylib::copy(moveBuffBegin + j, moveBuffBegin + size, first + j);
                }
            }
            count++;
        }
         
        if ((count & 1) != 0) {
            mylib::copy(buffBegin, buffEnd, first);
        }
    }

    template<typename RandomAccessIterator>
    constexpr void merge_sort(
        RandomAccessIterator first, RandomAccessIterator last
    ) noexcept {
        mylib::merge_sort(first, last, std::less{});
    }
}
