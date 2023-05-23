#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define White {SetColor(15);}

int main()
{
    int check = 0; // 화면에 출력했는지 체크
    int player = 0; // 0 동동이, 1 모모

    SetConsoleTitle(TEXT("Break the Bricks!"));
    system("mode con cols=120 lines=39");
    init();

    int Menu = title(); // 타이틀 화면

    while (1)
    {
        switch (Menu)
        {
        case 0: // 게임 방법
            if (check == 0)
            {
                manual();
                check = 1;
            }

            if (GetAsyncKeyState(VK_RETURN) & 0x8000)
            {
                system("cls");
                Sleep(200);
                Menu = title();
                check = 0;
            }
            break;
        case 1: // 게임 시작
            player = selPlayer(player);
            level1_play(player);

            system("cls");
            Menu = title();
            break;
        case 2: //게임 종료
            White;
            system("cls");
            printf("종료되었습니다.");
            exit(0);
            break;

        default: break;
        }
    }
    return 0;
}