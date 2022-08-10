module;

#include "mylib_assert.h"

#ifdef __INTELLISENSE__

#include <utility>
#include <iterator>

#endif

export module mylib.link_list;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.iterator;
import mylib.algorithm;
import mylib.functional;
import mylib.container_traits;


export namespace mylib::inline link_list {
    
    template<typename ElementType>
    class compressive_list;
    
    template<typename ElementType>
    struct compresive_list_node;

    template<typename ValueType>
    struct compressive_pointer {
        using value_type	= ValueType;
        using pointer       = value_type*;
        using const_pointer = const value_type*;
        
        constexpr compressive_pointer(const_pointer pointer) noexcept : 
            compressedPointer{ reinterpret_cast<size_t>(pointer) } {}
        
        constexpr compressive_pointer(const_pointer prior, const_pointer next) noexcept :
            compressedPointer{ reinterpret_cast<size_t>(prior) ^ reinterpret_cast<size_t>(next) } {}

        constexpr compressive_pointer& operator =(pointer pointer) noexcept {
            compressedPointer = reinterpret_cast<size_t>(pointer);
            
            return *this;
        }
        
        constexpr pointer       get_another(pointer one)       const noexcept {
            return reinterpret_cast<pointer>(compressedPointer ^ reinterpret_cast<size_t>(one));
        }

        constexpr const_pointer get_another(const_pointer one) const noexcept {
            return reinterpret_cast<const_pointer>(compressedPointer ^ reinterpret_cast<size_t>(one));
        }       

        pointer to_pointer() const noexcept {
            return reinterpret_cast<pointer>(compressedPointer);
        }

        constexpr compressive_pointer  operator ^ (compressive_pointer compressivePointer) const noexcept {
            return compressive_pointer{ compressedPointer ^ compressivePointer.compressedPointer };
        }
        
        constexpr compressive_pointer& operator ^=(compressive_pointer compressivePointer) noexcept {
            compressedPointer ^= compressivePointer.compressedPointer;
            
            return *this;
        }
        
        size_t compressedPointer;
    };
    
    template<typename ElementType>
    struct compresive_list_head_node {
        using node_type          = compresive_list_node<ElementType>;
        using node_pointer       = node_type*;
        using const_node_pointer = const node_type*;

        operator node_pointer() noexcept {
            return reinterpret_cast<node_pointer>(this->compressedPointer.compressedPointer);
        }
        
        constexpr node_pointer       get_another(node_pointer one)        const noexcept {
            return compressedPointer.get_another(one);
        }

        constexpr const_node_pointer get_another(const_node_pointer one) const noexcept {
            return compressedPointer.get_another(one);
        }

        node_pointer to_pointer() const noexcept {
            return compressedPointer.to_pointer();
        }
        
        compressive_pointer<node_type> compressedPointer{};
    };
        
    template<typename ElementType>
    struct compresive_list_node : public compresive_list_head_node<ElementType> {
        using node_type          = compresive_list_node;
        using node_pointer       = node_type*;
        using const_node_pointer = const node_type*;

        using base_type          = compresive_list_head_node<ElementType>;

        constexpr compresive_list_node() noexcept = default;
        
        constexpr compresive_list_node(const node_type&) noexcept = delete;

        constexpr compresive_list_node(
            const ElementType&  data, const_node_pointer prior  = nullptr, 
            const_node_pointer  next = nullptr
        ) noexcept: 
            data{ data }, base_type{ compressive_pointer<node_type>{ prior, next } } 
        {}
        
        constexpr compresive_list_node(
            ElementType&& data, const_node_pointer prior, 
            const_node_pointer next
        ) noexcept : 
            data{ std::move(data) }, 
            base_type{ compressive_pointer<node_type>{ prior, next } } 
        {}

        node_pointer to_pointer() const noexcept = delete;
        
        constexpr node_type& operator =(const node_type&) noexcept = delete;
        
        ElementType data;
    };

    

    template<typename _CompressiveListType>
    struct compressive_list_const_iterator {
        using value_type         = typename _CompressiveListType::value_type;

