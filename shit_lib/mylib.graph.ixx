export module mylib.graph;

import std.core;
import mylib.queue;
import mylib.binary_tree;

export namespace mylib {
     
    template<typename _IndexType>
    using edge = std::pair<_IndexType, _IndexType>;
    
    template<typename _ElementType, typename _Allocator = std::allocator<_ElementType>>
    class am_graph {
    public:
        using size_type				 = typename std::allocator_traits<_Allocator>::size_type;

        using value_type			 = _ElementType;

        using allocator_type		 = _Allocator;

        using reference				 = value_type&;
        using const_reference		 = const value_type&;

        using difference_type		 = typename std::allocator_traits<_Allocator>::difference_type;

        using pointer				 = typename std::allocator_traits<_Allocator>::pointer;
        using const_pointer			 = typename std::allocator_traits<_Allocator>::const_pointer;

        //using iterator			   = deque_iterator<block_type>;
        //using reverse_iterator	   = std::reverse_iterator<iterator>;
        //using const_iterator		   = deque_const_iterator<block_type>;
        //using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    private:
        constexpr void extend() noexcept {
            size_type   newVertexesMax = (vertexesMax >> 1) + vertexesMax; // *1.5
            size_type   newEdgesMax	   = newVertexesMax * newVertexesMax;
            value_type* newVertexes    = new value_type[newVertexesMax];
            bool*		newEdgesMatrix = new bool[newEdgesMax] {};
            
            memcpy(newVertexes, vertexes, vertexesSize * sizeof(value_type));
            for (size_type i = 0, limit = vertexesMax * sizeof(bool);
                i < edgesMax;
                ++i, i += vertexesMax
                ) {
                memcpy(newEdgesMatrix, edgesMatrix + i, limit);
            }

            delete[] vertexes;
            delete[] edgesMatrix;

            vertexes	= newVertexes;
            edgesMatrix = newEdgesMatrix;
            vertexesMax = newVertexesMax;
            edgesMax    = newEdgesMax;
        }

    public:
        constexpr am_graph() noexcept : edgesMax{ 0 }, edgesSize{ 0 },
            vertexesSize{ 0 }, vertexes{ nullptr }, edgesMatrix{ nullptr } {}

        constexpr am_graph(std::initializer_list<_ElementType> _InitializerList) noexcept :
                vertexesSize{ _InitializerList.size() }, edgesSize{0} {

            // TODO: use taylor expansion to calculate the max number of edges
            vertexesMax		  = std::ceil(std::log(vertexesSize) / std::log(1.5));
            edgesMax		  = vertexesMax * vertexesMax;
            vertexes		  = new value_type[vertexesMax];
            edgesMatrix		  = new bool[edgesMax]{};
            
            std::copy(_InitializerList.begin(), _InitializerList.end(), vertexes);
        }
        
        constexpr ~am_graph() noexcept {
            vertexesSize = 0;
            vertexesMax  = 0;
            edgesSize	 = 0;
            edgesMax	 = 0;
            
            delete[] vertexes;
            delete[] edgesMatrix;
            
            vertexes	= nullptr;
            edgesMatrix = nullptr;
        }

        constexpr void insert_edge(size_type _First, size_type _Second) noexcept {
            edgesMatrix[_First  * vertexesMax + _Second] = true;
            edgesMatrix[_Second * vertexesMax + _First ] = true;
            ++edgesSize;
        }

        constexpr void insert_edge(edge<size_type> _Edge) noexcept {
            insert_edge(_Edge.first, _Edge.second);
        }

        // return the index of vertex
        constexpr size_type insert_vertex(const value_type& _Value) noexcept {
            extend();
            vertexes[++vertexesSize] = _Value;

            return vertexesSize;
        }
        
        // return the index of vertex
        constexpr size_type insert_vertex(value_type&& _Value) noexcept {
            extend();
            vertexes[++vertexesSize] = std::move(_Value);

            return vertexesSize;
        }

        constexpr std::vector<size_type> adjacent_vertexes(size_t _Index) const noexcept {
            std::vector<size_type> result;

            const size_type vertexesSize = vertexes_size();
            for (size_type limit = _Index * vertexesSize, i = limit - vertexesSize; i < limit; ++i) {
                if (edgesMatrix[i]) {
                    result.push_back(i % limit);
                }
            }

            return result;
        }

