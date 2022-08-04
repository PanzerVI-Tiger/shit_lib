export module mylib.deque;

import std.core;
import mylib.iterator;

export namespace mylib {

    template<typename DequeType>
    struct deque_const_iterator {
        using difference_type   = typename DequeType::difference_type;
        using size_type         = typename DequeType::size_type;
        using block_type        = typename DequeType::block_type;
        using reference         = typename DequeType::reference;
        using const_reference   = typename DequeType::const_reference;
        using pointer           = typename DequeType::pointer;
        using value_type        = typename DequeType::value_type;
        using iterator_category = mylib::random_access_iterator_tag;
        
        constexpr static size_type block_size = block_type::block_size;

        constexpr deque_const_iterator() noexcept : container{}, position{} {}

        constexpr deque_const_iterator(const DequeType* pDeque, size_type index) noexcept :
            container{ const_cast<DequeType*>(pDeque) }, position{ index } {}

        constexpr const_reference operator *() const noexcept {
            return (*container)[position];
        }

        constexpr pointer operator ->() const noexcept {
            return &(*container)[position];
        }

        constexpr const_reference operator [](difference_type const& offset) const noexcept {
            return (*container)[position + offset];
        }

        constexpr deque_const_iterator& operator ++() noexcept {
            ++position;
            return *this;
        }

        constexpr deque_const_iterator  operator ++(int) noexcept {
            deque_const_iterator temp = *this;
            ++position;
            return temp;
        }

        constexpr deque_const_iterator& operator +=(difference_type index) noexcept {
            position += index;
            return *this;
        }

        constexpr deque_const_iterator  operator +(difference_type index) noexcept {
            deque_const_iterator result{ *this };
            return result += index;
        }

        constexpr deque_const_iterator  operator +(difference_type index) const noexcept {
            deque_const_iterator result{ *this };
            result.position += index;
            return result;
        }

        constexpr deque_const_iterator& operator --() noexcept {
            --position;
            return *this;
        }

        constexpr deque_const_iterator  operator --(int) noexcept {
            deque_const_iterator temp = *this;
            --position;
            return temp;
        }

        constexpr deque_const_iterator& operator -=(difference_type index) noexcept {
            operator +=(-index);
            return *this;
        }

        constexpr deque_const_iterator  operator -(difference_type index) noexcept {
            deque_const_iterator result{ *this };
            return result -= index;
        }

        constexpr deque_const_iterator  operator -(difference_type index) const noexcept {
            deque_const_iterator result{ *this };
            result.position -= index;
            return result;
        }

        constexpr bool operator ==(deque_const_iterator const& right) const noexcept {
            return position == right.position;
        }

        const DequeType* container;
        size_type        position;
    };

    template<typename DequeType>
    struct deque_iterator :
        deque_const_iterator<DequeType> {
        
        using deque_const_iterator<DequeType>::container;
        using deque_const_iterator<DequeType>::position;

        using difference_type   = typename DequeType::difference_type;
        using size_type         = typename DequeType::size_type;
        using block_type        = typename DequeType::block_type;
        using reference         = typename DequeType::reference;
        using const_reference   = typename DequeType::const_reference;
        using pointer           = typename DequeType::pointer;
        using value_type        = typename DequeType::value_type;
        using iterator_category = mylib::random_access_iterator_tag;
        
        constexpr static size_type block_size = block_type::block_size;

        constexpr deque_iterator() noexcept : deque_const_iterator<DequeType>{} {}
        
        constexpr deque_iterator(DequeType* pDeque, size_type index) noexcept :
            deque_const_iterator<DequeType>{ pDeque, index } {}

        constexpr reference operator *() const noexcept {
            return static_cast<reference>((*container)[position]);
        }

        constexpr pointer operator ->() const noexcept {
            return static_cast<pointer>(&(*container)[position]);
        }

        constexpr reference operator [](difference_type const& offset) const noexcept {
            return (*container)[position + offset];
        }

        constexpr deque_iterator& operator ++() noexcept {
            ++position;
            return *this;
        }

        constexpr deque_iterator  operator ++(int) noexcept {
            deque_iterator temp = *this;
            ++position;
            return temp;
        }

        constexpr deque_iterator& operator +=(difference_type index) noexcept {
            position += index;
            return *this;
        }

        constexpr deque_iterator  operator +(difference_type index) noexcept {
            deque_iterator result{ *this };
            return result += index;
        }

        constexpr deque_iterator  operator +(difference_type index) const noexcept {
            deque_iterator result{ *this };
            result.position += index;
            return result;
        }

        constexpr deque_iterator& operator --() noexcept {
            --position;
            return *this;
        }

        constexpr deque_iterator  operator --(int) noexcept {
            deque_iterator temp = *this;
            --position;
            return temp;
        }

        constexpr deque_iterator& operator -=(difference_type index) noexcept {
            operator +=(-index);
            return *this;
        }

        constexpr deque_iterator  operator -(difference_type index) noexcept {
            deque_iterator result{ *this };
            return result -= index;
        }

        constexpr deque_iterator  operator -(difference_type index) const noexcept {
            deque_iterator result{ *this };
            result.position -= index;
            return result;
        }
    };

