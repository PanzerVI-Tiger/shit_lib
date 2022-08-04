export module mylib.string;

import std.core;


export namespace mylib {

    template<typename CharType, typename CharTraits, typename Allocator>
    class base_string {
        
    };

    // not standard
    // default use std::to_string
    template<typename Type>
        requires std::is_arithmetic_v<Type>
    constexpr std::string to_string(const Type& value) {
        return std::to_string(value);
    }

    // not standard
    constexpr std::string to_string(const std::string& value) {
        return value;
    }

    // not standard
    constexpr std::string to_string(const char* value) {
        return value;
    }

    // not standard
    constexpr std::string to_string(const char value) {
        return { value };
    }

    // not standard
    template<std::ranges::range Range>
    constexpr std::string to_string(const Range& value) {
        std::string result{ "[" };
        
        for (bool isStart = true; const auto & i : value) {
            if (isStart) {
                isStart = false;
            } else {
                result += ", ";
            }
            result += to_string(i);
        }

        result += "]";

        return result;
    }


    // not standard
    template<typename... Type>
    constexpr std::string to_string(const std::tuple<Type...>& value) {
        using namespace std::literals;

        std::string result{ "(" };
        
        std::apply(
            [&result](const auto&... args) {
                bool isStart = true;
                ((result += (isStart ? isStart = false, ""s : ", "s) + to_string(args)), ...);
            },
            value
        );
        
        result += ")";
        
        return result;
    }

    // not standard
    template<typename KeyType>
    constexpr std::string to_string(const std::set<KeyType>& value) {
        std::string result{ "{" };
        
        for (bool isStart = true; const auto & i : value) {
            if (isStart) {
                isStart = false;
            } else {
                result += ", ";
            }
            result += to_string(i);
        }
        result += "}";
        
        return result;
    }

    // not standard
    template<typename KeyType, typename MappedType>
    constexpr std::string to_string(const std::map<KeyType, MappedType>& value) {
        std::string result{ "{" };
        
        for (bool isStart = true; const auto & i : value) {
            if (isStart) {
                isStart = false;
            } else {
                result += ", ";
            }
            result += to_string(i.first) + ": " + to_string(i.second);
        }
        result += "}";
        
        return result;
    }

    // not standard
    template<typename... Types>
    constexpr std::string to_string(const std::variant<Types...>& value) {
        using namespace std::string_literals;
        
        std::string result{ "{ " };
        
        std::visit(
            [&result]<typename Type>(const Type& arg) {
                result += "Type: "s + typeid(Type).name() + ", value: " + to_string(arg);
            },
            value
        );
        
        result += " }";
        
        return result;
    }

    // not standard
    template<typename Type>
    constexpr std::string to_string(const std::optional<Type>& value) {
        using namespace std::string_literals;
        
        if (value) {
            return "{ Type: "s + typeid(Type).name() + ", value: " + to_string(*value) + " }";
        } else {
            return "{ Type: nullopt_t, value: nullopt }";
        }
    }
}
