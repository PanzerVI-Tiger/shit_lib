export module mylib.eval;

import mylib.binary_tree;
import std.core;


export namespace mylib {

    struct operator_pair {
        operator_pair(std::string_view _Operators) noexcept {

        }

        bool operator <(operator_pair& _Right) const noexcept {
            return priority < _Right.priority;
        }

        unsigned char index;
        unsigned char priority;
    };

    struct calculate_object {

        enum class object_type {
            number,
            operators,
            left,
            leftBracket,
            rightBracket
        };

        union {
            operator_pair operators;
            double		  number;
        } data;
        object_type type;
    };

    double eval(std::string_view _Expression) {
        using namespace std::literals;

        base_key_binary_tree<calculate_object> calculateTree;
        using node_pointer = decltype(calculateTree)::node_pointer;

        node_pointer current{ calculateTree.root() };


    }
}