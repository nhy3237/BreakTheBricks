#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH 119
#define MAP_HEIGHT 38
#define DONGDONG {gotoxy(30, 15); printf("��");\
                  gotoxy(20, 20); printf("�̸� : ������");\
                  gotoxy(20, 22); printf("���� : �ӵ��� ������.");\
                  gotoxy(20, 24); printf("���� : �� �پ��� ���ŵȴ�."); }
#define MOMO {gotoxy(85, 15); printf("��");\
              gotoxy(75, 20); printf("�̸� : ���");\
              gotoxy(75, 22); printf("���� : �� �پ� ���ŵȴ�.");\
              gotoxy(75, 24); printf("���� : �ӵ��� ������."); }

void manual()
{
    system("cls");
    SetColor(14);

    gotoxy(50, 8); printf("<���� ���>");
    gotoxy(20, 13); printf("- ��� Ű : A Ű(����), D Ű(������), W Ű(����), I Ű(����Ŭ�ι� ���)");
    gotoxy(20, 15); printf("- �����ؼ� ������ ĥ ������ �� ���� ���� �μ�����.");
    gotoxy(20, 17); printf("- �������� ����Ŭ�ι��� ������ ��ų�� ����� �� �ִ�.");
    gotoxy(20, 19); printf("- ����Ŭ�ι� : 3�ʰ� ��ֹ��κ��� ���� ����, ������ 2�پ� ������.");
    gotoxy(20, 21); printf("- ��ֹ��� ������ ����� �ϳ� �ٰ� ������ �򸮸� �ٷ� ���ӿ��� �ȴ�.");

    SetColor(6);
    gotoxy(40, 30); printf("> ���͸� ������ �������� ���ư��ϴ�. <");
}

void draw_map() // �� �׵θ�
{
    SetColor(14);
    for (int i = 1; i < MAP_WIDTH; i++)
    {
        gotoxy(i, 2); printf("-");
        gotoxy(i, MAP_HEIGHT); printf("-");
    }
    for (int i = 3; i < MAP_HEIGHT; i++)
    {
        gotoxy(1, i); printf("-");
        gotoxy(MAP_WIDTH - 1, i); printf("-");
    }
}

int selPlayer(int player)
{    
    system("cls");

    SetColor(14);
    gotoxy(50, 8); printf("<�÷��̾� ����>");

    while (1)
    {
        if (GetAsyncKeyState(VK_LEFT) & 0x8000)
            if (player == 0) player = 1;
            else player = 0;
        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
            if (player == 1) player = 0;
            else player = 1;
        else if (GetAsyncKeyState(VK_RETURN) & 0x8000) // ���͸� ������ ��
        {
            Sleep(200);
            return player;
        }

        switch (player) {
        case 0:
            SetColor(14);
            MOMO;
            SetColor(6);
            DONGDONG;
          
            break;
        case 1:
            SetColor(14);
            DONGDONG;
            SetColor(6);
            MOMO;

            break;
        default: break;
        }
        Sleep(200);
    }
}