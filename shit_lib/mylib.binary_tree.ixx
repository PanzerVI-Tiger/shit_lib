export module mylib.binary_tree;

import std.core;
import mylib.queue;

export namespace mylib {

	template<typename _BinaryTreeNodeType>
	typename _BinaryTreeNodeType::size_type tree_size(
		const	 _BinaryTreeNodeType*			_PNode,
		typename _BinaryTreeNodeType::size_type _Count = 0
	) noexcept {
		if (_PNode == nullptr) {
			return _Count;
		}
		return tree_size(_PNode->pLeftNode, _Count + 1) + tree_size(_PNode->pRightNode, _Count + 1);
	}

	template<typename _KeyType, typename _Allocator>
	struct key_binary_tree_node {
		using value_type	  = std::remove_reference_t<_KeyType>;
		using key_type		  = value_type;

		using size_type		  = typename std::allocator_traits<_Allocator>::size_type;

		using node_type		  = key_binary_tree_node;
		using node_pointer	  = node_type*;

		using allocator_type  = _Allocator;

		using reference		  = value_type&;

		using const_reference = const value_type&;

		constexpr bool has_parent_node() const noexcept {
			return false;
		}

		constexpr key_binary_tree_node(const value_type& _Data, node_pointer _PLeftNode = nullptr,
			node_pointer _PRightNode = nullptr) noexcept :
				valueData{ _Data }, pLeftNode{ _PLeftNode }, pRightNode{ _PRightNode } {}

		constexpr key_binary_tree_node(value_type&& _Data, node_pointer _PLeftNode = nullptr,
			node_pointer _PRightNode = nullptr) noexcept :
				valueData{ std::move(_Data) }, pLeftNode{ _PLeftNode }, pRightNode{ _PRightNode } {}

		constexpr key_binary_tree_node() noexcept : valueData{}, pLeftNode{ nullptr }, pRightNode{ nullptr } {}

		constexpr key_binary_tree_node(const key_binary_tree_node&) noexcept = delete;

		constexpr key_binary_tree_node(key_binary_tree_node&& _Other) noexcept {
			*this = std::move(_Other);
		}

		constexpr ~key_binary_tree_node() noexcept {
			if (pLeftNode != nullptr) {
				delete pLeftNode;
			}
			if (pRightNode != nullptr) {
				delete pRightNode;
			}
		}

		constexpr node_type& operator =(const key_binary_tree_node&) noexcept = delete;

		constexpr node_type& operator =(key_binary_tree_node&& _Right) noexcept {
			valueData = std::move(_Right.valueData);
			pLeftNode = _Right.pLeftNode;
			pRightNode = _Right.pRightNode;
			_Right.pLeftNode = nullptr;
			_Right.pRightNode = nullptr;
			return *this;
		}

		constexpr static node_pointer make_new(const node_pointer _PNode) noexcept {
			if (_PNode == nullptr) {
				return nullptr;
			}
			return new node_type{ _PNode->value(), make_new(_PNode->left()), make_new(_PNode->right()) };
		}

		constexpr node_pointer& left() noexcept {
			return pLeftNode;
		}

		constexpr const node_pointer& left() const noexcept {
			return pLeftNode;
		}

		constexpr node_pointer& right() noexcept {
			return pRightNode;
		}

		constexpr const node_pointer& right() const noexcept {
			return pRightNode;
		}

		constexpr reference value() noexcept {
			return valueData;
		}

		constexpr const_reference value() const noexcept {
			return valueData;
		}

		node_pointer pLeftNode;
		node_pointer pRightNode;
		value_type   valueData;
	};

	template<typename _KeyType, typename _MappedType, typename _Allocator>
	struct pair_binary_tree_node :
		public key_binary_tree_node<std::pair<_KeyType, _MappedType>, _Allocator> {

		using base_type		  = key_binary_tree_node<std::pair<_KeyType, _MappedType>, _Allocator>;

		using key_type		  = _KeyType;
		using mapped_type	  = _MappedType;
		using value_type	  = std::pair<_KeyType, _MappedType>;

		using size_type		  = typename base_type::size_type;

		using node_type		  = pair_binary_tree_node;
		using node_pointer	  = pair_binary_tree_node*;

		using allocator_type  = _Allocator;

		using reference		  = value_type&;

		using const_reference = const value_type&;

		using base_type::pLeftNode;
		using base_type::pRightNode;
		using base_type::valueData;

		constexpr bool has_parent_node() const noexcept {
			return false;
		}

		constexpr pair_binary_tree_node(const value_type& _Pair, node_pointer _PLeftNode = nullptr,
			node_pointer _PRightNode = nullptr) noexcept :
			base_type{ _Pair, _PLeftNode, _PRightNode } {}

		constexpr pair_binary_tree_node(value_type&& _Pair, node_pointer _PLeftNode = nullptr,
			node_pointer _PRightNode = nullptr) noexcept :
			base_type{ std::move(_Pair), _PLeftNode, _PRightNode } {}

		constexpr pair_binary_tree_node(const key_type& _Key, const mapped_type& _Mapped, node_pointer _PLeftNode, node_pointer _PRightNode = nullptr) noexcept :
			base_type{ std::make_pair(_Key, _Mapped), _PLeftNode, _PRightNode } {}

		constexpr pair_binary_tree_node(key_type&& _Key, mapped_type&& _Mapped, node_pointer _PLeftNode = nullptr, node_pointer _PRightNode = nullptr) noexcept :
			base_type{ std::make_pair(std::move(_Key), std::move(_Mapped)), _PLeftNode, _PRightNode } {}

		constexpr pair_binary_tree_node() noexcept : base_type{} {}

		constexpr pair_binary_tree_node(const pair_binary_tree_node&) noexcept = delete;

		constexpr pair_binary_tree_node(pair_binary_tree_node&& _Other) noexcept :
			base_type{ std::move(_Other) } {}

		constexpr node_type& operator =(const pair_binary_tree_node& _Right) noexcept = delete;

		constexpr node_type& operator =(pair_binary_tree_node&& _Right) noexcept {
			return base_type::operator =(std::move(_Right));
		}

		constexpr static node_pointer make_new(const node_pointer _PNode) noexcept {
			
			return reinterpret_cast<node_pointer>(base_type::make_new(_PNode));
		}

		constexpr node_pointer& left() noexcept {
			return reinterpret_cast<node_pointer&>(pLeftNode);
		}

		constexpr const node_pointer& left() const noexcept {
			return reinterpret_cast<node_pointer&>(pLeftNode);
		}

		constexpr node_pointer& right() noexcept {
			return reinterpret_cast<node_pointer&>(pRightNode);
		}

		constexpr const node_pointer& right() const noexcept {
			return reinterpret_cast<node_pointer&>(pRightNode);
		}

		constexpr mapped_type& mapped() noexcept {
			return this->value().second;
		}

		constexpr const mapped_type& mapped() const noexcept {
			return this->value().second;
		}

		constexpr key_type& key() noexcept {
			return this->value().first;
		}

		constexpr const key_type& key() const noexcept {
			return this->value().first;
		}
	};

