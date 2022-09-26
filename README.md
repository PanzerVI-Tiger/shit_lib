# shit_lib
## introduction
## ����
This worst STL implementation is just for handing in homework.  
���������STLʵ��ֻ����������ҵ�ġ�  
  
This is my personal project to implement a simplified STL and some other facilities,  
and it is based on C\+\+2b, using module organize, and default disabled exception.  
�˸�����Ŀ����ʵ��STL��һЩ��������ʩ��  
����Ŀ����C\+\+2b��׼��ʹ��ģ����֯����Ĭ�Ͻ����쳣��  

## environment
## ����
visual studio 17.4.0(2022) preview 1.0  
std: C\+\+latest(C\+\+2b\C\+\+23)  
  
## structure
## �ṹ
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
|  |  |  |  |- mylib_assert.hpp
|  |  |  |
|  |  |  |- mylib_sort.hpp
|  |  |
|  |  |- cxxstd.hpp
|  |
|  |- macro_meta
|  |  |- macro_base.hpp
|  |  |- arithmetic.hpp
|  |  |- bool.hpp
|  |  |- compare.hpp
|  |  |- dec.hpp
|  |  |- for.hpp
|  |  |- if.hpp
|  |  |- inc.hpp
|  |  |- numeric
|  |  |- repet.hpp
|  |  |- tuple.hpp
|  |  |- variadic.hpp
|  |  |- more macro_meta head
|  |
|  |- preprocessor.hpp
|  |- more head
|
|- module
|  |- standard
|  |  |- algorithm
|  |  |  |- mylib.algorithm.cppm
|  |  |  |- # TODO: more standard algorithm module
|  |  |
|  |  |- container
|  |  |  |- mylib.deque.cppm
|  |  |  |- mylib.list.cppm
|  |  |  |- mylib.queue.cppm
|  |  |  |- mylib.stack.cppm
|  |  |  |- mylib.vector.cppm
|  |  |  |- # TODO: more standard container module
|  |  |
|  |  |- exception
|  |  |  |- mylib.exception.cppm
|  |  |  |- # TODO: more standard exception module
|  |  |
|  |  |- io
|  |  |  |- # TODO: more standard io module
|  |  |
|  |  |- iterator
|  |  |  |- mylib.iterator.cppm
|  |  |
|  |  |- memory
|  |  |  |- mylib.memory.cppm
|  |  |  |- # TODO: more standard memory module
|  |  |
|  |  |- numeric
|  |  |  |- mylib.numeric.cppm
|  |  |  |- # TODO: more standard numeric module
|  |  |
|  |  |- string
|  |  |  |- mylib.string.cppm
|  |  |  |- # TODO: more standard string module
|  |  |
|  |  |- utility
|  |  |  |- mylib.compare.cppm
|  |  |  |- mylib.cstddef.cppm
|  |  |  |- mylib.functional.cppm
|  |  |  |- mylib.tuple.cppm
|  |  |  |- mylib.type_traits.cppm
|  |  |  |- mylib.utility.cppm
|  |  |  |- # TODO: more standard utility module
|  |  |
|  |  |- # TODO: more standard module
|  |
|  |- non_standard
|     |- algorithm
|     |  |- mylib.concat.cppm
|     |  |- mylib.sort.cppm
|     |  |- # TODO: more non_standard algorithm module
|     |
|     |- container
|     |  |- tree
|     |  |  |- mylib.binary_tree.cppm
|     |  |  |- mylib.hppuffman_tree.cppm
|     |  |  |- mylib.new_binary_tree.cppm
|     |  |  |- mylib.red_black_tree.cppm
|     |  |  |- # TODO: more non_standard tree module
|     |  |
|     |  |- mylib.fixed.cppm
|     |  |- mylib.grade.cppm
|     |  |- mylib.graph.cppm
|     |  |- mylib.link_list.cppm
|     |  |- mylib.matrix.cppm
|     |  |- # TODO: more non_standard container module
|     |
|     |- exception
|     |  |- mylib.assert.cppm
|     |  |- mylib.iterator_check.cppm
|     |  |- # TODO: more non_standard exception module
|     |
|     |- io
|     |  |- mylib.stream_output.cppm
|     |  |- # TODO: more non_standard io module
|     |
|     |- string
|     |  |- mylib.char_sequence.cppm
|     |  |- mylib.static_string.cppm
|     |  |- mylib.string_literal.cppm
|     |  |- # TODO: more non_standard string module
|     |
|     |- templates
|     |  |- mylib.meta_function.cppm
|     |  |- mylib.templates_utility.cppm
|     |  |- mylib.type_list.cppm
|     |  |- mylib.type_pack.cppm
|     |  |- # TODO: more non_standard templates module
|     |
|     |- utility
|        |- mylib.aggregate.cppm
|        |- mylib.conatiner_traits.cppm
|        |- mylib.eval.cppm
|        |- mylib.pointer.cppm
|        |- mylib.string_traits.cppm
|        |- mylib.timer.cppm
|        |- # TODO: more non_standard utility module
|
|- mylib.cppm # import all mylib module
```  
  
## conditional compilation macro
## ���������
`MYLIB_ASSERT`   : to open mylib's assert.    (default: close)  
`MYLIB_UNIITEST` : to open mylib's unittest.  (default: close)  
`MYLIB_EXCEPTION`: to open mylib's exception. (default: close)  
`MYLIB_STANDARD` : to open mylib's standard mode, equal to defined `MYLIB_EXCEPTION`,  
	and will undefine `MYLIB_ASSERT`.         (default: close)
  
`MYLIB_ASSERT`   : ����mylib�Ķ���     ��Ĭ�Ϲرգ�  
`MYLIB_UNIITEST` : ����mylib�����ϲ��� ��Ĭ�Ϲرգ�  
`MYLIB_EXCEPTION`: ����mylib���쳣     ��Ĭ�Ϲرգ�  
`MYLIB_STANDARD` : ����mylib�ı�׼ģʽ�����ڶ���`MYLIB_EXCEPTION`�꣬ 
	ͬʱ��ȡ��`MYLIB_ASSERT`��Ķ���    ��Ĭ�Ϲرգ� 

## unittest
## ���ϲ���
If you want to use unittest to test mylib, please predefined macro `MYLIB_UNITTEST`.  
There are two test method in mylib: by static_assert and by print example.  
The former will automatic test all module, will report error when test failed.  
The latter shall call print test function to print test example,  
all print test function is in namespace `myib::unittest`,  
and naming style is `module_name` + `_print_test`.  
Such as module vector's is `mylib::unittest::vector_print_test`.  
If you want to run all print test, you can call `mylib::unittest::print_test`.  
  
�����ʹ�����ϲ���������mylib����Ԥ����`MYLIB_UNITTEST`�ꡣ  
mylib�����ֲ��Է���: ͨ��static_assert�ʹ�ӡ����,  
ǰ�߽��Զ��������е�ģ��, ����ʧ��ʱ������,  
��������ô�ӡ���Ժ�������ӡ���в�������,  
��Щ���Ժ����������ռ�`myib::unittest`��,  
���������������`module_name` + `_print_test`��  
����vectorģ��Ĳ��Ժ�����`mylib::unittest::vector_print_test`  
������������еĴ�ӡ���Կ��Ե��ú���`mylib::unittest::print_test`  