    template<typename DequeType>
    struct deque_block {
        using size_type       = typename DequeType::size_type;
        using value_type      = typename DequeType::value_type;
        using reference       = typename DequeType::reference;
        using const_reference = typename DequeType::const_reference;
        using pointer         = typename DequeType::pointer;
        using difference_type = typename DequeType::difference_type;

        static constexpr size_type element_bytes = sizeof(value_type);
        static constexpr size_type block_size    = element_bytes <= 1 ? 16
                                                 : element_bytes <= 2 ? 8
                                                 : element_bytes <= 4 ? 4
                                                 : element_bytes <= 8 ? 2
                                                 : 1;
        static constexpr size_type block_bytes   = element_bytes * block_size;
        static constexpr size_type exponent      = std::bit_width(std::bit_ceil(block_size)) - 1;

        constexpr deque_block(deque_block const& other) noexcept :
                numberOfBlocks{ other.numberOfBlocks }, numberOfElement{ other.numberOfElement },
                head{ other.head } {
            map = ::new pointer[numberOfBlocks];
            for (size_type i = 0; i < numberOfBlocks; ++i) {
                map[i] = ::new value_type[block_size];
                for (size_type j = 0; j < block_size; ++j) {
                    map[i][j] = other.map[i][j];
                }
            }
        }
        
        constexpr deque_block(deque_block&& other) noexcept :
                numberOfBlocks{ other.numberOfBlocks }, numberOfElement{ other.numberOfElement },
                head{ other.head }, map{ other.map } {
            other.numberOfBlocks   = 0;
            other.numberOfElement  = 0;
            other.head             = 0;
            other.map              = nullptr;
        }
        
        constexpr deque_block() : map{ nullptr }, head{}, numberOfElement{}, numberOfBlocks{} {}
        
        constexpr deque_block(std::initializer_list<value_type> initializerList) noexcept {
            size_t const elementSize = initializerList.size();
            head = 0;
            numberOfElement = elementSize;
            numberOfBlocks  = std::bit_ceil(elementSize / block_size + bool(elementSize % block_size));
            map             = ::new pointer[numberOfBlocks];

            auto beginIterator = initializerList.begin();
            auto const endIterator = initializerList.end();
            for (size_type i = 0; i < numberOfBlocks; ++i) {
                map[i] = ::new value_type[block_size];
                for (size_t j = 0; beginIterator != endIterator && j < block_size; ++j, ++beginIterator) {
                    map[i][j] = *beginIterator;
                }
            }
        }

        constexpr ~deque_block() {
            for (size_type i = 0; i < numberOfBlocks; ++i) {
                ::delete[] map[i];
            }
            ::delete[] map;
        }

        constexpr deque_block& operator =(deque_block const& other) noexcept {
            if (this != &other) {
                for (size_type i = 0; i < numberOfBlocks; ++i) {
                    ::delete[] map[i];
                }
                ::delete[] map;

                numberOfBlocks   = other.numberOfBlocks;
                numberOfElement  = other.numberOfElement;
                head             = other.head;
                map              = ::new pointer[numberOfBlocks];
                for (size_type i = 0; i < numberOfBlocks; ++i) {
                    map[i]       = ::new value_type[block_size];
                    for (size_type j = 0; j < block_size; ++j) {
                        map[i][j] = other.map[i][j];
                    }
                }
            }
            return *this;
        }

        constexpr deque_block& operator =(deque_block&& other) noexcept {
            if (this != &other) {
                for (size_type i = 0; i < numberOfBlocks; ++i) {
                    ::delete[] map[i];
                }
                ::delete[] map;

                numberOfBlocks         = other.numberOfBlocks;
                numberOfElement        = other.numberOfElement;
                head                   = other.head;
                map                    = other.map;

                other.numberOfBlocks   = 0;
                other.numberOfElement  = 0;
                other.head             = 0;
                other.map              = nullptr;
            }
            return *this;
        }

