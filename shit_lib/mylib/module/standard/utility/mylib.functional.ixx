export module mylib.functional;


export namespace mylib {
    
    template<typename FunctionType>
    class function {
        
    };
    
    template<typename Type = void>
    struct plus {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left + right;
        }
    };

    template<>
    struct plus<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left + right;
        }
    };

    template<typename Type = void>
    struct minus {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left - right;
        }
    };

    template<>
    struct minus<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left - right;
        }
    };

    template<typename Type = void>
    struct multiplies {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left * right;
        }
    };

    template<>
    struct multiplies<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left * right;
        }
    };

    template<typename Type = void>
    struct divides {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left / right;
        }
    };

    template<>
    struct divides<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left / right;
        }
    };

    template<typename Type = void>
    struct modulus {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left % right;
        }
    };
    
    template<>
    struct modulus<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left % right;
        }
    };

    template<typename Type = void>
    struct negate {
        Type operator()(const Type& left) const noexcept {
            return -left;
        }
    };

    template<>
    struct negate<void> {
        template<typename Type>
        Type operator()(const Type& left) const noexcept {
            return -left;
        }
    };

    template<typename Type = void>
    struct equal_to {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left == right;
        }
    };

    template<>
    struct equal_to<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left == right;
        }
    };

    template<typename Type = void>
    struct not_equal_to {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left != right;
        }
    };

    template<>
    struct not_equal_to<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left != right;
        }
    };

    template<typename Type = void>
    struct greater {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left > right;
        }
    };

    template<>
    struct greater<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left > right;
        }
    };

    template<typename Type = void>
    struct less {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left < right;
        }
    };

    template<>
    struct less<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left < right;
        }
    };
    
    template<typename Type = void>
    struct greater_equal {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left >= right;
        }
    };

    template<>
    struct greater_equal<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left >= right;
        }
    };

    template<typename Type = void>
    struct less_equal {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left <= right;
        }
    };

    template<>
    struct less_equal<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left <= right;
        }
    };

    template<typename Type = void>
    struct logical_and {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left && right;
        }
    };

    template<>
    struct logical_and<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left && right;
        }
    };

    template<typename Type = void>
    struct logical_or {
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left || right;
        }
    };

    template<>
    struct logical_or<void> {
        template<typename Type>
        bool operator()(const Type& left, const Type& right) const noexcept {
            return left || right;
        }
    };

    template<typename Type = void>
    struct logical_not {
        bool operator()(const Type& left) const noexcept {
            return !left;
        }
    };

    template<>
    struct logical_not<void> {
        template<typename Type>
        bool operator()(const Type& left) const noexcept {
            return !left;
        }
    };

    template<typename Type = void>
    struct bit_and {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left & right;
        }
    };

    template<>
    struct bit_and<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left & right;
        }
    };

    template<typename Type = void>
    struct bit_or {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left | right;
        }
    };

    template<>
    struct bit_or<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left | right;
        }
    };

    template<typename Type = void>
    struct bit_xor {
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left ^ right;
        }
    };

    template<>
    struct bit_xor<void> {
        template<typename Type>
        Type operator()(const Type& left, const Type& right) const noexcept {
            return left ^ right;
        }
    };

    template<typename Type = void>
    struct bit_not {
        Type operator()(const Type& left) const noexcept {
            return ~left;
        }
    };

    template<>
    struct bit_not<void> {
        template<typename Type>
        Type operator()(const Type& left) const noexcept {
            return ~left;
        }
    };
}