        using difference_type    = typename _CompressiveListType::difference_type;

        using reference          = typename _CompressiveListType::reference;
        using const_reference    = typename _CompressiveListType::const_reference;

        using pointer            = typename _CompressiveListType::pointer;
        using const_pointer      = typename _CompressiveListType::const_pointer;

        using node_pointer       = typename _CompressiveListType::node_pointer;
        using const_node_pointer = typename _CompressiveListType::const_node_pointer;

        using container_type     = _CompressiveListType;

        using mylib_tag          = mylib_iterator_tag;

        using iterator_category  = bidirectional_iterator_tag;

        constexpr compressive_list_const_iterator(
            const_node_pointer prior = nullptr, const_node_pointer current = nullptr
            MYLIB_OPTION_CONTAINER_POINTER_PARAMETER
        ) noexcept :
            pPrior{ prior }, pCurrent{ current } MYLIB_OPTION_CONTAINER_POINTER_INITIALIZE
        {}

        constexpr const_reference operator  *() const noexcept {
            MYLIB_CHECK_ITERATOR_IS_END(*this);
            
            return pCurrent->data;
        }

        constexpr const_pointer   operator ->() const noexcept {
            return &pCurrent->data;
        }

        constexpr compressive_list_const_iterator& operator ++()    noexcept {
            MYLIB_CHECK_ITERATOR_IS_END(*this);
            
            auto pNext   = pCurrent->get_another(pPrior);
            pPrior       = pCurrent;
            pCurrent     = pNext;
            
            return *this;
        }

        constexpr compressive_list_const_iterator  operator ++(int) noexcept {
            MYLIB_CHECK_ITERATOR_IS_END(*this);
            
            auto old = *this;
            ++*this;
            
            return old;
        }

        constexpr compressive_list_const_iterator& operator --() noexcept {
            MYLIB_CHECK_ITERATOR_IS_BEGIN(*this);
            
            auto pLast   = pPrior->get_another(pCurrent);
            pPrior       = pCurrent;
            pCurrent     = pLast;
            
            return *this;
        }

        constexpr compressive_list_const_iterator  operator --(int) noexcept {
            MYLIB_CHECK_ITERATOR_IS_BEGIN(*this);
            
            auto old = *this;
            --*this;
            
            return old;
        }

        constexpr bool operator ==(
            const compressive_list_const_iterator& right
        ) const noexcept {
            
            MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(*this, right);
            
            return pCurrent == right.pCurrent;
        }

        constexpr void reverse() noexcept {
            pPrior = pCurrent->get_another(pPrior);
        }

        MYLIB_OPTION_CONTAINER_POINTER;
        const_node_pointer pPrior;
        const_node_pointer pCurrent;
    };

        template<typename _CompressiveListType>
    struct compressive_list_iterator :
        public compressive_list_const_iterator<_CompressiveListType> {
        
        using value_type         = typename _CompressiveListType::value_type;

        using difference_type    = typename _CompressiveListType::difference_type;

        using reference          = typename _CompressiveListType::reference;
        using const_reference    = typename _CompressiveListType::const_reference;

        using pointer            = typename _CompressiveListType::pointer;
        using const_pointer      = typename _CompressiveListType::const_pointer;

        using node_pointer       = typename _CompressiveListType::node_pointer;
        using const_node_pointer = typename _CompressiveListType::const_node_pointer;
        
        using base_type          = compressive_list_const_iterator<_CompressiveListType>;

        using container_type     = _CompressiveListType;

        using mylib_tag          = mylib_iterator_tag;
        
        using iterator_category  = bidirectional_iterator_tag;

        constexpr compressive_list_iterator(
            node_pointer prior = nullptr, node_pointer current = nullptr
            MYLIB_OPTION_CONTAINER_POINTER_PARAMETER
        ) noexcept :
            base_type{ prior, current MYLIB_OPTION_CONTAINER_POINTER_ARGUMENT }
        {};

        constexpr reference operator  *() const noexcept {
            MYLIB_CHECK_ITERATOR_IS_END(*this);
            
            return const_cast<reference>(base_type::operator *());
        }

        constexpr pointer   operator ->() const noexcept {
            return reinterpret_cast<pointer>(base_type:: operator ->());
        }

        constexpr compressive_list_iterator& operator ++()    noexcept {
            MYLIB_CHECK_ITERATOR_IS_END(*this);
            
            base_type::operator ++();
            
            return *this;
        }

        constexpr compressive_list_iterator  operator ++(int) noexcept {
            MYLIB_CHECK_ITERATOR_IS_END(*this);
            
            auto old = *this;
            base_type::operator ++();

            return old;
        }

        constexpr compressive_list_iterator& operator --() noexcept {
            MYLIB_CHECK_ITERATOR_IS_BEGIN(*this);
            
            base_type::operator --();
            
            return *this;
        }

        constexpr compressive_list_iterator  operator --(int) noexcept {
            MYLIB_CHECK_ITERATOR_IS_BEGIN(*this);
            
            auto old = *this;
            base_type::operator --();
            
            return old;
        }
    };
    
