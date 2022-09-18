module;

#ifdef __INTELLISENSE__

#include <concepts>
#include <iostream>
#include <stacktrace>
#include <source_location>
#endif

export module mylib.assert;

#ifndef __INTELLISENSE__

import std.core;

#endif

import mylib.type_traits;


export namespace mylib {

#   ifdef MYLIB_ASSERT
    
    inline constexpr bool assert_enabled = true;
    
#   else
    
    inline constexpr bool assert_enabled = false;
    
#   endif
    
    struct abortor {
        constexpr abortor(bool isAbort = false) :
            is_abort(isAbort)
        {}

        constexpr abortor(abortor&& other) :
            is_abort(other.is_abort)
        {
            other.is_abort = false;
        }

        constexpr abortor(const abortor&) = delete;

        constexpr ~abortor() noexcept {
            if (is_abort) {
                abort();
            }
        }
        
        // evaluation at compile time has no effect in generally
        [[noreturn]]
        constexpr static void abort() noexcept
        {}
        
        bool is_abort;
    };
    
#   if !defined(__INTELLISENSE__) && defined(MYLIB_ASSERT)

    mylib::abortor (assert)(
        bool                 expression,
        const char*          description    = "",
        std::source_location loactionInfo   = std::source_location::current(),
        std::stacktrace      stacktraceInfo = std::stacktrace::current()
    ) noexcept {
        
        if (!expression) {
            std::cerr
                << "Assertion failed: " << description                  << "\n"
                << "  at file:  "       << loactionInfo.file_name()     << "\n"
                << "  line:     "       << loactionInfo.line()          << "\n"
                << "  column:   "       << loactionInfo.column()        << "\n"
                << "  function: "       << loactionInfo.function_name() << "\n\n"
                << "stacktrace:\n"
                << stacktraceInfo;

            return { true };
        }
        
        return { false };
    }

#   else
        
    mylib::abortor (assert)(
        bool                 expression,
        const char*          description         = "",
        std::source_location sourceLoacationInfo = {},
        std::stacktrace      stacktraceInfo      = {}
    ) noexcept 
    {}
    
#   endif 
}
