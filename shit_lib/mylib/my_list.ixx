export module mylib.list;

import std.core;


export namespace mylib {

	template<typename _ElementType>
	struct list_node;

	template<typename _ElementType>
	struct head_node {
		using list_node_type = list_node<_ElementType>;
		using list_node_ptr  = list_node_type*;

		list_node_ptr next { nullptr };
		list_node_ptr prior{ nullptr };

		head_node(list_node_ptr _Prior, list_node_ptr _Next) noexcept :
			prior{ _Prior }, next{ _Next } {}

		head_node() noexcept							 = default;
		head_node(head_node const&) noexcept             = delete;
		head_node& operator =(head_node const&) noexcept = delete;
	};

	template<typename _ElementType>
	struct list_node : head_node<_ElementType> {
		using head_node<_ElementType>::next;
		using head_node<_ElementType>::prior;
		_ElementType data{};

		list_node(list_node&& _Other) noexcept :
			head_node<_ElementType>{ _Other.prior, _Other.next }, data{ std::move(_Other.data) } {
			_Other.next  = nullptr;
			_Other.prior = nullptr;
		}
		list_node(list_node const&) noexcept = delete;
		list_node() noexcept : data{}, prior{ nullptr }, next{ nullptr } {}
		list_node(_ElementType const& _Data, list_node* _Prior, list_node* _Next) noexcept :
			data{ _Data }, head_node<_ElementType>{ _Prior, _Next } {}

		list_node(_ElementType&& _Data, list_node* _Prior, list_node* _Next) noexcept :
			data{ std::move(_Data) }, head_node<_ElementType>{ _Prior, _Next } {}

		list_node& operator =(list_node const&) noexcept = delete;
	};

	template<typename _ListType>
	struct list_const_iterator {
		using difference_type = typename _ListType::difference_type;
		
		using reference		  = typename _ListType::reference;
		using const_reference = typename _ListType::const_reference;
		
		using pointer		  = typename _ListType::pointer;
		using const_pointer   = typename _ListType::const_pointer;
		
		list_const_iterator() noexcept : pNode{ nullptr } {}
		list_const_iterator(typename _ListType::node_ptr _pNode) noexcept : pNode{ _pNode } {}

		const_reference operator *() const noexcept {
			return pNode->data;
		}

		const_pointer operator ->() const noexcept {
			return pNode->data;
		}

		list_const_iterator& operator ++() noexcept {
			pNode = pNode->next;
			return *this;
		}

		list_const_iterator operator ++(int) noexcept {
			list_const_iterator temp = *this;
			pNode = pNode->next;
			return temp;
		}

		list_const_iterator& operator +=(difference_type _Index) noexcept {
			if (_Index < 0) {
				return operator -=(-_Index);
			}

			for (difference_type i = 0; i < _Index; i++) {
				++* this;
			}

			return *this;
		}

		list_const_iterator operator +(difference_type _Index) noexcept {
			list_const_iterator result{ *this };
			return result;
		}


		list_const_iterator operator +(difference_type _Index) const noexcept {
			if (_Index < 0) {
				return operator -(-_Index);
			}

			list_const_iterator result{ *this };
			for (difference_type i = 0; i < _Index; i++) {
				++result;
			}

			return result;
		}

		list_const_iterator& operator --() noexcept {
			pNode = pNode->prior;
			return *this;
		}

		list_const_iterator operator --(int) noexcept {
			list_const_iterator temp = *this;
			pNode = pNode->prior;
			return temp;
		}

		list_const_iterator& operator -=(difference_type _Index) noexcept {
			if (_Index < 0) {
				return operator +=(-_Index);
			}

			for (difference_type i = 0; i < _Index; i++) {
				--* this;
			}

			return *this;
		}

		list_const_iterator operator -(difference_type _Index) noexcept {
			list_const_iterator result{ *this };
			return result += _Index;
		}

