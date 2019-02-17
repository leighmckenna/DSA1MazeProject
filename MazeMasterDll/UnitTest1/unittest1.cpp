#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//methods 
__declspec(dllimport) char* GetTeam();
__declspec(dllimport) void SetMaze(const int** data, int width, int height);
__declspec(dllimport) void GetNextPosition(int& xpos, int& ypos);
__declspec(dllimport) int** GetMaze(int&& width, int&& height);
__declspec(dllimport) void SetStart(int x, int y);
__declspec(dllimport) void GetStart(int& xPos, int& yPos);
__declspec(dllimport) void SetEnd(int x, int y);
__declspec(dllimport) void GetEnd(int& xPos, int& yPos);
const int** finalMaze;


namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestGetTeam)
		{
			char* names = GetTeam();
			Assert::AreEqual(names, "Lei McKenna and Jacob Marcovecchio");
		}
		TEST_METHOD(TestSetMaze)
		{
			int** maze;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					maze[i][j] = 0;
				}
			}
			finalMaze = (const int**) maze;

			SetMaze(finalMaze, 5, 5);
		}
		TEST_METHOD(TestGetMaze)
		{
			int** mazeReturn = GetMaze(5, 5);
			bool changeValue = true;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (finalMaze[i][j] != mazeReturn[i][j]) 
					{
						changeValue = false;
					}
				}
			}

			Assert::IsTrue(changeValue);
		}
		TEST_METHOD(TestGetNextPosition)
		{
			int xpos = 5;
			int ypos = 5;
			GetNextPosition(xpos, ypos);

			Assert::AreEqual(xpos, 1);
		}
		TEST_METHOD(TestSetStart)
		{

		}
		TEST_METHOD(TestGetStart)
		{

		}
		TEST_METHOD(TestSetEnd)
		{

		}
		TEST_METHOD(TestGetEnd)
		{

		}

	};
}