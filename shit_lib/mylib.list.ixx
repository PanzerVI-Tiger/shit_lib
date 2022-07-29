export module mylib.list;

import std.core;


export namespace mylib {

    template<typename _ElementType>
    struct list_node;

    template<typename _ElementType>
    struct head_node {
        using node_type     = list_node<_ElementType>;
        using node_pointer  = node_type*;

        constexpr head_node(node_pointer _Prior, node_pointer _Next) noexcept :
            prior{ _Prior }, next{ _Next } {}

        constexpr head_node() noexcept                             = default;
        
        constexpr head_node(const head_node&) noexcept             = delete;
            
        constexpr head_node& operator =(const head_node&) noexcept = delete;

        node_pointer next { nullptr };
        node_pointer prior{ nullptr };
    };

    template<typename _ElementType>
    struct list_node : head_node<_ElementType> {
        using head_node<_ElementType>::next;
        using head_node<_ElementType>::prior;

        constexpr list_node(list_node&& _Other) noexcept :
            head_node<_ElementType>{ _Other.prior, _Other.next }, data{ std::move(_Other.data) } {
            
            _Other.next  = nullptr;
            _Other.prior = nullptr;
        }
        
        constexpr list_node(const list_node&) noexcept = delete;
        
        constexpr list_node() noexcept : data{}, prior{ nullptr }, next{ nullptr } {}
        
        constexpr list_node(const _ElementType& _Data, list_node* _Prior, list_node* _Next) noexcept :
            data{ _Data }, head_node<_ElementType>{ _Prior, _Next } {}

        constexpr list_node(_ElementType&& _Data, list_node* _Prior, list_node* _Next) noexcept :
            data{ std::move(_Data) }, head_node<_ElementType>{ _Prior, _Next } {}

        list_node& operator =(const list_node&) noexcept = delete;
        
        _ElementType data;
    };

    template<typename _ListType>
    struct list_const_iterator {
        using value_type        = typename _ListType::value_type;
        
        using difference_type   = typename _ListType::difference_type;
        
        using reference         = typename _ListType::reference;
        using const_reference   = typename _ListType::const_reference;
        
        using pointer           = typename _ListType::pointer;
        using const_pointer     = typename _ListType::const_pointer;
        
        using iterator_category = std::bidirectional_iterator_tag;
        
        constexpr list_const_iterator() noexcept : pNode{} {}
        
        constexpr list_const_iterator(typename _ListType::node_pointer _pNode) noexcept : pNode{ _pNode } {}

        constexpr const_reference operator *() const noexcept {
            return pNode->data;
        }

        constexpr const_pointer operator ->() const noexcept {
            return pNode->data;
        }

        constexpr list_const_iterator& operator ++() noexcept {
            pNode = pNode->next;
            return *this;
        }

        constexpr list_const_iterator operator ++(int) noexcept {
            list_const_iterator temp = *this;
            pNode = pNode->next;
            return temp;
        }

        constexpr list_const_iterator& operator +=(difference_type _Index) noexcept {
            if (_Index < 0) {
                return operator -=(-_Index);
            }

            for (difference_type i = 0; i < _Index; i++) {
                ++* this;
            }

            return *this;
        }

        constexpr list_const_iterator operator +(difference_type _Index) noexcept {
            list_const_iterator result{ *this };
            return result;
        }


        constexpr list_const_iterator operator +(difference_type _Index) const noexcept {
            if (_Index < 0) {
                return operator -(-_Index);
            }

            list_const_iterator result{ *this };
            for (difference_type i = 0; i < _Index; i++) {
                ++result;
            }

            return result;
        }

        constexpr list_const_iterator& operator --() noexcept {
            pNode = pNode->prior;
            return *this;
        }

        constexpr list_const_iterator operator --(int) noexcept {
            list_const_iterator temp = *this;
            pNode = pNode->prior;
            return temp;
        }

        constexpr list_const_iterator& operator -=(difference_type _Index) noexcept {
            if (_Index < 0) {
                return operator +=(-_Index);
            }

            for (difference_type i = 0; i < _Index; i++) {
                --* this;
            }

            return *this;
        }

        constexpr list_const_iterator operator -(difference_type _Index) noexcept {
            list_const_iterator result{ *this };
            return result += _Index;
        }

        constexpr list_const_iterator operator -(difference_type _Index) const noexcept {
            if (_Index < 0) {
                return operator +(-_Index);
            }

            list_const_iterator result{ *this };
            for (difference_type i = 0; i < _Index; i++) {
                --result;
            }

            return result;
        }

        constexpr bool operator ==(list_const_iterator const& _Right) const noexcept {
            return pNode == _Right.pNode;
        }
        
        typename _ListType::const_node_pointer pNode;
    };

    template<typename _ListType>
    struct list_iterator : public list_const_iterator<_ListType> {
        using value_type = typename _ListType::value_type;
        
        using difference_type   = typename _ListType::difference_type;

        using reference         = typename _ListType::reference;
        using const_reference   = typename _ListType::const_reference;

