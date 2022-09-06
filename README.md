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
