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



// �ܼ� â�� ũ��
void ConsoleView()
{
	system("mod con cols=100 lines=25");

}

// ��ǥ �̵� �Լ�
void gotoXY(int x, int y)
{
	// x, y ��ǥ ���� 
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;

	// Ŀ�� �̵�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

//Ű������ �Է��� �ް�, �Էµ� Ű�� ���� ��ȯ�ϴ� �Լ�
int KeyBoard()
{
	if (_kbhit() != 0)
	{
		return _getch();

	}
	return 0;
}
//������ �׸��� �Լ�
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
//������ �׸��� �Լ�
void Tree(int treeX)
{
	gotoXY(treeX, TREE_BOTTOM_Y);
	printf("�סססס� ");
	gotoXY(treeX, TREE_BOTTOM_Y + 1);
	printf(" �סס� ");
	gotoXY(treeX, TREE_BOTTOM_Y + 2);
	printf(" �סס� ");
	gotoXY(treeX, TREE_BOTTOM_Y + 3);
	printf(" �סס� ");
	gotoXY(treeX, TREE_BOTTOM_Y + 4);
	printf(" �סס� ");
}

void Bird(int birdX)
{
	gotoXY(birdX, BIRD_BOTTOM_Y);
	printf("   �ססס�");
	gotoXY(birdX, BIRD_BOTTOM_Y + 1);
	printf("  �סס�");
	gotoXY(birdX, BIRD_BOTTOM_Y + 2);
	printf("�סססססססס�");
	gotoXY(birdX, BIRD_BOTTOM_Y + 3);
	printf("  �סס�");
	gotoXY(birdX, BIRD_BOTTOM_Y + 4);
	printf("   �ססס�");
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
// �浹������ true,�ƴϸ� false
bool isCollision(const int treeX, const int birdX, const int dinoY)
{
	// Ʈ���� x�� ������ ��ü�ʿ� ������,���� x �� ������ ��ü�ʿ� ������,
	// ������ ���̰� ������� �ʴٸ� �浹�� ó��
	gotoXY(0, 0);
	printf("treeX: %d,dinoY : %d", treeX, birdX, dinoY);
	if (treeX <= 8 && treeX >= 4 && birdX <= 8 && birdX >= 4 && dinoY > 8)
	{
		return true;
	}
	return false;

}
// �浹������ true,�ƴϸ� false
bool isCollison2(const int birdX, const int dinoY)
{
	// ���� x �� ������ ��ü�ʿ� ������,
	// ������ ���̰� ���ٸ� �浹�� ó��
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
		// ���� ���۽� �ʱ�ȭ
		bool isJumping = false;
		bool bowDown = true;
		const int gravity = 3;

		int dinoY = DINO_BOTTOM_Y;
		int treeX = TREE_BOTTOM_X;
		int birdX = BIRD_BOTTOM_X;

		int score = 0;
		clock_t start, curr; // ���� ���� �ʱ�ȭ
		start = clock();     // ���۽ð� �ʱ�ȭ

		while (true)  // �� �ǿ� ���� ����
		{
			//  �浹üũ Ʈ���� x���� ���� x��,������ y������ �Ǵ� 

			if (isCollision(treeX, birdX, dinoY))
				break;
			// �� Ű�� ���Ȱ�, �ٴ��� �ƴҶ� ����
			if (KeyBoard() == 'z')
			{
				isJumping = true;
				bowDown = false;

			}
			// �� Ű�� ���Ȱ�, �ٴ��̸� ���̱�
			if (KeyBoard() == 'x')
			{
				bowDown = true;
				isJumping = false;
			}
			// �������̶�� Y�� ����, ������ �������� Y�� ����
			if (isJumping)
			{
				dinoY -= gravity;
			}
			else
			{
				dinoY += gravity;
			}
			// ���̱� ���̶�� Y�� ����, ���̱Ⱑ �������� Y�� ����
			if (bowDown)
			{
				dinoY += gravity;
			}
			else
			{
				dinoY -= gravity;
			}

			// Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����
			if (dinoY >= DINO_BOTTOM_Y)
			{
				dinoY = DINO_BOTTOM_Y;
				bowDown = true;
			}
			// ������ �������� (x����) �������ϰ�
			// ������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ
			treeX -= 2;
			if (treeX <= 0)
			{
				treeX = TREE_BOTTOM_X;
			}
			// ���� �������� (x����) �������ϰ�
			// ���� ��ġ�� ���� ������ ���� �ٽ� ������ ������ ��ȯ
			birdX -= 2;
			if (birdX <= 0)
			{
				birdX = BIRD_BOTTOM_X;
			}
			// ������ ������ ������ ������ ���� ��Ȳ
			if (dinoY <= 3)
			{
				isJumping = false;
			}
			DrawDino(dinoY);
			Tree(treeX);
			Bird(birdX);

			curr = clock();  // ����ð� �޾ƿ���
			if (((curr - start) / CLOCKS_PER_SEC) >= 1) // 1�ʰ� �Ѿ�����
			{
				score++; // ����UP
				start = clock(); // ���۽ð� �ʱ�ȭ

			}
			Sleep(60);
			system("cls");  // clear

			// ��������� 1�ʸ��� ���ִ°��� �ƴ϶� �׻� ������ָ鼭, 1�ʰ� �������� ++ ����
			gotoXY(22, 0);  // Ŀ���� ��� �������� �ű��. �ܼ�â�� cols=100�̴ϱ� 2*x�̹Ƿ� 22 ���� �־���
			printf("Score : %d", score); // ���� ���

			GameOver(score);
		}

	}

	return 0;
}