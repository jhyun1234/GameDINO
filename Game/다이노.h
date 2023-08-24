#pragma once

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
#define BIRD_BOTTOM_Y 8



// 콘솔 창의 크기
void ConsoleView()
{
	system("mod con cols=100 lines=25");

}

// 좌표 이동 함수
void gotoXY(int x, int y)
{
	// x, y 좌표 설정 
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;

	// 커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int KeyBoard()
{
	if (_kbhit() != 0)
	{
		return _getch();

	}
	return 0;
}
//공룡을 그리는 함수
void DrawDino(int dinoY)
{
	gotoXY(0, dinoY);
	static bool legFlag = true;
	printf("        $$$$$$$ \n");
	printf("       $$ $$$$$$\n");
	printf("       $$$$$$$$$\n");
	printf("$      $$$      \n");
	printf("$$     $$$$$$$  \n");
	printf("$$$   $$$$$     \n");
	printf(" $$  $$$$$$$$$$ \n");
	printf(" $$$$$$$$$$$    \n");
	printf("  $$$$$$$$$$    \n");
	printf("    $$$$$$$$    \n");
	printf("     $$$$$$     \n");
	if (legFlag)
	{
		printf("     $    $$$    \n");
		printf("     $$          ");
		legFlag = false;
	}
	else
	{
		printf("     $$$  $     \n");
		printf("          $$    ");
		legFlag = true;
	}
}
void DrawDino1(int dinoY)
{
	gotoXY(0, dinoY);
	static bool legFlag = true;

	printf("       $                                  \n");
	printf("       $$                              \n");
	printf("       $$$                        \n");
	printf("       $$$              $$$$$$$         \n");
	printf("        $$$$$$$$$$$$$  $$ $$$$$$              \n");
	printf("        $$$$$$$$$$$$$$ $$$$$$$$$          \n");
	printf("         $$$$$$$$$$$    $$$        \n");
	printf("          $$$$$$$$     $$$$$$$            \n");
	printf("                 $                              \n");
	printf("                 $                               \n");
	if (legFlag)
	{
		printf("   $    $$$\n");
		printf("   $$         ");
		legFlag = false;
	}
	else
	{
		printf(" $$$    $    \n");
		printf("        $$     ");
		legFlag = true;
	}
}
//나무를 그리는 함수
void Tree(int treeX)
{
	gotoXY(treeX, TREE_BOTTOM_Y);
	printf("§§§§§ ");
	gotoXY(treeX, TREE_BOTTOM_Y + 1);
	printf(" §§§ ");
	gotoXY(treeX, TREE_BOTTOM_Y + 2);
	printf(" §§§ ");
	gotoXY(treeX, TREE_BOTTOM_Y + 3);
	printf(" §§§ ");
	gotoXY(treeX, TREE_BOTTOM_Y + 4);
	printf(" §§§ ");
}

void Bird(int birdX)
{
	gotoXY(birdX, BIRD_BOTTOM_Y);
	printf("   §§§§");
	gotoXY(birdX, BIRD_BOTTOM_Y + 1);
	printf("  §§§");
	gotoXY(birdX, BIRD_BOTTOM_Y + 2);
	printf("§§§§§§§§§");
	gotoXY(birdX, BIRD_BOTTOM_Y + 3);
	printf("  §§§");
	gotoXY(birdX, BIRD_BOTTOM_Y + 4);
	printf("   §§§§");
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
// 충돌했으면 true,아니면 false
bool isCollision(const int treeX, const int birdX, const int dinoY)
{
	// 트리의 x가 공룡의 몸체쪽에 있을때,새의 x 가 공룡의 몸체쪽에 있을때,
	// 공룡의 높이가 충분하지 않다면 충돌로 처리
	gotoXY(0, 0);
	printf("treeX: %d,dinoY : %d", treeX, birdX, dinoY);
	if (treeX <= 8 && treeX >= 4 && birdX <= 8 && birdX >= 4 && dinoY > 8)
	{
		return true;
	}
	return false;

}
// 충돌했으면 true,아니면 false
bool isCollison2(const int birdX, const int dinoY)
{
	// 새의 x 가 공룡의 몸체쪽에 있을때,
	// 공룡의 높이가 높다면 충돌로 처리
	gotoXY(0, 0);
	printf("birdX : %d,dinoY : %d", birdX, dinoY);
	if (birdX <= 8 && birdX >= 4 && dinoY > 8)
	{
		return true;
	}
	return false;

}



int main()
{

	ConsoleView();
	while (true)
	{
		// 게임 시작시 초기화
		bool isJumping = false;
		bool bowDown = true;
		const int gravity = 3;

		int dinoY = DINO_BOTTOM_Y;
		int treeX = TREE_BOTTOM_X;
		int birdX = BIRD_BOTTOM_X;

		int score = 0;
		clock_t start, curr; // 점수 변수 초기화
		start = clock();     // 시작시간 초기화

		while (true)  // 한 판에 대한 루프
		{
			//  충돌체크 트리의 x값과 새의 x값,공룡의 y값으로 판단 

			if (isCollision(treeX, birdX, dinoY))
				break;
			// ↑ 키가 눌렸고, 바닥이 아닐때 점프
			if (KeyBoard() == 'z')
			{
				isJumping = true;
				bowDown = false;

			}
			// ↓ 키가 눌렸고, 바닥이면 숙이기
			if (KeyBoard() == 'x')
			{
				bowDown = true;
				isJumping = false;
			}
			// 점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가
			if (isJumping)
			{
				dinoY -= gravity;
			}
			else
			{
				dinoY += gravity;
			}
			// 숙이기 중이라면 Y를 증가, 숙이기가 끝났으면 Y를 감소
			if (bowDown)
			{
				dinoY += gravity;
			}
			else
			{
				dinoY -= gravity;
			}

			// Y가 계속해서 증가하는걸 막기위해 바닥을 지정
			if (dinoY >= DINO_BOTTOM_Y)
			{
				dinoY = DINO_BOTTOM_Y;
				bowDown = true;
			}
			// 나무가 왼쪽으로 (x음수) 가도록하고
			// 나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환
			treeX -= 2;
			if (treeX <= 0)
			{
				treeX = TREE_BOTTOM_X;
			}
			// 새가 왼쪽으로 (x음수) 가도록하고
			// 새의 위치가 왼쪽 끝으로 가면 다시 오른쪽 끝으로 소환
			birdX -= 2;
			if (birdX <= 0)
			{
				birdX = BIRD_BOTTOM_X;
			}
			// 점프의 맨위를 찍으면 점프가 끝난 상황
			if (dinoY <= 3)
			{
				isJumping = false;
			}
			DrawDino(dinoY);
			Tree(treeX);
			Bird(birdX);

			curr = clock();  // 현재시간 받아오기
			if (((curr - start) / CLOCKS_PER_SEC) >= 1) // 1초가 넘었을때
			{
				score++; // 점수UP
				start = clock(); // 시작시간 초기화

			}
			Sleep(60);
			system("cls");  // clear

			// 점수출력을 1초마다 해주는것이 아니라 항상 출력해주면서, 1초가 지났을때 ++ 해줌
			gotoXY(22, 0);  // 커서를 가운데 위쪽으로 옮긴다. 콘솔창이 cols=100이니까 2*x이므로 22 정도 넣어줌
			printf("Score : %d", score); // 점수 출력

			GameOver(score);
		}

	}

	return 0;
}