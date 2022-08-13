module;

#ifdef __INTELLISENSE__

#include <memory>
#include <iterator>

#endif

export module mylib.list;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.iterator;

export namespace mylib {

    template<typename ElementType>
    struct list_node;

    template<typename ElementType>
    struct head_node {
        using node_type    = list_node<ElementType>;
        using node_pointer = node_type*;

        constexpr head_node(node_pointer prior, node_pointer next) noexcept :
            prior{ prior }, next{ next } {}

        constexpr head_node() noexcept                             = default;
        
        constexpr head_node(const head_node&) noexcept             = delete;
            
        constexpr head_node& operator =(const head_node&) noexcept = delete;

        node_pointer next { nullptr };
        node_pointer prior{ nullptr };
    };

    template<typename ElementType>
    struct list_node : 
        head_node<ElementType> 
    {
        using head_node<ElementType>::next;
        using head_node<ElementType>::prior;

        constexpr list_node(list_node&& other) noexcept :
            head_node<ElementType>{ other.prior, other.next }, data{ std::move(other.data) } {
            
            other.next  = nullptr;
            other.prior = nullptr;
        }
        
        constexpr list_node(const list_node&) noexcept = delete;
        
        constexpr list_node() noexcept : data{}, prior{ nullptr }, next{ nullptr } {}
        
        constexpr list_node(const ElementType& data, list_node* prior, list_node* next) noexcept :
            data{ data }, head_node<ElementType>{ prior, next } {}

        constexpr list_node(ElementType&& data, list_node* prior, list_node* next) noexcept :
            data{ std::move(data) }, head_node<ElementType>{ prior, next } {}

        list_node& operator =(const list_node&) noexcept = delete;
        
        ElementType data;
    };

    template<typename ListType>
    struct list_const_iterator {
        using value_type        = typename ListType::value_type;
        
        using difference_type   = typename ListType::difference_type;
        
        using reference         = typename ListType::reference;
        using const_reference   = typename ListType::const_reference;
        
        using pointer           = typename ListType::pointer;
        using const_pointer     = typename ListType::const_pointer;
        
        using iterator_category = mylib::bidirectional_iterator_tag;
        
        constexpr list_const_iterator() noexcept : node{} {}
        
        constexpr list_const_iterator(typename ListType::node_pointer pNode) noexcept : node{ pNode } {}

        constexpr const_reference operator *() const noexcept {
            return node->data;
        }

        constexpr const_pointer operator ->() const noexcept {
            return node->data;
        }

        constexpr list_const_iterator& operator ++() noexcept {
            node = node->next;
            return *this;
        }

        constexpr list_const_iterator operator ++(int) noexcept {
            list_const_iterator temp = *this;
            node = node->next;
            return temp;
        }

        constexpr list_const_iterator& operator +=(difference_type index) noexcept {
            if (index < 0) {
                return operator -=(-index);
            }

            for (difference_type i = 0; i < index; i++) {
                ++* this;
            }

            return *this;
        }

        constexpr list_const_iterator operator +(difference_type index) noexcept {
            list_const_iterator result{ *this };
            return result;
        }


        constexpr list_const_iterator operator +(difference_type index) const noexcept {
            if (index < 0) {
                return operator -(-index);
            }

            list_const_iterator result{ *this };
            for (difference_type i = 0; i < index; i++) {
                ++result;
            }

            return result;
        }

        constexpr list_const_iterator& operator --() noexcept {
            node = node->prior;
            return *this;
        }

        constexpr list_const_iterator operator --(int) noexcept {
            list_const_iterator temp = *this;
            node = node->prior;
            return temp;
        }

        constexpr list_const_iterator& operator -=(difference_type index) noexcept {
            if (index < 0) {
                return operator +=(-index);
            }

            for (difference_type i = 0; i < index; i++) {
                --* this;
            }

            return *this;
        }

        constexpr list_const_iterator operator -(difference_type index) noexcept {
            list_const_iterator result{ *this };
            
            return result += index;
        }

        constexpr list_const_iterator operator -(difference_type index) const noexcept {
            if (index < 0) {
                return operator +(-index);
            }

            list_const_iterator result{ *this };
            for (difference_type i = 0; i < index; i++) {
                --result;
            }

            return result;
        }

