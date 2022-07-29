export module mylib.graph;

import std.core;
import mylib.queue;
import mylib.binary_tree;

export namespace mylib {
     
    template<typename IndexType>
    using edge = std::pair<IndexType, IndexType>;
    
    template<typename ElementType, typename Allocator = std::allocator<ElementType>>
    class am_graph {
    public:
        using size_type              = typename std::allocator_traits<Allocator>::size_type;

        using value_type             = ElementType;

        using allocator_type         = Allocator;

        using reference              = value_type&;
        using const_reference        = const value_type&;

        using difference_type        = typename std::allocator_traits<Allocator>::difference_type;

        using pointer                = typename std::allocator_traits<Allocator>::pointer;
        using const_pointer          = typename std::allocator_traits<Allocator>::const_pointer;

        //using iterator               = deque_iterator<block_type>;
        //using reverse_iterator       = std::reverse_iterator<iterator>;
        //using const_iterator         = deque_const_iterator<block_type>;
        //using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    private:
        constexpr void extend() noexcept {
            size_type   newVertexesMax = (vertexesMax >> 1) + vertexesMax; // *1.5
            size_type   newEdgesMax    = newVertexesMax * newVertexesMax;
            value_type* newVertexes    = new value_type[newVertexesMax];
            bool*       newEdgesMatrix = new bool[newEdgesMax] {};
            
            memcpy(newVertexes, vertexes, vertexesSize * sizeof(value_type));
            for (size_type i = 0, limit = vertexesMax * sizeof(bool);
                i < edgesMax;
                ++i, i += vertexesMax
                ) {
                memcpy(newEdgesMatrix, edgesMatrix + i, limit);
            }

            delete[] vertexes;
            delete[] edgesMatrix;

            vertexes    = newVertexes;
            edgesMatrix = newEdgesMatrix;
            vertexesMax = newVertexesMax;
            edgesMax    = newEdgesMax;
        }

    public:
        constexpr am_graph() noexcept : edgesMax{ 0 }, edgesSize{ 0 },
            vertexesSize{ 0 }, vertexes{ nullptr }, edgesMatrix{ nullptr } {}

        constexpr am_graph(std::initializer_list<ElementType> initialValueList) noexcept :
                vertexesSize{ initialValueList.size() }, edgesSize{0} {

            // TODO: use taylor expansion to calculate the max number of edges
            vertexesMax       = std::ceil(std::log(vertexesSize) / std::log(1.5));
            edgesMax          = vertexesMax * vertexesMax;
            vertexes          = new value_type[vertexesMax];
            edgesMatrix       = new bool[edgesMax]{};
            
            std::copy(initialValueList.begin(), initialValueList.end(), vertexes);
        }
        
        constexpr ~am_graph() noexcept {
            vertexesSize = 0;
            vertexesMax  = 0;
            edgesSize    = 0;
            edgesMax     = 0;
            
            delete[] vertexes;
            delete[] edgesMatrix;
            
            vertexes    = nullptr;
            edgesMatrix = nullptr;
        }

        constexpr void insert_edge(size_type first, size_type second) noexcept {
            edgesMatrix[first  * vertexesMax + second] = true;
            edgesMatrix[second * vertexesMax + first ] = true;
            ++edgesSize;
        }

        constexpr void insert_edge(edge<size_type> edge) noexcept {
            insert_edge(edge.first, edge.second);
        }

        // return the index of vertex
        constexpr size_type insert_vertex(const value_type& value) noexcept {
            extend();
            vertexes[++vertexesSize] = value;

            return vertexesSize;
        }
        
        // return the index of vertex
        constexpr size_type insert_vertex(value_type&& value) noexcept {
            extend();
            vertexes[++vertexesSize] = std::move(value);

            return vertexesSize;
        }

        constexpr std::vector<size_type> adjacent_vertexes(size_t index) const noexcept {
            std::vector<size_type> result;

            const size_type vertexesSize = vertexes_size();
            for (size_type limit = index * vertexesSize, i = limit - vertexesSize; i < limit; ++i) {
                if (edgesMatrix[i]) {
                    result.push_back(i % limit);
                }
            }

            return result;
        }

        constexpr size_type degree(size_type index) const noexcept {
            size_type result{};

            const size_type vertexesSize = vertexes_size();
            for (size_type limit = index * vertexesSize, i = limit - vertexesSize; i < limit; ++i) {
                if (edgesMatrix[i]) {
                    ++result;
                }
            }

            return result;
        }

        constexpr size_type max_degree() const noexcept {
            if (edgesSize == 0) {
                return 0;
            }

            size_type max{ std::numeric_limits<size_type>::min() };

            for (size_type limit = vertexes_size(), i = 0; i < limit; ++i) {
                size_type temp = degree(i);
                if (temp > max) {
                    max = temp;
                }
            }

            return max;
        }

