#pragma once

#include "if.h"
#include "bool.h"
#include "macro_base.h"

// not equal
#define mylib_pp_not_equal_impl(left, right)                        \
    mylib_pp_cat_n(                                                 \
        2,                                                          \
        mylib_pp_check_,                                             \
        mylib_pp_not_equal ## left(1, mylib_pp_not_equal ## right))
#define mylib_pp_not_equal(left, right) \
    mylib_pp_not_equal_impl(left, right)

#define mylib_pp_equal(left, right) mylib_pp_logical_not(mylib_pp_not_equal(left, right))

#define mylib_pp_check_mylib_pp_nil                        1

#define mylib_pp_check_mylib_pp_not_equal0(isLeft, right)  0
#define mylib_pp_check_mylib_pp_not_equal1(isLeft, right)  0
#define mylib_pp_check_mylib_pp_not_equal2(isLeft, right)  0
#define mylib_pp_check_mylib_pp_not_equal3(isLeft, right)  0
#define mylib_pp_check_mylib_pp_not_equal4(isLeft, right)  0
#define mylib_pp_check_mylib_pp_not_equal5(isLeft, right)  0
#define mylib_pp_check_mylib_pp_not_equal6(isLeft, right)  0
#define mylib_pp_check_mylib_pp_not_equal7(isLeft, right)  0
#define mylib_pp_check_mylib_pp_not_equal8(isLeft, right)  0
#define mylib_pp_check_mylib_pp_not_equal9(isLeft, right)  0
#define mylib_pp_check_mylib_pp_not_equal10(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal11(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal12(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal13(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal14(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal15(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal16(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal17(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal18(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal19(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal20(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal21(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal22(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal23(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal24(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal25(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal26(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal27(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal28(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal29(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal30(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal31(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal32(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal33(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal34(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal35(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal36(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal37(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal38(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal39(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal40(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal41(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal42(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal43(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal44(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal45(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal46(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal47(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal48(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal49(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal50(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal51(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal52(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal53(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal54(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal55(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal56(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal57(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal58(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal59(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal60(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal61(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal62(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal63(isLeft, right) 0
#define mylib_pp_check_mylib_pp_not_equal64(isLeft, right) 0

#define mylib_pp_not_equal0(isLeft, arg)  mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal1(isLeft, arg)  mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal2(isLeft, arg)  mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal3(isLeft, arg)  mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal4(isLeft, arg)  mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal5(isLeft, arg)  mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal6(isLeft, arg)  mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal7(isLeft, arg)  mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal8(isLeft, arg)  mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal9(isLeft, arg)  mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal10(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal11(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal12(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal13(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal14(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal15(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal16(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal17(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal18(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal19(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal20(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal21(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal22(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal23(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal24(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal25(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal26(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal27(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal28(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal29(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal30(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal31(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal32(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal33(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal34(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal35(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal36(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal37(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal38(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal39(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal40(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal41(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal42(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal43(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal44(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal45(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal46(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal47(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal48(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal49(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal50(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal51(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal52(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal53(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal54(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal55(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal56(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal57(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal58(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal59(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal60(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal61(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal62(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal63(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
#define mylib_pp_not_equal64(isLeft, arg) mylib_pp_if(isLeft) (arg(0, arg)) (mylib_pp_nil)
