#pragma once

#ifdef __INTELLISENSE__

// concept
#include <concepts>;

// coroutine
#include <coroutine>;

// utility
#include <cstdlib>;
#include <csignal>;
#include <csetjmp>;
#include <cstdarg>;
#include <typeinfo>;
#include <typeindex>;
#include <type_traits>;
#include <bitset>;
#include <functional>;
#include <utility>;
#include <ctime>;
#include <chrono>;
#include <cstddef>;
#include <initializer_list>;
#include <tuple>;
#include <any>;
#include <optional>;
#include <variant>;
#include <compare>;
#include <version>;
#include <source_location>;
#include <stacktrace>;

// memory
#include <new>;
#include <memory>;
#include <scoped_allocator>;
#include <memory_resource>;

// limits
#include <cfloat>;
#include <cinttypes>;
#include <climits>;
#include <cstdint>;
#include <limits>;

// error handling
#include <exception>;
#include <stdexcept>;
#include <cassert>;
#include <system_error>;
#include <cerrno>;

// string
#include <cctype>;
#include <cwctype>;
#include <cstring>;
#include <cwchar>;
#include <cuchar>;
#include <string>;
#include <string_view>;
#include <charconv>;
#include <format>;


// conatiner
#include <array>;
#include <vector>;
#include <deque>;
#include <list>;
#include <forward_list>;
#include <set>;
#include <map>;
#include <unordered_set>;
#include <unordered_map>;
#include <stack>;
#include <queue>;
#include <span>;

// iterator
#include <iterator>;

// range
#include <ranges>;

// algorithm
#include <algorithm>;
#include <execution>;

// numeric
#include <cmath>;
#include <complex>;
#include <valarray>;
#include <random>;
#include <numeric>;
#include <ratio>;
#include <cfenv>;
#include <bit>;
#include <numbers>;

// locale
#include <locale>;
#include <clocale>;

// io
#include <iosfwd>;
#include <ios>;
#include <istream>;
#include <ostream>;
#include <iostream>;
#include <fstream>;
#include <sstream>;
#include <syncstream>;
#include <spanstream>;
#include <iomanip>;
#include <streambuf>;
#include <cstdio>;

// filesystem
#include <filesystem>;

// regex
#include <regex>;

// atomic
#include <atomic>;

// thread
#include <thread>;
#include <stop_token>;
#include <mutex>;
#include <shared_mutex>;
#include <future>;
#include <condition_variable>;
#include <semaphore>;
#include <latch>;
#include <barrier>;

#else

import std.core;

#endif