	template<typename _KeyType, typename _Compare, typename _Allocator>
	struct key_binary_search_tree_node : 
		public key_binary_tree_node<_KeyType, _Allocator> {

		using base_type		  = key_binary_tree_node<_KeyType, _Allocator>;
		using value_type	  = std::remove_reference_t<_KeyType>;
		using key_type		  = value_type;
		
		using value_compare   = _Compare;
		using key_compare	  = value_compare;

		using size_type		  = typename std::allocator_traits<_Allocator>::size_type;

		using node_type		  = key_binary_search_tree_node;
		using node_pointer    = node_type*;

		using allocator_type  = _Allocator;

		using reference		  = value_type&;

		using const_reference = const value_type&;

		using base_type::pLeftNode;
		using base_type::pRightNode;
		using base_type::valueData;

		constexpr bool has_parent_node() const noexcept {
			return false;
		}

		constexpr key_binary_search_tree_node(const value_type& _Data, node_pointer _PLeftNode = nullptr,
				node_pointer _PRightNode = nullptr) noexcept :
			valueData{ _Data }, pLeftNode{ _PLeftNode }, pRightNode{ _PRightNode } {}

		constexpr key_binary_search_tree_node(value_type&& _Data, node_pointer _PLeftNode = nullptr,
			node_pointer _PRightNode = nullptr) noexcept :
			valueData{ std::move(_Data) }, pLeftNode{ _PLeftNode }, pRightNode{ _PRightNode } {}

		constexpr key_binary_search_tree_node() noexcept : valueData{}, pLeftNode{ nullptr }, pRightNode{ nullptr } {}

		constexpr key_binary_search_tree_node(const key_binary_search_tree_node&) noexcept = delete;
		
		constexpr key_binary_search_tree_node(key_binary_search_tree_node&& _Other) noexcept{
			*this = std::move(_Other);
		}

		constexpr ~key_binary_search_tree_node() noexcept {
			if (pLeftNode != nullptr) {
				delete pLeftNode;
			}
			if (pRightNode != nullptr) {
				delete pRightNode;
			}
		}
		
		constexpr node_type& operator =(const key_binary_search_tree_node&) noexcept = delete;
		
		constexpr node_type& operator =(key_binary_search_tree_node&& _Right) noexcept {
			return base_type::operator =(std::move(_Right));
		}
		
		constexpr bool operator <(const value_type& _Right) const noexcept {
			return value_compare{}(this->value(), _Right);
		}

		constexpr bool operator >(const value_type& _Right) const noexcept {
			return value_compare{}(_Right, this->value());
		}

		constexpr bool operator ==(const value_type& _Right) const noexcept {
			return value_compare{}(this->value(), _Right) == false && value_compare{}(_Right, this->value()) == false;
		}

		constexpr bool operator <(const node_type& _Right) const noexcept {
			return value_compare{}(this->value(), _Right.value());
		}

		constexpr bool operator >(const node_type& _Right) const noexcept {
			return value_compare{}(_Right.value(), this->value());
		}

		constexpr bool operator ==(const node_type& _Right) const noexcept {
			return value_compare{}(this->value(), _Right.value()) == false && value_compare{}(_Right.value(), this->value()) == false;
		}

		constexpr static node_pointer make_new(const node_pointer _PNode) noexcept {
			if (_PNode == nullptr) {
				return nullptr;
			}
			return new node_type{ _PNode->value(), make_new(_PNode->left()), make_new(_PNode->right()) };			
		}
		
		constexpr node_pointer& left() noexcept {
			return reinterpret_cast<node_pointer&>(pLeftNode);
		}

		constexpr const node_pointer& left() const noexcept {
			return reinterpret_cast<node_pointer&>(pLeftNode);
		}

		constexpr node_pointer& right() noexcept {
			return reinterpret_cast<node_pointer&>(pRightNode);
		}

		constexpr const node_pointer& right() const noexcept {
			return reinterpret_cast<node_pointer&>(pRightNode);
		}
	};

	template<typename _KeyType, typename _MappedType, typename _Compare, typename _Allocator>
	struct pair_binary_search_tree_node : 
			public key_binary_search_tree_node<std::pair<_KeyType, _MappedType>, _Compare, _Allocator> {

		using base_type		  = key_binary_search_tree_node<std::pair<_KeyType, _MappedType>, _Compare, _Allocator>;
		
		using key_type		  = std::remove_reference_t<_KeyType>;
		using mapped_type	  = std::remove_reference_t<_MappedType>;
		using value_type	  = std::pair<_KeyType, _MappedType>;
		
		using key_compare     = _Compare;
		
		using size_type		  = typename base_type::size_type;
		
		using node_type		  = pair_binary_search_tree_node;
		using node_pointer    = pair_binary_search_tree_node*;

		using allocator_type  = _Allocator;

		using reference		  = value_type&;

		using const_reference = const value_type&;

		using base_type::pLeftNode;
		using base_type::pRightNode;
		using base_type::valueData;
		
		class value_compare {
			public:				
			constexpr value_compare() noexcept = default;

			constexpr value_compare(const value_compare&) noexcept = default;

			constexpr value_compare(value_compare&&) noexcept = default;

			constexpr value_compare& operator=(const value_compare&) noexcept = default;

			constexpr value_compare& operator=(value_compare&&) noexcept = default;

			constexpr bool operator()(const value_type& _Left, const value_type& _Right) const noexcept {
				return _Left.first < _Right.first;
			}			
			 
		private:
			key_compare _Comp;
		};
		
		constexpr bool has_parent_node() const noexcept {
			return false;
		}

		constexpr pair_binary_search_tree_node(const value_type& _Pair, node_pointer _PLeftNode = nullptr,
				node_pointer _PRightNode = nullptr) noexcept :
			base_type{ _Pair, _PLeftNode, _PRightNode } {}
		
		constexpr pair_binary_search_tree_node(value_type&& _Pair, node_pointer _PLeftNode = nullptr,
			node_pointer _PRightNode = nullptr) noexcept :
			base_type{ std::move(_Pair), _PLeftNode, _PRightNode } {}
		
		constexpr pair_binary_search_tree_node(const key_type& _Key, const mapped_type& _Mapped, node_pointer _PLeftNode, node_pointer _PRightNode = nullptr) noexcept :
			base_type{ std::make_pair(_Key, _Mapped), _PLeftNode, _PRightNode } {}
		
		constexpr pair_binary_search_tree_node(key_type&& _Key, mapped_type&& _Mapped, node_pointer _PLeftNode = nullptr, node_pointer _PRightNode = nullptr) noexcept :
			base_type{ std::make_pair(std::move(_Key), std::move(_Mapped)), _PLeftNode, _PRightNode } {}
		
		constexpr pair_binary_search_tree_node() noexcept : base_type{} {}
		
		constexpr pair_binary_search_tree_node(const pair_binary_search_tree_node&) noexcept = delete;
		
		constexpr pair_binary_search_tree_node(pair_binary_search_tree_node&& _Other) noexcept :
			base_type{ std::move(_Other) } {}

		constexpr node_type& operator =(const pair_binary_search_tree_node& _Right) noexcept = delete;

		constexpr node_type& operator =(pair_binary_search_tree_node&& _Right) noexcept {
			return base_type::operator =(std::move(_Right));
		}

		constexpr bool operator <(const value_type& _Right) const noexcept {
			return key_compare{}(this->key(), _Right.first);
		}
		
		constexpr bool operator >(const value_type& _Right) const noexcept {
			return key_compare{}(_Right.first, this->key());
		}

		constexpr bool operator ==(const value_type& _Right) const noexcept {
			return key_compare{}(this->key(), _Right.first) == false && key_compare{}(_Right.first, this->key()) == false;
		}

		constexpr bool operator <(const key_type& _Right) const noexcept {
			return key_compare{}(this->key(), _Right);
		}

		constexpr bool operator >(const key_type& _Right) const noexcept {
			return key_compare{}(_Right, this->key());
		}

		constexpr bool operator ==(const key_type& _Right) const noexcept {
			return key_compare{}(this->key(), _Right) == false && key_compare{}(_Right, this->key()) == false;
		}

		constexpr bool operator <(const node_type& _Right) const noexcept {
			return key_compare{}(this->key(), _Right.key());
		}

		constexpr bool operator >(const node_type& _Right) const noexcept {
			return key_compare{}(_Right.key(), this->key());
		}

		constexpr bool operator ==(const node_type& _Right) const noexcept {
			return key_compare{}(this->key(), _Right.key()) == false && key_compare{}(_Right.key(), this->key()) == false;
		}
		
		constexpr static node_pointer make_new(const node_pointer _PNode) noexcept {
			if (_PNode == nullptr) {
				return nullptr;
			}
			return new node_type{ _PNode->value(), make_new(_PNode->left()), make_new(_PNode->right()) };
		}		
		
		constexpr node_pointer& left() noexcept {
			return reinterpret_cast<node_pointer&>(pLeftNode);
		}

		constexpr const node_pointer& left() const noexcept {
			return reinterpret_cast<node_pointer&>(pLeftNode);
		}

		constexpr node_pointer& right() noexcept {
			return reinterpret_cast<node_pointer&>(pRightNode);
		}

		constexpr const node_pointer& right() const noexcept {
			return reinterpret_cast<node_pointer&>(pRightNode);
		}
		
		constexpr mapped_type& mapped() noexcept {
			return this->value().second;
		}

		constexpr const mapped_type& mapped() const noexcept {
			return this->value().second;
		}

		constexpr key_type& key() noexcept {
			return this->value().first;
		}
		
		constexpr const key_type& key() const noexcept {
			return this->value().first;
		}		
	};
		
