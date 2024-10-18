#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab07.3(it)/Lab7.3(it).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 3;
			int colCount = 3;
			int shift = 1;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				a[i] = new int[colCount];
			}

			a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
			a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
			a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

			ShiftRight(a, rowCount, colCount, shift);

			Assert::AreEqual(3, a[0][0]);
			Assert::AreEqual(1, a[0][1]);
			Assert::AreEqual(2, a[0][2]);
			Assert::AreEqual(6, a[1][0]);
			Assert::AreEqual(4, a[1][1]);
			Assert::AreEqual(5, a[1][2]);
			Assert::AreEqual(9, a[2][0]);
			Assert::AreEqual(7, a[2][1]);
			Assert::AreEqual(8, a[2][2]);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