        using pointer           = typename _ListType::pointer;
        
        using base_type         = list_const_iterator<_ListType>;
        
        using iterator_category = std::bidirectional_iterator_tag;
        
        using list_const_iterator<_ListType>::pNode;

        constexpr reference operator *() const noexcept {
            return const_cast<reference>(pNode->data);
        }

        constexpr pointer operator ->() const noexcept {
            return reinterpret_cast<pointer>(pNode);
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

        constexpr list_iterator& operator +=(difference_type _Index) noexcept {
            if (_Index < 0) {
                return operator -=(-_Index);
            }

            for (difference_type i = 0; i < _Index; i++) {
                ++* this;
            }

            return *this;
        }

        constexpr list_iterator operator +(difference_type _Index) noexcept {
            list_iterator _Result{ *this };
            return _Result += _Index;
        }

        constexpr list_iterator operator +(difference_type _Index) const noexcept {
            if (_Index < 0) {
                return operator -(-_Index);
            }

            list_iterator _Result{ *this };
            for (difference_type i = 0; i < _Index; i++) {
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

        constexpr list_iterator operator -=(difference_type _Index) noexcept {
            if (_Index < 0) {
                return operator +=(-_Index);
            }

            for (difference_type i = 0; i < _Index; i++) {
                --* this;
            }

            return *this;
        }

        constexpr list_iterator operator -(difference_type _Index) noexcept {
            list_iterator _Result{ *this };
            return _Result += _Index;
        }

        constexpr list_iterator operator -(difference_type _Index) const noexcept {
            if (_Index < 0) {
                return operator +(-_Index);
            }

            list_iterator _Result{ *this };
            for (difference_type i = 0; i < _Index; i++) {
                --_Result;
            }

            return _Result;
        }
    };

    template<typename _ElementType, typename _Allocator = std::allocator<_ElementType>>
    class list {
    public:
        using size_type              = typename std::allocator_traits<_Allocator>::size_type;

        using value_type             = _ElementType;

        using allocator_type         = _Allocator;

        using reference              = value_type&;

        using const_reference        = const value_type&;

        using difference_type        = typename std::allocator_traits<_Allocator>::difference_type;

        using pointer                = typename std::allocator_traits<_Allocator>::pointer;
        using const_pointer          = typename std::allocator_traits<_Allocator>::const_pointer;

        using iterator               = list_iterator<list<value_type, _Allocator>>;
        using reverse_iterator       = typename std::reverse_iterator<iterator>;
        using const_iterator         = list_const_iterator<list<value_type, _Allocator>>;
        using const_reverse_iterator = typename std::reverse_iterator<const_iterator>;

        using node_type              = list_node<value_type>;
        using node_pointer           = node_type*;
        using const_node_pointer     = const node_type*;
        using head_node_type         = head_node<value_type>;

    public:
        constexpr list() noexcept = default;

        constexpr explicit list(list const& _Other) noexcept {
            for (const value_type& i : _Other) {
                push_back(i);
            }
        }

        constexpr explicit list(list&& _Right) noexcept {
            if (_Right.size() != 0) {
                headNode.next         = _Right.headNode.next;
                headNode.prior        = _Right.headNode.prior;
                headNode.next->prior  = make_list_node_ptr(&headNode);
                headNode.prior->next  = make_list_node_ptr(&headNode);
                numOfNode             = _Right.numOfNode;
                _Right.headNode.next  = make_list_node_ptr(&_Right.headNode);
                _Right.headNode.prior = make_list_node_ptr(&_Right.headNode);
                _Right.numOfNode      = 0;
            }
        }

        constexpr list(std::initializer_list<value_type> _InitialValueList) noexcept {
            for (const value_type& i : _InitialValueList) {
                push_back(std::move(i));
            }
        }

        constexpr ~list() noexcept {
            auto const e = end();
            for (auto i = begin(); i != e;) {
                delete (i++).pNode;
            }
        }

        constexpr list& operator =(const list& _Right) noexcept {
            if (this != &_Right) {
                clear();
                new (this) list(_Right);
            }

            return *this;
        }
        
        constexpr list& operator =(list&& _Right) noexcept {
            if (this != &_Right) {
                clear();
                new (this) list(std::move(_Right));
            }

            return *this;
        }
        
        constexpr void swap(list& _Right) noexcept {
            std::swap(numOfNode,      _Right.numOfNode);
            std::swap(headNode.next,  _Right.headNode.next);
            std::swap(headNode.prior, _Right.headNode.prior);
        }

        constexpr void push_back(value_type&& _Value) noexcept {
            headNode.prior->next = ::new node_type{ std::move(_Value), headNode.prior, make_list_node_ptr(&headNode) };
            headNode.prior       = headNode.prior->next;
            numOfNode++;
        }

        constexpr void push_back(const value_type& _Value) noexcept {
            headNode.prior->next = ::new node_type{ _Value, headNode.prior, make_list_node_ptr(&headNode) };
            headNode.prior       = headNode.prior->next;
            numOfNode++;
        }

        constexpr void push_front(value_type&& _Value) noexcept {
            headNode.next->prior = ::new node_type{ std::move(_Value), make_list_node_ptr(&headNode), headNode.next };
            headNode.next        = headNode.next->prior;
            numOfNode++;
        }

        constexpr void push_front(const value_type& _Value) noexcept {
            headNode.next->prior = ::new node_type{ _Value, make_list_node_ptr(&headNode), headNode.next };
            headNode.next        = headNode.next->prior;
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

        constexpr iterator insert(const_iterator _Where, value_type&& _Value) noexcept {
            _Where.pNode->prior->next = ::new node_type{ std::move(_Value), _Where.pNode->prior, _Where.pNode };
            _Where.pNode->prior       = _Where.pNode->prior->next;
            numOfNode++;

            return iterator{ _Where.pNode->prior };
        }

        constexpr iterator insert(const_iterator _Where, const value_type& _Value) noexcept {
            _Where.pNode->prior->next = ::new node_type{ _Value, _Where.pNode->prior, _Where.pNode };
            _Where.pNode->prior       = _Where.pNode->prior->next;
            numOfNode++;

            return iterator{ _Where.pNode->prior };
        }

        constexpr iterator erase(const_iterator _Where) noexcept {
            numOfNode--;
            auto const temp           = _Where.pNode->next;
            _Where.pNode->prior->next = _Where.pNode->next;
            _Where.pNode->next->prior = _Where.pNode->prior;
            ::delete _Where.pNode;

            return iterator{ temp };
        }

        constexpr iterator erase(const_iterator _Frist, const_iterator _Last) noexcept {
            _Frist.pNode->prior->next = _Last.pNode;
            _Last.pNode->prior        = _Frist.pNode->prior;
            for (auto i = _Frist; i != _Last; ) {
                numOfNode--;
                ::delete (i++).pNode;
            }

            return iterator{ _Frist.pNode->prior };
        }

        constexpr const_iterator find(iterator _Begin, const value_type& _Value) const noexcept {
            auto const e = end();
            for (auto i = _Begin; i != e; i++) {
                if (*i == _Value) {
                    return i;
                }
            }

            return const_iterator{ headNode.next->prior };
        }

        constexpr value_type& operator [](size_type _Index) noexcept {
            return *(begin() + _Index);
        }

        constexpr const value_type& operator [](size_type _Index) const noexcept {
            return *(begin() + _Index);
        }

        constexpr iterator find(iterator _First, iterator _Last, const value_type& _FindValue) noexcept {
            return std::find(_First, _Last, _FindValue);
        }

        constexpr const_iterator find(const_iterator _First, const_iterator _Last, const value_type& _FindValue) const noexcept {
            return std::find(_First, _Last, _FindValue);
        }

        template<typename _UnaryPredicate>
        constexpr iterator find_if(iterator _First, iterator _Last, _UnaryPredicate _Predicate) noexcept {
            return std::find_if(_First, _Last, _Predicate);
        }

        template<typename _UnaryPredicate>
        constexpr const_iterator find_if(const_iterator _First, const_iterator _Last, _UnaryPredicate _Predicate) const noexcept {
            return std::find_if(_First, _Last, _Predicate);
        }

        constexpr size_type remove(const value_type& _FindValue) noexcept {
            iterator head{ begin() };
            size_type firstSize{ numOfNode };
            while (true) {
                head = find(head, end(), _FindValue);
                if (head != end()) {
                    erase(head);
                } else {
                    break;
                }
            }
            return firstSize - numOfNode;
        }

        template<typename _UnaryPredicate>
        constexpr size_type remove_if(_UnaryPredicate _Predicate) noexcept {
            iterator head{ begin() };
            size_type firstSize{ numOfNode };
            while (true) {
                head = find_if(head, end(), _Predicate);
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

        constexpr void resize(size_type _Count) noexcept {
            if (_Count < numOfNode) {
                iterator head{ begin() };
                erase(head, head + numOfNode - _Count);
            } else if (_Count > numOfNode) {
                for (size_type i{ 0 }, newCount{ _Count - numOfNode }; i < newCount; i++) {
                    push_back(std::move(value_type{}));
                }
            }
        }

        constexpr void resize(size_type _Count, const value_type& _Value) noexcept {
            if (_Count < numOfNode) {
                iterator head{ begin() };
                erase(head, head + numOfNode - _Count);
            } else if (_Count > numOfNode) {
                    for (size_type i{ 0 }, newCount{ _Count - numOfNode }; i < newCount; i++) {
                    push_back(_Value);
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
        template<typename _ElementType>
        constexpr static list_node<_ElementType>* make_list_node_ptr(head_node<_ElementType> const* _Source) noexcept {
            return reinterpret_cast<list_node<_ElementType>*>(const_cast<head_node<_ElementType>*>(_Source));
        }

    private:
        size_type      numOfNode{};
        head_node_type headNode { make_list_node_ptr(&headNode), make_list_node_ptr(&headNode) };
    };
}
