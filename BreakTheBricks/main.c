#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player = 0; // 0 동동이, 1 모모
int HP = 5;

int main()
{
    int check = 0; // 화면에 출력했는지 체크

    SetConsoleTitle(TEXT("Break the Bricks!"));
    system("mode con cols=120 lines=39");

    int Menu = title(); // 타이틀 화면

    while (Menu == 0 || Menu == 1)
    {
        switch (Menu)
        {
        case 0: // 게임 방법
            if (check == 0)
            {
                manual();
                check = 1;
            }

            if (GetAsyncKeyState(VK_RETURN) < 0)
            {
                system("cls");
                Sleep(200);
                Menu = title();
                check = 0;
            }
            break;
        case 1: // 게임 시작
            player = selPlayer(player);
            play(player, HP);
            break;
        default: break;
        }
    }
    if (Menu == 2) // 게임 종료
    {
        SetColor(15);
        system("cls");
        exit(0);
    }

    return 0;
}