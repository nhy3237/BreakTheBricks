#include <Windows.h>
#include <stdio.h>

#define MENU_Method {gotoxy(35, 27); printf("게임 방법");}
#define MENU_Start {gotoxy(55, 27); printf("게임 시작");}
#define MENU_End {gotoxy(75, 27); printf("게임 종료");}

int title()
{
	SetColor(14);
    gotoxy(8, 12); printf("■■■ ■■■ ■■■ ■■■ ■   ■  ■■■ ■  ■ ■■■  ■■■ ■■■ ■■■ ■■■ ■   ■ ■■■ ■");
    gotoxy(8, 13); printf("■  ■ ■  ■ ■     ■  ■ ■  ■     ■   ■  ■ ■      ■  ■ ■  ■   ■   ■     ■  ■  ■     ■");
    gotoxy(8, 14); printf("■■■ ■■   ■■■ ■■■ ■■       ■   ■■■ ■■■  ■■■ ■■     ■   ■     ■■    ■■■ ■");
    gotoxy(8, 15); printf("■  ■ ■  ■ ■     ■  ■ ■  ■     ■   ■  ■ ■      ■  ■ ■  ■   ■   ■     ■  ■      ■");
    gotoxy(8, 16); printf("■■■ ■  ■ ■■■ ■  ■ ■   ■    ■   ■  ■ ■■■  ■■■ ■  ■ ■■■ ■■■ ■   ■ ■■■ ■");
	
    gotoxy(25, 25); printf("---------------------------------------------------------------------");
    gotoxy(25, 26); printf("-                                                                   -");
    gotoxy(25, 27); printf("-                                                                   -");
    gotoxy(25, 28); printf("-                                                                   -");
    gotoxy(25, 29); printf("---------------------------------------------------------------------");

	int POS = 1; // 0 게임 방법, 1 게임 시작, 2 게임 종료

    while (1)
	{
		if (GetAsyncKeyState(VK_LEFT) < 0)
			if (POS == 0) POS = 2;
			else POS -= 1;
		else if (GetAsyncKeyState(VK_RIGHT) < 0)
			if (POS == 2) POS = 0;
			else POS += 1;
		else if (GetAsyncKeyState(VK_RETURN) < 0)// 엔터를 눌렀을 때
		{
			Sleep(100);
			return POS;
		}

		switch (POS) {
		case 0:
			SetColor(14);
			MENU_Start;
			MENU_End;
			SetColor(6);
			MENU_Method;
			break;
		case 1:
			SetColor(14);
			MENU_End;
			MENU_Method;
			SetColor(6);
			MENU_Start;
			break;
		case 2:
			SetColor(14);
			MENU_Method;
			MENU_Start;
			SetColor(6);
			MENU_End;
			break;
		default: break;
		}
		Sleep(200);
	}
}