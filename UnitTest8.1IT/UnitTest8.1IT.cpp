#include "pch.h"
#include "CppUnitTest.h"
#include "../Project8.1IT/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81IT
{
	TEST_CLASS(UnitTest81IT)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[] = "++-==";
			int count = Count(str);
			Assert::AreEqual(5, count);  
		}
	};
}
