module;

#ifdef __INTELLISENSE__

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
        constexpr abortor(bool _isAbort = false) :
            isAbort(_isAbort)
        {}

        constexpr abortor(abortor&& other) :
            isAbort(other.isAbort)
        {
            other.isAbort = false;
        }

        constexpr abortor(const abortor&) = delete;

        constexpr ~abortor() noexcept {
            if (!std::is_constant_evaluated()) {
                if (isAbort) {
                    abort();
                }
            }
        }
    
        [[noreturn]]
        constexpr static void abort() noexcept
        {}
        
        bool isAbort;
    };
    
#   if !defined(__INTELLISENSE__) && defined(MYLIB_ASSERT)

    mylib::abortor (assert)(
        bool                 expression,
        const char*          description           = "",
        std::source_location loactionInformation   = std::source_location::current(),
        std::stacktrace      stacktraceInformation = std::stacktrace::current()
    ) noexcept {
        
        if (!expression) {
            std::cerr
                << "Assertion failed: " << description                         << "\n"
                << "  at file:  "       << loactionInformation.file_name()     << "\n"
                << "  line:     "       << loactionInformation.line()          << "\n"
                << "  column:   "       << loactionInformation.column()        << "\n"
                << "  function: "       << loactionInformation.function_name() << "\n\n"
                << "stacktrace:\n"
                << stacktraceInformation;

            return { true };
        } else {
            return { false };
        }
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
