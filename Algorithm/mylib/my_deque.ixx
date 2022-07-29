export module mylib.deque;

import std.core;


export namespace mylib {

	template<typename _DequeBlock>
	struct deque_const_iterator {
		using difference_type = typename _DequeBlock::difference_type;
		using size_type		  = typename _DequeBlock::size_type;
		using block_type	  = _DequeBlock;
		using reference		  = typename _DequeBlock::reference;
		using const_reference = typename _DequeBlock::const_reference;
		using pointer		  = typename _DequeBlock::pointer;
		using value_type	  = typename _DequeBlock::value_type;

		constexpr static size_type block_size = block_type::block_size;

		deque_const_iterator() noexcept : deque_blocks{}, position{ 0 } {}
		deque_const_iterator(block_type const* _DequeBlocks, size_type _Index) noexcept :
			deque_blocks{ const_cast<block_type*>(_DequeBlocks) }, position{_Index} {}

		const_reference operator *() const noexcept {
			return (*deque_blocks)[position];
		}

		pointer operator ->() const noexcept {
			return &(*deque_blocks)[position];
		}

		const_reference operator [](difference_type const& _Offset) const noexcept {
			return (*deque_blocks)[position + _Offset];
		}

		deque_const_iterator& operator ++() noexcept {
			++position;
			return *this;
		}

		deque_const_iterator  operator ++(int) noexcept {
			deque_const_iterator temp = *this;
			++position;
			return temp;
		}

		deque_const_iterator& operator +=(difference_type _Index) noexcept {
			position += _Index;
			return *this;
		}

		deque_const_iterator  operator +(difference_type _Index) noexcept {
			deque_const_iterator result{ *this };
			return result += _Index;
		}

		deque_const_iterator  operator +(difference_type _Index) const noexcept {
			deque_const_iterator result{ *this };
			result.position += _Index;
			return result;
		}

		deque_const_iterator& operator --() noexcept {
			--position;
			return *this;
		}

		deque_const_iterator  operator --(int) noexcept {
			deque_const_iterator temp = *this;
			--position;
			return temp;
		}

		deque_const_iterator& operator -=(difference_type _Index) noexcept {
			operator +=(-_Index);
			return *this;
		}

		deque_const_iterator  operator -(difference_type _Index) noexcept {
			deque_const_iterator result{ *this };
			return result -= _Index;
		}

		deque_const_iterator  operator -(difference_type _Index) const noexcept {
			deque_const_iterator result{ *this };
			result.position -= _Index;
			return result;
		}

		bool operator ==(deque_const_iterator const& _Right) const noexcept {
			return position == _Right.position;
		}

		block_type const* deque_blocks;
		size_type		  position;
	};

	template<typename _DequeBlock>
	struct deque_iterator : public deque_const_iterator<_DequeBlock> {
		using deque_const_iterator<_DequeBlock>::deque_blocks;
		using deque_const_iterator<_DequeBlock>::position;

		using difference_type = typename _DequeBlock::difference_type;
		using size_type		  = typename _DequeBlock::size_type;
		using block_type	  = _DequeBlock;
		using reference		  = typename _DequeBlock::reference;
		using const_reference = typename _DequeBlock::const_reference;
		using pointer		  = typename _DequeBlock::pointer;
		using value_type	  = typename _DequeBlock::value_type;

		constexpr static size_type block_size = block_type::block_size;

		deque_iterator() noexcept : deque_const_iterator<_DequeBlock>{} {}
		deque_iterator(block_type* _DequeBlocks, size_type _Index) noexcept :
			deque_const_iterator<_DequeBlock>{ _DequeBlocks, _Index } {}

		reference operator *() const noexcept {
			return static_cast<reference>((*deque_blocks)[position]);
		}

		pointer operator ->() const noexcept {
			return static_cast<pointer>(&(*deque_blocks)[position]);
		}

		reference operator [](difference_type const& _Offset) const noexcept {
			return (*deque_blocks)[position + _Offset];
		}

