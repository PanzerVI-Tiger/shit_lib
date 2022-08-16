module;

#ifdef __INTELLISENSE__

#include <string>
#include <utility>
#include <iostream>
#include <stacktrace>
#include <source_location>

#endif

export module mylib.assert;

#ifndef __INTELLISENSE__

import std.core;

#endif


export namespace mylib {

#   ifdef MYLIB_ASSERT
    
    inline constexpr bool assert_enabled = true;
    
#   else
    
    inline constexpr bool assert_enabled = false;
    
#   endif
    
    struct abortor {
        [[noreturn]]
        static void abort() noexcept
        {}

        ~abortor() noexcept {
            if (isAbort) {
                abort();
            }
        }
    
        bool isAbort;
    };
    
#   if !defined(__INTELLISENSE__) && defined(MYLIB_ASSERT)

    abortor (assert)(
        bool                 expression,
        const char*          description           = "",
        std::source_location loactionInformation   = std::source_location::current(),
        std::stacktrace      stacktraceInformation = std::stacktrace::current()
    ) noexcept {
        
        if (!expression) {
            std::cerr
                << "Assertion failed: " << description << "\n"
                << "  at file:  " << loactionInformation.file_name() << "\n"
                << "  line:     " << loactionInformation.line() << "\n"
                << "  column:   " << loactionInformation.column() << "\n"
                << "  function: " << loactionInformation.function_name() << "\n\n"
                << "stacktrace:\n"
                << stacktraceInformation;

            return { true };
        } else {
            return { false };
        }
    }

#   else
    
    void (assert)(bool expression, const char* description = "") noexcept 
    {}
    
#   endif 
}
