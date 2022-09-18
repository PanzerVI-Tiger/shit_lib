module;

#ifdef __INTELLISENSE__

#include <string>
#include <optional>

#endif

export module mylib.eval;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.stack;
import mylib.binary_tree;
import mylib.type_traits;


export namespace mylib {

    struct scheme_tag 
    {};

    struct c_tag
    {};

    inline constexpr scheme_tag scheme_lang{};

    inline constexpr c_tag c_lang{};

    constexpr std::optional<long double> eval_scheme(
        const std::string& expression
    ) noexcept {
        
        //mylib::stack<long double> valueStack{};
        
        return {};
    }
    
    template<typename LanguageTag>
    constexpr auto eval(LanguageTag, const std::string& expression) noexcept {
        if constexpr (mylib::is_same_v<LanguageTag, mylib::scheme_tag>) {
            return eval_scheme(expression);
        }
    }

    constexpr auto eval(const std::string& expression) noexcept {
        return eval(mylib::scheme_lang, expression);
    }
}
