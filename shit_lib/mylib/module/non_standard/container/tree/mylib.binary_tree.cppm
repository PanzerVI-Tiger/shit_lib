module;

#ifdef __INTELLISENSE__

#include <string>
#include <memory>
#include <vector>
#include <utility>
#include <iostream>
#include <functional>

#endif

export module mylib.binary_tree;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.queue;

export namespace mylib {

    template<typename BinaryTreeNodeType>
    typename BinaryTreeNodeType::size_type tree_size(
        const    BinaryTreeNodeType*           pNode,
        typename BinaryTreeNodeType::size_type _Count = 0
    ) noexcept {
        if (pNode == nullptr) {
            return _Count;
        }
        return 
            mylib::tree_size(pNode->leftNode,  _Count + 1) + 
            mylib::tree_size(pNode->rightNode, _Count + 1);
    }

    template<typename KeyType, typename Allocator>
    struct key_binary_tree_node {
        using value_type      = KeyType;
        using key_type        = value_type;

        using size_type       = typename std::allocator_traits<Allocator>::size_type;

        using node_type       = key_binary_tree_node;
        using node_pointer    = node_type*;

        using allocator_type  = Allocator;

        using reference       = value_type&;

        using const_reference = const value_type&;

        constexpr bool has_parent_node() const noexcept {
            return false;
        }

        constexpr key_binary_tree_node(
            const value_type& data, node_pointer pLeftNode = nullptr,
            node_pointer      pRightNode = nullptr
        ) noexcept :
                valueData{ data }, leftNode{ pLeftNode }, rightNode{ pRightNode } 
        {}

        constexpr key_binary_tree_node(
            value_type&& value, node_pointer pLeftNode = nullptr,
            node_pointer pRightNode = nullptr
        ) noexcept :
                valueData{ std::move(value) }, leftNode{ pLeftNode }, rightNode{ pRightNode } 
        {}

        constexpr key_binary_tree_node() noexcept : valueData{}, leftNode{ nullptr }, rightNode{ nullptr } 
        {}

        constexpr key_binary_tree_node(const key_binary_tree_node&) noexcept = delete;

        constexpr key_binary_tree_node(key_binary_tree_node&& other) noexcept {
            *this = std::move(other);
        }

        constexpr ~key_binary_tree_node() noexcept {
            if (leftNode != nullptr) {
                delete leftNode;
            }
            if (rightNode != nullptr) {
                delete rightNode;
            }
        }

        constexpr node_type& operator =(const key_binary_tree_node&) noexcept = delete;

        constexpr node_type& operator =(key_binary_tree_node&& right) noexcept {
            valueData = std::move(right.valueData);
            leftNode = right.leftNode;
            rightNode = right.rightNode;
            right.leftNode = nullptr;
            right.rightNode = nullptr;
            return *this;
        }

        constexpr static node_pointer make_new(const node_pointer pNode) noexcept {
            if (pNode == nullptr) {
                return nullptr;
            }
            return 
                new node_type{ 
                    pNode->value(), 
                    make_new(pNode->left()), 
                    make_new(pNode->right()) 
                };
        }

        constexpr node_pointer& left() noexcept {
            return leftNode;
        }

        constexpr const node_pointer& left() const noexcept {
            return leftNode;
        }

        constexpr node_pointer& right() noexcept {
            return rightNode;
        }

        constexpr const node_pointer& right() const noexcept {
            return rightNode;
        }

        constexpr reference value() noexcept {
            return valueData;
        }

        constexpr const_reference value() const noexcept {
            return valueData;
        }

        node_pointer leftNode;
        node_pointer rightNode;
        value_type   valueData;
    };

