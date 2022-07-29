export module mylib.stream_output;

import std.core;


export namespace mylib {
    
    template<std::ranges::range Container>
        requires
          (!requires(const Container& c) { // not a string
              c.c_str();
          })							   &&
          (!requires(const Container& c) { // and not a c style string
              printf(c);
          })						       &&
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
    std::ostream& operator <<(std::ostream& os, const std::pair<First, Second>& _Pair) noexcept {
        os << '(' << _Pair.first << ', ' << _Pair.second << ')';
        return os;
    }
    
    template<typename... Types>
    std::ostream& operator <<(std::ostream& os, const std::tuple<Types...>& _Tuple) noexcept {
        os << '(';
        std::apply(
            [](const auto&... _Args) {
                bool isStart = true;
                ((std::cout << (isStart ? "" : ", ") << _Args, isStart = false), ...);
            }, 
            _Tuple
        );
        os << ')';
        
        return os;
    }

    template<typename KeyType, typename Compare, typename Allocator>
    std::ostream& operator <<(std::ostream& os, const std::set<KeyType, Compare, Allocator>& set) noexcept {
        os << '{';
        bool isStart = true;
        for (const auto& i : set) {
            os << (isStart ? "" : ", ") << i;
            isStart = false;
        }
        os << '}';
        
        return os;
    }

    template<typename KeyType, typename MappedType, typename Compare, typename Allocator>
    std::ostream& operator <<(
        std::ostream&											 os, 
        const std::map<KeyType, MappedType, Compare, Allocator>& map
    ) noexcept {
        
        os << '{';
        bool isStart = true;
        for (const auto& i : map) {
            os << (isStart ? "" : ", ") << i.first << ": " << i.second;
            isStart = false;
        }
        os << '}';
        
        return os;
    }
}