	template<
		typename _KeyType,
		typename _Allocator,
		typename _NodeType = key_binary_tree_node<_KeyType, _Allocator>
	>
	struct key_binary_tree_root_node {
		using value_type	  = _KeyType;

		using size_type		  = typename std::allocator_traits<_Allocator>::size_type;

		using node_type 	  = _NodeType;
		using node_pointer    = node_type*;

		using allocator_type  = _Allocator;

		using reference		  = value_type&;

		using const_reference = const value_type&;

		constexpr bool has_parent_node() const noexcept
		{
			return false;
		}

		constexpr key_binary_tree_root_node() noexcept : pRootNode{ nullptr }, numberOfNodes{ size_type{ 0 } } {}
		
		constexpr key_binary_tree_root_node(node_pointer _PRootNode) noexcept :
			pRootNode{ _PRootNode }, numberOfNodes{ tree_size(_PRootNode) } {}
		
		constexpr key_binary_tree_root_node(node_pointer _PRootNode, size_type _NumberOfNodes) noexcept :
			pRootNode{ _PRootNode }, numberOfNodes{ _NumberOfNodes } {}

		constexpr key_binary_tree_root_node(const key_binary_tree_root_node& _Other) noexcept :
			pRootNode{ node_type::make_new(_Other.pRootNode) }, numberOfNodes{_Other.numberOfNodes} {}

		constexpr key_binary_tree_root_node(key_binary_tree_root_node&& _Other) noexcept :
			pRootNode{ _Other.pRootNode }, numberOfNodes{ _Other.numberOfNodes } {
			_Other.pRootNode	 = nullptr;
			_Other.numberOfNodes = 0;
		}

		constexpr key_binary_tree_root_node& operator =(const key_binary_tree_root_node& _Right) noexcept {
			if (this != &_Right) {
				if (pRootNode != nullptr) {
					::delete pRootNode;
				}
				pRootNode	  = node_type::make_new(_Right.pRootNode);
				numberOfNodes = _Right.numberOfNodes;
			}
			return *this;
		}

		constexpr key_binary_tree_root_node& operator =(key_binary_tree_root_node&& _Right) noexcept {
			if (this != &_Right) {
				if (pRootNode != nullptr) {
					::delete pRootNode;
				}
				pRootNode			 = _Right.pRootNode;
				numberOfNodes		 = _Right.numberOfNodes;
				_Right.pRootNode	 = nullptr;
				_Right.numberOfNodes = 0;
			}
			return *this;
		}	

		constexpr ~key_binary_tree_root_node() noexcept {
			if (pRootNode != nullptr) {
				delete pRootNode;
			}
		}
		
		constexpr node_pointer& root() noexcept {
			return pRootNode;
		}

		constexpr const node_pointer& root() const noexcept {
			return pRootNode;
		}

		constexpr size_type size() const noexcept {
			return numberOfNodes;
		}
		
		constexpr void preorder_traversal(std::function<void(value_type&)> _Predicate) const noexcept {
			preorder_traversal(pRootNode, _Predicate);
		}

		constexpr void inorder_traversal(std::function<void(value_type&)> _Predicate) const noexcept {
			inorder_traversal(pRootNode, _Predicate);
		}

		constexpr void postorder_traversal(std::function<void(value_type&)> _Predicate) const noexcept {
			postorder_traversal(pRootNode, _Predicate);
		}

		constexpr void levelorder_traversal(std::function<void(node_pointer&)> _Predicate) const noexcept {
			levelorder_traversal(pRootNode, _Predicate);
		}

		constexpr void preorder_traversal(node_pointer _PNode, std::function<void(node_pointer&)> _Predicate) const noexcept {
			if (_PNode != nullptr) {
				_Predicate(_PNode->value());
				preorder_traversal(_PNode->left(), _Predicate);
				preorder_traversal(_PNode->right(), _Predicate);
			}
		}

		constexpr void inorder_traversal(node_pointer _PNode, std::function<void(node_pointer&)> _Predicate) const noexcept {
			if (_PNode != nullptr) {
				inorder_traversal(_PNode->left(), _Predicate);
				_Predicate(_PNode->value());
				inorder_traversal(_PNode->right(), _Predicate);
			}
		}

		constexpr void postorder_traversal(node_pointer _PNode, std::function<void(node_pointer&)> _Predicate) const noexcept {
			if (_PNode != nullptr) {
				postorder_traversal(_PNode->left(), _Predicate);
				postorder_traversal(_PNode->right(), _Predicate);
				_Predicate(_PNode->value());
			}
		}

		constexpr void levelorder_traversal(node_pointer _PNode, std::function<void(value_type&)> _Predicate) const noexcept {
			if (_PNode != nullptr) {
				queue<node_pointer> _Queue;
				_Queue.push(_PNode);
				while (!_Queue.empty()) {
					node_pointer _PNode = _Queue.front();
					_Queue.pop();
					_Predicate(_PNode->value());
					if (_PNode->left() != nullptr) {
						_Queue.push(_PNode->left());
					}
					if (_PNode->right() != nullptr) {
						_Queue.push(_PNode->right());
					}
				}
			}
		}
		
		constexpr std::vector<value_type> to_vector() const noexcept {
			return to_vector(*this);
		}

		constexpr void append_to_vector(std::vector<value_type>& _Result) const noexcept {
			to_vector(root(), _Result);
		}		
			
		constexpr static std::vector<value_type> to_vector(const key_binary_tree_root_node& _RootNode) noexcept {
			std::vector<value_type> result;
			append_to_vector(_RootNode.root(), result);
			return result;
		}

		constexpr static void append_to_vector(const node_pointer pNode, std::vector<value_type>& result) noexcept {
			if (pNode != nullptr) {
				append_to_vector(pNode->left(), result);
				result.push_back(pNode->value());
				append_to_vector(pNode->right(), result);
			}
		}

		constexpr const size_type depth() const noexcept {
			return depth(*this);
		}

		constexpr static const size_type depth(const key_binary_tree_root_node& _RootNode) noexcept {
			return depth(_RootNode.pRootNode);
		}

		constexpr static const size_type depth(const node_pointer pNode) noexcept {
			if (pNode == nullptr) {
				return 0;
			}

			size_type leftDepth = depth(pNode->left());
			size_type rightDepth = depth(pNode->right());

			return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
		}
		