        constexpr bool operator ==(list_const_iterator const& right) const noexcept {
            return node == right.node;
        }
        
        typename ListType::const_node_pointer node;
    };

    template<typename ListType>
    struct list_iterator : 
        list_const_iterator<ListType> {
        
        using value_type        = typename ListType::value_type;
        
        using difference_type   = typename ListType::difference_type;

        using reference         = typename ListType::reference;
        using const_reference   = typename ListType::const_reference;

        using pointer           = typename ListType::pointer;
        
        using base_type         = list_const_iterator<ListType>;
        
        using iterator_category = mylib::bidirectional_iterator_tag;
        
        using list_const_iterator<ListType>::node;

        constexpr reference operator *() const noexcept {
            return const_cast<reference>(node->data);
        }

        constexpr pointer operator ->() const noexcept {
            return reinterpret_cast<pointer>(node);
        }

        constexpr list_iterator& operator ++() noexcept {
            base_type:: operator ++();
            
            return *this;
        }

        constexpr list_iterator operator ++(int) noexcept {
            list_iterator temp = *this;
            base_type:: operator ++();
            
            return temp;
        }

        constexpr list_iterator& operator +=(difference_type index) noexcept {
            if (index < 0) {
                return operator -=(-index);
            }

            for (difference_type i = 0; i < index; i++) {
                ++* this;
            }

            return *this;
        }

        constexpr list_iterator operator +(difference_type index) noexcept {
            list_iterator _Result{ *this };
            return _Result += index;
        }

        constexpr list_iterator operator +(difference_type index) const noexcept {
            if (index < 0) {
                return operator -(-index);
            }

            list_iterator _Result{ *this };
            for (difference_type i = 0; i < index; i++) {
                ++_Result;
            }

            return _Result;
        }

        constexpr list_iterator& operator --() noexcept {
            base_type::operator --();
            
            return *this;
        }

        constexpr list_iterator operator --(int) noexcept {
            list_iterator temp = *this;
            base_type::operator --();
            
            return temp;
        }

        constexpr list_iterator operator -=(difference_type index) noexcept {
            if (index < 0) {
                return operator +=(-index);
            }

            for (difference_type i = 0; i < index; i++) {
                --* this;
            }

            return *this;
        }

        constexpr list_iterator operator -(difference_type index) noexcept {
            list_iterator _Result{ *this };
            return _Result += index;
        }

        constexpr list_iterator operator -(difference_type index) const noexcept {
            if (index < 0) {
                return operator +(-index);
            }

            list_iterator _Result{ *this };
            for (difference_type i = 0; i < index; i++) {
                --_Result;
            }

            return _Result;
        }
    };

    template<typename ElementType, typename Allocator = std::allocator<ElementType>>
    class list {
    public:
        using size_type              = typename std::allocator_traits<Allocator>::size_type;

        using value_type             = ElementType;

        using allocator_type         = Allocator;

        using reference              = value_type&;

        using const_reference        = const value_type&;

        using difference_type        = typename std::allocator_traits<Allocator>::difference_type;

        using pointer                = typename std::allocator_traits<Allocator>::pointer;
        using const_pointer          = typename std::allocator_traits<Allocator>::const_pointer;

        using iterator               = list_iterator<list<value_type, Allocator>>;
        using reverse_iterator       = typename std::reverse_iterator<iterator>;
        using const_iterator         = list_const_iterator<list<value_type, Allocator>>;
        using const_reverse_iterator = typename std::reverse_iterator<const_iterator>;

        using node_type              = list_node<value_type>;
        using node_pointer           = node_type*;
        using const_node_pointer     = const node_type*;
        using head_node_type         = head_node<value_type>;

    public:
        constexpr list() noexcept = default;

        constexpr explicit list(list const& other) noexcept {
            for (const value_type& i : other) {
                push_back(i);
            }
        }

        constexpr explicit list(list&& right) noexcept {
            if (right.size() != 0) {
                headNode.next         = right.headNode.next;
                headNode.prior        = right.headNode.prior;
                headNode.next->prior  = make_list_node_ptr(&headNode);
                headNode.prior->next  = make_list_node_ptr(&headNode);
                numOfNode             = right.numOfNode;
                right.headNode.next  = make_list_node_ptr(&right.headNode);
                right.headNode.prior = make_list_node_ptr(&right.headNode);
                right.numOfNode      = 0;
            }
        }