    template<typename ElementType>
    class compressive_list {
    public:
        using size_type               = size_t;
        using difference_type         = ptrdiff_t;
        
        using value_type              = ElementType;
        using reference               = value_type&;
        using const_reference         = const value_type&;
        using pointer                 = value_type*;
        using const_pointer           = const value_type*;
        
        using head_node               = compresive_list_head_node<value_type>;
        using head_node_pointer       = head_node*;
        using const_head_node_pointer = const head_node*;
        using node_type               = compresive_list_node<ElementType>;
        using node_pointer            = node_type*;
        using const_node_pointer      = const node_type*;
        
        using iterator                = compressive_list_iterator<compressive_list>;
        using const_iterator          = compressive_list_const_iterator<compressive_list>;
        using reverse_iterator        = std::reverse_iterator<iterator>;
        using const_reverse_iterator  = std::reverse_iterator<const_iterator>;
        
        using mylib_tag               = mylib_container_tag;
        
        constexpr compressive_list()  = default;

        constexpr compressive_list(const compressive_list& other) noexcept {
            insert(cbegin(), other.begin(), other.end());
        }

        constexpr compressive_list(compressive_list&& other) noexcept {
            head = other.head;
            tail = other.tail;
            auto* pFirstNode               = head.compressedPointer.to_pointer();
            auto* pLastNode                = tail.compressedPointer.to_pointer();
            pFirstNode->compressedPointer ^= make_node_pointer(&other.head);
            pFirstNode->compressedPointer ^= make_node_pointer(&head);
            pLastNode ->compressedPointer ^= make_node_pointer(&other.tail);
            pLastNode ->compressedPointer ^= make_node_pointer(&tail);
            new (&other.head) head_node();
        }
        
        template<std::input_iterator InputIterator>
        constexpr compressive_list(InputIterator first, InputIterator last) noexcept {
            insert(cbegin(), first, last);
        }

        constexpr compressive_list(std::initializer_list<ElementType> initializerList) :
            compressive_list(initializerList.begin(), initializerList.end())
        {}
        
        constexpr ~compressive_list() noexcept {
            clear();
        }
        
        void push_front(const ElementType& value) noexcept {
            auto* pNewNode = 
                new node_type{ value, make_node_pointer(&head), head.to_pointer() };
            
            auto& firstNode              = *head.compressedPointer.to_pointer();
            firstNode.compressedPointer ^= make_node_pointer(&head); // now it is containing it's next node pointer
            firstNode.compressedPointer ^= pNewNode;                 // then compresive newNodePointer and next node pointer
            head.compressedPointer       = pNewNode;
            ++nodeSize;
        }

