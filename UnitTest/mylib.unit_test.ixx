module;

#include <CppUnitTest.h>

export module mylib.unit_test;

import mylib;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestNamespace
{
	TEST_CLASS(UnitTestClass1) {
	public:	
		TEST_METHOD(TestMethod1) {		
		}
	};
}
