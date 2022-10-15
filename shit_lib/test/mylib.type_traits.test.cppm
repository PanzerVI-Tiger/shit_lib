import mylib.cstddef;
import mylib.type_traits;


#ifdef MYLIB_UNITTEST

namespace mylib::unittest {

    template<typename Void = void>
    constexpr bool type_traits_assert_test() noexcept {
        // test constant
        constexpr mylib::constant<int,       114514>          constant0;
        constexpr mylib::constant<long long, 1145141919810LL> constant1;

        // test constant::value
        static_assert(constant0.value == 114514);
        static_assert(constant1.value == 1145141919810LL);

        // test constant::operator Type()
        static_assert(constant0 == 114514);
        static_assert(constant1 == 1145141919810LL);

        // test operator()
        static_assert(constant0() == 114514);
        static_assert(constant1() == 1145141919810LL);

        // test true_type and false_type
        static_assert( mylib::true_type{});
        static_assert(!mylib::false_type{});

        // test is_void_v
        static_assert( mylib::is_void_v<void>);

        // test is_null_pointer_v
        static_assert( mylib::is_null_pointer_v<mylib::nullptr_t>);

        // test is_integral_v
        static_assert( mylib::is_integral_v<char>);
        static_assert( mylib::is_integral_v<long>);
        static_assert( mylib::is_integral_v<char8_t>);
        static_assert( mylib::is_integral_v<char16_t>);
        static_assert( mylib::is_integral_v<char32_t>);
        static_assert( mylib::is_integral_v<long long>);
        static_assert( mylib::is_integral_v<volatile int>);
        static_assert( mylib::is_integral_v<unsigned int>);
        static_assert( mylib::is_integral_v<const volatile short>);
        static_assert( mylib::is_integral_v<const unsigned long long>);

        static_assert(!mylib::is_integral_v<void>);
        static_assert(!mylib::is_integral_v<char*>);
        static_assert(!mylib::is_integral_v<float>);
        static_assert(!mylib::is_integral_v<double>);
        static_assert(!mylib::is_integral_v<nullptr_t>);
        static_assert(!mylib::is_integral_v<long double>);

        // test is_floating_point_v
        static_assert( mylib::is_floating_point_v<float>);
        static_assert( mylib::is_floating_point_v<double>);
        static_assert( mylib::is_floating_point_v<long double>);
        static_assert( mylib::is_floating_point_v<const float>);
        static_assert( mylib::is_floating_point_v<volatile double>);
        static_assert( mylib::is_floating_point_v<const volatile long double>);

        static_assert(!mylib::is_floating_point_v<int>);
        static_assert(!mylib::is_floating_point_v<char>);
        static_assert(!mylib::is_floating_point_v<void>);
        static_assert(!mylib::is_floating_point_v<char*>);
        static_assert(!mylib::is_floating_point_v<long long>);
        static_assert(!mylib::is_floating_point_v<mylib::nullptr_t>);
        static_assert(!mylib::is_floating_point_v<unsigned int>);
        static_assert(!mylib::is_floating_point_v<unsigned long long>);

        // test is_array_v
        static_assert( mylib::is_array_v<char[3]>);
        static_assert( mylib::is_array_v<long long[]>);
        static_assert( mylib::is_array_v<const int[3]>);
        static_assert( mylib::is_array_v<volatile double[3]>);
        static_assert( mylib::is_array_v<const volatile long long[3]>);

        static_assert(!mylib::is_array_v<int>);
        static_assert(!mylib::is_array_v<void>);
        static_assert(!mylib::is_array_v<char*>);
        static_assert(!mylib::is_array_v<nullptr_t>);
        static_assert(!mylib::is_array_v<long long>);

        // test is_pointer_v
        static_assert( mylib::is_pointer_v<int*>);
        static_assert( mylib::is_pointer_v<const int*>);
        static_assert( mylib::is_pointer_v<long long*>);

        static_assert(!mylib::is_pointer_v<int>);
        static_assert(!mylib::is_pointer_v<void>);
        static_assert(!mylib::is_pointer_v<long long>);
        static_assert(!mylib::is_pointer_v<nullptr_t>);

        enum Enum1 {};

        enum Enum2 : long long {};

        enum class EnumClass1 {};

        enum class EnumClass2 : unsigned long long {};

        // test is_enum

        static_assert( mylib::is_enum_v<Enum1>);
        static_assert( mylib::is_enum_v<Enum2>);
        static_assert( mylib::is_enum_v<EnumClass2>);
        static_assert( mylib::is_enum_v<EnumClass1>);
        static_assert( mylib::is_enum_v<const Enum2>);
        static_assert( mylib::is_enum_v<const EnumClass1>);

        static_assert(!mylib::is_enum_v<int>);
        static_assert(!mylib::is_enum_v<void>);
        static_assert(!mylib::is_enum_v<char*>);
        static_assert(!mylib::is_enum_v<nullptr_t>);
        static_assert(!mylib::is_enum_v<long long>);

        // test is_union
        union Union1 {};

        union Union2 {
            int       i;
            long long ll;
        };

        struct Struct1 {};

        struct Struct2 {
            long long ll;
            double    d;
        };

        struct Struct3 :
            Struct1
        {};

        return true;
    }

    static_assert(mylib::unittest::type_traits_assert_test(), "type_traits have bug!");
}

#endif
