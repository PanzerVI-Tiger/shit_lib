export module mylib.new_binary_tree;


export namespace mylib::inline test {
    
    template<typename TreeNode>
    struct binary_tree_node_base {

        // TODO: wait for support for `deducing this` in module

        //auto left(this auto& self) noexcept {
        //    return self.leftNode;
        //}

        //auto right(this auto& self) noexcept {
        //    return self.rightNode;
        //}

        TreeNode* leftNode;
        TreeNode* rightNode;
    };

    template<typename TreeTraits>
    struct binary_tree_node :
        binary_tree_node_base<
            binary_tree_node<TreeTraits>
        >
    {

    };
}