		deque_iterator& operator ++() noexcept {
			++position;
			return *this;
		}

		deque_iterator  operator ++(int) noexcept {
			deque_iterator temp = *this;
			++position;
			return temp;
		}

		deque_iterator& operator +=(difference_type _Index) noexcept {
			position += _Index;
			return *this;
		}

		deque_iterator  operator +(difference_type _Index) noexcept {
			deque_iterator result{ *this };
			return result += _Index;
		}

		deque_iterator  operator +(difference_type _Index) const noexcept {
			deque_iterator result{ *this };
			result.position += _Index;
			return result;
		}

		deque_iterator& operator --() noexcept {
			--position;
			return *this;
		}

		deque_iterator  operator --(int) noexcept {
			deque_iterator temp = *this;
			--position;
			return temp;
		}

		deque_iterator& operator -=(difference_type _Index) noexcept {
			operator +=(-_Index);
			return *this;
		}

		deque_iterator  operator -(difference_type _Index) noexcept {
			deque_iterator result{ *this };
			return result -= _Index;
		}

		deque_iterator  operator -(difference_type _Index) const noexcept {
			deque_iterator result{ *this };
			result.position -= _Index;
			return result;
		}
	};

	template<typename _DequeType>
	struct deque_blocks {
		using size_type		  = typename _DequeType::size_type;
		using value_type	  = typename _DequeType::value_type;
		using reference		  = typename _DequeType::reference;
		using const_reference = typename _DequeType::const_reference;
		using pointer		  = typename _DequeType::pointer;
		using difference_type = typename _DequeType::difference_type;

		static constexpr size_type element_bytes = sizeof(value_type);
		static constexpr size_type block_size    = element_bytes <= 1 ? 16
												 : element_bytes <= 2 ? 8
												 : element_bytes <= 4 ? 4
												 : element_bytes <= 8 ? 2
												 : 1;
		static constexpr size_type block_bytes = element_bytes * block_size;
		static constexpr size_type exponent    = std::bit_width(std::bit_ceil(block_size)) - 1;

		deque_blocks(deque_blocks const& _Other) noexcept :
				numberOfBlocks{ _Other.numberOfBlocks }, numberOfElement{ _Other.numberOfElement },
				head{ _Other.head } {
			map = ::new pointer[numberOfBlocks];
			for (size_type i = 0; i < numberOfBlocks; ++i) {
				map[i] = ::new value_type[block_size];
				for (size_type j = 0; j < block_size; ++j) {
					map[i][j] = _Other.map[i][j];
				}
			}
		}
		
		deque_blocks(deque_blocks&& _Other) noexcept :
				numberOfBlocks{ _Other.numberOfBlocks }, numberOfElement{ _Other.numberOfElement },
				head{ _Other.head }, map{ _Other.map } {
			_Other.numberOfBlocks  = 0;
			_Other.numberOfElement = 0;
			_Other.head			   = 0;
			_Other.map			   = nullptr;
		}
		
		deque_blocks() : map{ nullptr }, head{ 0 }, numberOfElement{ 0 }, numberOfBlocks{ 0 } {}
		
		deque_blocks(std::initializer_list<value_type> _InitializerList) noexcept {
			size_t const elementSize = _InitializerList.size();
			head = 0;
			numberOfElement = elementSize;
			numberOfBlocks  = std::bit_ceil(elementSize / block_size + bool(elementSize % block_size));
			map			    = ::new pointer[numberOfBlocks];

			auto beginIterator = _InitializerList.begin();
			auto const endIterator = _InitializerList.end();
			for (size_type i = 0; i < numberOfBlocks; ++i) {
				map[i] = ::new value_type[block_size];
				for (size_t j = 0; beginIterator != endIterator && j < block_size; ++j, ++beginIterator) {
					map[i][j] = *beginIterator;
				}
			}
		}

		__declspec(noinline)
		~deque_blocks() {
			for (size_type i = 0; i < numberOfBlocks; ++i) {
				::delete[] map[i];
			}
			::delete[] map;
		}

