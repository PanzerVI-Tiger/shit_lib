# shit_lib
## introduction
## 介绍
This worst STL implementation is just for handing in homework.  
这个最糟糕的STL实现只是用来交作业的。  
  
This is my personal project to implement a simplified STL and some other facilities,  
and it is based on C\+\+2b, using module organize, and default disabled exception.  
此个人项目用以实现STL与一些其他的设施，  
本项目基于C\+\+2b标准，使用模块组织，并默认禁用异常。  

## environment
## 环境
visual studio 17.4.0(2022) preview 1.0  
std: C\+\+latest(C\+\+2b\C\+\+23)  
  
## structure
## 结构
```
mylib
|
|- head
|  |- c
|  |  |- standard
|  |  |  |- # TODO: more c standard head
|  |  |
|  |  |- non_standard
|  |     |- # TODO: more non_standard head
|  |
|  |- cpp
|  |  |- standard # import corresponding module only
|  |  |  |- algorithm
|  |  |  |- compare
|  |  |  |- deque
|  |  |  |- functional
|  |  |  |- iterator
|  |  |  |- list
|  |  |  |- memory
|  |  |  |- numeric
|  |  |  |- queue
|  |  |  |- stack
|  |  |  |- string
|  |  |  |- type_traits
|  |  |  |- utility
|  |  |  |- vector
|  |  |  |- # TODO: more cpp standard head
|  |  |
|  |  |- non_standard # import corresponding module only
|  |  |  |- macro
|  |  |  |  |- mylib_assert.h
|  |  |  |
|  |  |  |- mylib_sort.h
|  |  |
|  |  |- cxxstd.h
|  |
|  |- macro_meta
|  |  |- macro_base.h
|  |  |- arithmetic.h
|  |  |- bool.h
|  |  |- compare.h
|  |  |- dec.h
|  |  |- for.h
|  |  |- if.h
|  |  |- inc.h
|  |  |- numeric
|  |  |- repet.h
|  |  |- tuple.h
|  |  |- variadic.h
|  |  |- more macro_meta head
|  |
|  |- preprocessor.h
|  |- more head
|
|- module
|  |- standard
|  |  |- algorithm
|  |  |  |- mylib.algorithm.ixx
|  |  |  |- # TODO: more standard algorithm module
|  |  |
|  |  |- container
|  |  |  |- mylib.deque.ixx
|  |  |  |- mylib.list.ixx
|  |  |  |- mylib.queue.ixx
|  |  |  |- mylib.stack.ixx
|  |  |  |- mylib.vector.ixx
|  |  |  |- # TODO: more standard container module
|  |  |
|  |  |- io
|  |  |  |- # TODO: more standard io module
|  |  |
|  |  |- iterator
|  |  |  |- mylib.iterator.ixx
|  |  |
|  |  |- memory
|  |  |  |- mylib.memory.ixx
|  |  |  |- # TODO: more standard memory module
|  |  |
|  |  |- numeric
|  |  |  |- mylib.numeric.ixx
|  |  |  |- # TODO: more standard numeric module
|  |  |
|  |  |- string
|  |  |  |- mylib.string.ixx
|  |  |  |- # TODO: more standard string module
|  |  |
|  |  |- utility
|  |  |  |- mylib.compare.ixx
|  |  |  |- mylib.functional.ixx
|  |  |  |- mylib.tuple.ixx
|  |  |  |- mylib.type_traits.ixx
|  |  |  |- mylib.utility.ixx
|  |  |  |- # TODO: more standard utility module
|  |  |
|  |  |- # TODO: more standard module
|  |
|  |- non_standard
|     |- algorithm
|     |  |- mylib.algorithm.ixx
|     |  |- mylib.concat.ixx
|     |  |- # TODO: more non_standard algorithm module
|     |
|     |- container
|     |  |- tree
|     |  |  |- mylib.binary_tree.ixx
|     |  |  |- mylib.huffman_tree.ixx
|     |  |  |- mylib.red_black_tree.ixx
|     |  |  |- # TODO: more non_standard tree module
|     |  |
|     |  |- mylib.fixed.ixx
|     |  |- mylib.grade.ixx
|     |  |- mylib.graph.ixx
|     |  |- mylib.link_list.ixx
|     |  |- mylib.matrix.ixx
|     |  |- # TODO: more non_standard container module
|     |
|     |- io
|     |  |- mylib.stream_output.ixx
|     |  |- # TODO: more non_standard io module
|     |
|     |- string
|     |  |- mylib.stack_string.ixx
|     |  |- mylib.char_sequence.ixx
|     |  |- mylib.string_literal.ixx
|     |  |- # TODO: more non_standard string module
|     |
|     |- templates
|     |  |- mylib.templates_utility.ixx
|     |  |- # TODO: more non_standard templates module
|     |
|     |- utility
|        |- mylib.aggregate.ixx
|        |- mylib.conatiner_traits.ixx
|        |- mylib.eval.ixx
|        |- mylib.pointer.ixx
|        |- mylib.string_traits.ixx
|        |- mylib.timer.ixx
|        |- # TODO: more non_standard utility module
|
|- mylib.ixx # import all mylib module
```  
  
## conditional compilation macro
## 条件编译宏
`MYLIB_ASSERT`   : to open mylib's assert.    (default: close)  
`MYLIB_UNIITEST` : to open mylib's unittest.  (default: close)  
`MYLIB_EXCEPTION`: to open mylib's exception. (default: close)  
`MYLIB_STANDARD` : to open mylib's standard mode, equal to defined `MYLIB_EXCEPTION`,  
	and will undefine `MYLIB_ASSERT`.         (default: close)
  
`MYLIB_ASSERT`   : 启用mylib的断言     （默认关闭）  
`MYLIB_UNIITEST` : 启用mylib的联合测试 （默认关闭）  
`MYLIB_EXCEPTION`: 启用mylib的异常     （默认关闭）  
`MYLIB_STANDARD` : 启用mylib的标准模式，等于定义`MYLIB_EXCEPTION`宏， 
	同时会取消`MYLIB_ASSERT`宏的定义    （默认关闭） 

## unittest
## 联合测试
If you want to use unittest to test mylib, please predefined macro `MYLIB_UNITTEST`.  
There are two test method in mylib: by static_assert and by print example.  
The former will automatic test all module, will report error when test failed.  
The latter shall call print test function to print test example,  
all print test function is in namespace `myib::unittest`,  
and naming style is `module_name` + `_print_test`.  
Such as module vector's is `mylib::unittest::vector_print_test`.  
If you want to run all print test, you can call `mylib::unittest::print_test`.  
  
如果想使用联合测试来测试mylib，请预定义`MYLIB_UNITTEST`宏。  
mylib有两种测试方法: 通过static_assert和打印样例,  
前者将自动测试所有的模块, 测试失败时将报错,  
后者需调用打印测试函数来打印所有测试样例,  
这些测试函数在命名空间`myib::unittest`内,  
函数的命名风格是`module_name` + `_print_test`。  
例如vector模块的测试函数是`mylib::unittest::vector_print_test`  
如果想运行所有的打印测试可以调用函数`mylib::unittest::print_test`  