		list_const_iterator operator -(difference_type _Index) const noexcept {
			if (_Index < 0) {
				return operator +(-_Index);
			}

			list_const_iterator result{ *this };
			for (difference_type i = 0; i < _Index; i++) {
				--result;
			}

			return result;
		}

		bool operator ==(list_const_iterator const& _Right) const noexcept {
			return pNode == _Right.pNode;
		}
		
		typename _ListType::node_ptr pNode;
	};

	template<typename _ListType>
	struct list_iterator : public list_const_iterator<_ListType> {
		using difference_type = typename _ListType::difference_type;

		using reference		  = typename _ListType::reference;
		using const_reference = typename _ListType::const_reference;

		using pointer		  = typename _ListType::pointer;		
		
		using list_const_iterator<_ListType>::pNode;

		typename reference operator *() const noexcept {
			return const_cast<reference>(pNode->data);
		}

		typename pointer operator ->() const noexcept {
			return reinterpret_cast<pointer>(pNode);
		}

		list_iterator& operator ++() noexcept {
			pNode = pNode->next;
			return *this;
		}

		list_iterator operator ++(int) noexcept {
			list_iterator temp = *this;
			pNode = pNode->next;
			return temp;
		}

		list_iterator& operator +=(difference_type _Index) noexcept {
			if (_Index < 0) {
				return operator -=(-_Index);
			}

			for (difference_type i = 0; i < _Index; i++) {
				++* this;
			}

			return *this;
		}

		list_iterator operator +(difference_type _Index) noexcept {
			list_iterator _Result{ *this };
			return _Result += _Index;
		}

		list_iterator operator +(difference_type _Index) const noexcept {
			if (_Index < 0) {
				return operator -(-_Index);
			}

			list_iterator _Result{ *this };
			for (difference_type i = 0; i < _Index; i++) {
				++_Result;
			}

			return _Result;
		}

		list_iterator& operator --() noexcept {
			pNode = pNode->prior;
			return *this;
		}

		list_iterator operator --(int) noexcept {
			list_iterator temp = *this;
			pNode = pNode->prior;
			return temp;
		}

		list_iterator operator -=(difference_type _Index) noexcept {
			if (_Index < 0) {
				return operator +=(-_Index);
			}

			for (difference_type i = 0; i < _Index; i++) {
				--* this;
			}

			return *this;
		}

		list_iterator operator -(difference_type _Index) noexcept {
			list_iterator _Result{ *this };
			return _Result += _Index;
		}