		constexpr void draw_tree(char _NodeChar = 'O', char _EmptyChar = 'X', char _MidLineChar = ' ', std::ostream & _Os = std::cout) noexcept {
			draw_tree(*this, _NodeChar, _EmptyChar, _MidLineChar, _Os);
		}

		constexpr static void draw_tree(key_binary_tree_root_node& _RootNode, char _NodeChar = 'O', char _EmptyChar = 'X', char _MidLineChar = ' ', std::ostream& _Os = std::cout) noexcept {
			std::vector<std::vector<node_pointer>> tree;			
			size_type treeDepth = depth(_RootNode);
			tree.resize(treeDepth);
			
			tree[0].push_back(_RootNode.root());

			for (size_type i = 0; i < treeDepth - 1; ++i) {
				tree[i + 1].resize(1 << (i + 1));
				for (size_type j = 0; j < (1 << i); ++j) {
					if (tree[i][j] != nullptr) {
						tree[i + 1][ j << 1		] = tree[i][j]->left();
						tree[i + 1][(j << 1) + 1] = tree[i][j]->right();
					}
				}
			}
			
			size_type interval = 1 << treeDepth;
			for (const auto& i : tree) {
				std::string previousSpace((interval >> 1) - 1, ' ');
				std::string middleSpace(interval - 1, ' ');
				_Os << previousSpace;
				std::string line;
				for (const auto& j : i) {
					if (j != nullptr) {
						line += _NodeChar;
					} else {
						line += _EmptyChar;
					}
					line += middleSpace;
				}
				_Os << line << '\n' 
					<< previousSpace << std::string(line.size() - middleSpace.size(), _MidLineChar) << '\n';
				interval >>= 1;
			}
			_Os << '\n';
		}

		// char type specific draw_tree reload
		constexpr void draw_tree(char _EmptyChar = ' ', std::ostream& _Os = std::cout) noexcept
				requires std::is_same_v<value_type, char> {
			std::vector<std::vector<node_pointer>> tree;
			size_type treeDepth = depth(*this);
			tree.resize(treeDepth);

			tree[0].push_back(this->root());

			for (size_type i = 0; i < treeDepth - 1; ++i) {
				tree[i + 1].resize(1 << (i + 1));
				for (size_type j = 0; j < (1 << i); ++j) {
					if (tree[i][j] != nullptr) {
						tree[i + 1][ j << 1		] = tree[i][j]->left();
						tree[i + 1][(j << 1) + 1] = tree[i][j]->right();
					}
				}
			}

			size_type interval = 1 << treeDepth;
			for (const auto& i : tree) {
				std::string previousSpace((interval >> 1) - 1, ' ');
				std::string middleSpace(interval - 1, ' ');
				_Os << previousSpace;
				std::string line;
				for (const auto& j : i) {
					if (j != nullptr) {
						line += j->value();
					} else {
						line += _EmptyChar;
					}
					line += middleSpace;
				}
				_Os << line << '\n'
					<< previousSpace << std::string(line.size() - middleSpace.size(), ' ') << '\n';
				interval >>= 1;
			}
			_Os << '\n';
		}
		
		node_pointer pRootNode;
		size_type    numberOfNodes;
	};

	template<
		typename _KeyType,
		typename _MappedType,
		typename _Allocator,
		typename _NodeType = pair_binary_tree_node<_KeyType, _MappedType, _Allocator>
	>
	struct pair_binary_tree_root_node :
		public key_binary_tree_root_node<std::pair<_KeyType, _MappedType>, _Allocator, _NodeType> {

		using base_type = key_binary_tree_root_node<std::pair<_KeyType, _MappedType>, _Allocator, _NodeType>;

		using size_type = typename base_type::size_type;

		using node_type = _NodeType;
		using node_pointer = node_type*;

		using key_type = _KeyType;
		using Mapped_type = _MappedType;
		using value_type = std::pair<_KeyType, _MappedType>;

		using value_comapre = typename node_type::value_compare;

		using reference = std::pair<_KeyType, _MappedType>&;
		using const_reference = const std::pair<_KeyType, _MappedType>&;

		using base_type::pRootNode;
		using base_type::numberOfNodes;

		constexpr pair_binary_tree_root_node() noexcept : base_type{} {}

		constexpr pair_binary_tree_root_node(const pair_binary_tree_root_node& _Other) noexcept :
			base_type{ _Other } {}

		constexpr pair_binary_tree_root_node(pair_binary_tree_root_node&& _Other) noexcept :
			base_type{ std::move(_Other) } {}

		constexpr pair_binary_tree_root_node& operator=(const pair_binary_tree_root_node& _Other) noexcept {
			base_type::operator=(_Other);
			return *this;
		}

		constexpr pair_binary_tree_root_node& operator=(pair_binary_tree_root_node&& _Other) noexcept {
			base_type::operator=(std::move(_Other));
			return *this;
		}
	};

