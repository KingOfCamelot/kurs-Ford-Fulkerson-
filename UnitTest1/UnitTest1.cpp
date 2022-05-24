#include "pch.h"
#include "CppUnitTest.h"
#include "../kurs/string.h"
#include "../kurs/Ford-Fulkerson.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Ford_Fulkerson test_1;
			string file_name = "test_1.txt";
			Assert::AreEqual(10, test_1.search_max_flow(file_name));
		}
		TEST_METHOD(TestMethod2)
		{
			Ford_Fulkerson test_2;
			string file_name = "test_2.txt";
			Assert::AreEqual(7, test_2.search_max_flow(file_name));
		}
		TEST_METHOD(TestMethod3)
		{
			Ford_Fulkerson test_3;
			string file_name = "test_3.txt";
			Assert::AreEqual(12, test_3.search_max_flow(file_name));
		}
	};
}
