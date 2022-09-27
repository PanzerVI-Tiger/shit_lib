#ifdef __INTELLISENSE__

#include <iostream>
#include <stacktrace>
#include <source_location>

#endif

export module mylib.iterator_check;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.assert;
import mylib.container_traits;


export namespace mylib {

#   if !defined(__INTELLISENSE__) && defined(MYLIB_ASSERT)

    template<typename Iterator>
    mylib::abortor check_iterator_valid(
        Iterator             iter,
        std::source_location loactionInfo   = std::source_location::current(),
        std::stacktrace      stacktraceInfo =      std::stacktrace::current()
    ) noexcept {
        return (mylib::assert)(true, "iterator is invalid!!!", loactionInfo, stacktraceInfo);
    }

    template<typename Type>
    mylib::abortor check_iterator_valid(
        Type* iter,
        std::source_location loactionInfo   = std::source_location::current(),
        std::stacktrace      stacktraceInfo =      std::stacktrace::current()
    ) noexcept {
        return (mylib::assert)(iter != nullptr, "pointer is null!!!", loactionInfo, stacktraceInfo);
    }

#   else
    
    template<typename Iterator>
    mylib::abortor check_iterator_valid(
        Iterator             iter,
        std::source_location loactionInfo   = {},
        std::stacktrace      stacktraceInfo = {}
    ) noexcept 
    {}

    template<typename Type>
    mylib::abortor check_iterator_valid(
        Type* iter,
        std::source_location loactionInfo   = {},
        std::stacktrace      stacktraceInfo = {}
    ) noexcept 
    {}

#   endif
}
