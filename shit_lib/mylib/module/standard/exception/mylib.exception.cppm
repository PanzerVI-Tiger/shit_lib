export module mylib.exception;


export namespace mylib {

#   ifdef MYLIB_EXCEPTION

    inline constexpr bool exception_enable = true

#   else
    
    inline constexpr bool exception_enable = false;

#   endif
}