        void push_front(ElementType&& value) noexcept {
            auto* pNewNode = 
                new node_type{ std::move(value), make_node_pointer(&head), head.to_pointer() };
            
            auto& firstNode              = *head.compressedPointer.to_pointer();
            firstNode.compressedPointer ^= make_node_pointer(&head); // now it is containing it's next node pointer
            firstNode.compressedPointer ^= pNewNode;                 // then compresive newNodePointer and next node pointer
            head.compressedPointer       = pNewNode;
            ++nodeSize;
        }
        
        void push_back(const ElementType& value) noexcept {
            auto  pNewNode = 
                new node_type{ value, tail.to_pointer(), make_node_pointer(&tail)};
            
            auto& lastNode               = *tail.compressedPointer.to_pointer();
            lastNode.compressedPointer  ^= make_node_pointer(&tail); // now it is containing it's last node pointer
            lastNode.compressedPointer  ^= pNewNode;                 // then compresive newNodePointer and last node pointer
            tail.compressedPointer       = pNewNode;
            ++nodeSize;
        }

        void push_back(ElementType&& value) noexcept {
            auto  pNewNode = 
                new node_type{ std::move(value), tail.to_pointer(), make_node_pointer(&tail) };
            
            auto& lastNode               = *tail.compressedPointer.to_pointer();
            lastNode.compressedPointer  ^= make_node_pointer(&tail); // now it is containing it's last node pointer
            lastNode.compressedPointer  ^= pNewNode;                 // then compresive newNodePointer and last node pointer
            tail.compressedPointer       = pNewNode;
            ++nodeSize;
        }

        void pop_front() noexcept {
            MYLIB_CHECK_CONTAINER_IS_EMPTY(*this);
            
            --nodeSize;
            auto* pFirstNode              = head.compressedPointer.to_pointer();
            auto* pNextNode               = pFirstNode->get_another(make_node_pointer(&head));
            pNextNode->compressedPointer ^= pFirstNode;
            pNextNode->compressedPointer ^= make_node_pointer(&head);
            delete pFirstNode;
            head.compressedPointer        = pNextNode;
        }

        void pop_back() noexcept {
            MYLIB_CHECK_CONTAINER_IS_EMPTY(*this);
            
            --nodeSize;
            auto* pLastNode                = tail.compressedPointer.to_pointer();
            auto* pPriorNode               = pLastNode->get_another(make_node_pointer(&tail));
            pPriorNode->compressedPointer ^= pLastNode;
            pPriorNode->compressedPointer ^= make_node_pointer(&tail);
            delete pLastNode;
            tail.compressedPointer         = pPriorNode;
        }

        reference front() noexcept {
            MYLIB_CHECK_CONTAINER_IS_EMPTY(*this);          
            
            return head.compressedPointer.to_pointer()->data;
        }

        const_reference front() const noexcept {
            MYLIB_CHECK_CONTAINER_IS_EMPTY(*this);
            
            return head.compressedPointer.to_pointer()->data;
        }

        reference back() noexcept {
            MYLIB_CHECK_CONTAINER_IS_EMPTY(*this);
            
            return tail.compressedPointer.to_pointer()->data;
        }

        const_reference back() const noexcept {
            MYLIB_CHECK_CONTAINER_IS_EMPTY(*this);
            
            return tail.compressedPointer.to_pointer()->data;
        }

        iterator insert(const_iterator where, const ElementType& value) noexcept {
            MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(cbegin(), where);
            
            return {
                const_cast<node_pointer>(where.pPrior),
                insert_between(
                    const_cast<node_pointer>(where.pPrior),
                    const_cast<node_pointer>(where.pCurrent), 
                    value
                )
                MYLIB_OPTION_ARGUMENT(this)
            };
        }
        
        iterator insert(const_iterator where, ElementType&& value) noexcept {
            MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(cbegin(), where);
            
            return {
                const_cast<node_pointer>(where.pPrior),
                insert_between(
                    const_cast<node_pointer>(where.pPrior),
                    const_cast<node_pointer>(where.pCurrent), 
                    std::move(value)
                )
                MYLIB_OPTION_ARGUMENT(this)
            };
        }

