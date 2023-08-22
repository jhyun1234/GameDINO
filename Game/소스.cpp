
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45



// 콘솔 창의 크기
void ConsoleView()
{
	system("mod con cols=100 lines=25");

}

// 좌표 이동 함수
void gotoXY(int x, int y)
{
	// x, y 좌표 설정 
	COORD position;

	position.X = x;
	position.Y = y;

	// 커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

}




int main()
{
	
	return 0;
}