	template<
		typename _KeyType,
		typename _Compare,
		typename _Allocator,
		typename _NodeType = key_binary_search_tree_node<_KeyType, _Compare, _Allocator>
	>
	struct key_binary_search_tree_root_node :
		public key_binary_tree_root_node<_KeyType, _Allocator, _NodeType> {

		using base_type		  = key_binary_tree_root_node<_KeyType, _Allocator, _NodeType>;

		using value_type	  = _KeyType;

		using value_compare   = _Compare;

		using size_type		  = typename std::allocator_traits<_Allocator>::size_type;

		using node_type		  = _NodeType;
		using node_pointer    = node_type*;

		using allocator_type  = _Allocator;

		using reference		  = value_type&;

		using const_reference = const value_type&;

		using base_type::pRootNode;
		using base_type::numberOfNodes;

		constexpr bool has_parent_node() const noexcept
		{
			return false;
		}

		constexpr key_binary_search_tree_root_node() noexcept : base_type{} {}

		constexpr key_binary_search_tree_root_node(node_pointer _PRootNode) noexcept :
			base_type{ _PRootNode } {}

		constexpr key_binary_search_tree_root_node(node_pointer _PRootNode, size_type _NumberOfNodes) noexcept :
			base_type{ _PRootNode, _NumberOfNodes } {}

		constexpr key_binary_search_tree_root_node(const key_binary_search_tree_root_node& _Other) noexcept :
			base_type{ _Other } {}

		constexpr key_binary_search_tree_root_node(key_binary_search_tree_root_node&& _Other) noexcept :
			base_type{ std::move(_Other) } {}

		constexpr key_binary_search_tree_root_node& operator =(const key_binary_search_tree_root_node& _Right) noexcept {
			if (this != &_Right) {
				if (pRootNode != nullptr) {
					::delete pRootNode;
				}
				pRootNode = node_type::make_new(_Right.pRootNode);
				numberOfNodes = _Right.numberOfNodes;
			}
			return *this;
		}

		constexpr key_binary_search_tree_root_node& operator =(key_binary_search_tree_root_node&& _Right) noexcept {
			if (this != &_Right) {
				if (pRootNode != nullptr) {
					::delete pRootNode;
				}
				pRootNode = _Right.pRootNode;
				numberOfNodes = _Right.numberOfNodes;
				_Right.pRootNode = nullptr;
				_Right.numberOfNodes = 0;
			}
			return *this;
		}

		// if not found, return nullptr
		constexpr node_pointer& find(const value_type& _FindValue) noexcept {
			return find(_FindValue, *this);
		}

		// if not found, return nullptr
		constexpr const node_pointer& find(const value_type& _FindValue) const noexcept {
			return find(_FindValue, *this);
		}

		// if not found, return nullptr
		constexpr static node_pointer& find(const value_type& _FindValue, key_binary_search_tree_root_node& _RootNode) noexcept {
			return find(_FindValue, _RootNode.root());
		}

		// if not found, return nullptr
		constexpr static const node_pointer& find(const value_type& _FindValue, const key_binary_search_tree_root_node& _RootNode) noexcept {
			return find(_FindValue, _RootNode.root());
		}

		// if not found, return nullptr
		constexpr static node_pointer& find(const value_type& _FindValue, node_pointer& _PRootNode) noexcept {
			return const_cast<node_pointer&>(find(_FindValue, static_cast<const node_pointer&>(_PRootNode)));
		}

		// if not found, return nullptr
		constexpr static const node_pointer& find(const value_type& _FindValue, const node_pointer& _PRootNode) noexcept {
			const node_pointer* result = &_PRootNode;

			while (*result != nullptr) {
				if (**result > _FindValue) {
					result = &(*result)->left();
				} else if (**result < _FindValue) {
					result = &(*result)->right();
				} else {
					break;
				}
			}

			return *result;
		}

		// if not found, return nullptr
		constexpr node_pointer& min() noexcept {
			return min(pRootNode);
		}

		// if not found, return nullptr
		constexpr const node_pointer& min() const noexcept {
			return min(pRootNode);
		}

		// if not found, return nullptr
		constexpr static node_pointer& min(node_pointer& _PRootNode) noexcept {
			return const_cast<node_pointer&>(min(static_cast<const node_pointer&>(_PRootNode)));
		}

		// if not found, return nullptr
		constexpr static const node_pointer& min(const node_pointer& _PRootNode) noexcept {
			const node_pointer* result = &_PRootNode;

			while (*result != nullptr) {
				result = &(*result)->left();
			}

			return *result;
		}

		// if not found, return nullptr
		constexpr node_pointer& max() noexcept {
			return max(pRootNode);
		}

		// if not found, return nullptr
		constexpr const node_pointer& max() const noexcept {
			return max(pRootNode);
		}

		// if not found, return nullptr
		constexpr static node_pointer& max(node_pointer& _PRootNode) noexcept {
			return const_cast<node_pointer&>(max(static_cast<const node_pointer&>(_PRootNode)));
		}

		// if not found, return nullptr
		constexpr static const node_pointer& max(const node_pointer& _PRootNode) noexcept {
			const node_pointer* result = &_PRootNode;

			while (*result != nullptr) {
				result = &(*result)->right();
			}

			return *result;
		}

		// if not found, return nullptr
		constexpr node_pointer& floor(const value_type& _FindValue) noexcept {
			return floor(_FindValue, *this);
		}

		// if not found, return nullptr
		constexpr const node_pointer& floor(const value_type& _FindValue) const noexcept {
			return floor(_FindValue, *this);
		}

		// if not found, return nullptr
		constexpr static node_pointer& floor(const value_type& _FindValue, key_binary_search_tree_root_node& _RootNode) noexcept {
			return floor(_FindValue, _RootNode.root());
		}

		// if not found, return nullptr
		constexpr static const node_pointer& floor(const value_type& _FindValue, const key_binary_search_tree_root_node& _RootNode) noexcept {
			return floor(_FindValue, _RootNode.root());
		}

		// if not found, return nullptr
		constexpr static node_pointer& floor(const value_type& _FindValue, node_pointer& _PRootNode) noexcept {
			return const_cast<node_pointer&>(floor(_FindValue, static_cast<const node_pointer&>(_PRootNode)));
		}

		// if not found, return nullptr
		constexpr static const node_pointer& floor(const value_type& _FindValue, const node_pointer& _PRootNode) noexcept {
			node_pointer* result = &_PRootNode;

			while (*result != nullptr) {
				if (**result > _FindValue) {
					result = &(*result)->left();
				} else if (**result == _FindValue) {
					break;
				} else {
					node_pointer* subFloor = &floor(_FindValue, (*result)->right());
					if (*subFloor == nullptr) {
						break;
					} else if (**subFloor > **result) {
						return *subFloor;
					} else {
						return*result;
					}
				}
			}

			return *result;
		}

		// if not found, return nullptr
		constexpr node_pointer& ceil(const value_type& _FindValue) noexcept {
			return ceil(_FindValue, *this);
		}

		// if not found, return nullptr
		constexpr const node_pointer& ceil(const value_type& _FindValue) const noexcept {
			return ceil(_FindValue, *this);
		}

		// if not found, return nullptr
		constexpr static node_pointer& ceil(const value_type& _FindValue, key_binary_search_tree_root_node& _RootNode) noexcept {
			return ceil(_FindValue, _RootNode.root());
		}

		// if not found, return nullptr
		constexpr static const node_pointer& ceil(const value_type& _FindValue, const key_binary_search_tree_root_node& _RootNode) noexcept {
			return ceil(_FindValue, _RootNode.root());
		}

		// if not found, return nullptr
		constexpr static node_pointer& ceil(const value_type& _FindValue, node_pointer& _PRootNode) noexcept {
			return const_cast<node_pointer&>(ceil(_FindValue, static_cast<const node_pointer&>(_PRootNode)));
		}

		// if not found, return nullptr
		constexpr static const node_pointer& ceil(const value_type& _FindValue, const node_pointer& _PRootNode) noexcept {
			const node_pointer* result = &_PRootNode;

			while (*result != nullptr) {
				if (**result < _FindValue) {
					result = &(*result)->right();
				} else if (**result == _FindValue) {
					break;
				} else {
					const node_pointer* subFloor = ceil(_FindValue, result->left());
					if (*subFloor == nullptr) {
						break;
					} else if (**subFloor < **result) {
						return *subFloor;
					} else {
						return*result;
					}
				}
			}

			return *result;
		}

		// if existed value equal to _FindValue, don't insert
		constexpr node_pointer& insert_unique(const value_type& _InsertValue) noexcept {
			return insert_unique(_InsertValue, *this);
		}

		// if existed value equal to _FindValue, don't insert
		constexpr node_pointer& insert_unique(value_type&& _InsertValue) noexcept {
			return insert_unique(std::move(_InsertValue), *this);
		}

		// if existed value equal to _FindValue, don't insert
		constexpr static node_pointer& insert_unique(const value_type& _InsertValue, key_binary_search_tree_root_node& _RootNode) noexcept {
			node_pointer& insertWhere = find(_InsertValue, _RootNode);
			if (insertWhere == nullptr) {
				insertWhere = new node_type(_InsertValue);
				++_RootNode.numberOfNodes;
			}

			return insertWhere;
		}

		// if existed value equal to _FindValue, don't insert
		constexpr static node_pointer& insert_unique(value_type&& _InsertValue, key_binary_search_tree_root_node& _RootNode) noexcept {
			node_pointer& insertWhere = find(_InsertValue, _RootNode);
			if (insertWhere == nullptr) {
				insertWhere = new node_type(std::move(_InsertValue));
				++_RootNode.numberOfNodes;
			}

			return insertWhere;
		}

		// if existed value equal to _FindValue, replace it
		constexpr node_pointer& insert_replace(const value_type& _InsertValue) noexcept {
			return insert_replace(_InsertValue, *this);
		}

		// if existed value equal to _FindValue, replace it
		constexpr node_pointer& insert_replace(value_type&& _InsertValue) noexcept {
			return insert_replace(std::move(_InsertValue), *this);
		}

		// if existed value equal to _FindValue, replace it
		constexpr static node_pointer& insert_replace(const value_type& _InsertValue, key_binary_search_tree_root_node& _RootNode) noexcept {
			node_pointer& insertWhere = find(_InsertValue, _RootNode);
			if (insertWhere == nullptr) {
				insertWhere = new node_type(_InsertValue);
				++_RootNode.numberOfNodes;
			} else {
				insertWhere->value() = _InsertValue;
				::delete _InsertValue;
			}

			return insertWhere;
		}

		// if existed value equal to _FindValue, replace it
		constexpr static node_pointer& insert_replace(value_type&& _InsertValue, key_binary_search_tree_root_node& _RootNode) noexcept {
			node_pointer& insertWhere = find(_InsertValue, _RootNode);
			if (insertWhere == nullptr) {
				insertWhere = new node_type(std::move(_InsertValue));
				++_RootNode.numberOfNodes;
			} else {
				insertWhere->value() = std::move(_InsertValue);
				::delete _InsertValue;
			}

			return insertWhere;
		}

		// if existed value equal to _FindValue, insert it
		constexpr node_pointer& insert_equal(const value_type& _InsertValue) noexcept {
			return insert_equal(_InsertValue, *this);
		}

		// if existed value equal to _FindValue, insert it
		constexpr node_pointer& insert_equal(value_type&& _InsertValue) noexcept {
			return insert_equal(std::move(_InsertValue), *this);
		}

		// if existed value equal to _FindValue, insert it
		constexpr static node_pointer& insert_equal(const value_type& _InsertValue, key_binary_search_tree_root_node& _RootNode) noexcept {
			node_pointer& insertWhere = find(_InsertValue, _RootNode);
			if (insertWhere == nullptr) {
				insertWhere = new node_type(_InsertValue);
				++_RootNode.numberOfNodes;
			} else {
				// TODO: implement insert in equal case
			}

			return insertWhere;
		}

		// if existed value equal to _FindValue, insert it
		constexpr static node_pointer& insert_equal(value_type&& _InsertValue, key_binary_search_tree_root_node& _RootNode) noexcept {
			node_pointer& insertWhere = find(_InsertValue, _RootNode);
			if (insertWhere == nullptr) {
				insertWhere = new node_type(std::move(_InsertValue));
				++_RootNode.numberOfNodes;
			} else {
				// TODO: implement insert in equal case
			}

			return insertWhere;
		}

		constexpr node_pointer& erase(node_pointer& _Where) noexcept {
			return erase(_Where, *this);
		}

		constexpr static node_pointer& erase(node_pointer& _Where, key_binary_search_tree_root_node& _RootNode) noexcept {
			::delete _Where;
			--_RootNode.numberOfNodes;
			node_pointer& max_node = max(_Where->left());
			if (max_node == nullptr) {
				_Where   = _Where->right();
			} else {
				_Where   = max_node;
				max_node = nullptr;
			}

			return _Where;
		}
	};

