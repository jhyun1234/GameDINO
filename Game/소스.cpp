
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



// �ܼ� â�� ũ��
void ConsoleView()
{
	system("mod con cols=100 lines=25");

}

// ��ǥ �̵� �Լ�
void gotoXY(int x, int y)
{
	// x, y ��ǥ ���� 
	COORD position;

	position.X = x;
	position.Y = y;

	// Ŀ�� �̵�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

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
	printf("         �ססססס�  \n");
	printf("       �ס� �ססססס� \n");
	printf("       �סססססססס� \n");
	printf("��      �סס�       \n");
	printf("�ס�     �סססססס�   \n");
	printf("�סס�   �סססס�      \n");
	printf(" �ס�  �ססססססססס� \n");
	printf(" �סססססססססס�    \n");
	printf("  �ססססססססס�     \n");
	printf("    �ססססססס�     \n");
	printf("     �ססססס�      \n");

	if (legFlag)
	{
		printf("   ��     �סס�\n");
		printf("   �ס�         ");
		legFlag = false;
	}
	else
	{
		printf(" �סס�    ��    \n");
		printf("        �ס�     ");
		legFlag = true;
	}
}
void DrawDino(int dinoY)
{
	gotoXY(0, dinoY);
	static bool legFlag = true;
	
	printf("       ��                                  \n");
	printf("       �ס�                              \n");
	printf("       �סס�                        \n");
	printf("       �סס�              �סססססס�          \n");
	printf("        �סססססססססססס�  �ס� �ססססס�              \n");
	printf("        �ססססססססססססס� �סססססססס�          \n");
	printf("         �ססססססססס�    �סס�        \n");
	printf("          �ססססססס�     �סססססס�            \n");
	printf("                 ��                              \n");
	printf("                 ��                               \n");
	if (legFlag)				   
	{
		printf("   ��     �סס�\n");
		printf("   �ס�         ");
		legFlag = false;
	}
	else
	{
		printf(" �סס�    ��    \n");
		printf("        �ס�     ");
		legFlag = true;
	}
}
//������ �׸��� �Լ�
void Tree(int treeX)
{
	gotoXY(treeX, TREE_BOTTOM_Y);
	printf("�סססס� ");
	gotoXY(treeX, TREE_BOTTOM_Y+1);
	printf(" �סס� ");
	gotoXY(treeX, TREE_BOTTOM_Y+2);
	printf(" �סס� ");
	gotoXY(treeX, TREE_BOTTOM_Y+3);
	printf(" �סס� ");
	gotoXY(treeX, TREE_BOTTOM_Y+4);
	printf(" �סס� ");
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