        iterator insert(const_iterator where, size_type _Count, const ElementType& value) noexcept {
            
            MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(cbegin(), where);
            
            while (_Count--) {
                where = insert(where, value);
            }

            return {
                const_cast<node_pointer>(where.pPrior),
                const_cast<node_pointer>(where.pCurrent)
                MYLIB_OPTION_ARGUMENT(this)
            };
        }
        
        iterator insert(const_iterator where, size_type _Count, ElementType&& value) noexcept {
            
            MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(cbegin(), where);
            
            while (_Count--) {
                where = insert(where, std::move(value));
            }

            return {
                const_cast<node_pointer>(where.pPrior),
                const_cast<node_pointer>(where.pCurrent)
                MYLIB_OPTION_ARGUMENT(this)
            };
        }

        template <std::input_iterator InputIterator>
        iterator insert(const_iterator where, InputIterator first, InputIterator last) noexcept {

            MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(cbegin(), where);
            
            while (first != last) {
                where = insert(where, *first);
                ++where;
                ++first;
            }

            return{
                const_cast<node_pointer>(where.pPrior),
                const_cast<node_pointer>(where.pCurrent)
                MYLIB_OPTION_ARGUMENT(this)
            };
        }

        iterator insert(const_iterator where, std::initializer_list<ElementType> initializerList) noexcept {
            MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(cbegin(), where);
            
            insert(where, initializerList.begin(), initializerList.end());
        }

        iterator erase(const_iterator where) noexcept {
            MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(cbegin(), where);
            MYLIB_CHECK_ITERATOR_IS_END(where);
            
            --nodeSize;
            
            auto* pPriorNode   = const_cast<node_pointer>(where.pPrior);
            auto* pCurrentNode = const_cast<node_pointer>(where.pCurrent);
            auto* pNextNode    = pCurrentNode->get_another(pPriorNode);

            pPriorNode->compressedPointer ^= pCurrentNode;
            pPriorNode->compressedPointer ^= pNextNode;
            pNextNode ->compressedPointer ^= pCurrentNode;
            pNextNode ->compressedPointer ^= pPriorNode;

            delete pCurrentNode;

            return { pPriorNode, pNextNode MYLIB_OPTION_ARGUMENT(this) };
        }

        iterator erase(const_iterator first, const_iterator last) noexcept {
            MYLIB_CHECK_ITERATOR_CONTAINER_IS_SAME(cbegin(), first);
            
            while (first != last) {
                first = erase(first);
            }

            return { 
                const_cast<node_pointer>(first.pPrior), 
                const_cast<node_pointer>(first.pCurrent) 
                MYLIB_OPTION_ARGUMENT(this) 
            };
        }

        void reverse() noexcept {
            auto* pFirstNode               = head.compressedPointer.to_pointer();
            auto* pLastNode                = tail.compressedPointer.to_pointer();
            pFirstNode->compressedPointer ^= make_node_pointer(&head);
            pFirstNode->compressedPointer ^= make_node_pointer(&tail);
            pLastNode ->compressedPointer ^= make_node_pointer(&tail);
            pLastNode ->compressedPointer ^= make_node_pointer(&head);
            std::swap(head, tail);
        }
        
        void swap(compressive_list& other) noexcept {
            std::swap(head, other.head);
            std::swap(tail, other.tail);
            std::swap(nodeSize, other.nodeSize);
            
            auto* pFirstNode               = head.compressedPointer.to_pointer();
            auto* pLastNode                = tail.compressedPointer.to_pointer();
            pFirstNode->compressedPointer ^= make_node_pointer(&other.head);
            pFirstNode->compressedPointer ^= make_node_pointer(&head);
            pLastNode ->compressedPointer ^= make_node_pointer(&other.tail);
            pLastNode ->compressedPointer ^= make_node_pointer(&tail);
            
            pFirstNode                     = other.head.compressedPointer.to_pointer();
            pLastNode                      = other.tail.compressedPointer.to_pointer();
            pFirstNode->compressedPointer ^= make_node_pointer(&head);
            pFirstNode->compressedPointer ^= make_node_pointer(&other.head);
            pLastNode ->compressedPointer ^= make_node_pointer(&tail);
            pLastNode ->compressedPointer ^= make_node_pointer(&other.tail);
        }

