module;

//#pragma optimize("", off)
#include <Windows.h>
#include <stdio.h>
#include "mylib_assert.h"
//#include <execution>

export module mylib.main;

import std.core;
import mylib;
//
//
//
//using mylib::operator <<;
//using namespace std::literals;
//
//struct my_promise;
//
//struct my_coroutine : std::coroutine_handle<my_promise> {
//	using promise_type = my_promise;
//};
//
//struct my_promise {	
//	my_coroutine get_return_object() {
//		return { my_coroutine::from_promise(*this) };
//	}
//
//	std::suspend_always initial_suspend() noexcept {
//		return {};
//	}
//
//	std::suspend_never final_suspend() noexcept {
//		return {};
//	}
//
//	void return_value(int i) noexcept {
//		result = i;
//	}
//	
//	void unhandled_exception() noexcept {}
//
//	int result;
//};
//
//my_coroutine f(double x)
//{
//	return {};
//}


export int main() noexcept
{
    
    
	return 0;
}