		deque_blocks& operator =(deque_blocks const& _Other) noexcept {
			if (this != &_Other) {
				for (size_type i = 0; i < numberOfBlocks; ++i) {
					::delete[] map[i];
				}
				::delete[] map;

				numberOfBlocks  = _Other.numberOfBlocks;
				numberOfElement = _Other.numberOfElement;
				head			= _Other.head;
				map			    = ::new pointer[numberOfBlocks];
				for (size_type i = 0; i < numberOfBlocks; ++i) {
					map[i] = ::new value_type[block_size];
					for (size_type j = 0; j < block_size; ++j) {
						map[i][j] = _Other.map[i][j];
					}
				}
			}
			return *this;
		}

		deque_blocks& operator =(deque_blocks&& _Other) noexcept {
			if (this != &_Other) {
				for (size_type i = 0; i < numberOfBlocks; ++i) {
					::delete[] map[i];
				}
				::delete[] map;

				numberOfBlocks  = _Other.numberOfBlocks;
				numberOfElement = _Other.numberOfElement;
				head			= _Other.head;
				map			    = _Other.map;

				_Other.numberOfBlocks  = 0;
				_Other.numberOfElement = 0;
				_Other.head			   = 0;
				_Other.map			   = nullptr;
			}
			return *this;
		}

		void swap(deque_blocks& _Right) noexcept {
			std::swap(numberOfElement, _Right.numberOfElement);
			std::swap(numberOfBlocks,  _Right.numberOfBlocks);
			std::swap(head,			   _Right.head);
			std::swap(map,			   _Right.map);
		}

		size_type get_block_offset(size_type _Offset) const noexcept {
			return (_Offset >> exponent) & (numberOfBlocks - 1);
		}

		static constexpr size_type get_block_offset(size_type _Offset, size_type _NumberOfBlock) noexcept {
			return (_Offset >> exponent) & (_NumberOfBlock - 1);
		}

		constexpr size_type get_relative_offset(size_type _Offset) const noexcept {
			return _Offset & (block_size - 1);
		}

		static constexpr size_type get_relative_offset(size_type _Offset, size_type _BlockSize) noexcept {
			return _Offset & (_BlockSize - 1);
		}

		size_type get_rear_offset() const noexcept {
			return head + numberOfElement - 1;
		}

		size_type size() const noexcept {
			return numberOfElement;
		}

		size_type map_size() const noexcept {
			return numberOfBlocks;
		}

		size_type capacity() const noexcept {
			return numberOfBlocks << exponent;
		}

		reference operator [](size_type _Index) noexcept {
			return get_element_by_index(_Index);
		}

		const reference operator [](size_type _Index) const noexcept {
			return get_element_by_index(_Index);
		}

		reference get_element_by_index(size_type _Index) noexcept {
			size_type const offset = _Index + head;
			return map[get_block_offset(offset)][get_relative_offset(offset)];
		}

		const reference get_element_by_index(size_type _Index) const noexcept {
			size_type const offset = _Index + head;
			return map[get_block_offset(offset)][get_relative_offset(offset)];
		}

		reference get_element_by_offset(size_type _Offset) noexcept {
			return map[get_block_offset(_Offset)][get_relative_offset(_Offset)];
		}

		const reference get_element_by_offset(size_type _Offset) const noexcept {
			return map[get_block_offset(_Offset)][get_relative_offset(_Offset)];
		}

		void clear() noexcept {
			for (size_type i = 0, limit = map_size(); i < limit; ++i) {
				::delete[] map[i];
			}
			::delete[] map;
		}

		pointer* map;			  // a array of pointer to value_type
		size_type head;
		size_type numberOfElement;
		size_type numberOfBlocks; // hold it's value is 2 ^ N or 0
	};

	template<typename _ElementType, typename _Allocator = std::allocator<_ElementType>>
	class deque {
	public:
		using size_type				 = typename std::allocator_traits<_Allocator>::size_type;