	template<
		typename _KeyType,
		typename _MappedType,
		typename _Compare,
		typename _Allocator,
		typename _NodeType = pair_binary_search_tree_node<_KeyType, _MappedType, _Compare, _Allocator>
	>
	struct pair_binary_search_tree_root_node :
		public key_binary_search_tree_root_node<std::pair<_KeyType, _MappedType>, _Compare, _Allocator, _NodeType> {
	
		using base_type		  = key_binary_search_tree_root_node<std::pair<_KeyType, _MappedType>, _Compare, _Allocator, _NodeType>;
		
		using size_type		  = typename base_type::size_type;
		
		using node_type		  = _NodeType;		
		using node_pointer	  = node_type*;
		
		using key_type		  = _KeyType;
		using Mapped_type	  = _MappedType;
		using value_type	  = std::pair<_KeyType, _MappedType>;
		
		using key_compare	  = _Compare;
		using value_comapre   = typename node_type::value_compare;

		using reference		  = std::pair<_KeyType, _MappedType>&;		
		using const_reference = const std::pair<_KeyType, _MappedType>&;

		using base_type::pRootNode;
		using base_type::numberOfNodes;
		
		constexpr pair_binary_search_tree_root_node() noexcept : base_type{} {}

		constexpr pair_binary_search_tree_root_node(const pair_binary_search_tree_root_node& _Other) noexcept :
			base_type{ _Other } {}

		constexpr pair_binary_search_tree_root_node(pair_binary_search_tree_root_node&& _Other) noexcept :
			base_type{ std::move(_Other) } {}

		constexpr pair_binary_search_tree_root_node& operator=(const pair_binary_search_tree_root_node& _Other) noexcept {
			base_type::operator=(_Other);
			return *this;
		}

		constexpr pair_binary_search_tree_root_node& operator=(pair_binary_search_tree_root_node&& _Other) noexcept {
			base_type::operator=(std::move(_Other));
			return *this;
		}		
		
		constexpr node_pointer& find(const key_type& _Key) noexcept {
			return find(_Key, *this);
		}
		
		constexpr const node_pointer& find(const key_type& _Key) const noexcept {
			return find(_Key, *this);
		}

		constexpr static node_pointer& find(const key_type& _Key, pair_binary_search_tree_root_node& _RootNode) noexcept {
			return find(_Key, _RootNode.pRootNode);
		}

		constexpr static const node_pointer& find(const key_type& _Key, const pair_binary_search_tree_root_node& _RootNode) noexcept {
			return find(_Key, _RootNode.pRootNode);
		}

		constexpr static node_pointer& find(const key_type& _Key, node_pointer& _PRootNode) noexcept {
			return const_cast<node_pointer&>(find(_Key, static_cast<const node_pointer&>(_PRootNode)));
		}

		constexpr static const node_pointer& find(const key_type& _Key, const node_pointer& _PRootNode) noexcept {
			const node_pointer* result = &_PRootNode;

			while (*result != nullptr) {
				if (**result > _Key) {
					result = &(*result)->left();
				} else if (**result < _Key) {
					result = &(*result)->right();
				} else {
					break;
				}
			}

			return *result;
		}

		// if not found, return nullptr
		constexpr node_pointer& floor(const key_type& _FindValue) noexcept {
			return floor(_FindValue, *this);
		}

		// if not found, return nullptr
		constexpr const node_pointer& floor(const key_type& _FindValue) const noexcept {
			return floor(_FindValue, *this);
		}

		// if not found, return nullptr
		constexpr static node_pointer& floor(const key_type& _FindValue, pair_binary_search_tree_root_node& _RootNode) noexcept {
			return floor(_FindValue, _RootNode.root());
		}

		// if not found, return nullptr
		constexpr static const node_pointer& floor(const key_type& _FindValue, const pair_binary_search_tree_root_node& _RootNode) noexcept {
			return floor(_FindValue, _RootNode.root());
		}

		// if not found, return nullptr
		constexpr static node_pointer& floor(const key_type& _FindValue, node_pointer& _PRootNode) noexcept {
			return const_cast<node_pointer&>(floor(_FindValue, static_cast<const node_pointer&>(_PRootNode)));
		}

		// if not found, return nullptr
		constexpr static const node_pointer& floor(const key_type& _FindValue, const node_pointer& _PRootNode) noexcept {
			node_pointer* result = &_PRootNode;

			while (*result != nullptr) {
				if (**result > _FindValue) {
					result = &(*result)->left();
				} else if (**result == _FindValue) {
					break;
				} else {
					node_pointer* subFloor = &floor(_FindValue, (*result)->right());
					if (*subFloor == nullptr) {
						break;
					} else if (**subFloor > **result) {
						return *subFloor;
					} else {
						return*result;
					}
				}
			}

			return *result;
		}

		// if not found, return nullptr
		constexpr node_pointer& ceil(const key_type& _FindValue) noexcept {
			return ceil(_FindValue, *this);
		}

		// if not found, return nullptr
		constexpr const node_pointer& ceil(const key_type& _FindValue) const noexcept {
			return ceil(_FindValue, *this);
		}

		// if not found, return nullptr
		constexpr static node_pointer& ceil(const key_type& _FindValue, pair_binary_search_tree_root_node& _RootNode) noexcept {
			return ceil(_FindValue, _RootNode.root());
		}

		// if not found, return nullptr
		constexpr static const node_pointer& ceil(const key_type& _FindValue, const pair_binary_search_tree_root_node& _RootNode) noexcept {
			return ceil(_FindValue, _RootNode.root());
		}

		// if not found, return nullptr
		constexpr static node_pointer& ceil(const key_type& _FindValue, node_pointer& _PRootNode) noexcept {
			return const_cast<node_pointer&>(ceil(_FindValue, static_cast<const node_pointer&>(_PRootNode)));
		}

		// if not found, return nullptr
		constexpr static const node_pointer& ceil(const key_type& _FindValue, const node_pointer& _PRootNode) noexcept {
			const node_pointer* result = &_PRootNode;

			while (*result != nullptr) {
				if (**result < _FindValue) {
					result = &(*result)->right();
				} else if (**result == _FindValue) {
					break;
				} else {
					const node_pointer* subFloor = ceil(_FindValue, result->left());
					if (*subFloor == nullptr) {
						break;
					} else if (**subFloor < **result) {
						return *subFloor;
					} else {
						return*result;
					}
				}
			}

			return *result;
		}
		
		// if existed value equal to _FindValue, replace it
		constexpr node_pointer& insert_replace(const value_type& _InsertValue) noexcept {
			return insert_replace(_InsertValue, *this);
		}

		// if existed value equal to _FindValue, replace it
		constexpr node_pointer& insert_replace(value_type&& _InsertValue) noexcept {
			return insert_replace(std::move(_InsertValue), *this);
		}

		// if existed value equal to _FindValue, replace it
		constexpr static node_pointer& insert_replace(const value_type& _InsertValue, pair_binary_search_tree_root_node& _RootNode) noexcept {
			node_pointer& insertWhere = find(_InsertValue, _RootNode);
			if (insertWhere == nullptr) {
				insertWhere = new node_type(_InsertValue);
				++_RootNode.numberOfNodes;
			} else {
				insertWhere->mapped() = _InsertValue.first;
				::delete _InsertValue;
			}

			return insertWhere;
		}

		// if existed value equal to _FindValue, replace it
		constexpr static node_pointer& insert_replace(value_type&& _InsertValue, pair_binary_search_tree_root_node& _RootNode) noexcept {
			node_pointer& insertWhere = find(_InsertValue, _RootNode);
			if (insertWhere == nullptr) {
				insertWhere = new node_type(std::move(_InsertValue));
				++_RootNode.numberOfNodes;
			} else {
				insertWhere->mapped() = std::move(_InsertValue.first);
				::delete _InsertValue;
			}

			return insertWhere;
		}	
	};
	
