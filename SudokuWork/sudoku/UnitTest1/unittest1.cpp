#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sudoku/initial.h"
#include "../sudoku/initial.cpp"
#include "../sudoku/define.h"
#include "../sudoku/define.cpp"
#include "../sudoku/create.h"
#include "../sudoku/create.cpp"
#include "../sudoku/solve.h"
#include "../sudoku/solve.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a = 1, b = 2;
			swap(a, b);
			Assert::AreEqual(a == 2, true);
			Assert::AreEqual(b == 1, true);
		}
		TEST_METHOD(TestMethod2)
		{
			int a = 19650, b = 1698;
			swap(a, b);
			Assert::AreEqual(a == 1698, true);
			Assert::AreEqual(b == 19650, true);
		}
		TEST_METHOD(TestMethod3)
		{
			initial_origin();
			Assert::AreEqual(origin[0][0] == 1, true);
			Assert::AreEqual(origin[0][1] == 2, true);
			Assert::AreEqual(origin[0][2] == 3, true);
			Assert::AreEqual(origin[0][3] == 4, true);
			Assert::AreEqual(origin[0][4] == 5, true);
			
		}
		TEST_METHOD(TestMethod4)
		{
			BOARD board = {
				{
					{ 1, 2, 3, 4, 5, 6, 7, 8, 9},
					{ 7, 8, 9, 1, 2, 3, 4, 5, 6},
					{ 4, 5, 6, 7, 8, 9, 1, 2, 3},
					{ 9, 1, 2, 3, 4, 5, 6, 7, 8},
					{ 6, 7, 8, 9, 1, 2, 3, 4, 5},
					{ 3, 4, 5, 6, 7, 8, 9, 1, 2},
					{ 8, 9, 1, 2, 3, 4, 5, 6, 7},
					{ 5, 6, 7, 8, 9, 1, 2, 3, 4},
					{ 2, 3, 4, 5, 6, 7, 8, 9, 1}
				},
				{ 0 },
				{ 0 },
				{ 0 }
			};
			
			cal_board(board);

			Assert::AreEqual(board.row[0] == 1022, true);
			Assert::AreEqual(board.row[1] == 1022, true);
			Assert::AreEqual(board.row[2] == 1022, true);
			Assert::AreEqual(board.row[3] == 1022, true);
			Assert::AreEqual(board.row[4] == 1022, true);
			Assert::AreEqual(board.row[5] == 1022, true);
			Assert::AreEqual(board.row[8] == 1022, true);
			Assert::AreEqual(board.col[0] == 1022, true);
			Assert::AreEqual(board.col[1] == 1022, true);
			Assert::AreEqual(board.col[2] == 1022, true);
			Assert::AreEqual(board.col[3] == 1022, true);
			Assert::AreEqual(board.col[4] == 1022, true);
			Assert::AreEqual(board.col[5] == 1022, true);
			Assert::AreEqual(board.col[8] == 1022, true);
			Assert::AreEqual(board.grid[0] == 1022, true);
			Assert::AreEqual(board.grid[8] == 1022, true);
			
		}
		TEST_METHOD(TestMethod5)
		{
			BOARD board = {
				{
					{ 0, 2, 3, 4, 5, 6, 7, 8, 9 },
					{ 0, 8, 9, 1, 2, 3, 4, 5, 6 },
					{ 4, 5, 6, 7, 8, 9, 1, 2, 3 },
					{ 9, 1, 2, 3, 4, 5, 6, 7, 8 },
					{ 6, 7, 8, 9, 1, 2, 3, 4, 5 },
					{ 3, 4, 5, 6, 7, 8, 9, 1, 2 },
					{ 8, 9, 1, 2, 3, 4, 5, 6, 7 },
					{ 5, 6, 7, 8, 9, 1, 2, 3, 4 },
					{ 2, 3, 4, 5, 6, 7, 8, 9, 1 }
				},
				{ 0 },
				{ 0 },
				{ 0 }
			};

			cal_board(board);

			BOARD backup = board;
			solution(board, backup);

			Assert::AreEqual(board.map[0][0] == 1, true);
			Assert::AreEqual(board.map[1][0] == 7, true);

		}
		TEST_METHOD(TestMethod6)
		{
			int a = -4, b = 2;
			swap(a, b);
			Assert::AreEqual(a == 2, true);
			Assert::AreEqual(b == -4, true);
		}
		TEST_METHOD(TestMethod7)
		{
			char s[20] = "123456";
			int num = change_num(s);
			Assert::AreEqual(num == 123456, true);
		}
		TEST_METHOD(TestMethod8)
		{
			char s[20] = "abc";
			int num = change_num(s);
			Assert::AreEqual(num == -1, true);

		}
		TEST_METHOD(TestMethod9)
		{
			char s[20] = "1000000000000";
			int num = change_num(s);
			Assert::AreEqual(num == -2, true);
		}
		TEST_METHOD(TestMethod10)
		{
			char s[20] = "2903000";
			int num = change_num(s);
			Assert::AreEqual(num == -3, true);
		}
		TEST_METHOD(TestMethod11)
		{
			BOARD board = {
				{
					{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
					{ 7, 8, 9, 1, 2, 3, 4, 5, 6 },
					{ 4, 5, 6, 7, 8, 9, 1, 2, 3 },
					{ 9, 1, 2, 3, 4, 5, 6, 7, 8 },
					{ 6, 7, 8, 9, 1, 2, 3, 4, 5 },
					{ 3, 4, 5, 6, 7, 8, 9, 1, 2 },
					{ 8, 9, 1, 2, 3, 4, 5, 6, 7 },
					{ 5, 6, 7, 8, 9, 1, 2, 3, 4 },
					{ 2, 3, 4, 5, 6, 7, 8, 9, 1 }
				},
				{ 0 },
				{ 0 },
				{ 0 }
			};

			cal_board(board);

			int n = find(board);

			Assert::AreEqual(n == -1, true);
		}
		TEST_METHOD(TestMethod12)
		{
			BOARD board = {
				{
					{ 0, 2, 3, 4, 5, 6, 7, 8, 9 },
					{ 7, 8, 9, 1, 2, 3, 4, 5, 6 },
					{ 4, 5, 6, 7, 8, 9, 1, 2, 3 },
					{ 9, 1, 2, 3, 4, 5, 6, 7, 8 },
					{ 6, 7, 8, 9, 1, 2, 3, 4, 5 },
					{ 3, 4, 5, 6, 7, 8, 9, 1, 2 },
					{ 8, 9, 1, 2, 3, 4, 5, 6, 7 },
					{ 5, 6, 7, 8, 9, 1, 2, 3, 4 },
					{ 2, 3, 4, 5, 6, 7, 8, 9, 1 }
				},
				{ 0 },
				{ 0 },
				{ 0 }
			};

			cal_board(board);

			int n = find(board);

			Assert::AreEqual(n == 0, true);
		}


	};
}