		using value_type			 = _ElementType;

		using block_type		     = deque_blocks<deque<value_type, _Allocator>>;

		using allocator_type		 = _Allocator;

		using reference				 = value_type&;

		using const_reference		 = const value_type&;

		using difference_type		 = typename std::allocator_traits<_Allocator>::difference_type;

		using pointer				 = typename std::allocator_traits<_Allocator>::pointer;
		using const_point			 = typename std::allocator_traits<_Allocator>::const_pointer;

		using iterator				 = deque_iterator<block_type>;
		using reverse_iterator		 = std::reverse_iterator<iterator>;
		using const_iterator		 = deque_const_iterator<block_type>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	private:
		template<typename _ValueType>
		void extend(size_type _Magnification, _ValueType&& _Value) noexcept {
			if (_Magnification <= 1) {
				return;
			}

			if (size() == 0) {
				data.map = ::new pointer[2]{
					::new value_type[block_type::block_size],
					::new value_type[block_type::block_size],
				};
				data.numberOfBlocks = 2;
				data.numberOfElement = 0;
				return;
			}

			_Magnification					 = std::bit_ceil(_Magnification); // make _Magnification equal to 2 ^ N  
			size_type previousMapSize		 = data.numberOfBlocks;
			size_type const previousCapacity = data.capacity();
			data.numberOfBlocks			   <<= std::bit_width(_Magnification) - 1;
			size_type previousHead			 = data.head;

			// change head when head is behind the rear
			if (data.head > (data.get_rear_offset() & (previousCapacity - 1))) {
				data.head = (data.head + (data.numberOfBlocks - previousMapSize) * data.block_size) & ((data.numberOfBlocks << data.exponent) - 1);
			}
			pointer* previousMap = ::new pointer[data.numberOfBlocks]; // allocate new memory then swap
			std::swap(data.map, previousMap);

			for (size_type i = 0; i < previousMapSize; ++i) {
				data.map[i] = previousMap[i];
			}

			::delete[] previousMap; // free privious Blocks' memory

			for (size_type i = previousMapSize; i < data.numberOfBlocks; ++i) {
				data.map[i] = ::new value_type[data.block_size];
				for (size_type j = 0; j < data.block_size; ++j) {
					data.map[i][j] = std::forward<_ValueType>(_Value);
				}
			}

			// copy from head to rear
			size_type previousBlockOffset	   = data.get_block_offset(previousHead, previousMapSize);
			size_type currentBlockOffset	   = data.get_block_offset(data.head);
			const size_type headRelativeOffset = data.get_relative_offset(data.head);
			const size_type rearBlockOffset    = data.get_block_offset(data.head + data.numberOfElement - 1);
			if (previousBlockOffset == rearBlockOffset) {
				for (size_type i = headRelativeOffset; i < data.block_size; ++i) {
					data.map[currentBlockOffset][i] = std::move(data.map[previousBlockOffset][i]);
				}
				++previousBlockOffset;
				++currentBlockOffset;
			}
			for (
				;
				previousBlockOffset < previousMapSize;
				++previousBlockOffset,
				++currentBlockOffset
				) {
				std::swap(data.map[currentBlockOffset], data.map[previousBlockOffset]);
			}
		}

