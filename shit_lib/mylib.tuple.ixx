export module mylib.tuple;

import std.core;
import mylib.type_traits;


export namespace mylib {
    
    template<typename Type = void, typename... Types>
    struct tuple {
        template<typename Argument, typename... Arguments>
        tuple(Argument&& argument, Arguments&&... arguments) noexcept {}
        
        Type            current;
        tuple<Types...> next;
    };

    template<typename Type>
    struct tuple<Type> {
        Type current;
    };
    
    template<>
    struct tuple<void> {};
}