        constexpr size_type degree(size_type _Index) const noexcept {
            size_type result{};

            const size_type vertexesSize = vertexes_size();
            for (size_type limit = _Index * vertexesSize, i = limit - vertexesSize; i < limit; ++i) {
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

        constexpr const value_type& operator [](size_type _Index) const noexcept {
            return vertexes[_Index];
        }

        constexpr value_type& operator [](size_type _Index) noexcept {
            return vertexes[_Index];
        }
        
    private:
        bool*	  edgesMatrix;   // hold it size equal 4 ^ 3N ( (2 ^ 1.5N) ^ 2 )
        pointer   vertexes;	     // hold it size equal 2 ^ 1.5N
        
        size_type vertexesSize;
        size_type vertexesMax;
        size_type edgesSize;
        size_type edgesMax;
    };

    template<
        typename _ElementType, 
        typename _Allocator						  = std::allocator<_ElementType>, 
        template<typename _ElementType> 
            class _AdjacencyEdgeContainerTemplate = std::vector
    >
    class al_graph {
    public:
        using size_type		  = typename std::allocator_traits<_Allocator>::size_type;

        using value_type	  = _ElementType;

        using allocator_type  = _Allocator;

        using reference		  = value_type&;
        using const_reference = const value_type&;

        using difference_type = typename std::allocator_traits<_Allocator>::difference_type;

        using pointer		  = typename std::allocator_traits<_Allocator>::pointer;
        using const_pointer	  = typename std::allocator_traits<_Allocator>::const_pointer;

        struct node {
            size_type								   index;
            _ElementType							   value;
            _AdjacencyEdgeContainerTemplate<size_type> adjacency_node;
        };

        constexpr al_graph() noexcept : edgesSize{}, adjacency_list {} {}

        constexpr al_graph(std::initializer_list<_ElementType> _InitializerList) noexcept :
            edgesSize{}, adjacency_list {} {
            
            auto iterBegin = _InitializerList.begin();
            auto iterEnd   = _InitializerList.end();
            for (size_type i = 0; iterBegin != iterEnd; ++i, ++iterBegin) {
                adjacency_list.emplace_back(i, *iterBegin);
            }
        }

        constexpr void insert_edge(size_type _First, size_type _Second) noexcept {
            adjacency_list[_First ].adjacency_node.push_back(_Second);
            adjacency_list[_Second].adjacency_node.push_back(_First );
            ++edgesSize;
        }

        constexpr void insert_edge(edge<size_type> _Edge) noexcept {
            insert_edge(_Edge.first, _Edge.second);
        }

        constexpr size_type insert_vertex(const value_type& _Value) noexcept {
            const size_type result = adjacency_list.size();
            adjacency_list.emplace_back(result, _Value);

            return result;
        }

        constexpr size_type insert_vertex(value_type&& _Value) noexcept {
            const size_type result = adjacency_list.size();
            adjacency_list.emplace_back(result, std::move(_Value));

            return result;
        }

        constexpr std::vector<size_type> adjacent_vertexes(size_t _Index) const noexcept {
            return adjacency_list[_Index].adjacency_node;
        }

        constexpr size_type degree(size_type _Index) const noexcept {
            return adjacency_list[_Index].adjacency_node.size();
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

        constexpr const value_type& operator [](size_type _Index) const noexcept {
            return adjacency_list[_Index].value;
        }

        constexpr value_type& operator [](size_type _Index) noexcept {
            return adjacency_list[_Index].value;
        }

    private:
        size_type		  edgesSize;
        std::vector<node> adjacency_list;
    };

    template<
        typename _ElementType, 
        typename _Allocator = std::allocator<_ElementType>, 
        typename _BaseGraph = al_graph<_ElementType, _Allocator>
    >
    class graph {
    public:
        using base_graph	  = _BaseGraph;

        using allocator_type  = typename base_graph::allocator_type;

        using size_type		  = typename base_graph::size_type;

        using value_type	  = _ElementType;

        using reference		  = typename base_graph::reference;

        using const_reference = typename base_graph::const_reference;

        using difference_type = typename base_graph::difference_type;

        using pointer		  = typename base_graph::pointer;
        using const_pointer   = typename base_graph::const_pointer;

        constexpr graph() : base{} {}

        constexpr graph(const _BaseGraph& _Base) : base{ _Base } {}

        constexpr graph(_BaseGraph&& _Base) : base{ std::move(_Base) } {}

        constexpr graph(std::initializer_list<_ElementType> _InitializerList) noexcept :
            base{ _InitializerList } {}

        constexpr void insert_edge(size_type _First, size_type _Second) noexcept {
            base.insert_edge(_First, _Second);
        }

        constexpr void insert_edge(edge<size_type> _Edge) noexcept {
            base.insert_edge(_Edge);
        }

        constexpr size_type insert_vertex(const value_type& _Value) noexcept {
            return base.insert_vertex(_Value);
        }

        constexpr size_type insert_vertex(value_type&& _Value) noexcept {
            return base.insert_vertex(std::move(_Value));
        }

        constexpr std::vector<size_type> adjacent_vertexes(size_t _Index) const noexcept {
            return base.adjacent_vertexes(_Index);
        }

        constexpr size_type degree(size_type _Index) const noexcept {
            return base.degree(_Index);
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

        constexpr const value_type& operator [](size_type _Index) const noexcept {
            return base[_Index];
        }

        constexpr value_type& operator [](size_type _Index) noexcept {
            return base[_Index];
        }

        constexpr std::vector<size_type> dfs(size_type _Source) const noexcept {
            const size_type		   vertexesSize = vertexes_size();
            bool*				   marked		= new bool[vertexesSize]{};
            std::vector<size_type> result;

            [&result, marked, this](this const auto& self, size_type _S) constexpr -> void {
                result.push_back(_S);
                marked[_S] = true;

                for (size_type i : adjacent_vertexes(_S)) {
                    if (!marked[i]) {
                        self(i);
                    }
                }
            }(_Source);

            delete[] marked;

            return result;
        }

        constexpr void dfs(size_type _Source, std::function<void(value_type&)> _Predicate) noexcept {
            const size_type		   vertexesSize = vertexes_size();
            bool*				   marked		= new bool[vertexesSize] {};

            [marked, this, _Predicate](this const auto& self, size_type _S) constexpr -> void {
                _Predicate((*this)[_S]);
                marked[_S] = true;

                for (size_type i : adjacent_vertexes(_S)) {
                    if (!marked[i]) {
                        self(i);
                    }
                }
            }(_Source);

            delete[] marked;
        }

        constexpr void dfs(size_type _Source, std::function<void(value_type&)> _Predicate) const noexcept {
            const size_type		   vertexesSize = vertexes_size();
            bool*				   marked		= new bool[vertexesSize] {};

            [marked, this, _Predicate](this const auto& self, size_type _S) constexpr -> void {
                _Predicate((*this)[_S]);
                marked[_S] = true;

                for (size_type i : adjacent_vertexes(_S)) {
                    if (!marked[i]) {
                        self(i);
                    }
                }
            }(_Source);

            delete[] marked;
        }

        constexpr std::vector<size_type> bfs(size_type _Source) const noexcept {
            const size_type		   vertexesSize = vertexes_size();
            bool*				   marked		= new bool[vertexesSize]{};
            std::vector<size_type> result;
            queue<size_type>	   next;
            next.push(_Source);
            
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

        constexpr void bfs(size_type _Source, std::function<void(value_type&)> _Predicate) noexcept {
            const size_type		   vertexesSize = vertexes_size();
            bool*				   marked		= new bool[vertexesSize] {};
            queue<size_type>	   next;
            next.push(_Source);

            while (!next.empty()) {
                const size_type s = next.front();

                next.pop();
                marked[s] = true;
                _Predicate((*this)[s]);

                for (size_type i : adjacent_vertexes(s)) {
                    if (!marked[i]) {
                        next.push(i);
                    }
                }
            }

            delete[] marked;
        }

        constexpr void bfs(size_type _Source, std::function<void(value_type&)> _Predicate) const noexcept {
            const size_type		   vertexesSize = vertexes_size();
            bool*				   marked		= new bool[vertexesSize] {};
            queue<size_type>	   next;
            next.push(_Source);

            while (!next.empty()) {
                const size_type s = next.front();

                next.pop();
                marked[s] = true;
                _Predicate((*this)[s]);

                for (size_type i : adjacent_vertexes(s)) {
                    if (!marked[i]) {
                        next.push(i);
                    }
                }
            }

            delete[] marked;
        }

        base_key_binary_tree<_ElementType> minimum_spanning_tree(size_type _Source) const noexcept {
             
        }
        
    private:
        base_graph base;
    };
}
