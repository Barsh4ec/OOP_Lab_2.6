#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_2.6/Fraction.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Fraction a(4, 5);
			Fraction b(6, 7);
			bool t = Less(a, b);
			Assert::IsTrue(t);
		}
	};
}