		template<typename _ValueType>
		iterator insert_internal(const_iterator _Where, _ValueType&& _Value) noexcept {
			size_type previousSize = data.size();
			if (previousSize == data.capacity()) {
				extend(2, std::forward<_ValueType>(_Value));
			}
			++data.numberOfElement;

			// no to move any element if _Were is first iterator, then insert new element in front of the _Where
			if (_Where == cbegin()) {
				data.head = (data.head - 1) & (data.capacity() - 1);
				data[0] = std::forward<_ValueType>(_Value);
				return begin();
			}

			// move front element when _Where is in front part, else move before element
			if (_Where.position > (previousSize >> 1)) {
				reverse_iterator	   destination{ rbegin() };
				const_reverse_iterator source{ destination + 1 };
				const_reverse_iterator beforeWhere{ _Where + 1 };
				for (; destination != beforeWhere; ++destination, ++source) {
					*destination = std::move(*source);
				}
				*destination = std::forward<_ValueType>(_Value);
			} else {
				data.head = (data.head - 1) & (data.capacity() - 1);
				iterator	   destination{ begin() };
				const_iterator source{ destination + 1 };
				const_iterator afterWhere{ _Where };
				for (; destination != afterWhere; ++destination, ++source) {
					*destination = std::move(*source);
				}
				*destination = std::forward<_ValueType>(_Value);
			}
			return iterator{ &data, _Where.position };
		}

	public:
		deque() noexcept : data{} {}
		
		explicit deque(deque const& _Other) noexcept : data{ _Other.data } {}
		
		explicit deque(deque&& _Other) noexcept : data{ std::move(_Other.data) } {}
		
		template<typename _InputIterator>
		deque(_InputIterator _First, _InputIterator _Last) noexcept : data{} {
			insert(begin(), _First, _Last);
		}
		
		deque(std::initializer_list<value_type> _InitialValueList) noexcept : data{} {
			for (const value_type& i : _InitialValueList) {
				push_back(std::move(i));
			}
		}
		
		~deque() noexcept {}

		deque& operator=(deque const& _Other) noexcept {
			data = _Other.data;
			return *this;
		}

		deque& operator=(deque&& _Other) noexcept {
			data = std::move(_Other.data);
			return *this;
		}

		void swap(deque& _Right) noexcept {
			data.swap(_Right.data);
		}

		void push_back(value_type&& _Value) noexcept {
			if (data.size() == data.capacity()) {
				extend<const value_type&>(2, value_type{});
			}
			data[data.size()] = std::move(_Value);
			++data.numberOfElement;
		}

		void push_back(const value_type& _Value) noexcept {
			if (data.size() == data.capacity()) {
				extend<const value_type&>(2, value_type{});
			}
			data[data.size()] = _Value;
			++data.numberOfElement;
		}

		void push_front(value_type&& _Value) noexcept {
			if (data.size() == data.capacity()) {
				extend<const value_type&>(2, value_type{});
			}
			data.head = (data.head - 1) & (data.capacity() - 1);
			data[0] = std::move(_Value);
			++data.numberOfElement;
		}

		void push_front(const value_type& _Value) noexcept {
			if (data.size() == data.capacity()) {
				extend<const value_type&>(2, value_type{});
			}
			data.head = (data.head - 1) & (data.capacity() - 1);
			data[0] = _Value;
			++data.numberOfElement;
		}

		void pop_back() noexcept {
			--data.numberOfElement;
		}

		void pop_front() noexcept {
			--data.numberOfElement;
			data.head = (data.head + 1) & (data.capacity() - 1);
		}

		reference front() noexcept {
			return data[0];
		}

		const_reference front() const noexcept {
			return data[0];
		}

		reference back() noexcept {
			return data[data.size() - 1];
		}

		const_reference back() const noexcept {
			return data[data.size() - 1];
		}

		reference operator [](size_type _Index) noexcept {
			return data[_Index];
		}

		reference operator [](size_type _Index) const noexcept {
			return data[_Index];
		}

		size_type size() const noexcept {
			return data.size();
		}

		bool empty() const noexcept {
			return size() == size_type{ 0 };
		}

		iterator insert(const_iterator _Where, const value_type& _Value) noexcept {
			return insert_internal(_Where, _Value);
		}

		iterator insert(const_iterator _Where, value_type&& _Value) noexcept {
			return insert_internal(_Where, std::move(_Value));
		}

