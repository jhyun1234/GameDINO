#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 81

#define BIRD_BOTTOM_X 105
#define BIRD_BOTTOM_Y 9

//�ܼ� â�� ũ�� �����ϴ� �Լ�
void SetConsoleView()
{
    system("mode con:cols=150 lines=25");
    
}

//Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = 3 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//Ű������ �Է��� �ް�, �Էµ� Ű�� ���� ��ȯ�ϴ� �Լ�
int GetKeyDown()
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
    GotoXY(0, dinoY);
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
    GotoXY(0, dinoY);
    static bool legFlag = true;

    printf("$                                \n");
    printf("$$                            \n");
    printf("$$$                      \n");
    printf("$$$              $$$$$$$       \n");
    printf(" $$$$$$$$$$$$$  $$ $$$$$$            \n");
    printf(" $$$$$$$$$$$$$$ $$$$$$$$$        \n");
    printf("  $$$$$$$$$$$    $$$      \n");
    printf("   $$$$$$$$     $$$$$$$          \n");
    printf("          $                            \n");
    printf("          $                             \n");
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
void DrawTree(int treeX)
{
    GotoXY(treeX, TREE_BOTTOM_Y);
    printf("$$$$");
    GotoXY(treeX, TREE_BOTTOM_Y + 1);
    printf(" $$ ");
    GotoXY(treeX, TREE_BOTTOM_Y + 2);
    printf(" $$ ");
    GotoXY(treeX, TREE_BOTTOM_Y + 3);
    printf(" $$ ");
    GotoXY(treeX, TREE_BOTTOM_Y + 4);
    printf(" $$ ");
}
// ���� �׸��� �Լ�
void Bird(int birdY)
{
    GotoXY(birdY, BIRD_BOTTOM_Y);
    printf("   $$$$");
    GotoXY(birdY, BIRD_BOTTOM_Y + 1);
    printf("  $$$");
    GotoXY(birdY, BIRD_BOTTOM_Y + 2);
    printf("$$$$$$$$");
    GotoXY(birdY, BIRD_BOTTOM_Y + 3);
    printf("  $$$");
    GotoXY(birdY, BIRD_BOTTOM_Y + 4);
    printf("   $$$$");
}
// �浹 ������ ���ӿ��� �׷���
void DrawGameOver(const int score)
{
    system("cls");
    int x = 18;
    int y = 8;
    GotoXY(x, y);
    printf("===========================");
    GotoXY(x, y + 1);
    printf("======G A M E O V E R======");
    GotoXY(x, y + 2);
    printf("===========================");
    GotoXY(x, y + 5);
    printf("SCORE : %d", score);

    printf("\n\n\n\n\n\n\n\n\n");
    system("pause");
}

// �浹������ true, �ƴϸ� false
bool isCollision(const int treeX,const int dinoY,const int birdY,const int birdX)
{
    // Ʈ���� X�� ������ ��ü�ʿ� ������,
    // ������ ���̰� ������� �ʴٸ� �浹�� ó��

    // ������ ������ ���� Y�� ���� �� �浹�� ó�� 
    // ���� ���� ������ �Ӹ��� ������ ���ӿ����� �Ǵ°� �������� ����
    // ���̴� ����� ��������� ��ȯ�ϴ� ����� �𸣰���
    
    GotoXY(0, 0);
    printf("treeX : %d, dinoY : %d  ", treeX,dinoY); //�̷������� ������ X, Y�� ã���ϴ�.
    if (treeX <= 5 && treeX >= 3 && dinoY  > 8)
    {
        return true;
    }
    printf("  birdX : %d", birdY);
    if (birdY <= 12 && dinoY < 12)
    {
        return true;
    }
    
    return false;
}



int main()
{
    SetConsoleView();

    while (true)        //(v2.0) ���� ����
    {
        //���� ���۽� �ʱ�ȭ
        bool isJumping = false;
        bool isBottom = true;
        bool isDown = false;
        bool isUp = true;

        const int gravity = 3;

        int dinoY = DINO_BOTTOM_Y;
        int treeX = TREE_BOTTOM_X;
        int birdY = BIRD_BOTTOM_Y;
        int birdX = BIRD_BOTTOM_X;
        int score = 0;
        clock_t start, curr;    //���� ���� �ʱ�ȭ
        start = clock();        //���۽ð� �ʱ�ȭ

        while (true)    //�� �ǿ� ���� ����
        {
            //(v2.0) �浹üũ Ʈ���� x���� ������ y������ �Ǵ�
            if (isCollision(treeX, dinoY,birdY,birdX))
                break;

            //zŰ�� ���Ȱ�, �ٴ��� �ƴҶ� ����
            if (GetKeyDown() == 'z' && isBottom)
            {
                isJumping = true;
                isBottom = false;
            }
            if (GetKeyDown() == 'x' && isDown)
            {
                isDown = true;
                isUp = false;
            }
           // if (isDown)
           // {
           //     dinoY += gravity;
           // }
           // else
           // {
           //     dinoY -= gravity;
           // }

            //�������̶�� Y�� ����, ������ �������� Y�� ����.
            if (isJumping)
            {
                dinoY -= gravity;
            }
            else
            {
                dinoY += gravity;
            }

            //Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
            if (dinoY >= DINO_BOTTOM_Y)
            {
                dinoY = DINO_BOTTOM_Y;
                isBottom = true;
            }
            // Y�� ����ؼ� �����ϴ°� �������� õ���� ����
           // if (dinoY <= DINO_BOTTOM_Y)
           // {
           //     dinoY = DINO_BOTTOM_Y;
           //     isDown = true;
           // }

            // ������ �������� (x����) �������ϰ�
            // ������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
            treeX -= 2;
            if (treeX <= 0)
            {
                treeX = TREE_BOTTOM_X;
            }
            // ���� �������� �������ϰ�
            // ���� ��ġ�� ���� �����ΰ��� �ٽ� ���������� ������ ��ȯ.
            
            birdY -= 1;
            if (birdY <= 0)
            {
                birdY = BIRD_BOTTOM_X;
            }
            

            //������ ������ ������ ������ ���� ��Ȳ.
            if (dinoY <= 3)
            {
                isJumping = false;
            }

            DrawDino(dinoY);        // draw dino
            DrawTree(treeX);        // draw Tree
            Bird(birdY);            // draw Bird
            
            curr = clock();            //����ð� �޾ƿ���
            if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1�ʰ� �Ѿ�����
            {
                score++;    //���ھ� UP
                start = clock();    //���۽ð� �ʱ�ȭ
            }
            Sleep(60);
            system("cls");    //clear

            // ��������� 1�ʸ��� ���ִ°��� �ƴ϶� �׻� ������ָ鼭, 1�ʰ� �������� ++ ���ݴϴ�.
            GotoXY(22, 0);    //Ŀ���� ��� �������� �ű��. �ܼ�â�� cols=100�̴ϱ� 2*x�̹Ƿ� 22���� �־���
            printf("Score : %d ", score);    //���� �������.
        }

        //(v2.0) ���� ���� �޴�
        DrawGameOver(score);
    }
    return 0;
}