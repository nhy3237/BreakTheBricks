#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <time.h>

#define Red {SetColor(4);}
#define DarkYellow {SetColor(6);}
#define Yellow {SetColor(14);}
#define SkyBlue {SetColor(11);}
#define BRICKS_WIDTH 113
#define BRICKS_HEIGHT 14
#define RUBBLE BRICKS_WIDTH - 1 // 

typedef struct xy {
    int x, y;
};

struct xy rubble[RUBBLE];

int bricks[12] = { 0, }; // 배열에 y값을 넣음
int bricks_size = sizeof(bricks) / sizeof(bricks[0]);
int numBricks = 0, totBricks = 0; // 남은 벽돌 수, 전체 벽돌 수
int cntTime = 30; // 제한 시간
int max_rubble = 0; // 떨어져야 하는 장애물의 수
int count_rubble = 0; // 떨어진 장애물 수
int HP = 5; // 체력
int rubble_flag = 0; // 장애물 내리기 시작 여부

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

unsigned _stdcall print_rubble()
{
    while (bricks[0] != 0 && 31 != bricks[numBricks - 1] && cntTime != 0) // 벽돌을 다 깼거나 플레이어가 벽돌에 깔렸을 경우
    {
        if (rubble_flag == 1) // 벽돌 처음 깨면 장애물을 내리게 함
        {
            for (int i = 0; i < rand()%max_rubble; i++)
            {
                // 땅에 떨어졌을 경우
                if (rubble[i].y == 33)
                {
                    // 기존 위치의 장애물을 삭제한다.
                    gotoxy(rubble[i].x, rubble[i].y);
                    printf(" ");

                    // 떨어진 장애물의 갯수 증가
                    count_rubble++;

                    // 떨어진 장애물의 갯수가 최대 갯수가 아닐 경우
                    if (max_rubble > count_rubble)
                    {
                        // 장애물을 위에서 다시 내리게 한다
                        rubble[i].x = rand() % 50;
                        rubble[i].x *= 2;
                    }
                    continue;
                }
                // 장애물을 밑으로 한칸 내린다
                rubble[i].y = rubble[i].y + 3;

                if (rubble[i].y > 1)
                {
                    // 기존 위치의 장애물을 삭제한다.
                    gotoxy(rubble[i].x, rubble[i].y - 3);
                    printf(" ");

                    // 새로운 위치에 장애물을 출력한다.
                    gotoxy(rubble[i].x, rubble[i].y);
                    printf("-");
                }
            }
            Sleep(700);
        }
    }
}

// 장애물을 맞았는지 체크
void check_hit(int po_x, int po_y)
{
    // 현재 장애물의 수 만큼 반복
    for (int count = 0; count < max_rubble; count++)
    {
        // 사용자와 같은 열인지 확인
        if (rubble[count].x == po_x && rubble[count].y == po_y - 1)
        {
            HitPoint(--HP);
        }
    }
}

void level1_play(int player)
{
    int po_x = 60, po_y = 32; // 플레이어 시작 위치

    system("cls");

    draw_map();
    draw_bricks();

    HP = 5;
    HitPoint(HP); 

    rubble_flag = 0;
    max_rubble = 10;
    count_rubble = 0;
    srand(time(0)); // 랜덤 값 초기화

    for (int i = 0; i < max_rubble; i++)
    {
        rubble[i].x = rand() % 50;
        rubble[i].y = i + 1;
        rubble[i].x *= 2;
        rubble[i].y *= -1;
    }

    _beginthreadex(NULL, 0, print_rubble, 0, 0, NULL);

    Yellow; gotoxy(57, 1); printf("LEVEL 1");
    gotoxy(57, 33); printf("////////");

    DarkYellow; gotoxy(po_x, po_y);
    if (player == 0) printf("●");
    else printf("■");

    _beginthreadex(NULL, 0, Timer, 0, 0, NULL);
     
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
            if (rubble_flag == 0) rubble_flag = 1;
        }
        Sleep(50);
        check_hit(po_x, po_y);
    }

    system("cls"); Yellow;
    if (bricks[0] == 0)
    {
        gotoxy(54, 18); printf("C L E A R ! !");
    }
    else
    {
        gotoxy(55, 18); printf("GAME OVER...");
    }
    Sleep(2500);
}