        constexpr list(std::initializer_list<value_type> initialValueList) noexcept {
            for (const value_type& i : initialValueList) {
                push_back(std::move(i));
            }
        }

        constexpr ~list() noexcept {
            auto const e = end();
            for (auto i = begin(); i != e;) {
                delete (i++).node;
            }
        }

        constexpr list& operator =(const list& right) noexcept {
            if (this != &right) {
                clear();
                new (this) list(right);
            }

            return *this;
        }
        
        constexpr list& operator =(list&& right) noexcept {
            if (this != &right) {
                clear();
                new (this) list(std::move(right));
            }

            return *this;
        }
        
        constexpr void swap(list& right) noexcept {
            std::swap(numOfNode,      right.numOfNode);
            std::swap(headNode.next,  right.headNode.next);
            std::swap(headNode.prior, right.headNode.prior);
        }

        constexpr void push_back(value_type&& value) noexcept {
            headNode.prior->next = 
                ::new node_type{ 
                    std::move(value), 
                    headNode.prior, 
                    make_list_node_ptr(&headNode) 
                };
            
            headNode.prior = headNode.prior->next;
            numOfNode++;
        }

        constexpr void push_back(const value_type& value) noexcept {
            headNode.prior->next = 
                ::new node_type{ 
                    value, headNode.prior, 
                    make_list_node_ptr(&headNode) 
                };
            
            headNode.prior = headNode.prior->next;
            numOfNode++;
        }

        constexpr void push_front(value_type&& value) noexcept {
            headNode.next->prior = 
                ::new node_type{ 
                    std::move(value), 
                    make_list_node_ptr(&headNode), 
                    headNode.next 
                };
            
            headNode.next = headNode.next->prior;
            numOfNode++;
        }

        constexpr void push_front(const value_type& value) noexcept {
            headNode.next->prior = 
                ::new node_type{ 
                    value, 
                    make_list_node_ptr(&headNode), 
                    headNode.next
                };
            
            headNode.next = headNode.next->prior;
            numOfNode++;
        }

        constexpr void pop_back() noexcept {
            numOfNode--;
            headNode.prior->prior->next = &headNode;
            auto temp                   = headNode.prior;
            headNode.prior              = headNode.prior->prior;
            delete temp;
        }

        constexpr void pop_front() noexcept {
            numOfNode--;
            headNode.next->next->prior = &headNode;
            auto temp                  = headNode.next;
            headNode.next              = headNode.next->next;
            delete temp;
        }

        constexpr const value_type& back() const noexcept {
            return headNode.prior->data;
        }

        constexpr const value_type& front() const noexcept {
            return headNode.next->data;
        }

        constexpr iterator insert(const_iterator where, value_type&& value) noexcept {
            where.node->prior->next = ::new node_type{ std::move(value), where.node->prior, where.node };
            where.node->prior       = where.node->prior->next;
            numOfNode++;

            return iterator{ where.node->prior };
        }

        constexpr iterator insert(const_iterator where, const value_type& value) noexcept {
            where.node->prior->next = ::new node_type{ value, where.node->prior, where.node };
            where.node->prior       = where.node->prior->next;
            numOfNode++;

            return iterator{ where.node->prior };
        }

        constexpr iterator erase(const_iterator where) noexcept {
            numOfNode--;
            auto const temp           = where.node->next;
            where.node->prior->next = where.node->next;
            where.node->next->prior = where.node->prior;
            ::delete where.node;

            return iterator{ temp };
        }

        constexpr iterator erase(const_iterator first, const_iterator last) noexcept {
            first.node->prior->next = last.node;
            last.node->prior        = first.node->prior;
            for (auto i = first; i != last; ) {
                numOfNode--;
                ::delete (i++).node;
            }

            return iterator{ first.node->prior };
        }

        constexpr const_iterator find(iterator first, const value_type& value) const noexcept {
            auto const e = end();
            for (auto i = first; i != e; i++) {
                if (*i == value) {
                    return i;
                }
            }

            return const_iterator{ headNode.next->prior };
        }