        constexpr double average_degree() const noexcept {
            return 2.0 * edges_size() / vertexes_size();
        }

        constexpr size_type vertexes_size() const noexcept {
            return vertexesSize;
        }

        constexpr size_type edges_size() const noexcept {
            return edgesSize;
        }

        constexpr const value_type& operator [](size_type index) const noexcept {
            return vertexes[index];
        }

        constexpr value_type& operator [](size_type index) noexcept {
            return vertexes[index];
        }
        
    private:
        bool*     edgesMatrix;   // hold it size equal 4 ^ 3N ( (2 ^ 1.5N) ^ 2 )
        pointer   vertexes;      // hold it size equal 2 ^ 1.5N
        
        size_type vertexesSize;
        size_type vertexesMax;
        size_type edgesSize;
        size_type edgesMax;
    };

    template<
        typename ElementType, 
        typename Allocator                       = std::allocator<ElementType>, 
        template<typename ElementType> 
            class AdjacencyEdgeContainerTemplate = std::vector
    >
    class al_graph {
    public:
        using size_type       = typename std::allocator_traits<Allocator>::size_type;

        using value_type      = ElementType;

        using allocator_type  = Allocator;

        using reference       = value_type&;
        using const_reference = const value_type&;

        using difference_type = typename std::allocator_traits<Allocator>::difference_type;

        using pointer         = typename std::allocator_traits<Allocator>::pointer;
        using const_pointer   = typename std::allocator_traits<Allocator>::const_pointer;

        struct node {
            size_type                                  index;
            ElementType                               value;
            AdjacencyEdgeContainerTemplate<size_type> adjacency_node;
        };

        constexpr al_graph() noexcept : edgesSize{}, adjacency_list {} {}

        constexpr al_graph(std::initializer_list<ElementType> initialValueList) noexcept :
            edgesSize{}, adjacency_list {} {
            
            auto iterBegin = initialValueList.begin();
            auto iterEnd   = initialValueList.end();
            for (size_type i = 0; iterBegin != iterEnd; ++i, ++iterBegin) {
                adjacency_list.emplace_back(i, *iterBegin);
            }
        }

        constexpr void insert_edge(size_type first, size_type second) noexcept {
            adjacency_list[first ].adjacency_node.push_back(second);
            adjacency_list[second].adjacency_node.push_back(first );
            ++edgesSize;
        }

        constexpr void insert_edge(edge<size_type> edge) noexcept {
            insert_edge(edge.first, edge.second);
        }

        constexpr size_type insert_vertex(const value_type& value) noexcept {
            const size_type result = adjacency_list.size();
            adjacency_list.emplace_back(result, value);

            return result;
        }

        constexpr size_type insert_vertex(value_type&& value) noexcept {
            const size_type result = adjacency_list.size();
            adjacency_list.emplace_back(result, std::move(value));

            return result;
        }

        constexpr std::vector<size_type> adjacent_vertexes(size_t index) const noexcept {
            return adjacency_list[index].adjacency_node;
        }

        constexpr size_type degree(size_type index) const noexcept {
            return adjacency_list[index].adjacency_node.size();
        }

        constexpr size_type max_degree() const noexcept {
            if (edgesSize == 0) {
                return 0;
            }

            size_type max{ std::numeric_limits<size_type>::min() };

            for (const node& i : adjacency_list) {
                const size_type temp = i.adjacency_node.size();
                if (temp > max) {
                    max = temp;
                }
            }

            return max;
        }

        constexpr double average_degree() const noexcept {
            return 2.0 * edges_size() / vertexes_size();
        }

        constexpr size_type edges_size() const noexcept {
            return edgesSize;
        }

        constexpr size_type vertexes_size() const noexcept {
            return adjacency_list.size();
        }

        constexpr const value_type& operator [](size_type index) const noexcept {
            return adjacency_list[index].value;
        }

        constexpr value_type& operator [](size_type index) noexcept {
            return adjacency_list[index].value;
        }

    private:
        size_type         edgesSize;
        std::vector<node> adjacency_list;
    };

    template<
        typename ElementType, 
        typename Allocator = std::allocator<ElementType>, 
        typename BaseGraph = al_graph<ElementType, Allocator>
    >
    class graph {
    public:
        using base_graph      = BaseGraph;

        using allocator_type  = typename base_graph::allocator_type;

        using size_type       = typename base_graph::size_type;

        using value_type      = ElementType;

        using reference       = typename base_graph::reference;

        using const_reference = typename base_graph::const_reference;

        using difference_type = typename base_graph::difference_type;

        using pointer         = typename base_graph::pointer;
        using const_pointer   = typename base_graph::const_pointer;

        constexpr graph() : base{} {}

        constexpr graph(const BaseGraph& baseGraph) : base{ baseGraph } {}

        constexpr graph(BaseGraph&& baseGraph) : base{ std::move(baseGraph) } {}

