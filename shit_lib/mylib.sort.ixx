export module mylib.sort;

import std.core;
import mylib.algorithm;


export namespace mylib::inline sort {

    template<typename _BidirectionalIterator, typename _Predicate>
    constexpr void bubble_sort(_BidirectionalIterator _First, _BidirectionalIterator _Last, _Predicate _Pred) noexcept {
        for (auto i = _Last; i != _First; --i) {
            for (auto j = _First; j != i;) {
                auto temp = j;
                if (_Pred(*++j, *temp)) {
                    std::swap(*j, *temp);
                }
            }
        }
    }

    template<typename _BidirectionalIterator>
    constexpr void bubble_sort(_BidirectionalIterator _First, _BidirectionalIterator _Last) noexcept {
        bubble_sort(_First, _Last, std::less<>{});
    }

    template<typename _ForwardIterator, typename _Predicate>
    constexpr void selection_sort(_ForwardIterator _First, _ForwardIterator _Last, _Predicate _Pred) noexcept {
        for (auto i = _First; i != _Last; ++i) {
            std::swap(*i, *std::min_element(i, _Last, _Pred));
        }
    }

    template<typename _ForwardIterator>
    constexpr void selection_sort(_ForwardIterator _First, _ForwardIterator _Last) noexcept {
        selection_sort(_First, _Last, std::less<>{});
    }

    template<typename _BidirectionalIterator, typename _Predicate>
    constexpr void insertion_sort(_BidirectionalIterator _First, _BidirectionalIterator _Last, _Predicate _Pred) noexcept {
        if (_First == _Last) {
            return;
        }

        auto i = _First;
        for (++i; i != _Last; ++i) {
            auto current{ std::move(*i) };
            auto temp = i;
            auto j    = i;
            for (; j != _First && _Pred(current, *--j); temp = j) {
                *temp = std::move(*j);
            }
            *temp = std::move(current);
        }
    }

    template<typename _BidirectionalIterator>
    constexpr void insertion_sort(_BidirectionalIterator _First, _BidirectionalIterator _Last) noexcept {
        insertion_sort(_First, _Last, std::less<>{});
    }

    template<typename _RandomAccessIterator, typename _Predicate>
    constexpr void shell_sort(_RandomAccessIterator _First, _RandomAccessIterator _Last, _Predicate _Pred) noexcept {
        const size_t buffSize = _Last - _First;
        size_t       distance = 1;

        while (distance < buffSize / 3) {
            distance = distance * 3 + 1;
        }

        while (distance >= 1) {
            for (size_t i = distance; i < buffSize; ++i) {
                auto current{ std::move(_First[i]) };
                auto temp = i;
                auto j    = i;
                for (; j >= distance && _Pred(current, _First[j -= distance]); temp = j) {
                    _First[temp] = std::move(_First[j]);
                }
                _First[temp] = std::move(current);
            }
            distance /= 3;
        }
    }

    template<typename _RandomAccessIterator>
    constexpr void shell_sort(_RandomAccessIterator _First, _RandomAccessIterator _Last) noexcept {
        shell_sort(_First, _Last, std::less<>{});
    }
    
    template<typename _RandomAccessIterator, typename _Predicate>
    constexpr void merge_sort(_RandomAccessIterator _First, _RandomAccessIterator _Last, _Predicate _Pred) noexcept {
        using move_iter1 = std::move_iterator<_RandomAccessIterator>;

        auto first = move_iter1{ _First };
        auto last  = move_iter1{ _Last  };
        
        const size_t size = last - first;
        std::vector<std::iter_value_t<_RandomAccessIterator>> auxiliarySpace(size);
        
        using move_iter2 = std::move_iterator<decltype(auxiliarySpace.begin())>;

        for (size_t i = 0; i < size; i += 16) {
            insertion_sort(_First + i, _First + std::min(i + 16, size), _Pred);
        }

        /*
        for (size_t i = 16; i < size; i <<= 1) {
            for (size_t j = 0; j + i < size; j += i + i) {
                mylib::inplace_merge(_First + j, _First + j + i, _First + std::min(j + i + i, size));
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
                        first + std::min(j + i + i, size), buffBegin + j, _Pred);
                }
                if (j < size) {
                    mylib::copy(first + j, first + size, buffBegin + j);
                }
            } else {
                size_t j = 0;
                for (; j < limit; j += i + i) {
                    mylib::merge(moveBuffBegin + j, moveBuffBegin + j + i, moveBuffBegin + j + i,
                        moveBuffBegin + std::min(j + i + i, size), _First + j, _Pred);
                }
                if (j < size) {
                    mylib::copy(moveBuffBegin + j, moveBuffBegin + size, _First + j);
                }
            }
            count++;
        }
         
        if ((count & 1) != 0) {
            mylib::copy(buffBegin, buffEnd, _First);
        }
    }

    template<typename _RandomAccessIterator>
    constexpr void merge_sort(_RandomAccessIterator _First, _RandomAccessIterator _Last) noexcept {
        merge_sort(_First, _Last, std::less<>{});
    }
}
