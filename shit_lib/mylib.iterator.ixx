export module mylib.iterator;

import std.core;


export namespace mylib {
    
    /*/ 
    /*  mylib's iterator tag can compatible with standard library
    /*  mylib's iterator tag inheriting all base class standard iterator tag types to prevent ambiguous base classes
    /*  Because ambiguous base classes will cause concept 'derive_from' to fail.
    /*/
    struct input_iterator_tag :
        std::input_iterator_tag
    {};

    struct output_iterator_tag :
        std::output_iterator_tag
    {};

    struct forward_iterator_tag : 
        input_iterator_tag, std::input_iterator_tag, 
        std::forward_iterator_tag
    {};

    struct bidirectional_iterator_tag : 
        forward_iterator_tag,      std::input_iterator_tag, 
        std::forward_iterator_tag, std::bidirectional_iterator_tag
    {};

    struct random_access_iterator_tag : 
        bidirectional_iterator_tag, std::input_iterator_tag, 
        std::forward_iterator_tag,  std::bidirectional_iterator_tag, 
        std::random_access_iterator_tag
    {};

    struct contiguous_iterator_tag :
        random_access_iterator_tag,      std::input_iterator_tag,
        std::forward_iterator_tag,       std::bidirectional_iterator_tag,
        std::random_access_iterator_tag, std::contiguous_iterator_tag 
    {};

    
}