        constexpr value_type& operator [](size_type index) noexcept {
            return *(begin() + index);
        }

        constexpr const value_type& operator [](size_type index) const noexcept {
            return *(begin() + index);
        }

        constexpr iterator find(iterator _First, iterator last, const value_type& value) noexcept {
            return std::find(_First, last, value);
        }

        constexpr const_iterator find(const_iterator _First, const_iterator last, const value_type& value) const noexcept {
            return std::find(_First, last, value);
        }

        template<typename UnaryPredicate>
        constexpr iterator find_if(iterator _First, iterator last, UnaryPredicate pred) noexcept {
            return std::find_if(_First, last, pred);
        }

        template<typename UnaryPredicate>
        constexpr const_iterator find_if(const_iterator _First, const_iterator last, UnaryPredicate pred) const noexcept {
            return std::find_if(_First, last, pred);
        }

        constexpr size_type remove(const value_type& value) noexcept {
            iterator head{ begin() };
            size_type firstSize{ numOfNode };
            while (true) {
                head = find(head, end(), value);
                if (head != end()) {
                    erase(head);
                } else {
                    break;
                }
            }
            return firstSize - numOfNode;
        }

        template<typename UnaryPredicate>
        constexpr size_type remove_if(UnaryPredicate pred) noexcept {
            iterator head{ begin() };
            size_type firstSize{ numOfNode };
            while (true) {
                head = find_if(head, end(), pred);
                if (head != end()) {
                    erase(head);
                } else {
                    break;
                }
            }
            return firstSize - numOfNode;
        }

        constexpr void clear() noexcept {
            erase(cbegin(), cend());
        }

        constexpr void resize(size_type count) noexcept {
            if (count < numOfNode) {
                iterator head{ begin() };
                erase(head, head + numOfNode - count);
            } else if (count > numOfNode) {
                for (size_type i{ 0 }, newCount{ count - numOfNode }; i < newCount; i++) {
                    push_back(std::move(value_type{}));
                }
            }
        }

        constexpr void resize(size_type count, const value_type& value) noexcept {
            if (count < numOfNode) {
                iterator head{ begin() };
                erase(head, head + numOfNode - count);
            } else if (count > numOfNode) {
                    for (size_type i{ 0 }, newCount{ count - numOfNode }; i < newCount; i++) {
                    push_back(value);
                }
            }
        }

        constexpr size_type size() const noexcept {
            return numOfNode;
        }

        constexpr bool empty() const noexcept {
            return size() == size_type{ 0 };
        }

        constexpr iterator begin() noexcept {
            return iterator{ headNode.next };
        }

        constexpr const_iterator begin() const noexcept {
            return cbegin();
        }

        constexpr const_iterator cbegin() const noexcept {
            return const_iterator{ headNode.next };
        }

        constexpr reverse_iterator rbegin() noexcept {
            return reverse_iterator{ end() };
        }

        constexpr const_reverse_iterator rbegin() const noexcept {
            return crbegin();
        }

        constexpr const_reverse_iterator crbegin() const noexcept {
            return const_reverse_iterator{ cend() };
        }

        constexpr iterator end() noexcept {
            return iterator{ make_list_node_ptr(&headNode) };
        }

        constexpr const_iterator end() const noexcept {
            return const_iterator{ make_list_node_ptr(&headNode) };
        }

        constexpr const_iterator cend() const noexcept {
            return end();
        }

        constexpr reverse_iterator rend() noexcept {
            return reverse_iterator{ begin() };
        }

        constexpr const_reverse_iterator rend() const noexcept {
            return crend();
        }

        constexpr const_reverse_iterator crend() const noexcept {
            return const_reverse_iterator{ cbegin() };
        }

    private:
        template<typename ElementType>
        constexpr static list_node<ElementType>* make_list_node_ptr(
            head_node<ElementType> const* source) noexcept {
            
            return 
                reinterpret_cast<list_node<ElementType>*>(
                    const_cast<head_node<ElementType>*>(source)
                );
        }

    private:
        size_type      numOfNode{};
        head_node_type headNode { make_list_node_ptr(&headNode), make_list_node_ptr(&headNode) };
    };
}