	template<
		typename _KeyType,
		typename _Allocator    = std::allocator  <_KeyType>,
		typename _RootNodeType = key_binary_tree_root_node<_KeyType, _Allocator>
	>
	class base_key_binary_tree {
	public:
		using key_type	      = _KeyType;
		using value_type	  = key_type;

		using size_type		  = typename std::allocator_traits<_Allocator>::size_type;

		using node_type		  = typename _RootNodeType::node_type;

		using node_pointer    = node_type*;

		using root_node_type  = _RootNodeType;

		using allocator_type  = _Allocator;

		using reference		  = value_type&;

		using const_reference = const value_type&;


		constexpr base_key_binary_tree() noexcept : rootNode{} {}

		constexpr base_key_binary_tree(const base_key_binary_tree& _Other) noexcept : rootNode{ _Other.rootNode } {}

		constexpr base_key_binary_tree(base_key_binary_tree&& _Other) noexcept : rootNode{ std::move(_Other.rootNode) } {}

		constexpr base_key_binary_tree& operator=(const base_key_binary_tree& _Other) noexcept {
			rootNode = _Other.rootNode;
			return *this;
		}

		constexpr base_key_binary_tree& operator=(base_key_binary_tree&& _Other) noexcept {
			rootNode = std::move(_Other.rootNode);
			return *this;
		}

		constexpr node_pointer root() noexcept {
			return rootNode.root();
		}

		constexpr node_pointer root() const noexcept {
			return rootNode.root();
		}

		constexpr std::vector<value_type> to_vector() noexcept {
			return rootNode.to_vector();
		}

		constexpr const size_type depth() const noexcept {
			return rootNode.depth();
		}

		constexpr void draw_tree(char _NodeChar = 'O', char _EmptyChar = 'X', char _MidLineChar = ' ', std::ostream& _Os = std::cout) noexcept {
			rootNode.draw_tree(_NodeChar, _EmptyChar, _MidLineChar, _Os);
		}

		// char type specific draw_tree reload
		constexpr void draw_tree(char _EmptyChar = ' ', std::ostream& _Os = std::cout) noexcept
			requires std::is_same_v<_KeyType, char> {
			rootNode.draw_tree(_EmptyChar, _Os);
		}

		constexpr size_type size() const noexcept {
			return rootNode.size();
		}

	private:
		template<typename _KeyType, typename _MappedType, typename _Allocator, typename _RootNodeType>
		friend class base_pair_binary_tree;

		root_node_type rootNode;

		// char type specific draw_tree reload
		constexpr node_pointer insert_by_string(std::string_view _InitialString, size_t& _Index) noexcept
			requires std::is_same_v<_KeyType, char> {

			if (_Index >= _InitialString.size() || _InitialString[_Index] == '#') {
				return nullptr;
			} else {
				++rootNode.numberOfNodes;
				node_pointer result = new node_type{ _InitialString[_Index], nullptr, nullptr };
				result->left()      = insert_by_string(_InitialString, ++_Index);
				result->right()     = insert_by_string(_InitialString, ++_Index);
				return result;
			}
		}

	public:
		// char type specific draw_tree reload
		constexpr base_key_binary_tree(std::string_view _InitialString) noexcept
			requires std::is_same_v<_KeyType, char> {
			size_t index = 0;
			rootNode.pRootNode = insert_by_string(_InitialString, index);
		}

		template<typename _KeyType, typename _Compare, typename _Allocator, typename _RootNodeType>
		friend class base_key_binary_search_tree;
	};

	template<
		typename _KeyType,
		typename _MappedType,
		typename _Allocator    = std::allocator<_KeyType>,
		typename _RootNodeType = pair_binary_tree_root_node<_KeyType, _MappedType, _Allocator>
	>
	class base_pair_binary_tree :
		public base_key_binary_tree<std::pair<_KeyType, _MappedType>, _Allocator, _RootNodeType> {

	public:
		using key_type		  = _KeyType;
		using mapped_type	  = _MappedType;
		using value_type	  = std::pair<key_type, mapped_type>;

		using node_type		  = typename _RootNodeType::node_type;

		using node_pointer    = node_type*;

		using size_type		  = typename std::allocator_traits<_Allocator>::size_type;

		using root_node_type  = _RootNodeType;

		using allocator_type  = _Allocator;

		using reference		  = value_type&;

		using const_reference = const value_type&;

		using base_type		  = base_key_binary_tree<std::pair<_KeyType, _MappedType>, _Allocator, _RootNodeType>;

		constexpr base_pair_binary_tree() : base_type{} {}

		constexpr base_pair_binary_tree(const base_pair_binary_tree& _Other) : base_type{ _Other } {}

		constexpr base_pair_binary_tree(base_pair_binary_tree&& _Other) : base_type{ std::move(_Other) } {}

		constexpr base_pair_binary_tree& operator=(const base_pair_binary_tree& _Other) {
			return base_type::operator =(_Other);
		}

		constexpr base_pair_binary_tree& operator=(base_pair_binary_tree&& _Other) {
			return base_type::operator =(std::move(_Other));
		}
	};