		list_iterator operator -(difference_type _Index) const noexcept {
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
		using size_type				 = typename std::allocator_traits<_Allocator>::size_type;

		using value_type			 = _ElementType;

		using allocator_type		 = _Allocator;

		using reference				 = value_type&;

		using const_reference		 = const value_type&;

		using difference_type		 = typename std::allocator_traits<_Allocator>::difference_type;

		using pointer				 = typename std::allocator_traits<_Allocator>::pointer;
		using const_point			 = typename std::allocator_traits<_Allocator>::const_pointer;

		using iterator				 = list_iterator < list < value_type, _Allocator>>;
		using reverse_iterator		 = typename std::reverse_iterator<iterator>;
		using const_iterator		 = list_const_iterator<list<value_type, _Allocator>>;
		using const_reverse_iterator = typename std::reverse_iterator<const_iterator>;

		using node_ptr				 = list_node<value_type>*;
		using node_type				 = list_node<value_type>;
		using head_node_type		 = head_node<value_type>;


	public:
		list() noexcept {}

		explicit list(list const& _Other) noexcept {
			for (const value_type& i : _Other) {
				push_back(i);
			}
		}

		explicit list(list&& _Right) noexcept {
			headNode  = _Right.headNode;
			numOfNode = _Right.numOfNode;
			_Right.headNode.next  = nullptr;
			_Right.headNode.prior = nullptr;
			_Right.numOfNode	  = 0;
		}

		list(std::initializer_list<value_type> _InitialValueList) noexcept {
			for (const value_type& i : _InitialValueList) {
				push_back(std::move(i));
			}
		}

		~list() noexcept {
			auto const e = end();
			for (auto i = begin(); i != e;) {
				delete (i++).pNode;
			}
		}

		void swap(list& _Right) noexcept {
			std::swap(numOfNode,	  _Right.numOfNode);
			std::swap(headNode.next,  _Right.headNode.next);
			std::swap(headNode.prior, _Right.headNode.prior);
		}

		void push_back(value_type&& _Value) noexcept {
			headNode.prior->next = ::new node_type{ std::move(_Value), headNode.prior, make_list_node_ptr(&headNode) };
			headNode.prior = headNode.prior->next;
			numOfNode++;
		}

		void push_back(const value_type& _Value) noexcept {
			headNode.prior->next = ::new node_type{ _Value, headNode.prior, make_list_node_ptr(&headNode) };
			headNode.prior = headNode.prior->next;
			numOfNode++;
		}

		void push_front(value_type&& _Value) noexcept {
			headNode.next->prior = ::new node_type{ std::move(_Value), make_list_node_ptr(&headNode), headNode.next };
			headNode.next = headNode.next->prior;
			numOfNode++;
		}

		void push_front(const value_type& _Value) noexcept {
			headNode.next->prior = ::new node_type{ _Value, make_list_node_ptr(&headNode), headNode.next };
			headNode.next = headNode.next->prior;
			numOfNode++;
		}

		void pop_back() noexcept {
			numOfNode--;
			headNode.prior->prior->next = &headNode;
			auto temp = headNode.prior;
			headNode.prior = headNode.prior->prior;
			delete temp;
		}

		void pop_front() noexcept {
			numOfNode--;
			headNode.next->next->prior = &headNode;
			auto temp = headNode.next;
			headNode.next = headNode.next->next;
			delete temp;
		}

		const value_type& back() const noexcept {
			return headNode.prior->data;
		}

		const value_type& front() const noexcept {
			return headNode.next->data;
		}

		iterator insert(const_iterator _Where, value_type&& _Value) noexcept {
			_Where.pNode->prior->next = ::new node_type{ std::move(_Value), _Where.pNode->prior, _Where.pNode };
			_Where.pNode->prior = _Where.pNode->prior->next;
			numOfNode++;

			return iterator{ _Where.pNode->prior };
		}

		iterator insert(const_iterator _Where, const value_type& _Value) noexcept {
			_Where.pNode->prior->next = ::new node_type{ _Value, _Where.pNode->prior, _Where.pNode };
			_Where.pNode->prior = _Where.pNode->prior->next;
			numOfNode++;

			return iterator{ _Where.pNode->prior };
		}

		iterator erase(const_iterator _Where) noexcept {
			numOfNode--;
			auto const temp = _Where.pNode->next;
			_Where.pNode->prior->next = _Where.pNode->next;
			_Where.pNode->next->prior = _Where.pNode->prior;
			delete _Where.pNode;

			return iterator{ temp };
		}

		iterator erase(const_iterator _Frist, const_iterator _Last) noexcept {
			_Frist.pNode->prior->next = _Last.pNode;
			_Last.pNode->prior = _Frist.pNode->prior;
			for (auto i = _Frist; i != _Last; ) {
				numOfNode--;
				delete (i++).pNode;
			}

			return iterator{ _Frist.pNode->prior };
		}

		const_iterator find(iterator _Begin, const value_type& _Value) const noexcept {
			auto const e = end();
			for (auto i = _Begin; i != e; i++) {
				if (*i == _Value) {
					return i;
				}
			}

			return const_iterator{ headNode.next->prior };
		}

		value_type& operator [](size_type _Index) noexcept {
			return *(begin() + _Index);
		}

		const value_type& operator [](size_type _Index) const noexcept {
			return *(begin() + _Index);
		}

		iterator find(iterator _First, iterator _Last, const value_type& _FindValue) noexcept {
			return std::find(_First, _Last, _FindValue);
		}

		const_iterator find(const_iterator _First, const_iterator _Last, const value_type& _FindValue) const noexcept {
			return std::find(_First, _Last, _FindValue);
		}

		template<typename _UnaryPredicat>
		iterator find_if(iterator _First, iterator _Last, _UnaryPredicat _Predicat) noexcept {
			return std::find_if(_First, _Last, _Predicat);
		}

		template<typename _UnaryPredicat>
		const_iterator find_if(const_iterator _First, const_iterator _Last, _UnaryPredicat _Predicat) const noexcept {
			return std::find_if(_First, _Last, _Predicat);
		}

		size_type remove(const value_type& _FindValue) noexcept {
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

		template<typename _UnaryPredicat>
		size_type remove_if(_UnaryPredicat _Predicat) noexcept {
			iterator head{ begin() };
			size_type firstSize{ numOfNode };
			while (true) {
				head = find_if(head, end(), _Predicat);
				if (head != end()) {
					erase(head);
				} else {
					break;
				}
			}
			return firstSize - numOfNode;
		}

		void clear() noexcept {
			erase(cbegin(), cend());
		}

		void resize(size_type _Count) noexcept {
			if (_Count < numOfNode) {
				iterator head{ begin() };
				erase(head, head + numOfNode - _Count);
			} else if (_Count > numOfNode) {
				for (size_type i{ 0 }, newCount{ _Count - numOfNode }; i < newCount; i++) {
					push_back(std::move(value_type{}));
				}
			}
		}

		void resize(size_type _Count, const value_type& _Value) noexcept {
			if (_Count < numOfNode) {
				iterator head{ begin() };
				erase(head, head + numOfNode - _Count);
			} else if (_Count > numOfNode) {
					for (size_type i{ 0 }, newCount{ _Count - numOfNode }; i < newCount; i++) {
					push_back(_Value);
				}
			}
		}

		size_type size() const noexcept {
			return numOfNode;
		}

		bool empty() const noexcept {
			return size() == size_type{ 0 };
		}

		iterator begin() noexcept {
			return iterator{ headNode.next };
		}

		const_iterator begin() const noexcept {
			return cbegin();
		}

		const_iterator cbegin() const noexcept {
			return const_iterator{ headNode.next };
		}

		reverse_iterator rbegin() noexcept {
			return reverse_iterator{ end() };
		}

		const_reverse_iterator rbegin() const noexcept {
			return crbegin();
		}

		const_reverse_iterator crbegin() const noexcept {
			return const_reverse_iterator{ cend() };
		}

		iterator end() noexcept {
			return iterator{ make_list_node_ptr(&headNode) };
		}

		const_iterator end() const noexcept {
			return const_iterator{ make_list_node_ptr(&headNode) };
		}

		const_iterator cend() const noexcept {
			return end();
		}

		reverse_iterator rend() noexcept {
			return reverse_iterator{ begin() };
		}

		const_reverse_iterator rend() const noexcept {
			return crend();
		}

		const_reverse_iterator crend() const noexcept {
			return const_reverse_iterator{ cbegin() };
		}

	private:
		template<typename _ElementType>
		static constexpr list_node<_ElementType>* make_list_node_ptr(head_node<_ElementType> const* _Source) noexcept
		{
			return reinterpret_cast<list_node<_ElementType>*>(const_cast<head_node<_ElementType>*>(_Source));
		}

	private:
		size_type numOfNode{};
		head_node_type headNode{ make_list_node_ptr(&headNode), make_list_node_ptr(&headNode) };
	};

	template<typename _ElementType>
	std::ostream& operator <<(std::ostream& _Os, list<_ElementType> const& _Value) {
		for (auto i : _Value) {
			_Os << i << ' ';
		}

		return _Os;
	}
}