        template<typename BinaryPredicate>
        void unique(BinaryPredicate binaryPred) noexcept {
            if (size() <= 1) {
                return;
            }
            
            for (auto temp = cbegin(), i = ++temp, last = cend(); i != last;) {
                if (binaryPred(*temp, *i)) {
                    i = erase(i);
                } else {
                    temp = i;
                    ++i;
                }
            }
        }
        
        void unique() noexcept {
            unique(mylib::equal_to{});
        }

        void clear() noexcept {
            erase(cbegin(), cend());
        }
        
        iterator begin() noexcept {
            return { 
                make_node_pointer(&head), 
                head.compressedPointer.to_pointer() 
                MYLIB_OPTION_ARGUMENT(this) 
            };
        }

        iterator end()   noexcept {
            return { 
                tail.compressedPointer.to_pointer(), 
                make_node_pointer(&tail) 
                MYLIB_OPTION_ARGUMENT(this) 
            };
        }

        const_iterator begin() const noexcept {
            return { 
                make_node_pointer(&head), 
                head.compressedPointer.to_pointer() 
                MYLIB_OPTION_ARGUMENT(this) 
            };
        }

        const_iterator end()   const noexcept {
            return { 
                tail.compressedPointer.to_pointer(), 
                make_node_pointer(&tail) 
                MYLIB_OPTION_ARGUMENT(this) 
            };
        }

        const_iterator cbegin() const noexcept {
            return begin();
        }

        const_iterator cend()   const noexcept {
            return end();
        }

        iterator rbegin() noexcept {
            return { 
                make_node_pointer(&tail), 
                tail.compressedPointer.to_pointer() 
                MYLIB_OPTION_ARGUMENT(this) 
            };
        }

        iterator rend()   noexcept {
            return { 
                head.compressedPointer.to_pointer(),
                make_node_pointer(&head) 
                MYLIB_OPTION_ARGUMENT(this) 
            };
        }

        const_iterator rbegin() const noexcept {
            return { 
                make_node_pointer(&tail), 
                tail.compressedPointer.to_pointer() 
                MYLIB_OPTION_ARGUMENT(this) 
            };
        }

        const_iterator rend()   const noexcept {
            return { 
                head.compressedPointer.to_pointer(), 
                make_node_pointer(&head) 
                MYLIB_OPTION_ARGUMENT(this)
            };
        }

        const_iterator crbegin() const noexcept {
            return rbegin();
        }

        const_iterator crend()   const noexcept {
            return rend();
        }
        
        size_type size() const noexcept {
            return nodeSize;
        }

        bool empty() const noexcept {
            return nodeSize == 0;
        }
        
    private:
        constexpr node_pointer insert_between(node_pointer prior, node_pointer last, node_pointer newNode) noexcept {
            prior  ->compressedPointer ^= last;
            prior  ->compressedPointer ^= newNode;
            last   ->compressedPointer ^= prior;
            last   ->compressedPointer ^= newNode;
            newNode->compressedPointer ^= prior;
            newNode->compressedPointer ^= last;
            
            ++nodeSize;
            
            return newNode;
        }

        constexpr node_pointer insert_between(node_pointer prior, node_pointer last, const ElementType& value) noexcept {
            return insert_between(prior, last, new node_type{ value });
        }

        constexpr node_pointer insert_between(node_pointer prior, node_pointer last, ElementType&& value) noexcept {
            return insert_between(prior, last, new node_type{ std::move(value) });
        }
        
        constexpr node_pointer make_node_pointer(const_head_node_pointer pointer) const noexcept {
            return reinterpret_cast<node_pointer>(const_cast<head_node_pointer>(pointer));
        }
        
        head_node head    { make_node_pointer(&tail) };
        head_node tail    { make_node_pointer(&head) };
        size_type nodeSize{};
    };
}
