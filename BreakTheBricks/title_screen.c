#include <Windows.h>
#include <stdio.h>

void gotoxy(int x, int y);
void SetColor(int color);

int start()
{
    SetConsoleTitle(TEXT("Break the Bricks!"));
    system("mode con cols=120 lines=40");

	SetColor(14);
    gotoxy(8, 12); printf("■■■ ■■■ ■■■ ■■■ ■   ■  ■■■ ■  ■ ■■■  ■■■ ■■■ ■■■ ■■■ ■   ■ ■■■ ■");
    gotoxy(8, 13); printf("■  ■ ■  ■ ■     ■  ■ ■  ■     ■   ■  ■ ■      ■  ■ ■  ■   ■   ■     ■  ■  ■     ■");
    gotoxy(8, 14); printf("■■■ ■■   ■■■ ■■■ ■■       ■   ■■■ ■■■  ■■■ ■■     ■   ■     ■■    ■■■ ■");
    gotoxy(8, 15); printf("■  ■ ■  ■ ■     ■  ■ ■  ■     ■   ■  ■ ■      ■  ■ ■  ■   ■   ■     ■  ■      ■");
    gotoxy(8, 16); printf("■■■ ■  ■ ■■■ ■  ■ ■   ■    ■   ■  ■ ■■■  ■■■ ■  ■ ■■■ ■■■ ■   ■ ■■■ ■");

    gotoxy(25, 24); printf("---------------------------------------------------------------------");
    gotoxy(25, 25); printf("-                                                                   -");
    gotoxy(25, 26); printf("-                                                                   -");
    gotoxy(35, 26); printf("게임 방법");
    gotoxy(55, 26); printf("게임 시작");
    gotoxy(75, 26); printf("게임 종료");
    gotoxy(25, 27); printf("-                                                                   -");
    gotoxy(25, 28); printf("---------------------------------------------------------------------\n\n\n\n\n\n");

    int POS = 3; // 0 게임 방법, 1 게임 시작, 2 게임 종료

    while (1)
	{
		if (GetAsyncKeyState(VK_LEFT)) // 
			if (POS == 0) POS = 2;
			else POS -= 1;
		else if (GetAsyncKeyState(VK_RIGHT))
			if (POS == 2) POS = 0;
			else POS += 1;
		else if (GetAsyncKeyState(VK_RETURN))//엔터를 눌렀을 때
			return POS;

		switch (POS) {
		case 0:
			SetColor(14);
			gotoxy(55, 26); printf("게임 시작");
			gotoxy(75, 26); printf("게임 종료");
			SetColor(6);
			gotoxy(35, 26); printf("게임 방법");
			
			break;
		case 1:
			SetColor(14);
			gotoxy(75, 26); printf("게임 종료");
			gotoxy(35, 26); printf("게임 방법");
			SetColor(6);
			gotoxy(55, 26); printf("게임 시작");
			break;
		case 2:
			SetColor(14);
			gotoxy(35, 26); printf("게임 방법");
			gotoxy(55, 26); printf("게임 시작");
			SetColor(6);
			gotoxy(75, 26); printf("게임 종료");
			break;
		default: break;
		}
		Sleep(100);
	}
}

void SetColor(int color)

{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}