        constexpr void swap(deque_block& right) noexcept {
            std::swap(numberOfElement, right.numberOfElement);
            std::swap(numberOfBlocks , right.numberOfBlocks );
            std::swap(head           , right.head           );
            std::swap(map            , right.map            );
        }

        constexpr size_type get_block_offset(size_type offset) const noexcept {
            return (offset >> exponent) & (numberOfBlocks - 1);
        }

        static constexpr size_type get_block_offset(size_type offset, size_type blockCount) noexcept {
            return (offset >> exponent) & (blockCount - 1);
        }

        constexpr size_type get_relative_offset(size_type offset) const noexcept {
            return offset & (block_size - 1);
        }

        static constexpr size_type get_relative_offset(size_type offset, size_type blockSize) noexcept {
            return offset & (blockSize - 1);
        }

        constexpr size_type get_rear_offset() const noexcept {
            return head + numberOfElement - 1;
        }

        constexpr size_type size() const noexcept {
            return numberOfElement;
        }

        constexpr size_type map_size() const noexcept {
            return numberOfBlocks;
        }

        constexpr size_type capacity() const noexcept {
            return numberOfBlocks << exponent;
        }

        constexpr reference operator [](size_type index) noexcept {
            return get_element_by_index(index);
        }

        constexpr const reference operator [](size_type index) const noexcept {
            return get_element_by_index(index);
        }

        constexpr reference get_element_by_index(size_type index) noexcept {
            size_type const offset = index + head;
            return map[get_block_offset(offset)][get_relative_offset(offset)];
        }

        constexpr const reference get_element_by_index(size_type index) const noexcept {
            size_type const offset = index + head;
            return map[get_block_offset(offset)][get_relative_offset(offset)];
        }

        constexpr reference get_element_by_offset(size_type offset) noexcept {
            return map[get_block_offset(offset)][get_relative_offset(offset)];
        }

        constexpr const reference get_element_by_offset(size_type offset) const noexcept {
            return map[get_block_offset(offset)][get_relative_offset(offset)];
        }

        constexpr void clear() noexcept {
            for (size_type i = 0, limit = map_size(); i < limit; ++i) {
                ::delete[] map[i];
            }
            ::delete[] map;
            numberOfBlocks  = 0;
            numberOfElement = 0;
        }

        pointer*  map;            // a array of pointer to value_type
        size_type head;
        size_type numberOfElement;
        size_type numberOfBlocks; // hold it's value is 2 ^ N or 0
    };

    template<typename _ElementType, typename _Allocator = std::allocator<_ElementType>>
    class deque {
    public:
        using size_type              = typename std::allocator_traits<_Allocator>::size_type;

        using value_type             = _ElementType;

        using block_type             = deque_block<deque<_ElementType, _Allocator>>;

        using allocator_type         = _Allocator;

        using reference              = value_type&;

        using const_reference        = const value_type&;

        using difference_type        = typename std::allocator_traits<_Allocator>::difference_type;

        using pointer                = typename std::allocator_traits<_Allocator>::pointer;
        using const_point            = typename std::allocator_traits<_Allocator>::const_pointer;

