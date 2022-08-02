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
    std::string to_string(const Type& value) {
        return std::to_string(value);
    }

    // not standard
    std::string to_string(const std::string& value) {
        return value;
    }

    // not standard
    std::string to_string(const char* value) {
        return value;
    }

    // not standard
    std::string to_string(const char value) {
        return { value };
    }

    // not standard
    template<std::ranges::range Range>
    std::string to_string(const Range& value) {
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
    template<typename Type>
    std::string to_string(const std::optional<Type>& value) {
        if (value) {
            return to_string(*value);
        } else {
            return "null";
        }
    }

    // not standard
    template<typename... Type>
    std::string to_string(const std::tuple<Type...>& value) {
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
    std::string to_string(const std::set<KeyType>& value) {
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
    std::string to_string(const std::map<KeyType, MappedType>& value) {
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
}
