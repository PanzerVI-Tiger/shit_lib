module;

#ifdef __INTELLISENSE__

#include <set>;
#include <map>;
#include <tuple>;
#include <ranges>;
#include <variant>;
#include <utility>;
#include <optional>;
#include <iostream>;

#endif

export module mylib.stream_output;

#ifndef __INTELLISENSE__

import std.core;

#endif

export namespace mylib {
    
    template<std::ranges::range Container>
        requires
          (!requires(const Container& c) { // not a string
              c.substr();
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

    std::ostream& operator <<(std::ostream& os, std::monostate) noexcept {
        return os << "std::monostate";
    }

    template<typename First, typename Second>
    std::ostream& operator <<(
        std::ostream& os, const std::pair<First, Second>& pairObject
    ) noexcept {

        os << '(' << pairObject.first << ', ' << pairObject.second << ')';
        return os;
    }
    
    template<typename... Types>
    std::ostream& operator <<(
        std::ostream& os, const std::tuple<Types...>& tupleObject
    ) noexcept {

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
    std::ostream& operator <<(
        std::ostream& os, const std::set<KeyType, Compare, Allocator>& setObject
    ) noexcept {

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

 /*   template<typename... Types>
    std::ostream& operator <<(
        std::ostream& os, const std::variant<Types...>& variantObject
    ) noexcept {

        os << "{ ";
        std::visit(
            [&os]<typename Type>(const Type& arg) noexcept {
                os << "Type: " << typeid(Type).name() << ", value: " << arg;
            }, 
            variantObject
        );
        os << " }";
        
        return os;
    }*/

    template<typename Type>
    std::ostream& operator <<(
        std::ostream& os, const std::optional<Type>& optionalObject
    ) noexcept {

        if (optionalObject) {
            os << "{ Type: " << typeid(Type).name() << ", value: " << *optionalObject << " }";
        } else {
            os << "{ Type: std::nullopt_t, value: std::nullopt }";
        }
        
        return os;
    }
}
