#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH 119
#define MAP_HEIGHT 38
#define DONGDONG {gotoxy(30, 15); printf("●");\
                  gotoxy(20, 20); printf("이름 : 동동이");\
                  gotoxy(20, 22); printf("장점 : 속도가 빠르다.");\
                  gotoxy(20, 24); printf("단점 : 한 줄씩만 제거된다."); }
#define MOMO {gotoxy(85, 15); printf("■");\
              gotoxy(75, 20); printf("이름 : 모모");\
              gotoxy(75, 22); printf("장점 : 두 줄씩 제거된다.");\
              gotoxy(75, 24); printf("단점 : 속도가 느리다."); }

void manual()
{
    system("cls");
    SetColor(14);

    gotoxy(50, 8); printf("<게임 방법>");
    gotoxy(20, 13); printf("- 사용 키 : A 키(왼쪽), D 키(오른쪽), W 키(점프), I 키(네잎클로버 사용)");
    gotoxy(20, 15); printf("- 점프해서 벽돌을 칠 때마다 한 줄이 전부 부서진다.");
    gotoxy(20, 17); printf("- 떨어지는 네잎클로버를 먹으면 스킬을 사용할 수 있다.");
    gotoxy(20, 19); printf("- 네잎클로버 : 3초간 장애물로부터 무적 상태, 벽돌이 2줄씩 깨진다.");
    gotoxy(20, 21); printf("- 장애물을 맞으면 목숨이 하나 줄고 벽돌에 깔리면 바로 게임오버 된다.");

    SetColor(6);
    gotoxy(40, 30); printf("> 엔터를 누르면 이전으로 돌아갑니다. <");
}

void draw_map() // 맵 테두리
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
    gotoxy(50, 8); printf("<플레이어 선택>");

    while (1)
    {
        if (GetAsyncKeyState(VK_LEFT) & 0x8000)
            if (player == 0) player = 1;
            else player = 0;
        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
            if (player == 1) player = 0;
            else player = 1;
        else if (GetAsyncKeyState(VK_RETURN) & 0x8000) // 엔터를 눌렀을 때
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