        using iterator               = deque_iterator<deque<_ElementType, _Allocator>>;
        using reverse_iterator       = std::reverse_iterator<iterator>;
        using const_iterator         = deque_const_iterator<deque<_ElementType, _Allocator>>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    private:
        template<typename ValueType>
        constexpr void extend(size_type magnification, ValueType&& value) noexcept {
            if (magnification <= 1) {
                return;
            }
        
            if (size() == 0) {
                data.map = ::new pointer[2]{
                    ::new value_type[block_type::block_size],
                    ::new value_type[block_type::block_size]
                };
                    
                data.numberOfBlocks  = 2;
                data.numberOfElement = 0;

                return;
            }
            
            magnification = std::bit_ceil(magnification); // make magnification equal to 2 ^ N  
            size_type        previousMapSize = data.numberOfBlocks;
            size_type const previousCapacity = data.capacity();
            data.numberOfBlocks            <<= std::bit_width(magnification) - 1;
            size_type           previousHead = data.head;

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

            if constexpr (std::is_lvalue_reference_v<ValueType&&>) {
                for (size_type i = previousMapSize; i < data.numberOfBlocks; ++i) {
                    data.map[i] = ::new value_type[data.block_size];
                    for (size_type j = 0; j < data.block_size; ++j) {
                        data.map[i][j] = value;
                    }
                }
            }

            // copy from head to rear
            size_type        previousBlockOffset = data.get_block_offset   (previousHead,        previousMapSize);
            size_type         currentBlockOffset = data.get_block_offset   (data.head                           );
            size_type const      rearBlockOffset = data.get_block_offset   (data.head + data.numberOfElement - 1);
            size_type const   headRelativeOffset = data.get_relative_offset(data.head                           );
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

        template<typename ValueType>
        constexpr iterator insert_internal(const_iterator where, ValueType&& value) noexcept {
            size_type previousSize = data.size();
            if (previousSize == data.capacity()) {
                extend(2, std::forward<ValueType>(value));
            }
            ++data.numberOfElement;

            // no to move any element if _Were is first iterator, then insert new element in front of the where
            if (where == cbegin()) {
                data.head = (data.head - 1) & (data.capacity() - 1);
                data[0]   = std::forward<ValueType>(value);

                return begin();
            }

            // move front element when where is in front part, else move before element
            if (where.position > (previousSize >> 1)) {
                reverse_iterator       destination{ rbegin() };
                const_reverse_iterator source{ destination + 1 };
                const_reverse_iterator beforeWhere{ where + 1 };
                for (; destination !=  beforeWhere; ++destination, ++source) {
                    *destination = std::move(*source);
                }
                if constexpr (std::is_lvalue_reference_v<ValueType&&>) {
                    *destination = value;
                }
            } else {
                data.head = (data.head - 1) & (data.capacity() - 1);
                iterator       destination{ begin() };
                const_iterator source     { destination + 1 };
                const_iterator afterWhere { where };
                for (; destination != afterWhere; ++destination, ++source) {
                    *destination    = std::move(*source);
                }
                if constexpr (std::is_lvalue_reference_v<ValueType&&>) {
                    *destination = value;
                }
            }

            return iterator{ this, where.position };
        }

    public:
        constexpr deque() noexcept : data{} {}
        
        constexpr explicit deque(deque const& other) noexcept : data{ other.data } {}
        
        constexpr explicit deque(deque&& other) noexcept : data{ std::move(other.data) } {}
        
        template<std::input_iterator _InputIterator>
        constexpr deque(_InputIterator first, _InputIterator last) noexcept {
            insert(cbegin(), first, last);
        }

        template<std::ranges::range Range>
        constexpr deque(const Range& range) noexcept : 
            deque(std::ranges::begin(range), std::ranges::end(range))
        {}
        
        constexpr deque(std::initializer_list<value_type> initialValueList) noexcept : 
            deque(initialValueList.begin(), initialValueList.end()) 
        {}
        
        constexpr ~deque() noexcept {}

        constexpr deque& operator=(deque const& other) noexcept {
            data = other.data;
            return *this;
        }

        constexpr deque& operator=(deque&& other) noexcept {
            data = std::move(other.data);
            return *this;
        }

        constexpr void swap(deque& right) noexcept {
            data.swap(right.data);
        }

        constexpr void push_back(value_type&& value) noexcept {
            if (data.size() == data.capacity()) {
                extend(2, value_type{});
            }
            data[data.size()] = std::move(value);
            ++data.numberOfElement;
        }

        constexpr void push_back(const value_type& value) noexcept {
            if (data.size() == data.capacity()) {
                extend(2, value_type{});
            }
            data[data.size()] = value;
            ++data.numberOfElement;
        }

        constexpr void push_front(value_type&& value) noexcept {
            if (data.size() == data.capacity()) {
                extend(2, value_type{});
            }
            data.head = (data.head - 1) & (data.capacity() - 1);
            data[0] = std::move(value);
            ++data.numberOfElement;
        }

        constexpr void push_front(const value_type& value) noexcept {
            if (data.size() == data.capacity()) {
                extend(2, value_type{});
            }
            data.head = (data.head - 1) & (data.capacity() - 1);
            data[0] = value;
            ++data.numberOfElement;
        }

        constexpr void pop_back() noexcept {
            --data.numberOfElement;
        }

        constexpr void pop_front() noexcept {
            --data.numberOfElement;
            data.head = (data.head + 1) & (data.capacity() - 1);
        }

        constexpr reference front() noexcept {
            return data[0];
        }

        constexpr const_reference front() const noexcept {
            return data[0];
        }

        constexpr reference back() noexcept {
            return data[data.size() - 1];
        }

        constexpr const_reference back() const noexcept {
            return data[data.size() - 1];
        }

        constexpr reference operator [](size_type index) noexcept {
            return data[index];
        }

        constexpr reference operator [](size_type index) const noexcept {
            return data[index];
        }

        constexpr size_type size() const noexcept {
            return data.size();
        }

        constexpr bool empty() const noexcept {
            return size() == size_type{ 0 };
        }

        constexpr iterator insert(const_iterator where, const value_type& value) noexcept {
            return insert_internal(where, value);
        }

        constexpr iterator insert(const_iterator where, value_type&& value) noexcept {
            return insert_internal(where, std::move(value));
        }

        constexpr iterator insert(const_iterator where, size_type count,const value_type& value) noexcept {
            size_type previousSize = data.size();
            if (previousSize + count >= data.capacity()) {
                resize(previousSize + count);
            }
            data.numberOfElement += count;

            if (where == cbegin()) {
                data.head = (data.head - count) & (data.capacity() - 1);
                for (size_type i = 0; i < count; ++i) {
                    data[i] = value;
                }
                return begin();
            }

            if (where.position > (previousSize >> 1)) {
                reverse_iterator       destination{ rbegin() };
                const_reverse_iterator source{ destination + count };
                const_reverse_iterator beforeWhere{ where + 1 };
                for (; destination != beforeWhere; ++destination, ++source) {
                    *destination = std::move(*source);
                }
            } else {
                data.head = (data.head - count) & (data.capacity() - 1);
                iterator       destination{ begin() };
                const_iterator source{ destination + count };
                const_iterator afterWhere{ where };
                for (; destination != afterWhere; ++destination, ++source) {
                    *destination = std::move(*source);
                }
            }
            for (size_type i = 0, j = where.position; i < count; ++i, ++j) {
                data[j] = value;
            }
            return iterator{ &data, where.position };
        }

        template<std::input_iterator _InputIterator>
        constexpr iterator insert(const_iterator where, _InputIterator first, _InputIterator last) noexcept {
            iterator result = iterator{ this, where.position };
            while (first != last) {
                result = insert(where++, std::move(*first++));
            }
            return result;
        }

        constexpr iterator insert(const_iterator where, std::initializer_list<value_type> initializerList) noexcept {
            return insert(where, initializerList.begin(), initializerList.end());
        }

        constexpr iterator erase(const_iterator where) noexcept {
            if (where.position == 0) {
                data.head = (data.head + 1) & (data.capacity() - 1);
                --data.numberOfElement;
                return begin();
            }
            const_iterator source   { where + 1 };
            const_iterator afterRear{ cend() };
            for (
                iterator destination{ &data, where.position };
                source != afterRear;
                ++source, ++destination
            ) {
                *destination = std::move(*source);
            }
            --data.numberOfElement;

            return iterator{ &data, where.position };
        }

        constexpr iterator erase(const_iterator first, const_iterator last) noexcept {
            size_type numOfEraseElement = last.position - first.position;
            if (first.position == 0) {
                data.head = last.position; 
                data.numberOfElement -= numOfEraseElement;
                return begin();
            }
            const_iterator source   { last };
            const_iterator afterRear{ cend() };
            for (
                iterator destination{ &data, first.position };
                destination != afterRear;
                ++source, ++destination
            ) {
                *destination = std::move(*source);
            }
            data.numberOfElement -= numOfEraseElement;

            return iterator{ &data, first.position };
        }

        constexpr iterator find(iterator first, iterator last, const value_type& value) noexcept {
            return std::find(first, last, value);
        }

        constexpr const_iterator find(const_iterator first, const_iterator last, const value_type& value) const noexcept {
            return std::find(first, last, value);
        }

        template<typename _UnaryPredicate>
        constexpr iterator find_if(iterator first, iterator last, _UnaryPredicate pred) noexcept {
            return std::find_if(first, last, pred);
        }

        template<typename _UnaryPredicate>
        constexpr const_iterator find_if(const_iterator first, const_iterator last, _UnaryPredicate pred) const noexcept {
            return std::find_if(first, last, pred);
        }

        constexpr size_type remove(const value_type& value) noexcept {
            iterator  head{ begin() };
            size_type firstSize{ size() };
            while (true) {
                head = find(head, end(), value);
                if (head != end()) {
                    erase(head);
                } else {
                    break;
                }
            }
            return firstSize - size();
        }

        template<typename _UnaryPredicate>
        constexpr size_type remove_if(_UnaryPredicate pred) noexcept {
            iterator head{ begin() };
            size_type firstSize{ size() };
            while (true) {
                head = find_if(head, end(), pred);
                if (head != end()) {
                    erase(head);
                } else {
                    break;
                }
            }
            return firstSize - size();
        }

        constexpr void clear() noexcept {
            erase(cbegin(), cend());
        }

        constexpr void resize(size_type newSize) noexcept {
            if (size() == 0) {
                extend(2, std::move(value_type{}));
                extend((newSize >> 1) + (newSize & 1), std::move(value_type{}));
            } else if (newSize > size()) {
                extend(newSize / size() + bool(newSize % size()), std::move(value_type{}));
            }
            data.numberOfElement = newSize;
        }

        constexpr void resize(size_type newSize, const value_type& value) noexcept {
            if (size() == 0) {
                extend(2, value);
                extend((newSize >> 1) + (newSize & 1), value);
            } else if (newSize > size()) {
                extend(newSize / size() + bool(newSize % size()), value);
            }
            data.numberOfElement = newSize;
        }

        constexpr void shrink_to_fit() noexcept {
            size_type const     numOfElement = data.size();
            size_type const previousCapacity = data.capacity();
            if (previousCapacity < (numOfElement << 1)) {
                return;
            }

            // make minification equal to 2 ^ N  
            size_type previousMapSize = data.map_size();
            size_type    minification = std::bit_floor(previousMapSize / ((numOfElement >> block_type::exponent) + bool(numOfElement & (block_type::block_size - 1))));
            data.numberOfBlocks     >>= std::bit_width(minification) - 1;
            size_type    previousHead = data.head;
            size_type    previousRear = data.get_rear_offset();

            // change head when head is behind the rear
            if (previousHead > (data.get_rear_offset() & (previousCapacity - 1))) {
                data.head             = (data.head + (previousMapSize - data.numberOfBlocks) * block_type::block_size) & ((data.numberOfBlocks << block_type::exponent) - 1);
            } else {
                data.head             = data.get_relative_offset(data.head);
            }
            pointer*  previousMap     = ::new pointer[data.numberOfBlocks]; // allocate new memory then swap
            std::swap(data.map, previousMap);

            size_type const          currentMapSize = data.map_size        (                             );
            size_type           previousBlockOffset = data.get_block_offset(previousRear, previousMapSize);
            size_type            currentBlockOffset = data.get_block_offset(data.get_rear_offset(       ));
            size_type const  currentHeadBlockOffset = data.get_block_offset(data.head                    );
            size_type const previousHeadBlockOffset = data.get_block_offset(previousHead, previousMapSize);

            // copy from rear to head
            if (currentHeadBlockOffset == currentBlockOffset) {
                while (true) {
                    data.map[currentBlockOffset] = previousMap[previousBlockOffset];
                    currentBlockOffset           = (currentBlockOffset  - 1) & (currentMapSize  - 1);
                    previousBlockOffset          = (previousBlockOffset - 1) & (previousMapSize - 1);
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
                    data.map[currentBlockOffset] = std::move(previousMap[previousBlockOffset]);
                }
            }
            ::delete[] previousMap;
        }

        constexpr iterator begin() noexcept {
            return iterator{ this, 0 };
        }

        constexpr const_iterator begin() const noexcept {
            return cbegin();
        }

        constexpr const_iterator cbegin() const noexcept {
            return const_iterator{ this, 0 };
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
            return iterator{ this, size() };
        }

        constexpr const_iterator end() const noexcept {
            return cend();
        }

        constexpr const_iterator cend() const noexcept {
            return const_iterator{ this, size() };
        }

        constexpr reverse_iterator rend() noexcept {
            return const_reverse_iterator{ begin() };
        }

        constexpr const_reverse_iterator rend() const noexcept {
            return crend();
        }

        constexpr const_iterator crend() const noexcept {
            return const_reverse_iterator{ cbegin() };
        }

    private:
        block_type data;
    };

    template<std::ranges::range Range>
    deque(const Range& range) -> deque<std::ranges::range_value_t<Range>>;

    // test fuction, check deque's map
    template<typename DequeType>
    std::ostream& operator <<(std::ostream& _Os, deque_block<DequeType> const& value) {
        for (size_t i = 0, j = value.capacity(); i < j; i++) {
            _Os << value.get_element_by_offset(i) << ' ';
        }

        return _Os;
    }
};
