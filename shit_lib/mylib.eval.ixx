export module mylib.eval;

import mylib.binary_tree;
import mylib.type_traits;
import std.core;


export namespace mylib {

    struct scheme_tag 
    {};

    constexpr auto eval_scheme(const std::string& expression) noexcept {
        
    }
    
    template<typename LanguageTag = scheme_tag>
    constexpr auto eval(const std::string& expression) noexcept {
        if constexpr (is_same_v<LanguageTag, scheme_tag>) {
            return eval_scheme(expression);
        }
    }
}
