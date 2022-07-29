export module mylib.huffman_tree;

import std.core;
import mylib.binary_tree;


export namespace mylib {

    template<
        typename _WeightType, 
        typename _MappedType, 
        typename _Compare      = std::less<size_t>, 
        typename _Allocator    = std::allocator<_WeightType>,
        typename _RootNodeType = pair_binary_search_tree_node<_WeightType, _MappedType, _Compare, _Allocator>
    >
    struct list_huffman_tree : 
        public base_pair_binary_search_tree<_WeightType, _MappedType, _Compare, _Allocator> {
        
    public:
        using base_type       = base_pair_binary_search_tree<_WeightType, _MappedType, _Compare, _Allocator>;
        
        using key_type        = _WeightType;
        using mapped_type     = _MappedType;
        using value_type      = std::pair<key_type, mapped_type>;

        using node_type       = typename base_type::node_type;

        using node_pointer    = node_type*;

        using key_compare     = _Compare;
        using value_compare   = typename base_type::value_compare;

        using size_type       = typename std::allocator_traits<_Allocator>::size_type;

        using root_node_type  = typename base_type::_RootNodeType;

        using allocator_type  = _Allocator;

        using reference       = value_type&;

        using const_reference = const value_type&;

        constexpr list_huffman_tree(std::set<node_pointer>& _NodeSet) {
            this->rootNode.numberOfNodes = _NodeSet.size();

            while (_NodeSet.size() > 1) {
                auto temp1 = *_NodeSet.begin();
                _NodeSet.erase(_NodeSet.begin());
                auto temp2 = *_NodeSet.begin();
                _NodeSet.erase(_NodeSet.begin());
                _NodeSet.insert(new node_type{ _MappedType{}, temp1, temp2 });
            }

            this->rootNode.pRootNode = new node_type{ std::move(*_NodeSet.begin()) };
        }
    };
}

export {

}