		iterator insert(const_iterator _Where, size_type _Count,const value_type& _Value) noexcept {
			size_type previousSize = data.size();
			if (previousSize + _Count >= data.capacity()) {
				resize(previousSize + _Count);
			}
			data.numberOfElement += _Count;

			if (_Where == cbegin()) {
				data.head = (data.head - _Count) & (data.capacity() - 1);
				for (size_type i = 0; i < _Count; ++i) {
					data[i] = _Value;
				}
				return begin();
			}

			if (_Where.position > (previousSize >> 1)) {
				reverse_iterator	   destination{ rbegin() };
				const_reverse_iterator source{ destination + _Count };
				const_reverse_iterator beforeWhere{ _Where + 1 };
				for (; destination != beforeWhere; ++destination, ++source) {
					*destination = std::move(*source);
				}
			} else {
				data.head = (data.head - _Count) & (data.capacity() - 1);
				iterator	   destination{ begin() };
				const_iterator source{ destination + _Count };
				const_iterator afterWhere{ _Where };
				for (; destination != afterWhere; ++destination, ++source) {
					*destination = std::move(*source);
				}
			}
			for (size_type i = 0, j = _Where.position; i < _Count; ++i, ++j) {
				data[j] = _Value;
			}
			return iterator{ &data, _Where.position };
		}

		template<typename _InputIterator>
		iterator insert(const_iterator _Where, _InputIterator _First, _InputIterator _Last) noexcept {
			iterator result = iterator{ &data, _Where.position };
			while (_First != _Last) {
				result = insert(_Where++, std::move(*_First++));
			}
			return result;
		}

		iterator insert(const_iterator _Where, std::initializer_list<value_type> _InitializerList) noexcept {
			return insert(_Where, _InitializerList.begin(), _InitializerList.end());
		}

		iterator erase(const_iterator _Where) noexcept {
			if (_Where.position == 0) {
				data.head = (data.head + 1) & (data.capacity() - 1);
				--data.numberOfElement;
				return begin();
			}
			const_iterator source	{ _Where + 1 };
			const_iterator afterRear{ cend() };
			for (
				iterator destination{ &data, _Where.position };
				source != afterRear;
				++source, ++destination
			) {
				*destination = std::move(*source);
			}
			--data.numberOfElement;

			return iterator{ &data, _Where.position };
		}

		iterator erase(const_iterator _First, const_iterator _Last) noexcept {
			size_type numOfEraseElement = _Last.position - _First.position;
			if (_First.position == 0) {
				data.head = _Last.position; 
				data.numberOfElement -= numOfEraseElement;
				return begin();
			}
			const_iterator source	  { _Last };
			const_iterator afterRear{ cend() };
			for (
				iterator destination{ &data, _First.position };
				destination != afterRear;
				++source, ++destination
			) {
				*destination = std::move(*source);
			}
			data.numberOfElement -= numOfEraseElement;

			return iterator{ &data, _First.position };
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
			iterator  head{ begin() };
			size_type firstSize{ size() };
			while (true) {
				head = find(head, end(), _FindValue);
				if (head != end()) {
					erase(head);
				} else {
					break;
				}
			}
			return firstSize - size();
		}

		template<typename _UnaryPredicat>
		size_type remove_if(_UnaryPredicat _Predicat) noexcept {
			iterator head{ begin() };
			size_type firstSize{ size() };
			while (true) {
				head = find_if(head, end(), _Predicat);
				if (head != end()) {
					erase(head);
				} else {
					break;
				}
			}
			return firstSize - size();
		}

		void clear() noexcept {
			erase(cbegin(), cend());
		}

		void resize(size_type _NewSize) noexcept {
			if (_NewSize > size()) {
				extend<const value_type&>(_NewSize / block_type::block_size + bool(_NewSize / block_type::block_size), value_type{});
			}
			data.numberOfElement = _NewSize;
		}

		void resize(size_type _NewSize, const value_type& _Value) noexcept {
			if (_NewSize > size()) {
				extend(_NewSize / block_type::block_size + bool(_NewSize / block_type::block_size), _Value);
			}
			data.numberOfElement = _NewSize;
		}

