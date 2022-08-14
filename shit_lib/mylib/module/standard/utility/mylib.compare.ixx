export module mylib.compare;


export namespace mylib {
    
    struct strong_ordering {

        
        static const strong_ordering less;
        static const strong_ordering equivalent;
        static const strong_ordering equal;
        static const strong_ordering greater;

        signed char value;
    };

    inline constexpr strong_ordering strong_ordering::less      { -1 };
    inline constexpr strong_ordering strong_ordering::equivalent{  0 };
    inline constexpr strong_ordering strong_ordering::equal     {  0 };
    inline constexpr strong_ordering strong_ordering::greater   {  1 };
}