	template<
		typename _KeyType									,
		typename _Compare		= std::less		  <_KeyType>,
		typename _Allocator		= std::allocator  <_KeyType>,
		typename _RootNodeType  = key_binary_search_tree_root_node<_KeyType, _Compare, _Allocator>
	>
	class base_key_binary_search_tree :
		public base_key_binary_tree<_KeyType, _Allocator, _RootNodeType> {

	public:
		using base_type		  = base_key_binary_tree<_KeyType, _Allocator, _RootNodeType>;

		using key_type		  = _KeyType;
		using value_type	  = key_type;

		using key_compare     = _Compare;
		using value_compare   = key_compare;

		using size_type		  = typename std::allocator_traits<_Allocator>::size_type;

		using node_type		  = typename _RootNodeType::node_type;

		using node_pointer	  = node_type*;
		
		using root_node_type  = _RootNodeType;
		
		using allocator_type  = _Allocator;

		using reference		  = value_type&;

		using const_reference = const value_type&;

		using base_type::rootNode;

		constexpr base_key_binary_search_tree() noexcept : base_type{} {}

		constexpr base_key_binary_search_tree(const base_key_binary_search_tree& _Other) noexcept : base_type{ _Other } {}

		constexpr base_key_binary_search_tree(base_key_binary_search_tree&& _Other) noexcept : base_type{ std::move(_Other) } {}

		constexpr base_key_binary_search_tree(std::initializer_list<_KeyType> _InitializerList) noexcept : base_type{} {
			for (const auto& value : _InitializerList) {
				insert_unique(value);
			}
		}
		
		constexpr base_key_binary_search_tree& operator=(const base_key_binary_search_tree& _Other) noexcept {
			return base_type::operator =(_Other);
		}

		constexpr base_key_binary_search_tree& operator=(base_key_binary_search_tree&& _Other) noexcept {
			return base_type::operator =(std::move(_Other));
		}

			
		// TODO: following methon return value change to iterator
		constexpr node_pointer& find(const value_type& _FindValue) noexcept {
			return rootNode.find(_FindValue);
		}

		constexpr const node_pointer& find(const value_type& _FindValue) const noexcept {
			return rootNode.find(_FindValue);
		}

		constexpr node_pointer& floor(const value_type& _FindValue) noexcept {
			return rootNode.floor(_FindValue);
		}

		constexpr const node_pointer& floor(const value_type& _FindValue) const noexcept {
			return rootNode.floor(_FindValue);
		}
		
		constexpr node_pointer& ceil(const value_type& _FindValue) noexcept {
			return rootNode.ceil(_FindValue);
		}
		
		constexpr const node_pointer& celi(const value_type& _FindValue) const noexcept {
			return rootNode.ceil(_FindValue);
		}
			
		constexpr node_pointer& insert_unique(const value_type& _InsertValue) noexcept {
			return rootNode.insert_unique(_InsertValue);
		}

		constexpr node_pointer& insert_unique(value_type&& _InsertValue) noexcept {
			return rootNode.insert_unique(std::move(_InsertValue));
		}

		constexpr node_pointer& insert_replace(const value_type& _InsertValue) noexcept {
			return rootNode.insert_replace(_InsertValue);
		}

		constexpr node_pointer& insert_replace(value_type&& _InsertValue) noexcept {
			return rootNode.insert_replace(std::move(_InsertValue));
		}
		
		constexpr node_pointer& insert_equal(const value_type& _InsertValue) noexcept {
			return rootNode.insert_equal(_InsertValue);
		}

		constexpr node_pointer& insert_equal(value_type&& _InsertValue) noexcept {
			return rootNode.insert_equal(std::move(_InsertValue));
		}

		constexpr node_pointer& erase(node_pointer& _Where) noexcept {
			return rootNode.erase(_Where);
		}

		constexpr std::vector<value_type> to_vector() noexcept {
			return rootNode.to_vector();
		}

		constexpr const size_type depth() const noexcept {
			return rootNode.depth();
		}

		constexpr void draw_tree(char _NodeChar = 'O', char _EmptyChar = 'X', char _MidLineChar = ' ', std::ostream& _Os = std::cout) noexcept {
			rootNode.draw_tree(_NodeChar, _EmptyChar, _MidLineChar, _Os);
		}

		// char type specific draw_tree reload
		constexpr void draw_tree(char _EmptyChar = ' ', std::ostream & _Os = std::cout) noexcept
				requires std::is_same_v<_KeyType, char> {
			rootNode.draw_tree(_EmptyChar, _Os);
		}

		constexpr size_type size() const noexcept {
			return rootNode.size();
		}

	private:
		template<typename _KeyType, typename _MappedType, typename _Compare, typename _Allocator, typename _RootNodeType>
		friend class base_pair_binary_search_tree;

	public:
		// char type specific draw_tree reload
		constexpr base_key_binary_search_tree(std::string_view _InitialString) noexcept
				requires std::is_same_v<_KeyType, char> : base_type{ _InitialString } {}
	};

	template<
		typename _KeyType								    ,
		typename _MappedType							    ,
		typename _Compare		= std::less		  <_KeyType>,
		typename _Allocator		= std::allocator  <_KeyType>,
		typename _RootNodeType  = pair_binary_search_tree_root_node<_KeyType, _MappedType, _Compare, _Allocator>
	>
	class base_pair_binary_search_tree : 
		public base_key_binary_search_tree<std::pair<_KeyType, _MappedType>, _Compare, _Allocator, _RootNodeType> {
		
	public:
		using key_type			= _KeyType;
		using mapped_type		= _MappedType;
		using value_type		= std::pair<key_type, mapped_type>;

		using node_type			= typename _RootNodeType::node_type;

		using node_pointer		= node_type*;
		
		using key_compare		= _Compare;
		using value_compare		= typename _RootNodeType::value_compare;

		using size_type			= typename std::allocator_traits<_Allocator>::size_type;

		using root_node_type	= _RootNodeType;

		using allocator_type	= _Allocator;

		using reference			= value_type&;

		using const_reference	= const value_type&;
		
		using base_type			= base_key_binary_search_tree<std::pair<_KeyType, _MappedType>, _Compare, _Allocator, _RootNodeType>;
		
		constexpr base_pair_binary_search_tree() : base_type{} {}

		constexpr base_pair_binary_search_tree(const base_pair_binary_search_tree& _Other) : base_type{ _Other } {}

		constexpr base_pair_binary_search_tree(base_pair_binary_search_tree&& _Other) : base_type{ std::move(_Other) } {}

		constexpr base_pair_binary_search_tree(std::initializer_list<std::pair<_KeyType, _MappedType>> _InitializerList) noexcept {
			for (auto& value : _InitializerList) {
				this->insert_unique(value);
			}
		}
		
		constexpr base_pair_binary_search_tree& operator=(const base_pair_binary_search_tree& _Other) {
			base_type::operator=(_Other);
			return *this;
		}

		constexpr base_pair_binary_search_tree& operator=(base_pair_binary_search_tree&& _Other) {
			base_type::operator=(std::move(_Other));
			return *this;
		}		
		
		constexpr node_pointer& find(const key_type& _Key) noexcept {
			return this->rootNode.find(_Key);
		}

		constexpr const node_pointer& find(const key_type& _Key) const noexcept {
			return this->rootNode.find(_Key);
		}	
		
		constexpr node_pointer& floor(const key_type& _Key) noexcept {
			return this->rootNode.floor(_Key);
		}

		constexpr const node_pointer& floor(const key_type& _Key) const noexcept {
			return this->rootNode.floor(_Key);
		}

		constexpr node_pointer& ceil(const key_type& _Key) noexcept {
			return this->rootNode.ceil(_Key);
		}

		constexpr const node_pointer& ceil(const key_type& _Key) const noexcept {
			return this->rootNode.ceil(_Key);
		}		
	};	
}