		void shrink_to_fit() noexcept {
			size_type const numOfElement	 = data.size();
			size_type const previousCapacity = data.capacity();
			if (previousCapacity < (numOfElement << 1)) {
				return;
			}

			// make minification equal to 2 ^ N  
			size_type previousMapSize = data.map_size();
			size_type minification	  = std::bit_floor(previousMapSize / ((numOfElement >> block_type::exponent) + bool(numOfElement & (block_type::block_size - 1))));
			data.numberOfBlocks		>>= std::bit_width(minification) - 1;
			size_type previousHead    = data.head;
			size_type previousRear	  = data.get_rear_offset();

			// change head when head is behind the rear
			if (previousHead > (data.get_rear_offset() & (previousCapacity - 1))) {
				data.head			  = (data.head + (previousMapSize - data.numberOfBlocks) * block_type::block_size) & ((data.numberOfBlocks << block_type::exponent) - 1);
			} else {
				data.head			  = data.get_relative_offset(data.head);
			}
			pointer*  previousMap	  = ::new pointer[data.numberOfBlocks]; // allocate new memory then swap
			std::swap(data.map, previousMap);

			size_type const currentMapSize		    = data.map_size();
			size_type previousBlockOffset		    = data.get_block_offset(previousRear, previousMapSize);
			size_type currentBlockOffset		    = data.get_block_offset(data.get_rear_offset());
			size_type const currentHeadBlockOffset  = data.get_block_offset(data.head);
			size_type const previousHeadBlockOffset = data.get_block_offset(previousHead, previousMapSize);

			// copy from rear to head
			if (currentHeadBlockOffset == currentBlockOffset) {
				while (true) {
					data.map[currentBlockOffset] = previousMap[previousBlockOffset];
					currentBlockOffset			 = (currentBlockOffset  - 1) & (currentMapSize  - 1);
					previousBlockOffset			 = (previousBlockOffset - 1) & (previousMapSize - 1);
					if (currentBlockOffset == currentHeadBlockOffset) {
						break;
					}
				}
				for (size_type i = data.get_relative_offset(data.head); i != block_type::block_size; ++i) {
					data.map[currentHeadBlockOffset][i] = std::move(previousMap[previousHeadBlockOffset][i]);
				}
			} else {
				for (
					size_type i = 0; 
					i < currentMapSize; 
					++i, 
					currentBlockOffset  = (currentBlockOffset  - 1) & (currentMapSize  - 1),
					previousBlockOffset = (previousBlockOffset - 1) & (previousMapSize - 1)
					) {
					data.map[currentBlockOffset] = previousMap[previousBlockOffset];
				}
			}
			::delete[] previousMap;
		}

		iterator begin() noexcept {
			return iterator{ &data, 0 };
		}

		const_iterator begin() const noexcept {
			return cbegin();
		}

		const_iterator cbegin() const noexcept {
			return const_iterator{ &data, 0 };
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
			return iterator{ &data, size() };
		}

		const_iterator end() const noexcept {
			return cend();
		}

		const_iterator cend() const noexcept {
			return const_iterator{ &data, size() };
		}

		reverse_iterator rend() noexcept {
			return const_reverse_iterator{ begin() };
		}

		const_reverse_iterator rend() const noexcept {
			return crend();
		}

		const_iterator crend() const noexcept {
			return const_reverse_iterator{ cbegin() };
		}

	private:
		block_type data;
	};

	template<typename _ElementType, typename _Allocator>
	std::ostream& operator <<(std::ostream& _Os, deque<_ElementType, _Allocator> const& _Value) {
		for (auto i : _Value) {
			_Os << i << ' ';
		}

		return _Os;
	}

	// test fuction, check deque's map
	template<typename _DequeType>
	std::ostream& operator <<(std::ostream& _Os, deque_blocks<_DequeType> const& _Value) {
		for (size_t i = 0, j = _Value.capacity(); i < j; i++) {
			_Os << _Value.get_element_by_offset(i) << ' ';
		}

		return _Os;
	}
};

