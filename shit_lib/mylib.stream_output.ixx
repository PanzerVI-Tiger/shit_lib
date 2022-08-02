export module mylib.stream_output;

import std.core;


export namespace mylib {
    
    template<std::ranges::range Container>
        requires
          (!requires(const Container& c) { // not a string
              c.c_str();
          })                               &&
          (!requires(const Container& c) { // and not a c style string
              printf(c);
          })                               &&
          (!requires(const Container& c) { // ^^ same as above
              wprintf(c);
          })
    std::ostream& operator <<(std::ostream& os, const Container& container) noexcept {
        bool isStart = true;
        os << '[';
        for (const auto& i : container) {
            os << (isStart ? "" : ", ") << i;
            isStart = false;
        }
        os << ']';
        
        return os;
    }

    template<typename First, typename Second>
    std::ostream& operator <<(std::ostream& os, const std::pair<First, Second>& pairObject) noexcept {
        os << '(' << pairObject.first << ', ' << pairObject.second << ')';
        return os;
    }
    
    template<typename... Types>
    std::ostream& operator <<(std::ostream& os, const std::tuple<Types...>& tupleObject) noexcept {
        os << '(';
        std::apply(
            [](const auto&... args) {
                bool isStart = true;
                ((std::cout << (isStart ? "" : ", ") << args, isStart = false), ...);
            }, 
            tupleObject
        );
        os << ')';
        
        return os;
    }

    template<typename KeyType, typename Compare, typename Allocator>
    std::ostream& operator <<(std::ostream& os, const std::set<KeyType, Compare, Allocator>& setObject) noexcept {
        os << '{';
        bool isStart = true;
        for (const auto& i : setObject) {
            os << (isStart ? "" : ", ") << i;
            isStart = false;
        }
        os << '}';
        
        return os;
    }

    template<typename KeyType, typename MappedType, typename Compare, typename Allocator>
    std::ostream& operator <<(
        std::ostream&                                            os, 
        const std::map<KeyType, MappedType, Compare, Allocator>& mapObject
    ) noexcept {
        
        os << '{';
        bool isStart = true;
        for (const auto& i : mapObject) {
            os << (isStart ? "" : ", ") << i.first << ": " << i.second;
            isStart = false;
        }
        os << '}';
        
        return os;
    }
}
