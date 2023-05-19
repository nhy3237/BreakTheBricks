#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_X 3
#define MAP_Y 2
#define MAP_WIDTH 30
#define MAP_HEIGHT 20

int player = 0; // 0 동동이, 1 모모
int HP = 5;

void gotoxy(int x, int y);
void draw_map();

int selPlayer();
void play();

int main()
{
    int Menu;

    Menu = title_screen(); // 타이틀 화면
    system("cls");

    switch (Menu)
    {
    case 0: // 게임 방법
        break; 
    case 1: // 게임 시작
        getchar();
        player = selPlayer();
        play(); 
        break; 
    case 2: // 게임 종료
        exit(0);
    default: break;
    }

    return 0;
}

void play()
{
    int countTime = 60;

    while (1)
    {
        system("cls");

        SetColor(14);
        draw_map();
        SetColor(14);
        gotoxy(2, 1); printf("♡ 체력 : %d", HP);
        gotoxy(102, 1); printf("제한 시간 : %2d초", countTime);
      
        if (player == 0)
        {
            gotoxy(60, 35); printf("●");
        }
        else
        {
            gotoxy(60, 35); printf("■");
        }
        gotoxy(57, 36); printf("////////");

        Sleep(1000);
        
        countTime -= 1;

        if (countTime < 0)
        {
            printf("종료되었습니다.");
            return 0;
        }
    }
}

int selPlayer()
{
    SetColor(14);
    gotoxy(50, 10); printf("<플레이어 선택>");

    while (1)
    {
        if (GetAsyncKeyState(VK_LEFT)) // 
            if (player == 0) player = 1;
            else player = 0;
        else if (GetAsyncKeyState(VK_RIGHT))
            if (player == 1) player = 0;
            else player = 1;
        else if (GetAsyncKeyState(VK_RETURN))//엔터를 눌렀을 때
            return player;

        switch (player) {
        case 0:
            SetColor(14);
            gotoxy(85, 15); printf("■");
            gotoxy(75, 20); printf("이름 : 모모");
            gotoxy(75, 22); printf("장점 : 두 줄씩 제거된다.");
            gotoxy(75, 24); printf("단점 : 속도가 느리다.");
            SetColor(6);
            gotoxy(30, 15); printf("●");
            gotoxy(20, 20); printf("이름 : 동동이");
            gotoxy(20, 22); printf("장점 : 속도가 빠르다.");
            gotoxy(20, 24); printf("단점 : 한 줄씩만 제거된다.");
            break;
        case 1:
            SetColor(14);
            gotoxy(30, 15); printf("●");
            gotoxy(20, 20); printf("이름 : 동동이");
            gotoxy(20, 22); printf("장점 : 속도가 빠르다.");
            gotoxy(20, 24); printf("단점 : 한 줄씩만 제거된다.");
            SetColor(6);
            gotoxy(85, 15); printf("■");
            gotoxy(75, 20); printf("이름 : 모모");
            gotoxy(75, 22); printf("장점 : 두 줄씩 제거된다.");
            gotoxy(75, 24); printf("단점 : 속도가 느리다.");
            break;
        default: break;
        }
        Sleep(100);
        GetAsyncKeyState(0x0000);
    }
}

void draw_map() // 맵 테두리
{
    int i, j;
    for (i = 1; i < 119; i++)
    {
        gotoxy(i, 2); printf("-");
        gotoxy(i, 38); printf("-");
    }
    for (i = 3; i < 38; i++)
    {
        gotoxy(1, i); printf("-");
        gotoxy(118, i); printf("-");
    }

    //벽돌
    SetColor(15);
    for (i = 4; i < 114; i++)
    {
        for (j = 3; j < 13; j++)
        {
            gotoxy(i, j); printf("□");
        }
    }
}

void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