        constexpr graph(std::initializer_list<ElementType> initialValueList) noexcept :
            base{ initialValueList } {}

        constexpr void insert_edge(size_type first, size_type second) noexcept {
            base.insert_edge(first, second);
        }

        constexpr void insert_edge(edge<size_type> edge) noexcept {
            base.insert_edge(edge);
        }

        constexpr size_type insert_vertex(const value_type& value) noexcept {
            return base.insert_vertex(value);
        }

        constexpr size_type insert_vertex(value_type&& value) noexcept {
            return base.insert_vertex(std::move(value));
        }

        constexpr std::vector<size_type> adjacent_vertexes(size_t index) const noexcept {
            return base.adjacent_vertexes(index);
        }

        constexpr size_type degree(size_type index) const noexcept {
            return base.degree(index);
        }

        constexpr size_type max_degree() const noexcept {
            return base.max_degree();
        }

        constexpr double average_degree() const noexcept {
            return base.average_size();
        }

        constexpr size_type edges_size() const noexcept {
            return base.edges_size();
        }

        constexpr size_type vertexes_size() const noexcept {
            return base.vertexes_size();
        }

        constexpr const value_type& operator [](size_type index) const noexcept {
            return base[index];
        }

        constexpr value_type& operator [](size_type index) noexcept {
            return base[index];
        }

        constexpr std::vector<size_type> dfs(size_type source) const noexcept {
            const size_type        vertexesSize = vertexes_size();
            bool*                  marked       = new bool[vertexesSize]{};
            std::vector<size_type> result;

            [&result, marked, this](this const auto& self, size_type s) constexpr -> void {
                result.push_back(s);
                marked[s] = true;

                for (size_type i : adjacent_vertexes(s)) {
                    if (!marked[i]) {
                        self(i);
                    }
                }
            }(source);

            delete[] marked;

            return result;
        }

        constexpr void dfs(size_type source, std::function<void(value_type&)> unaryFunc) noexcept {
            const size_type        vertexesSize = vertexes_size();
            bool*                  marked       = new bool[vertexesSize] {};

            [marked, this, unaryFunc](this const auto& self, size_type s) constexpr -> void {
                unaryFunc((*this)[s]);
                marked[s] = true;

                for (size_type i : adjacent_vertexes(s)) {
                    if (!marked[i]) {
                        self(i);
                    }
                }
            }(source);

            delete[] marked;
        }

        constexpr void dfs(size_type source, std::function<void(value_type&)> unaryFunc) const noexcept {
            const size_type        vertexesSize = vertexes_size();
            bool*                  marked       = new bool[vertexesSize] {};

            [marked, this, unaryFunc](this const auto& self, size_type s) constexpr -> void {
                unaryFunc((*this)[s]);
                marked[s] = true;

                for (size_type i : adjacent_vertexes(s)) {
                    if (!marked[i]) {
                        self(i);
                    }
                }
            }(source);

            delete[] marked;
        }

        constexpr std::vector<size_type> bfs(size_type source) const noexcept {
            const size_type        vertexesSize = vertexes_size();
            bool*                  marked       = new bool[vertexesSize]{};
            std::vector<size_type> result;
            queue<size_type>       next;
            next.push(source);
            
            while (!next.empty()) {
                const size_type s = next.front();

                next.pop();
                marked[s] = true;
                result.push_back(s);

                for (size_type i : adjacent_vertexes(s)) {
                    if (!marked[i]) {
                        next.push(i);
                    }
                }
            }

            delete[] marked;

            return result;
        }

        constexpr void bfs(size_type source, std::function<void(value_type&)> unaryFunc) noexcept {
            const size_type        vertexesSize = vertexes_size();
            bool*                  marked       = new bool[vertexesSize] {};
            queue<size_type>       next;
            next.push(source);

            while (!next.empty()) {
                const size_type s = next.front();

                next.pop();
                marked[s] = true;
                unaryFunc((*this)[s]);

                for (size_type i : adjacent_vertexes(s)) {
                    if (!marked[i]) {
                        next.push(i);
                    }
                }
            }

            delete[] marked;
        }

        constexpr void bfs(size_type source, std::function<void(value_type&)> unaryFunc) const noexcept {
            const size_type        vertexesSize = vertexes_size();
            bool*                  marked       = new bool[vertexesSize] {};
            queue<size_type>       next;
            next.push(source);

            while (!next.empty()) {
                const size_type s = next.front();

                next.pop();
                marked[s] = true;
                unaryFunc((*this)[s]);

                for (size_type i : adjacent_vertexes(s)) {
                    if (!marked[i]) {
                        next.push(i);
                    }
                }
            }

            delete[] marked;
        }

        base_key_binary_tree<ElementType> minimum_spanning_tree(size_type source) const noexcept {
             
        }
        
    private:
        base_graph base;
    };
}
