#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>

#define Red {SetColor(4);}
#define DarkYellow {SetColor(6);}
#define Yellow {SetColor(14);}
#define SkyBlue {SetColor(11);}
#define BRICKS_WIDTH 113
#define BRICKS_HEIGHT 14

int bricks[12] = { 0, }; // 배열에 y값을 넣음
int bricks_size = sizeof(bricks) / sizeof(bricks[0]);
int numBricks = 0, totBricks = 0; // 남은 벽돌 수, 전체 벽돌 수
int cntTime = 30; // 제한 시간
int max_rubble = 0; // 떨어져야 하는 장애물의 수

void print_heart(void); // 화면에 장애물을 뿌려준다
void check_hit(void); // 장애물과 캐릭터 충돌 체크

unsigned _stdcall Timer() // 제한 시간
{
    cntTime = 30;

    while (bricks[0] != 0 && 31 != bricks[numBricks - 1])
    {
        DarkYellow; gotoxy(102, 1); printf("제한 시간 : %2d초", cntTime);
        
        cntTime -= 1;
        if (cntTime < 0) return 0;

        if ((cntTime % 3 == 0 || cntTime == 2) && totBricks != 12)
        {
            for (int i = 5; i < BRICKS_WIDTH; i = i + 7)
            {
                for (int j = i; j < i + 5; j = j + 2)
                {

                    Yellow; gotoxy(j, bricks[numBricks - 1] + 2); printf("■");
                    gotoxy(j, bricks[numBricks - 1] + 3); printf("■");
                }
            }
            bricks[numBricks] = bricks[numBricks - 1] + 3;
            numBricks++;
            totBricks++;
        }
        Sleep(1000);
    }
}

void draw_bricks() // 처음 벽돌 설정
{
    numBricks = 0; totBricks = 4;
    for (int i = 0; i < bricks_size; i++)
    {
        bricks[i] = 0;
    }

    Yellow;
    for (int i = 3; i < BRICKS_HEIGHT; i = i + 3)
    {
        bricks[numBricks] = i + 1;
        numBricks++;
        for (int j = 5; j < BRICKS_WIDTH; j = j + 7)
        {
            for (int k = j; k < j + 5; k = k + 2)
            {
                gotoxy(k, i); printf("■");
                gotoxy(k, i + 1); printf("■");
            }
        }
    }
}

void HitPoint(int HP)
{
    Yellow; gotoxy(2, 1); printf(" 체력 ) ", HP);
    Red;
    for (int i = 0; i < 5; i++)
    {
        if (i < HP) printf("♥ ");
        else printf("♡ ");
    }
}

void level1_play(int player, int HP)
{
    system("cls");

    draw_map();
    draw_bricks();

    HitPoint(HP); 
    _beginthreadex(NULL, 0, Timer, 0, 0, NULL);

    Yellow; gotoxy(57, 1); printf("LEVEL 1");
    gotoxy(57, 33); printf("////////");

    DarkYellow; gotoxy(60, 32);
    if (player == 0) printf("●");
    else printf("■");

    //srand(time(0)); // 랜덤 값 초기화

    int po_x = 60, po_y = 32; // 플레이어 시작 위치
     
    while (bricks[0] != 0 && 31 != bricks[numBricks - 1] && cntTime != 0) // 벽돌을 다 깼거나 플레이어가 벽돌에 깔렸을 경우
    {
        int temp_x = po_x;
        
        if (GetAsyncKeyState(0x41) & 0x8000) // A키 - 왼쪽
        {
            DarkYellow;
            gotoxy(po_x, po_y); printf("  ");
            po_x = po_x - 2; 
            gotoxy(temp_x - 3, po_y + 1); printf("           ");
            gotoxy(po_x, po_y);
            if (player == 0) printf("●");
            else printf("■");

            Yellow; gotoxy(po_x - 3, po_y + 1); printf("////////");
        }
        else if(GetAsyncKeyState(0x44) & 0x8000) // D키 - 오른쪽
        {
            DarkYellow;
            gotoxy(po_x, po_y); printf("  ");
            po_x = po_x + 2; 
            gotoxy(temp_x - 3, po_y + 1); printf("           ");
            gotoxy(po_x, po_y);
            if (player == 0) printf("●");
            else printf("■");

            Yellow; gotoxy(po_x - 3, po_y + 1); printf("////////");
        }
        else if(GetAsyncKeyState(0x57) & 0x8000) // W키 - 점프
        {
            DarkYellow;
            gotoxy(po_x, po_y); printf("  ");
            gotoxy(po_x, bricks[--numBricks] + 1);
            if (player == 0) printf("●");
            else printf("■");

            Sleep(200);
            gotoxy(po_x, bricks[numBricks] + 1); printf("  ");
            gotoxy(po_x, po_y);
            if (player == 0) printf("●");
            else printf("■");

            for (int i = 5; i < BRICKS_WIDTH; i = i + 7)
            {
                for (int j = i; j < i + 5; j = j + 2)
                {
                    gotoxy(j, bricks[numBricks] - 1); printf("  ");
                    gotoxy(j, bricks[numBricks]); printf("  ");
                }
            }
            bricks[numBricks] = 0;
        }
        Sleep(50);
    }

    system("cls"); Yellow;
    if (bricks[0] == 0)
    {
        gotoxy(56, 18); printf("CLEAR!!");
    }
    else
    {
        gotoxy(55, 18); printf("GAME OVER...");
    }
    Sleep(2500);
}
