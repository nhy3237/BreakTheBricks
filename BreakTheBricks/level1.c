#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>

#define Red {SetColor(4);}
#define DarkYellow {SetColor(6);}
#define Yellow {SetColor(14);}
#define SkyBlue {SetColor(11);}
#define BRICKS_WIDTH 116

unsigned _stdcall Timer(void* arg);

void draw_bricks() // 처음 벽돌 설정
{
    Yellow;
    for (int i = 3; i < BRICKS_WIDTH; i = i + 5)
    {
        for (int j = 1; j < 6; j++)
        {
            gotoxy(i, (j * 2) + 1); printf("■");
            gotoxy(i + 2, (j * 2) + 1); printf("■");
            gotoxy(i, (j * 2) + 6); printf("■");
            gotoxy(i + 2, (j * 2) + 6); printf("■");
        }
    }
}

void level1_play(int player, int HP)
{
    system("cls");
    draw_map();
    draw_bricks();
    Red; gotoxy(2, 1); printf("♡"); 
    Yellow; printf(" 체력 : %d", HP);
    gotoxy(57, 36); printf("////////");

    _beginthreadex(NULL, 0, Timer, 0, 0, NULL);

    DarkYellow;
    if (player == 0)
    {
        gotoxy(60, 35); printf("●");
    }
    else
    {
        gotoxy(60, 35); printf("■");
    }
    int po_x = 60, po_y = 35;

    while (1)
    {
        if (GetAsyncKeyState(0x41) & 0x8000) // A키
        {
            int temp_x = po_x, temp_y = po_y;
            po_x = po_x - 2;
            DarkYellow;
            gotoxy(temp_x, temp_y); printf("  ");
            gotoxy(temp_x - 3, temp_y + 1); printf("           ");
            if (player == 0)
            {
                gotoxy(po_x, po_y); printf("●");
            }
            else
            {
                gotoxy(po_x, po_y); printf("■");
            }
            Yellow; gotoxy(po_x - 3, po_y + 1); printf("////////");
        }
        else if(GetAsyncKeyState(0x44) & 0x8000) // D키
        {
            int temp_x = po_x, temp_y = po_y;
            po_x = po_x + 2;
            DarkYellow;
            gotoxy(temp_x, temp_y); printf("  ");
            gotoxy(temp_x - 3, temp_y + 1); printf("           ");
            if (player == 0)
            {
                gotoxy(po_x, po_y); printf("●");
            }
            else
            {
                gotoxy(po_x, po_y); printf("■");
            }
            Yellow; gotoxy(po_x - 3, po_y + 1); printf("////////");
        }
        else if(GetAsyncKeyState(0x57) & 0x8000) // W키
        {
            int temp_x = po_x, temp_y = po_y;
            po_y = po_y - 2;
            DarkYellow;
            gotoxy(temp_x, temp_y); printf("  ");
            if (player == 0)
            {
                gotoxy(po_x, po_y); printf("●");
            }
            else
            {
                gotoxy(po_x, po_y); printf("■");
            }
        }

        Sleep(50);
    }
}

unsigned _stdcall Timer(void* arg)
{
    int countTime = 60;

    while (1)
    {
        Yellow;
        gotoxy(102, 1); printf("제한 시간 : %2d초", countTime);

        if (countTime % 10 == 0)
        {

        }

        Sleep(1000);

        countTime -= 1;
        if (countTime < 0) return 0;
    }
}