export module mylib.compare;


export namespace mylib {
    
    struct strong_ordering {

        
        static const strong_ordering less;
        static const strong_ordering equivalent;
        static const strong_ordering equal;
        static const strong_ordering greater;

        signed char value;
    };

    inline constexpr mylib::strong_ordering mylib::strong_ordering::less      { -1 };
    inline constexpr mylib::strong_ordering mylib::strong_ordering::equivalent{  0 };
    inline constexpr mylib::strong_ordering mylib::strong_ordering::equal     {  0 };
    inline constexpr mylib::strong_ordering mylib::strong_ordering::greater   {  1 };
}
