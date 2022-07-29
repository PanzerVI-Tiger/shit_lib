export module mylib.functional;


export namespace mylib::inline functional {
    
    template<typename _FunctionType>
    class function {
        
    };
    
    template<typename _Type = void>
    struct plus {
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left + _Right;
        }
    };

    template<>
    struct plus<void> {
        template<typename _Type>
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left + _Right;
        }
    };

    template<typename _Type = void>
    struct minus {
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left - _Right;
        }
    };

    template<>
    struct minus<void> {
        template<typename _Type>
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left - _Right;
        }
    };

    template<typename _Type = void>
    struct multiplies {
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left * _Right;
        }
    };

    template<>
    struct multiplies<void> {
        template<typename _Type>
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left * _Right;
        }
    };

    template<typename _Type = void>
    struct divides {
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left / _Right;
        }
    };

    template<>
    struct divides<void> {
        template<typename _Type>
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left / _Right;
        }
    };

    template<typename _Type = void>
    struct modulus {
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left % _Right;
        }
    };
    
    template<>
    struct modulus<void> {
        template<typename _Type>
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left % _Right;
        }
    };

    template<typename _Type = void>
    struct negate {
        _Type operator()(const _Type& _Left) const noexcept {
            return -_Left;
        }
    };

    template<>
    struct negate<void> {
        template<typename _Type>
        _Type operator()(const _Type& _Left) const noexcept {
            return -_Left;
        }
    };

    template<typename _Type = void>
    struct equal_to {
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left == _Right;
        }
    };

    template<>
    struct equal_to<void> {
        template<typename _Type>
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left == _Right;
        }
    };

    template<typename _Type = void>
    struct not_equal_to {
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left != _Right;
        }
    };

    template<>
    struct not_equal_to<void> {
        template<typename _Type>
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left != _Right;
        }
    };

    template<typename _Type = void>
    struct greater {
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left > _Right;
        }
    };

    template<>
    struct greater<void> {
        template<typename _Type>
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left > _Right;
        }
    };

    template<typename _Type = void>
    struct less {
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left < _Right;
        }
    };

    template<>
    struct less<void> {
        template<typename _Type>
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left < _Right;
        }
    };
    
    template<typename _Type = void>
    struct greater_equal {
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left >= _Right;
        }
    };

    template<>
    struct greater_equal<void> {
        template<typename _Type>
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left >= _Right;
        }
    };

    template<typename _Type = void>
    struct less_equal {
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left <= _Right;
        }
    };

    template<>
    struct less_equal<void> {
        template<typename _Type>
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left <= _Right;
        }
    };

    template<typename _Type = void>
    struct logical_and {
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left && _Right;
        }
    };

    template<>
    struct logical_and<void> {
        template<typename _Type>
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left && _Right;
        }
    };

    template<typename _Type = void>
    struct logical_or {
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left || _Right;
        }
    };

    template<>
    struct logical_or<void> {
        template<typename _Type>
        bool operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left || _Right;
        }
    };

    template<typename _Type = void>
    struct logical_not {
        bool operator()(const _Type& _Left) const noexcept {
            return !_Left;
        }
    };

    template<>
    struct logical_not<void> {
        template<typename _Type>
        bool operator()(const _Type& _Left) const noexcept {
            return !_Left;
        }
    };

    template<typename _Type = void>
    struct bit_and {
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left & _Right;
        }
    };

    template<>
    struct bit_and<void> {
        template<typename _Type>
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left & _Right;
        }
    };

    template<typename _Type = void>
    struct bit_or {
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left | _Right;
        }
    };

    template<>
    struct bit_or<void> {
        template<typename _Type>
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left | _Right;
        }
    };

    template<typename _Type = void>
    struct bit_xor {
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left ^ _Right;
        }
    };

    template<>
    struct bit_xor<void> {
        template<typename _Type>
        _Type operator()(const _Type& _Left, const _Type& _Right) const noexcept {
            return _Left ^ _Right;
        }
    };

    template<typename _Type = void>
    struct bit_not {
        _Type operator()(const _Type& _Left) const noexcept {
            return ~_Left;
        }
    };

    template<>
    struct bit_not<void> {
        template<typename _Type>
        _Type operator()(const _Type& _Left) const noexcept {
            return ~_Left;
        }
    };
}