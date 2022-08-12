# shit_lib
## introduction
This worst STL implementation is just for handing in homework.  
It's base on C++2b, use module organize, and disable exception.
## environment
visual studio 2022  
std = C++2b(23)
## structure
```
mylib
|
|- head
|  |- c
|  |  |- standard
|  |  |  |- # TODO: more c standard head
|  |  |
|  |  |- non_standard
|  |     |- macro_meta
|  |     |  |- # TODO: some macro_meta head
|  |     |
|  |     |- # TODO: more non_standard head
|  |
|  |- cpp
|     |- standard
|     |  |- algorithm
|     |  |- compare
|     |  |- deque
|     |  |- functional
|     |  |- iterator
|     |  |- list
|     |  |- memory
|     |  |- numeric
|     |  |- queue
|     |  |- stack
|     |  |- string
|     |  |- type_traits
|     |  |- utility
|     |  |- vector
|     |  |- # TODO: more cpp standard head
|     |
|     |- non_standard
|     |  |- macro
|     |  |  |- macro_meta
|     |  |     |- # TODO: some macro_meta head
|     |  |
|     |  |- mylib_sort.h
|     |
|     |- cxxstd.h
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
