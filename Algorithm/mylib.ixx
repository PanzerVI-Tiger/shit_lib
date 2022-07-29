export module mylib;

import std.core;

/*       standard module       */
//		   algorthim
export import mylib.algorithm;

//		   container
export import mylib.list;
export import mylib.deque;
export import mylib.queue;
export import mylib.stack;
export import mylib.vector;

//		    iterator
export import mylib.iterator;

//		     memory
export import mylib.memory;

//			 string
export import mylib.string;

//		     utility
export import mylib.compare;	 // C++20
export import mylib.utility;
export import mylib.functional;
export import mylib.type_traits; // C++11

//			 numeric
export import mylib.numeric;

/*     not standard module     */
//			algorthm
export import mylib.sort;

//		    container
export import mylib.fixed;
export import mylib.grade;
export import mylib.graph;
export import mylib.matrix;
export import mylib.link_list;
export import mylib.binary_tree;
export import mylib.huffman_tree;
export import mylib.red_black_tree;

//			   io
export import mylib.stream_output;    // ouput some container to stream

//			 utility
export import mylib.eval;			  // calculate C's or scheme's style expression
export import mylib.timer;
export import mylib.container_traits; // traits of mylib container and iterator

export {
	// test assmebly code
	extern "C" void test_asm();

	// standard namespace alias
	namespace stdr = std::ranges;
	namespace stdc = std::chrono;
	namespace stdv = std::views;
	namespace stdl = std::literals;
}
