
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


#define UP 72
#define DOWN 80

#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45
#define BIRD_BOTTOM_X 35
#define BIRD_BOTTOM_Y 15



// 嬬車 但税 滴奄
void ConsoleView()
{
	system("mod con cols=100 lines=25");

}

// 疎妊 戚疑 敗呪
void gotoXY(int x, int y)
{
	// x, y 疎妊 竺舛 
	COORD position;

	position.X = x;
	position.Y = y;

	// 朕辞 戚疑
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

}

//徹左球税 脊径聖 閤壱, 脊径吉 徹税 葵聖 鋼発馬澗 敗呪
int KeyBoard()
{
	if (_kbhit() != 0)
	{
		return _getch();

	}
	return 0;
}
//因傑聖 益軒澗 敗呪
void DrawDino(int dinoY)
{
	gotoXY(0, dinoY);
	static bool legFlag = true;
	printf("         」」」」」」  \n");
	printf("       」」 」」」」」」 \n");
	printf("       」」」」」」」」」 \n");
	printf("」      」」」       \n");
	printf("」」     」」」」」」」   \n");
	printf("」」」   」」」」」      \n");
	printf(" 」」  」」」」」」」」」」 \n");
	printf(" 」」」」」」」」」」」    \n");
	printf("  」」」」」」」」」」     \n");
	printf("    」」」」」」」」     \n");
	printf("     」」」」」」      \n");

	if (legFlag)
	{
		printf("   」     」」」\n");
		printf("   」」         ");
		legFlag = false;
	}
	else
	{
		printf(" 」」」    」    \n");
		printf("        」」     ");
		legFlag = true;
	}
}
void DrawDino(int dinoY)
{
	gotoXY(0, dinoY);
	static bool legFlag = true;
	
	printf("       」                                  \n");
	printf("       」」                              \n");
	printf("       」」」                        \n");
	printf("       」」」              」」」」」」」          \n");
	printf("        」」」」」」」」」」」」」  」」 」」」」」」              \n");
	printf("        」」」」」」」」」」」」」」 」」」」」」」」」          \n");
	printf("         」」」」」」」」」」    」」」        \n");
	printf("          」」」」」」」」     」」」」」」」            \n");
	printf("                 」                              \n");
	printf("                 」                               \n");
	if (legFlag)				   
	{
		printf("   」     」」」\n");
		printf("   」」         ");
		legFlag = false;
	}
	else
	{
		printf(" 」」」    」    \n");
		printf("        」」     ");
		legFlag = true;
	}
}
//蟹巷研 益軒澗 敗呪
void Tree(int treeX)
{
	gotoXY(treeX, TREE_BOTTOM_Y);
	printf("」」」」」 ");
	gotoXY(treeX, TREE_BOTTOM_Y+1);
	printf(" 」」」 ");
	gotoXY(treeX, TREE_BOTTOM_Y+2);
	printf(" 」」」 ");
	gotoXY(treeX, TREE_BOTTOM_Y+3);
	printf(" 」」」 ");
	gotoXY(treeX, TREE_BOTTOM_Y+4);
	printf(" 」」」 ");
}
void GameOver(const int score)
{
	system("cls");
	int x = 18;
	int y = 8;
	gotoXY(x, y);
	printf("===========================");
	gotoXY(x, y + 1);
	printf("======G A M E O V E R======");
	gotoXY(x, y + 2);
	printf("===========================");
	gotoXY(x, y + 5);
	printf("SCORE : %d,", score);

	printf("\n\n\n\n\n\n\n\n\n");
	system("pause");
}


int main()
{
	
	return 0;
}