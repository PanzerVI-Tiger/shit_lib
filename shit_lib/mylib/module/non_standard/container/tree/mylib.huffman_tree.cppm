module;

#ifdef __INTELLISENSE__

#include <set>
#include <memory>
#include <utility>

#endif


export module mylib.huffman_tree;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.binary_tree;


export namespace mylib {

    template<
        typename WeightType, 
        typename MappedType, 
        typename Compare      = std::less<size_t>, 
        typename Allocator    = std::allocator<WeightType>,
        typename RootNodeType = mylib::pair_binary_search_tree_node<WeightType, MappedType, Compare, Allocator>
    >
    struct list_huffman_tree : 
        mylib::base_pair_binary_search_tree<WeightType, MappedType, Compare, Allocator> {
        
    public:
        using base_type       = mylib::base_pair_binary_search_tree<WeightType, MappedType, Compare, Allocator>;
        
        using key_type        = WeightType;
        using mapped_type     = MappedType;
        using value_type      = std::pair<key_type, mapped_type>;

        using node_type       = typename base_type::node_type;

        using node_pointer    = node_type*;

        using key_compare     = Compare;
        using value_compare   = typename base_type::value_compare;

        using size_type       = typename std::allocator_traits<Allocator>::size_type;

        using root_node_type  = typename base_type::RootNodeType;

        using allocator_type  = Allocator;

        using reference       = value_type&;

        using const_reference = const value_type&;

        constexpr list_huffman_tree(std::set<node_pointer>& nodeSet) {
            this->rootNode.numberOfNodes = nodeSet.size();

            while (nodeSet.size() > 1) {
                auto temp1 = *nodeSet.begin();
                nodeSet.erase(nodeSet.begin());
                auto temp2 = *nodeSet.begin();
                nodeSet.erase(nodeSet.begin());
                nodeSet.insert(new node_type{ MappedType{}, temp1, temp2 });
            }

            this->rootNode.pRootNode = new node_type{ std::move(*nodeSet.begin()) };
        }
    };
}

export {

}