    template<typename KeyType, typename MappedType, typename Allocator>
    struct pair_binary_tree_node :
        mylib::key_binary_tree_node<std::pair<KeyType, MappedType>, Allocator> 
    {

        using base_type       = mylib::key_binary_tree_node<std::pair<KeyType, MappedType>, Allocator>;

        using key_type        = KeyType;
        using mapped_type     = MappedType;
        using value_type      = std::pair<KeyType, MappedType>;

        using size_type       = typename base_type::size_type;

        using node_type       = pair_binary_tree_node;
        using node_pointer    = pair_binary_tree_node*;

        using allocator_type  = Allocator;

        using reference       = value_type&;

        using const_reference = const value_type&;

        using base_type::leftNode;
        using base_type::rightNode;
        using base_type::valueData;

        constexpr bool has_parent_node() const noexcept {
            return false;
        }

        constexpr pair_binary_tree_node(const value_type& value, node_pointer pLeftNode = nullptr,
            node_pointer pRightNode = nullptr) noexcept :
            base_type{ value, pLeftNode, pRightNode } 
        {}

        constexpr pair_binary_tree_node(value_type&& value, node_pointer pLeftNode = nullptr,
            node_pointer pRightNode = nullptr) noexcept :
            base_type{ std::move(value), pLeftNode, pRightNode } 
        {}

        constexpr pair_binary_tree_node(
            const key_type& key,       const mapped_type& mapped, 
            node_pointer    pLeftNode, node_pointer       pRightNode = nullptr
        ) noexcept :
            base_type{ std::make_pair(key, mapped), pLeftNode, pRightNode } 
        {}

        constexpr pair_binary_tree_node(
            key_type&&   key,                 mapped_type&& mapped, 
            node_pointer pLeftNode = nullptr, node_pointer  pRightNode = nullptr
        ) noexcept :
            base_type{ std::make_pair(std::move(key), std::move(mapped)), pLeftNode, pRightNode }
        {}

        constexpr pair_binary_tree_node() noexcept : base_type{} 
        {}

        constexpr pair_binary_tree_node(const pair_binary_tree_node&) noexcept = delete;

        constexpr pair_binary_tree_node(pair_binary_tree_node&& other) noexcept :
            base_type{ std::move(other) } {}

        constexpr node_type& operator =(const pair_binary_tree_node&) noexcept = delete;

        constexpr node_type& operator =(pair_binary_tree_node&& right) noexcept {
            return base_type::operator =(std::move(right));
        }

        constexpr static node_pointer make_new(const node_pointer pNode) noexcept {
            
            return reinterpret_cast<node_pointer>(base_type::make_new(pNode));
        }

        constexpr node_pointer& left() noexcept {
            return reinterpret_cast<node_pointer&>(leftNode);
        }

        constexpr const node_pointer& left() const noexcept {
            return reinterpret_cast<node_pointer&>(leftNode);
        }

        constexpr node_pointer& right() noexcept {
            return reinterpret_cast<node_pointer&>(rightNode);
        }

        constexpr const node_pointer& right() const noexcept {
            return reinterpret_cast<node_pointer&>(rightNode);
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

    template<typename KeyType, typename Compare, typename Allocator>
    struct key_binary_search_tree_node : 
        mylib::key_binary_tree_node<KeyType, Allocator> 
    {

        using base_type       = mylib::key_binary_tree_node<KeyType, Allocator>;
        using value_type      = KeyType;
        using key_type        = value_type;
        
        using value_compare   = Compare;
        using key_compare     = value_compare;

        using size_type       = typename std::allocator_traits<Allocator>::size_type;

        using node_type       = key_binary_search_tree_node;
        using node_pointer    = node_type*;

        using allocator_type  = Allocator;

        using reference       = value_type&;

        using const_reference = const value_type&;

        using base_type::leftNode;
        using base_type::rightNode;
        using base_type::valueData;

        constexpr bool has_parent_node() const noexcept {
            return false;
        }

        constexpr key_binary_search_tree_node(
            const value_type& data, node_pointer pLeftNode = nullptr,
            node_pointer      pRightNode = nullptr
        ) noexcept :
            valueData{ data }, leftNode{ pLeftNode }, rightNode{ pRightNode } 
        {}

        constexpr key_binary_search_tree_node(value_type&& data, node_pointer pLeftNode = nullptr,
            node_pointer pRightNode = nullptr) noexcept :
            valueData{ std::move(data) }, leftNode{ pLeftNode }, rightNode{ pRightNode } 
        {}

        constexpr key_binary_search_tree_node() noexcept : valueData{}, leftNode{ nullptr }, rightNode{ nullptr } 
        {}

        constexpr key_binary_search_tree_node(const key_binary_search_tree_node&) noexcept = delete;
        
        constexpr key_binary_search_tree_node(key_binary_search_tree_node&& other) noexcept{
            *this = std::move(other);
        }

        constexpr ~key_binary_search_tree_node() noexcept {
            if (leftNode != nullptr) {
                ::delete leftNode;
            }
            if (rightNode != nullptr) {
                ::delete rightNode;
            }
        }
        
        constexpr node_type& operator =(const key_binary_search_tree_node&) noexcept = delete;
        
        constexpr node_type& operator =(key_binary_search_tree_node&& right) noexcept {
            return base_type::operator =(std::move(right));
        }
        
        constexpr bool operator <(const value_type& right) const noexcept {
            return value_compare{}(this->value(), right);
        }

        constexpr bool operator >(const value_type& right) const noexcept {
            return value_compare{}(right, this->value());
        }

        constexpr bool operator ==(const value_type& right) const noexcept {
            return 
                value_compare{}(this->value(), right) == false && 
                value_compare{}(right, this->value()) == false;
        }

        constexpr bool operator <(const node_type& right) const noexcept {
            return value_compare{}(this->value(), right.value());
        }

        constexpr bool operator >(const node_type& right) const noexcept {
            return value_compare{}(right.value(), this->value());
        }

        constexpr bool operator ==(const node_type& right) const noexcept {
            return 
                value_compare{}(this->value(), right.value()) == false && 
                value_compare{}(right.value(), this->value()) == false;
        }

        constexpr static node_pointer make_new(const node_pointer pNode) noexcept {
            if (pNode == nullptr) {
                return nullptr;
            }
            return 
                new node_type{ 
                    pNode->value(),
                    make_new(pNode->left()), 
                    make_new(pNode->right()) 
                };
        }
        
        constexpr node_pointer& left() noexcept {
            return reinterpret_cast<node_pointer&>(leftNode);
        }

        constexpr const node_pointer& left() const noexcept {
            return reinterpret_cast<node_pointer&>(leftNode);
        }

        constexpr node_pointer& right() noexcept {
            return reinterpret_cast<node_pointer&>(rightNode);
        }

        constexpr const node_pointer& right() const noexcept {
            return reinterpret_cast<node_pointer&>(rightNode);
        }
    };

    template<
        typename KeyType, 
        typename MappedType, 
        typename Compare, 
        typename Allocator
    > struct pair_binary_search_tree_node : 
            mylib::key_binary_search_tree_node<
                std::pair<KeyType, MappedType>, 
                Compare, 
                Allocator
            > 
    {

        using base_type       = 
            mylib::key_binary_search_tree_node<
                std::pair<KeyType, MappedType>, 
                Compare, Allocator
            >;
        
        using key_type        = KeyType;
        using mapped_type     = MappedType;
        using value_type      = std::pair<KeyType, MappedType>;
        
        using key_compare     = Compare;
        
        using size_type       = typename base_type::size_type;
        
        using node_type       = pair_binary_search_tree_node;
        using node_pointer    = pair_binary_search_tree_node*;

        using allocator_type  = Allocator;

        using reference       = value_type&;

        using const_reference = const value_type&;

        using base_type::leftNode;
        using base_type::rightNode;
        using base_type::valueData;
        
        class value_compare {
        public:
            constexpr value_compare() noexcept = default;

            constexpr value_compare(const value_compare&) noexcept = default;

            constexpr value_compare(value_compare&&) noexcept = default;

            constexpr value_compare& operator=(const value_compare&) noexcept = default;

            constexpr value_compare& operator=(value_compare&&) noexcept = default;

            constexpr bool operator()(const value_type& left, const value_type& right) const noexcept {
                return comp(left.first, right.first);
            }
             
        private:
            key_compare comp;
        };
        
        constexpr bool has_parent_node() const noexcept {
            return false;
        }

        constexpr pair_binary_search_tree_node(const value_type& value, node_pointer pLeftNode = nullptr,
                node_pointer pRightNode = nullptr) noexcept :
            base_type{ value, pLeftNode, pRightNode } 
        {}
        
        constexpr pair_binary_search_tree_node(value_type&& value, node_pointer pLeftNode = nullptr,
            node_pointer pRightNode = nullptr) noexcept :
            base_type{ std::move(value), pLeftNode, pRightNode } 
        {}
        
        constexpr pair_binary_search_tree_node(
            const key_type& key,       const mapped_type& mapped, 
            node_pointer    pLeftNode, node_pointer       pRightNode = nullptr
        ) noexcept :
            base_type{ std::make_pair(key, mapped), pLeftNode, pRightNode } 
        {}
        
        constexpr pair_binary_search_tree_node(
            key_type&&   key,                 mapped_type&& mapped, 
            node_pointer pLeftNode = nullptr, node_pointer pRightNode = nullptr
        ) noexcept :
            base_type{ std::make_pair(std::move(key), std::move(mapped)), pLeftNode, pRightNode } 
        {}
        
        constexpr pair_binary_search_tree_node() noexcept : base_type{} 
        {}
        
        constexpr pair_binary_search_tree_node(const pair_binary_search_tree_node&) noexcept = delete;
        
        constexpr pair_binary_search_tree_node(pair_binary_search_tree_node&& other) noexcept :
            base_type{ std::move(other) } {}

        constexpr node_type& operator =(const pair_binary_search_tree_node& right) noexcept = delete;

        constexpr node_type& operator =(pair_binary_search_tree_node&& right) noexcept {
            return base_type::operator =(std::move(right));
        }

        constexpr bool operator <(const value_type& right) const noexcept {
            return key_compare{}(this->key(), right.first);
        }
        
        constexpr bool operator >(const value_type& right) const noexcept {
            return key_compare{}(right.first, this->key());
        }

        constexpr bool operator ==(const value_type& right) const noexcept {
            return 
                key_compare{}(this->key(), right.first) == false && 
                key_compare{}(right.first, this->key()) == false;
        }

        constexpr bool operator <(const key_type& right) const noexcept {
            return key_compare{}(this->key(), right);
        }

        constexpr bool operator >(const key_type& right) const noexcept {
            return key_compare{}(right, this->key());
        }

        constexpr bool operator ==(const key_type& right) const noexcept {
            return 
                key_compare{}(this->key(), right) == false && 
                key_compare{}(right, this->key()) == false;
        }

        constexpr bool operator <(const node_type& right) const noexcept {
            return key_compare{}(this->key(), right.key());
        }

        constexpr bool operator >(const node_type& right) const noexcept {
            return key_compare{}(right.key(), this->key());
        }

        constexpr bool operator ==(const node_type& right) const noexcept {
            return 
                key_compare{}(this->key(), right.key()) == false && 
                key_compare{}(right.key(), this->key()) == false;
        }
        
        constexpr static node_pointer make_new(const node_pointer pNode) noexcept {
            if (pNode == nullptr) {
                return nullptr;
            }
            return new node_type{ pNode->value(), make_new(pNode->left()), make_new(pNode->right()) };
        }
        
        constexpr node_pointer& left() noexcept {
            return reinterpret_cast<node_pointer&>(leftNode);
        }

        constexpr const node_pointer& left() const noexcept {
            return reinterpret_cast<node_pointer&>(leftNode);
        }

        constexpr node_pointer& right() noexcept {
            return reinterpret_cast<node_pointer&>(rightNode);
        }

        constexpr const node_pointer& right() const noexcept {
            return reinterpret_cast<node_pointer&>(rightNode);
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
        typename KeyType,
        typename Allocator,
        typename NodeType = key_binary_tree_node<KeyType, Allocator>
    >
    struct key_binary_tree_root_node {
        using value_type      = KeyType;

        using size_type       = typename std::allocator_traits<Allocator>::size_type;

        using node_type       = NodeType;
        using node_pointer    = node_type*;

        using allocator_type  = Allocator;

        using reference       = value_type&;

        using const_reference = const value_type&;

        constexpr bool has_parent_node() const noexcept
        {
            return false;
        }

        constexpr key_binary_tree_root_node() noexcept : 
            pRootNode{ nullptr }, nodesSize{ size_type{ 0 } } 
        {}
        
        constexpr key_binary_tree_root_node(node_pointer pRootNode) noexcept :
            pRootNode{ pRootNode }, nodesSize{ tree_size(pRootNode) } 
        {}
        
        constexpr key_binary_tree_root_node(node_pointer pRootNode, size_type _nodeSize) noexcept :
            pRootNode{ pRootNode }, nodesSize{ _nodeSize } 
        {}

        constexpr key_binary_tree_root_node(const key_binary_tree_root_node& other) noexcept :
            pRootNode{ node_type::make_new(other.pRootNode) }, nodesSize{other.nodesSize} 
        {}

        constexpr key_binary_tree_root_node(key_binary_tree_root_node&& other) noexcept :
            pRootNode{ other.pRootNode }, nodesSize{ other.nodesSize } {
            other.pRootNode     = nullptr;
            other.nodesSize = 0;
        }

        constexpr key_binary_tree_root_node& operator =(const key_binary_tree_root_node& right) noexcept {
            if (this != &right) {
                if (pRootNode != nullptr) {
                    ::delete pRootNode;
                }
                pRootNode     = node_type::make_new(right.pRootNode);
                nodesSize = right.nodesSize;
            }
            return *this;
        }

        constexpr key_binary_tree_root_node& operator =(key_binary_tree_root_node&& right) noexcept {
            if (this != &right) {
                if (pRootNode != nullptr) {
                    ::delete pRootNode;
                }
                pRootNode            = right.pRootNode;
                nodesSize        = right.nodesSize;
                right.pRootNode     = nullptr;
                right.nodesSize = 0;
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
            return nodesSize;
        }
        
        constexpr void preorder_traversal(std::function<void(value_type&)> unaryFunc) const noexcept {
            preorder_traversal(pRootNode, unaryFunc);
        }

        constexpr void inorder_traversal(std::function<void(value_type&)> unaryFunc) const noexcept {
            inorder_traversal(pRootNode, unaryFunc);
        }

        constexpr void postorder_traversal(std::function<void(value_type&)> unaryFunc) const noexcept {
            postorder_traversal(pRootNode, unaryFunc);
        }

        constexpr void levelorder_traversal(std::function<void(node_pointer&)> unaryFunc) const noexcept {
            levelorder_traversal(pRootNode, unaryFunc);
        }

        constexpr void preorder_traversal(
            node_pointer pNode, std::function<void(node_pointer&)> unaryFunc
        ) const noexcept {
            
            if (pNode != nullptr) {
                unaryFunc(pNode->value());
                preorder_traversal(pNode->left(), unaryFunc);
                preorder_traversal(pNode->right(), unaryFunc);
            }
        }

        constexpr void inorder_traversal(
            node_pointer pNode, std::function<void(node_pointer&)> unaryFunc
        ) const noexcept {
            
            if (pNode != nullptr) {
                inorder_traversal(pNode->left(), unaryFunc);
                unaryFunc(pNode->value());
                inorder_traversal(pNode->right(), unaryFunc);
            }
        }

        constexpr void postorder_traversal(
            node_pointer pNode, std::function<void(node_pointer&)> unaryFunc
        ) const noexcept {
            
            if (pNode != nullptr) {
                postorder_traversal(pNode->left(), unaryFunc);
                postorder_traversal(pNode->right(), unaryFunc);
                unaryFunc(pNode->value());
            }
        }

        constexpr void levelorder_traversal(
            node_pointer pNode, std::function<void(value_type&)> unaryFunc
        ) const noexcept {
            
            if (pNode != nullptr) {
                queue<node_pointer> _Queue;
                _Queue.push(pNode);
                while (!_Queue.empty()) {
                    node_pointer pNode = _Queue.front();
                    _Queue.pop();
                    unaryFunc(pNode->value());
                    if (pNode->left() != nullptr) {
                        _Queue.push(pNode->left());
                    }
                    if (pNode->right() != nullptr) {
                        _Queue.push(pNode->right());
                    }
                }
            }
        }
        
        constexpr std::vector<value_type> to_vector() const noexcept {
            return to_vector(*this);
        }

        constexpr void append_to_vector(std::vector<value_type>& result) const noexcept {
            to_vector(root(), result);
        }
            
        constexpr static std::vector<value_type> to_vector(const key_binary_tree_root_node& rootNode) noexcept {
            std::vector<value_type> result;
            append_to_vector(rootNode.root(), result);
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

        constexpr static const size_type depth(const key_binary_tree_root_node& rootNode) noexcept {
            return depth(rootNode.pRootNode);
        }

        constexpr static const size_type depth(const node_pointer pNode) noexcept {
            if (pNode == nullptr) {
                return 0;
            }

            size_type leftDepth = depth(pNode->left());
            size_type rightDepth = depth(pNode->right());

            return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
        }
        
        constexpr void draw_tree(
            char nodeChar = 'O', char emptyChar = 'X', char middleLineChar = ' ', std::ostream& os = std::cout
        ) noexcept {
            
            draw_tree(*this, nodeChar, emptyChar, middleLineChar, os);
        }

        constexpr static void draw_tree(
            key_binary_tree_root_node& rootNode, 
            char nodeChar = 'O',       char emptyChar = 'X', 
            char middleLineChar = ' ', std::ostream& os = std::cout
        ) noexcept {
            
            std::vector<std::vector<node_pointer>> tree;
            size_type treeDepth = depth(rootNode);
            tree.resize(treeDepth);
            
            tree[0].push_back(rootNode.root());

            for (size_type i = 0; i < treeDepth - 1; ++i) {
                tree[i + 1].resize(1 << (i + 1));
                for (size_type j = 0; j < (1 << i); ++j) {
                    if (tree[i][j] != nullptr) {
                        tree[i + 1][ j << 1     ] = tree[i][j]->left();
                        tree[i + 1][(j << 1) + 1] = tree[i][j]->right();
                    }
                }
            }
            
            size_type interval = 1 << treeDepth;
            for (const auto& i : tree) {
                std::string previousSpace((interval >> 1) - 1, ' ');
                std::string middleSpace(interval - 1, ' ');
                os << previousSpace;
                std::string line;
                for (const auto& j : i) {
                    if (j != nullptr) {
                        line += nodeChar;
                    } else {
                        line += emptyChar;
                    }
                    line += middleSpace;
                }
                os << line << '\n' 
                    << previousSpace << std::string(line.size() - middleSpace.size(), middleLineChar) << '\n';
                interval >>= 1;
            }
            os << '\n';
        }

        // char type specific draw_tree reload
        constexpr void draw_tree(char emptyChar = ' ', std::ostream& os = std::cout) noexcept
            requires std::is_same_v<value_type, char> {
            
            std::vector<std::vector<node_pointer>> tree;
            size_type treeDepth = depth(*this);
            tree.resize(treeDepth);

            tree[0].push_back(this->root());

            for (size_type i = 0; i < treeDepth - 1; ++i) {
                tree[i + 1].resize(1 << (i + 1));
                for (size_type j = 0; j < (1 << i); ++j) {
                    if (tree[i][j] != nullptr) {
                        tree[i + 1][ j << 1     ] = tree[i][j]->left();
                        tree[i + 1][(j << 1) + 1] = tree[i][j]->right();
                    }
                }
            }

            size_type interval = 1 << treeDepth;
            for (const auto& i : tree) {
                std::string previousSpace((interval >> 1) - 1, ' ');
                std::string middleSpace(interval - 1, ' ');
                os << previousSpace;
                std::string line;
                for (const auto& j : i) {
                    if (j != nullptr) {
                        line += j->value();
                    } else {
                        line += emptyChar;
                    }
                    line += middleSpace;
                }
                os << line << '\n'
                    << previousSpace << std::string(line.size() - middleSpace.size(), ' ') << '\n';
                interval >>= 1;
            }
            os << '\n';
        }
        
        node_pointer pRootNode;
        size_type    nodesSize;
    };

    template<
        typename KeyType,
        typename MappedType,
        typename Allocator,
        typename NodeType = pair_binary_tree_node<KeyType, MappedType, Allocator>
    >
    struct pair_binary_tree_root_node :
        public mylib::key_binary_tree_root_node<std::pair<KeyType, MappedType>, Allocator, NodeType> {

        using base_type       = mylib::key_binary_tree_root_node<std::pair<KeyType, MappedType>, Allocator, NodeType>;

        using size_type       = typename base_type::size_type;

        using node_type       = NodeType;
        using node_pointer    = node_type*;

        using key_type        = KeyType;
        using Mapped_type     = MappedType;
        using value_type      = std::pair<KeyType, MappedType>;

        using value_comapre   = typename node_type::value_compare;

        using reference       = std::pair<KeyType, MappedType>&;
        using const_reference = const std::pair<KeyType, MappedType>&;

        using base_type::pRootNode;
        using base_type::nodesSize;

        constexpr pair_binary_tree_root_node() noexcept : base_type{} 
        {}

        constexpr pair_binary_tree_root_node(const pair_binary_tree_root_node& other) noexcept :
            base_type{ other } 
        {}

        constexpr pair_binary_tree_root_node(pair_binary_tree_root_node&& other) noexcept :
            base_type{ std::move(other) } 
        {}

        constexpr pair_binary_tree_root_node& operator=(const pair_binary_tree_root_node& other) noexcept {
            base_type::operator=(other);
            return *this;
        }

        constexpr pair_binary_tree_root_node& operator=(pair_binary_tree_root_node&& other) noexcept {
            base_type::operator=(std::move(other));
            return *this;
        }
    };

    template<
        typename KeyType,
        typename Compare,
        typename Allocator,
        typename NodeType = key_binary_search_tree_node<KeyType, Compare, Allocator>
    >
    struct key_binary_search_tree_root_node :
        public key_binary_tree_root_node<KeyType, Allocator, NodeType> {

        using base_type       = mylib::key_binary_tree_root_node<KeyType, Allocator, NodeType>;

        using value_type      = KeyType;

        using value_compare   = Compare;

        using size_type       = typename std::allocator_traits<Allocator>::size_type;

        using node_type       = NodeType;
        using node_pointer    = node_type*;

        using allocator_type  = Allocator;

        using reference       = value_type&;

        using const_reference = const value_type&;

        using base_type::pRootNode;
        using base_type::nodesSize;

        constexpr bool has_parent_node() const noexcept
        {
            return false;
        }

        constexpr key_binary_search_tree_root_node() noexcept : base_type{} 
        {}

        constexpr key_binary_search_tree_root_node(node_pointer pRootNode) noexcept :
            base_type{ pRootNode } 
        {}

        constexpr key_binary_search_tree_root_node(node_pointer pRootNode, size_type _nodeSize) noexcept :
            base_type{ pRootNode, _nodeSize } 
        {}

        constexpr key_binary_search_tree_root_node(const key_binary_search_tree_root_node& other) noexcept :
            base_type{ other } 
        {}

        constexpr key_binary_search_tree_root_node(key_binary_search_tree_root_node&& other) noexcept :
            base_type{ std::move(other) } 
        {}

        constexpr key_binary_search_tree_root_node& operator =(
            const key_binary_search_tree_root_node& right
        ) noexcept {
            if (this != &right) {
                if (pRootNode != nullptr) {
                    ::delete pRootNode;
                }
                pRootNode = node_type::make_new(right.pRootNode);
                nodesSize = right.nodesSize;
            }
            return *this;
        }

        constexpr key_binary_search_tree_root_node& operator =(
            key_binary_search_tree_root_node&& right
        ) noexcept {
            if (this != &right) {
                if (pRootNode != nullptr) {
                    ::delete pRootNode;
                }
                pRootNode = right.pRootNode;
                nodesSize = right.nodesSize;
                right.pRootNode = nullptr;
                right.nodesSize = 0;
            }
            return *this;
        }

        // if not found, return nullptr
        constexpr node_pointer& find(const value_type& value) noexcept {
            return find(value, *this);
        }

        // if not found, return nullptr
        constexpr const node_pointer& find(const value_type& value) const noexcept {
            return find(value, *this);
        }

        // if not found, return nullptr
        constexpr static node_pointer& find(
            const value_type& value, key_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            return find(value, rootNode.root());
        }

        // if not found, return nullptr
        constexpr static const node_pointer& find(
            const value_type& value, const key_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            return find(value, rootNode.root());
        }

        // if not found, return nullptr
        constexpr static node_pointer& find(
            const value_type& value, node_pointer& pRootNode
        ) noexcept {
            
            return const_cast<node_pointer&>(find(value, static_cast<const node_pointer&>(pRootNode)));
        }

        // if not found, return nullptr
        constexpr static const node_pointer& find(
            const value_type& value, const node_pointer& pRootNode
        ) noexcept {
            
            const node_pointer* result = &pRootNode;

            while (*result != nullptr) {
                if (**result > value) {
                    result = &(*result)->left();
                } else if (**result < value) {
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
        constexpr static node_pointer& min(node_pointer& pRootNode) noexcept {
            return const_cast<node_pointer&>(min(static_cast<const node_pointer&>(pRootNode)));
        }

        // if not found, return nullptr
        constexpr static const node_pointer& min(const node_pointer& pRootNode) noexcept {
            const node_pointer* result = &pRootNode;

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
        constexpr static node_pointer& max(node_pointer& pRootNode) noexcept {
            return const_cast<node_pointer&>(max(static_cast<const node_pointer&>(pRootNode)));
        }

        // if not found, return nullptr
        constexpr static const node_pointer& max(const node_pointer& pRootNode) noexcept {
            const node_pointer* result = &pRootNode;

            while (*result != nullptr) {
                result = &(*result)->right();
            }

            return *result;
        }

        // if not found, return nullptr
        constexpr node_pointer& floor(const value_type& value) noexcept {
            return floor(value, *this);
        }

        // if not found, return nullptr
        constexpr const node_pointer& floor(const value_type& value) const noexcept {
            return floor(value, *this);
        }

        // if not found, return nullptr
        constexpr static node_pointer& floor(
            const value_type& value, key_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            return floor(value, rootNode.root());
        }

        // if not found, return nullptr
        constexpr static const node_pointer& floor(
            const value_type& value, const key_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            return floor(value, rootNode.root());
        }

        // if not found, return nullptr
        constexpr static node_pointer& floor(
            const value_type& value, node_pointer& pRootNode
        ) noexcept {
            
            return const_cast<node_pointer&>(floor(value, static_cast<const node_pointer&>(pRootNode)));
        }

        // if not found, return nullptr
        constexpr static const node_pointer& floor(
            const value_type& value, const node_pointer& pRootNode
        ) noexcept {
            
            node_pointer* result = &pRootNode;

            while (*result != nullptr) {
                if (**result > value) {
                    result = &(*result)->left();
                } else if (**result == value) {
                    break;
                } else {
                    node_pointer* subFloor = &floor(value, (*result)->right());
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
        constexpr node_pointer& ceil(const value_type& value) noexcept {
            return ceil(value, *this);
        }

        // if not found, return nullptr
        constexpr const node_pointer& ceil(const value_type& value) const noexcept {
            return ceil(value, *this);
        }

        // if not found, return nullptr
        constexpr static node_pointer& ceil(
            const value_type& value, key_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            return ceil(value, rootNode.root());
        }

        // if not found, return nullptr
        constexpr static const node_pointer& ceil(
            const value_type& value, const key_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            return ceil(value, rootNode.root());
        }

        // if not found, return nullptr
        constexpr static node_pointer& ceil(
            const value_type& value, node_pointer& pRootNode
        ) noexcept {
            
            return const_cast<node_pointer&>(ceil(value, static_cast<const node_pointer&>(pRootNode)));
        }

        // if not found, return nullptr
        constexpr static const node_pointer& ceil(
            const value_type& value, const node_pointer& pRootNode
        ) noexcept {
            
            const node_pointer* result = &pRootNode;

            while (*result != nullptr) {
                if (**result < value) {
                    result = &(*result)->right();
                } else if (**result == value) {
                    break;
                } else {
                    const node_pointer* subFloor = ceil(value, result->left());
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

        // if existed value equal to value, don't insert
        constexpr node_pointer& insert_unique(const value_type& value) noexcept {
            
            return insert_unique(value, *this);
        }

        // if existed value equal to value, don't insert
        constexpr node_pointer& insert_unique(value_type&& value) noexcept {
            return insert_unique(std::move(value), *this);
        }

        // if existed value equal to value, don't insert
        constexpr static node_pointer& insert_unique(
            const value_type& value, key_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            node_pointer& insertWhere = find(value, rootNode);
            if (insertWhere == nullptr) {
                insertWhere = new node_type(value);
                ++rootNode.nodesSize;
            }

            return insertWhere;
        }

        // if existed value equal to value, don't insert
        constexpr static node_pointer& insert_unique(
            value_type&& value, key_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            node_pointer& insertWhere = find(value, rootNode);
            if (insertWhere == nullptr) {
                insertWhere = new node_type(std::move(value));
                ++rootNode.nodesSize;
            }

            return insertWhere;
        }

        // if existed value equal to value, replace it
        constexpr node_pointer& insert_replace(const value_type& value) noexcept {
            return insert_replace(value, *this);
        }

        // if existed value equal to value, replace it
        constexpr node_pointer& insert_replace(value_type&& value) noexcept {
            return insert_replace(std::move(value), *this);
        }

        // if existed value equal to value, replace it
        constexpr static node_pointer& insert_replace(
            const value_type& value, key_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            node_pointer& insertWhere = find(value, rootNode);
            if (insertWhere == nullptr) {
                insertWhere = new node_type(value);
                ++rootNode.nodesSize;
            } else {
                insertWhere->value() = value;
                ::delete value;
            }

            return insertWhere;
        }

        // if existed value equal to value, replace it
        constexpr static node_pointer& insert_replace(
            value_type&& value, key_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            node_pointer& insertWhere = find(value, rootNode);
            if (insertWhere == nullptr) {
                insertWhere = new node_type(std::move(value));
                ++rootNode.nodesSize;
            } else {
                insertWhere->value() = std::move(value);
                ::delete value;
            }

            return insertWhere;
        }

        // if existed value equal to value, insert it
        constexpr node_pointer& insert_equal(const value_type& value) noexcept {
            return insert_equal(value, *this);
        }

        // if existed value equal to value, insert it
        constexpr node_pointer& insert_equal(value_type&& value) noexcept {
            return insert_equal(std::move(value), *this);
        }

        // if existed value equal to value, insert it
        constexpr static node_pointer& insert_equal(
            const value_type& value, key_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            node_pointer& insertWhere = find(value, rootNode);
            if (insertWhere == nullptr) {
                insertWhere = new node_type(value);
                ++rootNode.nodesSize;
            } else {
                // TODO: implement insert in equal case
            }

            return insertWhere;
        }

        // if existed value equal to value, insert it
        constexpr static node_pointer& insert_equal(
            value_type&& value, key_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            node_pointer& insertWhere = find(value, rootNode);
            if (insertWhere == nullptr) {
                insertWhere = new node_type(std::move(value));
                ++rootNode.nodesSize;
            } else {
                // TODO: implement insert in equal case
            }

            return insertWhere;
        }

        constexpr node_pointer& erase(node_pointer& where) noexcept {
            return erase(where, *this);
        }

        constexpr static node_pointer& erase(
            node_pointer& where, key_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            ::delete where;
            --rootNode.nodesSize;
            node_pointer& max_node = max(where->left());
            if (max_node == nullptr) {
                where   = where->right();
            } else {
                where   = max_node;
                max_node = nullptr;
            }

            return where;
        }
    };

    template<
        typename KeyType,
        typename MappedType,
        typename Compare,
        typename Allocator,
        typename NodeType = pair_binary_search_tree_node<KeyType, MappedType, Compare, Allocator>
    >
    struct pair_binary_search_tree_root_node :
        public mylib::key_binary_search_tree_root_node<
            std::pair<KeyType, MappedType>, 
            Compare, 
            Allocator, 
            NodeType
        > 
    {
    
        using base_type       = 
            mylib::key_binary_search_tree_root_node<
                std::pair<KeyType, MappedType>, 
                Compare, 
                Allocator, 
                NodeType
            >;
        
        using size_type       = typename base_type::size_type;
        
        using node_type       = NodeType;
        using node_pointer    = node_type*;
        
        using key_type        = KeyType;
        using Mapped_type     = MappedType;
        using value_type      = std::pair<KeyType, MappedType>;
        
        using key_compare     = Compare;
        using value_comapre   = typename node_type::value_compare;

        using reference       = std::pair<KeyType, MappedType>&;
        using const_reference = const std::pair<KeyType, MappedType>&;

        using base_type::pRootNode;
        using base_type::nodesSize;
        
        constexpr pair_binary_search_tree_root_node() noexcept : base_type{} 
        {}

        constexpr pair_binary_search_tree_root_node(const pair_binary_search_tree_root_node& other) noexcept :
            base_type{ other } 
        {}

        constexpr pair_binary_search_tree_root_node(pair_binary_search_tree_root_node&& other) noexcept :
            base_type{ std::move(other) } 
        {}

        constexpr pair_binary_search_tree_root_node& operator=(
            const pair_binary_search_tree_root_node& other
        ) noexcept {
            base_type::operator=(other);
            return *this;
        }

        constexpr pair_binary_search_tree_root_node& operator=(
            pair_binary_search_tree_root_node&& other
        ) noexcept {
            base_type::operator=(std::move(other));
            return *this;
        }
        
        constexpr node_pointer& find(const key_type& key) noexcept {
            return find(key, *this);
        }
        
        constexpr const node_pointer& find(const key_type& key) const noexcept {
            return find(key, *this);
        }

        constexpr static node_pointer& find(
            const key_type& key, pair_binary_search_tree_root_node& rootNode
        ) noexcept {
            return find(key, rootNode.pRootNode);
        }

        constexpr static const node_pointer& find(
            const key_type& key, const pair_binary_search_tree_root_node& rootNode
        ) noexcept {
            return find(key, rootNode.pRootNode);
        }

        constexpr static node_pointer& find(
            const key_type& key, node_pointer& pRootNode
        ) noexcept {
            return const_cast<node_pointer&>(find(key, static_cast<const node_pointer&>(pRootNode)));
        }

        constexpr static const node_pointer& find(
            const key_type& key, const node_pointer& pRootNode
        ) noexcept {
            const node_pointer* result = &pRootNode;

            while (*result != nullptr) {
                if (**result > key) {
                    result = &(*result)->left();
                } else if (**result < key) {
                    result = &(*result)->right();
                } else {
                    break;
                }
            }

            return *result;
        }

        // if not found, return nullptr
        constexpr node_pointer& floor(const key_type& value) noexcept {
            return floor(value, *this);
        }

        // if not found, return nullptr
        constexpr const node_pointer& floor(const key_type& value) const noexcept {
            return floor(value, *this);
        }

        // if not found, return nullptr
        constexpr static node_pointer& floor(
            const key_type& value, pair_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            return floor(value, rootNode.root());
        }

        // if not found, return nullptr
        constexpr static const node_pointer& floor(
            const key_type& value, const pair_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            return floor(value, rootNode.root());
        }

        // if not found, return nullptr
        constexpr static node_pointer& floor(
            const key_type& value, node_pointer& pRootNode
        ) noexcept {
            
            return const_cast<node_pointer&>(floor(value, static_cast<const node_pointer&>(pRootNode)));
        }

        // if not found, return nullptr
        constexpr static const node_pointer& floor(
            const key_type& value, const node_pointer& pRootNode
        ) noexcept {
            
            node_pointer* result = &pRootNode;

            while (*result != nullptr) {
                if (**result > value) {
                    result = &(*result)->left();
                } else if (**result == value) {
                    break;
                } else {
                    node_pointer* subFloor = &floor(value, (*result)->right());
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
        constexpr node_pointer& ceil(const key_type& value) noexcept {
            return ceil(value, *this);
        }

        // if not found, return nullptr
        constexpr const node_pointer& ceil(const key_type& value) const noexcept {
            return ceil(value, *this);
        }

        // if not found, return nullptr
        constexpr static node_pointer& ceil(
            const key_type& value, pair_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            return ceil(value, rootNode.root());
        }

        // if not found, return nullptr
        constexpr static const node_pointer& ceil(
            const key_type& value, const pair_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            return ceil(value, rootNode.root());
        }

        // if not found, return nullptr
        constexpr static node_pointer& ceil(
            const key_type& value, node_pointer& pRootNode
        ) noexcept {
            
            return const_cast<node_pointer&>(ceil(value, static_cast<const node_pointer&>(pRootNode)));
        }

        // if not found, return nullptr
        constexpr static const node_pointer& ceil(
            const key_type& value, const node_pointer& pRootNode
        ) noexcept {
            
            const node_pointer* result = &pRootNode;

            while (*result != nullptr) {
                if (**result < value) {
                    result = &(*result)->right();
                } else if (**result == value) {
                    break;
                } else {
                    const node_pointer* subFloor = ceil(value, result->left());
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
        
        // if existed value equal to value, replace it
        constexpr node_pointer& insert_replace(const value_type& value) noexcept {
            return insert_replace(value, *this);
        }

        // if existed value equal to value, replace it
        constexpr node_pointer& insert_replace(value_type&& value) noexcept {
            return insert_replace(std::move(value), *this);
        }

        // if existed value equal to value, replace it
        constexpr static node_pointer& insert_replace(
            const value_type& value, pair_binary_search_tree_root_node& rootNode
        ) noexcept {
            node_pointer& insertWhere = find(value, rootNode);
            if (insertWhere == nullptr) {
                insertWhere = new node_type(value);
                ++rootNode.nodesSize;
            } else {
                insertWhere->mapped() = value.first;
                ::delete value;
            }

            return insertWhere;
        }

        // if existed value equal to value, replace it
        constexpr static node_pointer& insert_replace(
            value_type&& value, pair_binary_search_tree_root_node& rootNode
        ) noexcept {
            
            node_pointer& insertWhere = find(value, rootNode);
            if (insertWhere == nullptr) {
                insertWhere = new node_type(std::move(value));
                ++rootNode.nodesSize;
            } else {
                insertWhere->mapped() = std::move(value.first);
                ::delete value;
            }

            return insertWhere;
        }
    };
    
    template<typename KeyType, typename Compare, typename Allocator, typename RootNodeType>
    class base_key_binary_search_tree;

    template<
        typename KeyType,
        typename Allocator    = std::allocator  <KeyType>,
        typename RootNodeType = key_binary_tree_root_node<KeyType, Allocator>
    >
    class base_key_binary_tree {
    public:
        using key_type        = KeyType;
        using value_type      = key_type;

        using size_type       = typename std::allocator_traits<Allocator>::size_type;

        using node_type       = typename RootNodeType::node_type;

        using node_pointer    = node_type*;

        using root_node_type  = RootNodeType;

        using allocator_type  = Allocator;

        using reference       = value_type&;

        using const_reference = const value_type&;


        constexpr base_key_binary_tree() noexcept : 
            rootNode{} 
        {}

        constexpr base_key_binary_tree(const base_key_binary_tree& other) noexcept : 
            rootNode{ other.rootNode } 
        {}

        constexpr base_key_binary_tree(base_key_binary_tree&& other) noexcept : 
            rootNode{ std::move(other.rootNode) } 
        {}

        constexpr base_key_binary_tree& operator=(const base_key_binary_tree& other) noexcept {
            rootNode = other.rootNode;
            return *this;
        }

        constexpr base_key_binary_tree& operator=(base_key_binary_tree&& other) noexcept {
            rootNode = std::move(other.rootNode);
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

        constexpr void draw_tree(
            char nodeChar = 'O', char emptyChar = 'X', char middleLineChar = ' ', 
            std::ostream& os = std::cout
        ) noexcept {
            
            rootNode.draw_tree(nodeChar, emptyChar, middleLineChar, os);
        }

        // char type specific draw_tree reload
        constexpr void draw_tree(char emptyChar = ' ', std::ostream& os = std::cout) noexcept
            requires std::is_same_v<KeyType, char> {
            rootNode.draw_tree(emptyChar, os);
        }

        constexpr size_type size() const noexcept {
            return rootNode.size();
        }

    private:
        template<typename KeyType, typename MappedType, typename Allocator, typename RootNodeType>
        friend class base_pair_binary_tree;

        root_node_type rootNode;

        // char type specific draw_tree reload
        constexpr node_pointer insert_by_string(std::string_view initialString, size_t& index) noexcept
            requires std::is_same_v<KeyType, char> {

            if (index >= initialString.size() || initialString[index] == '#') {
                return nullptr;
            } else {
                ++rootNode.nodesSize;
                node_pointer result = new node_type{ initialString[index], nullptr, nullptr };
                result->left()      = insert_by_string(initialString, ++index);
                result->right()     = insert_by_string(initialString, ++index);
                return result;
            }
        }

    public:
        // char type specific draw_tree reload
        constexpr base_key_binary_tree(std::string_view initialString) noexcept
            requires std::is_same_v<KeyType, char> {
            size_t index = 0;
            rootNode.pRootNode = insert_by_string(initialString, index);
        }

        template<typename KeyType, typename Compare, typename Allocator, typename RootNodeType>
        friend class mylib::base_key_binary_search_tree;
    };

    template<
        typename KeyType,
        typename MappedType,
        typename Allocator    = std::allocator<KeyType>,
        typename RootNodeType = pair_binary_tree_root_node<KeyType, MappedType, Allocator>
    >
    class base_pair_binary_tree :
        public base_key_binary_tree<std::pair<KeyType, MappedType>, Allocator, RootNodeType> {

    public:
        using key_type        = KeyType;
        using mapped_type     = MappedType;
        using value_type      = std::pair<key_type, mapped_type>;

        using node_type       = typename RootNodeType::node_type;

        using node_pointer    = node_type*;

        using size_type       = typename std::allocator_traits<Allocator>::size_type;

        using root_node_type  = RootNodeType;

        using allocator_type  = Allocator;

        using reference       = value_type&;

        using const_reference = const value_type&;

        using base_type       = mylib::base_key_binary_tree<std::pair<KeyType, MappedType>, Allocator, RootNodeType>;

        constexpr base_pair_binary_tree() : base_type{} {}

        constexpr base_pair_binary_tree(const base_pair_binary_tree& other) : 
            base_type{ other } 
        {}

        constexpr base_pair_binary_tree(base_pair_binary_tree&& other) : 
            base_type{ std::move(other) } 
        {}

        constexpr base_pair_binary_tree& operator=(const base_pair_binary_tree& other) {
            return base_type::operator =(other);
        }

        constexpr base_pair_binary_tree& operator=(base_pair_binary_tree&& other) {
            return base_type::operator =(std::move(other));
        }
    };

    template<typename KeyType, typename MappedType, typename Compare, typename Allocator, typename RootNodeType>
    class base_pair_binary_search_tree;

    template<
        typename KeyType                                   ,
        typename Compare       = std::less       <KeyType>,
        typename Allocator     = std::allocator  <KeyType>,
        typename RootNodeType  = key_binary_search_tree_root_node<KeyType, Compare, Allocator>
    >
    class base_key_binary_search_tree :
        public mylib::base_key_binary_tree<KeyType, Allocator, RootNodeType> {

    public:
        using base_type       = mylib::base_key_binary_tree<KeyType, Allocator, RootNodeType>;

        using key_type        = KeyType;
        using value_type      = key_type;

        using key_compare     = Compare;
        using value_compare   = key_compare;

        using size_type       = typename std::allocator_traits<Allocator>::size_type;

        using node_type       = typename RootNodeType::node_type;

        using node_pointer    = node_type*;
        
        using root_node_type  = RootNodeType;
        
        using allocator_type  = Allocator;

        using reference       = value_type&;

        using const_reference = const value_type&;

        using base_type::rootNode;

        constexpr base_key_binary_search_tree() noexcept : base_type{} 
        {}

        constexpr base_key_binary_search_tree(const base_key_binary_search_tree& other) noexcept : 
            base_type{ other } 
        {}

        constexpr base_key_binary_search_tree(base_key_binary_search_tree&& other) noexcept : 
            base_type{ std::move(other) } 
        {}

        constexpr base_key_binary_search_tree(std::initializer_list<KeyType> _InitializerList) noexcept : base_type{} {
            for (const auto& value : _InitializerList) {
                insert_unique(value);
            }
        }
        
        constexpr base_key_binary_search_tree& operator=(const base_key_binary_search_tree& other) noexcept {
            return base_type::operator =(other);
        }

        constexpr base_key_binary_search_tree& operator=(base_key_binary_search_tree&& other) noexcept {
            return base_type::operator =(std::move(other));
        }

            
        // TODO: following methon return value change to iterator
        constexpr node_pointer& find(const value_type& value) noexcept {
            return rootNode.find(value);
        }

        constexpr const node_pointer& find(const value_type& value) const noexcept {
            return rootNode.find(value);
        }

        constexpr node_pointer& floor(const value_type& value) noexcept {
            return rootNode.floor(value);
        }

        constexpr const node_pointer& floor(const value_type& value) const noexcept {
            return rootNode.floor(value);
        }
        
        constexpr node_pointer& ceil(const value_type& value) noexcept {
            return rootNode.ceil(value);
        }
        
        constexpr const node_pointer& celi(const value_type& value) const noexcept {
            return rootNode.ceil(value);
        }
            
        constexpr node_pointer& insert_unique(const value_type& value) noexcept {
            return rootNode.insert_unique(value);
        }

        constexpr node_pointer& insert_unique(value_type&& value) noexcept {
            return rootNode.insert_unique(std::move(value));
        }

        constexpr node_pointer& insert_replace(const value_type& value) noexcept {
            return rootNode.insert_replace(value);
        }

        constexpr node_pointer& insert_replace(value_type&& value) noexcept {
            return rootNode.insert_replace(std::move(value));
        }
        
        constexpr node_pointer& insert_equal(const value_type& value) noexcept {
            return rootNode.insert_equal(value);
        }

        constexpr node_pointer& insert_equal(value_type&& value) noexcept {
            return rootNode.insert_equal(std::move(value));
        }

        constexpr node_pointer& erase(node_pointer& where) noexcept {
            return rootNode.erase(where);
        }

        constexpr std::vector<value_type> to_vector() noexcept {
            return rootNode.to_vector();
        }

        constexpr const size_type depth() const noexcept {
            return rootNode.depth();
        }

        constexpr void draw_tree(char nodeChar = 'O', char emptyChar = 'X', char middleLineChar = ' ', std::ostream& os = std::cout) noexcept {
            rootNode.draw_tree(nodeChar, emptyChar, middleLineChar, os);
        }

        // char type specific draw_tree reload
        constexpr void draw_tree(char emptyChar = ' ', std::ostream & os = std::cout) noexcept
                requires std::is_same_v<KeyType, char> {
            rootNode.draw_tree(emptyChar, os);
        }

        constexpr size_type size() const noexcept {
            return rootNode.size();
        }

    private:
        template<
            typename KeyType, 
            typename MappedType, 
            typename Compare, 
            typename Allocator, 
            typename RootNodeType
        > friend class mylib::base_pair_binary_search_tree;

    public:
        // char type specific draw_tree reload
        constexpr base_key_binary_search_tree(std::string_view initialString) noexcept
                requires std::is_same_v<KeyType, char> : base_type{ initialString } {}
    };

    template<
        typename KeyType                                   ,
        typename MappedType                                ,
        typename Compare       = std::less       <KeyType>,
        typename Allocator     = std::allocator  <KeyType>,
        typename RootNodeType  = pair_binary_search_tree_root_node<KeyType, MappedType, Compare, Allocator>
    >
    class base_pair_binary_search_tree : 
        public mylib::base_key_binary_search_tree<
            std::pair<KeyType, MappedType>, Compare, Allocator, RootNodeType
        > 
    {
        
    public:
        using key_type          = KeyType;
        using mapped_type       = MappedType;
        using value_type        = std::pair<key_type, mapped_type>;

        using node_type         = typename RootNodeType::node_type;

        using node_pointer      = node_type*;
        
        using key_compare       = Compare;
        using value_compare     = typename RootNodeType::value_compare;

        using size_type         = typename std::allocator_traits<Allocator>::size_type;

        using root_node_type    = RootNodeType;

        using allocator_type    = Allocator;

        using reference         = value_type&;

        using const_reference   = const value_type&;
        
        using base_type         = 
            mylib::base_key_binary_search_tree<
                std::pair<KeyType, MappedType>, 
                Compare, 
                Allocator,
                RootNodeType
            >;
        
        constexpr base_pair_binary_search_tree() : base_type{} 
        {}

        constexpr base_pair_binary_search_tree(const base_pair_binary_search_tree& other) : 
            base_type{ other } 
        {}

        constexpr base_pair_binary_search_tree(base_pair_binary_search_tree&& other) : 
            base_type{ std::move(other) } 
        {}

        constexpr base_pair_binary_search_tree(
            std::initializer_list<std::pair<KeyType, MappedType>> _InitializerList
        ) noexcept {
            for (auto& value : _InitializerList) {
                this->insert_unique(value);
            }
        }
        
        constexpr base_pair_binary_search_tree& operator=(const base_pair_binary_search_tree& other) {
            base_type::operator=(other);
            return *this;
        }

        constexpr base_pair_binary_search_tree& operator=(base_pair_binary_search_tree&& other) {
            base_type::operator=(std::move(other));
            return *this;
        }
        
        constexpr node_pointer& find(const key_type& key) noexcept {
            return this->rootNode.find(key);
        }

        constexpr const node_pointer& find(const key_type& key) const noexcept {
            return this->rootNode.find(key);
        }
        
        constexpr node_pointer& floor(const key_type& key) noexcept {
            return this->rootNode.floor(key);
        }

        constexpr const node_pointer& floor(const key_type& key) const noexcept {
            return this->rootNode.floor(key);
        }

        constexpr node_pointer& ceil(const key_type& key) noexcept {
            return this->rootNode.ceil(key);
        }

        constexpr const node_pointer& ceil(const key_type& key) const noexcept {
            return this->rootNode.ceil(key);
        }
    };
}
