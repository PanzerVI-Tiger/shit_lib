module;

#include "mylib_assert.h"

export module mylib.algorithm;


import std.core;
import mylib.functional;


export namespace mylib::inline algorithm {


    template<typename InputIterator, typename UnaryPredicate>
    inline constexpr bool all_of(InputIterator  first, InputIterator last,
                                 UnaryPredicate unaryPred) noexcept {

        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);

        while (first != last) {
            if (!unaryPred(*first)) {
                return false;
            }
            ++first;
        }
        
        return true;
    }
    
    template<typename InputIterator, typename UnaryPredicate>
    inline constexpr bool any_of(InputIterator  first, InputIterator last, 
                                 UnaryPredicate unaryPred) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);
        
        while (first != last) {
            if (unaryPred(*first)) {
                return true;
            }
            ++first;
        }

        return false;
    }

    template<typename InputIterator, typename UnaryPredicate>
    inline constexpr bool none_of(InputIterator  first, InputIterator last, 
                                  UnaryPredicate unaryPred) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);
        
        while (first != last) {
            if (unaryPred(*first)) {
                return false;
            }
            ++first;
        }

        return true;
    }

    template<typename InputIterator, typename UnaryFunction>
    inline constexpr UnaryFunction for_each(InputIterator first, InputIterator last, 
                                            UnaryFunction unaryFunc) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);
        
        while (first != last) {
            unaryFunc(*first);
            ++first;
        }

        return unaryFunc;
    }

    template<typename InputIterator, typename _Size, typename UnaryPredicate>
    inline constexpr UnaryPredicate for_each_n(InputIterator  first, _Size _Count, 
                                               UnaryPredicate unaryPred) noexcept {
        
        while (_Count--) {
            MYLIB_CHECK_ITERATOR_IS_END(first);
            
            unaryPred(*first);
            ++first;
        }

        return unaryPred;
    }

    template<typename InputIterator, typename _Type>
    inline constexpr std::iter_difference_t<InputIterator> count(
        InputIterator first, InputIterator last, 
        _Type		  _Val
    ) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);
        
        std::iter_difference_t<InputIterator> count = 0;
        while (first != last) {
            if (*first == _Val) {
                ++count;
            }
            ++first;
        }

        return count;
    }

    template<typename InputIterator, typename UnaryPredicate>
    inline constexpr std::iter_difference_t<InputIterator> count_if(
        InputIterator  first, InputIterator last, 
        UnaryPredicate unaryPred
    ) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);
        
        std::iter_difference_t<InputIterator> count = 0;
        while (first != last) {
            if (unaryPred(*first)) {
                ++count;
            }
            ++first;
        }

        return count;
    }

    template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
    inline constexpr std::pair<InputIterator1, InputIterator2> mismatch(
        InputIterator1 first1, InputIterator1   last1, 
        InputIterator2 first2, BinaryPredicate  binaryPred
    ) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first1, last1);
        
        while (first1 != last1) {
            MYLIB_CHECK_ITERATOR_IS_END(first2);
            
            if (!binaryPred(*first1, *first2)) {
                break;
            }

            ++first1;
            ++first2;
        }

        return std::make_pair(first1, first2);
    }

    template<typename InputIterator1, typename InputIterator2>
    inline constexpr std::pair<InputIterator1, InputIterator2> mismatch(
        InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2
    ) noexcept {
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first1, last1);
        
        return mylib::mismatch(first1, last1, first2, mylib::equal_to{});
    }
    
    template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
    inline constexpr std::pair<InputIterator1, InputIterator2> mismatch(
        InputIterator1  first1, InputIterator1 last1,
        InputIterator2  first2, InputIterator2 last2,
        BinaryPredicate binaryPred
    ) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first1, last1);
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first2, last2);

        while (first1 != last1 && first2 != last2) {
            if (!binaryPred(*first1, *first2)) {
                break;
            }
            ++first1;
            ++first2;
        }

        return std::make_pair(first1, first2);
    }
    
    template<typename InputIterator1, typename InputIterator2>
    inline constexpr std::pair<InputIterator1, InputIterator2> mismatch(
        InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2
    ) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first1, last1);
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first2, last2);

        return mylib::mismatch(first1, last1, first2, last2, mylib::equal_to<>());
    }
    
    template<typename InputIterator, typename _Type>
    inline constexpr InputIterator find(InputIterator first, InputIterator last, 
                                         const _Type& _Value) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);

        while (first != last) {
            if (*first == _Value) {
                break;
            }
            ++first;
            ++last;
        }

        return first;
    }

    template<typename InputIterator, typename UnaryPredicate>
    inline constexpr InputIterator find_if(InputIterator  first, InputIterator last, 
                                           UnaryPredicate unaryPred) noexcept {

        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);
        
        while (first != last) {
            if (unaryPred(*first)) {
                break;
            }
            ++first;
            ++last;
        }

        return first;
    }

    template<typename InputIterator, typename UnaryPredicate>
    inline constexpr InputIterator find_if_not(InputIterator  first, InputIterator last, 
                                               UnaryPredicate unaryPred) noexcept {

        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);
        
        while (first != last) {
            if (!unaryPred(*first)) {
                break;
            }
            ++first;
            ++last;
        }

        return first;
    }

    
    template<typename InputIterator, typename OutputIterator>
    inline constexpr OutputIterator copy(InputIterator  first, InputIterator last, 
                                         OutputIterator output) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);

        while (first != last) {
            *output = *first;
            ++first;
            ++output;
        }
        
        return output;
    }

    template<typename InputIterator, typename OutputIterator, typename UnaryPredicate>
    inline constexpr OutputIterator copy_if(
        InputIterator  first,		   InputIterator  last, 
        OutputIterator output, UnaryPredicate unaryPred
    ) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);

        while (first != last) {
            if (unaryPred(*first)) {
                *output = *first;
                ++output;
            }
            ++first;
        }
        
        return output;
    }

    template<typename ForwardIterator, typename Compare>
    inline constexpr bool is_sorted(ForwardIterator first, ForwardIterator last, 
                                    Compare			comp) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);

        if (first == last) {
            return true;
        }
        
        ForwardIterator next = first;
        ++next;
        
        while (next != last) {
            if (comp(*next, *first)) {
                return false;
            }
            ++next;
            ++first;
        }
        
        return true;
    }

    template<typename ForwardIterator>
    inline constexpr bool is_sorted(ForwardIterator first, ForwardIterator last) noexcept {		
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);
        
        return mylib::is_sorted(first, last, mylib::less{});
    }
    
    template<typename InputIterator1, typename InputIterator2, typename OutputIterator, typename Compare>
    inline constexpr OutputIterator merge(InputIterator1 first1,  InputIterator1 last1, 
                                          InputIterator2 first2,  InputIterator2 last2, 
                                          OutputIterator output,  Compare		 comp) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first1, last1);
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first2, last2);
        
        for (; ; ++output) {
            if (first1 == last1) {
                return mylib::copy(first2, last2, output);
            } else if (first2 == last2) {
                return mylib::copy(first1, last1, output);
            } else if (comp(*first2, *first1)) {
                *output = *first2;
                ++first2;
            } else {
                *output = *first1;
                ++first1;
            }
        }
    }

    template<typename InputIterator1, typename InputIterator2, typename OutputIterator>
    inline constexpr OutputIterator merge(InputIterator1 first1, InputIterator1 last1,
                                          InputIterator2 first2, InputIterator2 last2,
                                          OutputIterator output) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first1, last1);
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first2, last2);

        return mylib::merge(first1, last1, first2, last2, mylib::less{});
    }
    
    template<typename ForwardIterator, typename Compare>
    inline constexpr void inplace_merge(ForwardIterator first, ForwardIterator middle, 
                                        ForwardIterator last,  Compare		   comp) noexcept {
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, middle);
        
        using move_iter1 = std::move_iterator<ForwardIterator>;
        
        std::vector auxiliarySpace(move_iter1{ first }, move_iter1{ middle });

        using move_iter2 = std::move_iterator<typename decltype(auxiliarySpace)::iterator>;

        auto middleIndex = auxiliarySpace.size();
        auxiliarySpace.insert(auxiliarySpace.end(), move_iter1{ middle }, move_iter1{ last });
        auto last        = move_iter2{ auxiliarySpace.end() };
        auto middle		 = move_iter2{ auxiliarySpace.begin() + middleIndex };
        
        mylib::merge(move_iter2{ auxiliarySpace.begin() }, middle, middle, last, first, comp);
    }

    template<typename _BidirectionalIterator>
    inline constexpr void inplace_merge(_BidirectionalIterator first, _BidirectionalIterator middle, 
                                        _BidirectionalIterator last) noexcept {	
        
        MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(first, last);

        mylib::inplace_merge(first, middle, last, mylib::less{});
    }
}
