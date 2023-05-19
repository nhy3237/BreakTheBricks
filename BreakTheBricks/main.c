#include <Windows.h>
#include <stdio.h>
#include <time.h>

int HP = 5;

int main()
{
    int Menu;

    Menu = title_screen(); // 타이틀 화면
    system("cls");

    switch (Menu)
    {
    case 0: break; // 게임 방법
    case 1: break; // 게임 시작
    case 2: return 0; // 게임 종료
    }

    int countTime = 60;

    /*while (1)
    {   
        printf("\n  체력 : %d", HP);
        printf("\t\t\t\t\t\t\t\t\t\t\t     제한 시간 : %d초\n", countTime);
        Sleep(1000);
        system("cls");
        countTime -= 1;
        
        if (countTime < 0)
        {
            printf("종료되었습니다.");
            return 0;
        }
	}*/
    return 0;
}

void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
